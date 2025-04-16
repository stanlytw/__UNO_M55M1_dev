int photoresistorPin = A5;   // select the input pin for the photoresistor
int ledPin = D7;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
 pinMode(ledPin, OUTPUT); 
  Serial.begin(115200); 
}

void loop() {
 
    sensorValue = analogRead(photoresistorPin);    
    digitalWrite(ledPin, HIGH);  
    delay(sensorValue);          
    digitalWrite(ledPin, LOW);   
    delay(sensorValue);
    Serial.println(sensorValue, DEC);  
}