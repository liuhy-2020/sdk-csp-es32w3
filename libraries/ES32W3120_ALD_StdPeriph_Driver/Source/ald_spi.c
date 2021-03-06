/**********************************************************************************
 *
 * @file    ald_spi.c
 * @brief   SPI module driver.
 *
 * @date    30 Apri 2021
 * @author  AE Team
 * @note
 *          Change Logs:
 *          Date            Author          Notes
 *          30 Apri 2021    yanght          the first version
 *
 * Copyright (C) Shanghai Eastsoft Microelectronics Co. Ltd. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 **********************************************************************************
 */

/* Includes ------------------------------------------------------------------ */
#include "ald_spi.h"


/** @addtogroup ES32FXXX_ALD
  * @{
  */

/** @defgroup SPI SPI
  * @brief SPI module driver
  * @{
  */


/** @addtogroup SPI_Private_Functions   SPI Private Functions
  * @{
  */

static void __spi_send_by_it(spi_handle_t *hperh);
static void __spi_recv_by_it(spi_handle_t *hperh);
static void __spi_send_recv_by_it(spi_handle_t *hperh, spi_sr_status_t status);

static ald_status_t spi_wait_flag_irq(spi_handle_t *hperh, spi_flag_t flag, flag_status_t status, uint32_t timeout);
static void spi_dma_send_cplt(void *arg);
static void spi_dma_recv_cplt(void *arg);
static void spi_dma_send_recv_cplt(void *arg);

/**
  * @}
  */

/** @defgroup SPI_Public_Functions SPI Public Functions
  * @{
  */

/** @defgroup SPI_Public_Functions_Group1 Initialization functions
  * @brief Initialization and Configuration functions
  *
  * @verbatim
 ===============================================================================
              ##### Initialization and de-initialization functions #####
 ===============================================================================
    [..]  This subsection provides a set of functions allowing to initialize and
          reset the SPIx peripheral:

      (+) User must configure all related peripherals resources
          (CLOCK, GPIO, DMA, NVIC).

      (+) Call the function ald_spi_init() to configure the selected device with
          the selected configuration:
        (++) Mode
        (++) Direction
        (++) Data Size
        (++) Clock Polarity and Phase
        (++) NSS Management
        (++) BaudRate Prescaler
        (++) FirstBit
        (++) TIMode
        (++) CRC Calculation
        (++) CRC Polynomial if CRC enabled

      (+) Call the function ald_spi_reset() to reset the selected SPIx periperal.

    @endverbatim
  * @{
  */

/**
  * @brief  Reset the SPI peripheral.
  * @param  hperh: Pointer to a spi_handle_t structure that contains
  *         the configuration information for the specified SPI module.
  * @retval None
  */
void ald_spi_reset(spi_handle_t *hperh)
{
	hperh->perh->CON1    = 0x0;
	hperh->perh->CON2    = 0x0;
	hperh->perh->CRCPOLY = 0x00000007;

	SPI_RESET_HANDLE_STATE(hperh);
	__UNLOCK(hperh);

	return;
}

/**
  * @brief  Initializes the SPI mode according to the specified parameters in
  *         the SPI_init_t and create the associated handle.
  * @param  hperh: Pointer to a spi_handle_t structure that contains
  *         the configuration information for the specified SPI module.
  * @retval Status, see @ref ald_status_t.
  */
ald_status_t ald_spi_init(spi_handle_t *hperh)
{
	uint32_t tmp = 0;

	if (hperh == NULL)
		return ERROR;

	assert_param(IS_SPI(hperh->perh));
	assert_param(IS_SPI_MODE(hperh->init.mode));
	assert_param(IS_SPI_DIRECTION(hperh->init.dir));
	assert_param(IS_SPI_BAUD(hperh->init.baud));
	assert_param(IS_SPI_FIRBIT(hperh->init.first_bit));
	assert_param(IS_FUNC_STATE(hperh->init.ss_en));
	assert_param(IS_FUNC_STATE(hperh->init.crc_calc));
	assert_param(IS_SPI_DATASIZE(hperh->init.data_size));
	assert_param(IS_SPI_CPHA(hperh->init.phase));
	assert_param(IS_SPI_CPOL(hperh->init.polarity));
	assert_param(IS_SPI_FRAME(hperh->init.frame));

	ald_spi_reset(hperh);
	tmp = hperh->perh->CON1;

	if (hperh->init.mode == SPI_MODE_MASTER)
		tmp |= 1 << SPI_CON1_SSOUT_POS;

	tmp |= ((hperh->init.phase << SPI_CON1_CPHA_POS) | (hperh->init.polarity << SPI_CON1_CPOL_POS) |
	        (hperh->init.baud << SPI_CON1_BAUD_POSS) | (hperh->init.data_size << SPI_CON1_FLEN_POS) |
		(hperh->init.mode << SPI_CON1_MSTREN_POS) | (hperh->init.ss_en << SPI_CON1_SSEN_POS) |
		(hperh->init.first_bit << SPI_CON1_LSBFST_POS));

	hperh->perh->CON1 = tmp;

	MODIFY_REG(hperh->perh->CON2, SPI_CON2_FRF_MSK, hperh->init.frame << SPI_CON2_FRF_POS);

	if (hperh->init.dir == SPI_DIRECTION_2LINES) {
		CLEAR_BIT(hperh->perh->CON1, SPI_CON1_BIDEN_MSK);
		CLEAR_BIT(hperh->perh->CON1, SPI_CON1_RXO_MSK);
	}
	else if (hperh->init.dir == SPI_DIRECTION_2LINES_RXONLY) {
		CLEAR_BIT(hperh->perh->CON1, SPI_CON1_BIDEN_MSK);
		SET_BIT(hperh->perh->CON1, SPI_CON1_RXO_MSK);
	}
	else if (hperh->init.dir == SPI_DIRECTION_1LINE_RX) {
		SET_BIT(hperh->perh->CON1, SPI_CON1_BIDEN_MSK);
		CLEAR_BIT(hperh->perh->CON1, SPI_CON1_BIDOEN_MSK);
	}
	else {
		SET_BIT(hperh->perh->CON1, SPI_CON1_BIDEN_MSK);
		SET_BIT(hperh->perh->CON1, SPI_CON1_BIDOEN_MSK);
	}

	/* configure CRC */
	hperh->perh->CON1   |= (hperh->init.crc_calc << SPI_CON1_CRCEN_POS);
	hperh->perh->CRCPOLY = hperh->init.crc_poly;

	hperh->err_code = SPI_ERROR_NONE;
	hperh->state    = SPI_STATE_READY;

	SPI_ENABLE(hperh);
	return OK;
}

/**
  * @brief  Config the fifo threshold 
  * @param  hperh: Pointer to a spi_handle_t structure that contains
  *         the configuration information for the specified SPI module.
  * @param  threshold: The threshold value of fifo. 
  * @retval Status, see @ref ald_status_t.
  */
ald_status_t spi_fifo_threshold_config(spi_handle_t *hperh, uint8_t threshold)
{
	assert_param(IS_SPI(hperh->perh));

	MODIFY_REG(hperh->perh->CON2, SPI_CON2_RXFTH_MSK, threshold << SPI_CON2_RXFTH_POSS);
	MODIFY_REG(hperh->perh->CON2, SPI_CON2_TXFTH_MSK, threshold << SPI_CON2_TXFTH_POSS);

	return OK;
}
/**
  * @}
  */

/** @defgroup SPI_Public_Functions_Group2 IO fast functions
  * @brief SPI Transmit and Receive functions
  *
  * @verbatim
  ==============================================================================
                      ##### IO fast functions #####
 ===============================================================================
    This subsection provides a set of functions allowing to manage the SPI
    data transfers fast.

  * @endverbatim
  * @{
  */

/**
  * @brief  Transmit one byte fast in blocking mode.
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  data: Data to be sent
  * @retval status:
  *           -  0 Success
  *           - -1 Failed
  */
int32_t ald_spi_send_byte_fast(spi_handle_t *hperh, uint8_t data)
{
	uint16_t cnt = 5000, temp;

	while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
	hperh->perh->DATA = data;
	while (((hperh->perh->STAT & SPI_STAT_TXE_MSK) == 0) && (--cnt));

	cnt = 5000;
	while (((hperh->perh->STAT & SPI_STAT_RXE_MSK) == SPI_STAT_RXE_MSK) && (--cnt));
	temp = hperh->perh->DATA;
	UNUSED(temp);

	return cnt == 0 ? -1 : 0;
}

/**
  * @brief  Transmit one byte fast in blocking mode(1line).
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  data: Data to be sent
  * @retval status:
  *           -  0 Success
  *           - -1 Failed
  */
