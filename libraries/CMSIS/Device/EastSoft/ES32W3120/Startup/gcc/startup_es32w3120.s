/**
  ******************************************************************************

  * @file      startup_es32f36xx.s
  * @author    AE Team
  * @brief     ES32F36xx devices vector table for GCC toolchain.
  *            This module performs:
  *                - Set the initial SP
  *                - Set the initial PC == Reset_Handler,
  *                - Set the vector table entries with the exceptions ISR addres
s
  *                - Branches to main in the C library (which eventually
  *                  calls main()).
  *            After Reset the Cortex-M3 processor is in Thread mode,
  *            priority is Privileged, and the Stack is set to Main.
  * @note
  *          Change Logs:
  *          Date            Author          Notes
  *          23 Jan 2019     AE Team         The first version
  *
  * Copyright (C) Shanghai Eastsoft Microelectronics Co. Ltd. All rights reserve
d.
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
  ******************************************************************************
****
  */

  .syntax unified
  .arch armv7-m
  .cpu cortex-m3
  .fpu softvfp
  .thumb

.global g_pfnVectors
.global Default_Handler

/* start address for the initialization values of the .data section.
defined in linker script */
.word _sidata
/* start address for the .data section. defined in linker script */
.word _sdata
/* end address for the .data section. defined in linker script */
.word _edata
/* start address for the .bss section. defined in linker script */
.word _sbss
/* end address for the .bss section. defined in linker script */
.word _ebss

  .section .text.Reset_Handler
  .weak Reset_Handler
  .type Reset_Handler, %function
Reset_Handler:
  ldr   r0, =_estack
  mov   sp, r0          /* set stack pointer */
  
/* Copy the data segment initializers from flash to SRAM */
  ldr r0, =_sdata
  ldr r1, =_edata
  ldr r2, =_sidata
  movs r3, #0
  b LoopCopyDataInit

CopyDataInit:
  ldr r4, [r2, r3]
  str r4, [r0, r3]
  adds r3, r3, #4

LoopCopyDataInit:
  adds r4, r0, r3
  cmp r4, r1
  bcc CopyDataInit
  
/* Zero fill the bss segment. */
  ldr r2, =_sbss
  ldr r4, =_ebss
  movs r3, #0
  b LoopFillZerobss

FillZerobss:
  str  r3, [r2]
  adds r2, r2, #4

LoopFillZerobss:
  cmp r2, r4
  bcc FillZerobss
  

/*bl __libc_init_array

  bl main */
  bl entry

LoopForever:
    b LoopForever


.size Reset_Handler, .-Reset_Handler

/**
 * @brief  This is the code that gets called when the processor receives an
 *         unexpected interrupt.  This simply enters an infinite loop, preserving
 *         the system state for examination by a debugger.
 *
 * @param  None
 * @retval : None
*/
    .section .text.Default_Handler,"ax",%progbits
Default_Handler:
Infinite_Loop:
  b Infinite_Loop
  .size Default_Handler, .-Default_Handler
/******************************************************************************
*
* The minimal vector table for a Cortex M0.  Note that the proper constructs
* must be placed on this to ensure that it ends up at physical address
* 0x0000.0000.
*
******************************************************************************/
   .section .isr_vector,"a",%progbits
  .type g_pfnVectors, %object
  .size g_pfnVectors, .-g_pfnVectors


