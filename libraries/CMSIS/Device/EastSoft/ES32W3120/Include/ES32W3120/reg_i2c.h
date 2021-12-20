/**
  **************************************************************************************
  * @file    REG_I2CX.h
  * @brief   I2CX Head File
  *
  * @version V0.01
  * @data    8/17/2020
  * @author  Eastsoft MCU Software Team
  * @note
  *
  * Copyright (C) 2018 Shanghai Eastsoft Microelectronics Co., Ltd. ALL rights reserved.
  *
  **************************************************************************************
  */

#ifndef __REG_I2Cx_H__
#define __REG_I2Cx_H__


/******************************************************************************/
/*                              设备特殊寄存器结构定义                        */
/******************************************************************************/

/*   允许匿名结构和匿名联合    */
 

/****************** Bit definition for I2C_CON1 register ************************/

#define	I2C_CON1_PECEN_POS	23U 
#define	I2C_CON1_PECEN_MSK	BIT(I2C_CON1_PECEN_POS)

#define	I2C_CON1_ALERTEN_POS	22U 
#define	I2C_CON1_ALERTEN_MSK	BIT(I2C_CON1_ALERTEN_POS)

#define	I2C_CON1_SMBDEN_POS	21U 
#define	I2C_CON1_SMBDEN_MSK	BIT(I2C_CON1_SMBDEN_POS)

#define	I2C_CON1_SMBHEN_POS	20U 
#define	I2C_CON1_SMBHEN_MSK	BIT(I2C_CON1_SMBHEN_POS)

#define	I2C_CON1_GCEN_POS	19U 
#define	I2C_CON1_GCEN_MSK	BIT(I2C_CON1_GCEN_POS)

#define	I2C_CON1_NOSTRETCH_POS	17U 
#define	I2C_CON1_NOSTRETCH_MSK	BIT(I2C_CON1_NOSTRETCH_POS)

#define	I2C_CON1_SBC_POS	16U 
#define	I2C_CON1_SBC_MSK	BIT(I2C_CON1_SBC_POS)

#define	I2C_CON1_RXDMAEN_POS	15U 
#define	I2C_CON1_RXDMAEN_MSK	BIT(I2C_CON1_RXDMAEN_POS)

#define	I2C_CON1_TXDMAEN_POS	14U 
#define	I2C_CON1_TXDMAEN_MSK	BIT(I2C_CON1_TXDMAEN_POS)

#define	I2C_CON1_DNF_POSS	8U 
#define	I2C_CON1_DNF_POSE	11U 
#define	I2C_CON1_DNF_MSK	BITS(I2C_CON1_DNF_POSS,I2C_CON1_DNF_POSE)

#define	I2C_CON1_PE_POS	0U 
#define	I2C_CON1_PE_MSK	BIT(I2C_CON1_PE_POS)

/****************** Bit definition for I2C_CON2 register ************************/

#define	I2C_CON2_ACK_UPD_POS	29U 
#define	I2C_CON2_ACK_UPD_MSK	BIT(I2C_CON2_ACK_UPD_POS)

#define	I2C_CON2_HOLDACK_POS	28U 
#define	I2C_CON2_HOLDACK_MSK	BIT(I2C_CON2_HOLDACK_POS)

#define	I2C_CON2_PECBYTE_POS	26U 
#define	I2C_CON2_PECBYTE_MSK	BIT(I2C_CON2_PECBYTE_POS)

#define	I2C_CON2_AUTOEND_POS	25U 
#define	I2C_CON2_AUTOEND_MSK	BIT(I2C_CON2_AUTOEND_POS)

#define	I2C_CON2_RELOAD_POS	24U 
#define	I2C_CON2_RELOAD_MSK	BIT(I2C_CON2_RELOAD_POS)

#define	I2C_CON2_NBYTES_POSS	16U 
#define	I2C_CON2_NBYTES_POSE	23U 
#define	I2C_CON2_NBYTES_MSK	BITS(I2C_CON2_NBYTES_POSS,I2C_CON2_NBYTES_POSE)

#define	I2C_CON2_NACK_POS	15U 
#define	I2C_CON2_NACK_MSK	BIT(I2C_CON2_NACK_POS)

#define	I2C_CON2_STOP_POS	14U 
#define	I2C_CON2_STOP_MSK	BIT(I2C_CON2_STOP_POS)

