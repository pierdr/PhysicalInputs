#include <FTDebouncer.h>
#define BUTTON_PIN 7

//How many pins do you want to affect? In this case just one!
FTDebouncer pinDebouncer(1);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // NOTE: 
  // pinDebouncer.addPin(4, HIGH);
  // pinDebouncer.addPin(4, LOW);
  // Specify the PIN number and the logical value of the pin (is it triggered HIGH or LOW?)
  //  pinDebouncer.addPin(2, HIGH, INPUT_PULLUP);
  // INPUT_PULLDOWN is only supported by some microcontrollers
  //pinDebouncer.addPin(3, LOW, INPUT_PULLDOWN); 
  
  pinDebouncer.addPin(BUTTON_PIN, LOW);
  pinDebouncer.init();
  
  Serial.println(sizeof(pinDebouncer));
  Serial.println(pinDebouncer.getPinCount());
}

void loop() {
  // put your main code here, to run repeatedly:
  pinDebouncer.run();
}
void onPinActivated(uint8_t pinNr){
  Serial.print("Pin activated: ");
  Serial.println(pinNr);
}
void onPinDeactivated(uint8_t pinNr){
  Serial.print("Pin deactivated: ");
  Serial.println(pinNr);
}
