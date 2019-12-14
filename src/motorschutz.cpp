#include "InputOutput.hpp"
#include <Arduino.h>
#include "funktionen.hpp"


String motorSchutzSchalter (String motorschutzschalter, float kontakte_schuetz1[], float kontakte_schuetz2[]){
  for (int i = 0; i<3; i++){
    if ((kontakte_schuetz1[i] > 20.) && (kontakte_schuetz2[i] > 20.)){
      return ("Motorschutzschalter "+motorschutzschalter+" wahrscheinlich defekt oder ausgeschaltet");
    }
  }
  return "OK";
}
