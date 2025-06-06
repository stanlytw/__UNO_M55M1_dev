/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include "Arduino.h"
#include "Pins_arduino.h"
//__M55M1__


#if defined(__M55M1__) 
#ifdef USE_BoardToPin
//[2025-02-18] BoardToPin updated
BoardToPin BoardToPinInfo[] =
{
    //For D0~D13, D16 UNO_SDA, D17 UNO_SCL
	//{pin, type, num}//
	{ 21, UART_TYPE, 0                 },// 0:       (D0/PB2/UART_RX0)
    { 20, UART_TYPE, 0                 },// 1:       (D1/PB3/UART_TX0)
    { 19, PWM_TYPE, PWM_DESC_IDX0      }, // 2:      (D2/PC9/PWM)
    { 18, PWM_TYPE, PWM_DESC_IDX1      }, // 3:      (D3/PC10/PWM)
    { 25, PWM_TYPE, PWM_DESC_IDX2      }, // 4:      (D4/PC11/PWM)
    { 26, PWM_TYPE, PWM_DESC_IDX3      }, // 5:      (D5/PC12/PWM)
    {  8, PWM_TYPE, PWM_DESC_IDX4      }, // 6:      (D6/PB4/PWM)
    { 52, PWM_TYPE, PWM_DESC_IDX5      }, // 7:      (D7/PB5/PWM)
    {  7, SPI_TYPE, 0                  }, // 8:      (D8/PA5/QSPI)
    { 12, SPI_TYPE, 0                  }, // 9:      (D9/PA4/QSPI)
    { 27, SPI_TYPE, 0                  }, //10:      (D10/PA3/QSPI)
    { 30, SPI_TYPE, 0                  }, //11:      (D11/PA0/QSPI)
    { 29, SPI_TYPE, 0                  }, //12:      (D12/PA1/QSPI)
    { 28, SPI_TYPE, 0                  }, //13:      (D13/PA2/QSPI)
	{ -1,        0, 0                  }, //14:      VSS
    { -1,        0, 0                  }, //15:      VREF
	{ 56, I2C_TYPE, 0                  }, //16:      (UNO_SDA/PG0/I2C0_SDA)
    { 55, I2C_TYPE, 0                  }, //17:      (UNO_SCL/PG1/I2C0_SCL)
 
#ifdef NU5_CONNECTOR_SPI 
    { -1,        0, 0}, //22: NC
    { -1,        0, 0}, //23: NC
    { -1,        0, 0}, //24: NC
    { -1,        0, 0}, //25: NC
#endif

};
#endif

#define GPIO_Desc_A0_Idx 0
#define GPIO_Desc_A1_Idx 1
#define GPIO_Desc_A2_Idx 2
#define GPIO_Desc_A3_Idx 3
#define GPIO_Desc_A4_Idx 4
#define GPIO_Desc_A5_Idx 5

#define GPIO_Desc_D0_Idx 6
#define GPIO_Desc_D1_Idx 7
#define GPIO_Desc_D2_Idx 8
#define GPIO_Desc_D3_Idx 9
#define GPIO_Desc_D4_Idx 10
#define GPIO_Desc_D5_Idx 11
#define GPIO_Desc_D6_Idx 12
#define GPIO_Desc_D7_Idx 13
#define GPIO_Desc_D8_Idx 14
#define GPIO_Desc_D9_Idx 15
#define GPIO_Desc_D10_Idx 16
#define GPIO_Desc_D11_Idx 17
#define GPIO_Desc_D12_Idx 18
#define GPIO_Desc_D13_Idx 19
#define GPIO_Desc_D16_Idx 22
#define GPIO_Desc_D17_Idx 23