int32_t ald_spi_send_byte_fast_1line(spi_handle_t *hperh, uint8_t data)
{
	uint16_t cnt = 5000;

    while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
	hperh->perh->DATA = data;
	while (((hperh->perh->STAT & SPI_STAT_TXE_MSK) == 0) && (--cnt));

	return cnt == 0 ? -1 : 0;
}

/**
  * @brief  Receive one byte fast in blocking mode.
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  status: Status, success[0]/failed[-1]
  * @retval Data.
  */
uint8_t ald_spi_recv_byte_fast(spi_handle_t *hperh, int *status)
{
	uint16_t cnt = 5000;

	if (hperh->init.mode == SPI_MODE_MASTER) {
		hperh->perh->DATA = 0xFF;
		while (((hperh->perh->STAT & SPI_STAT_TXE_MSK) == 0) && (--cnt));
	}

	cnt = 5000;
	while (((hperh->perh->STAT & SPI_STAT_RXE_MSK) == SPI_STAT_RXE_MSK) && (--cnt));
	*status = cnt == 0 ? - 1 : 0;

	return (uint8_t)hperh->perh->DATA;
}

/**
  * @brief  Transmit some bytes fast in blocking mode.
  * @note   Bit width is 8-bits. Supports mode: Master/Slave.
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  buf: Data to be sent.
  * @param  size: Length of data.
  * @param  timeout: Timeout between two bytes.
  * @retval status: OK/TIMEOUT
  */
ald_status_t ald_spi_send_bytes_fast(spi_handle_t *hperh, uint8_t *buf, uint32_t size, uint32_t timeout)
{
	uint32_t tick;
	uint16_t i, tmp = 0;

	while (size--) {
        while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
		hperh->perh->DATA = *buf++;
		tick = ald_get_tick();

		while ((hperh->perh->STAT & SPI_STAT_TXE_MSK) == 0) {
			if (((ald_get_tick()) - tick) > timeout)
				return TIMEOUT;
		}
	}

	for (i = 0; i < 16; ++i) {
		if ((hperh->perh->STAT & SPI_STAT_RXE_MSK) == SPI_STAT_RXE_MSK)
			tmp = hperh->perh->DATA;
		else
			break;
	}

	UNUSED(tmp);
	return OK;
}

/**
  * @brief  Receive some bytes fast in blocking mode.
  * @note   Bit width is 8-bits. Supports mode: Master.
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  buf: Data to be received.
  * @param  size: Length of data.
  * @retval status: OK/TIMEOUT
  */
ald_status_t ald_spi_master_recv_bytes_fast(spi_handle_t *hperh, uint8_t *buf, uint32_t size)
{
	uint16_t cnt = 8000;

	while (size--) {
		hperh->perh->DATA = 0xFF;
		cnt = 8000;
		while (((hperh->perh->STAT & SPI_STAT_RXE_MSK) == SPI_STAT_RXE_MSK) && (--cnt));

		if (cnt)
			*buf++ = (uint8_t)hperh->perh->DATA;
		else
			return TIMEOUT;
	}

	return OK;
}

/**
  * @brief  Receive some bytes fast in blocking mode.
  * @note   Bit width is 8-bits. Supports mode: Slave.
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  buf: Data to be received.
  * @param  size: Length of data.
  * @param  timeout: Timeout between two bytes.
  * @retval status: OK/TIMEOUT
  */
ald_status_t ald_spi_slave_recv_bytes_fast(spi_handle_t *hperh, uint8_t *buf, uint32_t size, uint32_t timeout)
{
	uint32_t tick;

	while (size--) {
		tick = ald_get_tick();

		while ((hperh->perh->STAT & SPI_STAT_RXE_MSK) == SPI_STAT_RXE_MSK) {
			if (((ald_get_tick()) - tick) > timeout)
				return TIMEOUT;
		}

		*buf++ = (uint8_t)hperh->perh->DATA;
	}

	return OK;
}

/**
  * @brief  Transmit some double-bytes fast in blocking mode.
  * @note   Bit width is 16-bits. Supports mode: Master/Slave.
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  buf: Data to be sent.
  * @param  size: Length of data. Unit is double-bytes.
  * @param  timeout: Timeout between two dbytes.
  * @retval status: OK/TIMEOUT
  */
ald_status_t ald_spi_send_dbytes_fast(spi_handle_t *hperh, uint8_t *buf, uint32_t size, uint32_t timeout)
{
	uint32_t tick;
	uint16_t i, tmp = 0;

	while (size--) {
        while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
		hperh->perh->DATA = (*(uint16_t *)buf);
		buf += 2;
		tick = ald_get_tick();

		while ((hperh->perh->STAT & SPI_STAT_TXE_MSK) == 0) {
			if (((ald_get_tick()) - tick) > timeout)
				return TIMEOUT;
		}
	}

	for (i = 0; i < 16; ++i) {
		if ((hperh->perh->STAT & SPI_STAT_RXE_MSK) == SPI_STAT_RXE_MSK)
			tmp = hperh->perh->DATA;
		else
			break;
	}

	UNUSED(tmp);
	return OK;
}

/**
  * @brief  Receive some double-bytes fast in blocking mode.
  * @note   Bit width is 16-bits. Supports mode: Master.
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  buf: Data to be received.
  * @param  size: Length of data. Unit is double-bytes.
  * @retval status: OK/TIMEOUT
  */
ald_status_t ald_spi_master_recv_dbytes_fast(spi_handle_t *hperh, uint8_t *buf, uint32_t size)
{
	uint16_t cnt = 8000;

	while (size--) {
		hperh->perh->DATA = 0xFFFF;
		cnt = 8000;
		while (((hperh->perh->STAT & SPI_STAT_RXE_MSK) == SPI_STAT_RXE_MSK) && (--cnt));

		if (cnt) {
			*(uint16_t *)buf = (uint16_t)hperh->perh->DATA;
			buf += 2;
		}
		else {
			return TIMEOUT;
		}
	}

	return OK;
}

/**
  * @brief  Receive some double-bytes fast in blocking mode.
  * @note   Bit width is 16-bits. Supports mode: Slave.
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  buf: Data to be received.
  * @param  size: Length of data. Unit is double-bytes.
  * @param  timeout: Timeout between two dbytes.
  * @retval status: OK/TIMEOUT
  */
ald_status_t ald_spi_slave_recv_dbytes_fast(spi_handle_t *hperh, uint8_t *buf, uint32_t size, uint32_t timeout)
{
	uint32_t tick;

	while (size--) {
		tick = ald_get_tick();

		while ((hperh->perh->STAT & SPI_STAT_RXE_MSK) == SPI_STAT_RXE_MSK) {
			if (((ald_get_tick()) - tick) > timeout)
				return TIMEOUT;
		}

		*(uint16_t *)buf = (uint16_t)hperh->perh->DATA;
		buf += 2;
	}

	return OK;
}
/**
  * @}
  */

/** @defgroup SPI_Public_Functions_Group3 IO operation functions
  * @brief SPI Transmit and Receive functions
  *
  * @verbatim
  ==============================================================================
                      ##### IO operation functions #####
 ===============================================================================
    This subsection provides a set of functions allowing to manage the SPI
    data transfers.

    [..] The SPI supports master or slave mode:

    (#) There are two modes of transfer:
       (++) Blocking mode: The communication is performed in polling mode.
            The ALD status of all data processing is returned by the same function
            after finishing transfer.
       (++) No-Blocking mode: The communication is performed using Interrupts
            or DMA, These APIs return the ALD status.
            The end of the data processing will be indicated through the
            dedicated SPI IRQ when using Interrupt mode or the DMA IRQ when
            using DMA mode.
            The hperh->tx_cplt_cbk(), hperh->rx_cplt_cbk() and hperh->tx_rx_cplt_cbk() user callbacks
            will be executed respectivelly at the end of the transmit or Receive process
            The hperh->err_cbk() user callback will be executed when a communication error is detected

    (#) APIs provided for these 2 transfer modes (Blocking mode or Non blocking mode using either Interrupt or DMA)
        exist for 1Line (simplex) and 2Lines (full duplex) modes.

  * @endverbatim
  * @{
  */
/**
  * @brief  Transmit an amount of data in blocking mode.
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  buf: Pointer to data buffer
  * @param  size: Amount of data to be sent
  * @param  timeout: Timeout duration
  * @retval Status, see @ref ald_status_t.
  */
