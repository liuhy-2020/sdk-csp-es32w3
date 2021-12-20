/*
 * Copyright (C) 2021 Shanghai Eastsoft Microelectronics Co., Ltd.
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
 * Change Logs:
 * Date           Author        Notes  
 * 2021-04-20     liuhy         the first version
 */

#include "string.h"
#include "board.h"
#include "drv_uart.h"
#include "es_conf_info_map.h"
#include <ald_uart.h>
#include <ald_gpio.h>
#include <ald_cmu.h>

/* es32 uart driver */
struct es32_uart
{
    uart_handle_t huart;
};
struct es32_uart *console_uart = 0;

static uint32_t es32f3x_configure(struct es32_uart *uart)
{

    gpio_init_t gpio_initstructure;

    /* Initialize tx pin */
    gpio_initstructure.mode = GPIO_MODE_OUTPUT;
    gpio_initstructure.odos = GPIO_PUSH_PULL;
    gpio_initstructure.pupd = GPIO_PUSH_UP;
    gpio_initstructure.odrv = GPIO_OUT_DRIVE_NORMAL;
    gpio_initstructure.flt  = GPIO_FILTER_DISABLE;
    gpio_initstructure.type = GPIO_TYPE_TTL;

    switch((unsigned long)(uart->huart.perh))
    {

#ifdef BSP_USING_UART0
    case ((unsigned long)UART0):
#if  defined(ES_UART0_TX_GPIO_FUNC)&&defined(ES_UART0_TX_GPIO_PORT)&&defined(ES_UART0_TX_GPIO_PIN)
        gpio_initstructure.func = ES_UART0_TX_GPIO_FUNC;
        ald_gpio_init(ES_UART0_TX_GPIO_PORT, ES_UART0_TX_GPIO_PIN, &gpio_initstructure);
#endif

#if  defined(ES_UART0_RX_GPIO_FUNC)&&defined(ES_UART0_RX_GPIO_PORT)&&defined(ES_UART0_RX_GPIO_PIN)        
        /* Initialize rx pin ,the same as txpin except mode */
        gpio_initstructure.mode = GPIO_MODE_INPUT;
        gpio_initstructure.func = ES_UART0_RX_GPIO_FUNC;
        ald_gpio_init(ES_UART0_RX_GPIO_PORT, ES_UART0_RX_GPIO_PIN, &gpio_initstructure);
#endif
        ald_cmu_perh_clock_config(CMU_PERH_UART0, ENABLE);
	break;
#endif /* uart0 gpio init */

#ifdef BSP_USING_UART1
    case ((unsigned long)UART1):
#if  defined(ES_UART1_TX_GPIO_FUNC)&&defined(ES_UART1_TX_GPIO_PORT)&&defined(ES_UART1_TX_GPIO_PIN)  
        gpio_initstructure.func = ES_UART1_TX_GPIO_FUNC;
        ald_gpio_init(ES_UART1_TX_GPIO_PORT, ES_UART1_TX_GPIO_PIN, &gpio_initstructure);
#endif

#if  defined(ES_UART1_RX_GPIO_FUNC)&&defined(ES_UART1_RX_GPIO_PORT)&&defined(ES_UART1_RX_GPIO_PIN) 
        /* Initialize rx pin ,the same as txpin except mode */
        gpio_initstructure.mode = GPIO_MODE_INPUT;
        gpio_initstructure.func = ES_UART1_RX_GPIO_FUNC;
        ald_gpio_init(ES_UART1_RX_GPIO_PORT, ES_UART1_RX_GPIO_PIN, &gpio_initstructure);
#endif

    ald_cmu_perh_clock_config(CMU_PERH_UART1, ENABLE);
	break;
#endif /* uart1 gpio init */

#ifdef BSP_USING_UART2
    case ((unsigned long)UART2):
#if  defined(ES_UART2_TX_GPIO_FUNC)&&defined(ES_UART2_TX_GPIO_PORT)&&defined(ES_UART2_TX_GPIO_PIN)
        gpio_initstructure.func = ES_UART2_TX_GPIO_FUNC;
        ald_gpio_init(ES_UART2_TX_GPIO_PORT, ES_UART2_TX_GPIO_PIN, &gpio_initstructure);
#endif

#if  defined(ES_UART2_RX_GPIO_FUNC)&&defined(ES_UART2_RX_GPIO_PORT)&&defined(ES_UART2_RX_GPIO_PIN)
        /* Initialize rx pin ,the same as txpin except mode */
        gpio_initstructure.mode = GPIO_MODE_INPUT;
        gpio_initstructure.func = ES_UART2_RX_GPIO_FUNC;
        ald_gpio_init(ES_UART2_RX_GPIO_PORT, ES_UART2_RX_GPIO_PIN, &gpio_initstructure);
#endif

    ald_cmu_perh_clock_config(CMU_PERH_UART2, ENABLE);
	break;
#endif /* uart2 gpio init */

    default:break;
    }


    ald_uart_tx_fifo_config(&(uart->huart), UART_TXFIFO_EMPTY);
    ald_uart_rx_fifo_config(&(uart->huart), UART_RXFIFO_1BYTE);

    uart->huart.init.mode        = UART_MODE_UART;
    uart->huart.init.baud        = 115200;
    uart->huart.init.word_length = UART_WORD_LENGTH_8B;
    uart->huart.init.stop_bits   = UART_STOP_BITS_1;
    uart->huart.init.parity      = UART_PARITY_NONE;
    uart->huart.init.fctl        = UART_HW_FLOW_CTL_DISABLE;
    ald_uart_init(&(uart->huart));

    return 0;
}

#ifdef BSP_USING_UART0
/* UART0 device driver structure */
struct es32_uart uart0 =
{
    {UART0}
};

#endif /* BSP_USING_UART0 */

#ifdef BSP_USING_UART1
/* UART1 device driver structure */
struct es32_uart uart1 =
{
    {UART1}
};

#endif /* BSP_USING_UART1 */

#ifdef BSP_USING_UART2
/* UART2 device driver structure */
struct es32_uart uart2 =
{
    {UART2}
};

#endif /* BSP_USING_UART2 */

int rt_hw_uart_init(void)
{

#ifdef BSP_USING_UART0
    es32f3x_configure(&uart0);
    if(!console_uart)console_uart = &uart0;
#endif /* BSP_USING_UART0 */

#ifdef BSP_USING_UART1
    es32f3x_configure(&uart1);
    if(!console_uart)console_uart = &uart1;
#endif /* BSP_USING_UART1 */

#ifdef BSP_USING_UART2
    es32f3x_configure(&uart2);
    if(!console_uart)console_uart = &uart2;
#endif /* BSP_USING_UART2 */

    return 0;
}
//INIT_BOARD_EXPORT(rt_hw_uart_init);


static int es32f3x_putc(struct es32_uart *uart, char c)
{

    while (ald_uart_get_status(&uart->huart, UART_STATUS_TFEMPTY) == RESET)
        ;
    WRITE_REG(uart->huart.perh->TXBUF, c);

    return 1;
}

void print_char(char c)
{
    es32f3x_putc(console_uart,c);
}

#ifdef RT_USING_FINSH

static int es32f3x_getc(struct es32_uart *uart)
{
    int ch = -1;

    if (ald_uart_get_status(&uart->huart, UART_STATUS_RFTH))
    {
        ch = (uint8_t)(uart->huart.perh->RXBUF & 0xFF);
    }

    return ch;
}

char rt_hw_console_getchar(void)
{
    if(!console_uart)return -1;
    return es32f3x_getc(console_uart);
}

#endif /* RT_USING_FINSH */
