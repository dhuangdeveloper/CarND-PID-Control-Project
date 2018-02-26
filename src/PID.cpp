#include "PID.h"
#include <math.h>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  // Initialize multipliers and initial errors
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  this->p_error = 0;
  this->d_error = 0;
  this->i_error = 0;
  this->t_abs_error = 0;
}

void PID::UpdateError(double cte) {
  // Update errors
  this->d_error = cte - this->p_error;
  this->i_error += cte;
  this->p_error = cte;
  this->t_abs_error += fabs(cte);
}

double PID::TotalError() {
  return this->t_abs_error;
}
