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

#include "drv_common.h"
#include "board.h"
#include "drv_uart.h"
#include <ald_cmu.h>
#include "es_conf_info_cmu.h"

#ifdef RT_USING_FINSH
#include <finsh.h>
#endif /* RT_USING_FINSH */

/*******************************************************************************
* Function Name  : NVIC_Configuration
* Description    : Configures Vector Table base location.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void NVIC_Configuration(void)
{
}

/*******************************************************************************
 * Function Name  : SystemClock_Configuration
 * Description    : Configures the System Clock.
 * Input          : None
 * Output         : None
 * Return         : None
 *******************************************************************************/
void  SystemClock_Config(char* clock_src,int32_t clock_src_freq,int32_t clock_target_freq )
{   

    ald_cmu_init();
     /* Configure system clock */
    ald_cmu_pll1_config(32);
    ald_cmu_clock_config(CMU_CLOCK_PLL1, 48000000);
    ald_cmu_perh_clock_config(CMU_PERH_ALL, ENABLE);

}

/*******************************************************************************
 * Function Name  : SysTick_Configuration
 * Description    : Configures the SysTick for OS tick.
 * Input          : None
 * Output         : None
 * Return         : None
 *******************************************************************************/
void  SysTick_Configuration(void)
{
    /* ticks = sysclk / RT_TICK_PER_SECOND */
    SysTick_Config(ald_cmu_get_sys_clock() / RT_TICK_PER_SECOND);
}

/**
 * This is the timer interrupt service routine.
 *
 */
void SysTick_Handler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    ald_inc_tick();
    rt_tick_increase();
    /* leave interrupt */
    rt_interrupt_leave();
}

/**
 * This is the cmu interrupt service.
 *
 */
void CMU_IRQHandler(void)
{
    ald_cmu_irq_handler();
}
/*@}*/
/**
 * This function will initial ES32F3 board.
 */
void hw_board_init(char *clock_src, int32_t clock_src_freq, int32_t clock_target_freq)
{
    /* NVIC Configuration */
    NVIC_Configuration();
    /*System Clock Configuration */
    SystemClock_Config(clock_src,clock_src_freq,clock_target_freq*1000000);
    /* Configure the SysTick */
    SysTick_Configuration();

#ifdef RT_USING_CONSOLE
    extern int rt_hw_uart_init(void);
    rt_hw_uart_init();
#endif
}

/**
 * This function will delay for some us.
 *
 * @param us the delay time of us
 */
void rt_hw_us_delay(rt_uint32_t us)
{
    unsigned int start, now, delta, reload, us_tick;
    start = SysTick->VAL;
    reload = SysTick->LOAD;
    us_tick = ald_cmu_get_sys_clock() / 1000000UL;
    do
    {
        now = SysTick->VAL;
        delta = start > now ? start - now : reload + start - now;
    }
    while (delta <  us_tick * us);
}
