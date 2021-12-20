/*
 *  Change Logs:
 *  Date            Author          Notes
 *  2021-04-20      liuhy          the first version
 *
 * Copyright (C) 2021 Shanghai Eastsoft Microelectronics Co., Ltd. All rights reserved.
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
 */

#ifndef __es_conf_info_map_H__
#define __es_conf_info_map_H__

#include <ald_gpio.h>

 

#define __ES_PIN(index, gpio, gpio_index) {index, GPIO##gpio, GPIO_PIN_##gpio_index}
#define __ES_PIN_DEFAULT {-1, 0, 0}

struct pin_index
{
    int index;
    GPIO_TypeDef *gpio;
    uint32_t pin;
};


#define   ES_GPIO_ADC_CH0_GPIO     GPIOA
#define   ES_GPIO_ADC_CH0_PIN      GPIO_PIN_2
#define   ES_GPIO_ADC_CH1_GPIO     GPIOA
#define   ES_GPIO_ADC_CH1_PIN      GPIO_PIN_3
#define   ES_GPIO_ADC_CH2_GPIO     GPIOA
#define   ES_GPIO_ADC_CH2_PIN      GPIO_PIN_4
#define   ES_GPIO_ADC_CH3_GPIO     GPIOA
#define   ES_GPIO_ADC_CH3_PIN      GPIO_PIN_5
#define   ES_GPIO_ADC_CH6_GPIO     GPIOA
#define   ES_GPIO_ADC_CH6_PIN      GPIO_PIN_8
#define   ES_GPIO_ADC_CH5_GPIO     GPIOA
#define   ES_GPIO_ADC_CH5_PIN      GPIO_PIN_7
#define   ES_GPIO_ADC_CH4_GPIO     GPIOA
#define   ES_GPIO_ADC_CH4_PIN      GPIO_PIN_6
#define   ES_GPIO_ADC_CH7_GPIO     GPIOA
#define   ES_GPIO_ADC_CH7_PIN      GPIO_PIN_11
#define   ES_GPIO_ADC_CHP_GPIO     GPIOB
#define   ES_GPIO_ADC_CHP_PIN      GPIO_PIN_2
#define   ES_GPIO_ADC_CHN_GPIO     GPIOB
#define   ES_GPIO_ADC_CHN_PIN      GPIO_PIN_3



static const struct pin_index pins[] =
{
    __ES_PIN_DEFAULT,
    __ES_PIN_DEFAULT,
    __ES_PIN_DEFAULT,
    __ES_PIN_DEFAULT,
    __ES_PIN_DEFAULT,
    __ES_PIN_DEFAULT,
    __ES_PIN_DEFAULT,
    __ES_PIN_DEFAULT,
    __ES_PIN(8,A,2),
    __ES_PIN(9,A,3),
    __ES_PIN(10,A,4),
    __ES_PIN(11,A,5),
    __ES_PIN(12,A,9),
    __ES_PIN(13,B,0),
    __ES_PIN(14,B,1),
    __ES_PIN(15,A,8),
    __ES_PIN(16,A,7),
    __ES_PIN(17,A,6),
    __ES_PIN_DEFAULT,
    __ES_PIN(19,A,11),
    __ES_PIN(20,A,10),
    __ES_PIN(21,A,0),
    __ES_PIN(22,A,1),
    __ES_PIN(23,B,2),
    __ES_PIN(24,B,3),
    __ES_PIN(25,B,4),
    __ES_PIN(26,B,5),
    __ES_PIN(27,B,6),
    __ES_PIN(28,B,7),
    __ES_PIN(29,B,8),
    __ES_PIN(30,B,9),
    __ES_PIN(31,A,13),
    __ES_PIN(32,A,14),
    __ES_PIN(33,A,15),
    __ES_PIN(34,A,12),
    __ES_PIN_DEFAULT,
    __ES_PIN(36,B,10),
    __ES_PIN(37,B,11),
    __ES_PIN(38,B,12),
    __ES_PIN(39,B,13),
    __ES_PIN(40,B,14),
    __ES_PIN(41,B,15),
    __ES_PIN_DEFAULT,
    __ES_PIN_DEFAULT,
    __ES_PIN_DEFAULT,
    __ES_PIN_DEFAULT,
    __ES_PIN_DEFAULT,
    __ES_PIN_DEFAULT,
    __ES_PIN_DEFAULT,
};

#define   ES_PIN_GPIO_A_2   8
#define   ES_PIN_GPIO_A_3   9
#define   ES_PIN_GPIO_A_4   10
#define   ES_PIN_GPIO_A_5   11
#define   ES_PIN_GPIO_A_9   12
#define   ES_PIN_GPIO_B_0   13
#define   ES_PIN_GPIO_B_1   14
#define   ES_PIN_GPIO_A_8   15
#define   ES_PIN_GPIO_A_7   16
#define   ES_PIN_GPIO_A_6   17
#define   ES_PIN_GPIO_A_11   19
#define   ES_PIN_GPIO_A_10   20
#define   ES_PIN_GPIO_A_0   21
#define   ES_PIN_GPIO_A_1   22
#define   ES_PIN_GPIO_B_2   23
#define   ES_PIN_GPIO_B_3   24
#define   ES_PIN_GPIO_B_4   25
#define   ES_PIN_GPIO_B_5   26
#define   ES_PIN_GPIO_B_6   27
#define   ES_PIN_GPIO_B_7   28
#define   ES_PIN_GPIO_B_8   29
#define   ES_PIN_GPIO_B_9   30
#define   ES_PIN_GPIO_A_13   31
#define   ES_PIN_GPIO_A_14   32
#define   ES_PIN_GPIO_A_15   33
#define   ES_PIN_GPIO_A_12   34
#define   ES_PIN_GPIO_B_10   36
#define   ES_PIN_GPIO_B_11   37
#define   ES_PIN_GPIO_B_12   38
#define   ES_PIN_GPIO_B_13   39
#define   ES_PIN_GPIO_B_14   40
#define   ES_PIN_GPIO_B_15   41

/* UART_TX */


#ifndef ES_UART0_TX_GPIO_FUNC 
#define ES_UART0_TX_GPIO_FUNC GPIO_FUNC_2 
#endif 
#ifndef ES_UART0_TX_GPIO_PORT 
#define ES_UART0_TX_GPIO_PORT GPIOA 
#endif 
#ifndef ES_UART0_TX_GPIO_PIN 
#define ES_UART0_TX_GPIO_PIN GPIO_PIN_2 
#endif 

#ifndef ES_UART0_TX_PIN 
#ifdef ES_PIN_GPIO_A_2 
#define ES_UART0_TX_PIN ES_PIN_GPIO_A_2 
#endif
#endif 

#ifndef ES_UART0_TX_GPIO_FUNC 
#define ES_UART0_TX_GPIO_FUNC GPIO_FUNC_5 
#endif 
#ifndef ES_UART0_TX_GPIO_PORT 
#define ES_UART0_TX_GPIO_PORT GPIOB 
#endif 
#ifndef ES_UART0_TX_GPIO_PIN 
#define ES_UART0_TX_GPIO_PIN GPIO_PIN_11 
#endif 

