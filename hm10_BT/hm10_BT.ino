/**

 * Conectar el módulo HM-10 al Arduino Uno:
 * RX  - 3
 * TX  - 2
 * GND - GND
 * VCC - 5V
 *

 */

#include <SoftwareSerial.h>

/*Definir el baudrate de la comunicación serial del bluetooth 
 y el arduino. */
 
#define PC_SERIAL_BAUDRATE 9600
#define BT_SERIAL_BAUDRATE 9600

SoftwareSerial SerialBt(2, 3);
char estado = ' ';

void setup()
{
    Serial.begin(PC_SERIAL_BAUDRATE);
    SerialBt.begin(BT_SERIAL_BAUDRATE);
}

void loop()
{
  /* Verificar la variable estado 
  mientras el BT esté disponible*/
  while (SerialBt.available()) {
     estado = SerialBt.read();  
  }
  
  /*Iniciar la transmisión de datos*/
  if(estado == 'i') {
    Serial.write(estado);
    SerialBt.println(analogRead(A0));
    delay(4);
  }

  /*Detener la transmisión de datos*/
  if(estado == 'p') {
    Serial.write(estado);
    delay(4);
  }

}
