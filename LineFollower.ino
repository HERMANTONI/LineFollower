/*
 * Developer  : Hermantoni
 * Email      : hermantoni0510@gmail.com
 * Board      : Arduino nano
 * Kategori   : LineFollower
 * Bagian     : ProgramUtama
 * harap berkabar jika menggunakan program ini :)
 * karena hasil pengujian teman teman membantu perbaiki bug program ini :)
 */

#include "Library/Motor.h"
#include "Library/Sensor2Biner.h"
#include "Library/Biner2Predecision.h"
#include "Library/Predecision2PID.h"
#include "Library/PID2Decision.h"
#include "Library/SaveTrack.h"

// #define MotorKanan0 8
// #define MotorKanan1 6
// #define MotorKiri1 5
// #define MotorKiri0 7
int LastPredecision;

void setup() {
  Serial.begin(115200);
  InitMotor();
  // analogWrite(MotorKanan1, 70);
  // analogWrite(MotorKiri1, 70);
  // while(1){
  //   delay(10);
  // }
  // InitSensor();
  delay(3000);
  TCCR0A=0b10100011;
  TCCR0B=0b00000001; //  default TCCR0B=0b00000011;
  // PutarArah(1);
  // delay(100000);
  // PutarArah(2);
  // delay(100000);
  // PutarArah(3);
  // while(1){
  //   Sensor2Biner();
  //   Serial.println();
  //   delay(100);
  // }
}

void loop() {
  // for (int a = 0; a<50; a++){
  //   PID2Decision(0);
  //   RunMotor();
  //   delay(5000);
  //   Serial.println("\t");
  // }
  while (1){
    int Biner = Sensor2Biner();
    // Serial.print(Biner); Serial.print("\t"); Serial.print(Biner, BIN); Serial.print("\t");
    int Predecision = Biner2Predecision(Biner);
    // Serial.print("Predecision = "); Serial.print(Predecision); Serial.print("\t");
    if (Predecision == 254){
      int PID = Predecision2PID(LastPredecision);
      PID2Decision2(PID);
      RunMotor(Kiri1,Kiri0,Kanan1,Kanan0);
      // Serial.print("PID = "); Serial.print(PID); Serial.print("\t");
      // Serial.print("Kiri = "); Serial.print(Kiri1); Serial.print("\t"); Serial.print(Kiri0); Serial.print("\t");
      // Serial.print("Kanan = "); Serial.print(Kanan1); Serial.print("\t"); Serial.print(Kanan0); Serial.print("\t");
    }
    else if (Predecision <= 40 and Predecision >= -40){
      LastPredecision = Predecision;
      int PID = Predecision2PID(Predecision);
      PID2Decision2(PID);
      RunMotor(Kiri1,Kiri0,Kanan1,Kanan0);
      // Serial.print("PID = "); Serial.print(PID); Serial.print("\t");
      // Serial.print("Kiri = "); Serial.print(Kiri1); Serial.print("\t"); Serial.print(Kiri0); Serial.print("\t");
      // Serial.print("Kanan = "); Serial.print(Kanan1); Serial.print("\t"); Serial.print(Kanan0); Serial.print("\t");
    }
    else if (Predecision == 255){
      RunMotor(0,0,0,0);
    }
    // Serial.println("\t");
    delay(100);
  }
}
