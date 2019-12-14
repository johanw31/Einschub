#include "InputOutput.hpp"
#include <Arduino.h>
#include "funktionen.hpp"

String schuetzVerriegelung (String nameSchuetz1, String nameSchuetz2, int pinSchuetz1, int pinSchuetz2, int analogEingang, int startPin_ic){
  String fehlermeldung = (nameSchuetz1+"/"+nameSchuetz2+"OK");
  int value1 = 0;
  digitalWrite(pinSchuetz1,HIGH);
  delay (1000);
  digitalWrite(pinSchuetz2,HIGH);
  delay (1000);
  for (int i = 0; i<3; i++){
    icAnalogInput(i+3, startPin_ic);
    value1 = analogRead(analogEingang);
    bitsNull();
    if (value1 > 100){
      digitalWrite (pinSchuetz1, LOW);
      digitalWrite (pinSchuetz2, LOW);
      return ("Verriegelung "+nameSchuetz1+" defekt");
    }
  }
  digitalWrite (pinSchuetz1,LOW);
  delay (1000);
  digitalWrite (pinSchuetz1,HIGH);
  delay (500);
  for (int i = 0; i<3; i++){
    icAnalogInput(i, startPin_ic);
    value1 = analogRead(analogEingang);
    bitsNull();
    if (value1 > 100){
      digitalWrite (pinSchuetz1, LOW);
      digitalWrite (pinSchuetz2, LOW);
      return ("Verriegelung "+nameSchuetz2+" defekt");
    }
  }
  digitalWrite(pinSchuetz1,LOW);
  digitalWrite(pinSchuetz2,LOW);
  return fehlermeldung;            // wenn die Verriegelung in Ordnung ist, wird ein leerer String zurückgegeben
}

String einzelVerriegelung (String nameSchuetz1, int pinSchuetz1, int pinSchuetz2, int startAnalogIcEingang, int analogEingang, int startPin_ic) {
  digitalWrite(pinSchuetz1,HIGH);
  delay (1000);
  digitalWrite(pinSchuetz2,HIGH);
  delay (1000);
  for (int i = 0; i<3; i++){
    icAnalogInput(startAnalogIcEingang+i, startPin_ic);
    int value1 = analogRead(analogEingang);
    bitsNull();
    if (value1 > 20){
      digitalWrite (pinSchuetz1, LOW);
      digitalWrite (pinSchuetz2, LOW);
      return ("Verriegelungskontakt "+nameSchuetz1+" defekt");
    }
  }
  return "Verriegelungskontakt "+nameSchuetz1+" ok";
}


void schuetzKontakte_widerstand(int schuetz, int analogEingang, int startPin_ic, int icStartinput, float widerstand[] ){   // icStartinput benötigt für auswahl von welchen Input gestartet werden soll. Es sind immer 2 schuetze an einem IC angeklemmt. das erste schuetz von 0,1,2 , das zweite 3,4,5
  delay(200);
  digitalWrite(schuetz,HIGH);
  delay (500);
  digitalWrite(schuetz,LOW);
  delay (500);
  digitalWrite(schuetz,HIGH);                                                                                  // icStartinput ist entweder 0 oder 3
  delay (2000);
  for (int i = 0; i<3; i++){
    icAnalogInput(i+icStartinput, startPin_ic);
  //  int analogwert = analogMittelwert(analogEingang);
  int analogwert = analogMittelwert(analogEingang);
  //  Serial.println(multimeter(analogwert));
    widerstand[i] = multimeter(analogwert);
    delay (200);
    bitsNull();
  }
  digitalWrite(schuetz,LOW);
}


String schuetzVerklebt (String nameSchuetz, int analogEingang, int startPin_ic, int icStartinput){     // icStartinput benötigt für auswahl von welchen Input gestartet werden soll. Es sind immer 2 schuetze an einem IC angeklemmt. das erste schuetz von 0,1,2 , das zweite 3,4,5
  for (int i = 0; i<3; i++){
    int value1 = 0;
    icAnalogInput(i+icStartinput, startPin_ic);
    value1 = analogRead(analogEingang);
    bitsNull();
    if (value1 > 10){
      return ("Schuetz "+nameSchuetz+" Kontakt oder Schuetz verklebt");
    }
  }
  return (nameSchuetz+" OK");
}
