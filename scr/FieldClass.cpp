#include "FieldClass.h"

FieldClass::FieldClass(){
   A     = new double[gridSize];
   delta = new double[gridSize];
   r   = new double[gridSize];
   phi = new double[gridSize];
   Phi = new double[gridSize];
   Pi  = new double[gridSize];
   Psi = new double[gridSize];

   snapShotHeader = "# r, Phi, Pi, A, delta";
   phaseSpaceHeader = " Phase Space Header is not Implimented";

   status = true;
 
   cout << "FIELD CONSTRUCTED SUCCESSFULLY !" << endl;
}

FieldClass::~FieldClass(){
   delete [] A;
   delete [] delta;
   delete [] r;
   delete [] phi;
   delete [] Phi;
   delete [] Pi;
   delete [] Psi;
   cout << "FIELD DECONSTRUCTED SUCCESSFULLY !" << endl;
}

bool FieldClass::Initialize(){ 
   InitialConditionClass<InitialConditionClass_Gaussian> IC; //check to make sure I understand how the templating makes this work
   status = IC.Initialize(r, phi, Phi, Pi, gridSize);
   if (!status){
      cout << " ERROR: Field could not be initialized." << endl;
      return false;
   }
   return true;
}

bool FieldClass::saveSnapShot(string fname){ 
   return saveDataIntoFile(fname, snapShotHeader, r, Phi, Pi, A, delta, gridSize);
}

bool FieldClass::solveForOneTimeStep(){
   status = SSolve.MetricSolver(r, phi, Phi, Pi, A, delta);
   if (!status){
      cout << " ERROR: Problem occued during solving the metric." << endl;
      return false;
   }
   status = TSolve.EvolveFieldOneTimeStep(r, phi, Phi, Pi, A, delta);
   if (!status){
      cout << " ERROR: Problem occued during evolving field." << endl;
      return false;
   }
   return true;
}

