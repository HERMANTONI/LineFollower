/*
 * Developer  : Hermantoni
 * Email      : hermantoni0510@gmail.com
 * Board      : Arduino nano
 * Kategori   : LineFollower
 * Bagian     : Predecision2PID
 * 
 */
 
float SetPoint = 0, LastError = 0;
float KonstantaP = 3, KonstantaI = 4, KonstantaD = 3, Integral;
unsigned long ElapsedTime, LastTime;

float Predecision2PID(float Data){
	float Porposional, Derivatif;
  // Serial.print("Data = "); Serial.print(Data); Serial.print("\t");
  Data = Data;
	float Error = Data - SetPoint;
  // Serial.print("SP = "); Serial.print(SetPoint); Serial.print("\t");
  Porposional = Error * KonstantaP;
  if (Error == 0){
    Integral = 0;
  }
  if (Error < -5 or Error > 5){
    Integral = Integral + (KonstantaI * Error);
    if (Integral > 50){ Integral = 50;}
    else if (Integral < -50){ Integral = -50;}
    else {
      Integral = Integral;
    }
  }
  // else {
  //   Integral = 0;
  // }
  unsigned long Time = millis();
  ElapsedTime = (Time - LastTime) / 100;
  Derivatif = KonstantaD * ((Error - LastError)/ElapsedTime);
  float PID = Porposional + Integral + Derivatif;
  // Serial.print("Data = "); Serial.print(Data); Serial.print("\t");
  // Serial.print("E = "); Serial.print(Error); Serial.print("\t");
  // Serial.print("P = "); Serial.print(Porposional); Serial.print("\t");
	// Serial.print("I = "); Serial.print(Integral); Serial.print("\t");
  // Serial.print("D = "); Serial.print(Derivatif); Serial.println("\t");
	LastTime = Time; LastError = Error;
	return PID;
}