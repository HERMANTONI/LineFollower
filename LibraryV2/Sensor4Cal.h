/*
 * Developer  : Hermantoni
 * Email      : hermantoni0510@gmail.com
 * Board      : Arduino nano
 * Kategori   : LineFollower
 * Bagian     : Kalibrasi Sensor
 * 
 */

int setSensor(){
  int SensorH[]={0,0,0,0,0,0};
  int SensorH1[]={0,0,0,0,0,0};
  int SensorL[]={1023,1023,1023,1023,1023,1023};
  int SensorL1[]={1023,1023,1023,1023,1023,1023};
  int SensorM[]={0,0,0,0,0,0};
  if (digitalRead(8) == 0){
    while(digitalRead(8) == 0) digitalWrite(13,1);
    Serial.println("Baca Gelap");
    digitalWrite(13,0); delay(500);
    while(1){
      digitalWrite(13,1); delay(100); digitalWrite(13,0); delay(500);
      for (int a=0; a<5; a++){
        SensorH[a] = max(SensorH[a], analogRead(a));
        Serial.print(SensorH[a]); Serial.print(" ");
      }
      Serial.println();
      for (int a=0; a<5; a++){
        SensorL[a] = min(SensorL[a], analogRead(a));
        Serial.print(SensorL[a]); Serial.print(" ");
      }
      Serial.println();
      if (digitalRead(8) == 0) break;
    }
  }
  if (digitalRead(8) == 0){
    while(digitalRead(8) == 0) digitalWrite(13,1);
    Serial.println("Baca Terang");
    digitalWrite(13,0); delay(500);
    while(1){
      digitalWrite(13,1); delay(100); digitalWrite(13,0); delay(100);
      digitalWrite(13,1); delay(100); digitalWrite(13,0); delay(500);
      for (int a=0; a<5; a++){
        SensorH1[a] = max(SensorH1[a], analogRead(a));
        Serial.print(SensorH1[a]); Serial.print(" ");
      }
      Serial.println();
      for (int a=0; a<5; a++){
        SensorL1[a] = min(SensorL1[a], analogRead(a));
        Serial.print(SensorL1[a]); Serial.print(" ");
      }
      Serial.println();
      if (digitalRead(8) == 0) break;
    }
  }
  if (digitalRead(8) == 0){
    while(digitalRead(8) == 0) digitalWrite(13,1);
    Serial.println("Kita Hitung");
    digitalWrite(13,0); delay(500);
    for (int a=0; a<10; a++){
      digitalWrite(13,1); delay(100); digitalWrite(13,0); delay(100);
    }
    delay(500);
    for (int a=0; a<5; a++){
      SensorH[a] = max(SensorH[a], SensorH1[a]);
      SensorL[a] = min(SensorL[a], SensorL1[a]);
      Serial.print(SensorH[a]); Serial.print(" ");
    }
    Serial.println();
    for (int a=0; a<5; a++){
      Serial.print(SensorL[a]); Serial.print(" ");
    }
    Serial.println();
    for (int a=0; a<5; a++){
      SensorM[a] = SensorH[a] - SensorL[a];
      SensorH[a] = SensorM[a] / 2;
      Serial.print(SensorH[a]); Serial.print(" ");
      SensorM[a] = SensorH[a] + SensorL[a];
      EEPROM.write(a, SensorM[a] / 4);
      Serial.print(SensorM[a]); Serial.print(" ");
      Serial.print(EEPROM.read(a)); Serial.print(" ");
    }
    Serial.println();
    for (int a=0; a<5; a++){
      Sensor_eeprom[a] = EEPROM.read(a) * 4;
      Serial.print(Sensor_eeprom[a]); Serial.print(" ");
    }
    Serial.println(); Serial.println("Hitung Siap");
  }  
}
