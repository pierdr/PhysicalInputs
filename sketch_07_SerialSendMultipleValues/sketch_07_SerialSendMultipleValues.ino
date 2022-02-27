#define LDR1_PIN  A7
#define LDR2_PIN  A6

int workingValue1 = 0;
int workingValue2 = 0;

void setup() {
  
  Serial.begin(115200); //Typical values for the baud rate: 9600, 115200
  
  pinMode(LDR1_PIN,INPUT);
  pinMode(LDR2_PIN,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  workingValue1 = analogRead(LDR1_PIN);
  workingValue2 = analogRead(LDR2_PIN);
  
  Serial.print(workingValue1);
  Serial.print(",");
  Serial.print(workingValue2);
  Serial.println();
  delay(10);
}
