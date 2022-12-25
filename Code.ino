//sketch created by Akshay Joseph
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <string.h>

//SoftwareSerial newSerial(2,3);
LiquidCrystal_I2C lcd(0x27, 16, 2);
String val = "";
String oldval;
String newval = "";
int i = 0;
int iLineNumber = 1;

int led = 8;
int buzzer = 9;

void setup() {

  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.init();
  Serial.begin(9600);
  lcd.backlight();
  //lcd.clear();
  lcd.setCursor(12, 1);
  lcd.print("RUET");
}

void loop() {
  
  val = Serial.readString();
  val.trim();
  if(val != oldval)
  {
    newval = val;
    buz();
  }
  int length = newval.length();
  for(int i = 0; i<length; i++)
  {
    ClearRow(0);
    lcd.print(newval.substring(i,i+15));
    Serial.print(newval);
    delay(500);
    ClearRow(0);
  }
  val = oldval;
  
  
}


void ClearRow(int rowNum)
{
  lcd.setCursor(0,rowNum);
  lcd.print("                 ");
  lcd.setCursor(0,rowNum);
}
void takeInput()
{
  
}

void buz() {
  tone(buzzer, 993, 1000);
  digitalWrite(led, HIGH);
  //digitalWrite(buzzer,HIGH);
  delay(200);
  digitalWrite(led, LOW);
  delay(200);
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
  delay(200);
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
  delay(200);
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);

  //digitalWrite(buzzer,LOW);
  digitalWrite(led, 0);
  delay(4000);
  noTone(buzzer);
}

