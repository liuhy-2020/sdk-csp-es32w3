/**
  **************************************************************************************
  * @file    REG_RTC.h
  * @brief   RTC Head File
  *
  * @version V0.01
  * @data    8/24/2020
  * @author  Eastsoft MCU Software Team
  * @note
  *
  * Copyright (C) 2018 Shanghai Eastsoft Microelectronics Co., Ltd. ALL rights reserved.
  *
  **************************************************************************************
  */

#ifndef __REG_RTC_H__
#define __REG_RTC_H__


/******************************************************************************/
/*                              设备特殊寄存器结构定义                        */
/******************************************************************************/

/*   允许匿名结构和匿名联合    */
 

/****************** Bit definition for RTC_WPR register ************************/

#define	RTC_WPR_WP_POS	0U 
#define	RTC_WPR_WP_MSK	BIT(RTC_WPR_WP_POS)

/****************** Bit definition for RTC_CON register ************************/

#define	RTC_CON_SSEC_POS	25U 
#define	RTC_CON_SSEC_MSK	BIT(RTC_CON_SSEC_POS)

#define	RTC_CON_BUSY_POS	24U 
#define	RTC_CON_BUSY_MSK	BIT(RTC_CON_BUSY_POS)

#define	RTC_CON_POL_POS	22U 
#define	RTC_CON_POL_MSK	BIT(RTC_CON_POL_POS)

#define	RTC_CON_EOS_POSS	20U 
#define	RTC_CON_EOS_POSE	21U 
#define	RTC_CON_EOS_MSK	BITS(RTC_CON_EOS_POSS,RTC_CON_EOS_POSE)

#define	RTC_CON_CKOS_POSS	17U 
#define	RTC_CON_CKOS_POSE	19U 
#define	RTC_CON_CKOS_MSK	BITS(RTC_CON_CKOS_POSS,RTC_CON_CKOS_POSE)

#define	RTC_CON_CKOE_POS	16U 
#define	RTC_CON_CKOE_MSK	BIT(RTC_CON_CKOE_POS)

#define	RTC_CON_WUCKS_POSS	13U 
#define	RTC_CON_WUCKS_POSE	15U 
#define	RTC_CON_WUCKS_MSK	BITS(RTC_CON_WUCKS_POSS,RTC_CON_WUCKS_POSE)

#define	RTC_CON_WUTE_POS	12U 
#define	RTC_CON_WUTE_MSK	BIT(RTC_CON_WUTE_POS)

#define	RTC_CON_DSTS_POS	10U 
#define	RTC_CON_DSTS_MSK	BIT(RTC_CON_DSTS_POS)

#define	RTC_CON_SUB1H_POS	9U 
#define	RTC_CON_SUB1H_MSK	BIT(RTC_CON_SUB1H_POS)

#define	RTC_CON_ADD1H_POS	8U 
#define	RTC_CON_ADD1H_MSK	BIT(RTC_CON_ADD1H_POS)

#define	RTC_CON_TSPIN_POS	7U 
#define	RTC_CON_TSPIN_MSK	BIT(RTC_CON_TSPIN_POS)

#define	RTC_CON_TSSEL_POS	6U 
#define	RTC_CON_TSSEL_MSK	BIT(RTC_CON_TSSEL_POS)

#define	RTC_CON_TSEN_POS	5U 
#define	RTC_CON_TSEN_MSK	BIT(RTC_CON_TSEN_POS)

#define	RTC_CON_SHDBP_POS	4U 
#define	RTC_CON_SHDBP_MSK	BIT(RTC_CON_SHDBP_POS)

#define	RTC_CON_HFM_POS	3U 
#define	RTC_CON_HFM_MSK	BIT(RTC_CON_HFM_POS)

#define	RTC_CON_ALMBEN_POS	2U 
#define	RTC_CON_ALMBEN_MSK	BIT(RTC_CON_ALMBEN_POS)

#define	RTC_CON_ALMAEN_POS	1U 
#define	RTC_CON_ALMAEN_MSK	BIT(RTC_CON_ALMAEN_POS)

#define	RTC_CON_GO_POS	0U 
#define	RTC_CON_GO_MSK	BIT(RTC_CON_GO_POS)

/****************** Bit definition for RTC_PSR register ************************/

#define	RTC_PSR_APRS_POSS	16U 
#define	RTC_PSR_APRS_POSE	22U 
#define	RTC_PSR_APRS_MSK	BITS(RTC_PSR_APRS_POSS,RTC_PSR_APRS_POSE)

#define	RTC_PSR_SPRS_POSS	0U 
#define	RTC_PSR_SPRS_POSE	14U 
#define	RTC_PSR_SPRS_MSK	BITS(RTC_PSR_SPRS_POSS,RTC_PSR_SPRS_POSE)

