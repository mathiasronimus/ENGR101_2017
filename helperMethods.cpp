#include <stdio.h>
#include <time.h>
#include "E101.h"

double avgOfIRReading(int irPin) {
  int reading = 0;
  double averaged = 0.0;
  for (int i = 0; i < 5; i = i +1) {
    reading = reading + read_analog(irPin);
  }
  averaged = reading / 5;
}

int main() {
  
}
