#include <SparkFun_Si7021_Breakout_Library.h>

#include <LiquidCrystal.h>
#include <Wire.h>

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float temp = 0;
float humidity = 0;
Weather sensor;
int speed= 0;
int fan=3;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  sensor.begin();
  pinMode(fan,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  getTemp();
  lcd.setCursor(0,1);
  getHumid();
  delay(1000);
  lcd.clear();
  if(temp>65){
   speed = 200;
  }
  else{
    speed=0;
  }
  analogWrite(fan,speed);
}

void getTemp() {
  
  temp = sensor.getTempF();

  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" F ");
 


}

void getHumid() {
  humidity = sensor.getRH();
  lcd.print("humidity: ");
  lcd.print(humidity);
  lcd.print("%");
}
