#include <Servo.h>

Servo VictorSP_MC;
const int victorPin = 3;

void setup() {
  VictorSP_MC.attach(victorPin); // sets DIO3 as control pin
}

void setSpeed(Servo motor, double iSpeed) { // method to set motor speed more naturally then motor.write()
  double mSpeed = 90 * (iSpeed + 1); // maps {-1,...,1} to {0,...,180}, where both sets are members of R
  motor.write(mSpeed); // sets motor speed
}

void loop() {
  setSpeed(VictorSP_MC, 1); // full speed forward
  delay(10000); // 10 s delay
  setSpeed(VictorSP_MC, -1);// full speed backward
  delay(10000); // 10 s delay
  setSpeed(VictorSP_MC, 0);// stops motor
  delay(5000); // 5 s delay
}
