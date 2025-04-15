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
    //{pin, type, num}//
	{ 21, UART_TYPE, 0                 },// 0:      (D0/PA6/UART_RX0)
    { 20, UART_TYPE, 0                 },// 1:      (D1/PA7/UART_TX0)
    { 19, PWM_TYPE, PWM_DESC_IDX_NOUSE }, // 2:      (D2/PC6/PWM)
    { 18, PWM_TYPE, PWM_DESC_IDX_NOUSE }, // 3:      (D3/PC7/PWM)
    { 25, PWM_TYPE, PWM_DESC_IDX_NOUSE }, // 4:      (D4/PA5/PWM)
    { 26, PWM_TYPE, PWM_DESC_IDX_NOUSE }, // 5:      (D5/PA4/PWM)
    {  8, PWM_TYPE, PWM_DESC_IDX_NOUSE }, // 6:      (D6/PA11/PWM)
    { 52, PWM_TYPE, PWM_DESC_IDX_NOUSE }, // 7:      (D7/PC14/PWM)

    {  7, PWM_TYPE, PWM_DESC_IDX2      }, // 8:      (D8/PB0/PWM)
    { 12, PWM_TYPE, PWM_DESC_IDX_NOUSE }, // 9:      (D9/PF6/PWM)
    { 27, SPI_TYPE, 0                  }, //10:      (D10/PA3/SPI0_CS)
    { 30, SPI_TYPE, 0                  }, //11:      (D11/PA0/SPI0_MOSI)
    { 29, SPI_TYPE, 0                  }, //12:      (D12/PA1/SPI0_MISO)
    { 28, SPI_TYPE, 0                  }, //13:      (D13/PA2/SPI0_SCK)
	
	{ 55, ADC_TYPE, 0                  }, //14:      (D14/PB13/A0)
    { 60, ADC_TYPE, 1                  }, //15:      (D15/PB11/A1)
    { 61, ADC_TYPE, 2                  }, //16:      (D16/PB10/A2)
    { 62, ADC_TYPE, PWM_DESC_IDX_NOUSE }, //17:      (D17/PB9/A3), PWM not testable
    { 56, I2C_TYPE, 0                  }, //18:      (D18/PB12/I2C0_SDA/A4)
    { 55, PWM_TYPE, PWM_DESC_IDX_NOUSE }, //19:      (D19/PB13/I2C0_SCL/A5), PWM not testable
 
    { -1,        0, 0}, //22: NC
    { -1,        0, 0}, //23: NC
    { -1,        0, 0}, //24: NC
    { -1,        0, 0}, //25: NC
    { -1,        0, 0}, //26: NC
    { -1,        0, 0}, //27: NC
    { -1,        0, 0}, //28: NC
    { -1,        0, 0}, //29: NC
    { -1,        0, 0}, //30: NC
    { -1,        0, 0}, //31: NC
    { -1,        0, 0}, //32: NC
    { -1,        0, 0}, //33: NC
    { -1,        0, 0}, //34: NC
    { -1,        0, 0}, //35: NC
    { -1,        0, 0}, //36: NC
    { -1,        0, 0}, //37: NC
    { -1,        0, 0}, //38: NC
    { -1,        0, 0}, //39: NC

};
#endif

