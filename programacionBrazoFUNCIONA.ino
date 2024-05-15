#include <Servo.h>
#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  
SoftwareSerial BT(10,11);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth

int c;                       // variable para guardar el valor que nos manda el dispositivo bluetooth

// crear variables de los servos, para identificarlos por nombre
Servo Base;
Servo Hombro;
Servo Codo;
Servo Pinza;

// variables con la posición inicial de los servos
int anguloBase = 90;
int anguloHombro = 45;
int anguloCodo = 30;
int anguloPinza = 45;

void setup()
{
  BT.begin(9600);       // Inicializamos el puerto serie BT (Para Modo AT 2)
  Serial.begin(9600);   // Inicializamos  el puerto serie  

  // Pines
  Base.attach(6);
  Hombro.attach(8);
  Codo.attach(7);
  Pinza.attach(4);

  // Inicializar los servos, estaría bien poner siempre los servos en un ángulo inicial, por si se han movido al transportarlo/guardarlo...
  Base.write(anguloBase);
  //Hombro.write(anguloHombro);
  //Codo.write(anguloCodo);
  Pinza.write(anguloPinza);
  
}

void loop()
{
  if(BT.available())                 // Si llega un dato por el puerto BT se envía al monitor serial
  {
    c = BT.read();                   // guardamos en la variable el valor leido
    Serial.println("Recibe dato");

    switch (c) {
      case 254:  // abrir pinza
        // Si la pinza está entre los dos ángulos, se abre 5 grados
        if(anguloPinza > 44 && anguloPinza < 181){
          anguloPinza = anguloPinza + 5;
          Pinza.write(anguloPinza);
          if(anguloPinza > 180){
            anguloPinza = 180;
          }
        }
        Serial.println("Se abre la pinza");
        Serial.println(anguloPinza);
        break;
      case 255:  // cerrar pinza
        if(anguloPinza > 44 && anguloPinza < 181){
          anguloPinza = anguloPinza - 5;
          Pinza.write(anguloPinza);
          Serial.println(anguloPinza);
          if(anguloPinza < 45){
            anguloPinza = 45;
          }
        }
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
        if(anguloBase >= 0 && anguloBase < 181){
          anguloBase = anguloBase + 5;
          Base.write(anguloBase);
          if(anguloBase > 180){
            anguloBase = 180;
          }
        }
        Serial.println("Se gira hacia la derecha");
        break;
      case 222:  // girar base hacia la izquierda
      if(anguloBase >= 0 && anguloBase < 181){
          anguloBase = anguloBase - 5;
          Base.write(anguloBase);
          if(anguloBase < 0){
            anguloBase = 0;
          }
        }
        Serial.println("Se gira hacia la izquierda");
        break;
      default:
        Serial.println("Nada");
        break;
    }
  }
}
