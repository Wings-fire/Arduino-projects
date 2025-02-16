
#define ir 5
#define buz 4
void setup() {
  pinMode(ir,INPUT);
  pinMode(buz,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(ir)==HIGH)
  {
    digitalWrite(buz,HIGH);
    Serial.println("Object is Detected");
  }
  else
  {
    digitalWrite(buz,LOW);
    Serial.println("Object is not Detcted");
    }
    delay(1000);
}