/*
    Note for M55M1 Multi-Function Pins, the SYS_GPx_MFP namings as follow:
    P0~P3  : MPF0
    P4~P7  : MPF1
    P8~P11 : MPF2
    P12~P15: MPF3
*/
//[2025-02-17] GPIO pins updated
GPIOPinDescription GPIO_Desc[] =
{
    {NULL, 0, {0, 0, 0}}, //0-->0
	{PB, BIT6,  {(uint32_t) &SYS->GPB_MFP1, SYS_GPB_MFP1_PB6MFP_Msk,  SYS_GPB_MFP1_PB6MFP_GPIO}}, //1
    {PB, BIT5, {(uint32_t)  &SYS->GPB_MFP1, SYS_GPB_MFP1_PB5MFP_Msk,  SYS_GPB_MFP1_PB5MFP_GPIO}}, //2
    {PB, BIT4, {(uint32_t)  &SYS->GPB_MFP1, SYS_GPB_MFP1_PB4MFP_Msk,  SYS_GPB_MFP1_PB4MFP_GPIO}}, //3
    {PB, BIT3, {(uint32_t)  &SYS->GPB_MFP0, SYS_GPB_MFP0_PB3MFP_Msk,  SYS_GPB_MFP0_PB3MFP_GPIO}}, //4
    {PB, BIT2, {(uint32_t)  &SYS->GPB_MFP0, SYS_GPB_MFP0_PB2MFP_Msk,  SYS_GPB_MFP0_PB2MFP_GPIO }}, //5
	{PB, BIT1, {(uint32_t)  &SYS->GPB_MFP0, SYS_GPB_MFP0_PB1MFP_Msk,  SYS_GPB_MFP0_PB1MFP_GPIO}}, //6
    {PB, BIT0, {(uint32_t)  &SYS->GPB_MFP0, SYS_GPB_MFP0_PB0MFP_Msk,  SYS_GPB_MFP0_PB0MFP_GPIO }}, //7
	{PA, BIT11, {(uint32_t) &SYS->GPA_MFP2, SYS_GPA_MFP2_PA11MFP_Msk, SYS_GPA_MFP2_PA11MFP_GPIO }}, //8
	{PA, BIT10, {(uint32_t) &SYS->GPA_MFP2, SYS_GPA_MFP2_PA10MFP_Msk, SYS_GPA_MFP2_PA10MFP_GPIO }}, //9
	{PA, BIT9, {(uint32_t)  &SYS->GPA_MFP2, SYS_GPA_MFP2_PA9MFP_Msk,  SYS_GPA_MFP2_PA9MFP_GPIO }}, //10
    {PA, BIT8, {(uint32_t)  &SYS->GPA_MFP2, SYS_GPA_MFP2_PA8MFP_Msk,  SYS_GPA_MFP2_PA8MFP_GPIO }}, //11
    {PF, BIT6, {(uint32_t)  &SYS->GPF_MFP1, SYS_GPF_MFP1_PF6MFP_Msk, SYS_GPF_MFP1_PF6MFP_GPIO }}, //12
	{NULL, 0, {0, 0, 0}},//13, VBat
    {PF, BIT5, {(uint32_t)  &SYS->GPF_MFP1, SYS_GPF_MFP1_PF5MFP_Msk, SYS_GPF_MFP1_PF5MFP_GPIO }}, //14
    {PF, BIT4, {(uint32_t)  &SYS->GPF_MFP1, SYS_GPF_MFP1_PF4MFP_Msk, SYS_GPF_MFP1_PF4MFP_GPIO }}, //15
    {PF, BIT3, {(uint32_t)  &SYS->GPF_MFP0, SYS_GPF_MFP0_PF3MFP_Msk, SYS_GPF_MFP0_PF3MFP_GPIO }}, //16
    {PF, BIT2, {(uint32_t)  &SYS->GPF_MFP0, SYS_GPF_MFP0_PF2MFP_Msk, SYS_GPF_MFP0_PF2MFP_GPIO }}, //17
    {PC, BIT7, {(uint32_t)  &SYS->GPC_MFP1, SYS_GPC_MFP1_PC7MFP_Msk, SYS_GPC_MFP1_PC7MFP_GPIO }}, //18
    {PC, BIT6, {(uint32_t)  &SYS->GPC_MFP1, SYS_GPC_MFP1_PC6MFP_Msk, SYS_GPC_MFP1_PC6MFP_GPIO }}, //19
    {PA, BIT7, {(uint32_t)  &SYS->GPA_MFP1, SYS_GPA_MFP1_PA7MFP_Msk, SYS_GPA_MFP1_PA7MFP_GPIO }}, //20
    {PA, BIT6, {(uint32_t)  &SYS->GPA_MFP1, SYS_GPA_MFP1_PA6MFP_Msk, SYS_GPA_MFP1_PA6MFP_GPIO }}, //21
	{NULL, 0, {0, 0, 0}}, //22, Vdd
    {NULL, 0, {0, 0, 0}}, //23, Vss
    {NULL, 0, {0, 0, 0}}, //24, LDO cap
	{PA, BIT5, {(uint32_t) &SYS->GPA_MFP1, SYS_GPA_MFP1_PA5MFP_Msk, SYS_GPA_MFP1_PA5MFP_GPIO }}, //25
    {PA, BIT4, {(uint32_t) &SYS->GPA_MFP1, SYS_GPA_MFP1_PA4MFP_Msk, SYS_GPA_MFP1_PA4MFP_GPIO }}, //26
    {PA, BIT3, {(uint32_t) &SYS->GPA_MFP0, SYS_GPA_MFP0_PA3MFP_Msk, SYS_GPA_MFP0_PA3MFP_GPIO }}, //27
    {PA, BIT2, {(uint32_t) &SYS->GPA_MFP0, SYS_GPA_MFP0_PA2MFP_Msk, SYS_GPA_MFP0_PA2MFP_GPIO }}, //28
    {PA, BIT1, {(uint32_t) &SYS->GPA_MFP0, SYS_GPA_MFP0_PA1MFP_Msk, SYS_GPA_MFP0_PA1MFP_GPIO }}, //29
    {PA, BIT0, {(uint32_t) &SYS->GPA_MFP0, SYS_GPA_MFP0_PA0MFP_Msk, SYS_GPA_MFP0_PA0MFP_GPIO }}, //30
    {NULL, 0, {0, 0, 0}}, //31, Vddio
	{NULL, 0, {0, 0, 0}}, //32, nRst
	{PF, BIT0, {(uint32_t) &SYS->GPF_MFP0, SYS_GPF_MFP0_PF0MFP_Msk, SYS_GPF_MFP0_PF0MFP_GPIO }}, //33
    {PF, BIT1, {(uint32_t) &SYS->GPF_MFP0, SYS_GPF_MFP0_PF1MFP_Msk, SYS_GPF_MFP0_PF1MFP_GPIO }}, //34
    {PC, BIT5, {(uint32_t) &SYS->GPC_MFP1, SYS_GPC_MFP1_PC5MFP_Msk, SYS_GPC_MFP1_PC5MFP_GPIO }}, //35
    {PC, BIT4, {(uint32_t) &SYS->GPC_MFP1, SYS_GPC_MFP1_PC4MFP_Msk, SYS_GPC_MFP1_PC4MFP_GPIO }}, //36
	{PA, BIT12, {(uint32_t) &SYS->GPA_MFP3, SYS_GPA_MFP3_PA12MFP_Msk, SYS_GPA_MFP3_PA12MFP_GPIO }}, //37
	{PA, BIT13, {(uint32_t) &SYS->GPA_MFP3, SYS_GPA_MFP3_PA13MFP_Msk, SYS_GPA_MFP3_PA13MFP_GPIO }}, //38
	{PA, BIT14, {(uint32_t) &SYS->GPA_MFP3, SYS_GPA_MFP3_PA14MFP_Msk, SYS_GPA_MFP3_PA14MFP_GPIO }}, //39
	{PA, BIT15, {(uint32_t) &SYS->GPA_MFP3, SYS_GPA_MFP3_PA15MFP_Msk, SYS_GPA_MFP3_PA15MFP_GPIO }}, //40
	{NULL, 0, {0, 0, 0}}, //41 
    {NULL, 0, {0, 0, 0}}, //42
    {NULL, 0, {0, 0, 0}}, //43
    {NULL, 0, {0, 0, 0}}, //44
    {NULL, 0, {0, 0, 0}}, //45
    {NULL, 0, {0, 0, 0}}, //46
    {NULL, 0, {0, 0, 0}}, //47
	{NULL, 0, {0, 0, 0}}, //48
	{NULL, 0, {0, 0, 0}}, //49
	{NULL, 0, {0, 0, 0}}, //50
	{NULL, 0, {0, 0, 0}}, //51
	    
	{PC, BIT14, {(uint32_t) &SYS->GPC_MFP3, SYS_GPC_MFP3_PC14MFP_Msk, SYS_GPC_MFP3_PC14MFP_GPIO }}, //52
    {PB, BIT15, {(uint32_t) &SYS->GPB_MFP3, SYS_GPB_MFP3_PB15MFP_Msk, SYS_GPB_MFP3_PB15MFP_GPIO }}, //53
    {PB, BIT14, {(uint32_t) &SYS->GPB_MFP3, SYS_GPB_MFP3_PB14MFP_Msk, SYS_GPB_MFP3_PB14MFP_GPIO }}, //54
    {PB, BIT13, {(uint32_t) &SYS->GPB_MFP3, SYS_GPB_MFP3_PB13MFP_Msk, SYS_GPB_MFP3_PB13MFP_GPIO }}, //55
    {PB, BIT12, {(uint32_t) &SYS->GPB_MFP3, SYS_GPB_MFP3_PB12MFP_Msk, SYS_GPB_MFP3_PB12MFP_GPIO }}, //56
	
	{NULL, 0, {0, 0, 0}}, //57
	{NULL, 0, {0, 0, 0}}, //58
	{NULL, 0, {0, 0, 0}}, //59
	
	{PB, BIT11, {(uint32_t) &SYS->GPB_MFP2, SYS_GPB_MFP2_PB11MFP_Msk, SYS_GPB_MFP2_PB11MFP_GPIO }}, //60
    {PB, BIT10, {(uint32_t) &SYS->GPB_MFP2, SYS_GPB_MFP2_PB10MFP_Msk, SYS_GPB_MFP2_PB10MFP_GPIO }}, //61
    {PB, BIT9,  {(uint32_t) &SYS->GPB_MFP2, SYS_GPB_MFP2_PB9MFP_Msk,  SYS_GPB_MFP2_PB9MFP_GPIO  }}, //62
    {PB, BIT8,  {(uint32_t) &SYS->GPB_MFP2, SYS_GPB_MFP2_PB8MFP_Msk,  SYS_GPB_MFP2_PB8MFP_GPIO  }}, //63
    {PB, BIT7,  {(uint32_t) &SYS->GPB_MFP1, SYS_GPB_MFP1_PB7MFP_Msk,  SYS_GPB_MFP1_PB7MFP_GPIO  }}, //64

   
};