ald_status_t ald_spi_send(spi_handle_t *hperh, uint8_t *buf, uint16_t size, uint32_t timeout)
{
	uint32_t tick;
	uint16_t temp;

	assert_param(IS_SPI(hperh->perh));

	if (hperh->state != SPI_STATE_READY)
		return BUSY;
	if (buf == NULL || size == 0)
		return ERROR;

	hperh->state = SPI_STATE_BUSY_TX;

	if (hperh->init.crc_calc)
		SPI_CRC_RESET(hperh);

	while (size > 1) {
		tick = ald_get_tick();

		while ((hperh->perh->STAT & SPI_STATUS_TXE) == RESET) {
			if (((ald_get_tick()) - tick) > timeout)
				goto timeout;
		}

		if (hperh->init.data_size == SPI_DATA_SIZE_8) {
            while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
			hperh->perh->DATA = *buf;
			++buf;
		}
		else {
            while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
			hperh->perh->DATA = (*(uint16_t *)buf);
			buf += 2;
		}

		--size;
	}

	tick = ald_get_tick();

	while ((hperh->perh->STAT & SPI_STATUS_TXE) == RESET) {
		if (((ald_get_tick()) - tick) > timeout)
			goto timeout;
	}

	if (hperh->init.crc_calc) {
		if (hperh->init.data_size == SPI_DATA_SIZE_8)
        {
            while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
			hperh->perh->DATA = *buf;
        }
		else
        {
            while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
			hperh->perh->DATA = (*(uint16_t *)buf);
        }

		SPI_CRCNEXT_ENABLE(hperh);
	}
	else {
		if (hperh->init.data_size == SPI_DATA_SIZE_8)
        {
            while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
			hperh->perh->DATA = *buf;
        }
		else
        {
            while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
			hperh->perh->DATA = (*(uint16_t *)buf);
        }
	}

	while ((hperh->perh->STAT & SPI_STATUS_TXE) == RESET) {
		if (((ald_get_tick()) - tick) > timeout)
			goto timeout;
	}

	while ((hperh->perh->STAT & SPI_STATUS_BUSY) != RESET) {
		if (((ald_get_tick()) - tick) > timeout)
			goto timeout;
	}

	while ((spi_get_status(hperh, SPI_STATUS_RXE)) == RESET) {
		temp = hperh->perh->DATA;
		UNUSED(temp);
	}

	hperh->state = SPI_STATE_READY;
	return OK;
timeout:
	if (hperh->init.crc_calc)
		SPI_CRC_RESET(hperh);

	hperh->state = SPI_STATE_READY;
	return TIMEOUT;
}

/**
  * @brief  Receive an amount of data in blocking mode.
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  buf: Pointer to data buffer
  * @param  size: Amount of data to be received
  * @param  timeout: Timeout duration
  * @retval Status, see @ref ald_status_t.
  */
ald_status_t ald_spi_recv(spi_handle_t *hperh, uint8_t *buf, uint16_t size, uint32_t timeout)
{
	uint32_t tick;
	uint16_t temp;

	assert_param(IS_SPI(hperh->perh));

	if (hperh->state != SPI_STATE_READY)
		return BUSY;
	if (buf == NULL || size == 0)
		return ERROR;

	if (hperh->init.mode == SPI_MODE_MASTER)
		return ald_spi_send_recv(hperh, buf, buf, size, timeout);

	hperh->state    = SPI_STATE_BUSY_RX;
	hperh->err_code = SPI_ERROR_NONE;

	if (hperh->init.crc_calc)
		SPI_CRC_RESET(hperh);

	while (size > 0) {
		tick = ald_get_tick();

		while ((hperh->perh->STAT & SPI_STATUS_RXE) != RESET) {
			if (((ald_get_tick()) - tick) > timeout)
				goto timeout;
		}

		if (hperh->init.data_size == SPI_DATA_SIZE_8) {
			*buf = hperh->perh->DATA;
			++buf;
		}
		else {
			*(uint16_t *)buf = hperh->perh->DATA;
			buf += 2;
		}

		--size;
	}

	if (hperh->init.crc_calc) {
		tick = ald_get_tick();

		while ((hperh->perh->STAT & SPI_STATUS_RXTH) != RESET) {
			if (((ald_get_tick()) - tick) > timeout)
				goto timeout;
		}

		temp = hperh->perh->DATA;
		UNUSED(temp);

		if ((hperh->perh->RIF & SPI_IF_CRCERR) != RESET) {
			hperh->err_code |= SPI_ERROR_CRC;
			SPI_CRC_RESET(hperh);
			ald_spi_clear_flag_status(hperh, SPI_IF_CRCERR);
			hperh->state = SPI_STATE_READY;

			return ERROR;
		}
	}

	hperh->state = SPI_STATE_READY;
	return OK;

timeout:
	if (hperh->init.crc_calc)
		SPI_CRC_RESET(hperh);

	hperh->state = SPI_STATE_READY;
	return TIMEOUT;
}

/**
  * @brief  Full-Duplex Send receive an amount of data in full-duplex mode (blocking mode).
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  tx_buf: Pointer to data transmitted buffer
  * @param  rx_buf: Pointer to data received buffer
  * @param  size: Amount of data to be sent
  * @param  timeout: Timeout duration
  * @retval Status, see @ref ald_status_t.
  */
ald_status_t ald_spi_send_recv(spi_handle_t *hperh, uint8_t *tx_buf, uint8_t *rx_buf, uint16_t size, uint32_t timeout)
{
	uint32_t tick;
	uint16_t temp;

	assert_param(IS_SPI(hperh->perh));

	if (hperh->state != SPI_STATE_READY)
		return BUSY;
	if (hperh->init.dir != SPI_DIRECTION_2LINES)
		return ERROR;
	if (tx_buf == NULL || rx_buf == NULL || size == 0)
		return ERROR;

	hperh->state    = SPI_STATE_BUSY_TX_RX;
	hperh->err_code = SPI_ERROR_NONE;

	if (hperh->init.crc_calc)
		SPI_CRC_RESET(hperh);

	while (size > 1) {
		tick = ald_get_tick();

		while ((hperh->perh->STAT & SPI_STATUS_TXE) == RESET) {
			if (((ald_get_tick()) - tick) > timeout)
				goto timeout;
		}

		if (hperh->init.data_size == SPI_DATA_SIZE_8) {
            while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
			hperh->perh->DATA = *tx_buf;
			++tx_buf;
		}
		else {
            while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
			hperh->perh->DATA = (*(uint16_t *)tx_buf);
			tx_buf += 2;
		}

		tick = ald_get_tick();

		while ((hperh->perh->STAT & SPI_STATUS_RXE) != RESET) {
			if (((ald_get_tick()) - tick) > timeout)
				goto timeout;
		}

		if (hperh->init.data_size == SPI_DATA_SIZE_8) {
			*rx_buf = (uint8_t)hperh->perh->DATA;
			++rx_buf;
		}
		else {
			(*(uint16_t *)rx_buf) = hperh->perh->DATA;
			rx_buf += 2;
		}

		--size;
	}

	tick = ald_get_tick();

	while ((hperh->perh->STAT & SPI_STATUS_TXE) == RESET) {
		if (((ald_get_tick()) - tick) > timeout)
			goto timeout;
	}

	if (hperh->init.data_size == SPI_DATA_SIZE_8) {
		if (hperh->init.crc_calc) {
            while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
			hperh->perh->DATA = *tx_buf;
			SPI_CRCNEXT_ENABLE(hperh);
		}
		else {
            while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
			hperh->perh->DATA = *tx_buf;
		}
	}
	else {
		if (hperh->init.crc_calc) {
            while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
			hperh->perh->DATA = (*(uint16_t *)tx_buf);
			SPI_CRCNEXT_ENABLE(hperh);
		}
		else {
            while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
			hperh->perh->DATA = (*(uint16_t *)tx_buf);
		}
	}

	tick = ald_get_tick();

	while ((hperh->perh->STAT & SPI_STATUS_RXE) != RESET) {
		if (((ald_get_tick()) - tick) > timeout)
			goto timeout;
	}

	if (hperh->init.data_size == SPI_DATA_SIZE_8)
		*rx_buf = (uint8_t)hperh->perh->DATA;
	else
		(*(uint16_t *)rx_buf) = hperh->perh->DATA;

	if (hperh->init.crc_calc) {
		tick = ald_get_tick();

		while ((hperh->perh->STAT & SPI_STATUS_TXE) == RESET) {
			if (((ald_get_tick()) - tick) > timeout)
				goto timeout;
		}

		tick = ald_get_tick();

		while ((hperh->perh->STAT & SPI_STATUS_RXE) != RESET) {
			if (((ald_get_tick()) - tick) > timeout)
				goto timeout;
		}

		temp = hperh->perh->DATA;
		UNUSED(temp);

		if (ald_spi_get_flag_status(hperh, SPI_IF_CRCERR) != RESET) {
			hperh->err_code |= SPI_ERROR_CRC;
			SPI_CRC_RESET(hperh);
			ald_spi_clear_flag_status(hperh, SPI_IF_CRCERR);
			hperh->state = SPI_STATE_READY;

			return ERROR;
		}
	}

	while ((hperh->perh->STAT & SPI_STATUS_BUSY) != RESET) {
		if (((ald_get_tick()) - tick) > timeout)
			goto timeout;
	}

	hperh->state = SPI_STATE_READY;
	return OK;
timeout:
	if (hperh->init.crc_calc)
		SPI_CRC_RESET(hperh);

	hperh->state = SPI_STATE_READY;
	return TIMEOUT;
}

