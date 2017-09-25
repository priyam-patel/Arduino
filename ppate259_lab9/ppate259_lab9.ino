/*
 * Priyam Patel - 650675226
 * Lab 9
 * Description: Connect two analog devices to the arduino and plot the data received on the computer using processing.
 * Assumption: Two devices I used were photoresistor (A0) and potentiometer (A1)         
 * References: https://learn.sparkfun.com/tutorials/connecting-arduino-to-processing#introduction
 *             http://arduino.cc/en/Tutorial/Graph
 */
 
int sensorPin = A0; //pin for photoresistor
int sensorValue = 0; //initialize variable for analog value output 

void setup(){
  Serial.begin(9600);
}

void loop(){
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue); //print out photoresistor value in serial monitor
  Serial.println(analogRead(A1)); //print out potentiometer value in serial monitor 
  delay(2); //short delay 
}

