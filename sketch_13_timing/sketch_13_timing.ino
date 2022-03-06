/* with this sketch you are learning how to create a blink without delay
 *  delay is bad generally, because blocks the execution of all the other code in the sketch
 */
#define LED_PIN 13
unsigned long timeOfEventLastFired = 0;
boolean isOn = false;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN,OUTPUT);
}

void loop() {
  /*
  WHAT IS MILLIS? 
      https://www.arduino.cc/reference/en/language/functions/time/millis/
  */
  
  if(millis()-timeOfEventLastFired > 300)
  {
    timeOfEventLastFired = millis();
    if(isOn)
    {
      digitalWrite(LED_PIN, HIGH);
    }
    else
    {
      digitalWrite(LED_PIN, LOW);
    }
    //This is equivalent of saying 
    // isOn = (opposite of) isOn;
    // if isOn is true make it false
    // if isOn is false make it true
    isOn = !isOn;
  }
}
