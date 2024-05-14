#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  
SoftwareSerial BT(10,11);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth

int c;                       // variable para guardar el valor que nos manda el dispositivo bluetooth

// crear variables de los servos, para identificarlos por nombre

void setup()
{
  BT.begin(9600);       // Inicializamos el puerto serie BT (Para Modo AT 2)
  Serial.begin(9600);   // Inicializamos  el puerto serie  

  // Inicializar los servos, estaría bien poner siempre los servos en un ángulo inicial, por si se han movido al transportarlo/guardarlo...

  
}

void loop()
{
  if(BT.available())                 // Si llega un dato por el puerto BT se envía al monitor serial
  {
    c = BT.read();                   // guardamos en la variable el valor leido

    switch (c) {
      case 254:  // abrir pinza
        Serial.println("Se abre la pinza");
        break;
      case 255:  // cerrar pinza
        Serial.println("Se cierra la pinza");
        break;
      case 243:  // subir codo
        Serial.println("Se sube el codo");
        break;
      case 247:  // bajar codo
        Serial.println("Se baja el codo");
        break;
      case 231:  // subir hombro
        Serial.println("Se sube el hombro");
        break;
      case 250:  // bajar hombro
        Serial.println("Se baja el hombro");
        break;
      case 218:  // girar base hacia la derecha
        Serial.println("Se gira hacia la derecha");
        break;
      case 222:  // girar base hacia la izquierda
        Serial.println("Se gira hacia la izquierda");
        break;
      default:
        Serial.println("Nada");
        break;
    }
  }
}