#define	I2C_CON2_START_POS	13U 
#define	I2C_CON2_START_MSK	BIT(I2C_CON2_START_POS)

#define	I2C_CON2_HEAD10R_POS	12U 
#define	I2C_CON2_HEAD10R_MSK	BIT(I2C_CON2_HEAD10R_POS)

#define	I2C_CON2_ADD10_POS	11U 
#define	I2C_CON2_ADD10_MSK	BIT(I2C_CON2_ADD10_POS)

#define	I2C_CON2_RD_WRN_POS	10U 
#define	I2C_CON2_RD_WRN_MSK	BIT(I2C_CON2_RD_WRN_POS)

#define	I2C_CON2_SADD_POSS	0U 
#define	I2C_CON2_SADD_POSE	9U 
#define	I2C_CON2_SADD_MSK	BITS(I2C_CON2_SADD_POSS,I2C_CON2_SADD_POSE)

/****************** Bit definition for I2C_ADDR1 register ************************/

#define	I2C_ADDR1_OA1EN_POS	15U 
#define	I2C_ADDR1_OA1EN_MSK	BIT(I2C_ADDR1_OA1EN_POS)

#define	I2C_ADDR1_OA1MODE_POS	10U 
#define	I2C_ADDR1_OA1MODE_MSK	BIT(I2C_ADDR1_OA1MODE_POS)

#define	I2C_ADDR1_OA1_POSS	0U 
#define	I2C_ADDR1_OA1_POSE	9U 
#define	I2C_ADDR1_OA1_MSK	BITS(I2C_ADDR1_OA1_POSS,I2C_ADDR1_OA1_POSE)

/****************** Bit definition for I2C_ADDR2 register ************************/

#define	I2C_ADDR2_OA2EN_POS	15U 
#define	I2C_ADDR2_OA2EN_MSK	BIT(I2C_ADDR2_OA2EN_POS)

#define	I2C_ADDR2_OA2MSK_POSS	8U 
#define	I2C_ADDR2_OA2MSK_POSE	10U 
#define	I2C_ADDR2_OA2MSK_MSK	BITS(I2C_ADDR2_OA2MSK_POSS,I2C_ADDR2_OA2MSK_POSE)

#define	I2C_ADDR2_OA2_POSS	1U 
#define	I2C_ADDR2_OA2_POSE	7U 
#define	I2C_ADDR2_OA2_MSK	BITS(I2C_ADDR2_OA2_POSS,I2C_ADDR2_OA2_POSE)

/****************** Bit definition for I2C_TIMINGR register ************************/

#define	I2C_TIMINGR_PRESC_POSS	28U 
#define	I2C_TIMINGR_PRESC_POSE	31U 
#define	I2C_TIMINGR_PRESC_MSK	BITS(I2C_TIMINGR_PRESC_POSS,I2C_TIMINGR_PRESC_POSE)

#define	I2C_TIMINGR_SCLDEL_POSS	20U 
#define	I2C_TIMINGR_SCLDEL_POSE	23U 
#define	I2C_TIMINGR_SCLDEL_MSK	BITS(I2C_TIMINGR_SCLDEL_POSS,I2C_TIMINGR_SCLDEL_POSE)

#define	I2C_TIMINGR_SDADEL_POSS	16U 
#define	I2C_TIMINGR_SDADEL_POSE	19U 
#define	I2C_TIMINGR_SDADEL_MSK	BITS(I2C_TIMINGR_SDADEL_POSS,I2C_TIMINGR_SDADEL_POSE)

#define	I2C_TIMINGR_SCLH_POSS	8U 
#define	I2C_TIMINGR_SCLH_POSE	15U 
#define	I2C_TIMINGR_SCLH_MSK	BITS(I2C_TIMINGR_SCLH_POSS,I2C_TIMINGR_SCLH_POSE)

#define	I2C_TIMINGR_SCLL_POSS	0U 
#define	I2C_TIMINGR_SCLL_POSE	7U 
#define	I2C_TIMINGR_SCLL_MSK	BITS(I2C_TIMINGR_SCLL_POSS,I2C_TIMINGR_SCLL_POSE)

/****************** Bit definition for I2C_TIMEOUTR register ************************/

