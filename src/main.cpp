#include "InputOutput.hpp"
#include <Arduino.h>
#include "funktionen.hpp"

void setup() {
  pinMode(k11, OUTPUT);
  pinMode(k21, OUTPUT);
  pinMode(k12, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  delay (2000);
  //k12_k22_test ();
  String test = schuetzKontakte_widerstand(k11,0 , startPin_ic_1 );
}
