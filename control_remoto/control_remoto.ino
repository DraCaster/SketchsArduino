#include <IRremote.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27,16,2); 
int receiver = 3; 
Servo servoMotor; //variable para controlar el servo
IRrecv irrecv(receiver);     
decode_results results;   
 
void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  servoMotor.attach(11); 
  servoMotor.write(0);// Inicializamos al ángulo 0 el servomotor
  irrecv.enableIRIn(); 
}
boolean on = LOW;
 
void loop()  
{
  if (irrecv.decode(&results)) 
 
  {
    switch(results.value)
    {
      case 0x00FF629D: lcd.clear(); lcd.print("Hola :3 "); 
                       break;
      case 0x00FF22DD: lcd.clear(); lcd.print("Te quiero!");    
                       break;
      case 0x00FF02FD: lcd.clear();  if (irrecv.decode(&results)) {
    // Dato recibido, conmutamos el LED
    on = !on;
    digitalWrite(13,  on? HIGH : LOW); 
    if (on == LOW){
      lcd.clear();
      lcd.print("Me apague :(");
    }
    else{
      lcd.clear();
      lcd.print("Me prendi :D");
    }   
                       break;
      case 0x00FFC23D: lcd.clear(); lcd.print("Tecla: Derecha");   
                       break;
      case 0x00FFA857: lcd.clear(); lcd.print("Tecla: Abajo"); 
                       break;
      case 0x00FF6897: lcd.clear(); lcd.print("Tecla: 1");    
                       servoMotor.write(0);
                       break;
      case 0x00FF9867: lcd.clear(); lcd.print("Tecla: 2");
                        servoMotor.write(90);    
                       break;
      case 0x0FFB04F: lcd.clear(); lcd.print("Tecla: 3");  
                      servoMotor.write(180);  
                       break;
      case 0x00FF30CF: lcd.clear(); lcd.print("Tecla: 4");
                       break;
      case 0x00FF18E7: lcd.clear(); lcd.print("Tecla: 5");   
                       break;
      case 0x00FF7A85: lcd.clear(); lcd.print("Tecla: 6"); 
                       break;
      case 0x00FF10EF: lcd.clear(); lcd.print("Tecla: 7");
                       break; 
      case 0x00FF38C7: lcd.clear(); lcd.print("Tecla: 8");    
                       break;
      case 0x00FF5AA5: lcd.clear(); lcd.print("Tecla: 9");    
                       break;
      case 0x00FF42BD: lcd.clear(); lcd.print("Tecla: *");    
                       break;
      case 0x00FF4AB5: lcd.clear(); lcd.print("Tecla: 0");    
                       break;
      case 0x00FF52AD: lcd.clear(); lcd.print("Tecla: #");    
                       break;
    }
    irrecv.resume();
    }
}

 

