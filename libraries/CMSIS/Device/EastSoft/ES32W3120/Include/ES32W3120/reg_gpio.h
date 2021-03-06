/**
  **************************************************************************************
  * @file    REG_GPIO.h
  * @brief   GPIO Head File
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

#ifndef __REG_GPIO_H__
#define __REG_GPIO_H__


/******************************************************************************/
/*                              设备特殊寄存器结构定义                        */
/******************************************************************************/

/*   允许匿名结构和匿名联合    */
 

/****************** Bit definition for GPIO_DIN register ************************/

#define	GPIO_DIN_DIN_POSS	0U 
#define	GPIO_DIN_DIN_POSE	15U 
#define	GPIO_DIN_DIN_MSK	BITS(GPIO_DIN_DIN_POSS,GPIO_DIN_DIN_POSE)

/****************** Bit definition for GPIO_DOUT register ************************/

#define	GPIO_DOUT_DOUT_POSS	0U 
#define	GPIO_DOUT_DOUT_POSE	15U 
#define	GPIO_DOUT_DOUT_MSK	BITS(GPIO_DOUT_DOUT_POSS,GPIO_DOUT_DOUT_POSE)

/****************** Bit definition for GPIO_BSRR register ************************/

#define	GPIO_BSRR_BRR_POSS	16U 
#define	GPIO_BSRR_BRR_POSE	31U 
#define	GPIO_BSRR_BRR_MSK	BITS(GPIO_BSRR_BRR_POSS,GPIO_BSRR_BRR_POSE)

#define	GPIO_BSRR_BSR_POSS	0U 
#define	GPIO_BSRR_BSR_POSE	15U 
#define	GPIO_BSRR_BSR_MSK	BITS(GPIO_BSRR_BSR_POSS,GPIO_BSRR_BSR_POSE)

/****************** Bit definition for GPIO_BIR register ************************/

#define	GPIO_BIR_BIR_POSS	0U 
#define	GPIO_BIR_BIR_POSE	15U 
#define	GPIO_BIR_BIR_MSK	BITS(GPIO_BIR_BIR_POSS,GPIO_BIR_BIR_POSE)

/****************** Bit definition for GPIO_MODE register ************************/

#define	GPIO_MODE_MODE_POSS	0U 
#define	GPIO_MODE_MODE_POSE	31U 
#define	GPIO_MODE_MODE_MSK	BITS(GPIO_MODE_MODE_POSS,GPIO_MODE_MODE_POSE)

/****************** Bit definition for GPIO_ODOS register ************************/

#define	GPIO_ODOS_ODOS_POSS	0U 
#define	GPIO_ODOS_ODOS_POSE	31U 
#define	GPIO_ODOS_ODOS_MSK	BITS(GPIO_ODOS_ODOS_POSS,GPIO_ODOS_ODOS_POSE)

/****************** Bit definition for GPIO_PUPD register ************************/

#define	GPIO_PUPD_PUPD_POSS	0U 
#define	GPIO_PUPD_PUPD_POSE	31U 
#define	GPIO_PUPD_PUPD_MSK	BITS(GPIO_PUPD_PUPD_POSS,GPIO_PUPD_PUPD_POSE)

/****************** Bit definition for GPIO_ODRV register ************************/

#define	GPIO_ODRV_ODRV_POSS	0U 
#define	GPIO_ODRV_ODRV_POSE	31U 
#define	GPIO_ODRV_ODRV_MSK	BITS(GPIO_ODRV_ODRV_POSS,GPIO_ODRV_ODRV_POSE)

/****************** Bit definition for GPIO_FLT register ************************/

#define	GPIO_FLT_FLT_POSS	0U 
#define	GPIO_FLT_FLT_POSE	15U 
#define	GPIO_FLT_FLT_MSK	BITS(GPIO_FLT_FLT_POSS,GPIO_FLT_FLT_POSE)

/****************** Bit definition for GPIO_TYPE register ************************/

/****************** Bit definition for GPIO_FUNC0 register ************************/

#define	GPIO_FUNC0_FSEL_IO7_POSS	28U 
#define	GPIO_FUNC0_FSEL_IO7_POSE	31U 
#define	GPIO_FUNC0_FSEL_IO7_MSK	BITS(GPIO_FUNC0_FSEL_IO7_POSS,GPIO_FUNC0_FSEL_IO7_POSE)

