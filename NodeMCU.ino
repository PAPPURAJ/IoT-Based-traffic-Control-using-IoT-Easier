#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
#include <Servo.h>

#define FIREBASE_HOST "iot-traffic-54efa-default-rtdb.firebaseio.com"  //Database link
#define FIREBASE_AUTH "AbNey3fFggcQM55oK6uCZv1V8tQheVCa6MibWxQK"  //Database secrate

#define WIFI_SSID "IOT TRAFFIC"      //Router name
#define WIFI_PASSWORD "12345678"  //Router password

FirebaseData firebaseData;

int r1=D0,Y1=D1,g1=D2,r2=D3,g2=D5,y2=D4,t1=D6,t2=D7;

int waitingTime=15;


void setVal(String path, String v){
  Firebase.setString(firebaseData,"/AnalogOutput/"+path,v);
} 





void setup() {
    pinMode(r1,OUTPUT);
    pinMode(g1,OUTPUT);
    pinMode(Y1,OUTPUT);
    pinMode(r2,OUTPUT);
    pinMode(g2,OUTPUT);
    pinMode(y2,OUTPUT);
    pinMode(t1,INPUT);
    pinMode(t2,INPUT);


  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  
  while (WiFi.status() != WL_CONNECTED)
  {
    digitalWrite(D4,0);
    Serial.print(".");
    delay(200);
    digitalWrite(D4,1);
    Serial.print(".");
    delay(200);
    
  }
  
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  Firebase.setString(firebaseData,"/Testing","OK!");;
}

void loop() {
  if(!digitalRead(t1) && !digitalRead(t2)){

      for(int i=0;i<waitingTime-5  && !digitalRead(t1) && !digitalRead(t2);i++){
          Serial.println(i+1);
          digitalWrite(r1,0);
          digitalWrite(g1,1);
          digitalWrite(Y1,0);
          
          digitalWrite(r2,1);
          digitalWrite(g2,0);
          digitalWrite(y2,0);
          setVal("1 RED","Off");
          delay(200);
          setVal("1 GREEN","On");
          delay(200);
          setVal("1 YELLOW","Off");
          delay(200);
          setVal("2 RED","On");
          delay(200);
          setVal("2 GREEN","Off");
          delay(200);
          setVal("2 YELLOW","Off");
          delay(200);
          
          
      }
          setVal("2 RED","Off");
          delay(200);
          setVal("2 GREEN","Off");
          delay(200);
          setVal("2 YELLOW","On");
          delay(200);
          
          digitalWrite(r2,0);
          digitalWrite(g2,0);
          digitalWrite(y2,1);
      
      delay(3000);

      for(int i=0;i<waitingTime-5 && !digitalRead(t1) && !digitalRead(t2);i++){
          Serial.println(i+1);
          digitalWrite(r1,1);
          digitalWrite(g1,0);
          digitalWrite(Y1,0);       
          digitalWrite(r2,0);
          digitalWrite(g2,1);
          digitalWrite(y2,0);
          setVal("1 RED","On");
          delay(200);
          setVal("1 GREEN","Off");
          delay(200);
          setVal("1 YELLOW","Off");
          delay(200);
          setVal("2 RED","Off");
          delay(200);
          setVal("2 GREEN","On");
          delay(200);
          setVal("2 YELLOW","Off");
          delay(200);
      }
          digitalWrite(r1,0);
          digitalWrite(g1,0);
          digitalWrite(Y1,1);
                    setVal("1 RED","Off");
          delay(200);
          setVal("1 GREEN","Off");
          delay(200);
          setVal("1 RED","Off");
          delay(200);
          setVal("1 YELLOW","On");
         delay(3000);
      
  }else if(!digitalRead(t2)){
          digitalWrite(r1,1);
          digitalWrite(g1,0);
          digitalWrite(Y1,0);
          digitalWrite(r2,0);
          digitalWrite(g2,1);
          digitalWrite(y2,0);
          setVal("1 RED","On");
          delay(200);
          setVal("1 GREEN","Off");
          delay(200);
          setVal("1 YELLOW","Off");
          delay(200);
          setVal("2 RED","Off");
          delay(200);
          setVal("2 GREEN","On");
          delay(200);
          setVal("2 YELLOW","Off");
          delay(200);
         
  }
else if(!digitalRead(t1)){
          digitalWrite(r1,0);
          digitalWrite(g1,1);
          digitalWrite(Y1,0);  
          digitalWrite(r2,1);
          digitalWrite(g2,0);
          digitalWrite(y2,0);   
          setVal("1 RED","Off");
          delay(200);
          setVal("1 GREEN","On");
          delay(200);
          setVal("1 YELLOW","Off");
          delay(200);
          setVal("2 RED","On");
          delay(200);
          setVal("2 GREEN","Off");
          delay(200);
          setVal("2 YELLOW","Off");
          delay(200);
         
  }else{
          digitalWrite(r1,0);
          digitalWrite(g1,1);
          digitalWrite(Y1,0);
          
          digitalWrite(r2,0);
          digitalWrite(g2,1);
          digitalWrite(y2,0);
          setVal("1 RED","Off");
          delay(200);
          setVal("1 GREEN","On");
          delay(200);
          setVal("1 YELLOW","Off");
          delay(200);
          setVal("2 RED","Off");
          delay(200);
          setVal("2 GREEN","On");
          delay(200);
          setVal("2 YELLOW","Off");
          delay(200);
  }

  


}
