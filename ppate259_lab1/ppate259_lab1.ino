// Priyam Patel - 650675226
// Lab 1
// Description - Blink different LEDS at different times, and connect the board LED to pin 13
// I have made the assumption that these LEDs are naturally super bright because I only used a 220 resistor and they were still very bright
// References - Link posted on blackboard, arduino tutorials 


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize pin 13 as an output.
  pinMode(13, OUTPUT);
  // initialize pin 3 as an output.
  pinMode(3, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(300);   
  digitalWrite(LED_BUILTIN, LOW); // turn the LED off by making the voltage LOW
  digitalWrite(10, HIGH); //now turn the pin associated with the RED LED ON
  delay(300);
  digitalWrite(10,LOW); //turn the red LED OFF 
  digitalWrite(3,HIGH); // turn the green LED ON 
  delay(300);
  digitalWrite(3,LOW); //turn the green LED OFF 
  delay(300);
}
