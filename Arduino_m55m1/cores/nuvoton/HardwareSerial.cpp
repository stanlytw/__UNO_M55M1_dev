/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2010 Perry Hung.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *****************************************************************************/

/**
 * @file HardwareSerial.cpp
 * @brief Wirish serial port implementation.
 */

#include <cstdint>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"
#include "HardwareSerial.h"


#if(UART_MAX_COUNT>0)
ring_buffer rx_buffer1= { { 0 }, 0, 0};
HardwareSerial Serial(UART_Desc[0].U, UART_DESC_IDX0 , UART_Desc[0].clksrcsel, UART_Desc[0].clkdiv, UART_Desc[0].irq, UART_Desc[0].modulenum, &rx_buffer1);//UART0
#endif
#if(UART_MAX_COUNT>1)
ring_buffer rx_buffer2 = { { 0 }, 0, 0};
HardwareSerial Serial1(UART_Desc[1].U, UART_DESC_IDX1 , UART_Desc[1].clksrcsel, UART_Desc[1].clkdiv, UART_Desc[1].irq, UART_Desc[1].modulenum, &rx_buffer2);//UART0
#endif


#ifdef __cplusplus
extern "C" {
#endif
#if(UART_MAX_COUNT>0)
void UART0_IRQHandler(void)
{
    while (UART_GET_INT_FLAG(UART0, UART_INTEN_RDAIEN_Msk))
    {
        int i = (unsigned int)(rx_buffer1.head + 1) % SERIAL_BUFFER_SIZE;
        if (i != rx_buffer1.tail)
        {
            rx_buffer1.buffer[rx_buffer1.head] = UART0->DAT;
            rx_buffer1.head = i;
        }
		else//i == rx_buffer1.tail
		{
			unsigned char dummy = UART0->DAT;
		}
    }

}
#endif  

#if(UART_MAX_COUNT>1)
void UART1_IRQHandler(void)
{
    while (UART_GET_INT_FLAG(UART1, UART_INTEN_RDAIEN_Msk))
    {
        int i = (unsigned int)(rx_buffer2.head + 1) % SERIAL_BUFFER_SIZE;
        if (i != rx_buffer2.tail)
        {
            rx_buffer2.buffer[rx_buffer2.head] = UART1->DAT;
            rx_buffer2.head = i;
        }
		else//i == rx_buffer1.tail
		{
			unsigned char dummy = UART1->DAT;
		}
    }

}
#endif
 

#ifdef __cplusplus
}
#endif



#if(UART_MAX_COUNT>0)
    void serialEvent() __attribute__((weak));
#endif

#if(UART_MAX_COUNT>1)
    void serial1Event() __attribute__((weak));
#endif



void serialEventRun(void)
{
#if(UART_MAX_COUNT>0)
    if (Serial.available()) serialEvent();
#endif

#if(UART_MAX_COUNT>1)
    if (Serial1.available()) serial1Event();
#endif

}

HardwareSerial::HardwareSerial(UART_T *uart_device,
                               uint32_t u32Idx,
                               uint32_t u32ClkSrc,
                               uint32_t u32ClkDiv,
                               IRQn_Type u32IrqId,
							   uint32_t u32ModuleNum,
                               ring_buffer *rx_buffer)
{
    this->use_vcom = 0;
    this->uart_device = uart_device;
    this->u32Idx = u32Idx;
    this->u32ClkSrc = u32ClkSrc;
    this->u32ClkDiv = u32ClkDiv;
    this->u32IrqId = u32IrqId;
	this->u32ModuleNum = u32ModuleNum;
    this->_rx_buffer = rx_buffer;
    
}

/*
 * Set up/tear down
 */
