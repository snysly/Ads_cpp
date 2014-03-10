#ifndef __SOLVER_CLASS_FORWARDSCHEME__
#define __SOLVER_CLASS_FORWARDSCHEME__

#include <cmath>
#include <iostream>
using namespace std;
#include "../constants.h"

#include "../GlobalFunctions/solveTridiagonalMatrix.h"

class SolverClass_ForwardScheme{
   public:
      
      SolverClass_ForwardScheme(void);

      bool ReturnTrue(double r[], double phi[], double Phi[], double Pi[],
                      double A[], double delta[]){
         return false;
      }

      bool Solve(const double r[], const double phi[],
                 const double Phi[], const double Pi[],
                 double A[], double delta[]);

   private:
      bool status;
};


#endif
