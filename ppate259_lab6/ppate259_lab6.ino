#include <Time.h>
#include <TimeLib.h>

/*
 * Priyam Patel - 650675226
 * Lab 6
 * Description: Have your arduino get the date(mm/dd/yyyy) & time(hh/mm/ss) from the user via the serial monitor in the arduino software. 
 * Assumptions: Normal setup with LCD and potentiometer, similar to Lab 3, use of the Serial Monitor for user input          
 *              
 * https://www.arduino.cc/en/Serial/Available#.UwYy2PldV8E
 * https://www.pjrc.com/teensy/td_libs_Time.html
 * 
 * 
 
 */
 

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup(){

  Serial.begin(9600);
  lcd.begin(16, 2);
  
int mysecond = 0;
int myminute = 0;
int myhour = 0;
int mymonth = 0;
int date = 0; 
int myyear = 0; 

  //Get hours from user 
  Serial.println("Enter the hour");
  while(Serial.available() == 0){}
  myhour = Serial.parseInt();  // make input an int 
  Serial.print("Hours: ");
  Serial.println(myhour);
  
  // error checking for hours 
  while(myhour >= 24 || myhour < 0){
    Serial.println("Error: Input is Invalid");
    Serial.println("Enter the hour");
    while(Serial.available() == 0){}
    myhour = Serial.parseInt();  // make input an int 
    Serial.print("Hours: ");
    Serial.println(myhour);
  }

  //Get minutes from user 
  Serial.println("Enter the minute");
  while(Serial.available() == 0){}
  myminute = Serial.parseInt();  //make input an int 
  Serial.print("Minutes: ");
  Serial.println(myminute);
  
  // error checking for minutes 
  while(myminute >= 60 || myminute < 0){
    Serial.println("Error: Input is Invalid");
    Serial.println("Enter the minute");
    while(Serial.available() == 0){}
    myminute = Serial.parseInt();  //make input an int 
    Serial.print("Minutes: ");
    Serial.println(myminute);
  }

  //get seconds from user
  //Get minutes from user 
  Serial.println("Enter the second");
  while(Serial.available() == 0){}
  mysecond = Serial.parseInt();  //make input an int 
  Serial.print("Seconds: ");
  Serial.println(mysecond);

  while(mysecond >= 60 || mysecond < 0){
    Serial.println("Error: Input is Invalid");
    Serial.println("Enter the second");
    while(Serial.available() == 0){}
    mysecond = Serial.parseInt();  //make input an int 
    Serial.print("Seconds: ");
    Serial.println(mysecond);
  }

    //Get year from user 
  Serial.println("Enter the year");
  while(Serial.available() == 0){}
  myyear = Serial.parseInt();  //make input an int 
  Serial.print("Year: ");
  Serial.println(myyear);

  while(myyear <= 0){
    Serial.println("Error: Input is Invalid");
    Serial.println("Enter the year");
    while(Serial.available() == 0){}
    myyear = Serial.parseInt();  //make input an int 
    Serial.print("Year: ");
    Serial.println(myyear);
  }

  
  //Get months from user 
  Serial.println("Enter the month");
  while(Serial.available() == 0){}
  mymonth = Serial.parseInt();  //make input an int 
  Serial.print("Month: ");
  Serial.println(mymonth);

  //error checking for months
  while(mymonth > 12 || mymonth <= 0){
    Serial.println("Error: Input is Invalid"); 
    Serial.println("Enter the month");
    while(Serial.available() == 0){}
    mymonth = Serial.parseInt();  //make input an int 
    Serial.print("Month: ");
    Serial.println(mymonth);
  }

  //Get date from user 
  Serial.println("Enter the date");
  while(Serial.available() == 0){}
  date = Serial.parseInt();  //make input an int 
  Serial.print("Date: ");
  Serial.println(date);

  //error checking for date 
  while(date > 31 || date <= 0){
    Serial.println("Error: Input is Invalid"); 
    Serial.println("Enter the date");
    while(Serial.available() == 0){}
    date = Serial.parseInt();  //make input an int 
    Serial.print("Date: ");
    Serial.println(date);
  }

  //even months have 30 days
  while((mymonth == 9 || mymonth == 11 || mymonth == 4 || mymonth == 6) && (date > 30)){
    Serial.println("Error: Input is Invalid");
    Serial.println("Enter the date");
    while(Serial.available() == 0){}
    date = Serial.parseInt();  //make input an int 
    Serial.print("Date: ");
    Serial.println(date);
    
  }

  //february 
  while( (myyear%4 != 0) && (mymonth == 2) && (date > 28 || date < 1)){
    Serial.println("Error: Input is Invalid");
    Serial.println("Enter the date");
    while(Serial.available() == 0){}
    date = Serial.parseInt();  //make input an int 
    Serial.print("Date: ");
    Serial.println(date);
  }

 
  while( (myyear%4 == 0) && (mymonth == 2) && (date > 29 || date < 1)){
    Serial.println("Error: Input is Invalid");
    Serial.println("Enter the date");
    while(Serial.available() == 0){}
    date = Serial.parseInt();  //make input an int 
    Serial.print("Date: ");
    Serial.println(date);
  }
  


  //reset seconds 
  if(mysecond == 59){
    myminute++;
    mysecond = 0;
  }
  
  //reset minutes 
  if(myminute == 59){
    myhour++;
    myminute = 0;
  }
  
  // Reset hours
  if(myhour == 24){
    myhour = 0;
  }

  //pass in parameters
  //takes ints as inputs
  setTime(myhour, myminute, mysecond, date, mymonth, myyear);
}

void loop(){   



  // use first line on LCD for time  
  lcd.setCursor(1,0);

  //so single digit numbers print out correctly
  lcd.clear();

  //print time 
  lcd.print(String(hour()) + ":" + String(minute()) + ":" + String(second()));
  


  //print date on LCD on second line
  lcd.setCursor(0,1);
  lcd.print(String(month()) + "/" + String(day()) + "/" + String(year()) );
  

}
