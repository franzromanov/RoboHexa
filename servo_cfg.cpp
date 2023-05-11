#include "servo_cfg.h"

Servo coxa[6], femur[6], tibia[6]; // array servo coxa, femur, tibia
unsigned int maxServoCoxa[6],maxServoFemur[6],maxServoTibia[6];
unsigned int minServoCoxa[6],minServoFemur[6],minServoTibia[6];
//pin 3 dan 31 jadi satu pin
int deg_servo(unsigned int* offset,unsigned int legNum){
  return  (offset[legNum]);
}

void init_servo(){
  //define max dan min pos dari COXA, FEMUR, TIBIA
  for(int i=0;i<NUM_LEG;i++){
    maxServoCoxa[i]= offsetServoCoxa[i]+SWING_COXA;
    minServoCoxa[i]= offsetServoCoxa[i]-SWING_COXA;
    maxServoFemur[i]= offsetServoFemur[i]+SWING_FEMUR;
    minServoFemur[i]= offsetServoFemur[i]-SWING_FEMUR;
    maxServoTibia[i]= offsetServoTibia[i]+SWING_TIBIA;
    minServoTibia[i]= offsetServoTibia[i]-SWING_TIBIA;
  }

  // mengatur pin servo coxa
  coxa[0].attach(8);        //C
  coxa[1].attach(18);       //B
  coxa[2].attach(37);       //F
  coxa[3].attach(36);       //D
  coxa[4].attach(30);       //A
  coxa[5].attach(40);       //E
 
  // mengatur pin servo femur
  femur[0].attach(9);       //C
  femur[1].attach(2);       //B
  femur[2].attach(35);      //F
  femur[3].attach(34);      //D
  femur[4].attach(31);      //A
  femur[5].attach(39);      //E
 
  // mengatur pin servo tibia
  tibia[0].attach(6);       //C
  tibia[1].attach(22);      //B
  tibia[2].attach(33);      //F
  tibia[3].attach(32);      //D
  tibia[4].attach(28);      //A
  tibia[5].attach(38);      //E

  standby();
  delay(2000);
}

void standby(){
  //posisi servo standby
  for(int i=0;i<NUM_LEG;i++){
    coxa[i].write(deg_servo(offsetServoCoxa,i));
    femur[i].write(deg_servo(offsetServoFemur,i));
    tibia[i].write(deg_servo(offsetServoTibia,i));
  }
}

void maju(){
  //A,C,E maju swing
  coxa[0].write(deg_servo(minServoCoxa,0)); //C
  coxa[4].write(deg_servo(minServoCoxa,4)); //A
  coxa[5].write(deg_servo(maxServoCoxa,5)); //E
  femur[0].write(deg_servo(minServoFemur,0)); //C
  femur[4].write(deg_servo(minServoFemur,4)); //A
  femur[5].write(deg_servo(minServoFemur,5)); //E
  
  //B,D,F mundur stance
  coxa[1].write(deg_servo(maxServoCoxa,1)); //B
  coxa[3].write(deg_servo(minServoCoxa,3)); //D
  coxa[2].write(deg_servo(minServoCoxa,2)); //F
  femur[1].write(deg_servo(offsetServoFemur,1)); //B
  femur[3].write(deg_servo(offsetServoFemur,3)); //D
  femur[2].write(deg_servo(offsetServoFemur,2)); //F
  delay(300);

  //A,C,E mundur stance
  coxa[0].write(deg_servo(maxServoCoxa,0)); //C
  coxa[4].write(deg_servo(maxServoCoxa,4)); //A
  coxa[5].write(deg_servo(minServoCoxa,5)); //E
  femur[0].write(deg_servo(offsetServoFemur,0)); //C
  femur[4].write(deg_servo(offsetServoFemur,4)); //A
  femur[5].write(deg_servo(offsetServoFemur,5)); //E
  
  //B,D,F maju swing
  coxa[1].write(deg_servo(minServoCoxa,1)); //B
  coxa[3].write(deg_servo(maxServoCoxa,3)); //D
  coxa[2].write(deg_servo(maxServoCoxa,2)); //F
  femur[1].write(deg_servo(minServoFemur,1)); //B
  femur[3].write(deg_servo(minServoFemur,3)); //D
  femur[2].write(deg_servo(minServoFemur,2)); //F
  delay(300);
}