#define	I2C_TIMEOUTR_TEXTEN_POS	31U 
#define	I2C_TIMEOUTR_TEXTEN_MSK	BIT(I2C_TIMEOUTR_TEXTEN_POS)

#define	I2C_TIMEOUTR_TIMEOUTB_POSS	16U 
#define	I2C_TIMEOUTR_TIMEOUTB_POSE	27U 
#define	I2C_TIMEOUTR_TIMEOUTB_MSK	BITS(I2C_TIMEOUTR_TIMEOUTB_POSS,I2C_TIMEOUTR_TIMEOUTB_POSE)

#define	I2C_TIMEOUTR_TIMEOUTEN_POS	15U 
#define	I2C_TIMEOUTR_TIMEOUTEN_MSK	BIT(I2C_TIMEOUTR_TIMEOUTEN_POS)

#define	I2C_TIMEOUTR_TIDLE_POS	12U 
#define	I2C_TIMEOUTR_TIDLE_MSK	BIT(I2C_TIMEOUTR_TIDLE_POS)

#define	I2C_TIMEOUTR_TIMEOUTA_POSS	0U 
#define	I2C_TIMEOUTR_TIMEOUTA_POSE	11U 
#define	I2C_TIMEOUTR_TIMEOUTA_MSK	BITS(I2C_TIMEOUTR_TIMEOUTA_POSS,I2C_TIMEOUTR_TIMEOUTA_POSE)

/****************** Bit definition for I2C_STAT register ************************/

#define	I2C_STAT_ADDCODE_POSS	17U 
#define	I2C_STAT_ADDCODE_POSE	23U 
#define	I2C_STAT_ADDCODE_MSK	BITS(I2C_STAT_ADDCODE_POSS,I2C_STAT_ADDCODE_POSE)

#define	I2C_STAT_DIR_POS	16U 
#define	I2C_STAT_DIR_MSK	BIT(I2C_STAT_DIR_POS)

#define	I2C_STAT_BUSY_POS	15U 
#define	I2C_STAT_BUSY_MSK	BIT(I2C_STAT_BUSY_POS)

#define	I2C_STAT_TCR_POS	11U 
#define	I2C_STAT_TCR_MSK	BIT(I2C_STAT_TCR_POS)

#define	I2C_STAT_TC_POS	10U 
#define	I2C_STAT_TC_MSK	BIT(I2C_STAT_TC_POS)

#define	I2C_STAT_RXTH_POS	9U 
#define	I2C_STAT_RXTH_MSK	BIT(I2C_STAT_RXTH_POS)

#define	I2C_STAT_RXUD_POS	8U 
#define	I2C_STAT_RXUD_MSK	BIT(I2C_STAT_RXUD_POS)

#define	I2C_STAT_RXOV_POS	7U 
#define	I2C_STAT_RXOV_MSK	BIT(I2C_STAT_RXOV_POS)

#define	I2C_STAT_RXF_POS	6U 
#define	I2C_STAT_RXF_MSK	BIT(I2C_STAT_RXF_POS)

#define	I2C_STAT_RXE_POS	5U 
#define	I2C_STAT_RXE_MSK	BIT(I2C_STAT_RXE_POS)

#define	I2C_STAT_TXTH_POS	4U 
#define	I2C_STAT_TXTH_MSK	BIT(I2C_STAT_TXTH_POS)

#define	I2C_STAT_TXUD_POS	3U 
#define	I2C_STAT_TXUD_MSK	BIT(I2C_STAT_TXUD_POS)

#define	I2C_STAT_TXOV_POS	2U 
#define	I2C_STAT_TXOV_MSK	BIT(I2C_STAT_TXOV_POS)

#define	I2C_STAT_TXF_POS	1U 
#define	I2C_STAT_TXF_MSK	BIT(I2C_STAT_TXF_POS)

#define	I2C_STAT_TXE_POS	0U 
#define	I2C_STAT_TXE_MSK	BIT(I2C_STAT_TXE_POS)

/****************** Bit definition for I2C_FCON register ************************/

#define	I2C_FCON_RXFTH_POSS	14U 
#define	I2C_FCON_RXFTH_POSE	15U 
#define	I2C_FCON_RXFTH_MSK	BITS(I2C_FCON_RXFTH_POSS,I2C_FCON_RXFTH_POSE)