/****************** Bit definition for RTC_TAMPCON register ************************/

#define	RTC_TAMPCON_TAMPFLT_POSS	20U 
#define	RTC_TAMPCON_TAMPFLT_POSE	21U 
#define	RTC_TAMPCON_TAMPFLT_MSK	BITS(RTC_TAMPCON_TAMPFLT_POSS,RTC_TAMPCON_TAMPFLT_POSE)

#define	RTC_TAMPCON_TAMPCKS_POSS	17U 
#define	RTC_TAMPCON_TAMPCKS_POSE	19U 
#define	RTC_TAMPCON_TAMPCKS_MSK	BITS(RTC_TAMPCON_TAMPCKS_POSS,RTC_TAMPCON_TAMPCKS_POSE)

#define	RTC_TAMPCON_TAMPTS_POS	16U 
#define	RTC_TAMPCON_TAMPTS_MSK	BIT(RTC_TAMPCON_TAMPTS_POS)

#define	RTC_TAMPCON_TAMP2LV_POS	9U 
#define	RTC_TAMPCON_TAMP2LV_MSK	BIT(RTC_TAMPCON_TAMP2LV_POS)

#define	RTC_TAMPCON_TAMP2EN_POS	8U 
#define	RTC_TAMPCON_TAMP2EN_MSK	BIT(RTC_TAMPCON_TAMP2EN_POS)

#define	RTC_TAMPCON_TAMP1LV_POS	1U 
#define	RTC_TAMPCON_TAMP1LV_MSK	BIT(RTC_TAMPCON_TAMP1LV_POS)

#define	RTC_TAMPCON_TAMP1EN_POS	0U 
#define	RTC_TAMPCON_TAMP1EN_MSK	BIT(RTC_TAMPCON_TAMP1EN_POS)

/****************** Bit definition for RTC_TIME register ************************/

#define	RTC_TIME_PM_POS	22U 
#define	RTC_TIME_PM_MSK	BIT(RTC_TIME_PM_POS)

#define	RTC_TIME_HRT_POSS	20U 
#define	RTC_TIME_HRT_POSE	21U 
#define	RTC_TIME_HRT_MSK	BITS(RTC_TIME_HRT_POSS,RTC_TIME_HRT_POSE)

#define	RTC_TIME_HRU_POSS	16U 
#define	RTC_TIME_HRU_POSE	19U 
#define	RTC_TIME_HRU_MSK	BITS(RTC_TIME_HRU_POSS,RTC_TIME_HRU_POSE)

#define	RTC_TIME_MINT_POSS	12U 
#define	RTC_TIME_MINT_POSE	14U 
#define	RTC_TIME_MINT_MSK	BITS(RTC_TIME_MINT_POSS,RTC_TIME_MINT_POSE)

#define	RTC_TIME_MINU_POSS	8U 
#define	RTC_TIME_MINU_POSE	11U 
#define	RTC_TIME_MINU_MSK	BITS(RTC_TIME_MINU_POSS,RTC_TIME_MINU_POSE)

#define	RTC_TIME_SECT_POSS	4U 
#define	RTC_TIME_SECT_POSE	6U 
#define	RTC_TIME_SECT_MSK	BITS(RTC_TIME_SECT_POSS,RTC_TIME_SECT_POSE)

#define	RTC_TIME_SECU_POSS	0U 
#define	RTC_TIME_SECU_POSE	3U 
#define	RTC_TIME_SECU_MSK	BITS(RTC_TIME_SECU_POSS,RTC_TIME_SECU_POSE)

/****************** Bit definition for RTC_DATE register ************************/

#define	RTC_DATE_WD_POSS	24U 
#define	RTC_DATE_WD_POSE	26U 
#define	RTC_DATE_WD_MSK	BITS(RTC_DATE_WD_POSS,RTC_DATE_WD_POSE)

#define	RTC_DATE_YRT_POSS	20U 
#define	RTC_DATE_YRT_POSE	23U 
#define	RTC_DATE_YRT_MSK	BITS(RTC_DATE_YRT_POSS,RTC_DATE_YRT_POSE)

#define	RTC_DATE_YRU_POSS	16U 
#define	RTC_DATE_YRU_POSE	19U 
#define	RTC_DATE_YRU_MSK	BITS(RTC_DATE_YRU_POSS,RTC_DATE_YRU_POSE)

#define	RTC_DATE_MONT_POS	12U 
#define	RTC_DATE_MONT_MSK	BIT(RTC_DATE_MONT_POS)

#define	RTC_DATE_MONU_POSS	8U 
#define	RTC_DATE_MONU_POSE	11U 
#define	RTC_DATE_MONU_MSK	BITS(RTC_DATE_MONU_POSS,RTC_DATE_MONU_POSE)