void mundur(){
  //A,C,E mundur swing
  coxa[0].write(deg_servo(maxServoCoxa,0)); //C
  coxa[4].write(deg_servo(maxServoCoxa,4)); //A
  coxa[5].write(deg_servo(minServoCoxa,5)); //E
  femur[0].write(deg_servo(minServoFemur,0)); //C
  femur[4].write(deg_servo(minServoFemur,4)); //A
  femur[5].write(deg_servo(minServoFemur,5)); //E
  
  //B,D,F maju stance
  coxa[1].write(deg_servo(minServoCoxa,1)); //B
  coxa[3].write(deg_servo(maxServoCoxa,3)); //D
  coxa[2].write(deg_servo(maxServoCoxa,2)); //F
  femur[1].write(deg_servo(offsetServoFemur,1)); //B
  femur[3].write(deg_servo(offsetServoFemur,3)); //D
  femur[2].write(deg_servo(offsetServoFemur,2)); //F
  delay(300);

  //A,C,E maju stance
  coxa[0].write(deg_servo(minServoCoxa,0)); //C
  coxa[4].write(deg_servo(minServoCoxa,4)); //A
  coxa[5].write(deg_servo(maxServoCoxa,5)); //E
  femur[0].write(deg_servo(offsetServoFemur,0)); //C
  femur[4].write(deg_servo(offsetServoFemur,4)); //A
  femur[5].write(deg_servo(offsetServoFemur,5)); //E
  
  //B,D,F mundur swing
  coxa[1].write(deg_servo(maxServoCoxa,1)); //B
  coxa[3].write(deg_servo(minServoCoxa,3)); //D
  coxa[2].write(deg_servo(minServoCoxa,2)); //F
  femur[1].write(deg_servo(minServoFemur,1)); //B
  femur[3].write(deg_servo(minServoFemur,3)); //D
  femur[2].write(deg_servo(minServoFemur,2)); //F
  delay(300);
}

void putar_kanan(){  
  //A,C,E maju swing  
  femur[0].write(deg_servo(maxServoFemur,0)); //C
  femur[4].write(deg_servo(maxServoFemur,4)); //A
  femur[5].write(deg_servo(maxServoFemur,5)); //E
  coxa[0].write(deg_servo(minServoCoxa,0)); //C
  coxa[4].write(deg_servo(minServoCoxa,4)); //A
  coxa[5].write(deg_servo(minServoCoxa,5)); //E

  
  //B,D,F mundur stance  
  femur[1].write(deg_servo(minServoFemur,1)); //B
  femur[3].write(deg_servo(minServoFemur,3)); //D
  femur[2].write(deg_servo(minServoFemur,2)); //F
  coxa[1].write(deg_servo(minServoCoxa,1)); //B
  coxa[3].write(deg_servo(minServoCoxa,3)); //D
  coxa[2].write(deg_servo(minServoCoxa,2)); //F
  delay(300);
  
  //B,D,F maju swing  
  femur[1].write(deg_servo(maxServoFemur,1)); //B
  femur[3].write(deg_servo(maxServoFemur,3)); //D
  femur[2].write(deg_servo(maxServoFemur,2)); //F
  coxa[1].write(deg_servo(offsetServoCoxa,1)); //B
  coxa[3].write(deg_servo(offsetServoCoxa,3)); //D
  coxa[2].write(deg_servo(offsetServoCoxa,2)); //F
  
  //A,C,E mundur stance  
  femur[0].write(deg_servo(minServoFemur,0)); //C
  femur[4].write(deg_servo(minServoFemur,4)); //A
  femur[5].write(deg_servo(minServoFemur,5)); //E
  coxa[0].write(deg_servo(maxServoCoxa,0)); //C
  coxa[4].write(deg_servo(maxServoCoxa,4)); //A
  coxa[5].write(deg_servo(maxServoCoxa,5)); //E  
  delay(300);
 
}

void putar_kiri(){
  //A,C,E maju swing  
  femur[0].write(deg_servo(maxServoFemur,0)); //C
  femur[4].write(deg_servo(maxServoFemur,4)); //A
  femur[5].write(deg_servo(maxServoFemur,5)); //E
  coxa[0].write(deg_servo(maxServoCoxa,0)); //C
  coxa[4].write(deg_servo(maxServoCoxa,4)); //A
  coxa[5].write(deg_servo(maxServoCoxa,5)); //E

  
  //B,D,F mundur stance  
  femur[1].write(deg_servo(minServoFemur,1)); //B
  femur[3].write(deg_servo(minServoFemur,3)); //D
  femur[2].write(deg_servo(minServoFemur,2)); //F
  coxa[1].write(deg_servo(maxServoCoxa,1)); //B
  coxa[3].write(deg_servo(maxServoCoxa,3)); //D
  coxa[2].write(deg_servo(maxServoCoxa,2)); //F
  delay(300);
  
  //B,D,F maju swing  
  femur[1].write(deg_servo(maxServoFemur,1)); //B
  femur[3].write(deg_servo(maxServoFemur,3)); //D
  femur[2].write(deg_servo(maxServoFemur,2)); //F
  coxa[1].write(deg_servo(offsetServoCoxa,1)); //B
  coxa[3].write(deg_servo(offsetServoCoxa,3)); //D
  coxa[2].write(deg_servo(offsetServoCoxa,2)); //F
  
  //A,C,E mundur stance  
  femur[0].write(deg_servo(minServoFemur,0)); //C
  femur[4].write(deg_servo(minServoFemur,4)); //A
  femur[5].write(deg_servo(minServoFemur,5)); //E
  coxa[0].write(deg_servo(minServoCoxa,0)); //C
  coxa[4].write(deg_servo(minServoCoxa,4)); //A
  coxa[5].write(deg_servo(minServoCoxa,5)); //E

  delay(300);  
  }

