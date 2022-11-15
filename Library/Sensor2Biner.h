/*
 * Developer  : Hermantoni
 * Email      : hermantoni0510@gmail.com
 * Board      : Arduino nano
 * Kategori   : LineFollower
 * Bagian     : Sensor2Biner
 * 
 */

byte Pangkat[] = {1, 2, 4, 8, 16, 32, 64, 128};
int Hitam[8]={1011,966,945,958,995,946,937,1002};
/*putih
0	661	569	788	913	759 741	916	//keramik
944	691	608	720	886	718	719	911
Hitam
0	947	940	982	1007 984	963 1008 //solasi
1005	948	947	963	1002	977	959	1004	
*/
int logPID;

int Sensor2Biner() {
  int Sensor[8];
  if (logPID < -80){
    for (int a = 0; a < 4; a++) {
      Sensor[a] = 0;
      // Serial.print(Sensor[a]); Serial.println("\t");
    }
    for (int a = 4; a < 8; a++) {
      Sensor[a] = analogRead(a);
      // Serial.print(Sensor[a]); Serial.println("\t");
    }
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
  }
  else {
    for (int a = 0; a < 8; a++) {
      Sensor[a] = analogRead(a);
      // Serial.print(Sensor[a]); Serial.print("\t");
    }
    // Serial.println();
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