#ifndef ES_UART0_TX_PIN 
#ifdef ES_PIN_GPIO_B_11 
#define ES_UART0_TX_PIN ES_PIN_GPIO_B_11 
#endif
#endif 

#ifndef ES_UART0_TX_GPIO_FUNC 
#define ES_UART0_TX_GPIO_FUNC GPIO_FUNC_5 
#endif 
#ifndef ES_UART0_TX_GPIO_PORT 
#define ES_UART0_TX_GPIO_PORT GPIOA 
#endif 
#ifndef ES_UART0_TX_GPIO_PIN 
#define ES_UART0_TX_GPIO_PIN GPIO_PIN_1 
#endif 

#ifndef ES_UART0_TX_PIN 
#ifdef ES_PIN_GPIO_A_1 
#define ES_UART0_TX_PIN ES_PIN_GPIO_A_1 
#endif
#endif 

#ifndef ES_UART1_TX_GPIO_FUNC 
#define ES_UART1_TX_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_UART1_TX_GPIO_PORT 
#define ES_UART1_TX_GPIO_PORT GPIOA 
#endif 
#ifndef ES_UART1_TX_GPIO_PIN 
#define ES_UART1_TX_GPIO_PIN GPIO_PIN_11 
#endif 

#ifndef ES_UART1_TX_PIN 
#ifdef ES_PIN_GPIO_A_11 
#define ES_UART1_TX_PIN ES_PIN_GPIO_A_11 
#endif
#endif 

#ifndef ES_UART2_TX_GPIO_FUNC 
#define ES_UART2_TX_GPIO_FUNC GPIO_FUNC_4 
#endif 
#ifndef ES_UART2_TX_GPIO_PORT 
#define ES_UART2_TX_GPIO_PORT GPIOB 
#endif 
#ifndef ES_UART2_TX_GPIO_PIN 
#define ES_UART2_TX_GPIO_PIN GPIO_PIN_3 
#endif 

#ifndef ES_UART2_TX_PIN 
#ifdef ES_PIN_GPIO_B_3 
#define ES_UART2_TX_PIN ES_PIN_GPIO_B_3 
#endif
#endif 


/* UART_RX */


#ifndef ES_UART0_RX_GPIO_FUNC 
#define ES_UART0_RX_GPIO_FUNC GPIO_FUNC_2 
#endif 
#ifndef ES_UART0_RX_GPIO_PORT 
#define ES_UART0_RX_GPIO_PORT GPIOA 
#endif 
#ifndef ES_UART0_RX_GPIO_PIN 
#define ES_UART0_RX_GPIO_PIN GPIO_PIN_3 
#endif 

#ifndef ES_UART0_RX_PIN 
#ifdef ES_PIN_GPIO_A_3 
#define ES_UART0_RX_PIN ES_PIN_GPIO_A_3 
#endif
#endif 

#ifndef ES_UART0_RX_GPIO_FUNC 
#define ES_UART0_RX_GPIO_FUNC GPIO_FUNC_5 
#endif 
#ifndef ES_UART0_RX_GPIO_PORT 
#define ES_UART0_RX_GPIO_PORT GPIOB 
#endif 
#ifndef ES_UART0_RX_GPIO_PIN 
#define ES_UART0_RX_GPIO_PIN GPIO_PIN_12 
#endif 

#ifndef ES_UART0_RX_PIN 
#ifdef ES_PIN_GPIO_B_12 
#define ES_UART0_RX_PIN ES_PIN_GPIO_B_12 
#endif
#endif 

#ifndef ES_UART0_RX_GPIO_FUNC 
#define ES_UART0_RX_GPIO_FUNC GPIO_FUNC_5 
#endif 
#ifndef ES_UART0_RX_GPIO_PORT 
#define ES_UART0_RX_GPIO_PORT GPIOA 
#endif 
#ifndef ES_UART0_RX_GPIO_PIN 
#define ES_UART0_RX_GPIO_PIN GPIO_PIN_0 
#endif 

#ifndef ES_UART0_RX_PIN 
#ifdef ES_PIN_GPIO_A_0 
#define ES_UART0_RX_PIN ES_PIN_GPIO_A_0 
#endif
#endif 

#ifndef ES_UART1_RX_GPIO_FUNC 
#define ES_UART1_RX_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_UART1_RX_GPIO_PORT 
#define ES_UART1_RX_GPIO_PORT GPIOA 
#endif 
#ifndef ES_UART1_RX_GPIO_PIN 
#define ES_UART1_RX_GPIO_PIN GPIO_PIN_12 
#endif 

#ifndef ES_UART1_RX_PIN 
#ifdef ES_PIN_GPIO_A_12 
#define ES_UART1_RX_PIN ES_PIN_GPIO_A_12 
#endif
#endif 

#ifndef ES_UART2_RX_GPIO_FUNC 
#define ES_UART2_RX_GPIO_FUNC GPIO_FUNC_4 
#endif 
#ifndef ES_UART2_RX_GPIO_PORT 
#define ES_UART2_RX_GPIO_PORT GPIOB 
#endif 
#ifndef ES_UART2_RX_GPIO_PIN 
#define ES_UART2_RX_GPIO_PIN GPIO_PIN_4 
#endif 

#ifndef ES_UART2_RX_PIN 
#ifdef ES_PIN_GPIO_B_4 
#define ES_UART2_RX_PIN ES_PIN_GPIO_B_4 
#endif
#endif 


/* UART_RTS */


#ifndef ES_UART0_RTS_GPIO_FUNC 
#define ES_UART0_RTS_GPIO_FUNC GPIO_FUNC_2 
#endif 
#ifndef ES_UART0_RTS_GPIO_PORT 
#define ES_UART0_RTS_GPIO_PORT GPIOA 
#endif 
#ifndef ES_UART0_RTS_GPIO_PIN 
#define ES_UART0_RTS_GPIO_PIN GPIO_PIN_5 
#endif 

#ifndef ES_UART0_RTS_PIN 
#ifdef ES_PIN_GPIO_A_5 
#define ES_UART0_RTS_PIN ES_PIN_GPIO_A_5 
#endif
#endif 

#ifndef ES_UART0_RTS_GPIO_FUNC 
#define ES_UART0_RTS_GPIO_FUNC GPIO_FUNC_5 
#endif 
#ifndef ES_UART0_RTS_GPIO_PORT 
#define ES_UART0_RTS_GPIO_PORT GPIOB 
#endif 
#ifndef ES_UART0_RTS_GPIO_PIN 
#define ES_UART0_RTS_GPIO_PIN GPIO_PIN_14 
#endif 

#ifndef ES_UART0_RTS_PIN 
#ifdef ES_PIN_GPIO_B_14 
#define ES_UART0_RTS_PIN ES_PIN_GPIO_B_14 
#endif
#endif 

#ifndef ES_UART1_RTS_GPIO_FUNC 
#define ES_UART1_RTS_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_UART1_RTS_GPIO_PORT 
#define ES_UART1_RTS_GPIO_PORT GPIOA 
#endif 
#ifndef ES_UART1_RTS_GPIO_PIN 
#define ES_UART1_RTS_GPIO_PIN GPIO_PIN_14 
#endif 

