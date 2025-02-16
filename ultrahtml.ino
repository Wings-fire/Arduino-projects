#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

WiFiClient wificlient;
ESP8266WiFiMulti wifiMulti;

#define trig 4
#define echo 5
#define led1 2
#define led2 0
#define led3 14
long duration;
int distance;

HTTPClient http;    //Declare object of class HTTPClient

String  Link1, Link2, c, payload1, payload2, getData, getData2;
int httpCode1, httpCode2,a=11;
int t1,h1;


void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  
  
  Serial.begin(9600);
 
  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
  //wifiMulti.addAP("Kiran89192", "8892@Kiran");
  //wifiMulti.addAP("kmrkrmd", "kmrkkmrk");
  //wifiMulti.addAP("oneplus", "r12345678");
  //wifiMulti.addAP("Redmi 9A", "12345678");
  //wifiMulti.addAP("EnthuTech_New", "3T5_20z1_1234");
    wifiMulti.addAP("Teju", "12345678");
  
  
  Serial.print("Connecting");  // Wait for connection
  while (wifiMulti.run() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  

 
  delay(200); 
}


void loop()
{
 delay(100);
 digitalWrite(trig,LOW);
 delayMicroseconds(10);
 digitalWrite(trig,HIGH);
 delayMicroseconds(2);
 digitalWrite(trig,LOW);
 duration=pulseIn(echo,HIGH);
 distance=duration*0.034/2;
 Serial.print("Distance");
 Serial.println(distance);
 if(distance<50)
 {
  Serial.println("Some one cross the border");
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
 }
 if(distance>50&& distance<150)
 {
  Serial.println("Some one near to the border");
  digitalWrite(led1,LOW);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
 }
 delay(200);
  getData= String(distance);//+ "/" +String(h1);
  Serial.println(getData);
  Link2 =" http://192.168.184.158:5000/add/"+getData; //http://192.168.43.48:5000
  http.begin(wificlient,Link2);
  httpCode1 = http.GET();
  payload1 = http.getString();
  Serial.println(httpCode1);
  Serial.println(payload1);
  delay(2000);

  
}
