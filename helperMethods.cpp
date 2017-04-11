#include <stdio.h>
#include <time.h>

double avgOfIRReading(int irPin) {
  int reading = 0;
  double averaged = 0.0;
  for (int i = 0; i < 5; i = i +1) {
    reading = reading + read_analog(irPin);
    sleep1(0, 1000);
  }
  averaged = reading / 5;
  return averaged;
}

void driveAhead(int speed) {
  setMotor(0, speed);
  sleep1(0, 1000);
  setMotor(1, speed);
  sleep1(0, 1000);
  return;
}

void turnRight(int duration, int intensity) {
  setMotor(0, 255);
  sleep1(0, 1000);
  setMotor(1, 255 - intensity);
  sleep1(0, 1000);
  sleep1(0, duration);
  setMotor(0, 0);
  sleep1(0, 1000);
  setMotor(1, 0);
  sleep1(0, 1000);
  return;
}

void turnLeft(int duration, int intensity) {
  setMotor(0, 255 - intensity);
  sleep1(0, 1000);
  setMotor(1, 255);
  sleep1(0, 1000);
  sleep1(0, duration);
  setMotor(0, 0);
  sleep1(0, 1000);
  setMotor(1, 0);
  sleep1(0, 1000);
  return;
}

void slowReverse() {
  setMotor(0, -50);
  sleep1(0, 1000);
  setMotor(1, -50);
  sleep1(0, 1000);
  return;
}

void backIfClose(double threshhold) {
  if (avgOfIRReading(0) <= threshhold) {
    slowReverse(); 
  }
  return;
}

int main() {
  init();
}
