#include <Arduino.h>

void k12_k22_test ();
double multimeter (int analogWert);
void icAnalogInput (int analogEingang, int startPin);
String schuetzVerriegelung (String schuetz1, String schuetz2, int analogEingang, int startPin_ic);
String schuetzKontakte_widerstand(int schuetz, int analogEingang, int startPin_ic );
