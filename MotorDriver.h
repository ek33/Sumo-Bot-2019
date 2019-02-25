//Make sure nothing bad happens if inserted more than once
#ifndef MotorDriver_h
#define MotorDriver_h
//Define all motordriver and encoder pins
#define pwm_LF 4
#define pwm_LB 6
#define pwm_RF 5
#define pwm_RB 3
#define dir_RF 30
#define dir_RB 29
#define dir_LF 28
#define dir_LB 31
#define encoder_LF A6
#define encoder_RF A7
#define encoder_LB A2
#define encoder_RB A3
//Include arduino base library
#include "Arduino.h"
//WIP
class MotorDriver
{
  public:                                   //All Functions in MotorDriver Class
    void initMotors();
    void SetDirection(int Dir, int DirPin);
    void SetPower(int Pwm,int PwmPin);
    void SetR_MPower(int All_Pwm);
    void SetR_Direction(int Dir);
    void SetL_Direction(int Dir);
    void SetL_MPower(int L_Pwm);
    int Pwm_Chkd;
    
};

#endif
