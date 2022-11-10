#define MotorKanan0 4
#define MotorKanan1 5
#define MotorKiri1 6
#define MotorKiri0 7

void InitMotor(){
	pinMode(MotorKanan0, OUTPUT);
	pinMode(MotorKanan1, OUTPUT);
	pinMode(MotorKiri1, OUTPUT);
	pinMode(MotorKiri0, OUTPUT);
}

void RunMotor(){
  analogWrite(MotorKanan1, Kanan1);
  analogWrite(MotorKanan0, Kanan0);
  analogWrite(MotorKiri1, Kiri1);
  analogWrite(MotorKiri0, Kiri0);
}
