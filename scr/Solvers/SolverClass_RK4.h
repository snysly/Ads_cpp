#ifndef __SOLVER_CLASS_RK4__
#define __SOLVER_CLASS_RK4__

#include <cmath>
#include "../constants.h"

// Spatial Solver Class template
#include "SpatialSolverClass.h"

#include "../NumericalRecipes/Derivative.h"

class SolverClass_RK4{
   public:
      
      SolverClass_RK4(void);

      bool SolveField(const double r[], double phi[], double Phi[], double Pi[],
                      double A[], double delta[]);

   private:
      SpatialSolverClass<SolverClass_ForwardScheme> SS;
      Derivative<Derivative_ForwardScheme> D;
      bool status; 
};


#endif
