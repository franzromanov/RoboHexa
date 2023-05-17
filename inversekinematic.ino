#include <math.h>
//#include <Servo.h>

#define _T 1000
#define dlt_t 10
#define ax 90
#define ay 3
#define az 20
#define a0 60
#define setoffset -50 


float l_z1A,l_z1B;
float l_y1A,l_y1B;
float l_z0A,l_z0B;
float l_x0A,l_x0B;
float l_y0A,l_y0B;
float z0=0;
float theta0,theta1,theta2;


unsigned long current_mill=0;
unsigned long prev_mill=0;
unsigned long _t=0;
float x1=ax; //arbitrary constant

//angle_conversion
float deg(float rad){
return rad*(180/M_PI);
}

//defining function

float func_y1(float t,float T,float inp_Ay){
  float y1=ay*sin((2*M_PI*t)/T);
  return y1;
}
float func_x0 (float t,float T,float inp_ax,float inp_a0){
  float x0= inp_a0*(inp_ax*( pow(ax,2)+pow(func_y1(t,T,ay),2)));
  return x0;
}
float func_z1(float T,float t, float inp_az){

  float z1;

  if(t>=0 && t<(T/4)){z1=0;}
  else if((T/4)>=0 && t<(3*T/4)){z1=inp_az*sin(((2*M_PI*t)/T)-(T/4));}
  else if(t>=(3*T/4) && t<=T){z1=0;}

  return z1;
}
float func_y0(float t,float T, float inp_a0){
  float y0=inp_a0*sin((2*M_PI*t)/T);
}


//leg length
float leg_l(float t,float T, float inp_ax,float inp_a0,float inp_az,float inp_z0){
  return sqrt(pow(inp_ax-func_x0(t,T,inp_ax,inp_a0),2)+pow(func_z1( T, t, inp_az)-inp_z0,2));

}
float _d=leg_l(_t,_T,ax,a0,az,z0);
float _a1,_a2;


//angle

float func_angle0(float t,float T, float inp_ax,float inp_Ay){
  return atan(func_y1(t,T,inp_Ay)/inp_ax);
}

float func_angle1(float t,float T,float d ,float a1, float a2,float inp_ax,float inp_a0,float inp_az){

  return atan(func_z1(t,T,inp_az)/(inp_ax-func_x0(t,T,inp_ax,inp_a0))) + acos((pow(a2,2)-pow(a1,2)+pow(d,2))/(2*a1*a2));
}

float func_angle2(float t,float a1,float a2,float d){
  return asin((pow(d,2)-(pow(a1,2)+pow(a2,2)))*2*a1*a2);
  }

void setup(){
  Serial.begin(9600);
  prev_mill=0;
}

void loop(){

current_mill=millis();

//servo in y1
if(current_mill- prev_mill>=_t){
  _t=(_t+dlt_t)%_T;
  
  l_y1A=func_y1(_t,_T,ay);
  l_y1B=(-1)*func_y1(_t,_T,ay);

  l_z1A=func_z1(_t,_T,az);
  l_z1B=(-1)*func_z1(_t,_T,az);

  l_z0A=z0;//func_z0(t,T,a0);
  l_z0B=z0;//(-1)*func_z0(t,T,a0);

  l_x0A=func_x0(_t,_T,ax,a0);
  l_x0B=(-1)*func_x0(_t,_T,ax,a0);
  
  l_y0A=func_y0(_t,_T,a0);
  l_y0B=(-1)*func_y0(_t,_T,a0);

  prev_mill=millis();
}

//angle
theta0=deg(func_angle0(_t,_T,ax,ay));
theta1=deg(func_angle1(_t,_T,_d,_a1,_a2,ax,a0,az));
theta2=deg(func_angle2(_t,_a1,_a2,_d));


//printout
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

  Serial.println("");

  delay(120);
  }
