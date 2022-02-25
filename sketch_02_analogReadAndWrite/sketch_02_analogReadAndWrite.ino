static int LED_PIN =  11; //TO MODULATE THE LED INTENSITY YOU NEED TO USE A PWM PIN
static int LDR_PIN =  A7; 

float workingValue = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(LDR_PIN,INPUT);
  pinMode(LED_PIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  workingValue = analogRead(LDR_PIN);
  analogWrite(LED_PIN,map(workingValue,0,1023,255,0)); // You need to use a PWM Pin - Pulse Width Modulation
  
   
}