#define	RTC_DATE_DAYT_POSS	4U 
#define	RTC_DATE_DAYT_POSE	5U 
#define	RTC_DATE_DAYT_MSK	BITS(RTC_DATE_DAYT_POSS,RTC_DATE_DAYT_POSE)

#define	RTC_DATE_DAYU_POSS	0U 
#define	RTC_DATE_DAYU_POSE	3U 
#define	RTC_DATE_DAYU_MSK	BITS(RTC_DATE_DAYU_POSS,RTC_DATE_DAYU_POSE)

/****************** Bit definition for RTC_SSEC register ************************/

#define	RTC_SSEC_VAL_POSS	0U 
#define	RTC_SSEC_VAL_POSE	15U 
#define	RTC_SSEC_VAL_MSK	BITS(RTC_SSEC_VAL_POSS,RTC_SSEC_VAL_POSE)

/****************** Bit definition for RTC_WUMAT register ************************/

#define	RTC_WUMAT_VAL_POSS	0U 
#define	RTC_WUMAT_VAL_POSE	15U 
#define	RTC_WUMAT_VAL_MSK	BITS(RTC_WUMAT_VAL_POSS,RTC_WUMAT_VAL_POSE)

/****************** Bit definition for RTC_ALMA register ************************/

#define	RTC_ALMA_WDS_POS	31U 
#define	RTC_ALMA_WDS_MSK	BIT(RTC_ALMA_WDS_POS)

#define	RTC_ALMA_DAWD_POSS	24U 
#define	RTC_ALMA_DAWD_POSE	30U 
#define	RTC_ALMA_DAWD_MSK	BITS(RTC_ALMA_DAWD_POSS,RTC_ALMA_DAWD_POSE)

#define	RTC_ALMA_HRMSK_POS	23U 
#define	RTC_ALMA_HRMSK_MSK	BIT(RTC_ALMA_HRMSK_POS)

#define	RTC_ALMA_PM_POS	22U 
#define	RTC_ALMA_PM_MSK	BIT(RTC_ALMA_PM_POS)

#define	RTC_ALMA_HRT_POSS	20U 
#define	RTC_ALMA_HRT_POSE	21U 
#define	RTC_ALMA_HRT_MSK	BITS(RTC_ALMA_HRT_POSS,RTC_ALMA_HRT_POSE)

#define	RTC_ALMA_HRU_POSS	16U 
#define	RTC_ALMA_HRU_POSE	19U 
#define	RTC_ALMA_HRU_MSK	BITS(RTC_ALMA_HRU_POSS,RTC_ALMA_HRU_POSE)

#define	RTC_ALMA_MINMSK_POS	15U 
#define	RTC_ALMA_MINMSK_MSK	BIT(RTC_ALMA_MINMSK_POS)

#define	RTC_ALMA_MINT_POSS	12U 
#define	RTC_ALMA_MINT_POSE	14U 
#define	RTC_ALMA_MINT_MSK	BITS(RTC_ALMA_MINT_POSS,RTC_ALMA_MINT_POSE)

#define	RTC_ALMA_MINU_POSS	8U 
#define	RTC_ALMA_MINU_POSE	11U 
#define	RTC_ALMA_MINU_MSK	BITS(RTC_ALMA_MINU_POSS,RTC_ALMA_MINU_POSE)

#define	RTC_ALMA_SECMSK_POS	7U 
#define	RTC_ALMA_SECMSK_MSK	BIT(RTC_ALMA_SECMSK_POS)

#define	RTC_ALMA_SECT_POSS	4U 
#define	RTC_ALMA_SECT_POSE	6U 
#define	RTC_ALMA_SECT_MSK	BITS(RTC_ALMA_SECT_POSS,RTC_ALMA_SECT_POSE)

#define	RTC_ALMA_SECU_POSS	0U 
#define	RTC_ALMA_SECU_POSE	3U 
#define	RTC_ALMA_SECU_MSK	BITS(RTC_ALMA_SECU_POSS,RTC_ALMA_SECU_POSE)

/****************** Bit definition for RTC_ALMB register ************************/

#define	RTC_ALMB_WDS_POS	31U 
#define	RTC_ALMB_WDS_MSK	BIT(RTC_ALMB_WDS_POS)

#define	RTC_ALMB_DAWD_POSS	24U 
#define	RTC_ALMB_DAWD_POSE	30U 
#define	RTC_ALMB_DAWD_MSK	BITS(RTC_ALMB_DAWD_POSS,RTC_ALMB_DAWD_POSE)