#ifndef ES_UART1_RTS_PIN 
#ifdef ES_PIN_GPIO_A_14 
#define ES_UART1_RTS_PIN ES_PIN_GPIO_A_14 
#endif
#endif 

#ifndef ES_UART2_RTS_GPIO_FUNC 
#define ES_UART2_RTS_GPIO_FUNC GPIO_FUNC_4 
#endif 
#ifndef ES_UART2_RTS_GPIO_PORT 
#define ES_UART2_RTS_GPIO_PORT GPIOB 
#endif 
#ifndef ES_UART2_RTS_GPIO_PIN 
#define ES_UART2_RTS_GPIO_PIN GPIO_PIN_6 
#endif 

#ifndef ES_UART2_RTS_PIN 
#ifdef ES_PIN_GPIO_B_6 
#define ES_UART2_RTS_PIN ES_PIN_GPIO_B_6 
#endif
#endif 


/* UART_CTS */


#ifndef ES_UART0_CTS_GPIO_FUNC 
#define ES_UART0_CTS_GPIO_FUNC GPIO_FUNC_2 
#endif 
#ifndef ES_UART0_CTS_GPIO_PORT 
#define ES_UART0_CTS_GPIO_PORT GPIOA 
#endif 
#ifndef ES_UART0_CTS_GPIO_PIN 
#define ES_UART0_CTS_GPIO_PIN GPIO_PIN_4 
#endif 

#ifndef ES_UART0_CTS_PIN 
#ifdef ES_PIN_GPIO_A_4 
#define ES_UART0_CTS_PIN ES_PIN_GPIO_A_4 
#endif
#endif 

#ifndef ES_UART0_CTS_GPIO_FUNC 
#define ES_UART0_CTS_GPIO_FUNC GPIO_FUNC_5 
#endif 
#ifndef ES_UART0_CTS_GPIO_PORT 
#define ES_UART0_CTS_GPIO_PORT GPIOB 
#endif 
#ifndef ES_UART0_CTS_GPIO_PIN 
#define ES_UART0_CTS_GPIO_PIN GPIO_PIN_13 
#endif 

#ifndef ES_UART0_CTS_PIN 
#ifdef ES_PIN_GPIO_B_13 
#define ES_UART0_CTS_PIN ES_PIN_GPIO_B_13 
#endif
#endif 

#ifndef ES_UART1_CTS_GPIO_FUNC 
#define ES_UART1_CTS_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_UART1_CTS_GPIO_PORT 
#define ES_UART1_CTS_GPIO_PORT GPIOA 
#endif 
#ifndef ES_UART1_CTS_GPIO_PIN 
#define ES_UART1_CTS_GPIO_PIN GPIO_PIN_13 
#endif 

#ifndef ES_UART1_CTS_PIN 
#ifdef ES_PIN_GPIO_A_13 
#define ES_UART1_CTS_PIN ES_PIN_GPIO_A_13 
#endif
#endif 

#ifndef ES_UART2_CTS_GPIO_FUNC 
#define ES_UART2_CTS_GPIO_FUNC GPIO_FUNC_4 
#endif 
#ifndef ES_UART2_CTS_GPIO_PORT 
#define ES_UART2_CTS_GPIO_PORT GPIOB 
#endif 
#ifndef ES_UART2_CTS_GPIO_PIN 
#define ES_UART2_CTS_GPIO_PIN GPIO_PIN_5 
#endif 

#ifndef ES_UART2_CTS_PIN 
#ifdef ES_PIN_GPIO_B_5 
#define ES_UART2_CTS_PIN ES_PIN_GPIO_B_5 
#endif
#endif 


/* UART_CK */


#ifndef ES_UART0_CK_GPIO_FUNC 
#define ES_UART0_CK_GPIO_FUNC GPIO_FUNC_2 
#endif 
#ifndef ES_UART0_CK_GPIO_PORT 
#define ES_UART0_CK_GPIO_PORT GPIOA 
#endif 
#ifndef ES_UART0_CK_GPIO_PIN 
#define ES_UART0_CK_GPIO_PIN GPIO_PIN_6 
#endif 

#ifndef ES_UART0_CK_PIN 
#ifdef ES_PIN_GPIO_A_6 
#define ES_UART0_CK_PIN ES_PIN_GPIO_A_6 
#endif
#endif 

#ifndef ES_UART0_CK_GPIO_FUNC 
#define ES_UART0_CK_GPIO_FUNC GPIO_FUNC_5 
#endif 
#ifndef ES_UART0_CK_GPIO_PORT 
#define ES_UART0_CK_GPIO_PORT GPIOB 
#endif 
#ifndef ES_UART0_CK_GPIO_PIN 
#define ES_UART0_CK_GPIO_PIN GPIO_PIN_15 
#endif 

#ifndef ES_UART0_CK_PIN 
#ifdef ES_PIN_GPIO_B_15 
#define ES_UART0_CK_PIN ES_PIN_GPIO_B_15 
#endif
#endif 

#ifndef ES_UART1_CK_GPIO_FUNC 
#define ES_UART1_CK_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_UART1_CK_GPIO_PORT 
#define ES_UART1_CK_GPIO_PORT GPIOA 
#endif 
#ifndef ES_UART1_CK_GPIO_PIN 
#define ES_UART1_CK_GPIO_PIN GPIO_PIN_15 
#endif 

#ifndef ES_UART1_CK_PIN 
#ifdef ES_PIN_GPIO_A_15 
#define ES_UART1_CK_PIN ES_PIN_GPIO_A_15 
#endif
#endif 

#ifndef ES_UART2_CK_GPIO_FUNC 
#define ES_UART2_CK_GPIO_FUNC GPIO_FUNC_4 
#endif 
#ifndef ES_UART2_CK_GPIO_PORT 
#define ES_UART2_CK_GPIO_PORT GPIOB 
#endif 
#ifndef ES_UART2_CK_GPIO_PIN 
#define ES_UART2_CK_GPIO_PIN GPIO_PIN_7 
#endif 

#ifndef ES_UART2_CK_PIN 
#ifdef ES_PIN_GPIO_B_7 
#define ES_UART2_CK_PIN ES_PIN_GPIO_B_7 
#endif
#endif 


/* USART_TX */



/* USART_RX */



/* USART_RTS */



/* USART_CTS */



/* USART_CK */



/* I2C_SCL */


#ifndef ES_I2C0_SCL_GPIO_FUNC 
#define ES_I2C0_SCL_GPIO_FUNC GPIO_FUNC_4 
#endif 
#ifndef ES_I2C0_SCL_GPIO_PORT 
#define ES_I2C0_SCL_GPIO_PORT GPIOA 
#endif 
#ifndef ES_I2C0_SCL_GPIO_PIN 
#define ES_I2C0_SCL_GPIO_PIN GPIO_PIN_14 
#endif 

#ifndef ES_I2C0_SCL_PIN 
#ifdef ES_PIN_GPIO_A_14 
#define ES_I2C0_SCL_PIN ES_PIN_GPIO_A_14 
#endif
#endif 

