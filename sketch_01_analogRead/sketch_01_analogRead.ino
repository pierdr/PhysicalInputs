
static int LDR_PIN  = A7;

float workingValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  workingValue = analogRead(LDR_PIN);
  Serial.println(workingValue);
  
  
}
