#include<LiquidCrystal.h>
const int echoPin=7;
const int trigPin=6;
int IN1=4;
int IN2=5;
const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int value1;
long duration; 
int distance; 

void setup() {

  pinMode(IN1,OUTPUT);
   pinMode(IN2,OUTPUT);
  
   pinMode(echoPin,INPUT);
pinMode(trigPin,OUTPUT);
   
   Serial.begin(9600);

   lcd.begin(16,2);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("AUTOMATIC DOOR");
   lcd.setCursor(0,1);
   lcd.print("MONITOR SYSTEM");
   Serial.println("AUTOMATIC DOOR MONITOR SYSTEM");
   delay(4000);
}

void loop(){
 
 
  ultracheck();
   delay(1000);
 
 
}


void ultracheck(){
   
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin, HIGH);
  distance=duration*0.034/2;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distance:");
  lcd.print(distance);
  lcd.print("cm");
  delay(1000);
  Serial.print("Distance:");
  Serial.print(distance);
  Serial.println("cm");
  delay(1000);
  if(distance<20)
  { 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("PERSON DETECTED");
    
    digitalWrite(IN1,HIGH);
     digitalWrite(IN2,LOW);
    delay(1000);
     digitalWrite(IN1,HIGH);
     digitalWrite(IN2,HIGH);
    delay(1000);
     digitalWrite(IN1,LOW);
     digitalWrite(IN2,HIGH);
    delay(1000);
  }
  

  else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("NO PERSON");
     digitalWrite(IN1,LOW);
     digitalWrite(IN2,LOW);
    delay(1000);
  }
  
}

