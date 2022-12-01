#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); //need this text to work
float value=0;
float rev=0;
int rpm;
int oldtime=0;
int time;
float turns = 0;

#define DIGITAL_PIN 2
boolean sensorOut = HIGH;

boolean previous_read = true;
boolean display_done = false;

void setup()
{
lcd.begin(16,2);                //initialize LCD
Serial.begin(9600);
pinMode(DIGITAL_PIN, INPUT);

lcd.clear();
lcd.setCursor(0,0);
// lcd.print("turns : 0");
}

void loop()
{
sensorOut = digitalRead(DIGITAL_PIN);
if (sensorOut == HIGH && previous_read ==false)
  {
    turns +=1;
    previous_read = true;
    display_done = false;
    
    // delay(1);
}

if (sensorOut == LOW)
  {
    previous_read = false;
    
    // delay(1);
}

if ( int (turns/10) == turns/10 && turns > 0 && display_done == false) {
    lcd.setCursor(0,1);
    lcd.print("turns :" + String(turns));
    Serial.println(turns);
    display_done = true;
}

}
