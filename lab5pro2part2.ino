#include <SparkFun_Si7021_Breakout_Library.h>

#include <LiquidCrystal.h>
#include <Wire.h>

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float temp = 0;
float humidity = 0;
float mintemp = 0;
float maxtemp = 0;
float minhum = 0;
float maxhum = 0;
int count = 0;
Weather sensor;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  sensor.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  temp = sensor.getTempF();
  humidity = sensor.getRH();
  if (count == 0) {
    mintemp = temp;
    maxtemp = temp;
    minhum = humidity;
    maxhum = humidity;
  }
  if (mintemp > temp) {
    mintemp = temp;
  }
  if (maxtemp < temp) {
    maxtemp = temp;
  }
  if (minhum > humidity) {
    minhum = humidity;
  }
  if (maxhum < humidity) {
    maxhum = humidity;
  }
  printTemp(mintemp, maxtemp, minhum, maxhum);
  delay(1000);
  lcd.clear();
  count++;
}

void printTemp(float minF, float maxF, float minH, float maxH ) {
  lcd.print("T: ");
  lcd.print(minF);
  lcd.print("F,");
  lcd.print(maxF);
  lcd.print("F");
  lcd.setCursor(0, 1);
  lcd.print("H: ");
  lcd.print(minH);
  lcd.print("%,");
  lcd.print(maxH);
  lcd.print("%");

}

void printHumid() {

  lcd.print("humidity: ");
  lcd.print(humidity);
  lcd.print("%");
}
