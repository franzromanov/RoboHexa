#include <Servo.h>
#include <Arduino.h>

#define LEGS 6
#define COXA 0
#define FEMUR 40
#define TIBIA -50


const unsigned int offsetServoCoxa[6]={90,90,90,90,90,90}; //zero offset servo C,B,F,D,A,E (coxa C rusak)
const unsigned int offsetServoFemur[6]={70,30,85,85,90,85};   //zero offset servo C,B,F,D,A,E (femur C rusak)
const unsigned int offsetServoTibia[6]={55,90,80,10,0,80};
const unsigned int pinCox[LEGS]={8,18,37,36,30,40};
const unsigned int pinFem[LEGS]={9,2,35,32,31,39};
const unsigned int pinTibs[LEGS]={6,22,33,34,28,38};


//func


float deg(float rad);
float func_y1(float t,float T,float inp_ay);
float func_x0 (float t,float T,float inp_ax,float inp_a0,float inp_ay);
float func_z1(float T,float t, float inp_az,float offset);
float func_y0(float t,float T, float inp_a0);

float leg_l(float t,float T, float inp_ax,float inp_a0,float inp_az,float inp_z0,float inp_ay);

float func_angle0(float t,float T, float inp_ax,float inp_Ay);
float func_angle1(float t,float T,float d ,float a1, float a2,float inp_ax,float inp_a0,float inp_az, float inp_ay);
float func_angle2(float t,float a1,float a2,float d);

float  velocity_cox(float co_y,float diff_time);
