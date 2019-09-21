#include "InputOutput.hpp"
#include <Arduino.h>

double multimeter (int analogWert) {
  double angelegteSpannung = (5./1023.)*(double)MessSpannung;              // MessSpannung ist definiert als analogRead (15) und gibt einen Wert zwischen 0 - 1023 zurück. (0-5V)
  Serial.println(angelegteSpannung);
  double Spannung = (angelegteSpannung / (double)MessSpannung)*(double)analogWert;
  double shuntWiderstand = 18.;
  double Strom = Spannung / shuntWiderstand;
  double kontaktWiderstand = (angelegteSpannung - Spannung) /  Strom;
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
}