#define	I2C_FCON_RXFRST_POS	13U 
#define	I2C_FCON_RXFRST_MSK	BIT(I2C_FCON_RXFRST_POS)

#define	I2C_FCON_RXFLV_POSS	8U 
#define	I2C_FCON_RXFLV_POSE	12U 
#define	I2C_FCON_RXFLV_MSK	BITS(I2C_FCON_RXFLV_POSS,I2C_FCON_RXFLV_POSE)

#define	I2C_FCON_TXFTH_POSS	6U 
#define	I2C_FCON_TXFTH_POSE	7U 
#define	I2C_FCON_TXFTH_MSK	BITS(I2C_FCON_TXFTH_POSS,I2C_FCON_TXFTH_POSE)

#define	I2C_FCON_TXFRST_POS	5U 
#define	I2C_FCON_TXFRST_MSK	BIT(I2C_FCON_TXFRST_POS)

#define	I2C_FCON_TXFLV_POSS	0U 
#define	I2C_FCON_TXFLV_POSE	4U 
#define	I2C_FCON_TXFLV_MSK	BITS(I2C_FCON_TXFLV_POSS,I2C_FCON_TXFLV_POSE)

/****************** Bit definition for I2C_PECR register ************************/

#define	I2C_PECR_PEC_POSS	0U 
#define	I2C_PECR_PEC_POSE	7U 
#define	I2C_PECR_PEC_MSK	BITS(I2C_PECR_PEC_POSS,I2C_PECR_PEC_POSE)

/****************** Bit definition for I2C_RXDATA register ************************/

#define	I2C_RXDATA_RXDATA_POSS	0U 
#define	I2C_RXDATA_RXDATA_POSE	7U 
#define	I2C_RXDATA_RXDATA_MSK	BITS(I2C_RXDATA_RXDATA_POSS,I2C_RXDATA_RXDATA_POSE)

/****************** Bit definition for I2C_TXDATA register ************************/

#define	I2C_TXDATA_TXDATA_POSS	0U 
#define	I2C_TXDATA_TXDATA_POSE	7U 
#define	I2C_TXDATA_TXDATA_MSK	BITS(I2C_TXDATA_TXDATA_POSS,I2C_TXDATA_TXDATA_POSE)

/****************** Bit definition for I2C_IER register ************************/

#define	I2C_IER_ALERTIE_POS	20U 
#define	I2C_IER_ALERTIE_MSK	BIT(I2C_IER_ALERTIE_POS)

#define	I2C_IER_TOUTIE_POS	19U 
#define	I2C_IER_TOUTIE_MSK	BIT(I2C_IER_TOUTIE_POS)

#define	I2C_IER_PECEIE_POS	18U 
#define	I2C_IER_PECEIE_MSK	BIT(I2C_IER_PECEIE_POS)

#define	I2C_IER_ARLOIE_POS	17U 
#define	I2C_IER_ARLOIE_MSK	BIT(I2C_IER_ARLOIE_POS)

#define	I2C_IER_BERRIE_POS	16U 
#define	I2C_IER_BERRIE_MSK	BIT(I2C_IER_BERRIE_POS)

#define	I2C_IER_STOPIE_POS	14U 
#define	I2C_IER_STOPIE_MSK	BIT(I2C_IER_STOPIE_POS)

#define	I2C_IER_NACKIE_POS	13U 
#define	I2C_IER_NACKIE_MSK	BIT(I2C_IER_NACKIE_POS)

#define	I2C_IER_ADDRIE_POS	12U 
#define	I2C_IER_ADDRIE_MSK	BIT(I2C_IER_ADDRIE_POS)

#define	I2C_IER_TCRIE_POS	11U 
#define	I2C_IER_TCRIE_MSK	BIT(I2C_IER_TCRIE_POS)

#define	I2C_IER_TCIE_POS	10U 
#define	I2C_IER_TCIE_MSK	BIT(I2C_IER_TCIE_POS)

#define	I2C_IER_RXTHIE_POS	9U 
#define	I2C_IER_RXTHIE_MSK	BIT(I2C_IER_RXTHIE_POS)

#define	I2C_IER_RXUDIE_POS	8U 
#define	I2C_IER_RXUDIE_MSK	BIT(I2C_IER_RXUDIE_POS)

#define	I2C_IER_RXOVIE_POS	7U 
#define	I2C_IER_RXOVIE_MSK	BIT(I2C_IER_RXOVIE_POS)

