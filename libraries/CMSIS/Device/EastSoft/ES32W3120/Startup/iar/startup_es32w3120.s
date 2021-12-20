;*******************************************************************************
; file       : startup_esw3120.s
; description: ESW3120 Device Startup File
; author     : Eastsoft MCU Software Team
; data       : 10 Nov 2020
; Copyright (C) Shanghai Eastsoft Microelectronics Co. Ltd. All rights reserved.
;*******************************************************************************

        MODULE  ?cstartup

        ;; Forward declaration of sections.
        SECTION CSTACK:DATA:NOROOT(3)
        SECTION .intvec:CODE:NOROOT(2)

        EXTERN  __iar_program_start
        PUBLIC  __vector_table

        DATA
__vector_table
                DCD     sfe(CSTACK)                    ; Top of Stack
                DCD     Reset_Handler                   ;1, Reset Handler
                DCD     NMI_Handler                     ;2, NMI Handler
                DCD     HardFault_Handler               ;3, HardFault Handler
                DCD     MemManage_Handler               ;4, MemManage Handler
                DCD     BusFault_Handler                ;5, BusFault Handler
                DCD     UsageFault_Handler              ;6, UsageFault Handler
                DCD     0                               ;7, Reserved
                DCD     0                               ;8, Reserved
                DCD     0                               ;9, Reserved
                DCD     0                               ;10, Reserved
                DCD     SVC_Handler                     ;11, SVCall Handler
                DCD     DebugMon_Handler                ;12, DebugMonitor Handler
                DCD     0                               ;13, Reserved
                DCD     PendSV_Handler                  ;14, PendSV Handler
                DCD     SysTick_Handler                 ;15, Systick Handler

                ; External Interrupts
                DCD     WWDG_IRQHandler                 ;16, WWDG IRQHandler
                DCD     IWDG_IRQHandler                 ;17, IWDG IRQHandler
                DCD     LVD_IRQHandler                  ;18, LVD IRQHandler
                DCD     RTC_WAKE_IRQHandler             ;19, RTC_WAKE IRQHandler
                DCD     RTC_ALARM_IRQHandler            ;20, RTC_ALARM IRQHandler
                DCD     0                               ;21, Reserved
                DCD     CMU_IRQHandler                  ;22, CMU IRQHandler
                DCD     ADC_IRQHandler                  ;23, ADC IRQHandler
                DCD     LP16T_IRQHandler                ;24, LP16T IRQHandler
                DCD     0                               ;25, Reserved
                DCD     BS16T0_IRQHandler               ;26, BS16T0 IRQHandler
                DCD     BS16T1_IRQHandler               ;27, BS16T1 IRQHandler
                DCD     GP16C4T0_IRQHandler             ;28, GP16C4T0 IRQHandler
                DCD     0                               ;29, Reserved
                DCD     0                               ;30, Reserved
                DCD     0                               ;31, Reserved
                DCD     GP16C4T1_IRQHandler             ;32, GP16C4T1 IRQHandler
                DCD     0                               ;33, Reserved
                DCD     0                               ;34, Reserved
                DCD     0                               ;35, Reserved
                DCD     AD16C4T0_BRK_IRQHandler         ;36, AD16C4T0_BRK IRQHandler
                DCD     AD16C4T0_UP_IRQHandler          ;37, AD16C4T0_UP IRQHandler
                DCD     AD16C4T0_TRIG_COM_IRQHandler    ;38, AD16C4T0_TRIG_COM IRQHandler
                DCD     AD16C4T0_CC_IRQHandler          ;39, AD16C4T0_CC IRQHandler
                DCD     AD16C4T1_BRK_IRQHandler         ;40, AD16C4T1_BRK IRQHandler
                DCD     AD16C4T1_UP_IRQHandler          ;41, AD16C4T1_UP IRQHandler
                DCD     AD16C4T1_TRIG_COM_IRQHandler    ;42, AD16C4T1_TRIG_COM IRQHandler
                DCD     AD16C4T1_CC_IRQHandler          ;43, AD16C4T1_CC IRQHandler
                DCD     I2C0_EV_IRQHandler              ;44, I2C0_EV IRQHandler
                DCD     I2C0_ERR_IRQHandler             ;45, I2C0_ERR IRQHandler
                DCD     I2C1_EV_IRQHandler              ;46, I2C1_EV IRQHandler
                DCD     I2C1_ERR_IRQHandler             ;47, I2C1_ERR IRQHandler
                DCD     SPI0_I2S0_IRQHandler            ;48, SPI0_I2S0 IRQHandler
                DCD     SPI1_I2S1_IRQHandler            ;49, SPI1_I2S1 IRQHandler
                DCD     UART0_IRQHandler                ;50, UART0 IRQHandler
                DCD     UART1_IRQHandler                ;51, UART1 IRQHandler
                DCD     UART2_IRQHandler                ;52, UART2 IRQHandler
                DCD     0                               ;53, Reserved
                DCD     PDM2PCM_IRQHandler              ;54, PDM2PCM IRQHandler
                DCD     TK_IRQHandler                   ;55, TK IRQHandler
                DCD     KSCAN_IRQHandler                ;56, KSCAN IRQHandler
                DCD     QSPI_IRQHandler                 ;57, QSPI IRQHandler
                DCD     CRYPT_IRQHandler                ;58, CRYPT IRQHandler
                DCD     ADPCM_IRQHandler                ;59, ADPCM IRQHandler
                DCD     0                               ;60, Reserved
                DCD     HASH_IRQHandler                 ;61, HASH IRQHandler
                DCD     0                               ;62, Reserved
                DCD     ECC_IRQHandler                  ;63, ECC IRQHandler
                DCD     TRNG_IRQHandler                 ;64, TRNG IRQHandler
                DCD     0                               ;65, Reserved
                DCD     EXTI0_IRQHandler                ;66, EXTI0 IRQHandler
                DCD     EXTI1_IRQHandler                ;67, EXTI1 IRQHandler
                DCD     EXTI2_IRQHandler                ;68, EXTI2 IRQHandler
                DCD     EXTI3_IRQHandler                ;69, EXTI3 IRQHandler
                DCD     EXTI4_IRQHandler                ;70, EXTI4 IRQHandler
                DCD     EXTI5_IRQHandler                ;71, EXTI5 IRQHandler
                DCD     EXTI6_IRQHandler                ;72, EXTI6 IRQHandler
                DCD     EXTI7_IRQHandler                ;73, EXTI7 IRQHandler
                DCD     EXTI8_IRQHandler                ;74, EXTI8 IRQHandler
                DCD     EXTI9_IRQHandler                ;75, EXTI9 IRQHandler
                DCD     EXTI10_IRQHandler               ;76, EXTI10 IRQHandler
                DCD     EXTI11_IRQHandler               ;77, EXTI11 IRQHandler
                DCD     EXTI12_IRQHandler               ;78, EXTI12 IRQHandler
                DCD     EXTI13_IRQHandler               ;79, EXTI13 IRQHandler
                DCD     EXTI14_IRQHandler               ;80, EXTI14 IRQHandler
                DCD     EXTI15_IRQHandler               ;81, EXTI15 IRQHandler
                DCD     DMA_IRQHandler                  ;82, DMA IRQHandler
                DCD     0                               ;83, Reserved
                DCD     0                               ;84, Reserved
                DCD     0                               ;85, Reserved
                DCD     0                               ;86, Reserved
                DCD     0                               ;87, Reserved
                DCD     0                               ;88, Reserved
                DCD     0                               ;89, Reserved
                DCD     0                               ;90, Reserved
                DCD     0                               ;91, Reserved
                DCD     0                               ;92, Reserved
                DCD     0                               ;93, Reserved
                DCD     0                               ;94, Reserved
                DCD     0                               ;95, Reserved
                DCD     BLE_ERROR_IRQHandler            ;96, BLE_ERROR IRQHandler
                DCD     BLE_HSLOT_IRQHandler            ;97, BLE_HSLOT IRQHandler
                DCD     BLE_RX_IRQHandler               ;98, BLE_RX IRQHandler
                DCD     BLE_TX_IRQHandler               ;99, BLE_TX IRQHandler
                DCD     BLE_START_IRQHandler            ;100, BLE_START IRQHandler
                DCD     BLE_END_IRQHandler              ;101, BLE_END IRQHandler
                DCD     BLE_SKIP_IRQHandler             ;102, BLE_SKIP IRQHandler
                DCD     BLE_SLP_IRQHandler              ;103, BLE_SLP IRQHandler
                DCD     BLE_CRYPT_IRQHandler            ;104, BLE_CRYPT IRQHandler
                DCD     BLE_GROSSTGTIM_IRQHandler       ;105, BLE_GROSSTGTIM IRQHandler
                DCD     BLE_FINETGTIM_IRQHandler        ;106, BLE_FINETGTIM IRQHandler
                DCD     BLE_TIMESTAMP_TGT_IRQHandler    ;107, BLE_TIMESTAMP_TGT IRQHandler
                DCD     BLE_SW_IRQHandler               ;108, BLE_SW IRQHandler
                DCD     BLE_AUDIO0_IRQHandler           ;109, BLE_AUDIO0 IRQHandler
                DCD     BLE_AUDIO1_IRQHandler           ;110, BLE_AUDIO1 IRQHandler
                DCD     BLE_AUDIO2_IRQHandler           ;111, BLE_AUDIO2 IRQHandler
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Default interrupt handlers.
;;
        THUMB

        PUBWEAK Reset_Handler
        SECTION .text:CODE:NOROOT:REORDER(2)
