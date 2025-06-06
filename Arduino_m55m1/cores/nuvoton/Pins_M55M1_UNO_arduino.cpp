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
    {NULL, 0, {0, 0, 0}}, //0
	{PB, BIT5, {(uint32_t) &SYS->GPB_MFP1, SYS_GPB_MFP1_PB5MFP_Msk, SYS_GPB_MFP1_PB5MFP_GPIO}},    // Pin 1: PB.5
    {PB, BIT4, {(uint32_t) &SYS->GPB_MFP1, SYS_GPB_MFP1_PB4MFP_Msk, SYS_GPB_MFP1_PB4MFP_GPIO}},    // Pin 2: PB.4
    {PB, BIT3, {(uint32_t) &SYS->GPB_MFP0, SYS_GPB_MFP0_PB3MFP_Msk, SYS_GPB_MFP0_PB3MFP_GPIO}},    // Pin 3: PB.3
    {PB, BIT2, {(uint32_t) &SYS->GPB_MFP0, SYS_GPB_MFP0_PB2MFP_Msk, SYS_GPB_MFP0_PB2MFP_GPIO}},    // Pin 4: PB.2
    {PC, BIT12, {(uint32_t) &SYS->GPC_MFP3, SYS_GPC_MFP3_PC12MFP_Msk, SYS_GPC_MFP3_PC12MFP_GPIO}}, // Pin 5: PC.12
    {PC, BIT11, {(uint32_t) &SYS->GPC_MFP2, SYS_GPC_MFP2_PC11MFP_Msk, SYS_GPC_MFP2_PC11MFP_GPIO}}, // Pin 6: PC.11
    {PC, BIT10, {(uint32_t) &SYS->GPC_MFP2, SYS_GPC_MFP2_PC10MFP_Msk, SYS_GPC_MFP2_PC10MFP_GPIO}}, // Pin 7: PC.10
    {PC, BIT9, {(uint32_t) &SYS->GPC_MFP2, SYS_GPC_MFP2_PC9MFP_Msk, SYS_GPC_MFP2_PC9MFP_GPIO}},    // Pin 8: PC.9
    {PB, BIT1, {(uint32_t) &SYS->GPB_MFP0, SYS_GPB_MFP0_PB1MFP_Msk, SYS_GPB_MFP0_PB1MFP_GPIO}},    // Pin 9: PB.1
    {PB, BIT0, {(uint32_t) &SYS->GPB_MFP0, SYS_GPB_MFP0_PB0MFP_Msk, SYS_GPB_MFP0_PB0MFP_GPIO}},    // Pin 10: PB.0
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 11: VSS
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 12: VDD
    {PA, BIT11, {(uint32_t) &SYS->GPA_MFP2, SYS_GPA_MFP2_PA11MFP_Msk, SYS_GPA_MFP2_PA11MFP_GPIO}}, // Pin 13: PA.11
    {PA, BIT10, {(uint32_t) &SYS->GPA_MFP2, SYS_GPA_MFP2_PA10MFP_Msk, SYS_GPA_MFP2_PA10MFP_GPIO}}, // Pin 14: PA.10
    {PA, BIT9, {(uint32_t) &SYS->GPA_MFP2, SYS_GPA_MFP2_PA9MFP_Msk, SYS_GPA_MFP2_PA9MFP_GPIO}},    // Pin 15: PA.9
    {PA, BIT8, {(uint32_t) &SYS->GPA_MFP2, SYS_GPA_MFP2_PA8MFP_Msk, SYS_GPA_MFP2_PA8MFP_GPIO}},    // Pin 16: PA.8
    {PC, BIT13, {(uint32_t) &SYS->GPC_MFP3, SYS_GPC_MFP3_PC13MFP_Msk, SYS_GPC_MFP3_PC13MFP_GPIO}}, // Pin 17: PC.13
    {PD, BIT12, {(uint32_t) &SYS->GPD_MFP3, SYS_GPD_MFP3_PD12MFP_Msk, SYS_GPD_MFP3_PD12MFP_GPIO}}, // Pin 18: PD.12
    {PD, BIT11, {(uint32_t) &SYS->GPD_MFP2, SYS_GPD_MFP2_PD11MFP_Msk, SYS_GPD_MFP2_PD11MFP_GPIO}}, // Pin 19: PD.11
    {PD, BIT10, {(uint32_t) &SYS->GPD_MFP2, SYS_GPD_MFP2_PD10MFP_Msk, SYS_GPD_MFP2_PD10MFP_GPIO}}, // Pin 20: PD.10
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 21: VSS
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 22: VDD
    {PG, BIT0, {(uint32_t) &SYS->GPG_MFP0, SYS_GPG_MFP0_PG0MFP_Msk, SYS_GPG_MFP0_PG0MFP_GPIO}},    // Pin 23: PG.0
    {PG, BIT1, {(uint32_t) &SYS->GPG_MFP0, SYS_GPG_MFP0_PG1MFP_Msk, SYS_GPG_MFP0_PG1MFP_GPIO}},    // Pin 24: PG.1
    {PG, BIT2, {(uint32_t) &SYS->GPG_MFP0, SYS_GPG_MFP0_PG2MFP_Msk, SYS_GPG_MFP0_PG2MFP_GPIO}},    // Pin 25: PG.2
    {PG, BIT3, {(uint32_t) &SYS->GPG_MFP0, SYS_GPG_MFP0_PG3MFP_Msk, SYS_GPG_MFP0_PG3MFP_GPIO}},    // Pin 26: PG.3
    {PG, BIT4, {(uint32_t) &SYS->GPG_MFP1, SYS_GPG_MFP1_PG4MFP_Msk, SYS_GPG_MFP1_PG4MFP_GPIO}},    // Pin 27: PG.4
    {PI, BIT6, {(uint32_t) &SYS->GPI_MFP1, SYS_GPI_MFP1_PI6MFP_Msk, SYS_GPI_MFP1_PI6MFP_GPIO}},    // Pin 28: PI.6
    {PI, BIT7, {(uint32_t) &SYS->GPI_MFP1, SYS_GPI_MFP1_PI7MFP_Msk, SYS_GPI_MFP1_PI7MFP_GPIO}},    // Pin 29: PI.7
    {PI, BIT8, {(uint32_t) &SYS->GPI_MFP2, SYS_GPI_MFP2_PI8MFP_Msk, SYS_GPI_MFP2_PI8MFP_GPIO}},    // Pin 30: PI.8
    {PI, BIT9, {(uint32_t) &SYS->GPI_MFP2, SYS_GPI_MFP2_PI9MFP_Msk, SYS_GPI_MFP2_PI9MFP_GPIO}},    // Pin 31: PI.9
    {PI, BIT10, {(uint32_t) &SYS->GPI_MFP2, SYS_GPI_MFP2_PI10MFP_Msk, SYS_GPI_MFP2_PI10MFP_GPIO}}, // Pin 32: PI.10
    {PI, BIT11, {(uint32_t) &SYS->GPI_MFP2, SYS_GPI_MFP2_PI11MFP_Msk, SYS_GPI_MFP2_PI11MFP_GPIO}}, // Pin 33: PI.11
    {PF, BIT11, {(uint32_t) &SYS->GPF_MFP2, SYS_GPF_MFP2_PF11MFP_Msk, SYS_GPF_MFP2_PF11MFP_GPIO}}, // Pin 34: PF.11
    {PF, BIT10, {(uint32_t) &SYS->GPF_MFP2, SYS_GPF_MFP2_PF10MFP_Msk, SYS_GPF_MFP2_PF10MFP_GPIO}}, // Pin 35: PF.10
    {PF, BIT9, {(uint32_t) &SYS->GPF_MFP2, SYS_GPF_MFP2_PF9MFP_Msk, SYS_GPF_MFP2_PF9MFP_GPIO}},    // Pin 36: PF.9
    {PF, BIT8, {(uint32_t) &SYS->GPF_MFP2, SYS_GPF_MFP2_PF8MFP_Msk, SYS_GPF_MFP2_PF8MFP_GPIO}},    // Pin 37: PF.8
    {PF, BIT7, {(uint32_t) &SYS->GPF_MFP1, SYS_GPF_MFP1_PF7MFP_Msk, SYS_GPF_MFP1_PF7MFP_GPIO}},    // Pin 38: PF.7
    {PF, BIT6, {(uint32_t) &SYS->GPF_MFP1, SYS_GPF_MFP1_PF6MFP_Msk, SYS_GPF_MFP1_PF6MFP_GPIO}},    // Pin 39: PF.6
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 40: VBAT
    {PF, BIT5, {(uint32_t) &SYS->GPF_MFP1, SYS_GPF_MFP1_PF5MFP_Msk, SYS_GPF_MFP1_PF5MFP_GPIO}},    // Pin 41: PF.5
    {PF, BIT4, {(uint32_t) &SYS->GPF_MFP1, SYS_GPF_MFP1_PF4MFP_Msk, SYS_GPF_MFP1_PF4MFP_GPIO}},    // Pin 42: PF.4
    {PH, BIT0, {(uint32_t) &SYS->GPH_MFP0, SYS_GPH_MFP0_PH0MFP_Msk, SYS_GPH_MFP0_PH0MFP_GPIO}},    // Pin 43: PH.0
    {PH, BIT1, {(uint32_t) &SYS->GPH_MFP0, SYS_GPH_MFP0_PH1MFP_Msk, SYS_GPH_MFP0_PH1MFP_GPIO}},    // Pin 44: PH.1
    {PH, BIT2, {(uint32_t) &SYS->GPH_MFP0, SYS_GPH_MFP0_PH2MFP_Msk, SYS_GPH_MFP0_PH2MFP_GPIO}},    // Pin 45: PH.2
    {PH, BIT3, {(uint32_t) &SYS->GPH_MFP0, SYS_GPH_MFP0_PH3MFP_Msk, SYS_GPH_MFP0_PH3MFP_GPIO}},    // Pin 46: PH.3
    {PH, BIT4, {(uint32_t) &SYS->GPH_MFP1, SYS_GPH_MFP1_PH4MFP_Msk, SYS_GPH_MFP1_PH4MFP_GPIO}},    // Pin 47: PH.4
    {PH, BIT5, {(uint32_t) &SYS->GPH_MFP1, SYS_GPH_MFP1_PH5MFP_Msk, SYS_GPH_MFP1_PH5MFP_GPIO}},    // Pin 48: PH.5
    {PH, BIT6, {(uint32_t) &SYS->GPH_MFP1, SYS_GPH_MFP1_PH6MFP_Msk, SYS_GPH_MFP1_PH6MFP_GPIO}},    // Pin 49: PH.6
    {PH, BIT7, {(uint32_t) &SYS->GPH_MFP1, SYS_GPH_MFP1_PH7MFP_Msk, SYS_GPH_MFP1_PH7MFP_GPIO}},    // Pin 50: PH.7
    {PF, BIT3, {(uint32_t) &SYS->GPF_MFP0, SYS_GPF_MFP0_PF3MFP_Msk, SYS_GPF_MFP0_PF3MFP_GPIO}},    // Pin 51: PF.3
    {PF, BIT2, {(uint32_t) &SYS->GPF_MFP0, SYS_GPF_MFP0_PF2MFP_Msk, SYS_GPF_MFP0_PF2MFP_GPIO}},    // Pin 52: PF.2
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 53: VSS
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 54: VDD
    {PE, BIT8, {(uint32_t) &SYS->GPE_MFP2, SYS_GPE_MFP2_PE8MFP_Msk, SYS_GPE_MFP2_PE8MFP_GPIO}},    // Pin 55: PE.8
    {PE, BIT9, {(uint32_t) &SYS->GPE_MFP2, SYS_GPE_MFP2_PE9MFP_Msk, SYS_GPE_MFP2_PE9MFP_GPIO}},    // Pin 56: PE.9
    {PE, BIT10, {(uint32_t) &SYS->GPE_MFP2, SYS_GPE_MFP2_PE10MFP_Msk, SYS_GPE_MFP2_PE10MFP_GPIO}}, // Pin 57: PE.10
    {PE, BIT11, {(uint32_t) &SYS->GPE_MFP2, SYS_GPE_MFP2_PE11MFP_Msk, SYS_GPE_MFP2_PE11MFP_GPIO}}, // Pin 58: PE.11
    {PE, BIT12, {(uint32_t) &SYS->GPE_MFP3, SYS_GPE_MFP3_PE12MFP_Msk, SYS_GPE_MFP3_PE12MFP_GPIO}}, // Pin 59: PE.12
    {PE, BIT13, {(uint32_t) &SYS->GPE_MFP3, SYS_GPE_MFP3_PE13MFP_Msk, SYS_GPE_MFP3_PE13MFP_GPIO}}, // Pin 60: PE.13
    {PC, BIT8, {(uint32_t) &SYS->GPC_MFP2, SYS_GPC_MFP2_PC8MFP_Msk, SYS_GPC_MFP2_PC8MFP_GPIO}},    // Pin 61: PC.8
    {PC, BIT7, {(uint32_t) &SYS->GPC_MFP1, SYS_GPC_MFP1_PC7MFP_Msk, SYS_GPC_MFP1_PC7MFP_GPIO}},    // Pin 62: PC.7
    {PC, BIT6, {(uint32_t) &SYS->GPC_MFP1, SYS_GPC_MFP1_PC6MFP_Msk, SYS_GPC_MFP1_PC6MFP_GPIO}},    // Pin 63: PC.6
    {PA, BIT7, {(uint32_t) &SYS->GPA_MFP1, SYS_GPA_MFP1_PA7MFP_Msk, SYS_GPA_MFP1_PA7MFP_GPIO}},    // Pin 64: PA.7
    {PA, BIT6, {(uint32_t) &SYS->GPA_MFP1, SYS_GPA_MFP1_PA6MFP_Msk, SYS_GPA_MFP1_PA6MFP_GPIO}},    // Pin 65: PA.6
    {PI, BIT12, {(uint32_t) &SYS->GPI_MFP3, SYS_GPI_MFP3_PI12MFP_Msk, SYS_GPI_MFP3_PI12MFP_GPIO}}, // Pin 66: PI.12
    {PI, BIT13, {(uint32_t) &SYS->GPI_MFP3, SYS_GPI_MFP3_PI13MFP_Msk, SYS_GPI_MFP3_PI13MFP_GPIO}}, // Pin 67: PI.13
    {PI, BIT14, {(uint32_t) &SYS->GPI_MFP3, SYS_GPI_MFP3_PI14MFP_Msk, SYS_GPI_MFP3_PI14MFP_GPIO}}, // Pin 68: PI.14
    {PI, BIT15, {(uint32_t) &SYS->GPI_MFP3, SYS_GPI_MFP3_PI15MFP_Msk, SYS_GPI_MFP3_PI15MFP_GPIO}}, // Pin 69: PI.15
    {PJ, BIT0, {(uint32_t) &SYS->GPJ_MFP0, SYS_GPJ_MFP0_PJ0MFP_Msk, SYS_GPJ_MFP0_PJ0MFP_GPIO}},    // Pin 70: PJ.0
    {PJ, BIT1, {(uint32_t) &SYS->GPJ_MFP0, SYS_GPJ_MFP0_PJ1MFP_Msk, SYS_GPJ_MFP0_PJ1MFP_GPIO}},    // Pin 71: PJ.1
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 72: VSS
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 73: VDD
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 74: NC
    {PA, BIT5, {(uint32_t) &SYS->GPA_MFP1, SYS_GPA_MFP1_PA5MFP_Msk, SYS_GPA_MFP1_PA5MFP_GPIO}},    // Pin 75: PA.5
    {PA, BIT4, {(uint32_t) &SYS->GPA_MFP1, SYS_GPA_MFP1_PA4MFP_Msk, SYS_GPA_MFP1_PA4MFP_GPIO}},    // Pin 76: PA.4
    {PA, BIT3, {(uint32_t) &SYS->GPA_MFP0, SYS_GPA_MFP0_PA3MFP_Msk, SYS_GPA_MFP0_PA3MFP_GPIO}},    // Pin 77: PA.3
    {PA, BIT2, {(uint32_t) &SYS->GPA_MFP0, SYS_GPA_MFP0_PA2MFP_Msk, SYS_GPA_MFP0_PA2MFP_GPIO}},    // Pin 78: PA.2
    {PA, BIT1, {(uint32_t) &SYS->GPA_MFP0, SYS_GPA_MFP0_PA1MFP_Msk, SYS_GPA_MFP0_PA1MFP_GPIO}},    // Pin 79: PA.1
    {PA, BIT0, {(uint32_t) &SYS->GPA_MFP0, SYS_GPA_MFP0_PA0MFP_Msk, SYS_GPA_MFP0_PA0MFP_GPIO}},    // Pin 80: PA.0
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 81: VDDIO0
    {PE, BIT14, {(uint32_t) &SYS->GPE_MFP3, SYS_GPE_MFP3_PE14MFP_Msk, SYS_GPE_MFP3_PE14MFP_GPIO}}, // Pin 82: PE.14
    {PE, BIT15, {(uint32_t) &SYS->GPE_MFP3, SYS_GPE_MFP3_PE15MFP_Msk, SYS_GPE_MFP3_PE15MFP_GPIO}}, // Pin 83: PE.15
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 84: nRESET
    {PF, BIT0, {(uint32_t) &SYS->GPF_MFP0, SYS_GPF_MFP0_PF0MFP_Msk, SYS_GPF_MFP0_PF0MFP_GPIO}},    // Pin 85: PF.0
    {PF, BIT1, {(uint32_t) &SYS->GPF_MFP0, SYS_GPF_MFP0_PF1MFP_Msk, SYS_GPF_MFP0_PF1MFP_GPIO}},    // Pin 86: PF.1
    {PD, BIT9, {(uint32_t) &SYS->GPD_MFP2, SYS_GPD_MFP2_PD9MFP_Msk, SYS_GPD_MFP2_PD9MFP_GPIO}},    // Pin 87: PD.9
    {PD, BIT8, {(uint32_t) &SYS->GPD_MFP2, SYS_GPD_MFP2_PD8MFP_Msk, SYS_GPD_MFP2_PD8MFP_GPIO}},    // Pin 88: PD.8
    {PC, BIT5, {(uint32_t) &SYS->GPC_MFP1, SYS_GPC_MFP1_PC5MFP_Msk, SYS_GPC_MFP1_PC5MFP_GPIO}},    // Pin 89: PC.5
    {PC, BIT4, {(uint32_t) &SYS->GPC_MFP1, SYS_GPC_MFP1_PC4MFP_Msk, SYS_GPC_MFP1_PC4MFP_GPIO}},    // Pin 90: PC.4
    {PC, BIT3, {(uint32_t) &SYS->GPC_MFP0, SYS_GPC_MFP0_PC3MFP_Msk, SYS_GPC_MFP0_PC3MFP_GPIO}},    // Pin 91: PC.3
    {PC, BIT2, {(uint32_t) &SYS->GPC_MFP0, SYS_GPC_MFP0_PC2MFP_Msk, SYS_GPC_MFP0_PC2MFP_GPIO}},    // Pin 92: PC.2
    {PC, BIT1, {(uint32_t) &SYS->GPC_MFP0, SYS_GPC_MFP0_PC1MFP_Msk, SYS_GPC_MFP0_PC1MFP_GPIO}},    // Pin 93: PC.1
    {PC, BIT0, {(uint32_t) &SYS->GPC_MFP0, SYS_GPC_MFP0_PC0MFP_Msk, SYS_GPC_MFP0_PC0MFP_GPIO}},    // Pin 94: PC.0
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 95: VSS
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 96: VDD
    {PG, BIT9, {(uint32_t) &SYS->GPG_MFP2, SYS_GPG_MFP2_PG9MFP_Msk, SYS_GPG_MFP2_PG9MFP_GPIO}},    // Pin 97: PG.9
    {PG, BIT10, {(uint32_t) &SYS->GPG_MFP2, SYS_GPG_MFP2_PG10MFP_Msk, SYS_GPG_MFP2_PG10MFP_GPIO}},// Pin 98: PG.10
    {PG, BIT11, {(uint32_t) &SYS->GPG_MFP2, SYS_GPG_MFP2_PG11MFP_Msk, SYS_GPG_MFP2_PG11MFP_GPIO}},// Pin 99: PG.11
    {PG, BIT12, {(uint32_t) &SYS->GPG_MFP3, SYS_GPG_MFP3_PG12MFP_Msk, SYS_GPG_MFP3_PG12MFP_GPIO}},// Pin 100: PG.12
    {PD, BIT7, {(uint32_t) &SYS->GPD_MFP1, SYS_GPD_MFP1_PD7MFP_Msk, SYS_GPD_MFP1_PD7MFP_GPIO}},    // Pin 101: PD.7
    {PD, BIT6, {(uint32_t) &SYS->GPD_MFP1, SYS_GPD_MFP1_PD6MFP_Msk, SYS_GPD_MFP1_PD6MFP_GPIO}},    // Pin 102: PD.6
    {PD, BIT5, {(uint32_t) &SYS->GPD_MFP1, SYS_GPD_MFP1_PD5MFP_Msk, SYS_GPD_MFP1_PD5MFP_GPIO}},    // Pin 103: PD.5
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 104: VDDIO1
    {PJ, BIT2, {(uint32_t) &SYS->GPJ_MFP0, SYS_GPJ_MFP0_PJ2MFP_Msk, SYS_GPJ_MFP0_PJ2MFP_GPIO}},    // Pin 105: PJ.2
    {PJ, BIT3, {(uint32_t) &SYS->GPJ_MFP0, SYS_GPJ_MFP0_PJ3MFP_Msk, SYS_GPJ_MFP0_PJ3MFP_GPIO}},    // Pin 106: PJ.3
    {PJ, BIT4, {(uint32_t) &SYS->GPJ_MFP1, SYS_GPJ_MFP1_PJ4MFP_Msk, SYS_GPJ_MFP1_PJ4MFP_GPIO}},    // Pin 107: PJ.4
    {PJ, BIT5, {(uint32_t) &SYS->GPJ_MFP1, SYS_GPJ_MFP1_PJ5MFP_Msk, SYS_GPJ_MFP1_PJ5MFP_GPIO}},    // Pin 108: PJ.5
    {PJ, BIT6, {(uint32_t) &SYS->GPJ_MFP1, SYS_GPJ_MFP1_PJ6MFP_Msk, SYS_GPJ_MFP1_PJ6MFP_GPIO}},    // Pin 109: PJ.6
    {PJ, BIT7, {(uint32_t) &SYS->GPJ_MFP1, SYS_GPJ_MFP1_PJ7MFP_Msk, SYS_GPJ_MFP1_PJ7MFP_GPIO}},    // Pin 110: PJ.7
    {PH, BIT12, {(uint32_t) &SYS->GPH_MFP3, SYS_GPH_MFP3_PH12MFP_Msk, SYS_GPH_MFP3_PH12MFP_GPIO}}, // Pin 111: PH.12
    {PH, BIT13, {(uint32_t) &SYS->GPH_MFP3, SYS_GPH_MFP3_PH13MFP_Msk, SYS_GPH_MFP3_PH13MFP_GPIO}}, // Pin 112: PH.13
    {PH, BIT14, {(uint32_t) &SYS->GPH_MFP3, SYS_GPH_MFP3_PH14MFP_Msk, SYS_GPH_MFP3_PH14MFP_GPIO}}, // Pin 113: PH.14
    {PH, BIT15, {(uint32_t) &SYS->GPH_MFP3, SYS_GPH_MFP3_PH15MFP_Msk, SYS_GPH_MFP3_PH15MFP_GPIO}}, // Pin 114: PH.15
    {PG, BIT13, {(uint32_t) &SYS->GPG_MFP3, SYS_GPG_MFP3_PG13MFP_Msk, SYS_GPG_MFP3_PG13MFP_GPIO}}, // Pin 115: PG.13
    {PG, BIT14, {(uint32_t) &SYS->GPG_MFP3, SYS_GPG_MFP3_PG14MFP_Msk, SYS_GPG_MFP3_PG14MFP_GPIO}}, // Pin 116: PG.14
    {PG, BIT15, {(uint32_t) &SYS->GPG_MFP3, SYS_GPG_MFP3_PG15MFP_Msk, SYS_GPG_MFP3_PG15MFP_GPIO}}, // Pin 117: PG.15
    {PD, BIT3, {(uint32_t) &SYS->GPD_MFP0, SYS_GPD_MFP0_PD3MFP_Msk, SYS_GPD_MFP0_PD3MFP_GPIO}},    // Pin 118: PD.3
    {PD, BIT2, {(uint32_t) &SYS->GPD_MFP0, SYS_GPD_MFP0_PD2MFP_Msk, SYS_GPD_MFP0_PD2MFP_GPIO}},    // Pin 119: PD.2
    {PD, BIT1, {(uint32_t) &SYS->GPD_MFP0, SYS_GPD_MFP0_PD1MFP_Msk, SYS_GPD_MFP0_PD1MFP_GPIO}},    // Pin 120: PD.1
    {PD, BIT0, {(uint32_t) &SYS->GPD_MFP0, SYS_GPD_MFP0_PD0MFP_Msk, SYS_GPD_MFP0_PD0MFP_GPIO}},    // Pin 121: PD.0
    {PD, BIT13, {(uint32_t) &SYS->GPD_MFP3, SYS_GPD_MFP3_PD13MFP_Msk, SYS_GPD_MFP3_PD13MFP_GPIO}}, // Pin 122: PD.13
    {PA, BIT12, {(uint32_t) &SYS->GPA_MFP3, SYS_GPA_MFP3_PA12MFP_Msk, SYS_GPA_MFP3_PA12MFP_GPIO}}, // Pin 123: PA.12
    {PA, BIT13, {(uint32_t) &SYS->GPA_MFP3, SYS_GPA_MFP3_PA13MFP_Msk, SYS_GPA_MFP3_PA13MFP_GPIO}}, // Pin 124: PA.13
    {PA, BIT14, {(uint32_t) &SYS->GPA_MFP3, SYS_GPA_MFP3_PA14MFP_Msk, SYS_GPA_MFP3_PA14MFP_GPIO}}, // Pin 125: PA.14
    {PA, BIT15, {(uint32_t) &SYS->GPA_MFP3, SYS_GPA_MFP3_PA15MFP_Msk, SYS_GPA_MFP3_PA15MFP_GPIO}}, // Pin 126: PA.15
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 127: HSUSB_VRES
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 128: HSUSB_VDD33
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 129: HSUSB_VBUS
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 130: HSUSB_D-
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 131: HSUSB_VSS
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 132: HSUSB_D+
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 133: HSUSB_VDD11
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 134: HSUSB_ID
    {PE, BIT7, {(uint32_t) &SYS->GPE_MFP1, SYS_GPE_MFP1_PE7MFP_Msk, SYS_GPE_MFP1_PE7MFP_GPIO}},    // Pin 135: PE.7
    {PE, BIT6, {(uint32_t) &SYS->GPE_MFP1, SYS_GPE_MFP1_PE6MFP_Msk, SYS_GPE_MFP1_PE6MFP_GPIO}},    // Pin 136: PE.6
    {PE, BIT5, {(uint32_t) &SYS->GPE_MFP1, SYS_GPE_MFP1_PE5MFP_Msk, SYS_GPE_MFP1_PE5MFP_GPIO}},    // Pin 137: PE.5
    {PE, BIT4, {(uint32_t) &SYS->GPE_MFP1, SYS_GPE_MFP1_PE4MFP_Msk, SYS_GPE_MFP1_PE4MFP_GPIO}},    // Pin 138: PE.4
    {PE, BIT3, {(uint32_t) &SYS->GPE_MFP0, SYS_GPE_MFP0_PE3MFP_Msk, SYS_GPE_MFP0_PE3MFP_GPIO}},    // Pin 139: PE.3
    {PE, BIT2, {(uint32_t) &SYS->GPE_MFP0, SYS_GPE_MFP0_PE2MFP_Msk, SYS_GPE_MFP0_PE2MFP_GPIO}},    // Pin 140: PE.2
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 141: VSS
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 142: VDD
    {PE, BIT1, {(uint32_t) &SYS->GPE_MFP0, SYS_GPE_MFP0_PE1MFP_Msk, SYS_GPE_MFP0_PE1MFP_GPIO}},    // Pin 143: PE.1
    {PE, BIT0, {(uint32_t) &SYS->GPE_MFP0, SYS_GPE_MFP0_PE0MFP_Msk, SYS_GPE_MFP0_PE0MFP_GPIO}},    // Pin 144: PE.0
    {PH, BIT8, {(uint32_t) &SYS->GPH_MFP2, SYS_GPH_MFP2_PH8MFP_Msk, SYS_GPH_MFP2_PH8MFP_GPIO}},    // Pin 145: PH.8
    {PH, BIT9, {(uint32_t) &SYS->GPH_MFP2, SYS_GPH_MFP2_PH9MFP_Msk, SYS_GPH_MFP2_PH9MFP_GPIO}},    // Pin 146: PH.9
    {PH, BIT10, {(uint32_t) &SYS->GPH_MFP2, SYS_GPH_MFP2_PH10MFP_Msk, SYS_GPH_MFP2_PH10MFP_GPIO}}, // Pin 147: PH.10
    {PH, BIT11, {(uint32_t) &SYS->GPH_MFP2, SYS_GPH_MFP2_PH11MFP_Msk, SYS_GPH_MFP2_PH11MFP_GPIO}}, // Pin 148: PH.11
    {PD, BIT14, {(uint32_t) &SYS->GPD_MFP3, SYS_GPD_MFP3_PD14MFP_Msk, SYS_GPD_MFP3_PD14MFP_GPIO}}, // Pin 149: PD.14
    {PJ, BIT8, {(uint32_t) &SYS->GPJ_MFP2, SYS_GPJ_MFP2_PJ8MFP_Msk, SYS_GPJ_MFP2_PJ8MFP_GPIO}},    // Pin 150: PJ.8
    {PJ, BIT9, {(uint32_t) &SYS->GPJ_MFP2, SYS_GPJ_MFP2_PJ9MFP_Msk, SYS_GPJ_MFP2_PJ9MFP_GPIO}},    // Pin 151: PJ.9
    {PJ, BIT10, {(uint32_t) &SYS->GPJ_MFP2, SYS_GPJ_MFP2_PJ10MFP_Msk, SYS_GPJ_MFP2_PJ10MFP_GPIO}}, // Pin 152: PJ.10
    {PJ, BIT11, {(uint32_t) &SYS->GPJ_MFP2, SYS_GPJ_MFP2_PJ11MFP_Msk, SYS_GPJ_MFP2_PJ11MFP_GPIO}}, // Pin 153: PJ.11
    {PJ, BIT12, {(uint32_t) &SYS->GPJ_MFP3, SYS_GPJ_MFP3_PJ12MFP_Msk, SYS_GPJ_MFP3_PJ12MFP_GPIO}}, // Pin 154: PJ.12
    {PJ, BIT13, {(uint32_t) &SYS->GPJ_MFP3, SYS_GPJ_MFP3_PJ13MFP_Msk, SYS_GPJ_MFP3_PJ13MFP_GPIO}}, // Pin 155: PJ.13
    {PG, BIT5, {(uint32_t) &SYS->GPG_MFP1, SYS_GPG_MFP1_PG5MFP_Msk, SYS_GPG_MFP1_PG5MFP_GPIO}},    // Pin 156: PG.5
    {PG, BIT6, {(uint32_t) &SYS->GPG_MFP1, SYS_GPG_MFP1_PG6MFP_Msk, SYS_GPG_MFP1_PG6MFP_GPIO}},    // Pin 157: PG.6
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 158: VSS
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 159: VSS
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 160: NC
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 161: VDD
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 162: VDD
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 163: LDO CAP
    {PB, BIT15, {(uint32_t) &SYS->GPB_MFP3, SYS_GPB_MFP3_PB15MFP_Msk, SYS_GPB_MFP3_PB15MFP_GPIO}}, // Pin 164: PB.15
    {PB, BIT14, {(uint32_t) &SYS->GPB_MFP3, SYS_GPB_MFP3_PB14MFP_Msk, SYS_GPB_MFP3_PB14MFP_GPIO}}, // Pin 165: PB.14
    {PB, BIT13, {(uint32_t) &SYS->GPB_MFP3, SYS_GPB_MFP3_PB13MFP_Msk, SYS_GPB_MFP3_PB13MFP_GPIO}}, // Pin 166: PB.13
    {PB, BIT12, {(uint32_t) &SYS->GPB_MFP3, SYS_GPB_MFP3_PB12MFP_Msk, SYS_GPB_MFP3_PB12MFP_GPIO}}, // Pin 167: PB.12
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 168: AVDD
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 169: VREF
    {NULL, 0, {0, 0, 0}},                                                                       // Pin 170: AVSS
    {PB, BIT11, {(uint32_t) &SYS->GPB_MFP2, SYS_GPB_MFP2_PB11MFP_Msk, SYS_GPB_MFP2_PB11MFP_GPIO}}, // Pin 171: PB.11
    {PB, BIT10, {(uint32_t) &SYS->GPB_MFP2, SYS_GPB_MFP2_PB10MFP_Msk, SYS_GPB_MFP2_PB10MFP_GPIO}}, // Pin 172: PB.10
    {PB, BIT9, {(uint32_t) &SYS->GPB_MFP2, SYS_GPB_MFP2_PB9MFP_Msk, SYS_GPB_MFP2_PB9MFP_GPIO}},    // Pin 173: PB.9
    {PB, BIT8, {(uint32_t) &SYS->GPB_MFP2, SYS_GPB_MFP2_PB8MFP_Msk, SYS_GPB_MFP2_PB8MFP_GPIO}},    // Pin 174: PB.8
    {PB, BIT7, {(uint32_t) &SYS->GPB_MFP1, SYS_GPB_MFP1_PB7MFP_Msk, SYS_GPB_MFP1_PB7MFP_GPIO}},    // Pin 175: PB.7
    {PB, BIT6, {(uint32_t) &SYS->GPB_MFP1, SYS_GPB_MFP1_PB6MFP_Msk, SYS_GPB_MFP1_PB6MFP_GPIO}},    // Pin 176: PB.6
    {NULL, 0, {0, 0, 0}}                                                                        // Pin 177: VSS 

   
};

