#include "math.h"
#include "Arduino.h"

//direction
#define MAJU 0
#define MUNDUR 1

//panjang lengan
#define A0  60
#define A1  60
#define A2  115

//gerak robot
#define AX  90  
#define AY  30
#define AZ  20
#define Z_Offset  -50

//time
#define DT  10
#define T   1000

//rad
#define RAD 53

void get_coordinate(bool dir,int time,int period,float* coordinate1,float *coordinate2);
void get_tetha(float* coordinate0, float* coordinate1, float* sudut);