#define	GPIO_FUNC0_FSEL_IO6_POSS	24U 
#define	GPIO_FUNC0_FSEL_IO6_POSE	27U 
#define	GPIO_FUNC0_FSEL_IO6_MSK	BITS(GPIO_FUNC0_FSEL_IO6_POSS,GPIO_FUNC0_FSEL_IO6_POSE)

#define	GPIO_FUNC0_FSEL_IO5_POSS	20U 
#define	GPIO_FUNC0_FSEL_IO5_POSE	23U 
#define	GPIO_FUNC0_FSEL_IO5_MSK	BITS(GPIO_FUNC0_FSEL_IO5_POSS,GPIO_FUNC0_FSEL_IO5_POSE)

#define	GPIO_FUNC0_FSEL_IO4_POSS	16U 
#define	GPIO_FUNC0_FSEL_IO4_POSE	19U 
#define	GPIO_FUNC0_FSEL_IO4_MSK	BITS(GPIO_FUNC0_FSEL_IO4_POSS,GPIO_FUNC0_FSEL_IO4_POSE)

#define	GPIO_FUNC0_FSEL_IO3_POSS	12U 
#define	GPIO_FUNC0_FSEL_IO3_POSE	15U 
#define	GPIO_FUNC0_FSEL_IO3_MSK	BITS(GPIO_FUNC0_FSEL_IO3_POSS,GPIO_FUNC0_FSEL_IO3_POSE)

#define	GPIO_FUNC0_FSEL_IO2_POSS	8U 
#define	GPIO_FUNC0_FSEL_IO2_POSE	11U 
#define	GPIO_FUNC0_FSEL_IO2_MSK	BITS(GPIO_FUNC0_FSEL_IO2_POSS,GPIO_FUNC0_FSEL_IO2_POSE)

#define	GPIO_FUNC0_FSEL_IO1_POSS	4U 
#define	GPIO_FUNC0_FSEL_IO1_POSE	7U 
#define	GPIO_FUNC0_FSEL_IO1_MSK	BITS(GPIO_FUNC0_FSEL_IO1_POSS,GPIO_FUNC0_FSEL_IO1_POSE)

#define	GPIO_FUNC0_FSEL_IO0_POSS	0U 
#define	GPIO_FUNC0_FSEL_IO0_POSE	3U 
#define	GPIO_FUNC0_FSEL_IO0_MSK	BITS(GPIO_FUNC0_FSEL_IO0_POSS,GPIO_FUNC0_FSEL_IO0_POSE)

/****************** Bit definition for GPIO_FUNC1 register ************************/

#define	GPIO_FUNC1_FSEL_IO15_POSS	28U 
#define	GPIO_FUNC1_FSEL_IO15_POSE	31U 
#define	GPIO_FUNC1_FSEL_IO15_MSK	BITS(GPIO_FUNC1_FSEL_IO15_POSS,GPIO_FUNC1_FSEL_IO15_POSE)

#define	GPIO_FUNC1_FSEL_IO14_POSS	24U 
#define	GPIO_FUNC1_FSEL_IO14_POSE	27U 
#define	GPIO_FUNC1_FSEL_IO14_MSK	BITS(GPIO_FUNC1_FSEL_IO14_POSS,GPIO_FUNC1_FSEL_IO14_POSE)

#define	GPIO_FUNC1_FSEL_IO13_POSS	20U 
#define	GPIO_FUNC1_FSEL_IO13_POSE	23U 
#define	GPIO_FUNC1_FSEL_IO13_MSK	BITS(GPIO_FUNC1_FSEL_IO13_POSS,GPIO_FUNC1_FSEL_IO13_POSE)

#define	GPIO_FUNC1_FSEL_IO12_POSS	16U 
#define	GPIO_FUNC1_FSEL_IO12_POSE	19U 
#define	GPIO_FUNC1_FSEL_IO12_MSK	BITS(GPIO_FUNC1_FSEL_IO12_POSS,GPIO_FUNC1_FSEL_IO12_POSE)

#define	GPIO_FUNC1_FSEL_IO11_POSS	12U 
#define	GPIO_FUNC1_FSEL_IO11_POSE	15U 
#define	GPIO_FUNC1_FSEL_IO11_MSK	BITS(GPIO_FUNC1_FSEL_IO11_POSS,GPIO_FUNC1_FSEL_IO11_POSE)

