/*
 * Developer  : Hermantoni
 * Email      : hermantoni0510@gmail.com
 * Board      : Arduino nano
 * Kategori   : LineFollower
 * Bagian     : Predecision2PID
 * 
 */

int SetPoint, LastError;
float KonstantaP = 1, KonstantaI = 0.01, KonstantaD = 0.01, Integral;
unsigned long ElapsedTime, LastTime;

float Predecision2PID(float Data){
	float Porposional, Derivatif;
	Data = Data;
	float Error = SetPoint - Data;
  Porposional = Error * KonstantaP;
  if (-0.5 < Error <0.5){
    Integral = Integral + (KonstantaI * Error);
  }
  unsigned long Time = millis();
  ElapsedTime = (Time - LastTime) / 1;
  Derivatif = KonstantaD * ((Error - LastError)/ElapsedTime);
  float PID = Porposional + Integral + Derivatif;
	Serial.print("Check = "); Serial.print(ElapsedTime); Serial.print(" ");
	LastTime = Time; LastError = Error;
	return PID;
}