#ifndef ES_I2C0_SCL_GPIO_FUNC 
#define ES_I2C0_SCL_GPIO_FUNC GPIO_FUNC_2 
#endif 
#ifndef ES_I2C0_SCL_GPIO_PORT 
#define ES_I2C0_SCL_GPIO_PORT GPIOB 
#endif 
#ifndef ES_I2C0_SCL_GPIO_PIN 
#define ES_I2C0_SCL_GPIO_PIN GPIO_PIN_10 
#endif 

#ifndef ES_I2C0_SCL_PIN 
#ifdef ES_PIN_GPIO_B_10 
#define ES_I2C0_SCL_PIN ES_PIN_GPIO_B_10 
#endif
#endif 

#ifndef ES_I2C1_SCL_GPIO_FUNC 
#define ES_I2C1_SCL_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_I2C1_SCL_GPIO_PORT 
#define ES_I2C1_SCL_GPIO_PORT GPIOB 
#endif 
#ifndef ES_I2C1_SCL_GPIO_PIN 
#define ES_I2C1_SCL_GPIO_PIN GPIO_PIN_4 
#endif 

#ifndef ES_I2C1_SCL_PIN 
#ifdef ES_PIN_GPIO_B_4 
#define ES_I2C1_SCL_PIN ES_PIN_GPIO_B_4 
#endif
#endif 

#ifndef ES_I2C1_SCL_GPIO_FUNC 
#define ES_I2C1_SCL_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_I2C1_SCL_GPIO_PORT 
#define ES_I2C1_SCL_GPIO_PORT GPIOA 
#endif 
#ifndef ES_I2C1_SCL_GPIO_PIN 
#define ES_I2C1_SCL_GPIO_PIN GPIO_PIN_0 
#endif 

#ifndef ES_I2C1_SCL_PIN 
#ifdef ES_PIN_GPIO_A_0 
#define ES_I2C1_SCL_PIN ES_PIN_GPIO_A_0 
#endif
#endif 


/* I2C_SDA */


#ifndef ES_I2C0_SDA_GPIO_FUNC 
#define ES_I2C0_SDA_GPIO_FUNC GPIO_FUNC_4 
#endif 
#ifndef ES_I2C0_SDA_GPIO_PORT 
#define ES_I2C0_SDA_GPIO_PORT GPIOA 
#endif 
#ifndef ES_I2C0_SDA_GPIO_PIN 
#define ES_I2C0_SDA_GPIO_PIN GPIO_PIN_15 
#endif 

#ifndef ES_I2C0_SDA_PIN 
#ifdef ES_PIN_GPIO_A_15 
#define ES_I2C0_SDA_PIN ES_PIN_GPIO_A_15 
#endif
#endif 

#ifndef ES_I2C0_SDA_GPIO_FUNC 
#define ES_I2C0_SDA_GPIO_FUNC GPIO_FUNC_2 
#endif 
#ifndef ES_I2C0_SDA_GPIO_PORT 
#define ES_I2C0_SDA_GPIO_PORT GPIOB 
#endif 
#ifndef ES_I2C0_SDA_GPIO_PIN 
#define ES_I2C0_SDA_GPIO_PIN GPIO_PIN_11 
#endif 

#ifndef ES_I2C0_SDA_PIN 
#ifdef ES_PIN_GPIO_B_11 
#define ES_I2C0_SDA_PIN ES_PIN_GPIO_B_11 
#endif
#endif 

#ifndef ES_I2C1_SDA_GPIO_FUNC 
#define ES_I2C1_SDA_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_I2C1_SDA_GPIO_PORT 
#define ES_I2C1_SDA_GPIO_PORT GPIOB 
#endif 
#ifndef ES_I2C1_SDA_GPIO_PIN 
#define ES_I2C1_SDA_GPIO_PIN GPIO_PIN_5 
#endif 

#ifndef ES_I2C1_SDA_PIN 
#ifdef ES_PIN_GPIO_B_5 
#define ES_I2C1_SDA_PIN ES_PIN_GPIO_B_5 
#endif
#endif 

#ifndef ES_I2C1_SDA_GPIO_FUNC 
#define ES_I2C1_SDA_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_I2C1_SDA_GPIO_PORT 
#define ES_I2C1_SDA_GPIO_PORT GPIOA 
#endif 
#ifndef ES_I2C1_SDA_GPIO_PIN 
#define ES_I2C1_SDA_GPIO_PIN GPIO_PIN_1 
#endif 

#ifndef ES_I2C1_SDA_PIN 
#ifdef ES_PIN_GPIO_A_1 
#define ES_I2C1_SDA_PIN ES_PIN_GPIO_A_1 
#endif
#endif 


/* SPI_MISO */


#ifndef ES_SPI0_MISO_GPIO_FUNC 
#define ES_SPI0_MISO_GPIO_FUNC GPIO_FUNC_2 
#endif 
#ifndef ES_SPI0_MISO_GPIO_PORT 
#define ES_SPI0_MISO_GPIO_PORT GPIOA 
#endif 
#ifndef ES_SPI0_MISO_GPIO_PIN 
#define ES_SPI0_MISO_GPIO_PIN GPIO_PIN_9 
#endif 

#ifndef ES_SPI0_MISO_PIN 
#ifdef ES_PIN_GPIO_A_9 
#define ES_SPI0_MISO_PIN ES_PIN_GPIO_A_9 
#endif
#endif 

#ifndef ES_SPI0_MISO_GPIO_FUNC 
#define ES_SPI0_MISO_GPIO_FUNC GPIO_FUNC_2 
#endif 
#ifndef ES_SPI0_MISO_GPIO_PORT 
#define ES_SPI0_MISO_GPIO_PORT GPIOB 
#endif 
#ifndef ES_SPI0_MISO_GPIO_PIN 
#define ES_SPI0_MISO_GPIO_PIN GPIO_PIN_14 
#endif 

#ifndef ES_SPI0_MISO_PIN 
#ifdef ES_PIN_GPIO_B_14 
#define ES_SPI0_MISO_PIN ES_PIN_GPIO_B_14 
#endif
#endif 

#ifndef ES_SPI1_MISO_GPIO_FUNC 
#define ES_SPI1_MISO_GPIO_FUNC GPIO_FUNC_4 
#endif 
#ifndef ES_SPI1_MISO_GPIO_PORT 
#define ES_SPI1_MISO_GPIO_PORT GPIOA 
#endif 
#ifndef ES_SPI1_MISO_GPIO_PIN 
#define ES_SPI1_MISO_GPIO_PIN GPIO_PIN_6 
#endif 

#ifndef ES_SPI1_MISO_PIN 
#ifdef ES_PIN_GPIO_A_6 
#define ES_SPI1_MISO_PIN ES_PIN_GPIO_A_6 
#endif
#endif 

#ifndef ES_SPI1_MISO_GPIO_FUNC 
#define ES_SPI1_MISO_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_SPI1_MISO_GPIO_PORT 
#define ES_SPI1_MISO_GPIO_PORT GPIOB 
#endif 
#ifndef ES_SPI1_MISO_GPIO_PIN 
#define ES_SPI1_MISO_GPIO_PIN GPIO_PIN_2 
#endif 

