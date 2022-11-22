/*
 * Developer  : Hermantoni
 * Email      : hermantoni0510@gmail.com
 * Board      : Arduino nano
 * Kategori   : LineFollower
 * Bagian     : PID2Decision
 *  
 */

int Kiri1, Kiri0, Kanan1, Kanan0;
int SpeedKiri = 20, SpeedKanan = 20, SpeedKiriMax = 80, SpeedKananMax = 80;
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
	}

	// Serial.print("Kiri = "); Serial.print(SpeedKiri); Serial.print("\t");
	// Serial.print("Kanan = "); Serial.print(SpeedKanan); Serial.println("\t");

	if (SpeedKiri > 255){
		Kiri1 = 255; Kiri0 = 0;
	}
	else if (SpeedKiri < 0){
		SpeedKiri = 255-SpeedKiri;
		Kiri1 = SpeedKiri; Kiri0 = 1;
	}
	else {
		Kiri1 = SpeedKiri; Kiri0 = 0;
	}
	if (SpeedKanan > 255){
		Kanan1 = 255; Kanan0 = 0;
	}
	else if (SpeedKanan < 0){
		SpeedKanan = 255-SpeedKanan;
		Kanan1 = SpeedKanan; Kanan0 = 1;
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
