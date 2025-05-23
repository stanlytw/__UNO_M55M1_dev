/* Tone.cpp

  A Tone Generator Library

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*/


#include "Arduino.h"

HardwareTimer *ToneTimer = Timer[1];

typedef struct
{
    HardwareTimer *timer;
    uint8_t pin;
    uint8_t enabled;
    volatile uint8_t waitISR;
} tone_t;

tone_t Tone = {0};



void tone_ISR(uint8_t num)
{
    Tone.waitISR = 0;

    Tone.timer->close();
    EPWM_DisableOutput(PWM_Desc[Tone.pin].P, (1 << PWM_Desc[Tone.pin].ch));


}

static uint8_t pinEnabled[PWM_MAX_COUNT] = {0};
// frequency (in hertz) and duration (in milliseconds).
void tone(uint8_t ulPin, unsigned int frequency, unsigned long duration)
{
    tone_t *tone;
#ifdef USE_BoardToPin
    if (ulPin > BoardToPin_MAX_COUNT) return;
    if (BoardToPinInfo[ulPin].type != PWM_TYPE) return;
    ulPin = BoardToPinInfo[ulPin].num;
#else
    if (ulPin > PWM_MAX_COUNT || PWM_Desc[ulPin].P == NULL) return;
#endif

#if defined(__M032BT__)


#else
    if (!pinEnabled[ulPin] && frequency != 0)
    {
        //Set Mutifunction pins
        PWM_Config(PWM_Desc[ulPin]);

        //Config PWMs
        EPWM_ConfigOutputChannel(PWM_Desc[ulPin].P, PWM_Desc[ulPin].ch, frequency, 50);

        //Enable PWM output
        EPWM_EnableOutput(PWM_Desc[ulPin].P, (1 << PWM_Desc[ulPin].ch));

        //Start PWM
        EPWM_Start(PWM_Desc[ulPin].P, (1 << PWM_Desc[ulPin].ch));    

        
        pinEnabled[ulPin] = 1;
    }

    tone = &Tone;
    tone->pin = ulPin;
    tone->timer = ToneTimer;
    tone->enabled = 1;
    if (duration == 0)
    {
        if (frequency != 0)
        {

            EPWM_EnableOutput(PWM_Desc[ulPin].P, (1 << PWM_Desc[ulPin].ch));
            EPWM_ConfigOutputChannel(PWM_Desc[ulPin].P, PWM_Desc[ulPin].ch, frequency, 50);

        }
    }
    else
    {
        while (tone->waitISR);
        //Config PWMs
        if (frequency != 0)
        {

            EPWM_EnableOutput(PWM_Desc[ulPin].P, (1 << PWM_Desc[ulPin].ch));
            EPWM_ConfigOutputChannel(PWM_Desc[ulPin].P, PWM_Desc[ulPin].ch, frequency, 50);

        }
        //PWM_Start(PWM_Desc[tone->pin].P,(1<<PWM_Desc[tone->pin].ch));
        tone->waitISR = 1;

        //Config Timer
        tone->timer->open(ONESHOT, tone->timer->getModuleClock());
        tone->timer->setPrescaleFactor(0);
        tone->timer->setCompare(tone->timer->getModuleClock() / 1000 * duration); /* milliseconds */
        tone->timer->attachInterrupt(tone_ISR);
        tone->timer->start();
    }
#endif
}

void noTone(uint8_t ulPin)
{

#if defined(__M032BT__)|| defined(__M032KG__)

   
#else
    tone_t *tone;
#ifdef USE_BoardToPin
    if (ulPin > BoardToPin_MAX_COUNT) return;
    if (BoardToPinInfo[ulPin].type != PWM_TYPE) return;
    ulPin = BoardToPinInfo[ulPin].num;
#else
    if (ulPin > PWM_MAX_COUNT || PWM_Desc[ulPin].P == NULL) return;
#endif
    //close tone
    tone = &Tone;
    if (tone->pin == ulPin)
    {
        while (tone->waitISR);

        EPWM_DisableOutput(PWM_Desc[tone->pin].P, (1 << PWM_Desc[tone->pin].ch));
      
        tone->pin = 0;
        tone->enabled = 0;
        tone->timer->close();
    }
#endif
}
