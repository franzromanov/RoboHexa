#include "servo.h"
#include "inverse_kinematics.h"

unsigned long cur_millis,prev_millis;
unsigned int t;

float cj0[3],cj1[3],cm0[3],cm1[3];
float tethaA[3],tethaB[3];
int betaA[3],betaB[3];

Servo coxa[6], femur[6], tibia[6]; // array servo coxa, femur, tibia

void init_servo(){  
  for(int i=0;i<6;i++){
    coxa[i].attach(pinCoxa[i]);
    femur[i].attach(pinFemur[i]);
    tibia[i].attach(pinTibia[i]);
  }
}

float mov1(){
  cur_millis= millis();
  if(cur_millis- prev_millis>= DT){
    t=(t+DT)%T;
    //koordinat maju
    get_coordinate(MAJU,t,T,cj1,cj0);
    get_tetha(cj0,cj1,tethaA);
    //koordinat mundur
    get_coordinate(MUNDUR,T-t,T,cm1,cm0);
    get_tetha(cm0,cm1,tethaB);
    //ubah dari radian ke degree
    for(int i=0;i<3;i++){
      betaA[i]=(int)(tethaA[i]*RAD);
      betaB[i]=(int)(tethaB[i]*RAD);
    }

    int tt0= (betaA[0]-COXA)+ServoCoxa[5];
    int tt1= (betaA[0]-COXA)+ServoFemur[5];
    int tt2=((betaA[0]-COXA)+ServoTibia[5]);

    coxa[2].write(tt0-10);
    femur[2].write(tt1+10);
    tibia[2].write(tt2+10);
    
    coxa[5].write(tt0);
    femur[5].write(tt1);
    tibia[5].write(tt2+30);

    coxa[3].write(tt0);
    femur[3].write(tt1);
    tibia[3].write(tt2+30);
    prev_millis= cur_millis;
    //delay(10);
    prev_millis=millis();
    }
  }

 float mov2(){
  cur_millis= millis();
  if(cur_millis- prev_millis>= DT){
    t=(t+DT)%T;
    //koordinat maju
    get_coordinate(MAJU,t,T,cj1,cj0);
    get_tetha(cj0,cj1,tethaA);
    //koordinat mundur
    get_coordinate(MUNDUR,T-t,T,cm1,cm0);
    get_tetha(cm0,cm1,tethaB);
    //ubah dari radian ke degree
    for(int i=0;i<3;i++){
      betaA[i]=(int)(tethaA[i]*RAD);
      betaB[i]=(int)(tethaB[i]*RAD);
    }

    int tt0= (betaA[0]-COXA)+ServoCoxa[5];
    int tt1= (betaA[0]-COXA)+ServoFemur[5];
    int tt2=((betaA[0]-COXA)+ServoTibia[5]);
    
    coxa[4].write(tt0);
    femur[4].write(tt1);
    tibia[4].write(tt2+30);
    
    coxa[1].write(tt0);
    femur[1].write(tt1);
    tibia[1].write(tt2+30);

    coxa[0].write(tt0);
    femur[0].write(tt1);
    tibia[0].write(tt2+30);
    prev_millis= cur_millis;
    //delay(10);
    prev_millis=millis();
    
  }}
  
void setup() {
  Serial.begin(9600);
  init_servo();
  delay(5000);
  t=0;
  prev_millis=0;
}

void loop() {

  
  mov1();
 // delay(30);
  mov2();
    
/*
    //cetak serial print
    Serial.print("Maju t= ");
        Serial.print(t);
    Serial.print(";X1= ");
        Serial.print(cj1[0]);
    Serial.print(";Y1= ");
        Serial.print(cj1[1]);
    Serial.print(";Z1= ");
        Serial.print(cj1[2]);
    Serial.print(";X0= ");
        Serial.print(cj0[0]);
    Serial.print(";Y0= ");
        Serial.print(cj0[1]);
    Serial.print(";Z0= ");
        Serial.print(cj0[2]);
        Serial.println(";");

    Serial.print("tetha0= ");
        Serial.print(betaA[0]);
    Serial.print(";tetha1= ");
        Serial.print(betaA[1]);
    Serial.print(";tetha2= ");
        Serial.print(betaA[2]);
        Serial.println(";");

    //cetak serial print
    Serial.print("Mundur t= ");
        Serial.print(T-t);
    Serial.print(";X1= ");
        Serial.print(cm1[0]);
    Serial.print(";Y1= ");
        Serial.print(cm1[1]);
    Serial.print(";Z1= ");
        Serial.print(cm1[2]);
    Serial.print(";X0= ");
        Serial.print(cm0[0]);
    Serial.print(";Y0= ");
        Serial.print(cm0[1]);
    Serial.print(";Z0= ");
        Serial.print(cm0[2]);
        Serial.println(";");

    Serial.print("tetha0= ");
        Serial.print(betaB[0]);
    Serial.print(";tetha1= ");
        Serial.print(betaB[1]);
    Serial.print(";tetha2= ");
        Serial.print(betaB[2]);
        Serial.println(";");
        */


        
   
    //delay(30);
    
  
}
