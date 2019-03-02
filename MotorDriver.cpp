//Set some pins
//Default direction
//Initiate(init)
//Init Motors, Pinne
//Set Directions - DIRx
//Get Direction - Read encoders? - Wait for now
//Set Power = PWMx
//Get power - Wait for now
//Make it a motor driver class
#include "Arduino.h"
#include "MotorDriver.h"

//Beginning at least of functions


void MotorDriver::SetDirection(int Dir, int DirPin){ //Putting 1 or 0 into the direction pin of the specified motor
   digitalWrite(DirPin, Dir);
}

void MotorDriver::SetPower(int Pwm,int PwmPin){ //Set power to specified pin
 Pwm_Chkd = max(0,min(255,Pwm));        //Check to make sure power isn't above/below range
 analogWrite(PwmPin, Pwm_Chkd);              //Send checked power value to specified motor
}

void MotorDriver::SetR_MPower(int R_Pwm){ //Function to change power of right motors
  SetPower(R_Pwm,pwm_RF);                 //Use SetPower to control right side motor power
  SetPower(R_Pwm,pwm_RB);

}
void MotorDriver::SetR_Direction(int Dir){ //Function to set right motor direction
digitalWrite(dir_RF, Dir);
digitalWrite(dir_RB, Dir);
}
void MotorDriver::SetL_Direction(int Dir){ //Set left motor direction(set same direction as right, set to correct it)
digitalWrite(dir_LF, Dir);
digitalWrite(dir_LB, Dir);
}
void MotorDriver::SetL_MPower(int L_Pwm){ //Set left motor power
  SetPower(L_Pwm, pwm_LF);
  SetPower(L_Pwm, pwm_LB); 
}
