/* Priyam Patel - 650675226
 * Lab 4
 * Description: Use a photocell and display the amount of light in a room on the LCD screen
 * Assumption: LCD needs to be properly wired, used the 10k resistor for the photoresistor, 4 1k resistors for the rest
 * References: http://playground.arduino.cc/Learning/PhotoResistor
 *  
 */
  
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup() { //initialise for at least 2s
  lcd.begin(16, 2);
}
void loop()
{
 int sensorValue = analogRead(A0);
 Serial.println(sensorValue);
 int level = sensorValue;
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("LIGHT LEVEL:");
 lcd.print(level);
 lcd.setCursor(0, 1);
  
 if ((level >= 0) && (level <= 100))
 {
  lcd.print("DARK"); 
 }
 else if ((level > 100) && (level <= 300))
 {
  lcd.print("PARTIALLY DARK"); 
 }
 else if ((level > 300) && (level <= 600))
 {
  lcd.print("MEDIUM"); 
 }
 else if ((level > 600) && (level <=800))
 {
  lcd.print("LIGHT");
 }
 else
 {
  lcd.print("FULLY LIT"); 
 }
  
 delay(500); 
}