GPIOPinDescription GPIO_Desc[] =
{
    //A0~A5
	{PB, BIT6,  {(uint32_t) &SYS->GPB_MFP1, SYS_GPB_MFP1_PB6MFP_Msk, SYS_GPB_MFP1_PB6MFP_GPIO}},    // Pin : PB.6
    {PB, BIT7,  {(uint32_t) &SYS->GPB_MFP1, SYS_GPB_MFP1_PB7MFP_Msk, SYS_GPB_MFP1_PB7MFP_GPIO}},    // Pin : PB.7
	{PB, BIT8,  {(uint32_t) &SYS->GPB_MFP2, SYS_GPB_MFP2_PB8MFP_Msk, SYS_GPB_MFP2_PB8MFP_GPIO}},    // Pin : PB.8
	{PB, BIT9,  {(uint32_t) &SYS->GPB_MFP2, SYS_GPB_MFP2_PB9MFP_Msk, SYS_GPB_MFP2_PB9MFP_GPIO}},    // Pin : PB.9
	{PB, BIT0,  {(uint32_t) &SYS->GPB_MFP0, SYS_GPB_MFP0_PB0MFP_Msk, SYS_GPB_MFP0_PB0MFP_GPIO}},    // Pin : PB.0
	{PB, BIT1,  {(uint32_t) &SYS->GPB_MFP0, SYS_GPB_MFP0_PB1MFP_Msk, SYS_GPB_MFP0_PB1MFP_GPIO}},    // Pin : PB.1
	
	//D0~D13
	{PB, BIT2,  {(uint32_t) &SYS->GPB_MFP0, SYS_GPB_MFP0_PB2MFP_Msk, SYS_GPB_MFP0_PB2MFP_GPIO}},    // Pin : PB.2
	{PB, BIT3,  {(uint32_t) &SYS->GPB_MFP0, SYS_GPB_MFP0_PB3MFP_Msk, SYS_GPB_MFP0_PB3MFP_GPIO}},    // Pin : PB.3
    {PC, BIT9,  {(uint32_t) &SYS->GPC_MFP2, SYS_GPC_MFP2_PC9MFP_Msk, SYS_GPC_MFP2_PC9MFP_GPIO}},    // Pin : PC.9
	{PC, BIT10, {(uint32_t) &SYS->GPC_MFP2, SYS_GPC_MFP2_PC10MFP_Msk, SYS_GPC_MFP2_PC10MFP_GPIO}},  // Pin : PC.10
	{PC, BIT11, {(uint32_t) &SYS->GPC_MFP2, SYS_GPC_MFP2_PC11MFP_Msk, SYS_GPC_MFP2_PC11MFP_GPIO}},  // Pin : PC.11
	{PC, BIT12, {(uint32_t) &SYS->GPC_MFP3, SYS_GPC_MFP3_PC12MFP_Msk, SYS_GPC_MFP3_PC12MFP_GPIO}},  // Pin : PC.12
    {PB, BIT4,  {(uint32_t) &SYS->GPB_MFP1, SYS_GPB_MFP1_PB4MFP_Msk, SYS_GPB_MFP1_PB4MFP_GPIO}},    // Pin : PB.4
    {PB, BIT5,  {(uint32_t) &SYS->GPB_MFP1, SYS_GPB_MFP1_PB5MFP_Msk, SYS_GPB_MFP1_PB5MFP_GPIO}},    // Pin : PB.5
    {PA, BIT5,  {(uint32_t) &SYS->GPA_MFP1, SYS_GPA_MFP1_PA5MFP_Msk, SYS_GPA_MFP1_PA5MFP_GPIO}},    // Pin : PA.5
    {PA, BIT4,  {(uint32_t) &SYS->GPA_MFP1, SYS_GPA_MFP1_PA4MFP_Msk, SYS_GPA_MFP1_PA4MFP_GPIO}},    // Pin : PA.4
    {PA, BIT3,  {(uint32_t) &SYS->GPA_MFP0, SYS_GPA_MFP0_PA3MFP_Msk, SYS_GPA_MFP0_PA3MFP_GPIO}},    // Pin : PA.3
    {PA, BIT0,  {(uint32_t) &SYS->GPA_MFP0, SYS_GPA_MFP0_PA0MFP_Msk, SYS_GPA_MFP0_PA0MFP_GPIO}},    // Pin : PA.0
	{PA, BIT1,  {(uint32_t) &SYS->GPA_MFP0, SYS_GPA_MFP0_PA1MFP_Msk, SYS_GPA_MFP0_PA1MFP_GPIO}},    // Pin : PA.1
	{PA, BIT2,  {(uint32_t) &SYS->GPA_MFP0, SYS_GPA_MFP0_PA2MFP_Msk, SYS_GPA_MFP0_PA2MFP_GPIO}},    // Pin : PA.2
    
	//D14, D15
	{NULL, 0, {0, 0, 0}},                                                                           // Pin : X
	{NULL, 0, {0, 0, 0}},                                                                           // Pin : X
	
	//D16, D17 
	{PG, BIT1,  {(uint32_t) &SYS->GPG_MFP0, SYS_GPG_MFP0_PG1MFP_Msk, SYS_GPG_MFP0_PG1MFP_GPIO}},    // Pin : PG.1
	{PG, BIT0,  {(uint32_t) &SYS->GPG_MFP0, SYS_GPG_MFP0_PG0MFP_Msk, SYS_GPG_MFP0_PG0MFP_GPIO}},    // Pin : PG.0
	
	//For Nulink VCOM
	{PB, BIT13, {(uint32_t) &SYS->GPB_MFP3, SYS_GPB_MFP3_PB13MFP_Msk, SYS_GPB_MFP3_PB13MFP_GPIO}},  // Pin : PB.13
    {PB, BIT12, {(uint32_t) &SYS->GPB_MFP3, SYS_GPB_MFP3_PB12MFP_Msk, SYS_GPB_MFP3_PB12MFP_GPIO}},  // Pin : PB.12
 
};