#define	RTC_ALMB_HRMSK_POS	23U 
#define	RTC_ALMB_HRMSK_MSK	BIT(RTC_ALMB_HRMSK_POS)

#define	RTC_ALMB_PM_POS	22U 
#define	RTC_ALMB_PM_MSK	BIT(RTC_ALMB_PM_POS)

#define	RTC_ALMB_HRT_POSS	20U 
#define	RTC_ALMB_HRT_POSE	21U 
#define	RTC_ALMB_HRT_MSK	BITS(RTC_ALMB_HRT_POSS,RTC_ALMB_HRT_POSE)

#define	RTC_ALMB_HRU_POSS	16U 
#define	RTC_ALMB_HRU_POSE	19U 
#define	RTC_ALMB_HRU_MSK	BITS(RTC_ALMB_HRU_POSS,RTC_ALMB_HRU_POSE)

#define	RTC_ALMB_MINMSK_POS	15U 
#define	RTC_ALMB_MINMSK_MSK	BIT(RTC_ALMB_MINMSK_POS)

#define	RTC_ALMB_MINT_POSS	12U 
#define	RTC_ALMB_MINT_POSE	14U 
#define	RTC_ALMB_MINT_MSK	BITS(RTC_ALMB_MINT_POSS,RTC_ALMB_MINT_POSE)

#define	RTC_ALMB_MINU_POSS	8U 
#define	RTC_ALMB_MINU_POSE	11U 
#define	RTC_ALMB_MINU_MSK	BITS(RTC_ALMB_MINU_POSS,RTC_ALMB_MINU_POSE)

#define	RTC_ALMB_SECMSK_POS	7U 
#define	RTC_ALMB_SECMSK_MSK	BIT(RTC_ALMB_SECMSK_POS)

#define	RTC_ALMB_SECT_POSS	4U 
#define	RTC_ALMB_SECT_POSE	6U 
#define	RTC_ALMB_SECT_MSK	BITS(RTC_ALMB_SECT_POSS,RTC_ALMB_SECT_POSE)

#define	RTC_ALMB_SECU_POSS	0U 
#define	RTC_ALMB_SECU_POSE	3U 
#define	RTC_ALMB_SECU_MSK	BITS(RTC_ALMB_SECU_POSS,RTC_ALMB_SECU_POSE)

/****************** Bit definition for RTC_ALMASSEC register ************************/

#define	RTC_ALMASSEC_SSECM_POSS	24U 
#define	RTC_ALMASSEC_SSECM_POSE	27U 
#define	RTC_ALMASSEC_SSECM_MSK	BITS(RTC_ALMASSEC_SSECM_POSS,RTC_ALMASSEC_SSECM_POSE)

#define	RTC_ALMASSEC_SSEC_POSS	0U 
#define	RTC_ALMASSEC_SSEC_POSE	14U 
#define	RTC_ALMASSEC_SSEC_MSK	BITS(RTC_ALMASSEC_SSEC_POSS,RTC_ALMASSEC_SSEC_POSE)

/****************** Bit definition for RTC_ALMBSSEC register ************************/

#define	RTC_ALMBSSEC_SSECM_POSS	24U 
#define	RTC_ALMBSSEC_SSECM_POSE	27U 
#define	RTC_ALMBSSEC_SSECM_MSK	BITS(RTC_ALMBSSEC_SSECM_POSS,RTC_ALMBSSEC_SSECM_POSE)

#define	RTC_ALMBSSEC_SSEC_POSS	0U 
#define	RTC_ALMBSSEC_SSEC_POSE	14U 
#define	RTC_ALMBSSEC_SSEC_MSK	BITS(RTC_ALMBSSEC_SSEC_POSS,RTC_ALMBSSEC_SSEC_POSE)

/****************** Bit definition for RTC_TSTIME register ************************/

#define	RTC_TSTIME_PM_POS	22U 
#define	RTC_TSTIME_PM_MSK	BIT(RTC_TSTIME_PM_POS)

#define	RTC_TSTIME_HRT_POSS	20U 
#define	RTC_TSTIME_HRT_POSE	21U 
#define	RTC_TSTIME_HRT_MSK	BITS(RTC_TSTIME_HRT_POSS,RTC_TSTIME_HRT_POSE)

#define	RTC_TSTIME_HRU_POSS	16U 
#define	RTC_TSTIME_HRU_POSE	19U 
#define	RTC_TSTIME_HRU_MSK	BITS(RTC_TSTIME_HRU_POSS,RTC_TSTIME_HRU_POSE)

#define	RTC_TSTIME_MINT_POSS	12U 
#define	RTC_TSTIME_MINT_POSE	14U 
#define	RTC_TSTIME_MINT_MSK	BITS(RTC_TSTIME_MINT_POSS,RTC_TSTIME_MINT_POSE)

