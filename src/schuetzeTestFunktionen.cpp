#include "InputOutput.hpp"
#include <Arduino.h>
#include "funktionen.hpp"

String schuetzVerriegelung (String schuetz1, String schuetz2, int analogEingang, int startPin_ic){
  String fehlermeldung ="";
  boolean merker = false;
  int value1 = 0;
  int value2 = 0;
  digitalWrite(k11,HIGH);
  digitalWrite(k21,HIGH);
  for (int i = 0; i<3; i++){
    int status = digitalRead(i);     // überprüfen ob ein Schützkontakt durchgang hat
    if (status == 1) {               // beide Kontakte von K11 und K21 kommen auf den selben Kontakt. Da beide Schütze betätigt sind, sollte der status immer 0 bleiben
      icAnalogInput(i, startPin_ic); // für k11 sind die IC Eingänge 0, 1, 2 => i
      value1 = analogRead(analogEingang);
      icAnalogInput(i+3, startPin_ic); // für k21 sind die IC Eingänge 3, 4, 5 => i+3
      value2 = analogRead(analogEingang);
      if (value1 < 1022){
        if (value2 < 1022){
           fehlermeldung = "Verrieglung "+schuetz1+" o. "+schuetz2+" defekt";
           merker = true;
         }
        else fehlermeldung = "Verriegelung "+schuetz1+" defekt";
      }
      if (value2 < 1022 && merker == false){
        fehlermeldung = "Verriegelung "+schuetz2+" defekt";
      }

    }
  }
  return fehlermeldung;            // wenn die Verriegelung in Ordnung ist, wird ein leerer String zurückgegeben
}



String schuetzKontakte_widerstand(int schuetz, int analogEingang, int startPin_ic ){
  for (int i = 0; i<3; i++){
    icAnalogInput(i, startPin_ic);
    int analogwert = analogRead(analogEingang);
    double widerstand = multimeter(analogwert);
    Serial.println (widerstand);
  }
  return "lol";
}