/**
  * @brief  Wraps up transmission in non blocking mode.
  * @param  hperh: pointer to a spi_handle_t structure.
  * @param  buf: Pointer to data transmitted buffer
  * @param  size: Amount of data to be sent
  * @retval Status, see @ref ald_status_t.
  */
ald_status_t ald_spi_send_by_it(spi_handle_t *hperh, uint8_t *buf, uint16_t size)
{
	assert_param(IS_SPI(hperh->perh));

	if (hperh->state != SPI_STATE_READY)
		return BUSY;
	if (buf == NULL || size == 0)
		return ERROR;

	__LOCK(hperh);
	hperh->state    = SPI_STATE_BUSY_TX;
	hperh->err_code = SPI_ERROR_NONE;

	hperh->tx_buf   = buf;
	hperh->tx_size  = size;
	hperh->tx_count = size;
	hperh->rx_buf   = NULL;
	hperh->rx_size  = 0;
	hperh->rx_count = 0;
	__UNLOCK(hperh);

	if (hperh->init.crc_calc)
		SPI_CRC_RESET(hperh);

	ald_spi_interrupt_config(hperh, SPI_IT_TXE, ENABLE);

	return OK;
}

/**
  * @brief  Receives an amount of data in non blocking mode
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  buf: Pointer to data received buffer
  * @param  size: Amount of data to be sent
  * @retval Status, see @ref ald_status_t.
  */
ald_status_t ald_spi_recv_by_it(spi_handle_t *hperh, uint8_t *buf, uint16_t size)
{
	assert_param(IS_SPI(hperh->perh));

	if (hperh->state != SPI_STATE_READY)
		return BUSY;
	if (buf == NULL || size == 0)
		return ERROR;
	if ((hperh->init.dir == SPI_DIRECTION_2LINES) && (hperh->init.mode == SPI_MODE_MASTER))
		return ERROR;

	__LOCK(hperh);
	hperh->state    = SPI_STATE_BUSY_RX;
	hperh->err_code = SPI_ERROR_NONE;

	hperh->rx_buf   = buf;
	hperh->rx_size  = size;
	hperh->rx_count = size;
	hperh->tx_buf   = NULL;
	hperh->tx_size  = 0;
	hperh->tx_count = 0;
	__UNLOCK(hperh);

	if (hperh->init.dir == SPI_DIRECTION_1LINE_RX)
		SPI_1LINE_RX(hperh);

	if (hperh->init.crc_calc == ENABLE) {
		SPI_CRC_RESET(hperh);
		ald_spi_interrupt_config(hperh, SPI_IT_CRCERR, ENABLE);
	}

	ald_spi_interrupt_config(hperh, SPI_IT_RXTH, ENABLE);
	ald_spi_interrupt_config(hperh, SPI_IT_MODF, ENABLE);

	if (hperh->init.data_size <= SPI_DATA_SIZE_8) {
		*((uint8_t *)&(hperh->perh->DATA)) = 0xFF;
	}
	else {
		*((uint16_t *)&(hperh->perh->DATA)) = 0xFFFF;
	}

	return OK;
}

/**
  * @brief  Transmit and Receives an amount of data in non blocking mode
  * @param  hperh: Pointer to a spi_handle_t structure that contains
  *         the configuration information for the specified SPI module.
  * @param  tx_buf: Pointer to data transmitted buffer
  * @param  rx_buf: Pointer to data received buffer
  * @param  size: Amount of data to be sent
  * @retval Status, see @ref ald_status_t.
  */
ald_status_t ald_spi_send_recv_by_it(spi_handle_t *hperh, uint8_t *tx_buf, uint8_t *rx_buf, uint16_t size)
{
	assert_param(IS_SPI(hperh->perh));

	if (hperh->state != SPI_STATE_READY)
		return BUSY;
	if (tx_buf == NULL || rx_buf == NULL || size == 0)
		return ERROR;

	__LOCK(hperh);
	hperh->state    = SPI_STATE_BUSY_TX_RX;
	hperh->err_code = SPI_ERROR_NONE;

	hperh->tx_buf   = tx_buf;
	hperh->tx_size  = size;
	hperh->tx_count = size;
	hperh->rx_buf   = rx_buf;
	hperh->rx_size  = size;
	hperh->rx_count = size;
	__UNLOCK(hperh);

	if (hperh->init.crc_calc) {
		SPI_CRC_RESET(hperh);
		ald_spi_interrupt_config(hperh, SPI_IT_CRCERR, ENABLE);
	}

	if ((hperh->init.dir == SPI_DIRECTION_2LINES_RXONLY) || (hperh->init.dir == SPI_DIRECTION_1LINE_RX))
		SPI_ENABLE(hperh);

	ald_spi_interrupt_config(hperh, SPI_IT_RXTH, ENABLE);
	ald_spi_interrupt_config(hperh, SPI_IT_TXE, ENABLE);
 	ald_spi_interrupt_config(hperh, SPI_IT_MODF, ENABLE);

	return OK;
}


/**
  * @brief  Transmit an amount of data used dma channel
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  buf: Pointer to data buffer
  * @param  size: Amount of data to be sent
  * @param  channel: DMA channel as SPI transmit
  * @retval Status, see @ref ald_status_t.
  */
ald_status_t ald_spi_send_by_dma(spi_handle_t *hperh, uint8_t *buf, uint16_t size, uint8_t channel)
{
	assert_param(IS_SPI(hperh->perh));

	if (hperh->state != SPI_STATE_READY)
		return BUSY;
	if (buf == NULL || size == 0)
		return ERROR;

	__LOCK(hperh);
	hperh->state    = SPI_STATE_BUSY_TX;
	hperh->err_code = SPI_ERROR_NONE;

	hperh->tx_buf   = buf;
	hperh->tx_size  = size;
	hperh->tx_count = size;
	hperh->rx_buf   = NULL;
	hperh->rx_size  = 0;
	hperh->rx_count = 0;

	if (hperh->init.dir == SPI_DIRECTION_1LINE)
		SPI_1LINE_TX(hperh);
	if (hperh->init.crc_calc)
		SPI_CRC_RESET(hperh);

	if (hperh->hdmatx.perh == NULL)
		hperh->hdmatx.perh = DMA0;

	hperh->hdmatx.cplt_arg = (void *)hperh;
	hperh->hdmatx.cplt_cbk = spi_dma_send_cplt;

	/* Configure SPI DMA transmit */
	ald_dma_config_struct(&(hperh->hdmatx.config));
	hperh->hdmatx.config.data_width = hperh->init.data_size == SPI_DATA_SIZE_8 ? DMA_DATA_SIZE_BYTE : DMA_DATA_SIZE_HALFWORD;
	hperh->hdmatx.config.src        = (void *)buf;
	hperh->hdmatx.config.dst        = (void *)&hperh->perh->DATA;
	hperh->hdmatx.config.size       = size;
	hperh->hdmatx.config.src_inc    = hperh->init.data_size == SPI_DATA_SIZE_8 ? DMA_DATA_INC_BYTE : DMA_DATA_INC_HALFWORD;
	hperh->hdmatx.config.dst_inc    = DMA_DATA_INC_NONE;
	hperh->hdmatx.config.msel       = hperh->perh == SPI0 ? DMA_MSEL_SPI0 : DMA_MSEL_SPI1 ;
	hperh->hdmatx.config.msigsel    = DMA_MSIGSEL_SPI_TXEMPTY;
	hperh->hdmatx.config.channel    = channel;
	hperh->hdmatx.config.burst      = ENABLE;
	ald_dma_config_basic(&(hperh->hdmatx));

	__UNLOCK(hperh);

	if (READ_BIT(hperh->perh->CON1, SPI_CON1_SPIEN_MSK) == 0)
		SPI_ENABLE(hperh);

	ald_spi_dma_req_config(hperh, SPI_DMA_REQ_TX, ENABLE);

	return OK;
}

