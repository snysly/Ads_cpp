#ifndef __INITIAL_CONDITION_CLASS__
#define __INITIAL_CONDITION_CLASS__

#include "InitialConditionClass_Gaussian.h"

template <class InitialCondition>
class InitialConditionClass{

   public:

     bool Initialize(double r[], double phi[], double Phi[], double Pi[],int gridSize){       
        return IC.InitializeField(r, phi, Phi, Pi, gridSize);//so this is the definition of the function within the class declaration?
     }

   private:

      InitialCondition IC;

};

#endif