#ifndef ES_SPI1_MISO_PIN 
#ifdef ES_PIN_GPIO_B_2 
#define ES_SPI1_MISO_PIN ES_PIN_GPIO_B_2 
#endif
#endif 


/* SPI_MOSI */


#ifndef ES_SPI0_MOSI_GPIO_FUNC 
#define ES_SPI0_MOSI_GPIO_FUNC GPIO_FUNC_2 
#endif 
#ifndef ES_SPI0_MOSI_GPIO_PORT 
#define ES_SPI0_MOSI_GPIO_PORT GPIOA 
#endif 
#ifndef ES_SPI0_MOSI_GPIO_PIN 
#define ES_SPI0_MOSI_GPIO_PIN GPIO_PIN_10 
#endif 

#ifndef ES_SPI0_MOSI_PIN 
#ifdef ES_PIN_GPIO_A_10 
#define ES_SPI0_MOSI_PIN ES_PIN_GPIO_A_10 
#endif
#endif 

#ifndef ES_SPI0_MOSI_GPIO_FUNC 
#define ES_SPI0_MOSI_GPIO_FUNC GPIO_FUNC_2 
#endif 
#ifndef ES_SPI0_MOSI_GPIO_PORT 
#define ES_SPI0_MOSI_GPIO_PORT GPIOB 
#endif 
#ifndef ES_SPI0_MOSI_GPIO_PIN 
#define ES_SPI0_MOSI_GPIO_PIN GPIO_PIN_15 
#endif 

#ifndef ES_SPI0_MOSI_PIN 
#ifdef ES_PIN_GPIO_B_15 
#define ES_SPI0_MOSI_PIN ES_PIN_GPIO_B_15 
#endif
#endif 

#ifndef ES_SPI1_MOSI_GPIO_FUNC 
#define ES_SPI1_MOSI_GPIO_FUNC GPIO_FUNC_4 
#endif 
#ifndef ES_SPI1_MOSI_GPIO_PORT 
#define ES_SPI1_MOSI_GPIO_PORT GPIOA 
#endif 
#ifndef ES_SPI1_MOSI_GPIO_PIN 
#define ES_SPI1_MOSI_GPIO_PIN GPIO_PIN_7 
#endif 

#ifndef ES_SPI1_MOSI_PIN 
#ifdef ES_PIN_GPIO_A_7 
#define ES_SPI1_MOSI_PIN ES_PIN_GPIO_A_7 
#endif
#endif 

#ifndef ES_SPI1_MOSI_GPIO_FUNC 
#define ES_SPI1_MOSI_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_SPI1_MOSI_GPIO_PORT 
#define ES_SPI1_MOSI_GPIO_PORT GPIOB 
#endif 
#ifndef ES_SPI1_MOSI_GPIO_PIN 
#define ES_SPI1_MOSI_GPIO_PIN GPIO_PIN_3 
#endif 

#ifndef ES_SPI1_MOSI_PIN 
#ifdef ES_PIN_GPIO_B_3 
#define ES_SPI1_MOSI_PIN ES_PIN_GPIO_B_3 
#endif
#endif 


/* SPI_SCK */


#ifndef ES_SPI0_SCK_GPIO_FUNC 
#define ES_SPI0_SCK_GPIO_FUNC GPIO_FUNC_2 
#endif 
#ifndef ES_SPI0_SCK_GPIO_PORT 
#define ES_SPI0_SCK_GPIO_PORT GPIOA 
#endif 
#ifndef ES_SPI0_SCK_GPIO_PIN 
#define ES_SPI0_SCK_GPIO_PIN GPIO_PIN_7 
#endif 

#ifndef ES_SPI0_SCK_PIN 
#ifdef ES_PIN_GPIO_A_7 
#define ES_SPI0_SCK_PIN ES_PIN_GPIO_A_7 
#endif
#endif 

#ifndef ES_SPI0_SCK_GPIO_FUNC 
#define ES_SPI0_SCK_GPIO_FUNC GPIO_FUNC_2 
#endif 
#ifndef ES_SPI0_SCK_GPIO_PORT 
#define ES_SPI0_SCK_GPIO_PORT GPIOB 
#endif 
#ifndef ES_SPI0_SCK_GPIO_PIN 
#define ES_SPI0_SCK_GPIO_PIN GPIO_PIN_12 
#endif 

#ifndef ES_SPI0_SCK_PIN 
#ifdef ES_PIN_GPIO_B_12 
#define ES_SPI0_SCK_PIN ES_PIN_GPIO_B_12 
#endif
#endif 

#ifndef ES_SPI1_SCK_GPIO_FUNC 
#define ES_SPI1_SCK_GPIO_FUNC GPIO_FUNC_4 
#endif 
#ifndef ES_SPI1_SCK_GPIO_PORT 
#define ES_SPI1_SCK_GPIO_PORT GPIOA 
#endif 
#ifndef ES_SPI1_SCK_GPIO_PIN 
#define ES_SPI1_SCK_GPIO_PIN GPIO_PIN_4 
#endif 

#ifndef ES_SPI1_SCK_PIN 
#ifdef ES_PIN_GPIO_A_4 
#define ES_SPI1_SCK_PIN ES_PIN_GPIO_A_4 
#endif
#endif 

#ifndef ES_SPI1_SCK_GPIO_FUNC 
#define ES_SPI1_SCK_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_SPI1_SCK_GPIO_PORT 
#define ES_SPI1_SCK_GPIO_PORT GPIOB 
#endif 
#ifndef ES_SPI1_SCK_GPIO_PIN 
#define ES_SPI1_SCK_GPIO_PIN GPIO_PIN_0 
#endif 

#ifndef ES_SPI1_SCK_PIN 
#ifdef ES_PIN_GPIO_B_0 
#define ES_SPI1_SCK_PIN ES_PIN_GPIO_B_0 
#endif
#endif 


/* SPI_NSS */


#ifndef ES_SPI0_NSS_GPIO_FUNC 
#define ES_SPI0_NSS_GPIO_FUNC GPIO_FUNC_2 
#endif 
#ifndef ES_SPI0_NSS_GPIO_PORT 
#define ES_SPI0_NSS_GPIO_PORT GPIOA 
#endif 
#ifndef ES_SPI0_NSS_GPIO_PIN 
#define ES_SPI0_NSS_GPIO_PIN GPIO_PIN_8 
#endif 

#ifndef ES_SPI0_NSS_PIN 
#ifdef ES_PIN_GPIO_A_8 
#define ES_SPI0_NSS_PIN ES_PIN_GPIO_A_8 
#endif
#endif 

#ifndef ES_SPI0_NSS_GPIO_FUNC 
#define ES_SPI0_NSS_GPIO_FUNC GPIO_FUNC_2 
#endif 
#ifndef ES_SPI0_NSS_GPIO_PORT 
#define ES_SPI0_NSS_GPIO_PORT GPIOB 
#endif 
#ifndef ES_SPI0_NSS_GPIO_PIN 
#define ES_SPI0_NSS_GPIO_PIN GPIO_PIN_13 
#endif 

