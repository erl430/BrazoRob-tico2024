// LIBRERIAS
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
int anguloPinza = 45;

void setup()
{
  BT.begin(9600);       // Inicializamos el puerto serie BT (Para Modo AT 2)
  Serial.begin(9600);   // Inicializamos  el puerto serie  

  // Asignación de pines a los servos
  Base.attach(6);
  //Hombro.attach(8);
  Codo.attach(7);
  Pinza.attach(4);

  // Inicializar los servos en un ángulo inicial (solo los que no son continuos)
  Base.write(anguloBase);
  Pinza.write(anguloPinza);
}

void loop()
{
  if(BT.available())                 // Si llega un dato por el puerto BT se envía al monitor serial
  {
    c = BT.read();                   // guardamos en la variable el valor leido

    switch (c) {
      case 254:  // abrir pinza
        // Si la pinza está entre los dos ángulos, se abre 5 grados
        if(anguloPinza > 44 && anguloPinza < 181){
          anguloPinza = anguloPinza + 5;
          Pinza.write(anguloPinza);
        // Si el ángulo guardado es >180, lo dejamos en 180
          if(anguloPinza > 180){
            anguloPinza = 180;
          }
        }
        Serial.println("Se abre la pinza");
        break;
      case 255:  // cerrar pinza
        if(anguloPinza > 44 && anguloPinza < 181){
          anguloPinza = anguloPinza - 5;
          Pinza.write(anguloPinza);
          // Si el angulo de la pinza es <45, lo dejamos en 45
          if(anguloPinza < 45){
            anguloPinza = 45;
          }
        }
        Serial.println("Se cierra la pinza");
        break;
      case 243:  // subir codo
        // Servo continuo
        Codo.write(85); // gira despacio en sentido horario
        delay(1000);
        Codo.write(90); // se para
        Serial.println("Se sube el codo");
        break;
      case 247:  // bajar codo
        // Servo continuo
        Codo.write(93); // gira despacio en sentido antihorario
        delay(1000);
        Codo.write(90); // se para
        Serial.println("Se baja el codo");
        break;
      case 231:  // bajar hombro
        // Servo continuo
        
        
        //Hombro.write(85); // gira despacio en sentido horario
       //delay(1000);
        //Hombro.write(90); // se para
        //delay(3000);
        
         Hombro.attach(8);
  //servo2.write(90);
  Hombro.write(75); // gira despacio en sentido antihorario
  delay(50);

  Hombro.detach(); // se para
        
        
        
        Serial.println("Se sube el hombro");
        break;
      case 250:  // subir hombro
        // Servo continuo
//        Hombro.write(93); // gira despacio en sentido antihorario
//        delay(1000);
//        Hombro.write(90); // se para

         Hombro.attach(8);
  //servo2.write(90);
  Hombro.write(95); // gira despacio en sentido antihorario
  delay(50);

  Hombro.detach(); // se para

        Serial.println("Se baja el hombro");
        break;
      case 218:  // girar base hacia la derecha
        if(anguloBase >= 0 && anguloBase < 181){
          anguloBase = anguloBase + 5;
          Base.write(anguloBase);
          // Si el ángulo de la base >180, lo dejamos en 180
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
          // Si el ángulo de la base <0, lo dejamos en 0
          if(anguloBase < 0){
            anguloBase = 0;
          }
        }
        Serial.println("Se gira hacia la izquierda");
        break;
      default:  // en caso de recibir un caracter extraño
        Serial.println("Nada");
        break;
    }
  }
}
