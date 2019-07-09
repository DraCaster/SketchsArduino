#include <LiquidCrystal_I2C.h>
#include <IRremote.h>
#include <Servo.h>
#include <Wire.h>

int RECV_PIN = 3;
IRrecv irrecv(RECV_PIN);
decode_results results;
Servo servoMotor; //Para controlar el servo

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  byte cara[8] = {
        B00000,
        B11011,
        B11011,
        B00000,
        B10001,
        B01110,
        B00000,
   };
   byte corazon[8] = {
    B00000,
    B01010,
    B10101,
    B10001,
    B10001,
    B01010,
    B00100,
    B00000,
   };
  lcd.createChar(0,cara);
  lcd.createChar(1,corazon);
  irrecv.enableIRIn(); //Inicio de recepcion por IR
  servoMotor.attach(11); //Servo conectado al pin 11
  servoMotor.write(0); //Inicio al angulo 0 del servo
}


void loop() {
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.write(byte (1));
  lcd.print(" ");
  lcd.print("Catduino");
  lcd.print(" ");
  lcd.write(byte (1));
  lcd.setCursor(0,1);
  lcd.write (byte (0));
  lcd.print(" By: Lu - shan");
  delay(300);
  if (irrecv.decode(&results)){
      lcd.clear();
      switch(results.value){
        case 0x00FF629D:  lcd.print("Tecla arriba");
                          break;
        case 0x00FF22DD:  lcd.print("Tecla izquierda");
                          break;
        case 0x00FF02FD:  lcd.print("Tecla ok");
                          break;
        case 0x00FFC23D:  lcd.print("Tecla Derecha");
                          break;
        case 0x00FFA857:  lcd.print("Tecla abajo");
                          break;
        case 0x00FF6897:  lcd.print("Tecla uno");
                          break;
        case 0x00FF9867: lcd.print("Tecla 2");    
                       break;
      case 0x0FFB04F: lcd.print("Tecla 3");
                       break;
      case 0x00FF30CF: lcd.print("Tecla 4 ");
                       break;
      case 0x00FF18E7: lcd.print("Tecla 5");    
                       break;
      case 0x00FF7A85: lcd.print("Tecla 6");   
                       break;
      case 0x00FF10EF: lcd.print("Tecla 7");    
                       break; 
      case 0x00FF38C7: lcd.print("Tecla 8 ");  
                       break;
      case 0x00FF5AA5: lcd.print("Tecla 9");
                       break;
      case 0x00FF42BD: lcd.print("Tecla *");
                       servoMotor.write(10);  
                       break;
      case 0x00FF4AB5: lcd.print("Tecla 0");
                       servoMotor.write(90);  
                       break;
      case 0x00FF52AD: lcd.print("Tecla #");
                       servoMotor.write(180);   
                       break;
      }
      irrecv.resume();
    }
    delay(900);
}
