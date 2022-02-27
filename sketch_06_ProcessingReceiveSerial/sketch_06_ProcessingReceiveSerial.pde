//THIS SKETCH WORKS WITH sketch_04_Serial on the arduino side

import processing.serial.*;

Serial myPort;
int val;
String mystring= null;
int nl=10;



void setup() 
{
  size(200, 200);
  String portName = Serial.list()[2];
  myPort = new Serial(this, portName, 115200); //baud rate
  textAlign(CENTER);
}

void draw()
{
  updateSerial();
  background(map(val,0,1023,0,255));
  fill(77,77,77);
  //THIS IS how to convert a number into a character. Numbers from 65 to 90 are letters from A to Z
  //CHECK MORE ABOUT THE ALPHANUMERIC CODES HERE: https://www.asciitable.com
  int characterIndex =   int(map(val,0,1023,90,65));
  char ch = (char)( characterIndex); 
  text(""+ch,width/2,height/2);
}

void updateSerial()
{
  if ( myPort.available() > 0) {  // If data is available,
    //val = myPort.read();         // read it and store it in val
    mystring = myPort.readStringUntil('\n');
    if(mystring != null){
      println(mystring);
      mystring = mystring.trim();
      val=parseInt(mystring);

    }
      println(val); 
  }
}
