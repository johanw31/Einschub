#include <Arduino.h>

void SBRS3_test ();
void SBES3_test();
float multimeter (int analogWert);
void icAnalogInput (int analogEingang, int startPin);
String schuetzVerriegelung (String schuetz1, String schuetz2, int pinSchuetz1, int pinSchuetz2,  int analogEingang, int startPin_ic);
void schuetzKontakte_widerstand(int schuetz, int analogEingang, int startPin_ic, int icStartinput, float widerstand[] );
String schuetzVerklebt (String nameSchuetz, int analogEingang, int startPin_ic, int icStartinput);
String motorSchutzSchalter (String motorschutzschalter, float kontakte_schuetz1[], float kontakte_schuetz2[]);
int analogMittelwert (int analogEingang);
String einzelVerriegelung (String nameSchuetz1, int pinSchuetz1, int pinSchuetz2, int startAnalogIcEingang, int analogEingang, int startPin_ic);
void bitsNull();