#define	RTC_TSTIME_MINU_POSS	8U 
#define	RTC_TSTIME_MINU_POSE	11U 
#define	RTC_TSTIME_MINU_MSK	BITS(RTC_TSTIME_MINU_POSS,RTC_TSTIME_MINU_POSE)

#define	RTC_TSTIME_SECT_POSS	4U 
#define	RTC_TSTIME_SECT_POSE	6U 
#define	RTC_TSTIME_SECT_MSK	BITS(RTC_TSTIME_SECT_POSS,RTC_TSTIME_SECT_POSE)

#define	RTC_TSTIME_SECU_POSS	0U 
#define	RTC_TSTIME_SECU_POSE	3U 
#define	RTC_TSTIME_SECU_MSK	BITS(RTC_TSTIME_SECU_POSS,RTC_TSTIME_SECU_POSE)

/****************** Bit definition for RTC_TSDATE register ************************/

#define	RTC_TSDATE_WD_POSS	24U 
#define	RTC_TSDATE_WD_POSE	26U 
#define	RTC_TSDATE_WD_MSK	BITS(RTC_TSDATE_WD_POSS,RTC_TSDATE_WD_POSE)

#define	RTC_TSDATE_YRT_POSS	20U 
#define	RTC_TSDATE_YRT_POSE	23U 
#define	RTC_TSDATE_YRT_MSK	BITS(RTC_TSDATE_YRT_POSS,RTC_TSDATE_YRT_POSE)

#define	RTC_TSDATE_YRU_POSS	16U 
#define	RTC_TSDATE_YRU_POSE	19U 
#define	RTC_TSDATE_YRU_MSK	BITS(RTC_TSDATE_YRU_POSS,RTC_TSDATE_YRU_POSE)

#define	RTC_TSDATE_MONT_POS	12U 
#define	RTC_TSDATE_MONT_MSK	BIT(RTC_TSDATE_MONT_POS)

#define	RTC_TSDATE_MONU_POSS	8U 
#define	RTC_TSDATE_MONU_POSE	11U 
#define	RTC_TSDATE_MONU_MSK	BITS(RTC_TSDATE_MONU_POSS,RTC_TSDATE_MONU_POSE)

#define	RTC_TSDATE_DAYT_POSS	4U 
#define	RTC_TSDATE_DAYT_POSE	5U 
#define	RTC_TSDATE_DAYT_MSK	BITS(RTC_TSDATE_DAYT_POSS,RTC_TSDATE_DAYT_POSE)

#define	RTC_TSDATE_DAYU_POSS	0U 
#define	RTC_TSDATE_DAYU_POSE	3U 
#define	RTC_TSDATE_DAYU_MSK	BITS(RTC_TSDATE_DAYU_POSS,RTC_TSDATE_DAYU_POSE)

/****************** Bit definition for RTC_TSSSEC register ************************/

#define	RTC_TSSSEC_SSEC_POSS	0U 
#define	RTC_TSSSEC_SSEC_POSE	15U 
#define	RTC_TSSSEC_SSEC_MSK	BITS(RTC_TSSSEC_SSEC_POSS,RTC_TSSSEC_SSEC_POSE)

/****************** Bit definition for RTC_SSECTR register ************************/

#define	RTC_SSECTR_INC_POS	31U 
#define	RTC_SSECTR_INC_MSK	BIT(RTC_SSECTR_INC_POS)

#define	RTC_SSECTR_TRIM_POSS	0U 
#define	RTC_SSECTR_TRIM_POSE	14U 
#define	RTC_SSECTR_TRIM_MSK	BITS(RTC_SSECTR_TRIM_POSS,RTC_SSECTR_TRIM_POSE)

/****************** Bit definition for RTC_IER register ************************/

#define	RTC_IER_TCE_POS	25U 
#define	RTC_IER_TCE_MSK	BIT(RTC_IER_TCE_POS)

#define	RTC_IER_TCC_POS	24U 
#define	RTC_IER_TCC_MSK	BIT(RTC_IER_TCC_POS)

#define	RTC_IER_WU_POS	18U 
#define	RTC_IER_WU_MSK	BIT(RTC_IER_WU_POS)

#define	RTC_IER_SSTC_POS	17U 
#define	RTC_IER_SSTC_MSK	BIT(RTC_IER_SSTC_POS)

#define	RTC_IER_RSC_POS	16U 
#define	RTC_IER_RSC_MSK	BIT(RTC_IER_RSC_POS)

#define	RTC_IER_TAMP2_POS	13U 
#define	RTC_IER_TAMP2_MSK	BIT(RTC_IER_TAMP2_POS)