g_pfnVectors:
  .word  _estack                        /* 0,  load top of stack */
  .word  Reset_Handler                  /* 1,  reset handler */
  .word  NMI_Handler                    /* 2,  nmi handler */
  .word  HardFault_Handler              /* 3,  hard fault handler */
  .word  MemManage_Handler              /* 4,  MPU Fault Handler */
  .word  BusFault_Handler               /* 5,  Bus Fault Handler */
  .word  UsageFault_Handler             /* 6,  Usage Fault Handler */
  .word  0                              /* 7,  Reserved */
  .word  0                              /* 8,  Reserved */
  .word  0                              /* 9,  Reserved */
  .word  0                              /* 10, Reserved */
  .word  SVC_Handler                    /* 11, svcall handler */
  .word  DebugMon_Handler               /* 12, Debug Monitor Handler */
  .word  0                              /* 13, Reserved */
  .word  PendSV_Handler                 /* 14, pendsv handler */
  .word  SysTick_Handler                /* 15, systick handler */
  .word  WWDG_IRQHandler                   /* 16, irq0    WWDG handler */
  .word  IWDG_IRQHandler                   /* 17, irq1    IWDG handler */
  .word  LVD_IRQHandler                    /* 18, irq2    LVD handler */
  .word  RTC_WAKE_IRQHandler                    /* 19, irq3    RTC handler */
  .word  RTC_ALARM_IRQHandler                              /* 20, irq4    Reserved */
  .word  0                              /* 21, irq5    Reserved */
  .word  CMU_IRQHandler                    /* 22, irq6    CMU handler */
  .word  ADC_IRQHandler                   /* 23, irq7    ADC0 handler */
  .word  LP16T_IRQHandler                /* 24, irq8    CAN0_TX handler */
  .word  0               /* 25, Reserved */
  .word  BS16T0_IRQHandler               /* 26, irq10   CAN0_RX1 handler */
  .word  BS16T1_IRQHandler         /* 27, irq11   CAN0_EXCEPTION handler */
  .word  GP16C4T0_IRQHandler           /* 28, irq12   AD16C4T0_BRK handler */
  .word  0            /* 29, Reserved */
  .word  0      /* 30, Reserved */
  .word  0            /* 31, Reserved */
  .word  GP16C4T1_IRQHandler           /* 32, irq16   AD16C4T1_BRK handler */
  .word  0            /* 33, Reserved */
  .word  0      /* 34, Reserved */
  .word  0            /* 35, Reserved */
  .word  AD16C4T0_BRK_IRQHandler               /* 36, irq20   GP32C4T0 handler */
  .word  AD16C4T0_UP_IRQHandler               /* 37, irq21   GP32C4T1 handler */
  .word  AD16C4T0_TRIG_COM_IRQHandler                 /* 38, irq22   BS16T0  handler */
  .word  AD16C4T0_CC_IRQHandler                 /* 39, irq23   BS16T1 handler */
  .word  AD16C4T1_BRK_IRQHandler               /* 40, irq24   GP16C4T0 handler */
  .word  AD16C4T1_UP_IRQHandler               /* 41, irq25   GP16C4T1 handler */
  .word  AD16C4T1_TRIG_COM_IRQHandler                              /* 42, irq26   Reserved */
  .word  AD16C4T1_CC_IRQHandler               /* 43, irq27   DAC0_CH0 handler */
  .word  I2C0_EV_IRQHandler                /* 44, irq28   I2C0_EV handler */
  .word  I2C0_ERR_IRQHandler               /* 45, irq29   I2C0_ERR handler */
  .word  I2C1_EV_IRQHandler                /* 46  irq30   I2C1_EV handler */
  .word  I2C1_ERR_IRQHandler               /* 47, irq31   I2C1_ERR handler */
  .word  SPI0_I2S0_IRQHandler              /* 48, irq32   SPI0_I2S0 handler */
  .word  SPI1_I2S1_IRQHandler              /* 49, irq33   SPI1_I2S1 handler */
  .word  UART0_IRQHandler                  /* 50, irq34   UART0 handler */
  .word  UART1_IRQHandler                  /* 51, irq35   UART1 handler */
  .word  UART2_IRQHandler                  /* 52, irq36   UART2 handler */
  .word  0                  /* 53, Reserved */
  .word  PDM2PCM_IRQHandler                  /* 54, PDM2PCM IRQHandler */
  .word  TK_IRQHandler                  /* 55, TK IRQHandler */
  .word  KSCAN_IRQHandler                              /* 56, KSCAN IRQHandler */
  .word  QSPI_IRQHandler                              /* 57, QSPI IRQHandler */
  .word  CRYPT_IRQHandler                  /* 58, CRYPT IRQHandler */
  .word  ADPCM_IRQHandler                  /* 59, ADPCM IRQHandler */
  .word  0                  /* 60, Reserved */
  .word  HASH_IRQHandler              /* 61, HASH IRQHandler */
  .word  0                              /* 62, Reserved */
  .word  ECC_IRQHandler                    /* 63, ECC IRQHandler */
  .word  TRNG_IRQHandler                   /* 64, TRNG IRQHandler */
  .word  0                 /* 65, Reserved */
  .word  EXTI0_IRQHandler                  /* 66, EXTI0 handler */
  .word  EXTI1_IRQHandler                  /* 67, EXTI1 handler */
  .word  EXTI2_IRQHandler                  /* 68, EXTI2 handler */
  .word  EXTI3_IRQHandler                  /* 69, EXTI3 handler */
  .word  EXTI4_IRQHandler                  /* 70, EXTI4 handler */
  .word  EXTI5_IRQHandler                  /* 71, EXTI5 handler */
  .word  EXTI6_IRQHandler                  /* 72, EXTI6 handler */
  .word  EXTI7_IRQHandler                  /* 73, EXTI7 handler */
  .word  EXTI8_IRQHandler                  /* 74, EXTI8 handler */
  .word  EXTI9_IRQHandler                  /* 75, EXTI9 handler */
  .word  EXTI10_IRQHandler                 /* 76, EXTI10 handler */
  .word  EXTI11_IRQHandler                 /* 77, EXTI11 handler */
  .word  EXTI12_IRQHandler                 /* 78, EXTI12 handler */
  .word  EXTI13_IRQHandler                 /* 79, EXTI13 handler */
  .word  EXTI14_IRQHandler                 /* 80, EXTI14 handler */
  .word  EXTI15_IRQHandler                 /* 81, EXTI15 handler */
  .word  DMA_IRQHandler                    /* 82, DMA handler */
  .word  0                   /* 83, Reserved */
  .word  0               /* 84, Reserved */
  .word  0                   /* 85, Reserved */
  .word  0                /* 86, Reserved */
  .word  0                /* 87, Reserved */
  .word  0                  /* 88, Reserved */
  .word  0                   /* 89, Reserved */
  .word  0               /* 90, Reserved */
  .word  0                   /* 91, Reserved */
  .word  0                /* 92, Reserved */
  .word  0                /* 93, Reserved */
  .word  0                  /* 94, Reserved */
  .word  0                   /* 95, Reserved */
  .word  BLE_ERROR_IRQHandler               /* 96, BLE_ERROR IRQHandle */
  .word  BLE_HSLOT_IRQHandler                   /* 97, BLE_HSLOT IRQHandle */
  .word  BLE_RX_IRQHandler                /* 98, BLE_RX IRQHandler */
  .word  BLE_TX_IRQHandler                /* 99, BLE_TX IRQHandler */
  .word  BLE_START_IRQHandler                  /* 100, BLE_START IRQHandl */
  .word  BLE_END_IRQHandler                   /* 101, BLE_END IRQHandler */
  .word  BLE_SKIP_IRQHandler               /* 102, BLE_SKIP IRQHandle */
  .word  BLE_SLP_IRQHandler                   /* 103, BLE_SLP IRQHandler */
  .word  BLE_CRYPT_IRQHandler                /* 104, BLE_CRYPT IRQHandl */
  .word  BLE_GROSSTGTIM_IRQHandler                /* 105, BLE_GROSSTGTIM IRQ */
  .word  BLE_FINETGTIM_IRQHandler                  /* 106, BLE_FINETGTIM IRQH */
  .word  BLE_TIMESTAMP_TGT_IRQHandler                   /* 107, BLE_TIMESTAMP_TGT */
  .word  BLE_SW_IRQHandler               /* 108, BLE_SW IRQHandler */
  .word  BLE_AUDIO0_IRQHandler                   /* 109, BLE_AUDIO0 IRQHand */
  .word  BLE_AUDIO1_IRQHandler                /* 110, BLE_AUDIO1 IRQHand */
  .word  BLE_AUDIO2_IRQHandler                /* 111, BLE_AUDIO2 IRQHand */


