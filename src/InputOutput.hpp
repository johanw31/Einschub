#include <Arduino.h>
#define k11 1
#define k21 2
#define k12 3
#define k22 4
#define k13 5
#define k23 6

#define startPin_ic_1 0       //definieren der ICs zum  lesen der Analogen werte. Ic 1 belegt pin 0,1,2 auf dem Arduino
#define startPin_ic_2 3       //Ic 2 belegt pin 3,4,5 auf dem Arduino
#define startPin_ic_3 6       //Ic 3 belegt pin 6,7,8 auf dem Arduino
#define startPin_ic_4 9       //Ic 4 belegt pin 9,10,11 auf dem Arduino
#define startPin_ic_5 12      //Ic 5 belegt pin 12,13,14 auf dem Arduino
#define startPin_ic_6 15      //Ic 6 belegt pin 15,16,17 auf dem Arduino

#define MessSpannung analogRead(15)
#define betrag(x) (x)<0? -(x) : (x)
