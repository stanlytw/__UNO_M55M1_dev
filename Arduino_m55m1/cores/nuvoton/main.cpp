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
// #include "HardwareSerial.h"
void  __attribute__((weak)) loop(void)
{


}

void __attribute__((weak)) setup(void)
{
  // _TEST_POINT();
}

/*
 * \brief Main entry point of Arduino application
 */
int main( void )
{

	init();	//nuvoton board init

	#if defined(__M460MINIMA__)
	Serial.begin(115200);//[2025-03-03]Turn on VCOM
	#endif

	setup();

	for (;;)
	{
//#if defined(__M460MINIMA__)      
//      HID_RebootCmdhandler();
//#endif       
      loop();
      if(serialEventRun) serialEventRun();
     
	}

	return 0;
}
