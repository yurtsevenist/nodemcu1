
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>

#define FIREBASE_HOST "iotornek-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "AIzaSyDfpteqSZ1vhufOkvAzs4hHoecM6efqhh8"
#define WIFI_SSID "my1"
#define WIFI_PASSWORD "yurtseven226823"

FirebaseData data;
String ledstatus;
int salon=12;
void setup() {
  Serial.begin(115200);  
   pinMode(salon, OUTPUT);   
  Serial.println();
  Serial.print("Wifi connecting to ");
  Serial.println(WIFI_SSID);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 
  Serial.print("Connecting");
 
  while ( WiFi.status() != WL_CONNECTED ) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  
  // Start the server
  //server.begin();
  Serial.println("Server started");
  Serial.println("Wifi Connected Success!");
  Serial.print("NodeMCU IP Address : ");
  Serial.println(WiFi.localIP() );
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}

 
void loop() {
  Serial.print("Reading from firebase : ");
    Firebase.getString(data,"salon/status"); 
  Serial.println("salon değer "+ data.stringData());
  if(data.stringData()=="ON")
    {
  digitalWrite(salon, HIGH);
 }
 else
 {
digitalWrite(salon, LOW);
 } 
}
