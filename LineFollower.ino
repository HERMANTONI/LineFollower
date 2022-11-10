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
#include "PID2Decision.h"
#include "Motor.h"

#define MotorKanan0 4
#define MotorKanan1 5
#define MotorKiri1 6
#define MotorKiri0 7

void setup() {
  Serial.begin(115200);
  InitMotor();
}

void loop() {
  int Biner = Sensor2Biner();
  Serial.print(Biner); Serial.print("\t"); Serial.print(Biner, BIN); Serial.print("\t");
  int Predecision = Biner2Predecision(Biner);
  Serial.print("Predecision = "); Serial.print(Predecision); Serial.print("\t");
  if (Predecision != 255){;
    int PID = Predecision2PID(Predecision);
    Serial.print("PID = "); Serial.print(PID);
    PID2Decision(PID);
  }
  Serial.println("\t");
  // delay(500);
}
