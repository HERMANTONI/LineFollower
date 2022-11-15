/*
 * Developer  : Hermantoni
 * Email      : hermantoni0510@gmail.com
 * Board      : Arduino nano
 * Kategori   : LineFollower
 * Bagian     : SaveTrack
 * 
 */


int LogTrack[100];
int PosTrack;

int SaveTrack(int Track, int CountTrack){ //Track 1=Kiri, 2=Kanan, 3=Lurus; CountTrack 1=Plus, 2=Minus;
    int tempLog = LogTrack[PosTrack];
    if (CountTrack == 1){
        LogTrack[PosTrack] = Track;
        PosTrack +=1;
    }
    else if (CountTrack == 2){
        if (tempLog == 1){
            LogTrack[PosTrack] = 2;
        }
        else if (tempLog == 2){
            LogTrack[PosTrack] = 0;
        }
        else if (tempLog == 3){
            LogTrack[PosTrack] = 1;
        }
        else {
            
        }
        PosTrack -=1;
    }
    return tempLog;
}
 
void PutarArah(int Arah){ //1=Kiri, 2=Kanan, 3=PutarBalik
    // if (Arah == 1){
    //     while(1){
    //         analogWrite(MotorKanan1, 100);
    //         digitalWrite(MotorKanan0, 0);
    //         analogWrite(MotorKiri1, 100);
    //         digitalWrite(MotorKiri0, 1);
    //         delay(18000);
    //         break;
    //     }
    // }
    // else if (Arah == 2){
    //     while(1){
    //         analogWrite(MotorKanan1, 100);
    //         digitalWrite(MotorKanan0, 1);
    //         analogWrite(MotorKiri1, 100);
    //         digitalWrite(MotorKiri0, 0);
    //         delay(18000);
    //         break;
    //     }
    // }
    // else if (Arah == 3){
    //     while(1){
    //         analogWrite(MotorKanan1, 100);
    //         digitalWrite(MotorKanan0, 0);
    //         analogWrite(MotorKiri1, 100);
    //         digitalWrite(MotorKiri0, 1);
    //         delay(38000);
    //         break;
    //     }
    // }
    if (Arah == 1){
        while(1){
            analogWrite(MotorKanan1, 255);
            digitalWrite(MotorKanan0, 0);
            analogWrite(MotorKiri1, 0);
            digitalWrite(MotorKiri0, 1);
            delay(8000);
            break;
        }
    }
    else if (Arah == 2){
        while(1){
            analogWrite(MotorKanan1, 0);
            digitalWrite(MotorKanan0, 1);
            analogWrite(MotorKiri1, 255);
            digitalWrite(MotorKiri0, 0);
            delay(7500);
            break;
        }
    }
    else if (Arah == 3){
        while(1){
            analogWrite(MotorKanan1, 255);
            digitalWrite(MotorKanan0, 0);
            analogWrite(MotorKiri1, 0);
            digitalWrite(MotorKiri0, 1);
            delay(14000);
            break;
        }
    }
    else {
        analogWrite(MotorKanan1, 0);
        digitalWrite(MotorKanan0, 0);
        analogWrite(MotorKiri1, 0);
        digitalWrite(MotorKiri0, 0);
    }
    analogWrite(MotorKanan1, 0);
    digitalWrite(MotorKanan0, 0);
    analogWrite(MotorKiri1, 0);
    digitalWrite(MotorKiri0, 0);
}