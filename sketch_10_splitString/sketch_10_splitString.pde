//RECEIVE MULTIPLE VALUES FROM ARDUINO, AND SPLIT THEM
//Reference the 07_SerialSendMultipleValues
import processing.serial.*;
Serial myPort;

//WORKING VARIABLES (used for logic rather than holding values)
String workingString= null;
String[] workingStringArray;


float value1 = 0; 
float value2 = 0;

void setup()
{
  size(500,500);
   String portName = Serial.list()[2];
   myPort = new Serial(this, portName, 115200); //baud rate
   ellipseMode(CENTER);
}
void draw()
{
  updateSerial();
    background(0);
    fill(255);
    ellipse(map(value1,0,1023,0,width),map(value2,0,1023,0,height),15,15);
}

void updateSerial()
{
  if(myPort.available() > 0) { 
      workingString = myPort.readStringUntil('\n');
      if(workingString != null){
        
        workingString = workingString.trim();
        //CHECK THIS METHOD splitTokens here: https://processing.org/reference/splitTokens_.html
        String[] workingStringArray = splitTokens(workingString, ", ");
        if(workingStringArray.length > 1)
        {
          value1 = parseInt(workingStringArray[0]);
          value2 = parseFloat(workingStringArray[1]);
        }
      }
  }
}
