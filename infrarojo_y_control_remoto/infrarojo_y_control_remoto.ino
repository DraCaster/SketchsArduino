
#include <IRremote.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2); 
int RECV_PIN = 3;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  irrecv.enableIRIn(); // Empezamos la recepción  por IR
  pinMode(13, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hi Lushan");
}

boolean on = LOW;

void loop() {
  if (irrecv.decode(&results)) {
    // Dato recibido, conmutamos el LED
    on = !on;
    digitalWrite(13,  on? HIGH : LOW); 
    if (on == LOW){
      lcd.clear();
      lcd.print("Apagado");
    }
    else{
      lcd.clear();
      lcd.print("Prendido");
    }
    irrecv.resume(); // empezamos una nueva recepción
  }
  delay(300);
}
