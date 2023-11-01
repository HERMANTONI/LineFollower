int Motor(int Kiri, int Kanan){
  int SpeedReff = 255; //range 155-255
  int KN1 = 5, KN0 = 4, KR1 = 3, KR0 = 2;
  int SumKR = SpeedReff - (Kiri*50);
  int SumKN = SpeedReff - (Kanan*50);
  analogWrite(KR1, SumKR);
  analogWrite(KN1, SumKN);
  digitalWrite(KR0, 0);
  digitalWrite(KN0, 0);

  Serial.print(SumKR); Serial.print(" "); Serial.print(SumKN); Serial.print(" ");
  return 0;
}
