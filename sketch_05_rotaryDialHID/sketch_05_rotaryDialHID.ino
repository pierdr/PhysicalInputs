#include <Keyboard.h>

static int CLK = A2;
static int DT = 14;
static int CONTROL_BUTTON = 6;
boolean doNothing = false;


int counter, currentState, prevState;

void setup() {

  //VERIFY THAT BUTTON IS PRESSED OTHERWISE DO NOTHING;
  delay(1000);
  pinMode(CONTROL_BUTTON,INPUT);
  if(digitalRead(CONTROL_BUTTON) == HIGH)
  {
    doNothing = true;
    //with RETURN you exit the setup method (you return) and you don't initialize the keyboard.
    return;
  }
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  prevState = digitalRead(CLK);  
  Serial.begin(115200);
  Keyboard.begin();
}

void loop() {
  
  // put your main code here, to run repeatedly:
  currentState = digitalRead(CLK);
  if(currentState != prevState){
    if(digitalRead(DT) != currentState)
    {
      counter ++;
      Keyboard.print("a");
    }
    else
    {
      counter -- ;
      Keyboard.print("b");
    }   
    prevState = currentState; 
    
  }
 
  Serial.print(digitalRead(CLK));
  Serial.print("\t");
  Serial.print(digitalRead(DT));
  Serial.print("\t");
  Serial.println(counter);
}
