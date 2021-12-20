/*
 * Copyright (C) 2018 Shanghai Eastsoft Microelectronics Co., Ltd.
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
 *         
 */

#include <rthw.h>
#include <rtthread.h>
#include <rtdevice.h>
#include "board.h"
#include "drv_adc.h" 

#ifdef RT_USING_ADC

/* define adc instance */

static struct rt_adc_device _device_adc0;

/* enable or disable adc */
static rt_err_t es32w_adc_enabled(struct rt_adc_device *device, rt_uint32_t channel, rt_bool_t enabled)
{
    adc_handle_t *_hadc = (adc_handle_t *)device->parent.user_data;

    RT_ASSERT(device != RT_NULL);

    if (enabled)
    {
        ADC_ENABLE(_hadc); ;
    }
    else
    {
        ADC_DISABLE(_hadc);
    }

    return RT_EOK;
}

static adc_channel_t es32w_adc_get_channel(rt_uint32_t channel)
{
    adc_channel_t es32w3_channel;
    gpio_init_t gpio_initstruct;

    /* Initialize ADC pin */
    gpio_initstruct.mode = GPIO_MODE_INPUT;
    gpio_initstruct.pupd = GPIO_FLOATING;
    gpio_initstruct.odrv = GPIO_OUT_DRIVE_NORMAL;
    gpio_initstruct.flt  = GPIO_FILTER_DISABLE;
    gpio_initstruct.type = GPIO_TYPE_CMOS;
    gpio_initstruct.func = GPIO_FUNC_0;

    /* select gpio pin as adc function */
    switch (channel)
    {
    case  0:
        es32w3_channel = ADC_CHANNEL_0;
        ald_gpio_init(ES_GPIO_ADC_CH0_GPIO, ES_GPIO_ADC_CH0_PIN, &gpio_initstruct);
        break;
    case  1:
        es32w3_channel = ADC_CHANNEL_1;
        ald_gpio_init(ES_GPIO_ADC_CH1_GPIO, ES_GPIO_ADC_CH1_PIN, &gpio_initstruct);
        break;
    case  2:
        es32w3_channel = ADC_CHANNEL_2;
        ald_gpio_init(ES_GPIO_ADC_CH2_GPIO, ES_GPIO_ADC_CH2_PIN, &gpio_initstruct);
        break;
    case  3:
        es32w3_channel = ADC_CHANNEL_3;
        ald_gpio_init(ES_GPIO_ADC_CH3_GPIO, ES_GPIO_ADC_CH3_PIN, &gpio_initstruct);
        break;
    case  4:
        es32w3_channel = ADC_CHANNEL_4;
        ald_gpio_init(ES_GPIO_ADC_CH4_GPIO, ES_GPIO_ADC_CH4_PIN, &gpio_initstruct);
        break;
    case  5:
        es32w3_channel = ADC_CHANNEL_5;
        ald_gpio_init(ES_GPIO_ADC_CH5_GPIO, ES_GPIO_ADC_CH5_PIN, &gpio_initstruct);
        break;
    case  6:
        es32w3_channel = ADC_CHANNEL_6;
        ald_gpio_init(ES_GPIO_ADC_CH6_GPIO, ES_GPIO_ADC_CH6_PIN, &gpio_initstruct);
        break;
    case  7:
        es32w3_channel = ADC_CHANNEL_7;
        ald_gpio_init(ES_GPIO_ADC_CH7_GPIO, ES_GPIO_ADC_CH7_PIN, &gpio_initstruct);
        break;
    default:
        break;
    }

    return es32w3_channel;
}

static rt_err_t es32w_get_adc_value(struct rt_adc_device *device, rt_uint32_t channel, rt_uint32_t *value)
{
    adc_handle_t *_hadc = (adc_handle_t *)device->parent.user_data;
    adc_nch_conf_t nm_config;

    RT_ASSERT(device != RT_NULL);
    RT_ASSERT(value != RT_NULL);

    /* config adc channel */
    nm_config.ch       = es32w_adc_get_channel(channel);
    nm_config.idx          = ADC_NCH_IDX_1;
    nm_config.samp = ES_ADC0_NCH_SAMPLETIME;//ADC_SAMPLETIME_4;
    ald_adc_normal_channel_config(_hadc, &nm_config);

    ald_adc_normal_start(_hadc);

    if (ald_adc_normal_poll_for_conversion(_hadc, 5000) == OK)
        *value = ald_adc_normal_get_value(_hadc);

    return RT_EOK;
}

static const struct rt_adc_ops es32w_adc_ops =
{
    es32w_adc_enabled,
    es32w_get_adc_value,
};

int rt_hw_adc_init(void)
{
    int result = RT_EOK;
    static adc_handle_t _h_adc0;

    /* adc function initialization */
    _h_adc0.init.scan     = DISABLE;
    _h_adc0.init.cont     = DISABLE;
    _h_adc0.init.disc     = ADC_ALL_DISABLE;
    _h_adc0.init.disc_nr  = ADC_DISC_NR_1;
    _h_adc0.init.nche_sel = ADC_NCHESEL_MODE_ALL;
    _h_adc0.init.n_ref    = ADC_NEG_REF_VSS;
    _h_adc0.init.p_ref    = ADC_POS_REF_VDD;
	
	
    _h_adc0.perh = ADC;
    _h_adc0.init.align    = ES_ADC0_ALIGN;//ADC_DATAALIGN_RIGHT;
    _h_adc0.init.div      = ES_ADC0_CLK_DIV;//ADC_CKDIV_128;
    ald_adc_init(&_h_adc0);

    rt_hw_adc_register(&_device_adc0, ES_DEVICE_NAME_ADC0, &es32w_adc_ops, &_h_adc0);

    return result;
}
INIT_BOARD_EXPORT(rt_hw_adc_init);

#endif
