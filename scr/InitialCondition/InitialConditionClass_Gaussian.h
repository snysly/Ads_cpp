#ifndef __INITIAL_CONDITION_CLASS_GAUSSIAN__
#define __INITIAL_CONDITION_CLASS_GAUSSIAN__

#include <cmath>
#include <iostream>
using namespace std;
#include "../constants.h"

class InitialConditionClass_Gaussian{
   private:
      double epsilon;
      double sigma;

   public:
      InitialConditionClass_Gaussian();
      bool InitializeField(double r[], double phi[], double Phi[], double Pi[], int gridSize);

};


#endif
