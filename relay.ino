#define relay 5
void setup() {
  pinMode(relay,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(relay,LOW);
  Serial.println("Relay is ON");
  delay(3000);
  digitalWrite(relay,HIGH);
  Serial.println("Relay is OFF");
  delay(5000);

}
