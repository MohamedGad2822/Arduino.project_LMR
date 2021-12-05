#include <SoftwareSerial.h>
#include <Servo.h>

String device;

Servo s1;
int pos1;


#define in1 A0
#define en1 3
#define in2 A1

#define in3 A2
#define en2 4
#define in4 A3

#define in5 A4
#define en3 5
#define in6 A5

#define in7 A6
#define en4 6
#define in8 A7

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.setTimeout(3);

s1.attach(9);

pinMode (in1,OUTPUT);
pinMode (en1,OUTPUT);
pinMode (in2,OUTPUT);
pinMode (in3,OUTPUT);
pinMode (en2,OUTPUT);
pinMode (in4,OUTPUT);


pinMode (in5,OUTPUT);
pinMode (en3,OUTPUT);
pinMode (in6,OUTPUT);
pinMode (in7,OUTPUT);
pinMode (en4,OUTPUT);
pinMode (in8,OUTPUT);

}

void loop() {
  if(Serial.available()){
    device = Serial.readString(); 
   }
  if (device.length()>0){
   Serial.println(device);
   
   if (device.substring(0 , 2) =="S1"){
    pos1 = (device.substring(2)).toInt();
    s1.write(pos1);
    
   if (device =="f"){
    forward();   
   }
  
   if (device =="b"){
    back();
    }
 
   if (device =="l"){
    left();
  }
  
   if (device =="r"){
    right();
  }
   if (device =="s"){
    stop();
  }
   }
}
}  

void forward(){
  digitalWrite (in1,HIGH);
  analogWrite (en1,1023);
  digitalWrite (in3,HIGH);
  
  digitalWrite (in2,LOW);
  digitalWrite (in4,LOW);
  analogWrite (en2,1023);

  digitalWrite (in5,HIGH);
  analogWrite (en3,1023);
  digitalWrite (in7,HIGH);
  
  digitalWrite (in6,LOW);
  digitalWrite (in8,LOW);
  analogWrite (en4,1023);
}
void back(){
  digitalWrite (in1,LOW);
  analogWrite (en1,1023);
  digitalWrite (in3,LOW);
  
  digitalWrite (in2,HIGH);
  digitalWrite (in4,HIGH);
  analogWrite (en2,1023);
  
  digitalWrite (in5,LOW);
  analogWrite (en3,1023);
  digitalWrite (in7,LOW);
  
  digitalWrite (in6,HIGH);
  digitalWrite (in8,HIGH);
  analogWrite (en4,1023);

}
void stop(){
  digitalWrite (in1,LOW);
  analogWrite (en1,0);
  digitalWrite (in3,LOW);
  
  digitalWrite (in2,LOW);
  digitalWrite (in4,LOW);
  analogWrite (en2,0); 
  
  digitalWrite (in5,LOW);
  analogWrite (en3,0);
  digitalWrite (in7,LOW);
  
  digitalWrite (in6,LOW);
  digitalWrite (in8,LOW);
  analogWrite (en4,0);
}
void left(){
  digitalWrite (in1,HIGH);
  analogWrite (en1,1023);
  digitalWrite (in3,HIGH);
  
  digitalWrite (in2,LOW);
  digitalWrite (in4,LOW);
  analogWrite (en2,1023);
  
  digitalWrite (in5,LOW);
  analogWrite (en3,1023);
  digitalWrite (in7,LOW);
  
  digitalWrite (in6,HIGH);
  digitalWrite (in8,HIGH);
  analogWrite (en4,1023);

}
void right(){
  digitalWrite (in1,LOW);
  analogWrite (en1,1023);
  digitalWrite (in3,LOW);
  
  digitalWrite (in2,HIGH);
  digitalWrite (in4,HIGH);
  analogWrite (en2,1023);

  digitalWrite (in5,HIGH);
  analogWrite (en3,1023);
  digitalWrite (in7,HIGH);
  
  digitalWrite (in6,LOW);
  digitalWrite (in8,LOW);
  analogWrite (en4,1023);
}
