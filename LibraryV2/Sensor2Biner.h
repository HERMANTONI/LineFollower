/*
 * Developer  : Hermantoni
 * Email      : hermantoni0510@gmail.com
 * Board      : Arduino nano
 * Kategori   : LineFollower
 * Bagian     : Sensor2Biner
 * 
 */
/*
!!!Copy code to root program!!!
int Sensor_eeprom[]={200,210,210,210,120};
int JumlahSensor = 5;
*/

int Sensor2Biner(){
  int Pangkat[] = {1, 2, 4, 8, 16, 32, 64, 128};
  int Sensor[] = {0,0,0,0,0};
  int TempSensor = 0;
  for (int a=0; a<JumlahSensor; a++){
    Sensor[a] = analogRead(a);
    Serial.println(Sensor[a]);
    // delay(100);
  }
  for (int a=0; a<JumlahSensor; a++){
    if (Sensor[a] > Sensor_eeprom[a]){
      TempSensor = TempSensor | Pangkat[a];
    }
  }
  Serial.println(TempSensor,BIN);
  return TempSensor;
}
