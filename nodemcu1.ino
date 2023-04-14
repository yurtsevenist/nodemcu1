#include <FirebaseArduino.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

#define FIREBASE_HOST "https://nodemcu1-8058b-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "AIzaSyAOcL8mN6r_XF2Vn7fL4iNxdLskP_nZk10"
#define WIFI_SSID "my"
#define WIFI_PASSWORD "mustafa2549"

SoftwareSerial NodeMCU(D2);
String ledstatus;
int led1=12;
void setup() {
  Serial.begin(9600);
  NodeMCU.begin(9600);
  servo.attach(5);
  servo.write(0);
  pinMode(D2, INPUT);
  pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
   
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
ledstatus = Firebase.getString("/led/");
 Serial.println(ledstatus);
 if(ledstatus=="ON"){
  digitalWrite(led, HIGH);
 }
 else
 {
digitalWrite(led, LOW);
 } 
}
