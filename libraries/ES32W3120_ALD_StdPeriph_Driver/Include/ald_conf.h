/**
  *********************************************************************************
  *
  * @file    ald_conf.h
  * @brief   Enable/Disable the peripheral module.
  *
  * @version V1.0
  * @date    01 Jul 2019
  * @author  AE Team
  * @note
  *
  * Copyright (C) Shanghai Eastsoft Microelectronics Co. Ltd. All rights reserved.
  *
  *********************************************************************************
  */


#ifndef __ALD_CONF_H__
#define __ALD_CONF_H__


#define ALD_DMA
#define ALD_GPIO
#define ALD_UART
#define ALD_LPUART
#define ALD_I2C
#define ALD_CMU
#define ALD_RMU
#define ALD_PMU
#define ALD_RTC
#define ALD_ADC
#define ALD_UTILS      
#define ALD_TIMER
#define ALD_LPTIM     
#define ALD_SPI          
#define ALD_BKPC
                    
//#define ALD_CAN  
//#define ALD_WDT
//#define ALD_LCD
//#define ALD_FLASH
//#define ALD_CRC
//#define ALD_CRYPT
//#define ALD_PIS
//#define ALD_CALC
//#define ALD_ACMP
//#define ALD_OPAMP
//#define ALD_TRNG
//#define ALD_TSENSE
//#define ALD_DAC
//#define ALD_IAP
//#define ALD_I2S
//#define ALD_ECC
//#define ALD_NAND
//#define ALD_QSPI
//#define ALD_NOR
//#define ALD_SRAM
//#define ALD_USB

#include "ald_syscfg.h"
#include "ald_cmu.h"

#ifdef  ALD_GPIO

    #include "ald_gpio.h"

#endif /*ALD_GPIO*/

#ifdef  ALD_PMU

    #include "ald_pmu.h"

#endif /*ALD_PMU*/

#ifdef  ALD_RTC

    #include "ald_rtc.h"

#endif /*ALD_RTC*/

#ifdef  ALD_I2S

    #include "ald_i2s.h"

#endif /*ALD_I2S*/

#ifdef  ALD_PIS

    #include "ald_pis.h"

#endif /*ALD_PIS*/

#ifdef  ALD_TIMER

    #include "ald_timer.h"

#endif /*ALD_TIMER*/

#ifdef  ALD_ADC

    #include "ald_adc.h"

#endif /*ALD_ADC*/

#if defined(ALD_NAND) || defined(ALD_NOR) || defined(ALD_SRAM)
    #define ALD_EBI
#endif  /*defined(ALD_NAND) || defined(ALD_NOR) || defined(ALD_SRAM)*/

#define TICK_INT_PRIORITY   3

#endif     /*__ALD_CONF_H__*/
