/*
 * Developer  : Hermantoni
 * Email      : hermantoni0510@gmail.com
 * Board      : Arduino nano
 * Kategori   : LineFollower
 * Bagian     : Biner2
 * 
 */

int Biner2Predecision(){
    int Desimal = Sensor2Biner();
    int Hasil = 0;
    if (Desimal == 0b00000000) {Hasil = 255;}
    else if (Desimal == 0b11111111) {Hasil = 255;}
    //==========================================
    else if (Desimal == 0b00000001) {Hasil = 40;}
    else if (Desimal == 0b00000010) {Hasil = 30;}
    else if (Desimal == 0b00000100) {Hasil = 20;}
    else if (Desimal == 0b00001000) {Hasil = 10;}
    else if (Desimal == 0b00010000) {Hasil = -10;}
    else if (Desimal == 0b00100000) {Hasil = -20;}
    else if (Desimal == 0b01000000) {Hasil = -30;}
    else if (Desimal == 0b10000000) {Hasil = -40;}
    //===========================================
    else if (Desimal == 0b11000000) {Hasil = -35;}
    else if (Desimal == 0b01100000) {Hasil = -25;}
    else if (Desimal == 0b00110000) {Hasil = -15;}
    else if (Desimal == 0b00011000) {Hasil = 0;}
    else if (Desimal == 0b00001100) {Hasil = 15;}
    else if (Desimal == 0b00000110) {Hasil = 25;}
    else if (Desimal == 0b00000011) {Hasil = 35;}
    //===========================================
    else if (Desimal == 0b00000111) {Hasil = 30;}
    else if (Desimal == 0b00001110) {Hasil = 20;}
    else if (Desimal == 0b00011100) {Hasil = 10;}
    else if (Desimal == 0b00111000) {Hasil = -10;}
    else if (Desimal == 0b01110000) {Hasil = -20;}
    else if (Desimal == 0b11100000) {Hasil = -30;}
    //===========================================
    else if (Desimal == 0b11110000) {Hasil = 0;}
    else if (Desimal == 0b01111000) {Hasil = -10;}
    else if (Desimal == 0b00111100) {Hasil = 0;}
    else if (Desimal == 0b00011110) {Hasil = 10;}
    else if (Desimal == 0b00001111) {Hasil = 0;}
    else if (Desimal == 0b10000111) {Hasil = 20;}
    else if (Desimal == 0b11000011) {Hasil = 0;}
    else if (Desimal == 0b11100001) {Hasil = 10;}
    else if (Desimal == 0b11110000) {Hasil = 0;}
    //===========================================
    else if (Desimal == 0b00011111) {Hasil = -30;}
    else if (Desimal == 0b10001111) {Hasil = -20;}
    else if (Desimal == 0b11000111) {Hasil = -10;}
    else if (Desimal == 0b11100011) {Hasil = 10;}
    else if (Desimal == 0b11110001) {Hasil = 20;}
    else if (Desimal == 0b11111000) {Hasil = 30;}
    //===========================================
    else if (Desimal == 0b11111100) {Hasil = 35;}
    else if (Desimal == 0b11111001) {Hasil = 25;}
    else if (Desimal == 0b11110011) {Hasil = 15;}
    else if (Desimal == 0b11100111) {Hasil = 0;}
    else if (Desimal == 0b11001111) {Hasil = -15;}
    else if (Desimal == 0b10011111) {Hasil = -25;}
    else if (Desimal == 0b00111111) {Hasil = -35;}
    //===========================================
    else if (Desimal == 0b01111111) {Hasil = -40;}
    else if (Desimal == 0b10111111) {Hasil = -30;}
    else if (Desimal == 0b11011111) {Hasil = -20;}
    else if (Desimal == 0b11101111) {Hasil = -10;}
    else if (Desimal == 0b11110111) {Hasil = 10;}
    else if (Desimal == 0b11111011) {Hasil = 20;}
    else if (Desimal == 0b11111101) {Hasil = 30;}
    else if (Desimal == 0b11111110) {Hasil = 40;}

    return Hasil;
}