#define	GPIO_FUNC1_FSEL_IO10_POSS	8U 
#define	GPIO_FUNC1_FSEL_IO10_POSE	11U 
#define	GPIO_FUNC1_FSEL_IO10_MSK	BITS(GPIO_FUNC1_FSEL_IO10_POSS,GPIO_FUNC1_FSEL_IO10_POSE)

#define	GPIO_FUNC1_FSEL_IO9_POSS	4U 
#define	GPIO_FUNC1_FSEL_IO9_POSE	7U 
#define	GPIO_FUNC1_FSEL_IO9_MSK	BITS(GPIO_FUNC1_FSEL_IO9_POSS,GPIO_FUNC1_FSEL_IO9_POSE)

#define	GPIO_FUNC1_FSEL_IO8_POSS	0U 
#define	GPIO_FUNC1_FSEL_IO8_POSE	3U 
#define	GPIO_FUNC1_FSEL_IO8_MSK	BITS(GPIO_FUNC1_FSEL_IO8_POSS,GPIO_FUNC1_FSEL_IO8_POSE)

/****************** Bit definition for GPIO_LOCK register ************************/

#define	GPIO_LOCK_KEY_POSS	16U 
#define	GPIO_LOCK_KEY_POSE	31U 
#define	GPIO_LOCK_KEY_MSK	BITS(GPIO_LOCK_KEY_POSS,GPIO_LOCK_KEY_POSE)

#define	GPIO_LOCK_LOCK_POSS	0U 
#define	GPIO_LOCK_LOCK_POSE	15U 
#define	GPIO_LOCK_LOCK_MSK	BITS(GPIO_LOCK_LOCK_POSS,GPIO_LOCK_LOCK_POSE)

typedef struct
{
	__I uint32_t DIN;
	__IO uint32_t DOUT;
	__O uint32_t BSRR;
	__O uint32_t BIR;
	__IO uint32_t MODE;
	__IO uint32_t ODOS;
	__IO uint32_t PUPD;
	__IO uint32_t ODRV;
	__IO uint32_t FLT;
	__IO uint32_t TYPE;
	__IO uint32_t FUNC0;
	__IO uint32_t FUNC1;
	__IO uint32_t LOCK;
} GPIO_TypeDef;

/****************** Bit definition for GPIO_EXTIRER register ************************/

#define	GPIO_EXTIRER_EXTIRER_POSS	0U 
#define	GPIO_EXTIRER_EXTIRER_POSE	15U 
#define	GPIO_EXTIRER_EXTIRER_MSK	BITS(GPIO_EXTIRER_EXTIRER_POSS,GPIO_EXTIRER_EXTIRER_POSE)

/****************** Bit definition for GPIO_EXTIFER register ************************/

#define	GPIO_EXTIFER_EXTIFER_POSS	0U 
#define	GPIO_EXTIFER_EXTIFER_POSE	15U 
#define	GPIO_EXTIFER_EXTIFER_MSK	BITS(GPIO_EXTIFER_EXTIFER_POSS,GPIO_EXTIFER_EXTIFER_POSE)

/****************** Bit definition for GPIO_EXTIEN register ************************/

#define	GPIO_EXTIEN_EXTIEN_POSS	0U 
#define	GPIO_EXTIEN_EXTIEN_POSE	15U 
#define	GPIO_EXTIEN_EXTIEN_MSK	BITS(GPIO_EXTIEN_EXTIEN_POSS,GPIO_EXTIEN_EXTIEN_POSE)

/****************** Bit definition for GPIO_EXTIFLAG register ************************/

#define	GPIO_EXTIFLAG_EXTIFLAG_POSS	0U 
#define	GPIO_EXTIFLAG_EXTIFLAG_POSE	15U 
#define	GPIO_EXTIFLAG_EXTIFLAG_MSK	BITS(GPIO_EXTIFLAG_EXTIFLAG_POSS,GPIO_EXTIFLAG_EXTIFLAG_POSE)

/****************** Bit definition for GPIO_EXTISFR register ************************/

#define	GPIO_EXTISFR_EXTISFR_POSS	0U 
#define	GPIO_EXTISFR_EXTISFR_POSE	15U 
#define	GPIO_EXTISFR_EXTISFR_MSK	BITS(GPIO_EXTISFR_EXTISFR_POSS,GPIO_EXTISFR_EXTISFR_POSE)

