/*
 * Developer  : Hermantoni
 * Email      : hermantoni0510@gmail.com
 * Board      : Arduino nano
 * Kategori   : LineFollower
 * Bagian     : Sensor2Biner
 * 
 */

byte Pangkat[] = {1, 2, 4, 8, 16, 32, 64, 128};
int Hitam[8]={995,990,990,990,990,970,940,990};
/*
putih
991	954	929	936	954	841	759	953
Hitam
1017	1015	1013	1012	1015	1007	994	1012	
*/
int logPID;

int Sensor2Biner() {
  int Sensor[8];
  logPID=0;
  if (logPID < -80){
    for (int a = 0; a < 4; a++) {
      Sensor[a] = 0;
      // Serial.print(Sensor[a]); Serial.println("\t");
    }
    for (int a = 4; a < 8; a++) {
      Sensor[a] = analogRead(a);
      // Serial.print(Sensor[a]); Serial.println("\t");
    }
    int TempSensor = 0;
    for (int a = 0; a < 8; a++) {
      if (Sensor[a] > Hitam[a]) {
        int Temp = Pangkat[a];
        TempSensor = TempSensor | Temp;
        // Serial.print(Temp); Serial.print("\t");
        // Serial.print(Temp, BIN); Serial.println("\t");
      }
    }
    return TempSensor;
  }
  else if (logPID > 80){
    for (int a = 0; a < 4; a++) {
      Sensor[a] = analogRead(a);
      // Serial.print(Sensor[a]); Serial.println("\t");
    }
    for (int a = 4; a < 8; a++) {
      Sensor[a] = 0;
      // Serial.print(Sensor[a]); Serial.println("\t");
    }
    int TempSensor = 0;
    for (int a = 0; a < 8; a++) {
      if (Sensor[a] > Hitam[a]) {
        int Temp = Pangkat[a];
        TempSensor = TempSensor | Temp;
        // Serial.print(Temp); Serial.print("\t");
        // Serial.print(Temp, BIN); Serial.println("\t");
      }
    }
    return TempSensor;
  } 
  else {
    for (int a = 0; a < 8; a++) {
      Sensor[a] = analogRead(a);
      // Serial.print(Sensor[a]); Serial.print("\t");
    }
    int TempSensor = 0;
    for (int a = 0; a < 8; a++) {
      if (Sensor[a] > Hitam[a]) {
        int Temp = Pangkat[a];
        TempSensor = TempSensor | Temp;
        // Serial.print(Temp); Serial.print("\t");
        // Serial.print(Temp, BIN); Serial.println("\t");
      }
    }
    // Serial.println(TempSensor, BIN);
    return TempSensor;
  }
}

void InitSensor(){
  int Sensor[8];
  while(Serial.available() == 0){
    Serial.println("taro dilatar Hitam");
    for (int a = 0; a < 8; a++) {
      Sensor[a] = analogRead(a);
      Serial.print(Sensor[a]); Serial.println("\t");
    }
    delay(200);
  }
  Serial.readStringUntil("\n");
  while(Serial.available() == 0){
    Serial.println("taro dilatar Putih");
    for (int a = 0; a < 8; a++) {
      Hitam[a] = analogRead(a);
      Serial.print(Hitam[a]); Serial.println("\t");
    }
    delay(200);
    Serial.read();
  }
  Serial.readStringUntil("\n");
  for (int a = 0; a < 8; a++){
    Sensor[a] = ((Sensor[a] - Hitam[a])/2);
    Hitam[a] = (Sensor[a] + Hitam[a]);
  }
}
