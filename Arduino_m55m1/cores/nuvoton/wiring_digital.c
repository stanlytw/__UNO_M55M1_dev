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
#ifdef __cplusplus
extern "C" {
#endif


extern void pinMode(uint32_t ulPin, uint32_t ulMode)
{
#ifdef USE_BoardToPin
    if (ulPin > BoardToPin_MAX_COUNT) return;
    if (BoardToPinInfo[ulPin].pin == -1) return;
    ulPin = BoardToPinInfo[ulPin].pin;
#else
    if (ulPin > GPIO_MAX_COUNT || GPIO_Desc[ulPin].P == NULL) return;
#endif
    GPIO_Config(GPIO_Desc[ulPin]);
#if defined(__M451__) || defined(__M252__) || defined(__M480__)|| defined(__M460__)
//#if defined(__M480__)
    switch (ulMode)
    {
    case INPUT:
        GPIO_SetMode(GPIO_Desc[ulPin].P, GPIO_Desc[ulPin].bit, GPIO_MODE_INPUT);
        break;

    case INPUT_PULLUP:
        GPIO_SetMode(GPIO_Desc[ulPin].P, GPIO_Desc[ulPin].bit, GPIO_MODE_QUASI);
        break;

    case OUTPUT:
        GPIO_SetMode(GPIO_Desc[ulPin].P, GPIO_Desc[ulPin].bit, GPIO_MODE_OUTPUT);
        break;

    default:
        break;
    }
#elif defined(__M032BT__)|| defined(__M032KG__)

#elif defined(__NUC240__)

#elif defined(__NANO100__) || defined(__NANO1X2__)

#elif defined(__NUC131__)

#endif
}

extern void digitalWrite(uint32_t ulPin, uint32_t ulVal)
{
#ifdef USE_BoardToPin
    if (ulPin > BoardToPin_MAX_COUNT) return;
    if (BoardToPinInfo[ulPin].pin == -1) return;
    ulPin = BoardToPinInfo[ulPin].pin;
#else
    if (ulPin > GPIO_MAX_COUNT || GPIO_Desc[ulPin].P == NULL) return;
#endif

    if (ulVal == HIGH)
        (GPIO_Desc[ulPin].P)->DOUT |= GPIO_Desc[ulPin].bit;
    else
        (GPIO_Desc[ulPin].P)->DOUT &= ~GPIO_Desc[ulPin].bit;
}

extern int digitalRead(uint32_t ulPin)
{
#ifdef USE_BoardToPin
    if (ulPin > BoardToPin_MAX_COUNT) return 0;
    if (BoardToPinInfo[ulPin].pin == -1) return 0;
    ulPin = BoardToPinInfo[ulPin].pin;
#else
    if (ulPin > GPIO_MAX_COUNT || GPIO_Desc[ulPin].P == NULL) return LOW;
#endif
    return ((GPIO_Desc[ulPin].P)->PIN & GPIO_Desc[ulPin].bit) ? HIGH : LOW;
}

#ifdef __cplusplus
}
#endif

