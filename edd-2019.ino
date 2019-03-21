// CODE FOR TEAMONE EDD 2019 PROJECT
// STORED AT https://github.com/PhilMathew/edd-2019/blob/master/edd-2019.ino

#include <Servo.h>

//Arduino Pin Numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output.03
const int victorPin = 3; // digital pin connected to PWM signal

// Controller objects
Servo VictorSP_MC; // Victor SP motor controller


void setup() {
  VictorSP_MC.attach(victorPin); // sets DIO3 as control pin for the Victor
  pinMode(SW_pin, INPUT); // sets the switch value as an input
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

double joy2speed(int joyPin) { // maps {0,...,1023} to {-1,...,1}, where both sets are members of R
  double spd, joyIn;
  joyIn = analogRead(joyPin);
  
  if (joyIn < 516 && joyIn > 500) { // deadzone
    spd = 0;
  } else {
    spd = (0.00195503421 * joyIn) - 1; // conversion formula
  }
  return spd;
}

void setSpeed(Servo motor, double iSpeed) { // method to set motor speed more naturally then motor.write()
  if (iSpeed == 0) {
    iSpeed = 0.030;
  }
 
  double mSpeed = 90 * (iSpeed + 1); // maps {-1,...,1} to {0,...,180}, where both sets are members of R
  
  if (mSpeed < 6) {
    mSpeed = 6;
  }
  
  motor.write(mSpeed); // sets motor speed
}

void loop() {
  double spd = joy2speed(X_pin);
  setSpeed(VictorSP_MC, spd);
}
