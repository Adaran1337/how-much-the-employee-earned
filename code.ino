#include <LiquidCrystal.h>
#define US 6
#define BUTTON 7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int cm = 0;
int salary=0;
int lostSalary=0;
int rate=5;
bool switchMode=false;
bool butt_state=false;
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
  pinMode(BUTTON,INPUT_PULLUP);
  lcd.begin(16, 2);
}
bool buttonState(){

}
void loop() {
  lcd.setCursor(0, 0);
cm = 0.01723 * readUltrasonicDistance();
  lcd.clear();
  lcd.print(cm);
  lcd.print(" cm to odject");
  lcd.setCursor(0, 1);
  if(cm<100)
  salary+=rate;
  else
  lostSalary+=rate;
  if(!digitalRead(BUTTON)&&butt_state==false){
    if(switchMode)
      switchMode=false;
    else 
      switchMode=true;
    butt_state=true;
  }
if(digitalRead(BUTTON)&&butt_state==true)
  butt_state=false;
  if(switchMode){
  lcd.print("Salary: ");
    lcd.print(salary);}
  else{
    lcd.print("LostSalary: ");
    lcd.print(lostSalary);
  }
delay(100); 
}
