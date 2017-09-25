/*
 * Priyam Patel - 650675226
 * Lab 5
 * Description: Use photoresistor to light up LEDs based on PrValues
 *              Use a potentiometer to control buzzer volume 
 * Assumption: Photoresistor connected to power and analog pin, Basic pot setup, Buzzer connected to pin with ~            
 * References: https://www.arduino.cc/en/Reference/Map
 
 */
 

int photoresistor = 0; // will be used for analog 0.

int PrValue = 0; // value of output

int buzzer = 3; 

void setup() {
  
  pinMode(8, OUTPUT); // pin 8 as output
  
  pinMode(7, OUTPUT); 
  
  pinMode(5, OUTPUT); 
  
  pinMode(4, OUTPUT); 
  
  Serial.begin(9600); 

}

void loop() {

  PrValue = analogRead(photoresistor);
  
  Serial.println(PrValue); //prints photoresistor value
  
  delay(100); 

if (PrValue >= 800) { 
  
  digitalWrite(8, LOW);
  
  digitalWrite(7, LOW); 
  
  digitalWrite(5, LOW); 
  
  digitalWrite(4, LOW); 
}
if (PrValue < 800 && PrValue >= 500) {

  digitalWrite(8, HIGH);
  
  digitalWrite(7, LOW); 
  
  digitalWrite(5, LOW); 
  
  digitalWrite(4, LOW); 

} 

if (PrValue < 500 && PrValue >= 300) {

  digitalWrite(8, HIGH);
  
  digitalWrite(7, HIGH); 
  
  digitalWrite(5, LOW); 
  
  digitalWrite(4, LOW); 

}

if (PrValue < 300 && PrValue >= 100){

  digitalWrite(8, HIGH);
  
  digitalWrite(7, HIGH); 
  
  digitalWrite(5, HIGH); 
  
  digitalWrite(4, LOW);  

}

if (PrValue < 100) {

  digitalWrite(8, HIGH);
  
  digitalWrite(7, HIGH); 
  
  digitalWrite(5, HIGH); 
  
  digitalWrite(4, HIGH); 

}


// code for part 2 - buzzer and potentiometer  
   int val = map(analogRead(1), 0, 1023,0,255); 
   analogWrite(buzzer,val);  
    
}