#define	RTC_IER_TAMP1_POS	12U 
#define	RTC_IER_TAMP1_MSK	BIT(RTC_IER_TAMP1_POS)

#define	RTC_IER_TSOV_POS	11U 
#define	RTC_IER_TSOV_MSK	BIT(RTC_IER_TSOV_POS)

#define	RTC_IER_TS_POS	10U 
#define	RTC_IER_TS_MSK	BIT(RTC_IER_TS_POS)

#define	RTC_IER_ALMB_POS	9U 
#define	RTC_IER_ALMB_MSK	BIT(RTC_IER_ALMB_POS)

#define	RTC_IER_ALMA_POS	8U 
#define	RTC_IER_ALMA_MSK	BIT(RTC_IER_ALMA_POS)

#define	RTC_IER_YR_POS	5U 
#define	RTC_IER_YR_MSK	BIT(RTC_IER_YR_POS)

#define	RTC_IER_MON_POS	4U 
#define	RTC_IER_MON_MSK	BIT(RTC_IER_MON_POS)

#define	RTC_IER_DAY_POS	3U 
#define	RTC_IER_DAY_MSK	BIT(RTC_IER_DAY_POS)

#define	RTC_IER_HR_POS	2U 
#define	RTC_IER_HR_MSK	BIT(RTC_IER_HR_POS)

#define	RTC_IER_MIN_POS	1U 
#define	RTC_IER_MIN_MSK	BIT(RTC_IER_MIN_POS)

#define	RTC_IER_SEC_POS	0U 
#define	RTC_IER_SEC_MSK	BIT(RTC_IER_SEC_POS)

/****************** Bit definition for RTC_IFR register ************************/

#define	RTC_IFR_TCEF_POS	25U 
#define	RTC_IFR_TCEF_MSK	BIT(RTC_IFR_TCEF_POS)

#define	RTC_IFR_TCCF_POS	24U 
#define	RTC_IFR_TCCF_MSK	BIT(RTC_IFR_TCCF_POS)

#define	RTC_IFR_WUF_POS	18U 
#define	RTC_IFR_WUF_MSK	BIT(RTC_IFR_WUF_POS)

#define	RTC_IFR_SSTCF_POS	17U 
#define	RTC_IFR_SSTCF_MSK	BIT(RTC_IFR_SSTCF_POS)

#define	RTC_IFR_RSCF_POS	16U 
#define	RTC_IFR_RSCF_MSK	BIT(RTC_IFR_RSCF_POS)

#define	RTC_IFR_TAMP2F_POS	13U 
#define	RTC_IFR_TAMP2F_MSK	BIT(RTC_IFR_TAMP2F_POS)

#define	RTC_IFR_TAMP1F_POS	12U 
#define	RTC_IFR_TAMP1F_MSK	BIT(RTC_IFR_TAMP1F_POS)

#define	RTC_IFR_TSOVF_POS	11U 
#define	RTC_IFR_TSOVF_MSK	BIT(RTC_IFR_TSOVF_POS)

#define	RTC_IFR_TSF_POS	10U 
#define	RTC_IFR_TSF_MSK	BIT(RTC_IFR_TSF_POS)

#define	RTC_IFR_ALMBF_POS	9U 
#define	RTC_IFR_ALMBF_MSK	BIT(RTC_IFR_ALMBF_POS)

#define	RTC_IFR_ALMAF_POS	8U 
#define	RTC_IFR_ALMAF_MSK	BIT(RTC_IFR_ALMAF_POS)

#define	RTC_IFR_YRF_POS	5U 
#define	RTC_IFR_YRF_MSK	BIT(RTC_IFR_YRF_POS)

#define	RTC_IFR_MONF_POS	4U 
#define	RTC_IFR_MONF_MSK	BIT(RTC_IFR_MONF_POS)

#define	RTC_IFR_DAYF_POS	3U 
#define	RTC_IFR_DAYF_MSK	BIT(RTC_IFR_DAYF_POS)

#define	RTC_IFR_HRF_POS	2U 
#define	RTC_IFR_HRF_MSK	BIT(RTC_IFR_HRF_POS)

#define	RTC_IFR_MINF_POS	1U 
#define	RTC_IFR_MINF_MSK	BIT(RTC_IFR_MINF_POS)

#define	RTC_IFR_SECF_POS	0U 
#define	RTC_IFR_SECF_MSK	BIT(RTC_IFR_SECF_POS)

/****************** Bit definition for RTC_IFCR register ************************/

#define	RTC_IFCR_TCEFC_POS	25U 
#define	RTC_IFCR_TCEFC_MSK	BIT(RTC_IFCR_TCEFC_POS)

#define	RTC_IFCR_TCCFC_POS	24U 
#define	RTC_IFCR_TCCFC_MSK	BIT(RTC_IFCR_TCCFC_POS)

