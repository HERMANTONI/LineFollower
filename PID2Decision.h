/*
 * Developer  : Hermantoni
 * Email      : hermantoni0510@gmail.com
 * Board      : Arduino nano
 * Kategori   : LineFollower
 * Bagian     : PID2Decision
 * 
 */
int Kiri1, Kiri0, Kanan1, Kanan0;

int PID2Decision(int PID){ //kiri minus kanan plus
	int SpeedKiri = 100, SpeedKanan = 100;
	if (PID > 0){
		SpeedKiri = SpeedKiri + PID;
		SpeedKanan = SpeedKanan - PID;
	}
	else {
		PID = PID * -1;
		SpeedKiri = SpeedKiri - PID;
		SpeedKanan = SpeedKanan + PID;
	}

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
		Kanan1 = SpeedKanan; Kanan0 = 1;
	}
}
