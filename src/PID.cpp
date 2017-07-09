#include "PID.h"
#include <cmath>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) 
{
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    p_error = i_error = d_error = prev_cte = 0.0;
}

void PID::UpdateError(double cte) 
{
   p_error = cte;

   i_error =+ cte;

   d_error = cte - prev_cte;
   prev_cte = cte;

}

double PID::getOutput(double speed)
{
    //return cap(-(Kp/(1+ speed) ) * p_error - (Kd /(1+speed))* d_error - Ki * i_error);
    return cap(-(Kp ) * p_error - (Kd )* d_error - Ki * i_error);
}

double PID::cap(double val)
{
    if(val>1.0)
    {
        return 1.0;
    }
    else if(val < -1.0) 
    {
        return -1.0;
    }
   // else if(fabs(val) < 0.01)
   // {
   //     return 0;
   // }

    return val;
}

double PID::TotalError() 
{
    return 0;
}