/**
  * @brief  Receive an amount of data used dma channel
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  buf: Pointer to data buffer
  * @param  size: Amount of data to be sent
  * @param  channel: DMA channel as SPI transmit
  * @retval Status, see @ref ald_status_t.
  */
ald_status_t ald_spi_recv_by_dma(spi_handle_t *hperh, uint8_t *buf, uint16_t size, uint8_t channel)
{
	uint16_t tmp_rx = 0xB1B2;
	assert_param(IS_SPI(hperh->perh));

	if (hperh->state != SPI_STATE_READY)
		return BUSY;
	if (buf == NULL || size == 0)
		return ERROR;

	__LOCK(hperh);
	hperh->state    = SPI_STATE_BUSY_RX;
	hperh->err_code = SPI_ERROR_NONE;

	hperh->rx_buf   = buf;
	hperh->rx_size  = size;
	hperh->rx_count = size;
	hperh->tx_buf   = NULL;
	hperh->tx_size  = 0;
	hperh->tx_count = 0;

	if (hperh->init.dir == SPI_DIRECTION_1LINE_RX)
		SPI_1LINE_RX(hperh);
	if ((hperh->init.dir == SPI_DIRECTION_2LINES) && (hperh->init.mode == SPI_MODE_MASTER)) {
		__UNLOCK(hperh);
		return ERROR;
	}
	if (hperh->init.crc_calc)
		SPI_CRC_RESET(hperh);

	if (hperh->hdmatx.perh == NULL)
		hperh->hdmatx.perh = DMA0;
	if (hperh->hdmarx.perh == NULL)
		hperh->hdmarx.perh = DMA0;

	hperh->hdmarx.cplt_arg = (void *)hperh;
	hperh->hdmarx.cplt_cbk = spi_dma_recv_cplt;

	/* Configure SPI DMA transmit */
	ald_dma_config_struct(&(hperh->hdmatx.config));
	hperh->hdmatx.config.data_width = hperh->init.data_size == SPI_DATA_SIZE_8 ? DMA_DATA_SIZE_BYTE : DMA_DATA_SIZE_HALFWORD;
	hperh->hdmatx.config.src        = (void *)&tmp_rx;
	hperh->hdmatx.config.dst        = (void *)&hperh->perh->DATA;
	hperh->hdmatx.config.size       = size;
	hperh->hdmatx.config.src_inc    = DMA_DATA_INC_NONE;
	hperh->hdmatx.config.dst_inc    = DMA_DATA_INC_NONE;
	hperh->hdmatx.config.msel       = hperh->perh == SPI0 ? DMA_MSEL_SPI0 :  DMA_MSEL_SPI1 ;
	hperh->hdmatx.config.msigsel    = DMA_MSIGSEL_SPI_TXEMPTY;
	hperh->hdmatx.config.burst      = ENABLE;
	hperh->hdmatx.config.channel    = 11;
	ald_dma_config_basic(&(hperh->hdmatx));

	/* Configure DMA Receive */
	ald_dma_config_struct(&(hperh->hdmarx.config));
	hperh->hdmarx.config.data_width = hperh->init.data_size == SPI_DATA_SIZE_8 ? DMA_DATA_SIZE_BYTE : DMA_DATA_SIZE_HALFWORD;
	hperh->hdmarx.config.src        = (void *)&hperh->perh->DATA;
	hperh->hdmarx.config.dst        = (void *)buf;
	hperh->hdmarx.config.size       = size;
	hperh->hdmarx.config.src_inc    = DMA_DATA_INC_NONE;
	hperh->hdmarx.config.dst_inc    = hperh->init.data_size == SPI_DATA_SIZE_8 ? DMA_DATA_INC_BYTE : DMA_DATA_INC_HALFWORD;;
	hperh->hdmarx.config.msel       = hperh->perh == SPI0 ? DMA_MSEL_SPI0 :  DMA_MSEL_SPI1 ;
	hperh->hdmarx.config.msigsel    = DMA_MSIGSEL_SPI_RNR;
	hperh->hdmatx.config.burst      = ENABLE;
	hperh->hdmarx.config.channel    = channel;
	ald_dma_config_basic(&(hperh->hdmarx));

	__UNLOCK(hperh);

	if ((hperh->init.dir == SPI_DIRECTION_2LINES_RXONLY) || (hperh->init.dir == SPI_DIRECTION_1LINE_RX))
		SPI_ENABLE(hperh);

	ald_spi_dma_req_config(hperh, SPI_DMA_REQ_RX, ENABLE);
	ald_spi_dma_req_config(hperh, SPI_DMA_REQ_TX, ENABLE);

	return OK;
}

/**
  * @brief  Transmit and Receive an amount of data used dma channel
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  tx_buf: Pointer to data buffer
  * @param  rx_buf: Pointer to data buffer
  * @param  size: Amount of data to be sent
  * @param  tx_channel: DMA channel as SPI transmit
  * @param  rx_channel: DMA channel as SPI receive
  * @retval Status, see @ref ald_status_t.
  */
ald_status_t ald_spi_send_recv_by_dma(spi_handle_t *hperh, uint8_t *tx_buf, uint8_t *rx_buf, uint16_t size, uint8_t tx_channel, uint8_t rx_channel)
{
	assert_param(IS_SPI(hperh->perh));

	if (hperh->state != SPI_STATE_READY && hperh->state != SPI_STATE_BUSY_RX)
		return BUSY;
	if (tx_buf == NULL || rx_buf == NULL || size == 0)
		return ERROR;

	__LOCK(hperh);
	hperh->state    = SPI_STATE_BUSY_RX;
	hperh->err_code = SPI_ERROR_NONE;

	hperh->tx_buf   = tx_buf;
	hperh->tx_size  = size;
	hperh->tx_count = size;
	hperh->rx_buf   = rx_buf;
	hperh->rx_size  = size;
	hperh->rx_count = size;

	if (hperh->hdmatx.perh == NULL)
		hperh->hdmatx.perh = DMA0;
	if (hperh->hdmarx.perh == NULL)
		hperh->hdmarx.perh = DMA0;

	hperh->hdmatx.cplt_arg = NULL;
	hperh->hdmatx.cplt_cbk = NULL;
	hperh->hdmarx.cplt_arg = (void *)hperh;
	hperh->hdmarx.cplt_cbk = spi_dma_send_recv_cplt;

	if (hperh->init.crc_calc)
		SPI_CRC_RESET(hperh);

	/* Configure SPI DMA transmit */
	ald_dma_config_struct(&(hperh->hdmatx.config));
	hperh->hdmatx.config.data_width = hperh->init.data_size == SPI_DATA_SIZE_8 ? DMA_DATA_SIZE_BYTE : DMA_DATA_SIZE_HALFWORD;
	hperh->hdmatx.config.src        = (void *)tx_buf;
	hperh->hdmatx.config.dst        = (void *)&hperh->perh->DATA;
	hperh->hdmatx.config.size       = size;
	hperh->hdmatx.config.src_inc    = hperh->init.data_size == SPI_DATA_SIZE_8 ? DMA_DATA_INC_BYTE : DMA_DATA_INC_HALFWORD;
	hperh->hdmatx.config.dst_inc    = DMA_DATA_INC_NONE;
	hperh->hdmatx.config.msel       = hperh->perh == SPI0 ? DMA_MSEL_SPI0 : DMA_MSEL_SPI1 ;
	hperh->hdmatx.config.msigsel    = DMA_MSIGSEL_SPI_TXEMPTY;
	hperh->hdmatx.config.burst      = ENABLE;
	hperh->hdmatx.config.channel    = tx_channel;
	ald_dma_config_basic(&(hperh->hdmatx));

	/* Configure DMA Receive */
	ald_dma_config_struct(&(hperh->hdmarx.config));
	hperh->hdmarx.config.data_width = hperh->init.data_size == SPI_DATA_SIZE_8 ? DMA_DATA_SIZE_BYTE : DMA_DATA_SIZE_HALFWORD;
	hperh->hdmarx.config.src        = (void *)&hperh->perh->DATA;
	hperh->hdmarx.config.dst        = (void *)rx_buf;
	hperh->hdmarx.config.size       = size;
	hperh->hdmarx.config.src_inc    = DMA_DATA_INC_NONE;
	hperh->hdmarx.config.dst_inc    = hperh->init.data_size == SPI_DATA_SIZE_8 ? DMA_DATA_INC_BYTE : DMA_DATA_INC_HALFWORD;;
	hperh->hdmarx.config.msel       = hperh->perh == SPI0 ? DMA_MSEL_SPI0 :  DMA_MSEL_SPI1 ;
	hperh->hdmarx.config.msigsel    = DMA_MSIGSEL_SPI_RNR;
	hperh->hdmarx.config.burst      = ENABLE;
	hperh->hdmarx.config.channel    = rx_channel;
	ald_dma_config_basic(&(hperh->hdmarx));

	__UNLOCK(hperh);
	ald_spi_dma_req_config(hperh, SPI_DMA_REQ_TX, ENABLE);
	ald_spi_dma_req_config(hperh, SPI_DMA_REQ_RX, ENABLE);

	return OK;
}