Reset_Handler   
        LDR     R0, =__iar_program_start
        BX      R0
        
        PUBWEAK NMI_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
NMI_Handler             
        B NMI_Handler

        PUBWEAK HardFault_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)        
HardFault_Handler    
        B HardFault_Handler
        
        PUBWEAK MemManage_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)                        
MemManage_Handler  
        B MemManage_Handler
        
        PUBWEAK BusFault_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)                        
BusFault_Handler    
        B BusFault_Handler
        
        PUBWEAK UsageFault_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)                        
UsageFault_Handler     
        B UsageFault_Handler
        
        PUBWEAK SVC_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)                        
SVC_Handler  
        B SVC_Handler
        
        PUBWEAK DebugMon_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)           
DebugMon_Handler        
        B DebugMon_Handler
        
        PUBWEAK PendSV_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
PendSV_Handler          
        B PendSV_Handler
        
        PUBWEAK SysTick_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
SysTick_Handler         
        B SysTick_Handler
        
        PUBWEAK Default_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
Default_Handler 
        B Default_Handler
        
        PUBWEAK WWDG_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
WWDG_IRQHandler
        B WWDG_IRQHandler

        PUBWEAK IWDG_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
IWDG_IRQHandler
        B IWDG_IRQHandler

        PUBWEAK LVD_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