EPWMPinDescription PWM_Desc[] = 
{
    //{(EPWM_T  *)(EPWM1), (uint32_t)EPWM1_MODULE, PWM_USE_EPWM, EPWM1P0_IRQn, PWM_CHANNEL_CH2, PWM_FREQUENCY_500HZ, {55, SYS_GPB_MFP3_PB13MFP_EPWM1_CH2}}, //D14  PB13,EPWM1_CH2 
    //{(EPWM_T  *)(BPWM1), (uint32_t)BPWM1_MODULE, PWM_USE_BPWM, BPWM1_IRQn,   PWM_CHANNEL_CH2, PWM_FREQUENCY_500HZ, {62, SYS_GPB_MFP2_PB9MFP_BPWM1_CH2 }}, //D17  PB9, BPWM1_CH2
	//{(EPWM_T  *)(EPWM0), (uint32_t)EPWM0_MODULE, PWM_USE_EPWM, EPWM0P0_IRQn, PWM_CHANNEL_CH5, PWM_FREQUENCY_500HZ, { 7, SYS_GPB_MFP0_PB0MFP_EPWM0_CH5 }}, //D0   PB0, EPWM0_CH5
  
};

//[2025-02-25] ADC pins update done. 
ADCPinDescription ADC_Desc[] =
{
    //{EADC0, EADC0_MODULE, ADC_CHANNEL_CH13, { 55, SYS_GPB_MFP3_PB13MFP_EADC0_CH13 }},  //A0 PB13(EADC0_CH13, 10b)
    //{EADC0, EADC0_MODULE, ADC_CHANNEL_CH11, { 60, SYS_GPB_MFP2_PB11MFP_EADC0_CH11 }},  //A1 PB11(EADC0_CH11, 10b)
    //{EADC0, EADC0_MODULE, ADC_CHANNEL_CH10, { 61, SYS_GPB_MFP2_PB10MFP_EADC0_CH10 }},  //A2 PB10(EADC0_CH10, 10b)
    //{EADC0, EADC0_MODULE, ADC_CHANNEL_CH9,  { 62, SYS_GPB_MFP2_PB9MFP_EADC0_CH9   }},  //A3 PB9 (EADC_0CH9,  10b)
    //{EADC0, EADC0_MODULE, ADC_CHANNEL_CH12, { 56, SYS_GPB_MFP3_PB12MFP_EADC0_CH12 }},  //A4 PB12(EADC0_CH12, 10b)
	//{EADC0, EADC0_MODULE, ADC_CHANNEL_CH0,  {  7, SYS_GPB_MFP0_PB0MFP_EADC0_CH0   }},  //A5 PB0 (EADC0_CH0,  10b) for test
};
//[2025-02-18] SPI0 pins updated
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
#if defined(__M460MINIMA__)
    {(UART_T *)(0),  (uint32_t)(0), (uint32_t)(UART_USE_VCOM), (IRQn_Type)(0), {{255, (uint32_t)(0) },               {255, (uint32_t)(0) }}              ,  (uint32_t)(0)            , UART_CLKDIV_1},   //(USE VCOM)
	{UART0, (uint32_t)UART0_MODULE, (uint32_t)(UART_USE_UART0), UART0_IRQn, {{21, SYS_GPA_MFP1_PA6MFP_UART0_RXD },  {20, SYS_GPA_MFP1_PA7MFP_UART0_TXD }},  CLK_CLKSEL1_UART0SEL_HIRC, UART_CLKDIV_1},   //(T/R = PA7/PA6)
    {UART1, (uint32_t)UART1_MODULE, (uint32_t)(UART_USE_UART1), UART1_IRQn, {{28, SYS_GPA_MFP0_PA2MFP_UART1_RXD  }, {27, SYS_GPA_MFP0_PA3MFP_UART1_TXD }},  CLK_CLKSEL1_UART1SEL_HIRC, UART_CLKDIV_1},   //(T/R = PA3/PA2)