//For RS485 support
void HardwareSerial::begin(uint32_t baud, uint16_t config)
{
	
	this->u16config = config;
	begin(baud);
} 
 
 
void HardwareSerial::begin(uint32_t baud)
{

   if(u32ModuleNum == UART_USE_NOUSE)
	{
		return;
	}
	else
	{
		//u32ModuleNum = UART_USE_UART0, UART_USE_UART1... etc
       UART_Config(UART_Desc[u32Idx]);
	   
	   //RS485-AUD
	   if(u16config==RS485_OVER_SERIAL)
		   DE_Config(DEPin_Desc[u32Idx]);
	   
       SYS_UnlockReg();		
	}
	


	/* Enable IP clock */
    CLK_EnableModuleClock(UART_Desc[u32Idx].module);

    /* Select IP clock source and clock divider */
    if(uart_device == UART0)
	{
		CLK_SetModuleClock(UART_Desc[u32Idx].module, u32ClkSrc, CLK_UARTDIV0_UART0DIV(u32ClkDiv));
	}
    else if(uart_device == UART1)
	{
		CLK_SetModuleClock(UART_Desc[u32Idx].module, u32ClkSrc, CLK_UARTDIV0_UART1DIV(u32ClkDiv));
	}
	else if(uart_device == UART3)
	{	
        CLK_SetModuleClock(UART_Desc[u32Idx].module, u32ClkSrc, CLK_UARTDIV0_UART3DIV(u32ClkDiv));
	}
	else if(uart_device == UART4)
	{	
        CLK_SetModuleClock(UART_Desc[u32Idx].module, u32ClkSrc, CLK_UARTDIV0_UART4DIV(u32ClkDiv));
	}   
	/* Reset IP */
    //SYS_ResetModule(UART_Desc[u32Idx].module);

    /* Enable Interrupt */
    UART_ENABLE_INT(uart_device, UART_INTEN_RDAIEN_Msk);
    NVIC_EnableIRQ(u32IrqId);

    /* Configure UART and set UART Baudrate */
    UART_Open(uart_device, baud);   
	
	if(u16config==RS485_OVER_SERIAL)
	{
        UART_SelectRS485Mode(uart_device, UART_ALTCTL_RS485AUD_Msk, 0);		
		/* Set RTS pin active level as high level active */
        uart_device->MODEM = (uart_device->MODEM & (~UART_MODEM_RTSACTLV_Msk)) | UART_RTS_IS_HIGH_LEV_ACTIVE;
	}
	    
    SYS_LockReg();

}

void HardwareSerial::end(void)
{
    if(u32ModuleNum == UART_USE_NOUSE)
	{
		return;
	}
	else
	{
		//u32ModuleNum = UART_USE_UART0, UART_USE_UART1... etc
        UART_Close(uart_device);
	}	
}	
/*
 * I/O
 */

int HardwareSerial::read(void)
{
    // if the head isn't ahead of the tail, we don't have any characters
    if (_rx_buffer->head == _rx_buffer->tail)
    {
        return -1;
    }
    else
    {
        unsigned char c = _rx_buffer->buffer[_rx_buffer->tail];
        _rx_buffer->tail = (unsigned int)(_rx_buffer->tail + 1) % SERIAL_BUFFER_SIZE;
	
		return c;
    }
}

int HardwareSerial::availableForWrite(void)
{

    if(u32ModuleNum == UART_USE_NOUSE)
	{
		return -1;
	}
	else//u32ModuleNum = UART_USE_UART0, UART_USE_UART1... etc
	{
		if (UART_IS_TX_FULL(uart_device))
        {
            return 0;
        }
        else
        {
            if(uart_device == UART0)
                return (UART0_FIFO_SIZE - ((uart_device->FIFOSTS & UART_FIFOSTS_TXPTR_Msk) >> UART_FIFOSTS_TXPTR_Pos));
            else if(uart_device == UART1)
                return (UART1_FIFO_SIZE - ((uart_device->FIFOSTS & UART_FIFOSTS_TXPTR_Msk) >> UART_FIFOSTS_TXPTR_Pos));
		    else if(uart_device == UART3)
                return (UART3_FIFO_SIZE - ((uart_device->FIFOSTS & UART_FIFOSTS_TXPTR_Msk) >> UART_FIFOSTS_TXPTR_Pos));
            else if(uart_device == UART4)
                return (UART4_FIFO_SIZE - ((uart_device->FIFOSTS & UART_FIFOSTS_TXPTR_Msk) >> UART_FIFOSTS_TXPTR_Pos));
        }
	}



}

int HardwareSerial::available(void)
{
    if(u32ModuleNum == UART_USE_NOUSE)
	{
		return -1;
	}
	else
	{
		//u32ModuleNum = UART_USE_UART0, UART_USE_UART1... etc
        return (unsigned int)(SERIAL_BUFFER_SIZE + _rx_buffer->head - _rx_buffer->tail) % SERIAL_BUFFER_SIZE;
	}	  
}

size_t HardwareSerial::write(const uint8_t ch)
{

   if(u32ModuleNum == UART_USE_NOUSE)
	{
		return -1;
	}
	else
	{
		//u32ModuleNum = UART_USE_UART0, UART_USE_UART1... etc
        while (uart_device->FIFOSTS & UART_FIFOSTS_TXFULL_Msk);
        uart_device->DAT = ch;
	}	  
    return 1;


}

void HardwareSerial::flush(void)
{

    /* No need to implement because we use hardware UART and it is with hardware FIFO*/
}


int HardwareSerial::peek(void)
{
    if (_rx_buffer->head == _rx_buffer->tail)
    {
        return -1;
    }
    else
    {
        return _rx_buffer->buffer[_rx_buffer->tail];
    }
}
