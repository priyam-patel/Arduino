/*
 * Priyam Patel - 650675226
 * Lab 2
 * Description: Use two buttons to increment/decrement numbers 0-7
 *              and represent them in binary using 3 LEDs
 * An assumption I made is that I have to account for the changing states             
 * References: To first learn to use the buttons, I used this tutorial: 
 *  https://learn.adafruit.com/adafruit-arduino-lesson-6-digital-inputs/overview
 
 */
 
//intialize the LEDs 
int ledPin = 5;
int ledPin2 = 3;
int ledPin3 = 2; 

//initialize the switches
int buttonApin = 9; //button for incrementing
int buttonBpin = 8; //button for decrementing

//to keep track of changing states of the buttons 
int buttonAState = LOW; //incrementing button state
int buttonBState = LOW; //decrementing button state

byte leds = 0;

int count = 0; //counter intialized to zero
 
void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);  
  pinMode(buttonBpin, INPUT_PULLUP);  
}
 
void loop() 
{
  if (count > 7 || count < 0) { //only using 3 bits, no negatives 
    count = 0;
  }
  
  if (digitalRead(buttonApin) != buttonAState) //change in button
  {
    if(digitalRead(buttonApin)==LOW){ //incrementing button pressed 
    
    count++;

    }
  }
  if (digitalRead(buttonBpin) != buttonBState) //change in button
  {
    if(digitalRead(buttonBpin)==LOW){ //decrementing button pressed 
      
    count--;

    }
  }

  buttonAState = digitalRead(buttonApin);
  buttonBState = digitalRead(buttonBpin);
  
  //turn on LEDs based on the 3 bit representation of the int count 
  if(count==0){
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }

  else if(count==1){
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
  }

  else if(count==2){
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
  }

  else if(count==3){
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
  }

  else if(count==4){
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }

  else if(count==5){
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
  }

  else if(count==6){
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
  }

  else if(count==7){
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
  }

  delay(20);
}
