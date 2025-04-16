/*
  microphone
 
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 13, when microphone attached to pin 2 sense the sound peak.
 
 
 The circuit:
 * LED attached from pin 13 to ground 
 * microphone output (DO) attached to pin 10
 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.
 
 
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 28 Oct 2010
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to 
// set pin numbers:
const int microphoneDO_Pin = D10;     // the number of the microphone pin
const int ledPin =  D7;              // the number of the LED pin

// variables will change:
int microphoneState = 0;         // variable for reading the microphone status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the microphone pin as an input:
  pinMode(microphoneDO_Pin, INPUT);     
}

void loop(){
  // read the state of the microphone value:
  microphoneState = digitalRead(microphoneDO_Pin);

  // check if the microphone is pressed.
  // if it is, the microphoneState is HIGH:
  if (microphoneState == HIGH) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
  }
}