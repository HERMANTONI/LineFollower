/*
 * Developer  : Hermantoni
 * Email      : hermantoni0510@gmail.com
 * Board      : Arduino nano
 * Kategori   : LineFollower
 * Bagian     : Predecision2PID
 * 
 */
 
float SetPoint = 0, LastError = 0;
float KonstantaP = 1, KonstantaI = 0.2, KonstantaD = 0.7, Integral;
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
  if (Error < -10 or Error > 10){
    Integral = Integral + (KonstantaI * Error);
    if (Integral > 50){ Integral = 50;}
    else if (Integral < -50){ Integral = -50;}
    else {
      Integral = Integral;
    }
  }
  else {
    Integral = 0;
  }
  unsigned long Time = millis();
  ElapsedTime = (Time - LastTime) / 1;
  Derivatif = KonstantaD * ((Error - LastError)/ElapsedTime);
  float PID = Porposional + Integral + Derivatif;
  // Serial.print("Data = "); Serial.print(Data); Serial.print("\t");
  // Serial.print("E = "); Serial.print(Error); Serial.print("\t");
  // Serial.print("P = "); Serial.print(Porposional); Serial.print("\t");
	// Serial.print("I = "); Serial.print(Integral); Serial.print("\t");
  // Serial.print("D = "); Serial.print(Derivatif); Serial.print("\t");
	LastTime = Time; LastError = Error;
	return PID;
}