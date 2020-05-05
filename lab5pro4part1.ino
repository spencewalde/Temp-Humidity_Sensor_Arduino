#include <SparkFun_Si7021_Breakout_Library.h>

#include <LiquidCrystal.h>
#include <Wire.h>
#define trigPin 4
#define echoPin 2
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);



long duration;
float meandis = 0.0;
float values[50];
float stddev = 0.0;
float distanceCM;
float distanceIN;

void setup() {
  //setup lcd
  lcd.begin(16, 2);
  Serial.begin(9200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {


  for (int i = 0; i < 50; i++) {

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    //gets distance in cm
    distanceCM = duration * 0.034 / 2;
    values[i] = distanceCM;
    meandis += distanceCM;
    delay(10);
  }

  meandis /= 50;
  Serial.print(meandis);
  Serial.print("\n");
  
  for (int i = 0; i < 50; i++) {
    stddev += pow(values[i] - meandis, 2);
  }
  stddev = sqrt(stddev / 50);
  lcd.clear();
  //distanceIN = duration*.0133 /2;
  lcd.print("CM= ");
  lcd.print(meandis);
  lcd.setCursor(0, 1);
  lcd.print(meandis);
  lcd.print(" +- ");
  lcd.print(stddev);
  //lcd.print("Dis-IN= ");
  //lcd.print(distanceIN);
  delay(1000);
  

  distanceCM = 0;
  meandis = 0;
  stddev = 0;

}
