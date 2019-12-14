#include "InputOutput.hpp"
#include <Arduino.h>

float multimeter (int analogWert) {
  float angelegteSpannung = 5.;//(5./1023.)*(double)MessSpannung;              // MessSpannung ist definiert als analogRead (15) und gibt einen Wert zwischen 0 - 1023 zurück. (0-5V)
  float Spannung = (angelegteSpannung / 1023.)*(float)analogWert;
  float shuntWiderstand = 18.;
  float kontaktWiderstand = (angelegteSpannung/Spannung)*shuntWiderstand-shuntWiderstand;
  return betrag(kontaktWiderstand);
}


/*
*@param analogEingang
*@param startPin  Digitalausgang vom Arduino zum ansteuern der IC Eingänge
*/
void icAnalogInput (int analogEingang, int startPin){               // für die Analog ICs CD4051BE
  int bit1 = bitRead(analogEingang, 0);                             // Die Analogeneingänge von 0 - 7 werden angesteuert über drei Eingänge
  int bit2 = bitRead(analogEingang, 1);                             // --> zb. alle Eingänge LOW => IC Analogeingang 0 wird abgefragt
  int bit3 = bitRead(analogEingang, 2);                             //         erster Eingang 1, zweiter 0, dritter 1 => 101 (Binär) = 5 (dezimal) => Analogeingang 5 wird abgefragt
  digitalWrite(startPin,   bit1);
  digitalWrite(startPin+1, bit2);
  digitalWrite(startPin+2, bit3);
  delay(100);
}

int analogMittelwert (int analogEingang){
  long tmp = 0;
  for (int i= 0; i<1000; i++){
    tmp += analogRead(analogEingang);
  }
  int mittelwert = tmp/1000;
  return mittelwert;
}

void bitsNull(){
  digitalWrite(2,  LOW);
  digitalWrite(3,  LOW);
  digitalWrite(4,  LOW);
  digitalWrite(5,  LOW);
  digitalWrite(6,  LOW);
  digitalWrite(7,  LOW);
  digitalWrite(8,  LOW);
  digitalWrite(9,  LOW);
  digitalWrite(10,  LOW);
}
