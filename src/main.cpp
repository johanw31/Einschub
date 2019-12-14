#include "InputOutput.hpp"
#include <Arduino.h>
#include "funktionen.hpp"
#include <string.h>

void setup() {
  pinMode(k11, OUTPUT);
  pinMode(k21, OUTPUT);
  pinMode(k22, OUTPUT);
  pinMode(k12, OUTPUT);
  pinMode(k13, OUTPUT);
  pinMode(k23, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  Serial.begin(2000000);
}
float kontakte_k13[]={0,0,0};
void loop() {

char val = '0';
if (Serial.available()){
  val = Serial.read();
}
if (val == 'k'){
SBRS3_test();
bitsNull();
}
if (val == 'h'){
SBES3_test();
bitsNull();
}
  //k12_k22_test ();
  /*struct array test = schuetzKontakte_widerstand(k11 , 0 , startPin_ic_1 );
  Serial.print(test.wert[0]);
  Serial.print(" | ");
  Serial.print(test.wert[1]);
  Serial.print(" | ");
  Serial.print(test.wert[2]);
  Serial.println();
  Serial.println();*/
}
