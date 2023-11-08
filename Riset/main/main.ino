#include <EEPROM.h>

int Sensor_eeprom[]={200,210,210,210,120};
int JumlahSensor = 5;
int StopLoop = 0;

void setup() {
 Serial.begin(9600);
  pinMode(2,1); pinMode(3,1); pinMode(4,1); pinMode(5,1);
  pinMode(8,INPUT_PULLUP); pinMode(13,1);
  if(digitalRead(8) == 0) setSensor(); 
  Serial.println("Read EEPROM");
  for (int a=0; a<5; a++){
    Sensor_eeprom[a] = EEPROM.read(a) * 4;
    Serial.print(Sensor_eeprom[a]); Serial.print(" ");
  }
  Serial.println("Ready to Go"); 
}

void loop() {
  int Biner = Sensor2Biner();
  Biner2Motor(Biner);
  // Serial.println();
  // delay(1000);
}

int Sensor2Biner(){
  int Pangkat[] = {1, 2, 4, 8, 16, 32, 64, 128};
  int Sensor[]={0,0,0,0,0};
  int TempSensor = 0;
  for (int a=0; a<JumlahSensor; a++){
    Sensor[a] = analogRead(a);
    // Serial.print(Sensor[a]); Serial.print(" ");
    // delay(100);
  }
  for (int a=0; a<JumlahSensor; a++){
    if (Sensor[a] > Sensor_eeprom[a]){
      TempSensor = TempSensor | Pangkat[a];
    }
  }
  // Serial.println(TempSensor,BIN);
  return TempSensor;
}

int Biner2Motor(int Biner){
  if (StopLoop < 400){
    if (Biner == 0b11111){
      if (StopLoop < 3000) StopLoop +=1;
    }
    else if (Biner == 0b00000) {
      if (StopLoop < 3000) StopLoop +=1;
    }

    else if (Biner == 0b00001) Motor(2,-1);
    else if (Biner == 0b00010) Motor(2,0);
    else if (Biner == 0b00100) Motor(3,3);
    else if (Biner == 0b01000) Motor(0,2);
    else if (Biner == 0b10000) Motor(-1,2);

    else if (Biner == 0b00011) Motor(2,0);
    else if (Biner == 0b00110) Motor(3,1);
    else if (Biner == 0b01100) Motor(1,3);
    else if (Biner == 0b11000) Motor(0,2);
    
    else if (Biner == 0b00111) Motor(0,2);
    else if (Biner == 0b01110) Motor(3,3);
    else if (Biner == 0b11100) Motor(2,0);
    
    else if (Biner == 0b11110) Motor(2,-1);
    else if (Biner == 0b11101) Motor(2,0);
    else if (Biner == 0b11011) Motor(3,3);
    else if (Biner == 0b10111) Motor(0,2);
    else if (Biner == 0b01111) Motor(-1,2);

    else if (Biner == 0b11100) Motor(2,0);
    else if (Biner == 0b11001) Motor(3,1);
    else if (Biner == 0b10011) Motor(0,3);
    else if (Biner == 0b00111) Motor(0,2);

    else if (Biner == 0b00101) Motor(2,0);
    else if (Biner == 0b01010) Motor(3,3);
    else if (Biner == 0b10100) Motor(0,2);
    else if (Biner == 0b10101) Motor(3,3);

    else if (Biner == 0b01101) Motor(1,3);
    else if (Biner == 0b11010) Motor(3,1);
    else if (Biner == 0b10110) Motor(3,1);
    else if (Biner == 0b01011) Motor(1,3);
  }
  else {
    Motor(0,0);
  }
  return 0;
}

int Motor(int Kiri, int Kanan){
  StopLoop = 0;
  MotorV2(Kiri, Kanan);
  // int KN1 = 5, KN0 = 4, KR1 = 3, KR0 = 2;
  // if (Kiri != 0 and Kanan !=0){
  //   int SpeedReff = 155; //range 155-255
  //   int SumKR = SpeedReff - (Kiri*50);
  //   int SumKN = SpeedReff - (Kanan*50);
  //   if (Kanan == 0){
  //     analogWrite(KR1, SumKR);
  //     analogWrite(KN1, 120);
  //     digitalWrite(KR0, 1);
  //     digitalWrite(KN0, 0);
  //   }
  //   else if (Kiri == 0){
  //     analogWrite(KR1, 120);
  //     analogWrite(KN1, SumKN);
  //     digitalWrite(KR0, 0);
  //     digitalWrite(KN0, 1);
  //   }
  //   else {
  //     analogWrite(KR1, SumKR);
  //     analogWrite(KN1, SumKN);
  //     digitalWrite(KR0, 1);
  //     digitalWrite(KN0, 1);
  //   }
  // }
  // else {
  //   digitalWrite(KR1, 0);
  //   digitalWrite(KN1, 0);
  //   digitalWrite(KR0, 0);
  //   digitalWrite(KN0, 0);
  // }
  // Serial.print(SumKR); Serial.print(" "); Serial.print(SumKN); Serial.print(" ");
  return 0;
}

int MotorV2(int Kiri, int Kanan){
  int SpeedReff = 155; //range 155-255
  int KN1 = 5, KN0 = 4, KR1 = 3, KR0 = 2;
  int SumKR, SumKN;
  if (Kanan == 0 and Kiri == 0){
    digitalWrite(KR1, 1);
    digitalWrite(KN1, 1);
    digitalWrite(KR0, 1);
    digitalWrite(KN0, 1);
  }
  else if (Kanan == Kiri){
    digitalWrite(KR1, 0);
    digitalWrite(KN1, 0);
    digitalWrite(KR0, 1);
    digitalWrite(KN0, 1);
  }
  else if (Kanan > Kiri){
    if (Kiri < 0){
      SumKR = Kiri*-100;
      digitalWrite(KR0, 0);
      analogWrite(KR1, SumKR);
    }
    else {
      SumKR = SpeedReff - (Kiri*50);
      digitalWrite(KR0, 1);
      analogWrite(KR1, SumKR);
    }
    SumKN = SpeedReff - (Kanan*50);
    analogWrite(KN1, SumKN);
    digitalWrite(KN0, 1);
  }
  else if (Kanan < Kiri){
    if (Kanan < 0){
      SumKN = Kanan*-100;
      digitalWrite(KN0, 0);
      analogWrite(KN1, SumKN);
    }
    else {
      SumKN = SpeedReff - (Kanan*50);
      digitalWrite(KN0, 1);
      analogWrite(KN1, SumKN);
    }
    SumKR = SpeedReff - (Kiri*50);
    analogWrite(KR1, SumKR);
    digitalWrite(KR0, 1);
  }
}

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
      SensorH[a] = SensorM[a] / 3;
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