void geser_kanan(){
  //A,C,E maju swing  
  femur[0].write(deg_servo(maxServoFemur,0)); //C
  femur[4].write(deg_servo(maxServoFemur,4)); //A
  femur[5].write(deg_servo(maxServoFemur,5)); //E
  tibia[0].write(deg_servo(maxServoTibia,0)); //C
  tibia[4].write(deg_servo(maxServoTibia,4)); //A
  tibia[5].write(deg_servo(minServoTibia,5)); //E

  
  //B,D,F mundur stance  
  femur[1].write(deg_servo(minServoFemur,1)); //B
  femur[3].write(deg_servo(minServoFemur,3)); //D
  femur[2].write(deg_servo(minServoFemur,2)); //F
  tibia[1].write(deg_servo(maxServoTibia,1)); //B
  tibia[3].write(deg_servo(maxServoTibia,3)); //D
  tibia[2].write(deg_servo(maxServoTibia,2)); //F
  delay(300);
  
  //A,C,E mundur stance  
  femur[0].write(deg_servo(minServoFemur,0)); //C
  femur[4].write(deg_servo(minServoFemur,4)); //A
  femur[5].write(deg_servo(minServoFemur,5)); //E
  tibia[0].write(deg_servo(minServoTibia,0)); //C
  tibia[4].write(deg_servo(minServoTibia,4)); //A
  tibia[5].write(deg_servo(maxServoTibia,5)); //E  
  
  //B,D,F maju swing  
  femur[1].write(deg_servo(maxServoFemur,1)); //B
  femur[3].write(deg_servo(maxServoFemur,3)); //D
  femur[2].write(deg_servo(maxServoFemur,2)); //F
  tibia[1].write(deg_servo(minServoTibia,1)); //B
  tibia[3].write(deg_servo(minServoTibia,3)); //D
  tibia[2].write(deg_servo(minServoTibia,2)); //F

  delay(300);  
  }

void geser_kiri(){  
  
  //B,D,F mundur stance  
  femur[1].write(deg_servo(minServoFemur,1)); //B
  femur[3].write(deg_servo(minServoFemur,3)); //D
  femur[2].write(deg_servo(minServoFemur,2)); //F
  tibia[1].write(deg_servo(maxServoTibia,1)); //B
  tibia[3].write(deg_servo(maxServoTibia,3)); //D
  tibia[2].write(deg_servo(maxServoTibia,2)); //F
  
  //A,C,E maju swing  
  femur[0].write(deg_servo(maxServoFemur,0)); //C
  femur[4].write(deg_servo(maxServoFemur,4)); //A
  femur[5].write(deg_servo(maxServoFemur,5)); //E
  tibia[0].write(deg_servo(maxServoTibia,0)); //C
  tibia[4].write(deg_servo(maxServoTibia,4)); //A
  tibia[5].write(deg_servo(minServoTibia,5)); //E

  delay(300);
  
  //B,D,F maju swing  
  femur[1].write(deg_servo(maxServoFemur,1)); //B
  femur[3].write(deg_servo(maxServoFemur,3)); //D
  femur[2].write(deg_servo(maxServoFemur,2)); //F
  tibia[1].write(deg_servo(minServoTibia,1)); //B
  tibia[3].write(deg_servo(minServoTibia,3)); //D
  tibia[2].write(deg_servo(minServoTibia,2)); //F
  
  //A,C,E mundur stance  
  femur[0].write(deg_servo(minServoFemur,0)); //C
  femur[4].write(deg_servo(minServoFemur,4)); //A
  femur[5].write(deg_servo(minServoFemur,5)); //E
  tibia[0].write(deg_servo(minServoTibia,0)); //C
  tibia[4].write(deg_servo(minServoTibia,4)); //A
  tibia[5].write(deg_servo(maxServoTibia,5)); //E  
  
  delay(300);
  }



  
