#include "inverse_kinematics.h"

void get_coordinate(bool dir,int time,int period,float* coordinate1,float *coordinate2){
    coordinate1[0]= AX;
    coordinate1[1]= AY*sin((2*PI*time)/period);
    if(!dir){
      if((time>= period/4) && (time< (3*period)/4)){
        coordinate1[2]= Z_Offset+(AZ*sin(((2*PI*time)/period)-(period/4)));
      }
      else{
        coordinate1[2]= Z_Offset;
      }
    }
    else{
      if((time>= period/4) && (time< (3*period)/4)){
        coordinate1[2]= Z_Offset;
      }
      else{
        coordinate1[2]= Z_Offset+(AZ*sin(((2*PI*time)/period)+(period/2)));
      }
    }
    //koordinat 0
    coordinate2[0]= (A0*AX)/sqrt(pow(AX,2)+pow(coordinate1[1],2));
    coordinate2[1]= A0*sin((2*PI*time)/period);
    coordinate2[2]= 0;
}

void get_tetha(float* coordinate0, float* coordinate1, float* sudut){
  sudut[0]= atan(coordinate1[1]/AX);
  float d= sqrt(pow(coordinate1[2]-coordinate0[2],2)+pow(coordinate1[0]-coordinate0[0],2));
  sudut[2]= asin((pow(d,2)-(pow(A1,2)+pow(A2,2)))/(2*A1*A2));
  sudut[1]= atan(coordinate1[2]/(AX-coordinate0[0]))+acos((pow(A2,2)-(pow(A1,2)+pow(d,2)))/(2*A1*d));
}