/****************** Bit definition for GPIO_EXTICFR register ************************/

#define	GPIO_EXTICFR_EXTICFR_POSS	0U 
#define	GPIO_EXTICFR_EXTICFR_POSE	15U 
#define	GPIO_EXTICFR_EXTICFR_MSK	BITS(GPIO_EXTICFR_EXTICFR_POSS,GPIO_EXTICFR_EXTICFR_POSE)

/****************** Bit definition for GPIO_EXTIPSR0 register ************************/

#define	GPIO_EXTIPSR0_EXTIS7_POSS	28U 
#define	GPIO_EXTIPSR0_EXTIS7_POSE	30U 
#define	GPIO_EXTIPSR0_EXTIS7_MSK	BITS(GPIO_EXTIPSR0_EXTIS7_POSS,GPIO_EXTIPSR0_EXTIS7_POSE)

#define	GPIO_EXTIPSR0_EXTIS6_POSS	24U 
#define	GPIO_EXTIPSR0_EXTIS6_POSE	26U 
#define	GPIO_EXTIPSR0_EXTIS6_MSK	BITS(GPIO_EXTIPSR0_EXTIS6_POSS,GPIO_EXTIPSR0_EXTIS6_POSE)

#define	GPIO_EXTIPSR0_EXTIS5_POSS	20U 
#define	GPIO_EXTIPSR0_EXTIS5_POSE	22U 
#define	GPIO_EXTIPSR0_EXTIS5_MSK	BITS(GPIO_EXTIPSR0_EXTIS5_POSS,GPIO_EXTIPSR0_EXTIS5_POSE)

#define	GPIO_EXTIPSR0_EXTIS4_POSS	16U 
#define	GPIO_EXTIPSR0_EXTIS4_POSE	18U 
#define	GPIO_EXTIPSR0_EXTIS4_MSK	BITS(GPIO_EXTIPSR0_EXTIS4_POSS,GPIO_EXTIPSR0_EXTIS4_POSE)

#define	GPIO_EXTIPSR0_EXTIS3_POSS	12U 
#define	GPIO_EXTIPSR0_EXTIS3_POSE	14U 
#define	GPIO_EXTIPSR0_EXTIS3_MSK	BITS(GPIO_EXTIPSR0_EXTIS3_POSS,GPIO_EXTIPSR0_EXTIS3_POSE)

#define	GPIO_EXTIPSR0_EXTIS2_POSS	8U 
#define	GPIO_EXTIPSR0_EXTIS2_POSE	10U 
#define	GPIO_EXTIPSR0_EXTIS2_MSK	BITS(GPIO_EXTIPSR0_EXTIS2_POSS,GPIO_EXTIPSR0_EXTIS2_POSE)

#define	GPIO_EXTIPSR0_EXTIS1_POSS	4U 
#define	GPIO_EXTIPSR0_EXTIS1_POSE	6U 
#define	GPIO_EXTIPSR0_EXTIS1_MSK	BITS(GPIO_EXTIPSR0_EXTIS1_POSS,GPIO_EXTIPSR0_EXTIS1_POSE)

#define	GPIO_EXTIPSR0_EXTIS0_POSS	0U 
#define	GPIO_EXTIPSR0_EXTIS0_POSE	2U 
#define	GPIO_EXTIPSR0_EXTIS0_MSK	BITS(GPIO_EXTIPSR0_EXTIS0_POSS,GPIO_EXTIPSR0_EXTIS0_POSE)

/****************** Bit definition for GPIO_EXTIPSR1 register ************************/

#define	GPIO_EXTIPSR1_EXTIS15_POSS	28U 
#define	GPIO_EXTIPSR1_EXTIS15_POSE	30U 
#define	GPIO_EXTIPSR1_EXTIS15_MSK	BITS(GPIO_EXTIPSR1_EXTIS15_POSS,GPIO_EXTIPSR1_EXTIS15_POSE)

#define	GPIO_EXTIPSR1_EXTIS14_POSS	24U 
#define	GPIO_EXTIPSR1_EXTIS14_POSE	26U 
#define	GPIO_EXTIPSR1_EXTIS14_MSK	BITS(GPIO_EXTIPSR1_EXTIS14_POSS,GPIO_EXTIPSR1_EXTIS14_POSE)

