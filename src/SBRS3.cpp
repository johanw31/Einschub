#include "InputOutput.hpp"
#include <Arduino.h>
#include "funktionen.hpp"

void k12_k22_test (){
  int kontakt_k11[] = {0,0,0};
  int kontakt_k21[] = {0,0,0};
  String test = schuetzVerriegelung ("k11", "k21", 0 , startPin_ic_1);

  Serial.println("hallo "+test+"  g");
}
