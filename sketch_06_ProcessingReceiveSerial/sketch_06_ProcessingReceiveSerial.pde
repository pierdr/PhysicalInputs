import processing.serial.*;

Serial myPort;
int val;
String mystring= null;
int nl=10;

void setup() 
{
  size(200, 200);

  println(Serial.list());
  String portName = Serial.list()[2];
  myPort = new Serial(this, portName, 115200); //baud rate
}

void draw()
{
  updateSerial();
  background(val);
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
      val = (int) map(val,0,1023,0,255);
    }
      println(val); 
  }
}
