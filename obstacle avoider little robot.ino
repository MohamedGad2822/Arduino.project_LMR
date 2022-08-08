#include <SoftwareSerial.h>

#include <NewPing.h>

SoftwareSerial BT(0,1);
String device ;

#define IN1 7
#define ENA 6
#define IN2 5

#define IN3 4
#define ENB 3
#define IN4 8

int trig2 =11;
int echo2 =10;
int maX2 = 200;

int trig1 = 13;
int echo1  = 12;
int maX1 =200;

NewPing sonic1(trig1 , echo1 ,maX1);

NewPing sonic2(trig2 , echo2 ,maX2);

int isObstaclePin = 2;  // This is our input pin
int isObstacle = HIGH;  // HIGH MEANS NO OBSTACLE

void setup () {
  BT.begin(9600);
  Serial.begin(9600);
  
  pinMode(isObstaclePin, INPUT);
  
  pinMode(IN1 , OUTPUT);
  pinMode(IN2 , OUTPUT);
  pinMode(ENA , OUTPUT);

  pinMode(IN3 , OUTPUT);
  pinMode(IN4 , OUTPUT);
  pinMode(ENB , OUTPUT);
}
 void loop() {
  int us1 =sonic1.ping();
  int dis1 =us1 / US_ROUNDTRIP_CM ;

  int us2 =sonic2.ping();
  int dis2 = us2 / US_ROUNDTRIP_CM;
  if (BT.available()){
  delay(100);
  char c = BT.read();
  device = c;
  }
  if (device.length() >0) {
    Serial.println(device);

  if(device == "f")
  {
    digitalWrite(IN1 , LOW);
    digitalWrite(IN2 , HIGH);
    analogWrite(ENA, 120);

    digitalWrite(IN3 , LOW);
    digitalWrite(IN4 , HIGH);
    analogWrite(ENB, 120);
  } 
   if (device == "s"){
    
    digitalWrite(IN1 , LOW);
    digitalWrite(IN2 , LOW);
    analogWrite(ENA, 0);

    digitalWrite(IN3 , LOW);
    digitalWrite(IN4 , LOW);
    analogWrite(ENB, 0);
    }
    if (device =="r"){
      digitalWrite(IN1 , HIGH);
      digitalWrite(IN2 , LOW);
      analogWrite(ENA, 250);

      digitalWrite(IN3 , LOW);
      digitalWrite(IN4 , HIGH);
      analogWrite(ENB, 250);
    }
    if(device == "l"){
      digitalWrite(IN1 , LOW);
      digitalWrite(IN2 , HIGH);
      analogWrite(ENA, 120);

      digitalWrite(IN3 , HIGH);
      digitalWrite(IN4 , LOW);
      analogWrite(ENB, 120);      
    }
    if(device =="b"){
      digitalWrite(IN1 , HIGH);
      digitalWrite(IN2 , LOW);
      analogWrite(ENA, 120);

      digitalWrite(IN3 , HIGH);
      digitalWrite(IN4 , LOW);
      analogWrite(ENB, 120);
    }
    if(device =="a"){
     isObstacle = digitalRead(isObstaclePin);
     if (isObstacle == LOW)
     {
      if (dis1 < 10) {
       digitalWrite(IN1 , HIGH);
       digitalWrite(IN2 , LOW);
       analogWrite(ENA, 250);

       digitalWrite(IN3 , LOW);
       digitalWrite(IN4 , HIGH);
       analogWrite(ENB, 250);
      }
      if (dis2 < 10){
       digitalWrite(IN1 , LOW);
       digitalWrite(IN2 , HIGH);
       analogWrite(ENA, 120);

       digitalWrite(IN3 , HIGH);
       digitalWrite(IN4 , LOW);
       analogWrite(ENB, 120); 
      }
      if (dis1 > 10 && dis2 > 10) {
       digitalWrite(IN1 , LOW);
       digitalWrite(IN2 , HIGH);
       analogWrite(ENA, 120);

       digitalWrite(IN3 , LOW);
       digitalWrite(IN4 , HIGH);
       analogWrite(ENB, 120);
       } 
     } 
     if (isObstacle == HIGH){
      digitalWrite(IN1 , LOW);
      digitalWrite(IN2 , LOW);
      analogWrite(ENA, 0);

      digitalWrite(IN3 , LOW);
      digitalWrite(IN4 , LOW);
      analogWrite(ENB, 0); 
     }
    }
   }
 }