/**
  * @brief  Pauses the DMA Transfer.
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @retval Status
  */
ald_status_t ald_spi_dma_pause(spi_handle_t *hperh)
{
	assert_param(IS_SPI(hperh->perh));

	__LOCK(hperh);
	ald_spi_dma_req_config(hperh, SPI_DMA_REQ_TX, DISABLE);
	ald_spi_dma_req_config(hperh, SPI_DMA_REQ_RX, DISABLE);
	__UNLOCK(hperh);

	return OK;
}

/**
  * @brief  Resumes the DMA Transfer.
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @retval Status
  */
ald_status_t ald_spi_dma_resume(spi_handle_t *hperh)
{
	assert_param(IS_SPI(hperh->perh));

	__LOCK(hperh);
	ald_spi_dma_req_config(hperh, SPI_DMA_REQ_TX, ENABLE);
	ald_spi_dma_req_config(hperh, SPI_DMA_REQ_RX, ENABLE);
	__UNLOCK(hperh);

	return OK;
}

/**
  * @brief  Stops the DMA Transfer.
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @retval Status
  */
ald_status_t ald_spi_dma_stop(spi_handle_t *hperh)
{
	assert_param(IS_SPI(hperh->perh));

	__LOCK(hperh);
	ald_spi_dma_req_config(hperh, SPI_DMA_REQ_TX, DISABLE);
	ald_spi_dma_req_config(hperh, SPI_DMA_REQ_RX, DISABLE);
	__UNLOCK(hperh);

	hperh->state = SPI_STATE_READY;
	return OK;
}

/**
  * @}
  */

/** @defgroup SPI_Public_Functions_Group4 Control functions
  * @brief SPI Control functions
  *
  * @verbatim
   ===============================================================================
                      ##### Peripheral Control functions #####
   ===============================================================================
    [..]
    This subsection provides a set of functions allowing to control the SPI.
     (+) Handle interrupt about SPI module. The ald_spi_irq_handler() function must
         be invoked by SPI-IRQ function.
     (+) Configure the interrupt DISABLE/ENABLE.
     (+) Configure the DMA request.
     (+) Get interrupt source status.
     (+) Get interrupt flag status.
     (+) Clear interrupt flag

    @endverbatim
  * @{
  */

/**
  * @brief  This function handles SPI interrupt request.
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @retval None
  */
void ald_spi_irq_handler(spi_handle_t *hperh)
{
	if ((hperh->state == SPI_STATE_BUSY_RX) || (hperh->state == SPI_STATE_BUSY_TX)) {
		if ((ald_spi_get_it_status(hperh, SPI_IT_RXTH) != RESET) && (ald_spi_get_flag_status(hperh, SPI_IF_RXTH) != RESET))
			__spi_recv_by_it(hperh);

		if ((ald_spi_get_it_status(hperh, SPI_IT_TXE) != RESET) && (ald_spi_get_flag_status(hperh, SPI_IF_TXE) != RESET))
			__spi_send_by_it(hperh);
	}

	else if (hperh->state == SPI_STATE_BUSY_TX_RX) {
		if (hperh->init.mode == SPI_MODE_SLAVER) {
			if ((ald_spi_get_it_status(hperh, SPI_IT_TXE) != RESET) && (ald_spi_get_flag_status(hperh, SPI_IF_TXE) != RESET))
				__spi_send_recv_by_it(hperh, SPI_SR_TXE);
			if ((ald_spi_get_it_status(hperh, SPI_IT_RXTH) != RESET) && (ald_spi_get_flag_status(hperh, SPI_IF_RXTH) != RESET))
				__spi_send_recv_by_it(hperh, SPI_SR_RXNE);
		}
		else {
			if (hperh->rx_size == hperh->tx_count) {
				if ((ald_spi_get_it_status(hperh, SPI_IT_TXE) != RESET) && (ald_spi_get_flag_status(hperh, SPI_IF_TXE) != RESET))
					__spi_send_recv_by_it(hperh, SPI_SR_TXE);
			}
			else {
				if ((ald_spi_get_it_status(hperh, SPI_IT_TXE) != RESET) && (ald_spi_get_flag_status(hperh, SPI_IF_TXE) != RESET)
				   && (ald_spi_get_it_status(hperh, SPI_IT_RXTH) != RESET) && (ald_spi_get_flag_status(hperh, SPI_IF_RXTH) != RESET))
					__spi_send_recv_by_it(hperh, SPI_SR_TXE_RXNE);
			}
		}

	}

	if (ald_spi_get_flag_status(hperh, SPI_IF_CRCERR) != RESET) {
		hperh->err_code |= SPI_ERROR_CRC;
		ald_spi_clear_flag_status(hperh, SPI_IF_CRCERR);
	}
	if (ald_spi_get_flag_status(hperh, SPI_IF_MODF) != RESET) {
		hperh->err_code |= SPI_ERROR_MODF;
		ald_spi_clear_flag_status(hperh, SPI_IF_MODF);
	}
	if (ald_spi_get_flag_status(hperh, SPI_IF_FRE) != RESET) {
		hperh->err_code |= SPI_ERROR_FRE;
		ald_spi_clear_flag_status(hperh, SPI_IF_FRE);

	}
	if (ald_spi_get_flag_status(hperh, SPI_IF_TXOV) != RESET) {
		if (hperh->state != SPI_STATE_BUSY_TX) {
			hperh->err_code |= SPI_ERROR_TXOV;
			ald_spi_clear_flag_status(hperh, SPI_IF_TXOV);
		}
	}
	if (ald_spi_get_flag_status(hperh, SPI_IF_RXOV) != RESET) {
		if (hperh->state != SPI_STATE_BUSY_RX) {
			hperh->err_code |= SPI_ERROR_RXOV;
			ald_spi_clear_flag_status(hperh, SPI_IF_RXOV);
		}
	}

	return;
}

/**
  * @brief  Enables or disables the specified SPI interrupts.
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  it: Specifies the SPI interrupt sources to be enabled or disabled.
  *         This parameter can be one of the @ref spi_it_t.
  * @param  state: New status
  *           - ENABLE
  *           - DISABLE
  * @retval None
  */
void ald_spi_interrupt_config(spi_handle_t *hperh, spi_it_t it, type_func_t state)
{
	assert_param(IS_SPI(hperh->perh));
	assert_param(IS_SPI_IT(it));
	assert_param(IS_FUNC_STATE(state));

	if (state == ENABLE)
		hperh->perh->IER |= (uint32_t)it;
	else
		hperh->perh->IDR |= (uint32_t)it;

	return;
}

/**
  * @brief  Configure the specified SPI speed.
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  speed: Specifies the SPI speed.
  *         This parameter can be one of the @ref spi_baud_t.
  * @retval None
  */
void ald_spi_speed_config(spi_handle_t *hperh, spi_baud_t speed)
{
	uint32_t tmp = 0;
	assert_param(IS_SPI(hperh->perh));
	assert_param(IS_SPI_BAUD(speed));

	tmp = hperh->perh->CON1;
	tmp &= ~(0x7U << SPI_CON1_BAUD_POSS);
	tmp |= (speed << SPI_CON1_BAUD_POSS);
	hperh->perh->CON1 = tmp;
	return;
}

/**
  * @brief  Enables or disables the dma request.
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  req: Specifies the SPI dma request sources to be enabled or disabled.
  *         This parameter can be one of the @ref spi_dma_req_t.
  * @param  state: New status
  *           - ENABLE
  *           - DISABLE
  * @retval None
  */
void ald_spi_dma_req_config(spi_handle_t *hperh, spi_dma_req_t req, type_func_t state)
{
	assert_param(IS_SPI(hperh->perh));
	assert_param(IS_SPI_DMA_REQ(req));
	assert_param(IS_FUNC_STATE(state));

	if (state == ENABLE) {
		if (req == SPI_DMA_REQ_TX)
			SET_BIT(hperh->perh->CON2, SPI_CON2_TXDMA_MSK);
		else
			SET_BIT(hperh->perh->CON2, SPI_CON2_RXDMA_MSK);
	}
	else {
		if (req == SPI_DMA_REQ_TX)
			CLEAR_BIT(hperh->perh->CON2, SPI_CON2_TXDMA_MSK);
		else
			CLEAR_BIT(hperh->perh->CON2, SPI_CON2_RXDMA_MSK);
	}

	return;
}

