#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <DHT.h>

WiFiClient wificlient;
ESP8266WiFiMulti wifiMulti;

#define DHTTYPE DHT11
#define DHTPIN 14 //D5
DHT dht(DHTPIN, DHTTYPE);
HTTPClient http;    //Declare object of class HTTPClient

String  Link1, Link2, c, payload1, payload2, getData, getData2;
int httpCode1, httpCode2,a=11;
int t1,h1;


void setup() {
  
  Serial.begin(9600);
  dht.begin();
  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
  //wifiMulti.addAP("Kiran89192", "8892@Kiran");
  //wifiMulti.addAP("kmrkrmd", "kmrkkmrk");
  //wifiMulti.addAP("oneplus", "r12345678");
  //wifiMulti.addAP("Redmi 9A", "12345678");
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
  t1 = dht.readTemperature();
  h1= dht.readHumidity();
  getData= String(t1)+ "/" +String(h1);
  Serial.println(getData);
  Link2 ="http://192.168.235.158:5000/add/"+getData;http://192.168.235.158:5000
  http.begin(wificlient,Link2);
  httpCode1 = http.GET();
  payload1 = http.getString();
  Serial.println(httpCode1);
  Serial.println(payload1);
  delay(2000);

  
}
