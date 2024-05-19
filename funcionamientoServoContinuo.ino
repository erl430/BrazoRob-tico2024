#include <Servo.h>  // Incluir la librería Servo
Servo servo1;       // Crear un objeto tipo Servo llamado servo1

void setup() {
  servo1.attach(10);  // Conectar servo1 al pin 9
}

void loop() {
  servo1.write(85); // gira despacio en sentido antihorario
  delay(3000);
  servo1.write(90); // se para
  delay(3000);
  servo1.write(92); // gira despacio en sentido horario
  delay(3000);
}
