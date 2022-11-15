/*
 * Developer  : Hermantoni
 * Email      : hermantoni0510@gmail.com
 * Board      : Arduino nano
 * Kategori   : LineFollower
 * Bagian     : Motor
 * 
 */

#define MotorKanan0 8
#define MotorKanan1 6
#define MotorKiri1 5
#define MotorKiri0 7

void InitMotor(){
	pinMode(MotorKanan0, OUTPUT);
	pinMode(MotorKanan1, OUTPUT);
	pinMode(MotorKiri1, OUTPUT);
	pinMode(MotorKiri0, OUTPUT);
}

void RunMotor(){
  analogWrite(MotorKanan1, Kanan1);
  digitalWrite(MotorKanan0, Kanan0);
  analogWrite(MotorKiri1, Kiri1);
  digitalWrite(MotorKiri0, Kiri0);
  // Serial.print("Kiri1 = "); Serial.print(Kiri1); Serial.print("\t");
	// Serial.print("Kiri0 = "); Serial.print(Kiri0); Serial.print("\t");
	// Serial.print("Kanan1 = "); Serial.print(Kanan1); Serial.print("\t");
	// Serial.print("Kanan0 = "); Serial.print(Kanan0); Serial.print("\t");
}
