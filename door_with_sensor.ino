#define door 5
void setup() {
  pinMode(door,INPUT);
  Serial.begin(9600);

}

void loop() {
  if(digitalRead(door)==1)
  {
    Serial.println("Door is Open");
  }
  else
  {
    Serial.println("Door is Closed");
  }
 delay(1000);
}
