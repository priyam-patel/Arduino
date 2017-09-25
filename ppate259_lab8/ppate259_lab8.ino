/* Name: Priyam Patel
 * Partner: Sid Basu
 * My UIN: 650675226
 * March 30th, 2017
 * Lab #8-Using Two Arduinos, we create a communcation via TX to RX (Vice Versa)
 * Our light and buttons used the digital input and after uploading the program on each arduino, 
 * You will need to connect the RX to TX, and TX to Rx of the boards. You cannot connect them before because it causes an error if you do
 * Assumptions: The light button uses digital output (12) and button uses a digital input (11)
 * We are using two breadboards in which the two arduinos share the same ground power and have a button and led light on each breadboard
 * When we press a button on one bread board, the LED on the other breadboard will be lit and vice versa.
 * References: https://forum.arduino.cc/index.php?topic=365073.0, http://robotic-controls.com/learn/arduino/arduino-arduino-serial-communication
 * http://arduino.stackexchange.com/questions/23876/serial-communication-between-two-arduinos-asking-and-receiving
 * My partner for this lab was Sid Basu in which we used my elegoo board with his arduino board to create this lab
 */

 #include <LiquidCrystal.h> //LCD Library

LiquidCrystal lcd(10, 9, 5, 4, 3,2); //LCD used for debugging
int const ledpin = 12; //Using an led on digital input 12
int const buttonpin = 11; //Using a button on digital input 11

int light = LOW; //initialize the light to be low from the start
int cstate = LOW; //initialize the cstate to be low 
int pstate = LOW; //initialize the pstate to be low 
int counter=0; //Using a counter variable for debugging purposes
int statuss=0; //Creating the Serial.available at 0 initially


void setup() //The setup void function 
{
  lcd.begin(16,2); //The dimension of the lcd screen
  digitalWrite(ledpin, LOW); //Intially making the the ledpin be turned off (So no light)
  Serial.begin(9200); //Creating the dimentional space
  pinMode(buttonpin, INPUT); //Using the buttonpin as the Input
  pinMode(ledpin, OUTPUT); //Using the ledpin as an output
}
//end of setup function

void loop() //The void loop function
{
  counter=0; //Setting the counter at 0 
  cstate = digitalRead(buttonpin); //Setting the cstate variable for digitalRead for button


  if(cstate == HIGH && cstate!=pstate) //If the given state is high and cstate is not pstate
  {
    Serial.write("1"); //If the button is pressed, it will print "1" on the serial communication
    counter++;    //If this condition is being met, increment the counter
  }
  //End of the if statement 

  statuss= Serial.available(); //recognizing statuss as the Serial.avaiable
  
  if(statuss >=1 ) //If the s.avaiable is less than or equal to 1
  {
    while(Serial.available() >= 1) //Same condition as the if statement
    {
      Serial.read(); //No functional use but having a Serial.read to see if while loop is fulfilled
    }//End of while loop

    if(light==HIGH) //If the light state is turned on
    {
      digitalWrite(ledpin,LOW); //make the ledpin do a digitalwrite for low
      light=LOW; //And sequentially make the light low too
      counter++; //Increment the counter
    } //End of if statement 
    
    else //If the light state is turned off 
    {
      digitalWrite(ledpin,HIGH); //make the ledpin do the a digitalwrtie for high
      light=HIGH; //And sequentially make the light high too
      counter++; //Increment the counter
    }
    //end of else statement 
    
  } //end of if statement 
  
   pstate=cstate; //Creating equalized for both given states
   counter++; //Finally incrementing the counter one last time to see if we have the states equal to one another
}
