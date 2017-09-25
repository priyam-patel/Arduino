/*
 * Priyam Patel - 650675226
 * Lab 7
 * Description: Program that utilizes interrupts 
 * Assumptions: LCD and Potentiometer basic setup, 2 buttons set up on pins 2 and 3 because they utilize interrupts         
 * References:
 *  https://www.arduino.cc/en/Reference/attachInterrupt
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 7, 6, 5, 4 ); 

//Set up buttons with corresponding pins 
int button1 = 3; //interrupt pin 
int button2 = 2; 

//Keep track of buttons being pressed/interrupt 
boolean interruptState = false; //interrupt state 
boolean buttonPressed = false; //button 2 not pressed 
int button1State; 
int button2State; 

//Manual timer set up 
int timer = 0;

void setup() {
  Serial.begin(9600); 
  lcd.begin(16,2); //Set up lcd
  //set up buttons
  pinMode(button1,INPUT); 
  pinMode(button2,INPUT); 
  //attach interrupts with associated functions 
  //use falling for when pin goes from high to low (buttons being pressed)
  attachInterrupt(digitalPinToInterrupt(button1),InterruptServiceRoutine,FALLING); //Set button1's interrupt to call displayInterrupt
  attachInterrupt(digitalPinToInterrupt(button2),reset,FALLING); //Set button2's interrupt to call reset
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("Waiting for ");
  lcd.setCursor(0,1);
  lcd.print(timer);
  lcd.print(" seconds");
  
  delay(1000); //1 second incrementation 
  
  lcd.clear(); //clear lcd for new timer value after every second
  
  timer++; //increment seconds 
}

//function for if button 1 has been pressed 
//program is in the interrupt state  
void InterruptServiceRoutine(){
  lcd.clear(); 
  
  button2State = digitalRead(button2); 
  
  while(buttonPressed == false){ // button 2 has not been pressed 
    lcd.setCursor(0,0);
    lcd.print("Interrupt received");
    lcd.setCursor(0,1);
    lcd.print("Press Button 2");
    
    if(button2State==LOW){     
      buttonPressed = true; //button 2 pressed 
      interruptState=true; //interrupt state completed
    }
  }
  buttonPressed = false; //back to default 
}

//function that restarts time to 0 seconds 
void reset(){
  if(interruptState==true){ // if button 2 has been pressed after interrupt  
    timer = -1; //Reset timer to 0 (goes to 1 if timer = 0) 
    lcd.clear(); 
    interruptState = false; //Reset interrupt
  }  
}


