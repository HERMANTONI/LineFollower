/*
 * Developer  : Hermantoni
 * Email      : hermantoni0510@gmail.com
 * Board      : Arduino nano
 * Kategori   : LineFollower
 * Bagian     : Sensor2Biner
 * 
 */

byte Pangkat[] = {1, 2, 4, 8, 16, 32, 64, 128};

int Sensor2Biner() {
  int Sensor[8];
  int Hitam[8]={0,0,0,0,0,0,0,0};
  for (int a = 0; a < 6; a++) {
    Sensor[a] = analogRead(a);
  }
  int TempSensor = 0;
  for (int a = 0; a < 8; a++) {
    if (Sensor[a] > Hitam[a]) {
      int Temp = Pangkat[a];
      TempSensor = TempSensor | Temp;
      Serial.print(Temp); Serial.print(" ");
      Serial.print(Temp, BIN); Serial.println(" ");
    }
  }
  return TempSensor;
}
