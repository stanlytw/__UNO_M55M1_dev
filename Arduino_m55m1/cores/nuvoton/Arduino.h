/******************************************************************************
 * @file     Arduino.h
 * @version  V2.00
 * $Date: 13/10/07 3:57p $ 
 * @brief    MINI51 Series Global Control for Arduino
 *
 * @note
 * Copyright (C) 2012 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
 
#ifndef _ARDUINO_H_
#define _ARDUINO_H_

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#if defined(__M451__)
  #include "M451Series.h"
#elif defined(__NUC240__)
  #include "NUC200Series.h"
#elif defined(__NANO100__)
  #include "Nano100Series.h"
#elif defined(__NUC131__)
  #include "NUC131.h"
#elif defined(__NANO1X2__)
  #include "Nano1X2Series.h"
#elif defined(__M252__)
  #include "M251.h"
#elif defined(__M480__)
  #include "M480.h"
#elif defined(__M460__)
  #include "m460.h"
#elif defined(__M032KG__)
  #include "M031Series.h"
#elif defined(__M032BT__)
  #include "M031Series.h"
  #define ENABLE_C_PRINTF 1 /* enable UART0 PA0 PA1 fo C style printf in M032BT board for internal use*/
  #define NUVOTON_BLE_ENABLE 1

#if NUVOTON_BLE_ENABLE 
  #ifdef __cplusplus
  extern "C" {
  #endif

    #include "mcu_definition.h"
    #include "rf_phy.h"
    #include "porting_spi.h"
    #include "porting_misc.h"
    #include "mcu_definition.h"

    #include "bleAppSetting.h"
    #include "ble_cmd.h"
    #include "ble_hci_cmd.h"

    #include "ble_msgblock.h"


    void HCI_EVENT_CALLBACK(uint8_t *pHCIbufAddr, uint16_t length);
  #ifdef __cplusplus
  }
  #endif

#endif //NUVOTON_BLE_ENABLE
#endif

#include "Pins_arduino.h"
#include "wiring_constants.h"

extern uint32_t SystemTickClock;
#define clockCyclesPerMicrosecond() ( SystemCoreClock / 1000000L )
#define clockCyclesToMicroseconds(a) ( ((a) * 1000L) / (SystemCoreClock / 1000L) )
#define microsecondsToClockCycles(a) ( (a) * (SystemCoreClock / 1000000L) )

#ifdef __cplusplus
extern "C" {
#endif



#include "wiring.h"
#include "wiring_digital.h"
#include "wiring_analog.h"
//#include "wiring_shift.h"
#include "WInterrupts.h"
#include "itoa.h"
void yield(void);

#ifdef __cplusplus
}

#include "WCharacter.h"
#include "WString.h"
#include "WMath.h"
#include "HardwareSerial.h"
#include "HardwareTimer.h"
#include "wiring_pulse.h"

void tone(uint8_t _pin, unsigned int frequency, unsigned long duration = 0);
void noTone(uint8_t _pin);

#endif
	

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2
static volatile uint8_t init_flag=0;	
// void init(void);

void setup(void);
void loop(void);
	
#if defined(__M451__)
  #define USB_VID     0x0416 // nuvoton
  #define USB_PID     0x8249
#elif defined(__NUC240__)
  #define USB_VID            0x0416 // nuvoton
  #define USB_PID_NUC200     0x003E
#elif defined(__NANO100__)
  #define USB_VID            0x0416 // nuvoton
  #define USB_PID            0x8240
#endif

#if defined(__M460MINIMA__) 
    #include "vcom_serial.h"
    #include "isp_user.h"
    #include "fmc_user.h"
#else
    #include "USBCore.h"
    #include "USBAPI.h"
#endif




#endif
