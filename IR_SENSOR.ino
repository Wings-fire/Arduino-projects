
#define ir 5
void setup() {
  pinMode(ir,INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(ir)==HIGH)
  {
    Serial.println("Object is Detected");
  }
  else
  {
    Serial.println("Object is not Detcted");
    }
    delay(1000);
}
