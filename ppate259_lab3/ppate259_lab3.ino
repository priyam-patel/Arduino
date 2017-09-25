/*
 * Priyam Patel - 650675226
 * Lab 3
 * Description: Use LCD screen to print name and scrolling quote
 * Assumption: The set up needs to be the same as the tutorial's with the wiring
 *             The potentiometer needs to be slightly turned, so not too bright
 * References: 
               http://www.arduino.cc/en/Tutorial/LiquidCrystalScroll
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String line1 = "Priyam Patel";
char quote[] = "Be yourself; everyone else is already taken.";


 
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  
    lcd.setCursor(0,1);
    lcd.print(quote);    
 
    lcd.setCursor(0,0);
    lcd.print("Priyam Patel");
    
    char firstChar = quote[0];
    int i;
   for(i=0; i<44 && quote[i+1]!=0; i++){
    quote[i] = quote[i+1];
    }

    quote[i] = firstChar;
    
    delay(400);
    
    

  }