#ifndef ES_SPI0_NSS_PIN 
#ifdef ES_PIN_GPIO_B_13 
#define ES_SPI0_NSS_PIN ES_PIN_GPIO_B_13 
#endif
#endif 

#ifndef ES_SPI1_NSS_GPIO_FUNC 
#define ES_SPI1_NSS_GPIO_FUNC GPIO_FUNC_4 
#endif 
#ifndef ES_SPI1_NSS_GPIO_PORT 
#define ES_SPI1_NSS_GPIO_PORT GPIOA 
#endif 
#ifndef ES_SPI1_NSS_GPIO_PIN 
#define ES_SPI1_NSS_GPIO_PIN GPIO_PIN_5 
#endif 

#ifndef ES_SPI1_NSS_PIN 
#ifdef ES_PIN_GPIO_A_5 
#define ES_SPI1_NSS_PIN ES_PIN_GPIO_A_5 
#endif
#endif 

#ifndef ES_SPI1_NSS_GPIO_FUNC 
#define ES_SPI1_NSS_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_SPI1_NSS_GPIO_PORT 
#define ES_SPI1_NSS_GPIO_PORT GPIOB 
#endif 
#ifndef ES_SPI1_NSS_GPIO_PIN 
#define ES_SPI1_NSS_GPIO_PIN GPIO_PIN_1 
#endif 

#ifndef ES_SPI1_NSS_PIN 
#ifdef ES_PIN_GPIO_B_1 
#define ES_SPI1_NSS_PIN ES_PIN_GPIO_B_1 
#endif
#endif 


/* CAN_TX */



/* CAN_RX */



/* AD16C4T_CH1 */


#ifndef ES_AD16C4T0_CH1_GPIO_FUNC 
#define ES_AD16C4T0_CH1_GPIO_FUNC GPIO_FUNC_2 
#endif 
#ifndef ES_AD16C4T0_CH1_GPIO_PORT 
#define ES_AD16C4T0_CH1_GPIO_PORT GPIOB 
#endif 
#ifndef ES_AD16C4T0_CH1_GPIO_PIN 
#define ES_AD16C4T0_CH1_GPIO_PIN GPIO_PIN_1 
#endif 

#ifndef ES_AD16C4T0_CH1_PIN 
#ifdef ES_PIN_GPIO_B_1 
#define ES_AD16C4T0_CH1_PIN ES_PIN_GPIO_B_1 
#endif
#endif 

#ifndef ES_AD16C4T1_CH1_GPIO_FUNC 
#define ES_AD16C4T1_CH1_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_AD16C4T1_CH1_GPIO_PORT 
#define ES_AD16C4T1_CH1_GPIO_PORT GPIOB 
#endif 
#ifndef ES_AD16C4T1_CH1_GPIO_PIN 
#define ES_AD16C4T1_CH1_GPIO_PIN GPIO_PIN_10 
#endif 

#ifndef ES_AD16C4T1_CH1_PIN 
#ifdef ES_PIN_GPIO_B_10 
#define ES_AD16C4T1_CH1_PIN ES_PIN_GPIO_B_10 
#endif
#endif 


/* AD16C4T_CH2 */


#ifndef ES_AD16C4T0_CH2_GPIO_FUNC 
#define ES_AD16C4T0_CH2_GPIO_FUNC GPIO_FUNC_2 
#endif 
#ifndef ES_AD16C4T0_CH2_GPIO_PORT 
#define ES_AD16C4T0_CH2_GPIO_PORT GPIOB 
#endif 
#ifndef ES_AD16C4T0_CH2_GPIO_PIN 
#define ES_AD16C4T0_CH2_GPIO_PIN GPIO_PIN_3 
#endif 

#ifndef ES_AD16C4T0_CH2_PIN 
#ifdef ES_PIN_GPIO_B_3 
#define ES_AD16C4T0_CH2_PIN ES_PIN_GPIO_B_3 
#endif
#endif 

#ifndef ES_AD16C4T1_CH2_GPIO_FUNC 
#define ES_AD16C4T1_CH2_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_AD16C4T1_CH2_GPIO_PORT 
#define ES_AD16C4T1_CH2_GPIO_PORT GPIOB 
#endif 
#ifndef ES_AD16C4T1_CH2_GPIO_PIN 
#define ES_AD16C4T1_CH2_GPIO_PIN GPIO_PIN_12 
#endif 

#ifndef ES_AD16C4T1_CH2_PIN 
#ifdef ES_PIN_GPIO_B_12 
#define ES_AD16C4T1_CH2_PIN ES_PIN_GPIO_B_12 
#endif
#endif 


/* AD16C4T_CH3 */


#ifndef ES_AD16C4T0_CH3_GPIO_FUNC 
#define ES_AD16C4T0_CH3_GPIO_FUNC GPIO_FUNC_2 
#endif 
#ifndef ES_AD16C4T0_CH3_GPIO_PORT 
#define ES_AD16C4T0_CH3_GPIO_PORT GPIOB 
#endif 
#ifndef ES_AD16C4T0_CH3_GPIO_PIN 
#define ES_AD16C4T0_CH3_GPIO_PIN GPIO_PIN_5 
#endif 

#ifndef ES_AD16C4T0_CH3_PIN 
#ifdef ES_PIN_GPIO_B_5 
#define ES_AD16C4T0_CH3_PIN ES_PIN_GPIO_B_5 
#endif
#endif 

#ifndef ES_AD16C4T1_CH3_GPIO_FUNC 
#define ES_AD16C4T1_CH3_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_AD16C4T1_CH3_GPIO_PORT 
#define ES_AD16C4T1_CH3_GPIO_PORT GPIOB 
#endif 
#ifndef ES_AD16C4T1_CH3_GPIO_PIN 
#define ES_AD16C4T1_CH3_GPIO_PIN GPIO_PIN_14 
#endif 

#ifndef ES_AD16C4T1_CH3_PIN 
#ifdef ES_PIN_GPIO_B_14 
#define ES_AD16C4T1_CH3_PIN ES_PIN_GPIO_B_14 
#endif
#endif 


/* AD16C4T_CH4 */


#ifndef ES_AD16C4T0_CH4_GPIO_FUNC 
#define ES_AD16C4T0_CH4_GPIO_FUNC GPIO_FUNC_2 
#endif 
#ifndef ES_AD16C4T0_CH4_GPIO_PORT 
#define ES_AD16C4T0_CH4_GPIO_PORT GPIOB 
#endif 
#ifndef ES_AD16C4T0_CH4_GPIO_PIN 
#define ES_AD16C4T0_CH4_GPIO_PIN GPIO_PIN_6 
#endif 

#ifndef ES_AD16C4T0_CH4_PIN 
#ifdef ES_PIN_GPIO_B_6 
#define ES_AD16C4T0_CH4_PIN ES_PIN_GPIO_B_6 
#endif
#endif 

#ifndef ES_AD16C4T1_CH4_GPIO_FUNC 
#define ES_AD16C4T1_CH4_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_AD16C4T1_CH4_GPIO_PORT 
#define ES_AD16C4T1_CH4_GPIO_PORT GPIOB 
#endif 
#ifndef ES_AD16C4T1_CH4_GPIO_PIN 
#define ES_AD16C4T1_CH4_GPIO_PIN GPIO_PIN_15 
#endif 