/** @brief  Check whether the specified SPI state flag is set or not.
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  status: specifies the flag to check.
  *         This parameter can be one of the @ref spi_status_t.
  * @retval Status
  *           - SET
  *           - RESET
  */
flag_status_t spi_get_status(spi_handle_t *hperh, spi_status_t status)
{
	assert_param(IS_SPI(hperh->perh));
	assert_param(IS_SPI_STATUS(status));

	if (hperh->perh->STAT & status)
		return SET;

	return RESET;
}

/**
  * @brief  Checks whether the specified SPI interrupt has occurred or not.
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  it: Specifies the SPI interrupt source to check.
  *         This parameter can be one of the @ref spi_it_t.
  * @retval Status
  *           - SET
  *           - RESET
  */
it_status_t ald_spi_get_it_status(spi_handle_t *hperh, spi_it_t it)
{
	assert_param(IS_SPI(hperh->perh));
	assert_param(IS_SPI_IT(it));

	if (hperh->perh->IVS & it)
		return SET;

	return RESET;
}

/** @brief  Check whether the specified SPI flag is set or not.
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  flag: specifies the flag to check.
  *         This parameter can be one of the @ref spi_flag_t.
  * @retval Status
  *           - SET
  *           - RESET
  */
flag_status_t ald_spi_get_flag_status(spi_handle_t *hperh, spi_flag_t flag)
{
	assert_param(IS_SPI(hperh->perh));
	assert_param(IS_SPI_IF(flag));

	if (hperh->perh->RIF & flag)
		return SET;

	return RESET;
}

/** @brief  Clear the specified SPI pending flags.
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  flag: specifies the flag to check.
  *         This parameter can be one of the @ref spi_flag_t.
  * @retval None
  */
void ald_spi_clear_flag_status(spi_handle_t *hperh, spi_flag_t flag)
{
	assert_param(IS_SPI(hperh->perh));
	assert_param(IS_SPI_IF(flag));


	hperh->perh->ICR |= flag;
	return;
}


/**
  * @brief  This function handles SPI communication timeout in interrupt function.
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  flag: specifies the SPI flag to check.
  * @param  status: The new Flag status (SET or RESET).
  * @param  timeout: Timeout duration
  * @retval Status, see @ref ald_status_t.
  */
static ald_status_t spi_wait_flag_irq(spi_handle_t *hperh, spi_flag_t flag, flag_status_t status, uint32_t timeout)
{
	assert_param(timeout > 0);

	while (((ald_spi_get_flag_status(hperh, flag)) != status) && (--timeout));

	if (timeout)
		return OK;

	ald_spi_interrupt_config(hperh, SPI_IT_TXE, DISABLE);
	ald_spi_interrupt_config(hperh, SPI_IT_RXTH, DISABLE);
	ald_spi_interrupt_config(hperh, SPI_IT_CRCERR, DISABLE);
	ald_spi_interrupt_config(hperh, SPI_IT_MODF, DISABLE);

	return TIMEOUT;
}


static ald_status_t spi_wait_bsy_flag(spi_handle_t *hperh, flag_status_t status, uint32_t timeout)
{
	assert_param(timeout > 0);

	while ((READ_BIT(hperh->perh->STAT, SPI_STAT_BUSY_MSK)) && (--timeout));

	if (timeout)
		return OK;

	ald_spi_interrupt_config(hperh, SPI_IT_TXE, DISABLE);
	ald_spi_interrupt_config(hperh, SPI_IT_RXTH, DISABLE);
	ald_spi_interrupt_config(hperh, SPI_IT_CRCERR, DISABLE);
	ald_spi_interrupt_config(hperh, SPI_IT_MODF, DISABLE);

	return TIMEOUT;
}

/**
  * @}
  */

/** @defgroup SPI_Public_Functions_Group5 Peripheral State and Errors functions
  *  @brief   SPI State and Errors functions
  *
  * @verbatim
 ===============================================================================
                      ##### Peripheral State and Errors functions #####
 ===============================================================================
    [..]
    This subsection provides a set of functions allowing to control the SPI.
     (+) ald_spi_get_state() API can check in run-time the state of the SPI peripheral
     (+) ald_spi_get_error() check in run-time Errors occurring during communication

    @endverbatim
  * @{
  */

/**
  * @brief  Returns the SPI state.
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @retval ALD state
  */
spi_state_t ald_spi_get_state(spi_handle_t *hperh)
{
	assert_param(IS_SPI(hperh->perh));
	return hperh->state;
}

/**
  * @brief  Return the SPI error code
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @retval SPI Error Code
  */
uint32_t ald_spi_get_error(spi_handle_t *hperh)
{
	assert_param(IS_SPI(hperh->perh));
	return hperh->err_code;
}
/**
  * @}
  */

/**
  * @}
  */

/** @defgroup SPI_Private_Functions SPI Private Functions
  * @brief   SPI Private functions
  * @{
  */

/**
  * @brief  handle program when an tx empty interrupt flag arrived in non block mode
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @retval Status, see @ref ald_status_t.
  */
static void __spi_send_by_it(spi_handle_t *hperh)
{
	uint16_t temp;

	if (hperh->tx_count == 0) {
		ald_spi_interrupt_config(hperh, SPI_IT_TXE, DISABLE);
		hperh->state = SPI_STATE_READY;

		if (hperh->init.dir == SPI_DIRECTION_2LINES) {
			ald_spi_clear_flag_status(hperh, SPI_IF_TXOV);
		}

		if ((spi_wait_bsy_flag(hperh, RESET, 5000)) != OK) {
			if (hperh->err_cbk)
				hperh->err_cbk(hperh);

			return;
		}

		while ((spi_get_status(hperh, SPI_STATUS_RXE)) == RESET) {
			temp = hperh->perh->DATA;
			UNUSED(temp);
		}

		if (hperh->tx_cplt_cbk)
			hperh->tx_cplt_cbk(hperh);

		return;
	}

	ald_spi_clear_flag_status(hperh, SPI_IF_TXE);

	if (hperh->tx_count == 1) {
		if (hperh->init.data_size == SPI_DATA_SIZE_8) {
			if (hperh->init.crc_calc) {
                while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
				hperh->perh->DATA = *hperh->tx_buf;
				SPI_CRCNEXT_ENABLE(hperh);
			}
			else {
                while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
				hperh->perh->DATA = *hperh->tx_buf;
			}

			++hperh->tx_buf;
		}
		else {
			if (hperh->init.crc_calc) {
                while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
				hperh->perh->DATA = *(uint16_t *)hperh->tx_buf;
				SPI_CRCNEXT_ENABLE(hperh);
			}
			else
            {
                while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
				hperh->perh->DATA = *(uint16_t *)hperh->tx_buf;
            }

			hperh->tx_buf += 2;
		}
	}
	else {
		if (hperh->init.data_size == SPI_DATA_SIZE_8) {
            while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
			hperh->perh->DATA = *hperh->tx_buf;
			++hperh->tx_buf;
		}
		else {
            while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
			hperh->perh->DATA = *(uint16_t *)hperh->tx_buf;
			hperh->tx_buf    += 2;
		}
	}

	--hperh->tx_count;
	return;
}

/**
  * @brief  handle program when an rx no empty interrupt flag arrived in non block mode
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @retval Status, see @ref ald_status_t.
  */
static void __spi_recv_by_it(spi_handle_t *hperh)
{
	uint16_t temp;

	while (READ_BITS(hperh->perh->STAT, SPI_STAT_RXFLV_MSK, SPI_STAT_RXFLV_POSS)) {
		if (hperh->init.data_size == SPI_DATA_SIZE_8) {
			*hperh->rx_buf = hperh->perh->DATA;
			++hperh->rx_buf;
		}
		else {
			*(uint16_t *)hperh->rx_buf = hperh->perh->DATA;
			hperh->rx_buf += 2;
		}

		--hperh->rx_count;
	}

	ald_spi_clear_flag_status(hperh, SPI_IF_RXTH);

	if (hperh->rx_count == 0) {
		ald_spi_interrupt_config(hperh, SPI_IT_RXTH, DISABLE);
		hperh->state = SPI_STATE_READY;

		if ((hperh->init.crc_calc) && (ald_spi_get_flag_status(hperh, SPI_IF_CRCERR) != RESET)) {
			hperh->err_code |= SPI_ERROR_CRC;
			ald_spi_clear_flag_status(hperh, SPI_IF_CRCERR);

			if (hperh->err_cbk)
				hperh->err_cbk(hperh);

			return;
		}

		if (hperh->init.crc_calc) {
			temp = hperh->perh->DATA;
			UNUSED(temp);
		}

		if (hperh->rx_cplt_cbk)
			hperh->rx_cplt_cbk(hperh);
	}

	if (hperh->init.data_size <= SPI_DATA_SIZE_8) {
		hperh->perh->DATA = 0xff;
	}
	else {
		hperh->perh->DATA = 0xffff;
	}

	return;
}