EPWMPinDescription PWM_Desc[] = 
{
    {(EPWM_T  *)(EPWM1), (uint32_t)EPWM1_MODULE, PWM_USE_EPWM, EPWM1P0_IRQn, PWM_CHANNEL_CH2, PWM_FREQUENCY_500HZ, {55, SYS_GPB_MFP3_PB13MFP_EPWM1_CH2}}, //D14  PB13,EPWM1_CH2 
    {(EPWM_T  *)(BPWM1), (uint32_t)BPWM1_MODULE, PWM_USE_BPWM, BPWM1_IRQn,   PWM_CHANNEL_CH2, PWM_FREQUENCY_500HZ, {62, SYS_GPB_MFP2_PB9MFP_BPWM1_CH2 }}, //D17  PB9, BPWM1_CH2
	{(EPWM_T  *)(EPWM0), (uint32_t)EPWM0_MODULE, PWM_USE_EPWM, EPWM0P0_IRQn, PWM_CHANNEL_CH5, PWM_FREQUENCY_500HZ, { 7, SYS_GPB_MFP0_PB0MFP_EPWM0_CH5 }}, //D0   PB0, EPWM0_CH5
  
};

//[2025-02-25] ADC pins update done. 
ADCPinDescription ADC_Desc[] =
{
    {EADC0, EADC0_MODULE, ADC_CHANNEL_CH13, { 55, SYS_GPB_MFP3_PB13MFP_EADC0_CH13 }},  //A0 PB13(EADC0_CH13, 10b)
    {EADC0, EADC0_MODULE, ADC_CHANNEL_CH11, { 60, SYS_GPB_MFP2_PB11MFP_EADC0_CH11 }},  //A1 PB11(EADC0_CH11, 10b)
    {EADC0, EADC0_MODULE, ADC_CHANNEL_CH10, { 61, SYS_GPB_MFP2_PB10MFP_EADC0_CH10 }},  //A2 PB10(EADC0_CH10, 10b)
    {EADC0, EADC0_MODULE, ADC_CHANNEL_CH9,  { 62, SYS_GPB_MFP2_PB9MFP_EADC0_CH9   }},  //A3 PB9 (EADC_0CH9,  10b)
    {EADC0, EADC0_MODULE, ADC_CHANNEL_CH12, { 56, SYS_GPB_MFP3_PB12MFP_EADC0_CH12 }},  //A4 PB12(EADC0_CH12, 10b)
	{EADC0, EADC0_MODULE, ADC_CHANNEL_CH0,  {  7, SYS_GPB_MFP0_PB0MFP_EADC0_CH0   }},  //A5 PB0 (EADC0_CH0,  10b) for test
};
//[2025-02-18] SPI0 pins updated
SPIPinDescription SPI_Desc[] =
{
    {
        SPI0, (uint32_t)SPI0_MODULE, SPI0_IRQn, CLK_CLKSEL2_SPI0SEL_PCLK1,
        {   {28, SYS_GPA_MFP0_PA2MFP_SPI0_CLK }, {30, SYS_GPA_MFP0_PA0MFP_SPI0_MOSI},
            {29, SYS_GPA_MFP0_PA1MFP_SPI0_MISO}, {27, SYS_GPA_MFP0_PA3MFP_SPI0_SS  }
        }
    },

};
//[2025-02-25] UART pins update done.
/*UART0, 1, 3 and 4 related pins are defined. Check pins for UART3/CANFD */
UARTPinDescription UART_Desc[] =
{
#if defined(__M460MINIMA__)
    {(UART_T *)(0),  (uint32_t)(0), (uint32_t)(UART_USE_VCOM), (IRQn_Type)(0), {{255, (uint32_t)(0) },               {255, (uint32_t)(0) }}              ,  (uint32_t)(0)            , UART_CLKDIV_1},   //(USE VCOM)
	{UART0, (uint32_t)UART0_MODULE, (uint32_t)(UART_USE_UART0), UART0_IRQn, {{21, SYS_GPA_MFP1_PA6MFP_UART0_RXD },  {20, SYS_GPA_MFP1_PA7MFP_UART0_TXD }},  CLK_CLKSEL1_UART0SEL_HIRC, UART_CLKDIV_1},   //(T/R = PA7/PA6)
    {UART1, (uint32_t)UART1_MODULE, (uint32_t)(UART_USE_UART1), UART1_IRQn, {{28, SYS_GPA_MFP0_PA2MFP_UART1_RXD  }, {27, SYS_GPA_MFP0_PA3MFP_UART1_TXD }},  CLK_CLKSEL1_UART1SEL_HIRC, UART_CLKDIV_1},   //(T/R = PA3/PA2)
#else
    {UART0, (uint32_t)UART0_MODULE, (uint32_t)(UART_USE_UART0), UART0_IRQn, {{21, SYS_GPA_MFP1_PA6MFP_UART0_RXD }, {20, SYS_GPA_MFP1_PA7MFP_UART0_TXD  }},  CLK_CLKSEL1_UART0SEL_HIRC, UART_CLKDIV_1},   //(T/R = PA7/PA6)
    {UART1, (uint32_t)UART1_MODULE, (uint32_t)(UART_USE_UART1), UART1_IRQn, {{28, SYS_GPA_MFP0_PA2MFP_UART1_RXD }, {27, SYS_GPA_MFP0_PA3MFP_UART1_TXD  }},  CLK_CLKSEL1_UART1SEL_HIRC, UART_CLKDIV_1},   //(T/R = PA3/PA2)
	{UART3, (uint32_t)UART3_MODULE, (uint32_t)(UART_USE_UART3), UART3_IRQn, {{100, SYS_GPB_MFP3_PB12MFP_UART0_RXD  }, { 100 , SYS_GPB_MFP3_PB13MFP_UART0_TXD }},  CLK_CLKSEL3_UART3SEL_HIRC, UART_CLKDIV_1},   //
#endif
	
};

