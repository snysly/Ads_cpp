#include "SolverClass_RK4.h"

SolverClass_RK4::SolverClass_RK4(void){
   cout << "TIME SOLVER RK4 CONSTRUCTED SUCCESSFULLY" << endl;
}

bool SolverClass_RK4::SolveField(const double r[], double phi[],
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
   double *PiNew  = new double[gridSize];
   double *PhiNew = new double[gridSize];

   double *k1 = new double[gridSize];
   double *k2 = new double[gridSize];
   double *k3 = new double[gridSize];  
   double *k4 = new double[gridSize];

   double *h1 = new double[gridSize];
   double *h2 = new double[gridSize];
   double *h3 = new double[gridSize];  
   double *h4 = new double[gridSize];

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

   for (i = 1; i < (gridSize-1); i++){
      k1[i] = D.derivative(axFun1, i, dr);
      h1[i] = D.derivative(axFun2, i, dr) / axTan[i];
   }

   // k2 and h2
   for (i = 1; i < (gridSize-1); i++){
      PhiNew[i] = Phi[i] + 0.5 * dt * k1[i];   
      PiNew[i]  = Pi[i]  + 0.5 * dt * h1[i];   
   }
   PhiNew[0] = 0;
   PiNew[0]  = PiNew[1]; 
   PhiNew[gridSize-1] = 0;
   PiNew[gridSize-1]  = 0;

   status = SS.MetricSolver(r, phi, PhiNew, PiNew, A, delta);
   if (!status){
     return false;
   }

   for (i = 0; i < gridSize; i++){
      axMet[i] = A[i] * exp(-delta[i]);   
   }

   for (i = 1; i < (gridSize-1); i++){
      axFun1[i] = axMet[i] * PiNew[i];   
      axFun2[i] = axTan[i] * axMet[i] * PhiNew[i];   
   }
   axFun1[0] = 0;
   axFun2[0] = axFun2[1];
   axFun1[gridSize-1] = 0;
   axFun1[gridSize-1] = 0;

   for (i = 1; i < (gridSize-1); i++){
      k2[i] = dt * D.derivative(axFun1, i, dr);
      h2[i] = dt * D.derivative(axFun2, i, dr) / axTan[i];
   }

   // k3 and h3
   for (i = 1; i < (gridSize-1); i++){
      PhiNew[i] = Phi[i] + 0.5 * dt * k2[i];   
      PiNew[i]  = Pi[i]  + 0.5 * dt * h2[i];   
   }
   PhiNew[0] = 0;
   PiNew[0]  = PiNew[1]; 
   PhiNew[gridSize-1] = 0;
   PiNew[gridSize-1]  = 0;

   status = SS.MetricSolver(r, phi, PhiNew, PiNew, A, delta);
   if (!status){
     return false;
   }

   for (i = 0; i < gridSize; i++){
      axMet[i] = A[i] * exp(-delta[i]);   
   }

   for (i = 1; i < (gridSize-1); i++){
      axFun1[i] = axMet[i] * PiNew[i];   
      axFun2[i] = axTan[i] * axMet[i] * PhiNew[i];   
   }
   axFun1[0] = 0;
   axFun2[0] = axFun2[1];
   axFun1[gridSize-1] = 0;
   axFun1[gridSize-1] = 0;

   for (i = 1; i < (gridSize-1); i++){
      k3[i] = D.derivative(axFun1, i, dr);
      h3[i] = D.derivative(axFun2, i, dr) / axTan[i];
   }

   // k4 and h4
   for (i = 1; i < (gridSize-1); i++){
      PhiNew[i] = Phi[i] + dt * k3[i];   
      PiNew[i]  = Pi[i]  + dt * h3[i];   
   }
   PhiNew[0] = 0;
   PiNew[0]  = PiNew[1]; 
   PhiNew[gridSize-1] = 0;
   PiNew[gridSize-1]  = 0;

   status = SS.MetricSolver(r, phi, PhiNew, PiNew, A, delta);
   if (!status){
     return false;
   }

   for (i = 0; i < gridSize; i++){
      axMet[i] = A[i] * exp(-delta[i]);   
   }

   for (i = 1; i < (gridSize-1); i++){
      axFun1[i] = axMet[i] * PiNew[i];   
      axFun2[i] = axTan[i] * axMet[i] * PhiNew[i];   
   }
   axFun1[0] = 0;
   axFun2[0] = axFun2[1];
   axFun1[gridSize-1] = 0;
   axFun1[gridSize-1] = 0;

   for (i = 1; i < (gridSize-1); i++){
      k4[i] = D.derivative(axFun1, i, dr);
      h4[i] = D.derivative(axFun2, i, dr) / axTan[i];
   }
  
   // New Fields after time step dt at time dt + t
   for (i = 1; i < (gridSize-1); i++){
      Phi[i] += dt * (k1[i] + 2*k1[i] + 2*k1[i] + k1[i]) / 6;
      Pi[i]  += dt * (h1[i] + 2*h1[i] + 2*h1[i] + h1[i]) / 6;
   }
   Phi[0] = 0;
   Pi[0] = Pi[1];
   Phi[gridSize-1] = 0;
   Pi[gridSize-1] = 0;

   delete [] k1;
   delete [] k2;
   delete [] k3;
   delete [] k4;

   delete [] h1;
   delete [] h2;
   delete [] h3;
   delete [] h4;

   delete [] axTan  ;
   delete [] axMet  ;
   delete [] axFun1 ;
   delete [] axFun2 ;
   delete [] PiNew  ;
   delete [] PhiNew ;

   return true;
}

