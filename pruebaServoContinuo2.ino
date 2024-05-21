#include <Servo.h>  // Incluir la librería Servo
Servo servo1;       // Crear un objeto tipo Servo llamado servo1
Servo servo2;

void setup() {
  servo1.attach(13);  // Conectar servo1 al pin 9
  servo2.attach(12);
}

void loop() {
  // servo1.write(70); // gira despacio en sentido antihorario
  // //servo2.write(70);
  // delay(3000);
  // servo1.write(0); // se para
  // //servo2.write(90);
  // delay(3000);
  // servo1.write(110); // gira despacio en sentido horario
  // //servo2.write(110);
  // delay(3000);
  servo2.attach(12);
  //servo2.write(90);
  servo2.write(75); // gira despacio en sentido antihorario
  delay(50);

  servo2.detach(); // se para
  delay(2000);
  servo2.attach(12);
  //servo2.write(90);

  servo2.write(95); // gira despacio en sentido horario
  //servo2.write(110);
  delay(50);
  servo2.detach(); // se para
  delay(3000);
}