/**
  * @brief  handle program when an rx no empty interrupt flag arrived in non block mode(2 lines)
  * @param  hperh: Pointer to a spi_handle_t structure.
  * @param  status: SR.TXE or SR.RXNE set.
  * @retval Status, see @ref ald_status_t.
  */
static void __spi_send_recv_by_it(spi_handle_t *hperh, spi_sr_status_t status)
{
	if (hperh->rx_count != 0) {
		if ((status == SPI_SR_RXNE) || (status == SPI_SR_TXE_RXNE)) {
			ald_spi_clear_flag_status(hperh, SPI_IF_RXTH);
			while (spi_get_status(hperh, SPI_STATUS_RXTH) != RESET) {
				if (hperh->init.data_size == SPI_DATA_SIZE_8) {
					*hperh->rx_buf = hperh->perh->DATA;
					++hperh->rx_buf;
				}
				else {
					*(uint16_t *)hperh->rx_buf = hperh->perh->DATA;
					hperh->rx_buf += 2;
				}
				--hperh->rx_count;
			}
		}
	}

	if (hperh->tx_count != 0) {
		if ((status == SPI_SR_TXE) || (status == SPI_SR_TXE_RXNE)) {
			ald_spi_clear_flag_status(hperh, SPI_IF_TXE);
			if (hperh->tx_count == 1) {
				if (hperh->init.data_size == SPI_DATA_SIZE_8) {
					if (hperh->init.crc_calc) {
                        while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
						hperh->perh->DATA = *hperh->tx_buf;
						SPI_CRCNEXT_ENABLE(hperh);
					}
					else {
                        while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
						hperh->perh->DATA = *hperh->tx_buf;
					}

					++hperh->tx_buf;
				}
				else {
					if (hperh->init.crc_calc) {
                        while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
						hperh->perh->DATA = *(uint16_t *)hperh->tx_buf;
						SPI_CRCNEXT_ENABLE(hperh);
					}
					else {
                        while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
						hperh->perh->DATA = *(uint16_t *)hperh->tx_buf;
					}

					hperh->tx_buf += 2;
				}

				--hperh->tx_count;
			}
			else {
				if (hperh->init.data_size == SPI_DATA_SIZE_8) {
                    while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
					hperh->perh->DATA = *hperh->tx_buf;
					++hperh->tx_buf;
				}
				else {
                    while(hperh->perh->STAT & SPI_STAT_TXF_MSK);
					hperh->perh->DATA = *(uint16_t *)hperh->tx_buf;
					hperh->tx_buf    += 2;
				}

				--hperh->tx_count;
			}
		}
	}

	if (hperh->rx_count == 0) {
		ald_spi_interrupt_config(hperh, SPI_IT_TXE, DISABLE);
		ald_spi_interrupt_config(hperh, SPI_IT_RXTH, DISABLE);
		ald_spi_interrupt_config(hperh, SPI_IT_MODF, DISABLE);
		hperh->state = SPI_STATE_READY;

		if ((hperh->init.crc_calc) && (ald_spi_get_flag_status(hperh, SPI_IF_CRCERR) != RESET)) {
			hperh->err_code |= SPI_ERROR_CRC;
			ald_spi_clear_flag_status(hperh, SPI_IF_CRCERR);

			if (hperh->err_cbk)
				hperh->err_cbk(hperh);

			return;
		}

		if (hperh->tx_rx_cplt_cbk)
			hperh->tx_rx_cplt_cbk(hperh);
	}

	return;
}


/**
  * @brief  DMA SPI transmit process complete callback.
  * @param  arg: Pointer to a spi_handle_t structure.
  * @retval None
  */
static void spi_dma_send_cplt(void *arg)
{
	uint16_t delay, temp;
	spi_handle_t *hperh = (spi_handle_t *)arg;

	hperh->tx_count = 0;
	ald_spi_dma_req_config(hperh, SPI_DMA_REQ_TX, DISABLE);
	hperh->state = SPI_STATE_READY;

	while ((spi_get_status(hperh, SPI_STATUS_RXE)) == RESET) {
		temp = hperh->perh->DATA;
		UNUSED(temp);
	}

	if (hperh->init.dir == SPI_DIRECTION_2LINES)
		ald_spi_clear_flag_status(hperh, SPI_IF_TXOV);

	if ((spi_wait_bsy_flag(hperh, RESET, 5000)) != OK)
		hperh->err_code |= SPI_ERROR_FLAG;

	for (delay = 0; delay < 3000; delay++);

	if (hperh->err_code == SPI_ERROR_NONE) {
		if (hperh->tx_cplt_cbk)
			hperh->tx_cplt_cbk(hperh);
	}
	else {
		if (hperh->err_cbk)
			hperh->err_cbk(hperh);
	}

	return;
}

/**
  * @brief  DMA SPI receive process complete callback.
  * @param  arg: Pointer to a spi_handle_t structure.
  * @retval None
  */
static void spi_dma_recv_cplt(void *arg)
{
	uint32_t tmp;
	spi_handle_t *hperh = (spi_handle_t *)arg;

	hperh->rx_count = 0;
	ald_spi_dma_req_config(hperh, SPI_DMA_REQ_TX, DISABLE);
	ald_spi_dma_req_config(hperh, SPI_DMA_REQ_RX, DISABLE);
	hperh->state = SPI_STATE_READY;

	if (hperh->init.crc_calc) {
		if ((spi_wait_flag_irq(hperh, SPI_IF_RXTH, SET, 5000)) != OK)
			hperh->err_code |= SPI_ERROR_FLAG;

		tmp = hperh->perh->DATA;
		UNUSED(tmp);

		if (ald_spi_get_flag_status(hperh, SPI_IF_CRCERR) == SET) {
			SET_BIT(hperh->err_code, SPI_ERROR_CRC);
			SPI_CRC_RESET(hperh);
			ald_spi_clear_flag_status(hperh, SPI_IF_CRCERR);
		}
	}

	if (hperh->err_code == SPI_ERROR_NONE) {
		if (hperh->rx_cplt_cbk)
			hperh->rx_cplt_cbk(hperh);
	}
	else {
		if (hperh->err_cbk)
			hperh->err_cbk(hperh);
	}

	return;
}

/**
  * @brief  DMA SPI transmit and receive process complete callback.
  * @param  arg: Pointer to a SPI_handle_t structure.
  * @retval None
  */
static void spi_dma_send_recv_cplt(void *arg)
{
	uint32_t tmp;
	uint16_t delay;
	spi_handle_t *hperh = (spi_handle_t *)arg;

	if (hperh->init.crc_calc) {
		if ((spi_wait_flag_irq(hperh, SPI_IF_RXTH, SET, 5000)) != OK)
			hperh->err_code |= SPI_ERROR_FLAG;

		tmp = hperh->perh->DATA;
		UNUSED(tmp);

		if (ald_spi_get_flag_status(hperh, SPI_IF_CRCERR) == SET) {
			SET_BIT(hperh->err_code, SPI_ERROR_CRC);
			ald_spi_clear_flag_status(hperh, SPI_IF_CRCERR);
		}
	}

	if ((spi_wait_bsy_flag(hperh, RESET, 5000)) != OK)
		hperh->err_code |= SPI_ERROR_FLAG;

	for (delay = 0; delay < 3000; delay++);

	ald_spi_dma_req_config(hperh, SPI_DMA_REQ_TX, DISABLE);
	ald_spi_dma_req_config(hperh, SPI_DMA_REQ_RX, DISABLE);
	hperh->tx_count = 0;
	hperh->rx_count = 0;
	hperh->state    = SPI_STATE_READY;

	if (hperh->err_code == SPI_ERROR_NONE) {
		if (hperh->tx_rx_cplt_cbk)
			hperh->tx_rx_cplt_cbk(hperh);
	}
	else {
		if (hperh->err_cbk)
			hperh->err_cbk(hperh);
	}

	return;
}


/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************* (C) COPYRIGHT Eastsoft Microelectronics *****END OF FILE****/
