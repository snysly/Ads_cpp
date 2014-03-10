#include "InitialConditionClass_Gaussian.h"

InitialConditionClass_Gaussian::InitialConditionClass_Gaussian(){
   epsilon = 1.0;
   sigma   = 0.5;
   cout << "GAUSSIAN INITILIZATION SCHEME IS USED FOR INITIAL CONDTION" << endl;
}

bool InitialConditionClass_Gaussian::InitializeField(double r[], double phi[], double Phi[], double Pi[], int gridSize){
    double sigma2 = sigma*sigma;

    for (int i = 0; i < gridSize; i++){
       r[i]   = (double)i / (double)(gridSize-1) * PI_CONST / 2; 
       phi[i] = epsilon * exp(-tan(r[i]) * tan(r[i]) / sigma2);
       Phi[i] = -2 * epsilon * sin(r[i])
                   * exp(-tan(r[i]) * tan(r[i]) / sigma2)
                   / (sigma2 * cos(r[i]) * cos(r[i]) * cos(r[i]));
       Pi[i]  = 0;
    }

    return true;
}

