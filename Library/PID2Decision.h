/*
 * Developer  : Hermantoni
 * Email      : hermantoni0510@gmail.com
 * Board      : Arduino nano
 * Kategori   : LineFollower
 * Bagian     : PID2Decision
 *  
 */

int Kiri1, Kiri0, Kanan1, Kanan0;
int SpeedKiri = 20, SpeedKanan = 20, SpeedKiriMax = 150, SpeedKananMax = 150;
int PID2Decision(int PID){ //kiri minus kanan plus
	if (PID > 0){
		if (SpeedKiri < SpeedKiriMax or SpeedKanan < SpeedKananMax){
			SpeedKiri += 1 ; SpeedKanan += 1;
			delay(1000);
		}
		else {
			SpeedKiri = 80; SpeedKanan = SpeedKananMax;
		}
		SpeedKiri = SpeedKiri - PID;
		SpeedKanan = SpeedKanan + (PID/4);
		if (SpeedKiri < -250){ SpeedKiri = -250;}
		if (SpeedKanan > 255){ SpeedKanan = 255;}
	}
	else {
		if (SpeedKiri < SpeedKiriMax or SpeedKanan < SpeedKananMax){
			SpeedKiri += 1 ; SpeedKanan += 1;
			delay(1000);
		}
		else {
			SpeedKiri = SpeedKiriMax; SpeedKanan = SpeedKananMax;
		}
		PID = PID * -1;
		SpeedKiri = SpeedKiri + (PID/4);
		SpeedKanan = SpeedKanan - PID; 
		if (SpeedKanan < -250){ SpeedKanan = -250;}
		if (SpeedKiri > 255){ SpeedKiri = 255;}
	}

	Serial.print("Kiri = "); Serial.print(SpeedKiri); Serial.print("\t");
	Serial.print("Kanan = "); Serial.print(SpeedKanan); Serial.print("\t");

	if (SpeedKiri > 255){
		Kiri1 = 255; Kiri0 = 0;
	}
	else if (SpeedKiri < 0){
		Kiri1 = SpeedKiri + 255;
		Kiri0 = 1;
	}
	else {
		Kiri1 = SpeedKiri; Kiri0 = 0;
	}
	if (SpeedKanan > 255){
		Kanan1 = 255; Kanan0 = 0;
	}
	else if (SpeedKanan < 0){
		Kanan1 = SpeedKanan + 255;
		Kanan0 = 1;
	}
	else {
		Kanan1 = SpeedKanan; Kanan0 = 0;
	}
	// RunMotor(Kiri1,Kiri0,Kanan1,Kanan0);
	// Serial.print("Kiri1 = "); Serial.print(Kiri1); Serial.print("\t");
	// Serial.print("Kiri0 = "); Serial.print(Kiri0); Serial.print("\t");
	// Serial.print("Kanan1 = "); Serial.print(Kanan1); Serial.print("\t");
	// Serial.print("Kanan0 = "); Serial.print(Kanan0); Serial.print("\t");
}
int PID2Decision2(int PID){
	SpeedKiri = SpeedKiriMax-PID;
	SpeedKanan = SpeedKananMax+PID;

	if (SpeedKiri > 255){
		Kiri1 = 255; Kiri0 = 0;
	}
	else if (SpeedKiri < 0){
		Kiri1 = SpeedKiri + 255;
		Kiri0 = 1;
	}
	else {
		Kiri1 = SpeedKiri; Kiri0 = 0;
	}
	if (SpeedKanan > 255){
		Kanan1 = 255; Kanan0 = 0;
	}
	else if (SpeedKanan < 0){
		Kanan1 = SpeedKanan + 255;
		Kanan0 = 1;
	}
	else {
		Kanan1 = SpeedKanan; Kanan0 = 0;
	}
}