#ifndef ES_AD16C4T1_CH4_PIN 
#ifdef ES_PIN_GPIO_B_15 
#define ES_AD16C4T1_CH4_PIN ES_PIN_GPIO_B_15 
#endif
#endif 


/* AD16C4T_CH1N */


#ifndef ES_AD16C4T0_CH1N_GPIO_FUNC 
#define ES_AD16C4T0_CH1N_GPIO_FUNC GPIO_FUNC_2 
#endif 
#ifndef ES_AD16C4T0_CH1N_GPIO_PORT 
#define ES_AD16C4T0_CH1N_GPIO_PORT GPIOB 
#endif 
#ifndef ES_AD16C4T0_CH1N_GPIO_PIN 
#define ES_AD16C4T0_CH1N_GPIO_PIN GPIO_PIN_0 
#endif 

#ifndef ES_AD16C4T0_CH1N_PIN 
#ifdef ES_PIN_GPIO_B_0 
#define ES_AD16C4T0_CH1N_PIN ES_PIN_GPIO_B_0 
#endif
#endif 

#ifndef ES_AD16C4T1_CH1N_GPIO_FUNC 
#define ES_AD16C4T1_CH1N_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_AD16C4T1_CH1N_GPIO_PORT 
#define ES_AD16C4T1_CH1N_GPIO_PORT GPIOB 
#endif 
#ifndef ES_AD16C4T1_CH1N_GPIO_PIN 
#define ES_AD16C4T1_CH1N_GPIO_PIN GPIO_PIN_9 
#endif 

#ifndef ES_AD16C4T1_CH1N_PIN 
#ifdef ES_PIN_GPIO_B_9 
#define ES_AD16C4T1_CH1N_PIN ES_PIN_GPIO_B_9 
#endif
#endif 


/* AD16C4T_CH2N */


#ifndef ES_AD16C4T0_CH2N_GPIO_FUNC 
#define ES_AD16C4T0_CH2N_GPIO_FUNC GPIO_FUNC_2 
#endif 
#ifndef ES_AD16C4T0_CH2N_GPIO_PORT 
#define ES_AD16C4T0_CH2N_GPIO_PORT GPIOB 
#endif 
#ifndef ES_AD16C4T0_CH2N_GPIO_PIN 
#define ES_AD16C4T0_CH2N_GPIO_PIN GPIO_PIN_2 
#endif 

#ifndef ES_AD16C4T0_CH2N_PIN 
#ifdef ES_PIN_GPIO_B_2 
#define ES_AD16C4T0_CH2N_PIN ES_PIN_GPIO_B_2 
#endif
#endif 

#ifndef ES_AD16C4T1_CH2N_GPIO_FUNC 
#define ES_AD16C4T1_CH2N_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_AD16C4T1_CH2N_GPIO_PORT 
#define ES_AD16C4T1_CH2N_GPIO_PORT GPIOB 
#endif 
#ifndef ES_AD16C4T1_CH2N_GPIO_PIN 
#define ES_AD16C4T1_CH2N_GPIO_PIN GPIO_PIN_11 
#endif 

#ifndef ES_AD16C4T1_CH2N_PIN 
#ifdef ES_PIN_GPIO_B_11 
#define ES_AD16C4T1_CH2N_PIN ES_PIN_GPIO_B_11 
#endif
#endif 


/* AD16C4T_CH3N */


#ifndef ES_AD16C4T0_CH3N_GPIO_FUNC 
#define ES_AD16C4T0_CH3N_GPIO_FUNC GPIO_FUNC_2 
#endif 
#ifndef ES_AD16C4T0_CH3N_GPIO_PORT 
#define ES_AD16C4T0_CH3N_GPIO_PORT GPIOB 
#endif 
#ifndef ES_AD16C4T0_CH3N_GPIO_PIN 
#define ES_AD16C4T0_CH3N_GPIO_PIN GPIO_PIN_4 
#endif 

#ifndef ES_AD16C4T0_CH3N_PIN 
#ifdef ES_PIN_GPIO_B_4 
#define ES_AD16C4T0_CH3N_PIN ES_PIN_GPIO_B_4 
#endif
#endif 

#ifndef ES_AD16C4T1_CH3N_GPIO_FUNC 
#define ES_AD16C4T1_CH3N_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_AD16C4T1_CH3N_GPIO_PORT 
#define ES_AD16C4T1_CH3N_GPIO_PORT GPIOB 
#endif 
#ifndef ES_AD16C4T1_CH3N_GPIO_PIN 
#define ES_AD16C4T1_CH3N_GPIO_PIN GPIO_PIN_13 
#endif 

#ifndef ES_AD16C4T1_CH3N_PIN 
#ifdef ES_PIN_GPIO_B_13 
#define ES_AD16C4T1_CH3N_PIN ES_PIN_GPIO_B_13 
#endif
#endif 


/* AD16C4T_CH4N */



/* AD16C4T_ET */


#ifndef ES_AD16C4T0_ET_GPIO_FUNC 
#define ES_AD16C4T0_ET_GPIO_FUNC GPIO_FUNC_2 
#endif 
#ifndef ES_AD16C4T0_ET_GPIO_PORT 
#define ES_AD16C4T0_ET_GPIO_PORT GPIOA 
#endif 
#ifndef ES_AD16C4T0_ET_GPIO_PIN 
#define ES_AD16C4T0_ET_GPIO_PIN GPIO_PIN_14 
#endif 

#ifndef ES_AD16C4T0_ET_PIN 
#ifdef ES_PIN_GPIO_A_14 
#define ES_AD16C4T0_ET_PIN ES_PIN_GPIO_A_14 
#endif
#endif 

#ifndef ES_AD16C4T1_ET_GPIO_FUNC 
#define ES_AD16C4T1_ET_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_AD16C4T1_ET_GPIO_PORT 
#define ES_AD16C4T1_ET_GPIO_PORT GPIOB 
#endif 
#ifndef ES_AD16C4T1_ET_GPIO_PIN 
#define ES_AD16C4T1_ET_GPIO_PIN GPIO_PIN_7 
#endif 

#ifndef ES_AD16C4T1_ET_PIN 
#ifdef ES_PIN_GPIO_B_7 
#define ES_AD16C4T1_ET_PIN ES_PIN_GPIO_B_7 
#endif
#endif 


/* GP32C4T_CH1 */



/* GP32C4T_CH2 */



/* GP32C4T_CH3 */



/* GP32C4T_CH4 */



/* GP32C4T_ET */



/* GP16C4T_CH1 */


#ifndef ES_GP16C4T0_CH1_GPIO_FUNC 
#define ES_GP16C4T0_CH1_GPIO_FUNC GPIO_FUNC_4 
#endif 
#ifndef ES_GP16C4T0_CH1_GPIO_PORT 
#define ES_GP16C4T0_CH1_GPIO_PORT GPIOA 
#endif 
#ifndef ES_GP16C4T0_CH1_GPIO_PIN 
#define ES_GP16C4T0_CH1_GPIO_PIN GPIO_PIN_0 
#endif 

