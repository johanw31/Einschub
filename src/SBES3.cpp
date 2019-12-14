#include "InputOutput.hpp"
#include <Arduino.h>
#include "funktionen.hpp"

void SBES3_test(){
  float kontakte_k11[] = {0,0,0};
  float kontakte_k21[] = {0,0,0};
  float kontakte_k31[] = {0,0,0};

  int k31 = k12;

  schuetzKontakte_widerstand(k11 , 0 , startPin_ic_1, 0, kontakte_k11);
  delay (500);
  schuetzKontakte_widerstand(k21 , 0 , startPin_ic_1, 3, kontakte_k21);
  delay (500);
  schuetzKontakte_widerstand(k31 , 1 , startPin_ic_2, 0, kontakte_k31);
  delay (500);


  String verklebt_k11 = schuetzVerklebt ("k11", 0 , startPin_ic_1, 0);
  delay (500);
  String verklebt_k21 = schuetzVerklebt ("k21", 0 , startPin_ic_1, 3);
  delay (500);
  String verklebt_k31 = schuetzVerklebt ("k31", 1 , startPin_ic_2, 0);


  Serial.println("\n\nSchuetze verklebt? :");
  delay(100);
  Serial.println(verklebt_k11);
  delay(100);
  Serial.println(verklebt_k21);
  delay(100);
  Serial.println(verklebt_k31);
  delay(100);


  Serial.println("\n\nKontaktwiderstaende:");
  delay(100);
  Serial.println("\n\nk11 : ");
  for (int i = 0;i<3;i++){
    delay(100);
    Serial.print(kontakte_k11[i]);
    Serial.print(" Ohm     ");
  }
  delay(100);
  Serial.println("\n\nk21 : ");
  for (int i = 0;i<3;i++){
    delay(100);
    Serial.print(kontakte_k21[i]);
    Serial.print(" Ohm     ");
  }
  delay(100);
  Serial.println("\n\nk31 : ");
  for (int i = 0;i<3;i++){
    delay(100);
    Serial.print(kontakte_k31[i]);
    Serial.print(" Ohm     ");
  }



}