EPWMPinDescription PWM_Desc[PWM_DESC_MAX] = 
{
    //D2 EPWM1_CH3
	{(EPWM_T  *)(EPWM1), (uint32_t)EPWM1_MODULE, PWM_USE_EPWM, EPWM1P0_IRQn, PWM_CHANNEL_CH3, PWM_FREQUENCY_500HZ, {GPIO_Desc_D2_Idx, SYS_GPC_MFP2_PC9MFP_EPWM1_CH3}}, 
    //D3 EPWM1_CH2
	{(EPWM_T  *)(EPWM1), (uint32_t)EPWM1_MODULE, PWM_USE_EPWM, BPWM1P0_IRQn, PWM_CHANNEL_CH2, PWM_FREQUENCY_500HZ, {GPIO_Desc_D3_Idx, SYS_GPC_MFP3_PC10MFP_EPWM1_CH2 }}, 
	//D4 EPWM1_CH1
	{(EPWM_T  *)(EPWM1), (uint32_t)EPWM1_MODULE, PWM_USE_EPWM, EPWM1P0_IRQn, PWM_CHANNEL_CH1, PWM_FREQUENCY_500HZ, {GPIO_Desc_D4_Idx, SYS_GPC_MFP3_PC11MFP_EPWM1_CH1}}, 
    //D5 EPWM1_CH0
	{(EPWM_T  *)(EPWM1), (uint32_t)EPWM1_MODULE, PWM_USE_EPWM, BPWM1P0_IRQn, PWM_CHANNEL_CH0, PWM_FREQUENCY_500HZ, {GPIO_Desc_D5_Idx, SYS_GPC_MFP3_PB12MFP_EPWM1_CH0 }}, 
	//D6 EPWM0_CH1
	{(EPWM_T  *)(EPWM0), (uint32_t)EPWM0_MODULE, PWM_USE_EPWM, EPWM0P0_IRQn, PWM_CHANNEL_CH1, PWM_FREQUENCY_500HZ, {GPIO_Desc_D6_Idx , SYS_GPB_MFP1_PB4MFP_EPWM0_CH1 }}, 
    //D7 EPWM0_CH0
	{(EPWM_T  *)(EPWM0), (uint32_t)EPWM0_MODULE, PWM_USE_EPWM, EPWM0P0_IRQn, PWM_CHANNEL_CH0, PWM_FREQUENCY_500HZ, {GPIO_Desc_D7_Idx, SYS_GPB_MFP1_PB5MFP_EPWM0_CH0 }}, 
};


ADCPinDescription ADC_Desc[ADC_DESC_MAX] =
{
    //PB6, EADC0_CH6
	{EADC0, EADC0_MODULE, ADC_CHANNEL_CH6, { GPIO_Desc_A0_Idx, SYS_GPB_MFP1_PB6MFP_EADC0_CH6 }},  
    //PB7, EADC0_CH7
	{EADC0, EADC0_MODULE, ADC_CHANNEL_CH7, { GPIO_Desc_A1_Idx, SYS_GPB_MFP1_PB7MFP_EADC0_CH7 }},  
    //PB8, EADC0_CH8
	{EADC0, EADC0_MODULE, ADC_CHANNEL_CH8, { GPIO_Desc_A2_Idx, SYS_GPB_MFP3_PB8MFP_EADC0_CH8 }},  
    //PB9, EADC0_CH9
	{EADC0, EADC0_MODULE, ADC_CHANNEL_CH9, { GPIO_Desc_A3_Idx, SYS_GPB_MFP3_PB9MFP_EADC0_CH9 }},  
    //PB0, EADC0_CH0
	{EADC0, EADC0_MODULE, ADC_CHANNEL_CH0, { GPIO_Desc_A4_Idx, SYS_GPB_MFP0_PB0MFP_EADC0_CH0 }},  
	//PB1, EADC0_CH1
	{EADC0, EADC0_MODULE, ADC_CHANNEL_CH1, { GPIO_Desc_A5_Idx, SYS_GPB_MFP0_PB1MFP_EADC0_CH1 }},  
};

