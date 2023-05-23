#include <math.h>
#include <Servo.h>
#include "leg_conf.h"
#define _T 1000
#define dlt_t 100
#define ax 110
#define ay 60
#define az 20
#define a0 60
#define setoffset -50 
#define _a1 60
#define _a2 110

  float l_z1A,l_z1B;
  float l_y1A,l_y1B;
  float l_z0A,l_z0B;
  float l_x0A,l_x0B;
  float l_y0A,l_y0B;
  float z0=0;
  int theta0,theta1,theta2;


  unsigned long current_mill=0;
  unsigned long prev_mill=0;
  unsigned long  _t=0;
  float x1=ax; //arbitrary constant
  Servo coxa[6], femur[6], tibia[6];
  
void setup(){
  Serial.begin(9600);
  prev_mill=millis();
  for(int i=0;i<6;i++){
    coxa[i].attach(pinCox[i]);
    femur[i].attach(pinFem[i]);
    tibia[i].attach(pinTibs[i]);
  }
}

void loop(){



  float _d= leg_l(_t,_T,ax,a0,az,z0,ay);
  current_mill=millis();

  //servo in y1
  if(current_mill- prev_mill>=dlt_t){
    _t=(_t+dlt_t)%_T;
    
    l_y1A=func_y1(_t,_T,ay);
    l_y1B=(-1)*func_y1(_t,_T,ay);

    l_z1A=func_z1(_T,_t,az,setoffset);
    l_z1B=(-1)*func_z1(_t,_T,az,setoffset);

    l_z0A=z0;//func_z0(t,T,a0);
    l_z0B=z0;//(-1)*func_z0(t,T,a0);

    l_x0A=func_x0(_t,_T,ax,a0,ay);
    l_x0B=(-1)*func_x0(_t,_T,ax,a0,ay);
    
    l_y0A=func_y0(_t,_T,a0);
    l_y0B=(-1)*func_y0(_t,_T,a0);


  }
  
    int vel_cox=velocity_cox(l_x0A,dlt_t);

  //angle
  theta0=deg(func_angle0(_t,_T,ax,ay));
  theta1=deg(func_angle1(_t,_T,_d,_a1,_a2,ax,a0,az,ay));
  theta2=deg(func_angle2(_t,_a1,_a2,_d));

// 
  coxa[3].write(theta0);
  femur[3].write(theta1);
  coxa[3].write(theta2);

  coxa[3].write(theta0);
  femur[3].write(theta1);
  coxa[3].write(theta2);
  
  coxa[3].write(theta0);
  femur[3].write(theta1);
  coxa[3].write(theta2);


//
  coxa[3].write(theta0);
  femur[3].write(theta1);
  coxa[3].write(theta2);

  coxa[3].write(theta0);
  femur[3].write(theta1);
  coxa[3].write(theta2);

  coxa[3].write(theta0);
  femur[3].write(theta1);
  coxa[3].write(theta2);
/*  
  Serial.print("l_y1A=");
  Serial.print(l_y1A);

  Serial.print(",l_y1B=");
  Serial.print(l_y1B);

  Serial.print(",l_z1A=");
  Serial.print(l_z1A);

  Serial.print(",l_z0A=");
  Serial.print(l_z0A);

  Serial.print(",l_z0B=");
  Serial.print(l_z0B);

  Serial.print(",l_x0A=");
  Serial.println(l_x0A);

  Serial.print("l_x0B=");
  Serial.println(l_x0B);

  Serial.print("theta0=");
  Serial.println(theta0);

  Serial.print("theta1=");
  Serial.println(theta1);

  Serial.print("theta2=");
  Serial.println(theta2);

  Serial.print("velocity non inverse coxa=");
  Serial.println(vel_cox);
  
  Serial.println("");
  prev_mill=millis();
  delay(240);
  */


  }