#define	I2C_IER_RXFIE_POS	6U 
#define	I2C_IER_RXFIE_MSK	BIT(I2C_IER_RXFIE_POS)

#define	I2C_IER_TXTHIE_POS	4U 
#define	I2C_IER_TXTHIE_MSK	BIT(I2C_IER_TXTHIE_POS)

#define	I2C_IER_TXUDIE_POS	3U 
#define	I2C_IER_TXUDIE_MSK	BIT(I2C_IER_TXUDIE_POS)

#define	I2C_IER_TXOVIE_POS	2U 
#define	I2C_IER_TXOVIE_MSK	BIT(I2C_IER_TXOVIE_POS)

#define	I2C_IER_TXEIE_POS	0U 
#define	I2C_IER_TXEIE_MSK	BIT(I2C_IER_TXEIE_POS)

/****************** Bit definition for I2C_IDR register ************************/

#define	I2C_IDR_ALERTID_POS	20U 
#define	I2C_IDR_ALERTID_MSK	BIT(I2C_IDR_ALERTID_POS)

#define	I2C_IDR_TOUTID_POS	19U 
#define	I2C_IDR_TOUTID_MSK	BIT(I2C_IDR_TOUTID_POS)

#define	I2C_IDR_PECEID_POS	18U 
#define	I2C_IDR_PECEID_MSK	BIT(I2C_IDR_PECEID_POS)

#define	I2C_IDR_ARLOID_POS	17U 
#define	I2C_IDR_ARLOID_MSK	BIT(I2C_IDR_ARLOID_POS)

#define	I2C_IDR_BERRID_POS	16U 
#define	I2C_IDR_BERRID_MSK	BIT(I2C_IDR_BERRID_POS)

#define	I2C_IDR_STOPID_POS	14U 
#define	I2C_IDR_STOPID_MSK	BIT(I2C_IDR_STOPID_POS)

#define	I2C_IDR_NACKID_POS	13U 
#define	I2C_IDR_NACKID_MSK	BIT(I2C_IDR_NACKID_POS)

#define	I2C_IDR_ADDRID_POS	12U 
#define	I2C_IDR_ADDRID_MSK	BIT(I2C_IDR_ADDRID_POS)

#define	I2C_IDR_TCRID_POS	11U 
#define	I2C_IDR_TCRID_MSK	BIT(I2C_IDR_TCRID_POS)

#define	I2C_IDR_TCID_POS	10U 
#define	I2C_IDR_TCID_MSK	BIT(I2C_IDR_TCID_POS)

#define	I2C_IDR_RXTHID_POS	9U 
#define	I2C_IDR_RXTHID_MSK	BIT(I2C_IDR_RXTHID_POS)

#define	I2C_IDR_RXUDID_POS	8U 
#define	I2C_IDR_RXUDID_MSK	BIT(I2C_IDR_RXUDID_POS)

#define	I2C_IDR_RXOVID_POS	7U 
#define	I2C_IDR_RXOVID_MSK	BIT(I2C_IDR_RXOVID_POS)

#define	I2C_IDR_RXFID_POS	6U 
#define	I2C_IDR_RXFID_MSK	BIT(I2C_IDR_RXFID_POS)

#define	I2C_IDR_TXTHID_POS	4U 
#define	I2C_IDR_TXTHID_MSK	BIT(I2C_IDR_TXTHID_POS)

#define	I2C_IDR_TXUDID_POS	3U 
#define	I2C_IDR_TXUDID_MSK	BIT(I2C_IDR_TXUDID_POS)

#define	I2C_IDR_TXOVID_POS	2U 
#define	I2C_IDR_TXOVID_MSK	BIT(I2C_IDR_TXOVID_POS)

#define	I2C_IDR_TXEID_POS	0U 
#define	I2C_IDR_TXEID_MSK	BIT(I2C_IDR_TXEID_POS)

/****************** Bit definition for I2C_IVS register ************************/

#define	I2C_IVS_ALERTIV_POS	20U 
#define	I2C_IVS_ALERTIV_MSK	BIT(I2C_IVS_ALERTIV_POS)

#define	I2C_IVS_TOUTIV_POS	19U 
#define	I2C_IVS_TOUTIV_MSK	BIT(I2C_IVS_TOUTIV_POS)