#else
    {UART0, (uint32_t)UART0_MODULE, (uint32_t)(UART_USE_UART0), UART0_IRQn, {{167, SYS_GPB_MFP3_PB12MFP_UART0_RXD }, {166, SYS_GPB_MFP3_PB13MFP_UART0_TXD  }},  CLK_UARTSEL0_UART0SEL_HIRC, UART_CLKDIV_1},   //(T/R = PA7/PA6)
    //{UART1, (uint32_t)UART1_MODULE, (uint32_t)(UART_USE_UART1), UART1_IRQn, {{28, SYS_GPA_MFP0_PA2MFP_UART1_RXD }, {27, SYS_GPA_MFP0_PA3MFP_UART1_TXD  }},  CLK_CLKSEL1_UART1SEL_HIRC, UART_CLKDIV_1},   //(T/R = PA3/PA2)
	//{UART3, (uint32_t)UART3_MODULE, (uint32_t)(UART_USE_UART3), UART3_IRQn, {{100, SYS_GPB_MFP3_PB12MFP_UART0_RXD  }, { 100 , SYS_GPB_MFP3_PB13MFP_UART0_TXD }},  CLK_CLKSEL3_UART3SEL_HIRC, UART_CLKDIV_1},   //
#endif
	
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
    {LPI2C0, LPI2C0_MODULE, {{51 , SYS_GPC_MFP3_PC12MFP_LPI2C0_SCL}, {50 , SYS_GPC_MFP2_PC11MFP_LPI2C0_SDA }}},
	//{I2C2, I2C2_MODULE, {{29 , SYS_GPA_MFP0_PA1MFP_I2C2_SCL}, {30 , SYS_GPA_MFP0_PA0MFP_I2C2_SDA }}},
};


CANFDPinDescription CANFD_Desc[] =
{
    //{CANFD0, (uint32_t)CANFD0_MODULE, (uint32_t)(CANFD_USE_CANFD0), CANFD00_IRQn, {{70, SYS_GPC_MFP1_PC4MFP_CAN0_RXD },  {69, SYS_GPC_MFP1_PC5MFP_CAN0_TXD }}},//,  CLK_CLKSEL0_CANFD0SEL_HCLK, CANFD_CLKDIV_1},
    //{CANFD0, (uint32_t)CANFD0_MODULE, (uint32_t)(CANFD_USE_CANFD0), CANFD00_IRQn, {{26, SYS_GPA_MFP1_PA4MFP_CAN0_RXD },  {25, SYS_GPA_MFP1_PA5MFP_CAN0_TXD }}},//,  CLK_CLKSEL0_CANFD0SEL_HCLK, CANFD_CLKDIV_1},
	
	
};



#endif//__UNO_M55M1__