#ifndef ES_GP16C4T0_CH1_PIN 
#ifdef ES_PIN_GPIO_A_0 
#define ES_GP16C4T0_CH1_PIN ES_PIN_GPIO_A_0 
#endif
#endif 

#ifndef ES_GP16C4T1_CH1_GPIO_FUNC 
#define ES_GP16C4T1_CH1_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_GP16C4T1_CH1_GPIO_PORT 
#define ES_GP16C4T1_CH1_GPIO_PORT GPIOA 
#endif 
#ifndef ES_GP16C4T1_CH1_GPIO_PIN 
#define ES_GP16C4T1_CH1_GPIO_PIN GPIO_PIN_4 
#endif 

#ifndef ES_GP16C4T1_CH1_PIN 
#ifdef ES_PIN_GPIO_A_4 
#define ES_GP16C4T1_CH1_PIN ES_PIN_GPIO_A_4 
#endif
#endif 


/* GP16C4T_CH2 */


#ifndef ES_GP16C4T0_CH2_GPIO_FUNC 
#define ES_GP16C4T0_CH2_GPIO_FUNC GPIO_FUNC_4 
#endif 
#ifndef ES_GP16C4T0_CH2_GPIO_PORT 
#define ES_GP16C4T0_CH2_GPIO_PORT GPIOA 
#endif 
#ifndef ES_GP16C4T0_CH2_GPIO_PIN 
#define ES_GP16C4T0_CH2_GPIO_PIN GPIO_PIN_1 
#endif 

#ifndef ES_GP16C4T0_CH2_PIN 
#ifdef ES_PIN_GPIO_A_1 
#define ES_GP16C4T0_CH2_PIN ES_PIN_GPIO_A_1 
#endif
#endif 

#ifndef ES_GP16C4T1_CH2_GPIO_FUNC 
#define ES_GP16C4T1_CH2_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_GP16C4T1_CH2_GPIO_PORT 
#define ES_GP16C4T1_CH2_GPIO_PORT GPIOA 
#endif 
#ifndef ES_GP16C4T1_CH2_GPIO_PIN 
#define ES_GP16C4T1_CH2_GPIO_PIN GPIO_PIN_5 
#endif 

#ifndef ES_GP16C4T1_CH2_PIN 
#ifdef ES_PIN_GPIO_A_5 
#define ES_GP16C4T1_CH2_PIN ES_PIN_GPIO_A_5 
#endif
#endif 


/* GP16C4T_CH3 */


#ifndef ES_GP16C4T0_CH3_GPIO_FUNC 
#define ES_GP16C4T0_CH3_GPIO_FUNC GPIO_FUNC_4 
#endif 
#ifndef ES_GP16C4T0_CH3_GPIO_PORT 
#define ES_GP16C4T0_CH3_GPIO_PORT GPIOA 
#endif 
#ifndef ES_GP16C4T0_CH3_GPIO_PIN 
#define ES_GP16C4T0_CH3_GPIO_PIN GPIO_PIN_2 
#endif 

#ifndef ES_GP16C4T0_CH3_PIN 
#ifdef ES_PIN_GPIO_A_2 
#define ES_GP16C4T0_CH3_PIN ES_PIN_GPIO_A_2 
#endif
#endif 

#ifndef ES_GP16C4T1_CH3_GPIO_FUNC 
#define ES_GP16C4T1_CH3_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_GP16C4T1_CH3_GPIO_PORT 
#define ES_GP16C4T1_CH3_GPIO_PORT GPIOA 
#endif 
#ifndef ES_GP16C4T1_CH3_GPIO_PIN 
#define ES_GP16C4T1_CH3_GPIO_PIN GPIO_PIN_6 
#endif 

#ifndef ES_GP16C4T1_CH3_PIN 
#ifdef ES_PIN_GPIO_A_6 
#define ES_GP16C4T1_CH3_PIN ES_PIN_GPIO_A_6 
#endif
#endif 


/* GP16C4T_CH4 */


#ifndef ES_GP16C4T0_CH4_GPIO_FUNC 
#define ES_GP16C4T0_CH4_GPIO_FUNC GPIO_FUNC_4 
#endif 
#ifndef ES_GP16C4T0_CH4_GPIO_PORT 
#define ES_GP16C4T0_CH4_GPIO_PORT GPIOA 
#endif 
#ifndef ES_GP16C4T0_CH4_GPIO_PIN 
#define ES_GP16C4T0_CH4_GPIO_PIN GPIO_PIN_3 
#endif 

#ifndef ES_GP16C4T0_CH4_PIN 
#ifdef ES_PIN_GPIO_A_3 
#define ES_GP16C4T0_CH4_PIN ES_PIN_GPIO_A_3 
#endif
#endif 

#ifndef ES_GP16C4T1_CH4_GPIO_FUNC 
#define ES_GP16C4T1_CH4_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_GP16C4T1_CH4_GPIO_PORT 
#define ES_GP16C4T1_CH4_GPIO_PORT GPIOA 
#endif 
#ifndef ES_GP16C4T1_CH4_GPIO_PIN 
#define ES_GP16C4T1_CH4_GPIO_PIN GPIO_PIN_7 
#endif 

#ifndef ES_GP16C4T1_CH4_PIN 
#ifdef ES_PIN_GPIO_A_7 
#define ES_GP16C4T1_CH4_PIN ES_PIN_GPIO_A_7 
#endif
#endif 


/* GP16C4T_ET */


#ifndef ES_GP16C4T0_ET_GPIO_FUNC 
#define ES_GP16C4T0_ET_GPIO_FUNC GPIO_FUNC_4 
#endif 
#ifndef ES_GP16C4T0_ET_GPIO_PORT 
#define ES_GP16C4T0_ET_GPIO_PORT GPIOA 
#endif 
#ifndef ES_GP16C4T0_ET_GPIO_PIN 
#define ES_GP16C4T0_ET_GPIO_PIN GPIO_PIN_8 
#endif 

#ifndef ES_GP16C4T0_ET_PIN 
#ifdef ES_PIN_GPIO_A_8 
#define ES_GP16C4T0_ET_PIN ES_PIN_GPIO_A_8 
#endif
#endif 

#ifndef ES_GP16C4T1_ET_GPIO_FUNC 
#define ES_GP16C4T1_ET_GPIO_FUNC GPIO_FUNC_3 
#endif 
#ifndef ES_GP16C4T1_ET_GPIO_PORT 
#define ES_GP16C4T1_ET_GPIO_PORT GPIOA 
#endif 
#ifndef ES_GP16C4T1_ET_GPIO_PIN 
#define ES_GP16C4T1_ET_GPIO_PIN GPIO_PIN_10 
#endif 

#ifndef ES_GP16C4T1_ET_PIN 
#ifdef ES_PIN_GPIO_A_10 
#define ES_GP16C4T1_ET_PIN ES_PIN_GPIO_A_10 
#endif
#endif 


/* GP16C2T_CH1 */



/* GP16C2T_CH2 */



/* GP16C2T_CH1N */



/* GP16C2T_CH2N */



#endif
