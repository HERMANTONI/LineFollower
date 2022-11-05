/*
 * Developer  : Hermantoni
 * Email      : hermantoni0510@gmail.com
 * Board      : Arduino nano
 * Kategori   : LineFollower
 * Bagian     : ProgramUtama
 * 
 */

#include "Sensor2Biner.h"

void setup() {
  Serial.begin(115200);
}

void loop() {
  int Desimal = Sensor2Biner();
  Serial.print(Desimal); Serial.print(" ");
  Serial.print(Desimal, BIN); Serial.println(" ");
  delay(500);
}
