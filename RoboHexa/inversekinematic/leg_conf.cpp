#include <Servo.h>
#include <math.h>
#include <Arduino.h>
#include "leg_conf.h"


//velocity
float velocity_cox(float co_y,float diff_time){
  int angular=M_PI/300;
  int tangential=co_y/diff_time;
return tangential+(angular*14,5);
  };

//angle_conversion
float deg(float rad){
return rad*(180/M_PI);
}


//defining function

float func_y1(float t,float T,float inp_ay){
  float y1=inp_ay*sin((2*M_PI*t)/T);
  return y1;
}
float func_x0 (float t,float T,float inp_ax,float inp_a0,float inp_ay){
  return 10 *inp_a0*(inp_ax/sqrt( pow(inp_ax,2)+pow(func_y1(t,T,inp_ay),2)));
  
}
float func_z1(float T,float t, float inp_az,float offset){

  float z1;

  //if(t>=0 && t<(T/4)){z1=offset;}
  if(T/4<t && t<(3*T/4))z1=offset+inp_az*(-cos(((2*M_PI*t)/T)));
  else z1=offset;

  return z1;
}
float func_y0(float t,float T, float inp_a0){
  float y0=inp_a0*sin((2*M_PI*t)/T);
}
 

//leg length
float leg_l(float t,float T, float inp_ax,float inp_a0,float inp_az,float inp_z0,float inp_ay){
  return sqrt(pow(inp_ax-func_x0(t,T,inp_ax,inp_a0,inp_ay),2)+pow(func_z1( T, t, inp_az,-50)-inp_z0,2));

}



//angle

float func_angle0(float t,float T, float inp_ax,float inp_Ay){
  return atan(func_y1(t,T,inp_Ay)/inp_ax);
}

float func_angle1(float t,float T,float d ,float a1, float a2,float inp_ax,float inp_a0,float inp_az, float inp_ay){
  float a=50;
  return atan(func_z1(T,t,inp_az,a)/(inp_ax-func_x0(t,T,inp_ax,inp_a0,inp_ay))) + acos((pow(a1,2)+pow(d,2)-pow(a2,2))/(2*a1*d));
}

float func_angle2(float t,float a1,float a2,float d){
  return asin((((pow(a1,2)+pow(a2,2)-(pow(d,2))))/(2*a1*a2)));
  }

void fwdA();


//debug here