#define	RTC_IFCR_WUFC_POS	18U 
#define	RTC_IFCR_WUFC_MSK	BIT(RTC_IFCR_WUFC_POS)

#define	RTC_IFCR_SSTCFC_POS	17U 
#define	RTC_IFCR_SSTCFC_MSK	BIT(RTC_IFCR_SSTCFC_POS)

#define	RTC_IFCR_RSCFC_POS	16U 
#define	RTC_IFCR_RSCFC_MSK	BIT(RTC_IFCR_RSCFC_POS)

#define	RTC_IFCR_TAMP2FC_POS	13U 
#define	RTC_IFCR_TAMP2FC_MSK	BIT(RTC_IFCR_TAMP2FC_POS)

#define	RTC_IFCR_TAMP1FC_POS	12U 
#define	RTC_IFCR_TAMP1FC_MSK	BIT(RTC_IFCR_TAMP1FC_POS)

#define	RTC_IFCR_TSOVFC_POS	11U 
#define	RTC_IFCR_TSOVFC_MSK	BIT(RTC_IFCR_TSOVFC_POS)

#define	RTC_IFCR_TSSTC_POS	10U 
#define	RTC_IFCR_TSSTC_MSK	BIT(RTC_IFCR_TSSTC_POS)

#define	RTC_IFCR_ALMBFC_POS	9U 
#define	RTC_IFCR_ALMBFC_MSK	BIT(RTC_IFCR_ALMBFC_POS)

#define	RTC_IFCR_ALMAFC_POS	8U 
#define	RTC_IFCR_ALMAFC_MSK	BIT(RTC_IFCR_ALMAFC_POS)

#define	RTC_IFCR_YRFC_POS	5U 
#define	RTC_IFCR_YRFC_MSK	BIT(RTC_IFCR_YRFC_POS)

#define	RTC_IFCR_MONFC_POS	4U 
#define	RTC_IFCR_MONFC_MSK	BIT(RTC_IFCR_MONFC_POS)

#define	RTC_IFCR_DAYFC_POS	3U 
#define	RTC_IFCR_DAYFC_MSK	BIT(RTC_IFCR_DAYFC_POS)

#define	RTC_IFCR_HRFC_POS	2U 
#define	RTC_IFCR_HRFC_MSK	BIT(RTC_IFCR_HRFC_POS)

#define	RTC_IFCR_MINFC_POS	1U 
#define	RTC_IFCR_MINFC_MSK	BIT(RTC_IFCR_MINFC_POS)

#define	RTC_IFCR_SECFC_POS	0U 
#define	RTC_IFCR_SECFC_MSK	BIT(RTC_IFCR_SECFC_POS)

/****************** Bit definition for RTC_ISR register ************************/

#define	RTC_ISR_TCEF_POS	25U 
#define	RTC_ISR_TCEF_MSK	BIT(RTC_ISR_TCEF_POS)

#define	RTC_ISR_TCCF_POS	24U 
#define	RTC_ISR_TCCF_MSK	BIT(RTC_ISR_TCCF_POS)

#define	RTC_ISR_WUF_POS	18U 
#define	RTC_ISR_WUF_MSK	BIT(RTC_ISR_WUF_POS)

#define	RTC_ISR_SSTCF_POS	17U 
#define	RTC_ISR_SSTCF_MSK	BIT(RTC_ISR_SSTCF_POS)

#define	RTC_ISR_RSCF_POS	16U 
#define	RTC_ISR_RSCF_MSK	BIT(RTC_ISR_RSCF_POS)

#define	RTC_ISR_TAMP2F_POS	13U 
#define	RTC_ISR_TAMP2F_MSK	BIT(RTC_ISR_TAMP2F_POS)

#define	RTC_ISR_TAMP1F_POS	12U 
#define	RTC_ISR_TAMP1F_MSK	BIT(RTC_ISR_TAMP1F_POS)

#define	RTC_ISR_TSOVF_POS	11U 
#define	RTC_ISR_TSOVF_MSK	BIT(RTC_ISR_TSOVF_POS)

#define	RTC_ISR_TSF_POS	10U 
#define	RTC_ISR_TSF_MSK	BIT(RTC_ISR_TSF_POS)

#define	RTC_ISR_ALMBF_POS	9U 
#define	RTC_ISR_ALMBF_MSK	BIT(RTC_ISR_ALMBF_POS)

#define	RTC_ISR_ALMAF_POS	8U 
#define	RTC_ISR_ALMAF_MSK	BIT(RTC_ISR_ALMAF_POS)

#define	RTC_ISR_YRF_POS	5U 
#define	RTC_ISR_YRF_MSK	BIT(RTC_ISR_YRF_POS)

