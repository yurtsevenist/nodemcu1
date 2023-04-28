
#include <FirebaseArduino.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

#define FIREBASE_HOST "iotornek-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "AIzaSyDfpteqSZ1vhufOkvAzs4hHoecM6efqhh8"
#define WIFI_SSID "fatih"
#define WIFI_PASSWORD "!1qaz2WSX3edc4RFV%56"

SoftwareSerial NodeMCU(D2);
String ledstatus;
int salon=12;
void setup() {
  Serial.begin(9600);
  NodeMCU.begin(9600);
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
  Serial.println("Wifi Connected Success!");
  Serial.print("NodeMCU IP Address : ");
  Serial.println(WiFi.localIP() );  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  if (Firebase.failed()) {
  Serial.println(Firebase.error());
  firebasereconnect();
}
else
{
  Serial.println("bağlandı");
}
}
void firebasereconnect(){
  Serial.println("Trying to reconnect");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
 
void loop() {
  Serial.print("Reading from firebase : ");
ledstatus = Firebase.getString("/salon/");
 Serial.println(ledstatus);
 if(ledstatus=="ON"){
  digitalWrite(salon, HIGH);
 }
 else
 {
digitalWrite(salon, LOW);
 } 
}
