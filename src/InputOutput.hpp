#include <Arduino.h>

struct array{ double wert[3]; };
struct array2{ double wert2[3]; };
struct array3{ double wert3[3]; };


// definition der Ausgänge für die Schütze von SBRS3
#define k11 24
#define k21 25
#define k12 26
#define k22 27
#define k13 28
#define k23 29


#define startPin_ic_1 2       //definieren der ICs zum  lesen der Analogen werte. Ic 1 belegt pin 0,1,2 auf dem Arduino
#define startPin_ic_2 5       //Ic 2 belegt pin 3,4,5 auf dem Arduino
#define startPin_ic_3 8       //Ic 3 belegt pin 6,7,8 auf dem Arduino
#define startPin_ic_4 11       //Ic 4 belegt pin 9,10,11 auf dem Arduino
#define startPin_ic_5 14      //Ic 5 belegt pin 12,13,14 auf dem Arduino
#define startPin_ic_6 17      //Ic 6 belegt pin 15,16,17 auf dem Arduino





#define MessSpannung analogRead(15)
#define betrag(x) (x)<0? -(x) : (x)