//[2025-03-03] RS485 AUD
//nRTS(DE) Pin assignment
PinType DEPin_Desc[] = 
{
	{255 , SYS_GPC_MFP1_PC6MFP_UART0_nRTS},//VCOM,  dummy, UART0_nRTS
	{19 , SYS_GPC_MFP1_PC6MFP_UART0_nRTS},//UART0, PC6,   UART0_nRTS
    /*Left for other DE pin resource*/
	
};


//[2025-02-18] I2C pins updated
I2CPinDescription I2C_Desc[] =
{
    {I2C1, I2C1_MODULE, {{33 , SYS_GPF_MFP0_PF0MFP_I2C1_SCL}, {34 , SYS_GPF_MFP0_PF1MFP_I2C1_SDA }}},
	{I2C2, I2C2_MODULE, {{29 , SYS_GPA_MFP0_PA1MFP_I2C2_SCL}, {30 , SYS_GPA_MFP0_PA0MFP_I2C2_SDA }}},
};


CANFDPinDescription CANFD_Desc[] =
{
    //{CANFD0, (uint32_t)CANFD0_MODULE, (uint32_t)(CANFD_USE_CANFD0), CANFD00_IRQn, {{70, SYS_GPC_MFP1_PC4MFP_CAN0_RXD },  {69, SYS_GPC_MFP1_PC5MFP_CAN0_TXD }}},//,  CLK_CLKSEL0_CANFD0SEL_HCLK, CANFD_CLKDIV_1},
    {CANFD0, (uint32_t)CANFD0_MODULE, (uint32_t)(CANFD_USE_CANFD0), CANFD00_IRQn, {{26, SYS_GPA_MFP1_PA4MFP_CAN0_RXD },  {25, SYS_GPA_MFP1_PA5MFP_CAN0_TXD }}},//,  CLK_CLKSEL0_CANFD0SEL_HCLK, CANFD_CLKDIV_1},
	
	
};



#endif//__UNO_M55M1__