#define	I2C_IVS_PECEIV_POS	18U 
#define	I2C_IVS_PECEIV_MSK	BIT(I2C_IVS_PECEIV_POS)

#define	I2C_IVS_ARLOIV_POS	17U 
#define	I2C_IVS_ARLOIV_MSK	BIT(I2C_IVS_ARLOIV_POS)

#define	I2C_IVS_BERRIV_POS	16U 
#define	I2C_IVS_BERRIV_MSK	BIT(I2C_IVS_BERRIV_POS)

#define	I2C_IVS_STOPIV_POS	14U 
#define	I2C_IVS_STOPIV_MSK	BIT(I2C_IVS_STOPIV_POS)

#define	I2C_IVS_NACKIV_POS	13U 
#define	I2C_IVS_NACKIV_MSK	BIT(I2C_IVS_NACKIV_POS)

#define	I2C_IVS_ADDRIV_POS	12U 
#define	I2C_IVS_ADDRIV_MSK	BIT(I2C_IVS_ADDRIV_POS)

#define	I2C_IVS_TCRIV_POS	11U 
#define	I2C_IVS_TCRIV_MSK	BIT(I2C_IVS_TCRIV_POS)

#define	I2C_IVS_TCIV_POS	10U 
#define	I2C_IVS_TCIV_MSK	BIT(I2C_IVS_TCIV_POS)

#define	I2C_IVS_RXTHIV_POS	9U 
#define	I2C_IVS_RXTHIV_MSK	BIT(I2C_IVS_RXTHIV_POS)

#define	I2C_IVS_RXUDIV_POS	8U 
#define	I2C_IVS_RXUDIV_MSK	BIT(I2C_IVS_RXUDIV_POS)

#define	I2C_IVS_RXOVIV_POS	7U 
#define	I2C_IVS_RXOVIV_MSK	BIT(I2C_IVS_RXOVIV_POS)

#define	I2C_IVS_RXFIV_POS	6U 
#define	I2C_IVS_RXFIV_MSK	BIT(I2C_IVS_RXFIV_POS)

#define	I2C_IVS_TXTHIV_POS	4U 
#define	I2C_IVS_TXTHIV_MSK	BIT(I2C_IVS_TXTHIV_POS)

#define	I2C_IVS_TXUDIV_POS	3U 
#define	I2C_IVS_TXUDIV_MSK	BIT(I2C_IVS_TXUDIV_POS)

#define	I2C_IVS_TXOVIV_POS	2U 
#define	I2C_IVS_TXOVIV_MSK	BIT(I2C_IVS_TXOVIV_POS)

#define	I2C_IVS_TXEIV_POS	0U 
#define	I2C_IVS_TXEIV_MSK	BIT(I2C_IVS_TXEIV_POS)

/****************** Bit definition for I2C_RIF register ************************/

#define	I2C_RIF_ALERTRI_POS	20U 
#define	I2C_RIF_ALERTRI_MSK	BIT(I2C_RIF_ALERTRI_POS)

#define	I2C_RIF_TOUTRI_POS	19U 
#define	I2C_RIF_TOUTRI_MSK	BIT(I2C_RIF_TOUTRI_POS)

#define	I2C_RIF_PECERI_POS	18U 
#define	I2C_RIF_PECERI_MSK	BIT(I2C_RIF_PECERI_POS)

#define	I2C_RIF_ARLORI_POS	17U 
#define	I2C_RIF_ARLORI_MSK	BIT(I2C_RIF_ARLORI_POS)

#define	I2C_RIF_BERRRI_POS	16U 
#define	I2C_RIF_BERRRI_MSK	BIT(I2C_RIF_BERRRI_POS)

#define	I2C_RIF_STOPRI_POS	14U 
#define	I2C_RIF_STOPRI_MSK	BIT(I2C_RIF_STOPRI_POS)

#define	I2C_RIF_NACKRI_POS	13U 
#define	I2C_RIF_NACKRI_MSK	BIT(I2C_RIF_NACKRI_POS)

#define	I2C_RIF_ADDRRI_POS	12U 
#define	I2C_RIF_ADDRRI_MSK	BIT(I2C_RIF_ADDRRI_POS)

#define	I2C_RIF_TCRRI_POS	11U 
#define	I2C_RIF_TCRRI_MSK	BIT(I2C_RIF_TCRRI_POS)