LVD_IRQHandler
        B LVD_IRQHandler

        PUBWEAK RTC_WAKE_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
RTC_WAKE_IRQHandler
        B RTC_WAKE_IRQHandler

        PUBWEAK RTC_ALARM_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
RTC_ALARM_IRQHandler
        B RTC_ALARM_IRQHandler

        PUBWEAK CMU_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
CMU_IRQHandler
        B CMU_IRQHandler

        PUBWEAK ADC_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
ADC_IRQHandler
        B ADC_IRQHandler

        PUBWEAK LP16T_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
LP16T_IRQHandler
        B LP16T_IRQHandler

        PUBWEAK BS16T0_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
BS16T0_IRQHandler
        B BS16T0_IRQHandler

        PUBWEAK BS16T1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
BS16T1_IRQHandler
        B BS16T1_IRQHandler

        PUBWEAK GP16C4T0_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
GP16C4T0_IRQHandler
        B GP16C4T0_IRQHandler

        PUBWEAK GP16C4T1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
GP16C4T1_IRQHandler
        B GP16C4T1_IRQHandler

        PUBWEAK AD16C4T0_BRK_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
AD16C4T0_BRK_IRQHandler
        B AD16C4T0_BRK_IRQHandler

        PUBWEAK AD16C4T0_UP_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