#define	RTC_ISR_MONF_POS	4U 
#define	RTC_ISR_MONF_MSK	BIT(RTC_ISR_MONF_POS)

#define	RTC_ISR_DAYF_POS	3U 
#define	RTC_ISR_DAYF_MSK	BIT(RTC_ISR_DAYF_POS)

#define	RTC_ISR_HRF_POS	2U 
#define	RTC_ISR_HRF_MSK	BIT(RTC_ISR_HRF_POS)

#define	RTC_ISR_MINF_POS	1U 
#define	RTC_ISR_MINF_MSK	BIT(RTC_ISR_MINF_POS)

#define	RTC_ISR_SECF_POS	0U 
#define	RTC_ISR_SECF_MSK	BIT(RTC_ISR_SECF_POS)

/****************** Bit definition for RTC_CALWPR register ************************/

#define	RTC_CALWPR_WP_POS	0U 
#define	RTC_CALWPR_WP_MSK	BIT(RTC_CALWPR_WP_POS)

/****************** Bit definition for RTC_CALCON register ************************/

#define	RTC_CALCON_DCMACC_POS	24U 
#define	RTC_CALCON_DCMACC_MSK	BIT(RTC_CALCON_DCMACC_POS)

#define	RTC_CALCON_ALG_POS	23U 
#define	RTC_CALCON_ALG_MSK	BIT(RTC_CALCON_ALG_POS)

#define	RTC_CALCON_TCP_POSS	20U 
#define	RTC_CALCON_TCP_POSE	22U 
#define	RTC_CALCON_TCP_MSK	BITS(RTC_CALCON_TCP_POSS,RTC_CALCON_TCP_POSE)

#define	RTC_CALCON_ERR_POS	19U 
#define	RTC_CALCON_ERR_MSK	BIT(RTC_CALCON_ERR_POS)

#define	RTC_CALCON_BUSY_POS	18U 
#define	RTC_CALCON_BUSY_MSK	BIT(RTC_CALCON_BUSY_POS)

#define	RTC_CALCON_TCM_POSS	16U 
#define	RTC_CALCON_TCM_POSE	17U 
#define	RTC_CALCON_TCM_MSK	BITS(RTC_CALCON_TCM_POSS,RTC_CALCON_TCM_POSE)

#define	RTC_CALCON_CALP_POSS	1U 
#define	RTC_CALCON_CALP_POSE	3U 
#define	RTC_CALCON_CALP_MSK	BITS(RTC_CALCON_CALP_POSS,RTC_CALCON_CALP_POSE)

#define	RTC_CALCON_CALEN_POS	0U 
#define	RTC_CALCON_CALEN_MSK	BIT(RTC_CALCON_CALEN_POS)

/****************** Bit definition for RTC_CALDR register ************************/

#define	RTC_CALDR_DATA_POSS	16U 
#define	RTC_CALDR_DATA_POSE	31U 
#define	RTC_CALDR_DATA_MSK	BITS(RTC_CALDR_DATA_POSS,RTC_CALDR_DATA_POSE)

#define	RTC_CALDR_VAL_POSS	0U 
#define	RTC_CALDR_VAL_POSE	15U 
#define	RTC_CALDR_VAL_MSK	BITS(RTC_CALDR_VAL_POSS,RTC_CALDR_VAL_POSE)

/****************** Bit definition for RTC_BKPRx register ************************/

#define	RTC_BKPRx_BKPRx_POSS	0U 
#define	RTC_BKPRx_BKPRx_POSE	31U 
#define	RTC_BKPRx_BKPRx_MSK	BITS(RTC_BKPRx_BKPRx_POSS,RTC_BKPRx_BKPRx_POSE)

typedef struct
{
	__IO uint32_t WPR;
	__IO uint32_t CON;
	__IO uint32_t PSR;
	__IO uint32_t TAMPCON;
	__IO uint32_t TIME;
	__IO uint32_t DATE;
	__I uint32_t SSEC;
	__IO uint32_t WUMAT;
	__IO uint32_t ALMA;
	__IO uint32_t ALMB;
	__IO uint32_t ALMASSEC;
	__IO uint32_t ALMBSSEC;
	__I uint32_t TSTIME;
	__I uint32_t TSDATE;
	__I uint32_t TSSSEC;
	__O uint32_t SSECTR;
	__IO uint32_t IER;
	__I uint32_t IFR;
	__O uint32_t IFCR;
	__I uint32_t ISR;
	__IO uint32_t CALWPR;
	__IO uint32_t CALCON;
	__IO uint32_t CALDR;
	__IO uint32_t RTC_BKPR[32];
} RTC_TypeDef;





#endif