#include "Arduino.h"
#include <LiquidCrystal.h>

//LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 33, 32, 31, 30);

void setup()
{
    lcd.begin(16,2);
    lcd.print("hello, world!");
    delay(2000);
    lcd.clear();
}

void loop() {
    lcd.setCursor(0, 0);
    lcd.print("HHhm");
    delay(200);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Pommes!");
    delay(200);
    lcd.clear();
}