AD16C4T0_UP_IRQHandler
        B AD16C4T0_UP_IRQHandler

        PUBWEAK AD16C4T0_TRIG_COM_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
AD16C4T0_TRIG_COM_IRQHandler
        B AD16C4T0_TRIG_COM_IRQHandler

        PUBWEAK AD16C4T0_CC_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
AD16C4T0_CC_IRQHandler
        B AD16C4T0_CC_IRQHandler

        PUBWEAK AD16C4T1_BRK_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
AD16C4T1_BRK_IRQHandler
        B AD16C4T1_BRK_IRQHandler

        PUBWEAK AD16C4T1_UP_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
AD16C4T1_UP_IRQHandler
        B AD16C4T1_UP_IRQHandler

        PUBWEAK AD16C4T1_TRIG_COM_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
AD16C4T1_TRIG_COM_IRQHandler
        B AD16C4T1_TRIG_COM_IRQHandler

        PUBWEAK AD16C4T1_CC_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
AD16C4T1_CC_IRQHandler
        B AD16C4T1_CC_IRQHandler

        PUBWEAK I2C0_EV_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
I2C0_EV_IRQHandler
        B I2C0_EV_IRQHandler

        PUBWEAK I2C0_ERR_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
I2C0_ERR_IRQHandler
        B I2C0_ERR_IRQHandler

        PUBWEAK I2C1_EV_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
I2C1_EV_IRQHandler
        B I2C1_EV_IRQHandler

        PUBWEAK I2C1_ERR_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
I2C1_ERR_IRQHandler
        B I2C1_ERR_IRQHandler

        PUBWEAK SPI0_I2S0_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
SPI0_I2S0_IRQHandler
        B SPI0_I2S0_IRQHandler

        PUBWEAK SPI1_I2S1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
SPI1_I2S1_IRQHandler
        B SPI1_I2S1_IRQHandler

        PUBWEAK UART0_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
UART0_IRQHandler
        B UART0_IRQHandler

        PUBWEAK UART1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
UART1_IRQHandler
        B UART1_IRQHandler

        PUBWEAK UART2_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
UART2_IRQHandler
        B UART2_IRQHandler

        PUBWEAK PDM2PCM_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
PDM2PCM_IRQHandler
        B PDM2PCM_IRQHandler

        PUBWEAK TK_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TK_IRQHandler
        B TK_IRQHandler

        PUBWEAK KSCAN_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
KSCAN_IRQHandler
        B KSCAN_IRQHandler

        PUBWEAK QSPI_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
QSPI_IRQHandler
        B QSPI_IRQHandler

        PUBWEAK CRYPT_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
CRYPT_IRQHandler
        B CRYPT_IRQHandler

        PUBWEAK ADPCM_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
ADPCM_IRQHandler
        B ADPCM_IRQHandler

        PUBWEAK HASH_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
HASH_IRQHandler
        B HASH_IRQHandler

        PUBWEAK ECC_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