#define	I2C_RIF_TCRI_POS	10U 
#define	I2C_RIF_TCRI_MSK	BIT(I2C_RIF_TCRI_POS)

#define	I2C_RIF_RXTHRI_POS	9U 
#define	I2C_RIF_RXTHRI_MSK	BIT(I2C_RIF_RXTHRI_POS)

#define	I2C_RIF_RXUDRI_POS	8U 
#define	I2C_RIF_RXUDRI_MSK	BIT(I2C_RIF_RXUDRI_POS)

#define	I2C_RIF_RXOVRI_POS	7U 
#define	I2C_RIF_RXOVRI_MSK	BIT(I2C_RIF_RXOVRI_POS)

#define	I2C_RIF_RXFRI_POS	6U 
#define	I2C_RIF_RXFRI_MSK	BIT(I2C_RIF_RXFRI_POS)

#define	I2C_RIF_TXTHRI_POS	4U 
#define	I2C_RIF_TXTHRI_MSK	BIT(I2C_RIF_TXTHRI_POS)

#define	I2C_RIF_TXUDRI_POS	3U 
#define	I2C_RIF_TXUDRI_MSK	BIT(I2C_RIF_TXUDRI_POS)

#define	I2C_RIF_TXOVRI_POS	2U 
#define	I2C_RIF_TXOVRI_MSK	BIT(I2C_RIF_TXOVRI_POS)

#define	I2C_RIF_TXERI_POS	0U 
#define	I2C_RIF_TXERI_MSK	BIT(I2C_RIF_TXERI_POS)

/****************** Bit definition for I2C_IFM register ************************/

#define	I2C_IFM_ALERTFM_POS	20U 
#define	I2C_IFM_ALERTFM_MSK	BIT(I2C_IFM_ALERTFM_POS)

#define	I2C_IFM_TOUTFM_POS	19U 
#define	I2C_IFM_TOUTFM_MSK	BIT(I2C_IFM_TOUTFM_POS)

#define	I2C_IFM_PECEFM_POS	18U 
#define	I2C_IFM_PECEFM_MSK	BIT(I2C_IFM_PECEFM_POS)

#define	I2C_IFM_ARLOFM_POS	17U 
#define	I2C_IFM_ARLOFM_MSK	BIT(I2C_IFM_ARLOFM_POS)

#define	I2C_IFM_BERRFM_POS	16U 
#define	I2C_IFM_BERRFM_MSK	BIT(I2C_IFM_BERRFM_POS)

#define	I2C_IFM_STOPFM_POS	14U 
#define	I2C_IFM_STOPFM_MSK	BIT(I2C_IFM_STOPFM_POS)

#define	I2C_IFM_NACKFM_POS	13U 
#define	I2C_IFM_NACKFM_MSK	BIT(I2C_IFM_NACKFM_POS)

#define	I2C_IFM_ADDRFM_POS	12U 
#define	I2C_IFM_ADDRFM_MSK	BIT(I2C_IFM_ADDRFM_POS)

#define	I2C_IFM_TCRFM_POS	11U 
#define	I2C_IFM_TCRFM_MSK	BIT(I2C_IFM_TCRFM_POS)

#define	I2C_IFM_TCFM_POS	10U 
#define	I2C_IFM_TCFM_MSK	BIT(I2C_IFM_TCFM_POS)

#define	I2C_IFM_RXTHFM_POS	9U 
#define	I2C_IFM_RXTHFM_MSK	BIT(I2C_IFM_RXTHFM_POS)

#define	I2C_IFM_RXUDFM_POS	8U 
#define	I2C_IFM_RXUDFM_MSK	BIT(I2C_IFM_RXUDFM_POS)

#define	I2C_IFM_RXOVFM_POS	7U 
#define	I2C_IFM_RXOVFM_MSK	BIT(I2C_IFM_RXOVFM_POS)

#define	I2C_IFM_RXFFM_POS	6U 
#define	I2C_IFM_RXFFM_MSK	BIT(I2C_IFM_RXFFM_POS)

#define	I2C_IFM_TXTHFM_POS	4U 
#define	I2C_IFM_TXTHFM_MSK	BIT(I2C_IFM_TXTHFM_POS)

