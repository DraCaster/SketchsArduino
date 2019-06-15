#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2); 

void setup(){
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hi Lushan");
  delay(3000);
}

void loop(){
  for (int c=0; c<12;c++){
    lcd.scrollDisplayLeft();
    delay(400);
  }
  for (int c=0; c<12; c++){
    lcd.scrollDisplayRight();
    delay(400);
  }
}

