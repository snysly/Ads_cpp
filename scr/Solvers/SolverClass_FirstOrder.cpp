#include "SolverClass_FirstOrder.h"

SolverClass_FirstOrder::SolverClass_FirstOrder(void){
   cout << "TIME SOLVER FIRST ORDER CONSTRUCTED SUCCESSFULLY" << endl;
}

bool SolverClass_FirstOrder::SolveField(const double r[], double phi[],
                                 double Phi[], double Pi[],
                                 double A[], double delta[]){

   int i;
   double dr = r[1] - r[0];
   double dt = dr/4;

   // RK4 coefficient
   double *axTan  = new double[gridSize];
   double *axMet  = new double[gridSize];
   double *axFun1 = new double[gridSize];
   double *axFun2 = new double[gridSize];

   for (i = 0; i < (gridSize-1); i++){
      axTan[i]  = pow(tan(r[i]),DIM-1);
   }

   // k1 and h1
   status = SS.MetricSolver(r, phi, Phi, Pi, A, delta);
   if (!status){
     return false;
   }

   for (i = 0; i < gridSize; i++){
      axMet[i] = A[i] * exp(-delta[i]);   
   }

   for (i = 1; i < (gridSize-1); i++){
      axFun1[i] = axMet[i] * Pi[i];   
      axFun2[i] = axTan[i] * axMet[i] * Phi[i];   
   }
   axFun1[0] = 0;
   axFun2[0] = axFun2[1];
   axFun1[gridSize-1] = 0;
   axFun1[gridSize-1] = 0;

   // New Fields after time step dt at time dt + t
   for (i = 1; i < (gridSize-1); i++){
      Phi[i] += dt * D.derivative(axFun1, i, dr);
      Pi[i]  += dt * D.derivative(axFun2, i, dr) / axTan[i];
   }
   Pi[0] = Pi[1];
   Phi[0] = 0;
   Pi[gridSize-1] = 0;
   Phi[gridSize-1] = 0;

   delete [] axTan  ;
   delete [] axMet  ;
   delete [] axFun1 ;
   delete [] axFun2 ;

   return true;
}