/*******************************************************************************
*
* Provide weak aliases for each Exception handler to the Default_Handler.
* As they are weak aliases, any function with the same name will override
* this definition.
*
*******************************************************************************/

  .weak      NMI_Handler
  .thumb_set NMI_Handler,Default_Handler

  .weak      HardFault_Handler
  .thumb_set HardFault_Handler,Default_Handler

  .weak      MemManage_Handler
  .thumb_set MemManage_Handler,Default_Handler

  .weak      BusFault_Handler
  .thumb_set BusFault_Handler,Default_Handler

  .weak      UsageFault_Handler
  .thumb_set UsageFault_Handler,Default_Handler

  .weak      SVC_Handler
  .thumb_set SVC_Handler,Default_Handler

  .weak      DebugMon_Handler
  .thumb_set DebugMon_Handler,Default_Handler

  .weak      PendSV_Handler
  .thumb_set PendSV_Handler,Default_Handler

  .weak      SysTick_Handler
  .thumb_set SysTick_Handler,Default_Handler

  .weak      WWDG_IRQHandler
  .thumb_set WWDG_IRQHandler,Default_Handler

  .weak      IWDG_IRQHandler
  .thumb_set IWDG_IRQHandler,Default_Handler

  .weak      LVD_IRQHandler
  .thumb_set LVD_IRQHandler,Default_Handler

  .weak      RTC_WAKE_IRQHandler
  .thumb_set RTC_WAKE_IRQHandler,Default_Handler

  .weak      RTC_ALARM_IRQHandler
  .thumb_set RTC_ALARM_IRQHandler,Default_Handler

  .weak      CMU_IRQHandler
  .thumb_set CMU_IRQHandler,Default_Handler

  .weak      ADC_IRQHandler
  .thumb_set ADC_IRQHandler,Default_Handler

  .weak      LP16T_IRQHandler
  .thumb_set LP16T_IRQHandler,Default_Handler

  .weak      BS16T0_IRQHandler
  .thumb_set BS16T0_IRQHandler,Default_Handler

  .weak      BS16T1_IRQHandler
  .thumb_set BS16T1_IRQHandler,Default_Handler

  .weak      GP16C4T0_IRQHandler
  .thumb_set GP16C4T0_IRQHandler,Default_Handler

  .weak      GP16C4T1_IRQHandler
  .thumb_set GP16C4T1_IRQHandler,Default_Handler

  .weak      AD16C4T0_BRK_IRQHandler
  .thumb_set AD16C4T0_BRK_IRQHandler,Default_Handler

  .weak      AD16C4T0_UP_IRQHandler
  .thumb_set AD16C4T0_UP_IRQHandler,Default_Handler

  .weak      AD16C4T0_TRIG_COM_IRQHandler
  .thumb_set AD16C4T0_TRIG_COM_IRQHandler,Default_Handler

  .weak      AD16C4T0_CC_IRQHandler
  .thumb_set AD16C4T0_CC_IRQHandler,Default_Handler

  .weak      AD16C4T1_BRK_IRQHandler
  .thumb_set AD16C4T1_BRK_IRQHandler,Default_Handler

  .weak      AD16C4T1_UP_IRQHandler
  .thumb_set AD16C4T1_UP_IRQHandler,Default_Handler

  .weak      AD16C4T1_TRIG_COM_IRQHandler
  .thumb_set AD16C4T1_TRIG_COM_IRQHandler,Default_Handler

  .weak      AD16C4T1_CC_IRQHandler
  .thumb_set AD16C4T1_CC_IRQHandler,Default_Handler

  .weak      I2C0_EV_IRQHandler
  .thumb_set I2C0_EV_IRQHandler,Default_Handler

  .weak      I2C0_ERR_IRQHandler
  .thumb_set I2C0_ERR_IRQHandler,Default_Handler

  .weak      I2C1_EV_IRQHandler
  .thumb_set I2C1_EV_IRQHandler,Default_Handler

  .weak      I2C1_ERR_IRQHandler
  .thumb_set I2C1_ERR_IRQHandler,Default_Handler

  .weak      SPI0_I2S0_IRQHandler
  .thumb_set SPI0_I2S0_IRQHandler,Default_Handler

  .weak      SPI1_I2S1_IRQHandler
  .thumb_set SPI1_I2S1_IRQHandler,Default_Handler

  .weak      UART0_IRQHandler
  .thumb_set UART0_IRQHandler,Default_Handler

  .weak      UART1_IRQHandler
  .thumb_set UART1_IRQHandler,Default_Handler

  .weak      UART2_IRQHandler
  .thumb_set UART2_IRQHandler,Default_Handler

  .weak      PDM2PCM_IRQHandler
  .thumb_set PDM2PCM_IRQHandler,Default_Handler

  .weak      TK_IRQHandler
  .thumb_set TK_IRQHandler,Default_Handler

  .weak      KSCAN_IRQHandler
  .thumb_set KSCAN_IRQHandler,Default_Handler

  .weak      QSPI_IRQHandler
  .thumb_set QSPI_IRQHandler,Default_Handler

  .weak      CRYPT_IRQHandler
  .thumb_set CRYPT_IRQHandler,Default_Handler

  .weak      ADPCM_IRQHandler
  .thumb_set ADPCM_IRQHandler,Default_Handler

  .weak      HASH_IRQHandler
  .thumb_set HASH_IRQHandler,Default_Handler

  .weak      ECC_IRQHandler
  .thumb_set ECC_IRQHandler,Default_Handler

  .weak      TRNG_IRQHandler
  .thumb_set TRNG_IRQHandler,Default_Handler

  .weak      EXTI0_IRQHandler
  .thumb_set EXTI0_IRQHandler,Default_Handler

  .weak      EXTI1_IRQHandler
  .thumb_set EXTI1_IRQHandler,Default_Handler

  .weak      EXTI2_IRQHandler
  .thumb_set EXTI2_IRQHandler,Default_Handler

  .weak      EXTI3_IRQHandler
  .thumb_set EXTI3_IRQHandler,Default_Handler

  .weak      EXTI4_IRQHandler
  .thumb_set EXTI4_IRQHandler,Default_Handler

  .weak      EXTI5_IRQHandler
  .thumb_set EXTI5_IRQHandler,Default_Handler

  .weak      EXTI6_IRQHandler
  .thumb_set EXTI6_IRQHandler,Default_Handler

  .weak      EXTI7_IRQHandler
  .thumb_set EXTI7_IRQHandler,Default_Handler

  .weak      EXTI8_IRQHandler
  .thumb_set EXTI8_IRQHandler,Default_Handler

  .weak      EXTI9_IRQHandler
  .thumb_set EXTI9_IRQHandler,Default_Handler

  .weak      EXTI10_IRQHandler
  .thumb_set EXTI10_IRQHandler,Default_Handler

  .weak      EXTI11_IRQHandler
  .thumb_set EXTI11_IRQHandler,Default_Handler

  .weak      EXTI12_IRQHandler
  .thumb_set EXTI12_IRQHandler,Default_Handler

  .weak      EXTI13_IRQHandler
  .thumb_set EXTI13_IRQHandler,Default_Handler

  .weak      EXTI14_IRQHandler
  .thumb_set EXTI14_IRQHandler,Default_Handler

  .weak      EXTI15_IRQHandler
  .thumb_set EXTI15_IRQHandler,Default_Handler

  .weak      DMA_IRQHandler
  .thumb_set DMA_IRQHandler,Default_Handler

  .weak      BLE_ERROR_IRQHandler
  .thumb_set BLE_ERROR_IRQHandler,Default_Handler

  .weak      BLE_HSLOT_IRQHandler
  .thumb_set BLE_HSLOT_IRQHandler,Default_Handler

  .weak      BLE_RX_IRQHandler
  .thumb_set BLE_RX_IRQHandler,Default_Handler

  .weak      BLE_TX_IRQHandler
  .thumb_set BLE_TX_IRQHandler,Default_Handler

  .weak      BLE_START_IRQHandler
  .thumb_set BLE_START_IRQHandler,Default_Handler

  .weak      BLE_END_IRQHandler
  .thumb_set BLE_END_IRQHandler,Default_Handler

  .weak      BLE_SKIP_IRQHandler
  .thumb_set BLE_SKIP_IRQHandler,Default_Handler

  .weak      BLE_SLP_IRQHandler
  .thumb_set BLE_SLP_IRQHandler,Default_Handler

  .weak      BLE_CRYPT_IRQHandler
  .thumb_set BLE_CRYPT_IRQHandler,Default_Handler

  .weak      BLE_GROSSTGTIM_IRQHandler
  .thumb_set BLE_GROSSTGTIM_IRQHandler,Default_Handler

  .weak      BLE_FINETGTIM_IRQHandler
  .thumb_set BLE_FINETGTIM_IRQHandler,Default_Handler

  .weak      BLE_TIMESTAMP_TGT_IRQHandler
  .thumb_set BLE_TIMESTAMP_TGT_IRQHandler,Default_Handler

  .weak      BLE_SW_IRQHandler
  .thumb_set BLE_SW_IRQHandler,Default_Handler

  .weak      BLE_AUDIO0_IRQHandler
  .thumb_set BLE_AUDIO0_IRQHandler,Default_Handler

  .weak      BLE_AUDIO1_IRQHandler
  .thumb_set BLE_AUDIO1_IRQHandler,Default_Handler

  .weak      BLE_AUDIO2_IRQHandler
  .thumb_set BLE_AUDIO2_IRQHandler,Default_Handler

