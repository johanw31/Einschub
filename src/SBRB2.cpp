/*#include "inputSBRB2.hpp"
#include <Arduino.h>
#include "funktionen.hpp"

void SBRB2_test() {
  float kontakte_k11[] = {0,0,0};
  float kontakte_k10[] = {0,0,0};
  float kontakte_k12[] = {0,0,0};
  float kontakte_k13[] = {0,0,0};
  float kontakte_k17[] = {0,0,0};
  float kontakte_k31[] = {0,0,0};
  float kontakte_k30[] = {0,0,0};
  float kontakte_k32[] = {0,0,0};
  float kontakte_k33[] = {0,0,0};
  float kontakte_k37[] = {0,0,0};

  schuetzKontakte_widerstand(k11, 0, startPin_ic_1, 0, kontakte_k11);
  delay (200);
  schuetzKontakte_widerstand(k10, 0, startPin_ic_1, 3, kontakte_k10); // k10 spannung an x01.10 legen
  delay (200);
  schuetzKontakte_widerstand(k12, 3, startPin_ic_4, 0, kontakte_k12);
  delay (200);
  schuetzKontakte_widerstand(k17, 3, startPin_ic_4, 3, kontakte_k17);
  delay (200);
  schuetzKontakte_widerstand(k13, 4, startPin_ic_5, 0, kontakte_k13);
  delay (200);
  schuetzKontakte_widerstand(k31, 4, startPin_ic_5, 3, kontakte_k31);
  delay (200);
  schuetzKontakte_widerstand(k30, 5, startPin_ic_6, 0, kontakte_k30);
  delay (200);
  schuetzKontakte_widerstand(k32, 5, startPin_ic_6, 3, kontakte_k32);
  delay (200);
  schuetzKontakte_widerstand(k33, 6, startPin_ic_7, 0, kontakte_k33);
  delay (200);
  schuetzKontakte_widerstand(k37, 6, startPin_ic_7, 3, kontakte_k37);
  delay (200);


  String verklebt_k11 = schuetzVerklebt ("k11", 0 , startPin_ic_1, 0);
  delay (200);
  String verklebt_k10 = schuetzVerklebt ("k10", 0 , startPin_ic_1, 3);
  delay (200);
  String verklebt_k12 = schuetzVerklebt ("k12", 3 , startPin_ic_4, 0);
  delay (200);
  String verklebt_k17 = schuetzVerklebt ("k17", 3 , startPin_ic_4, 3);
  delay (200);
  String verklebt_k13 = schuetzVerklebt ("k13", 4 , startPin_ic_5, 0);
  delay (200);
  String verklebt_k31 = schuetzVerklebt ("k31", 4 , startPin_ic_5, 3);
  delay (200);
  String verklebt_k30 = schuetzVerklebt ("k30", 5 , startPin_ic_6, 0);
  delay (200);
  String verklebt_k32 = schuetzVerklebt ("k32", 5 , startPin_ic_6, 3);
  delay (200);
  String verklebt_k33 = schuetzVerklebt ("k33", 6 , startPin_ic_7, 0);
  delay (200);
  String verklebt_k37 = schuetzVerklebt ("k37", 6 , startPin_ic_7, 3);
  delay (200);

  String mss1 = motorSchutzSchalter ("Q01", kontakte_k11, kontakte_k12);
  String mss3 = motorSchutzSchalter ("Q03", kontakte_k31, kontakte_k32);


  String verriegelung_k37 = einzelVerriegelung ("k37", k37, k31, int startAnalogIcEingang, int analogEingang, int startPin_ic);
  String verriegelung_k32 = einzelVerriegelung ("k32", k32, k31, int startAnalogIcEingang, int analogEingang, int startPin_ic);
  String verriegelung_k11 = einzelVerriegelung ("k11", k11, k12, int startAnalogIcEingang, int analogEingang, int startPin_ic);
  String verriegelung_k10 = einzelVerriegelung ("k10", k10, k17, int startAnalogIcEingang, int analogEingang, int startPin_ic);
  String verriegelung_k17 = einzelVerriegelung ("k17", k17, k11, int startAnalogIcEingang, int analogEingang, int startPin_ic);
  String verriegelung_k12 = einzelVerriegelung ("k12", k12, k11, int startAnalogIcEingang, int analogEingang, int startPin_ic);
  String verriegelung_k31 = einzelVerriegelung ("k31", k31, k32, int startAnalogIcEingang, int analogEingang, int startPin_ic);
  String verriegelung_k30 = einzelVerriegelung ("k30", k30, k37, int startAnalogIcEingang, int analogEingang, int startPin_ic);


  Serial.println("Motorschutzschalter:");
  delay(100);
  Serial.println("Q01 : "+mss1);
  delay(100);
  Serial.println("Q03 : "+mss3);
  delay(100);

  Serial.println("\n\nSchuetze verklebt? :");
  delay(100);
  Serial.println(verklebt_k11);
  delay(100);
  Serial.println(verklebt_k10);
  delay(100);
  Serial.println(verklebt_k12);
  delay(100);
  Serial.println(verklebt_k17);
  delay(100);
  Serial.println(verklebt_k13);
  delay(100);
  Serial.println(verklebt_k31);
  delay(100);
  Serial.println(verklebt_k30);
  delay(100);
  Serial.println(verklebt_k32);
  delay(100);
  Serial.println(verklebt_k33);
  delay(100);
  Serial.println(verklebt_k37);
  delay(100);


  Serial.println("\n\nSchuetzverriegelung:");
  delay(100);
  Serial.println(verriegelung_k37);
  delay(100);
  Serial.println(verriegelung_k32);
  delay(100);
  Serial.println(verriegelung_k11);
  delay(100);
  Serial.println(verriegelung_k10);
  delay(100);
  Serial.println(verriegelung_k17);
  delay(100);
  Serial.println(verriegelung_k12);
  delay(100);
  Serial.println(verriegelung_k31);
  delay(100);
  Serial.println(verriegelung_k30);
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
  Serial.println("\n\nk10 : ");
  for (int i = 0;i<3;i++){
    delay(100);
    Serial.print(kontakte_k10[i]);
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
  Serial.println("\n\nk17 : ");
  for (int i = 0;i<3;i++){
    delay(100);
    Serial.print(kontakte_k17[i]);
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
  Serial.println("\n\nk31 : ");
  for (int i = 0;i<3;i++){
    delay(100);
    Serial.print(kontakte_k31[i]);
    Serial.print(" Ohm     ");
  }
  delay(100);
  Serial.println("\n\nk30 : ");
  for (int i = 0;i<3;i++){
    delay(100);
    Serial.print(kontakte_k30[i]);
    Serial.print(" Ohm     ");
  }
  delay(100);
  Serial.println("\n\nk32 : ");
  for (int i = 0;i<3;i++){
    delay(100);
    Serial.print(kontakte_k32[i]);
    Serial.print(" Ohm     ");
  }
  delay(100);
  Serial.println("\n\nk33 : ");
  for (int i = 0;i<3;i++){
    delay(100);
    Serial.print(kontakte_k33[i]);
    Serial.print(" Ohm     ");
  }
  delay(100);
  Serial.println("\n\nk37 : ");
  for (int i = 0;i<3;i++){
    delay(100);
    Serial.print(kontakte_k37[i]);
    Serial.print(" Ohm     ");
  }


}*/