SPIPinDescription SPI_Desc[] =
{
    //{
    //    SPI0, (uint32_t)SPI0_MODULE, SPI0_IRQn, CLK_CLKSEL2_SPI0SEL_PCLK1,
    //    {   {28, SYS_GPA_MFP0_PA2MFP_SPI0_CLK }, {30, SYS_GPA_MFP0_PA0MFP_SPI0_MOSI},
    //        {29, SYS_GPA_MFP0_PA1MFP_SPI0_MISO}, {27, SYS_GPA_MFP0_PA3MFP_SPI0_SS  }
    //    }
    //},

};
//[2025-02-25] UART pins update done.
/*UART0, 1, 3 and 4 related pins are defined. Check pins for UART3/CANFD */
UARTPinDescription UART_Desc[] =
{
    //Nulink VCOM
    {UART0, (uint32_t)UART0_MODULE, (uint32_t)(UART_USE_UART0), UART0_IRQn, {{25, SYS_GPB_MFP3_PB12MFP_UART0_RXD }, {24, SYS_GPB_MFP3_PB13MFP_UART0_TXD  }},  CLK_UARTSEL0_UART0SEL_HIRC, UART_CLKDIV_1},   //(T/R = PA7/PA6)
    //UART1 PB2, PB3
	{UART1, (uint32_t)UART1_MODULE, (uint32_t)(UART_USE_UART1), UART1_IRQn, {{GPIO_Desc_D0_Idx, SYS_GPB_MFP0_PB2MFP_UART1_RXD }, {GPIO_Desc_D1_Idx, SYS_GPB_MFP0_PB3MFP_UART1_TXD  }},  CLK_CLKSEL1_UART1SEL_HIRC, UART_CLKDIV_1},   //(T/R = PA3/PA2)
	

	
};

//[2025-03-03] RS485 AUD
//nRTS(DE) Pin assignment
PinType DEPin_Desc[] = 
{
	//{255 , SYS_GPC_MFP1_PC6MFP_UART0_nRTS},//VCOM,  dummy, UART0_nRTS
	//{19 , SYS_GPC_MFP1_PC6MFP_UART0_nRTS},//UART0, PC6,   UART0_nRTS
    /*Left for other DE pin resource*/
	
};


//[2025-05-07] LPI2C pins updated
LPI2CPinDescription LPI2C_Desc[] =
{
    {LPI2C0, LPI2C0_MODULE, {{GPIO_Desc_D5_Idx , SYS_GPC_MFP3_PC12MFP_LPI2C0_SCL}, {GPIO_Desc_D4_Idx , SYS_GPC_MFP2_PC11MFP_LPI2C0_SDA }}},
	//{I2C2, I2C2_MODULE, {{29 , SYS_GPA_MFP0_PA1MFP_I2C2_SCL}, {30 , SYS_GPA_MFP0_PA0MFP_I2C2_SDA }}},
};


CANFDPinDescription CANFD_Desc[] =
{
    //{CANFD0, (uint32_t)CANFD0_MODULE, (uint32_t)(CANFD_USE_CANFD0), CANFD00_IRQn, {{70, SYS_GPC_MFP1_PC4MFP_CAN0_RXD },  {69, SYS_GPC_MFP1_PC5MFP_CAN0_TXD }}},//,  CLK_CLKSEL0_CANFD0SEL_HCLK, CANFD_CLKDIV_1},
    //{CANFD0, (uint32_t)CANFD0_MODULE, (uint32_t)(CANFD_USE_CANFD0), CANFD00_IRQn, {{26, SYS_GPA_MFP1_PA4MFP_CAN0_RXD },  {25, SYS_GPA_MFP1_PA5MFP_CAN0_TXD }}},//,  CLK_CLKSEL0_CANFD0SEL_HCLK, CANFD_CLKDIV_1},

};



#endif//__UNO_M55M1__
