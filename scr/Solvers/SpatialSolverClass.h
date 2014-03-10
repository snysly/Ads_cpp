#ifndef __SPATIALSOLVER_CLASS__
#define __SPATIALSOLVER_CLASS__

// Spetial Solvers
#include "SolverClass_ForwardScheme.h"

template <class SpatialSolver>
class SpatialSolverClass{
   public:
      
      // This function solve metric at for this field configuration
      bool MetricSolver(const double r[], const double phi[],
                        const double Phi[], const double Pi[],
                        double A[], double delta[]);

   private:
      SpatialSolver SS;
};

#include "SpatialSolverClass.inl"

template <class SpatialSolver>
bool SpatialSolverClass<SpatialSolver>::MetricSolver(
                               const double r[], const double phi[],
                               const double Phi[], const double Pi[],
                               double A[], double delta[]){
   return SS.Solve(r, phi, Phi, Pi, A, delta);
}


#endif
