// C++ code
//
#include <Servo.h>

Servo servo_13;

void setup()
{
  servo_13.attach(13);  // Asocia el servo al pin
  Serial.begin(9600);
}

void loop()
{
  Serial.println("está en el loop");
  servo_13.write(0);
  delay(3000);     
  servo_13.write(45);
  delay(3000);
  servo_13.write(90);
  delay(3000);
  servo_13.write(120);
  delay(3000);
  servo_13.write(179);
  delay(3000);

  //digitalWrite(LED_BUILTIN, HIGH);
  //delay(3000); // Wait for 1000 millisecond(s)
  //digitalWrite(LED_BUILTIN, LOW);
  //delay(1000); // Wait for 1000 millisecond(s)
}
