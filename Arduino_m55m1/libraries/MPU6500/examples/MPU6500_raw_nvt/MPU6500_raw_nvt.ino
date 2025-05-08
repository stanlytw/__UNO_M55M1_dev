/*
  MPU6500 Raw

  A code for obtaining raw data from the MPU6500 module with the option to
  modify the data output format.

  Find the full MPU6500 library documentation here:
  
*/
#include "I2Cdev.h"
#include "MPU6500.h"

/* MPU6050 default I2C address is 0x68*/
MPU6500 mpu;
//MPU6050 mpu(0x69);         //Use for AD0 high
//MPU6050 mpu(0x68, &Wire1); //Use for AD0 low, but 2nd Wire (TWI/I2C) object.

/* OUTPUT FORMAT DEFINITION----------------------------------------------------------------------------------
- Use "OUTPUT_READABLE_ACCELGYRO" if you want to see a tab-separated list of the accel 
X/Y/Z and gyro X/Y/Z values in decimal. Easy to read, but not so easy to parse, and slower over UART.

- Use "OUTPUT_BINARY_ACCELGYRO" to send all 6 axes of data as 16-bit binary, one right after the other. 
As fast as possible without compression or data loss, easy to parse, but impossible to read for a human. 
This output format is used as an output.
--------------------------------------------------------------------------------------------------------------*/ 
#define OUTPUT_READABLE_ACCELGYRO


int16_t ax, ay, az;
bool blinkState;

void setup() {
  /*--Start I2C interface--*/
  #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    Wire.begin(); 
  #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
    Fastwire::setup(400, true);
  #endif

  Serial.begin(115200); //Initializate Serial wo work well at 8MHz/16MHz

  /*
      Initialize device and check connection
	  acc : 2G
	  gyro: 250dps
  */ 
  Serial.println("Initializing MPU...");
  mpu.initialize();
  
  Serial.println("Testing MPU6050 connection...");
  if(mpu.testConnection() ==  false){
    Serial.println("MPU6050 connection failed");
    while(true);
  }
  else{
    Serial.println("MPU6050 connection successful");
  }

  /*Configure board LED pin for output*/ 
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  /* Read raw accel/gyro data from the module. Other methods commented*/
  //mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  mpu.getAcceleration(&ax, &ay, &az);
  //mpu.getRotation(&gx, &gy, &gz);

  /*Print the obtained data on the defined format*/
  #ifdef OUTPUT_READABLE_ACCELGYRO
    Serial.print("a:\t");
    Serial.print(ax); Serial.print(",\t");
    Serial.print(ay); Serial.print(",\t");
    Serial.println(az);
  #endif


  delay(10);
  /*Blink LED to indicate activity*/
  blinkState = !blinkState;
  digitalWrite(LED_BUILTIN, blinkState);
}