#define	GPIO_EXTIPSR1_EXTIS13_POSS	20U 
#define	GPIO_EXTIPSR1_EXTIS13_POSE	22U 
#define	GPIO_EXTIPSR1_EXTIS13_MSK	BITS(GPIO_EXTIPSR1_EXTIS13_POSS,GPIO_EXTIPSR1_EXTIS13_POSE)

#define	GPIO_EXTIPSR1_EXTIS12_POSS	16U 
#define	GPIO_EXTIPSR1_EXTIS12_POSE	18U 
#define	GPIO_EXTIPSR1_EXTIS12_MSK	BITS(GPIO_EXTIPSR1_EXTIS12_POSS,GPIO_EXTIPSR1_EXTIS12_POSE)

#define	GPIO_EXTIPSR1_EXTIS11_POSS	12U 
#define	GPIO_EXTIPSR1_EXTIS11_POSE	14U 
#define	GPIO_EXTIPSR1_EXTIS11_MSK	BITS(GPIO_EXTIPSR1_EXTIS11_POSS,GPIO_EXTIPSR1_EXTIS11_POSE)

#define	GPIO_EXTIPSR1_EXTIS10_POSS	8U 
#define	GPIO_EXTIPSR1_EXTIS10_POSE	10U 
#define	GPIO_EXTIPSR1_EXTIS10_MSK	BITS(GPIO_EXTIPSR1_EXTIS10_POSS,GPIO_EXTIPSR1_EXTIS10_POSE)

#define	GPIO_EXTIPSR1_EXTIS9_POSS	4U 
#define	GPIO_EXTIPSR1_EXTIS9_POSE	6U 
#define	GPIO_EXTIPSR1_EXTIS9_MSK	BITS(GPIO_EXTIPSR1_EXTIS9_POSS,GPIO_EXTIPSR1_EXTIS9_POSE)

#define	GPIO_EXTIPSR1_EXTIS8_POSS	0U 
#define	GPIO_EXTIPSR1_EXTIS8_POSE	2U 
#define	GPIO_EXTIPSR1_EXTIS8_MSK	BITS(GPIO_EXTIPSR1_EXTIS8_POSS,GPIO_EXTIPSR1_EXTIS8_POSE)

/****************** Bit definition for GPIO_EXTIFLTCR register ************************/

#define	GPIO_EXTIFLTCR_FLTCKS_POSS	24U 
#define	GPIO_EXTIFLTCR_FLTCKS_POSE	25U 
#define	GPIO_EXTIFLTCR_FLTCKS_MSK	BITS(GPIO_EXTIFLTCR_FLTCKS_POSS,GPIO_EXTIFLTCR_FLTCKS_POSE)

#define	GPIO_EXTIFLTCR_FLTSEL_POSS	16U 
#define	GPIO_EXTIFLTCR_FLTSEL_POSE	23U 
#define	GPIO_EXTIFLTCR_FLTSEL_MSK	BITS(GPIO_EXTIFLTCR_FLTSEL_POSS,GPIO_EXTIFLTCR_FLTSEL_POSE)

#define	GPIO_EXTIFLTCR_FLTEN_POSS	0U 
#define	GPIO_EXTIFLTCR_FLTEN_POSE	15U 
#define	GPIO_EXTIFLTCR_FLTEN_MSK	BITS(GPIO_EXTIFLTCR_FLTEN_POSS,GPIO_EXTIFLTCR_FLTEN_POSE)

typedef struct
{
	__IO uint32_t EXTIRER;
	uint32_t RESERVED0 ;
	__IO uint32_t EXTIFER;
	uint32_t RESERVED1 ;
	__IO uint32_t EXTIEN;
	uint32_t RESERVED2 ;
	__I uint32_t EXTIFLAG;
	uint32_t RESERVED3 ;
	__O uint32_t EXTISFR;
	uint32_t RESERVED4 ;
	__O uint32_t EXTICFR;
	uint32_t RESERVED5 ;
	__IO uint32_t EXTIPSR0;
	__IO uint32_t EXTIPSR1;
	uint32_t RESERVED6[2] ;
	__IO uint32_t EXTIFLTCR;
} GPIOEXTI_TypeDef;





#endif
