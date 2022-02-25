static int CLK = A2;
static int DT = 14;

int counter, currentState, prevState;

void setup() {
  // put your setup code here, to run once:
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  prevState = digitalRead(CLK);  
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  currentState = digitalRead(CLK);
  if(currentState != prevState){
    if(digitalRead(DT) != currentState)
    {
      counter ++;
    }
    else
    {
      counter -- ;
    }   
    prevState = currentState; 
  
  }
 
  Serial.print(digitalRead(CLK));
  Serial.print("\t");
  Serial.print(digitalRead(DT));
  Serial.print("\t");
  Serial.println(counter);
}
