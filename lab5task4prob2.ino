#include <SparkFun_Si7021_Breakout_Library.h>

#include <LiquidCrystal.h>
#include <Wire.h>
#define trigPin 4
#define echoPin 2
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);



long duration;

long values[100];
float times[100];
float velocity;
float displacement;
float distanceCM;
unsigned long t0;

void setup() {
  //setup lcd
  lcd.begin(16, 2);
  Serial.begin(9200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {


  for (int i = 0; i < 100; i++) {
    if (i == 0) {
      times[i] = micros();
    }
    if (i == 99) {
      times[i] = micros();
    }
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);

    distanceCM = duration * 0.034 / 2;
    
    values[i] = distanceCM;
    delay(10);
  }
  /*
  Serial.print("\n time:  ");
  Serial.print(times[99]);
  Serial.print(", ");
  Serial.print(times[0]);
  Serial.print("\n distance:  ");
  Serial.print(values[99]);
  Serial.print(", ");
  Serial.print(values[0]);
  Serial.print("\n\n");
  */
  t0 = (times[99] - times[0]);
  /*
   Serial.print("delta Time US: ");
    Serial.print(t0);
    */
  //difference in time in ms:
  t0 /= 1000;
  
 Serial.print("time: ");
   Serial.print(t0);
   Serial.print("\n");
  
  displacement=(values[99] - values[0]);
  //difference in distance in meters
  displacement *= 1000;
  /*
   Serial.print("\nDelta distance: ");
    Serial.print(displacement);
    */
  velocity =  displacement/ t0;
    Serial.print("Velocity: ");
    Serial.print(velocity);

    //Serial.print("\n\n\n\n");

}
