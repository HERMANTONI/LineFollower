int Sensor_eeprom[]={200,210,210,210,120};
int JumlahSensor = 5;

void setup() {
  Serial.begin(9600);
  pinMode(2,1); pinMode(3,1); pinMode(4,1); pinMode(5,1);
}

void loop() {
  int Biner = Sensor2Biner();
  Biner2Motor(Biner);
  Serial.println();
  delay(1000);
}

int Sensor2Biner(){
  int Pangkat[] = {1, 2, 4, 8, 16, 32, 64, 128};
  int Sensor[]={0,0,0,0,0};
  int TempSensor = 0;
  for (int a=0; a<JumlahSensor; a++){
    Sensor[a] = analogRead(a);
    Serial.print(Sensor[a]); Serial.print(" ");
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

int Biner2Motor(int Biner){
  if (Biner == 0b11111) Motor(1,1);
  else if (Biner == 0b00001) Motor(2,0);
  else if (Biner == 0b00010) Motor(2,1);
  else if (Biner == 0b00100) Motor(3,3);
  else if (Biner == 0b01000) Motor(1,2);
  else if (Biner == 0b10000) Motor(0,2);

  else if (Biner == 0b00011) Motor(2,1);
  else if (Biner == 0b00110) Motor(3,2);
  else if (Biner == 0b01100) Motor(2,3);
  else if (Biner == 0b11000) Motor(1,2);
  
  else if (Biner == 0b00111) Motor(1,2);
  else if (Biner == 0b01110) Motor(3,3);
  else if (Biner == 0b11100) Motor(2,1);
  
  else if (Biner == 0b11110) Motor(2,0);
  else if (Biner == 0b11101) Motor(2,1);
  else if (Biner == 0b11011) Motor(3,3);
  else if (Biner == 0b10111) Motor(1,2);
  else if (Biner == 0b01111) Motor(0,2);

  else if (Biner == 0b11100) Motor(2,1);
  else if (Biner == 0b11001) Motor(3,2);
  else if (Biner == 0b10011) Motor(2,3);
  else if (Biner == 0b00111) Motor(1,2);

  else if (Biner == 0b00101) Motor(2,1);
  else if (Biner == 0b01010) Motor(3,3);
  else if (Biner == 0b10100) Motor(1,2);
  else if (Biner == 0b10101) Motor(3,3);

  else if (Biner == 0b01101) Motor(2,3);
  else if (Biner == 0b11010) Motor(2,3);
  else if (Biner == 0b10110) Motor(3,2);
  else if (Biner == 0b01011) Motor(3,2);

  else if (Biner == 0b00000) Motor(1,1);
  return 0;
}

int Motor(int Kiri, int Kanan){
  int SpeedReff = 255; //range 155-255
  int KN1 = 5, KN0 = 4, KR1 = 3, KR0 = 2;
  int SumKR = SpeedReff - (Kiri*50);
  int SumKN = SpeedReff - (Kanan*50);
  analogWrite(KR1, SumKR);
  analogWrite(KN1, SumKN);
  digitalWrite(KR0, 1);
  digitalWrite(KN0, 1);

  Serial.print(SumKR); Serial.print(" "); Serial.print(SumKN); Serial.print(" ");
  return 0;
}