#define	I2C_IFM_TXUDFM_POS	3U 
#define	I2C_IFM_TXUDFM_MSK	BIT(I2C_IFM_TXUDFM_POS)

#define	I2C_IFM_TXOVFM_POS	2U 
#define	I2C_IFM_TXOVFM_MSK	BIT(I2C_IFM_TXOVFM_POS)

#define	I2C_IFM_TXEFM_POS	0U 
#define	I2C_IFM_TXEFM_MSK	BIT(I2C_IFM_TXEFM_POS)

/****************** Bit definition for I2C_ICR register ************************/

#define	I2C_ICR_ALERTIC_POS	20U 
#define	I2C_ICR_ALERTIC_MSK	BIT(I2C_ICR_ALERTIC_POS)

#define	I2C_ICR_TOUTIC_POS	19U 
#define	I2C_ICR_TOUTIC_MSK	BIT(I2C_ICR_TOUTIC_POS)

#define	I2C_ICR_PECEIC_POS	18U 
#define	I2C_ICR_PECEIC_MSK	BIT(I2C_ICR_PECEIC_POS)

#define	I2C_ICR_ARLOIC_POS	17U 
#define	I2C_ICR_ARLOIC_MSK	BIT(I2C_ICR_ARLOIC_POS)

#define	I2C_ICR_BERRIC_POS	16U 
#define	I2C_ICR_BERRIC_MSK	BIT(I2C_ICR_BERRIC_POS)

#define	I2C_ICR_STOPIC_POS	14U 
#define	I2C_ICR_STOPIC_MSK	BIT(I2C_ICR_STOPIC_POS)

#define	I2C_ICR_NACKIC_POS	13U 
#define	I2C_ICR_NACKIC_MSK	BIT(I2C_ICR_NACKIC_POS)

#define	I2C_ICR_ADDRIC_POS	12U 
#define	I2C_ICR_ADDRIC_MSK	BIT(I2C_ICR_ADDRIC_POS)

#define	I2C_ICR_TCRIC_POS	11U 
#define	I2C_ICR_TCRIC_MSK	BIT(I2C_ICR_TCRIC_POS)

#define	I2C_ICR_TCIC_POS	10U 
#define	I2C_ICR_TCIC_MSK	BIT(I2C_ICR_TCIC_POS)

#define	I2C_ICR_RXTHIC_POS	9U 
#define	I2C_ICR_RXTHIC_MSK	BIT(I2C_ICR_RXTHIC_POS)

#define	I2C_ICR_RXUDIC_POS	8U 
#define	I2C_ICR_RXUDIC_MSK	BIT(I2C_ICR_RXUDIC_POS)

#define	I2C_ICR_RXOVIC_POS	7U 
#define	I2C_ICR_RXOVIC_MSK	BIT(I2C_ICR_RXOVIC_POS)

#define	I2C_ICR_RXFIC_POS	6U 
#define	I2C_ICR_RXFIC_MSK	BIT(I2C_ICR_RXFIC_POS)

#define	I2C_ICR_TXTHIC_POS	4U 
#define	I2C_ICR_TXTHIC_MSK	BIT(I2C_ICR_TXTHIC_POS)

#define	I2C_ICR_TXUDIC_POS	3U 
#define	I2C_ICR_TXUDIC_MSK	BIT(I2C_ICR_TXUDIC_POS)

#define	I2C_ICR_TXOVIC_POS	2U 
#define	I2C_ICR_TXOVIC_MSK	BIT(I2C_ICR_TXOVIC_POS)

#define	I2C_ICR_TXEIC_POS	0U 
#define	I2C_ICR_TXEIC_MSK	BIT(I2C_ICR_TXEIC_POS)

typedef struct
{
	__IO uint32_t CON1;
	__IO uint32_t CON2;
	__IO uint32_t ADDR1;
	__IO uint32_t ADDR2;
	__IO uint32_t TIMINGR;
	__IO uint32_t TIMEOUTR;
	__I uint32_t STAT;
	__IO uint32_t FCON;
	__I uint32_t PECR;
	__I uint32_t RXDATA;
	__O uint32_t TXDATA;
	__O uint32_t IER;
	__O uint32_t IDR;
	__I uint32_t IVS;
	__I uint32_t RIF;
	__I uint32_t IFM;
	__O uint32_t ICR;
} I2C_TypeDef;





#endif
