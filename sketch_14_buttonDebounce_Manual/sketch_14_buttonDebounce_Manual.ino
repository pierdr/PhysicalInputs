/*Debounce a button without using delays
*/
#define BUTTON_PIN 7
int prev_state = 0;
int current_state = 0;
unsigned long last_pressed_down = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON_PIN, INPUT);
  prev_state = digitalRead(BUTTON_PIN);

  Serial.begin(115200);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  current_state = digitalRead(BUTTON_PIN);
  if(prev_state != current_state)
  {
    if(prev_state == LOW && current_state == HIGH)
    {
      last_pressed_down = millis();
      Serial.println(" button down");
      
    }
    else if(prev_state == HIGH && current_state == LOW)
    {
      Serial.print("button up! Was pressed for:");
      Serial.print(millis()-last_pressed_down);
      Serial.println(" milliseconds");
    }
  }
 
  prev_state = current_state;
}
