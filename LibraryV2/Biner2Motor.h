/*
 * Developer  : Hermantoni
 * Email      : hermantoni0510@gmail.com
 * Board      : Arduino nano
 * Kategori   : LineFollower
 * Bagian     : Biner to Motor
 * 
 */

int Biner2Motor(int Biner){
  if (Biner == 0b11111) Motor(0,0);
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

  else if (Biner == 0b00000) Motor(0,0);
}
