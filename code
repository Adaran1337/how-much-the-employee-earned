#include <LiquidCrystal.h>
#define US 6
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int cm = 0;
int salary=lostSalary=0;
long readUltrasonicDistance()
{
pinMode(US, OUTPUT);
digitalWrite(US, LOW);
delayMicroseconds(2);
digitalWrite(US, HIGH);
delayMicroseconds(10);
digitalWrite(US, LOW);
pinMode(US, INPUT);
return pulseIn(US, HIGH);
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0, 0);
cm = 0.01723 * readUltrasonicDistance();
  lcd.clear();
  lcd.print(cm);
  lcd.print(" cm to odject");
delay(100); 
}
