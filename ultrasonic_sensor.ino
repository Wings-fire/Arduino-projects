#define trig 5
#define echo 4
int distance;
long duration;
void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}

void loop() {
  delay(100);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  duration=pulseIn(echo,HIGH);
  distance=duration*0.034/2;
  Serial.println("The distance is");
  Serial.println(distance);
  delay(1000);

}
