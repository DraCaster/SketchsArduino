#include <NewPing.h>
 
/*Aqui se configuran los pines donde debemos conectar el sensor*/
#define TRIGGER_PIN  9
#define ECHO_PIN     10
#define MAX_DISTANCE 200
 
/*Crear el objeto de la clase NewPing*/
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  // Esperar 1 segundo entre mediciones
  delay(3000);
  // Obtener medicion de tiempo de viaje del sonido y guardar en variable uS
  int uS = sonar.ping_median();
  // Imprimir la distancia medida a la consola serial
  Serial.print("Distancia: ");
  // Calcular la distancia con base en una constante
  Serial.print(uS/MAX_DISTANCE);
  Serial.println("cm");
}
