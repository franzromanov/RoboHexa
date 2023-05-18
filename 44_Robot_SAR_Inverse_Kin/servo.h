#include <Servo.h>
#include <Arduino.h>

#define NUM_LEG 6
#define COXA  0
#define FEMUR 75
#define TIBIA 135

const unsigned int ServoCoxa[NUM_LEG]={90,90,50,120,90,90}; //zero offset servo C,B,F,D,A,E
const unsigned int ServoFemur[NUM_LEG]={90,90,90,90,90,90};   //zero offset servo C,B,F,D,A,E
const unsigned int ServoTibia[NUM_LEG]={55,90,80,90,90,80};   //zero offset servo C,B,F,D,A,E 
const unsigned int pinCoxa[NUM_LEG]={8,18,37,36,30,40};
const unsigned int pinFemur[NUM_LEG]={9,2,35,34,31,39};
const unsigned int pinTibia[NUM_LEG]={6,22,33,32,28,38};  
