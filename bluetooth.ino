
#include<SoftwareSerial.h>
SoftwareSerial btSerial(14,12);
int led=2;
String data;
void setup() {
  Serial.begin(9600);
  btSerial.begin(9600);
  pinMode(led,OUTPUT);
  Serial.println("Started-------");

}

void loop() {
   if(btSerial.available()>0)
 {
  data=btSerial.readString();
  Serial.println(data);
 }
  if(Serial.available()>0)
  {
    data=Serial.readString();
    Serial.println(data);
  }
}
