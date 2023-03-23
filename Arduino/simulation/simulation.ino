//pins for sensor
#define echoPin 7
#define trigPin 6

//pins for motor

#define FwdRot_LeftMotor 2
#define BckRot_LeftMotor 3
#define FwdRot_RgtMotor 4 
#define BckRot_RgtMotor 5

//pins for LCD display
#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,8,9,10,11);

long duration;
int distance;

void setup()
{
  pinMode(echoPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(FwdRot_LeftMotor, OUTPUT);
  pinMode(BckRot_LeftMotor, OUTPUT);
  pinMode(FwdRot_RgtMotor, OUTPUT);
  pinMode(BckRot_RgtMotor, OUTPUT);
  lcd.begin(16, 2);
}


void loop() 
{

  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration=pulseIn(echoPin , HIGH);
  distance= duration * 0.034/2;

  lcd.setCursor(0,0);
  lcd.print("Distance");
  lcd.setCursor(9,0);
  lcd.print(distance);

  if(distance>=500)
  {
    //rotate in opposite direction
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Moving Back"); 
    lcd.setCursor(0,0);
  
  lcd.print("Distance");
  lcd.setCursor(9,0);
  lcd.print(distance);

    digitalWrite(BckRot_LeftMotor,HIGH);
    digitalWrite(BckRot_RgtMotor,HIGH);

    
    
    digitalWrite(FwdRot_LeftMotor,LOW);
    digitalWrite(FwdRot_RgtMotor,LOW);

    delay(1000);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Moving Left");
      
      lcd.setCursor(0,0);
  lcd.print("Distance");
  lcd.setCursor(9,0);
  lcd.print(distance);
    //rotate in left/right direction
    digitalWrite(BckRot_LeftMotor,HIGH);
    digitalWrite(BckRot_RgtMotor,LOW);

    
    digitalWrite(FwdRot_LeftMotor,HIGH);
    digitalWrite(FwdRot_RgtMotor,LOW);
    delay(500);
  }
  else
  {
    //moving forward
    lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Moving Forward");

    lcd.setCursor(0,0);
  lcd.print("Distance");
  lcd.setCursor(9,0);
  lcd.print(distance);
     //moving forward
    digitalWrite(BckRot_LeftMotor,LOW);
    digitalWrite(BckRot_RgtMotor,LOW);

    
    digitalWrite(FwdRot_LeftMotor,HIGH);
    digitalWrite(FwdRot_RgtMotor,HIGH);
    delay(500);
  }
}
