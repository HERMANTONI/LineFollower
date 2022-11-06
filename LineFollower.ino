/*
 * Developer  : Hermantoni
 * Email      : hermantoni0510@gmail.com
 * Board      : Arduino nano
 * Kategori   : LineFollower
 * Bagian     : ProgramUtama
 * 
 */

#include "Sensor2Biner.h"
#include "Biner2Predecision.h"
#include "Predecision2PID.h"

void setup() {
  Serial.begin(115200);
}

void loop() {
  int Biner = Sensor2Biner();
  Serial.print(Biner); Serial.print(" "); Serial.print(Biner, BIN); Serial.print(" ");
  int Predecision = Biner2Predecision(Biner);
  Serial.print("Predecision = "); Serial.print(Predecision); Serial.print(" ");
  if (Predecision != 255){;
    int PID = Predecision2PID(Predecision);
    Serial.print("PID = "); Serial.print(PID);
  }
  Serial.println(" ");
  // delay(500);
}