ECC_IRQHandler
        B ECC_IRQHandler

        PUBWEAK TRNG_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TRNG_IRQHandler
        B TRNG_IRQHandler

        PUBWEAK EXTI0_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTI0_IRQHandler
        B EXTI0_IRQHandler

        PUBWEAK EXTI1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTI1_IRQHandler
        B EXTI1_IRQHandler

        PUBWEAK EXTI2_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTI2_IRQHandler
        B EXTI2_IRQHandler

        PUBWEAK EXTI3_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTI3_IRQHandler
        B EXTI3_IRQHandler

        PUBWEAK EXTI4_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTI4_IRQHandler
        B EXTI4_IRQHandler

        PUBWEAK EXTI5_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTI5_IRQHandler
        B EXTI5_IRQHandler

        PUBWEAK EXTI6_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTI6_IRQHandler
        B EXTI6_IRQHandler

        PUBWEAK EXTI7_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTI7_IRQHandler
        B EXTI7_IRQHandler

        PUBWEAK EXTI8_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTI8_IRQHandler
        B EXTI8_IRQHandler

        PUBWEAK EXTI9_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTI9_IRQHandler
        B EXTI9_IRQHandler

        PUBWEAK EXTI10_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTI10_IRQHandler
        B EXTI10_IRQHandler

        PUBWEAK EXTI11_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTI11_IRQHandler
        B EXTI11_IRQHandler

        PUBWEAK EXTI12_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTI12_IRQHandler
        B EXTI12_IRQHandler

        PUBWEAK EXTI13_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTI13_IRQHandler
        B EXTI13_IRQHandler

        PUBWEAK EXTI14_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTI14_IRQHandler
        B EXTI14_IRQHandler

        PUBWEAK EXTI15_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTI15_IRQHandler
        B EXTI15_IRQHandler

        PUBWEAK DMA_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
DMA_IRQHandler
        B DMA_IRQHandler

        PUBWEAK BLE_ERROR_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
BLE_ERROR_IRQHandler
        B BLE_ERROR_IRQHandler

        PUBWEAK BLE_HSLOT_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
BLE_HSLOT_IRQHandler
        B BLE_HSLOT_IRQHandler

        PUBWEAK BLE_RX_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
BLE_RX_IRQHandler
        B BLE_RX_IRQHandler

        PUBWEAK BLE_TX_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
BLE_TX_IRQHandler
        B BLE_TX_IRQHandler

        PUBWEAK BLE_START_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
BLE_START_IRQHandler
        B BLE_START_IRQHandler

        PUBWEAK BLE_END_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
BLE_END_IRQHandler
        B BLE_END_IRQHandler

        PUBWEAK BLE_SKIP_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
BLE_SKIP_IRQHandler
        B BLE_SKIP_IRQHandler

        PUBWEAK BLE_SLP_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
BLE_SLP_IRQHandler
        B BLE_SLP_IRQHandler

        PUBWEAK BLE_CRYPT_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
BLE_CRYPT_IRQHandler
        B BLE_CRYPT_IRQHandler

        PUBWEAK BLE_GROSSTGTIM_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
BLE_GROSSTGTIM_IRQHandler
        B BLE_GROSSTGTIM_IRQHandler

        PUBWEAK BLE_FINETGTIM_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
BLE_FINETGTIM_IRQHandler
        B BLE_FINETGTIM_IRQHandler

        PUBWEAK BLE_TIMESTAMP_TGT_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
BLE_TIMESTAMP_TGT_IRQHandler
        B BLE_TIMESTAMP_TGT_IRQHandler

        PUBWEAK BLE_SW_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
BLE_SW_IRQHandler
        B BLE_SW_IRQHandler

        PUBWEAK BLE_AUDIO0_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
BLE_AUDIO0_IRQHandler
        B BLE_AUDIO0_IRQHandler

        PUBWEAK BLE_AUDIO1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
BLE_AUDIO1_IRQHandler
        B BLE_AUDIO1_IRQHandler

        PUBWEAK BLE_AUDIO2_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
BLE_AUDIO2_IRQHandler        
        B BLE_AUDIO2_IRQHandler

        END
