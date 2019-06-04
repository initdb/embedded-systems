#include "Arduino.h"
#include <LiquidCrystal.h>

//LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 33, 32, 31, 30);

void setup()
{
    lcd.begin(16,1);
    lcd.print("hello, world!");
}

void loop() {
    lcd.print("HHhm");
    delay(2000);
    lcd.clear();
    lcd.print("Pommes!");
    delay(1000);
    lcd.clear();
}