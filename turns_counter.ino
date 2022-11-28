#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,6,5,4,3);
float value=0;
float rev=0;
int rpm;
int oldtime=0;
int time;

void isr() //interrupt service routine
{
rev++;
}

void setup()
{
lcd.begin(16,2);                //initialize LCD
pinMode(3,INPUT);
Serial.begin(9600);
lcd.clear();
lcd.setCursor(0,0);
int turns = 0;
}

void loop()
{

if (digitalRead(3)== LOW)
  {
    turns +=1;
    
    delay(1);
}

if ( int (turns/100) == turns/100 ) {
    lcd.setCursor(0,1);
    lcd.print("turns :" + String(turns));
}

}
