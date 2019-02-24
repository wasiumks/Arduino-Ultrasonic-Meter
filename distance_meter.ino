#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define trigPin 12
#define echoPin 11 
#define redLedPin 9
#define greenLedPin 8
#define buzzerPin 7

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
  
void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin(16,2);  
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Distance meter");
  lcd.setCursor(0,1);
  lcd.print("v0.1");
  digitalWrite(greenLedPin,HIGH);
  digitalWrite(redLedPin, HIGH);
  digitalWrite(buzzerPin, HIGH);
  delay(2000);
  digitalWrite(redLedPin, LOW);
  digitalWrite(greenLedPin,LOW);
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distance:");
  lcd.setCursor(0,1);
  range(0, 30); 
  delay(50);
}

int measureDistance() {
  long time, distance;
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  time = pulseIn(echoPin, HIGH);
  distance = time / 58;
 
  return distance;
}

void range(int a, int b) {
  int howFar = measureDistance();
  if ((howFar > a) && (howFar < b)) {
      digitalWrite(greenLedPin, LOW);
      digitalWrite(buzzerPin, HIGH); 
      digitalWrite(redLedPin, HIGH);
      lcd.print(howFar);
  } else {
      digitalWrite(buzzerPin, LOW); 
      digitalWrite(redLedPin, LOW);
      digitalWrite(greenLedPin, HIGH);
      lcd.print(howFar);
  }
}
  
