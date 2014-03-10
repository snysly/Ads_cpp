#ifndef __TIMESOLVER_CLASS__
#define __TIMESOLVER_CLASS__

// Time Evolution Solvers for field 
#include "SolverClass_RK4.h"
#include "SolverClass_FirstOrder.h"

template <class TimeEvolution>
class TimeSolverClass{
   public:
      
      // This function evolve the field for one time step
      // and return the new values of field
      bool EvolveFieldOneTimeStep(const double r[], double phi[],
                                  double Phi[], double Pi[],
                                  double A[], double delta[]);

   private:
      TimeEvolution TE;
};

#include "TimeSolverClass.inl"


#endif
