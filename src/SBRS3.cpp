#include "InputOutput.hpp"
#include <Arduino.h>
#include "funktionen.hpp"

void SBRS3_test (){
  float kontakte_k11[] = {0,0,0};
  float kontakte_k21[] = {0,0,0};
  float kontakte_k22[] = {0,0,0};
  float kontakte_k12[] = {0,0,0};
  float kontakte_k13[] = {0,0,0};
  float kontakte_k23[] = {0,0,0};


  schuetzKontakte_widerstand(k11 , 0 , startPin_ic_1, 0, kontakte_k11);
  delay (500);
  schuetzKontakte_widerstand(k21 , 0 , startPin_ic_1, 3, kontakte_k21);
  delay (500);
  schuetzKontakte_widerstand(k22 , 1 , startPin_ic_2, 3, kontakte_k22);
  delay (500);
  schuetzKontakte_widerstand(k12 , 1 , startPin_ic_2, 0, kontakte_k12);
  delay (500);
  schuetzKontakte_widerstand(k13 , 2 , startPin_ic_3, 0, kontakte_k13);
  delay (500);
  schuetzKontakte_widerstand(k23 , 2 , startPin_ic_3, 3, kontakte_k23);
  delay (500);
  String mss1 = motorSchutzSchalter ("Q01", kontakte_k11, kontakte_k21);
  String mss2 = motorSchutzSchalter ("Q02", kontakte_k22, kontakte_k12);
  String mss3 = motorSchutzSchalter ("Q03", kontakte_k13, kontakte_k23);

  String verriegelung_k11_k21 = schuetzVerriegelung ("k11", "k21",k11 ,k21 , 0 , startPin_ic_1);
  delay (500);
  String verriegelung_k22_k12 = schuetzVerriegelung ("k12", "k22",k12 ,k22 , 1 , startPin_ic_2);
  delay (500);
  String verriegelung_k13_k23 = schuetzVerriegelung ("k13", "k23",k13 ,k23 , 2 , startPin_ic_3);
  delay (500);
  String verklebt_k11 = schuetzVerklebt ("k11", 0 , startPin_ic_1, 0);
  delay (500);
  String verklebt_k21 = schuetzVerklebt ("k21", 0 , startPin_ic_1, 3);
  delay (500);
  String verklebt_k22 = schuetzVerklebt ("k22", 1 , startPin_ic_2, 3);
  delay (500);
  String verklebt_k12 = schuetzVerklebt ("k12", 1 , startPin_ic_2, 0);
  delay (500);
  String verklebt_k13 = schuetzVerklebt ("k13", 2 , startPin_ic_3, 0);
  delay (500);
  String verklebt_k23 = schuetzVerklebt ("k23", 2 , startPin_ic_3, 3);
  delay (500);

  Serial.println("Motorschutzschalter:");
  delay(100);
  Serial.println("Q01 : "+mss1);
  delay(100);
  Serial.println("Q02 : "+mss2);
  delay(100);
  Serial.println("Q03 : "+mss3);
  delay(100);
  Serial.println("\n\nSchuetze verklebt? :");
  delay(100);
  Serial.println(verklebt_k11);
  delay(100);
  Serial.println(verklebt_k21);
  delay(100);
  Serial.println(verklebt_k22);
  delay(100);
  Serial.println(verklebt_k12);
  delay(100);
  Serial.println(verklebt_k13);
  delay(100);
  Serial.println(verklebt_k23);
  delay(100);
  Serial.println("\n\nSchuetzverriegelung:");
  delay(100);
  Serial.println(verriegelung_k11_k21);
  delay(100);
  Serial.println(verriegelung_k22_k12);
  delay(100);
  Serial.println(verriegelung_k13_k23);
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
  Serial.println("\n\nk22 : ");
  for (int i = 0;i<3;i++){
    delay(100);
    Serial.print(kontakte_k22[i]);
    Serial.print(" Ohm     ");
  }
  delay(100);
  Serial.println("\n\nk12 : ");
  for (int i = 0;i<3;i++){
    delay(100);
    Serial.print(kontakte_k12[i]);
    Serial.print(" Ohm     ");
  }
  delay(100);
  Serial.println("\n\nk13 : ");
  for (int i = 0;i<3;i++){
    delay(100);
    Serial.print(kontakte_k13[i]);
    Serial.print(" Ohm     ");
  }
  delay(100);
  Serial.println("\n\nk23 : ");
  for (int i = 0;i<3;i++){
    delay(100);
    Serial.print(kontakte_k23[i]);
    Serial.print(" Ohm     ");
  }
}
