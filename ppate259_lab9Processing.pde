/*
 * Priyam Patel - 650675226
 * Lab 9
 * Description: Connect two analog devices to the arduino and plot the data received on the computer using processing.
 * Assumption: Two devices I used were photoresistor (A0) and potentiometer (A1)         
 * References: https://learn.sparkfun.com/tutorials/connecting-arduino-to-processing#introduction
 *             http://arduino.cc/en/Tutorial/Graph
 */
 
import processing.serial.*;
 
Serial myPort;  // Create object from Serial class
int xPos = 1;
float inByte = 0;     // Data received from the serial port
 
void setup() 
{
// set window size:
  size(400, 300);
// set up port
String portName = Serial.list()[2]; //change the 0 to a 1 or 2 etc. to match your port
myPort = new Serial(this, portName, 9600); 
 
// don't generate a serialEvent() unles you get a newline character:
myPort.bufferUntil('\n');
 
// set inital background
background(0);
}
 
void draw(){
 
  // draw the line:
  stroke(127, 34, 255);
  line(xPos, height, xPos, height - inByte);
 
  // at the edge of the screen, go back to the beginning:
  if(xPos >= width){
    xPos = 0;
    background(0);
  }else{
    // increment the horizontal postion:
    xPos++;
  }
}
 
void serialEvent (Serial myPort){
 
  // get ASCII string:
  String inString = myPort.readStringUntil('\n');
 
  if(inString !=null){
 
    // trim off any whitespace:
    inString = trim(inString);
 
    // convert to an int and map the the screen height:
    inByte = float(inString);
    println(inByte);
    inByte = map(inByte, 0, 1023, 0, height);
  }
 
}