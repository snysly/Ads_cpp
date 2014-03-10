#include "SolverClass_ForwardScheme.h"

SolverClass_ForwardScheme::SolverClass_ForwardScheme(void){
   cout << "SOLVER Forward Scheme CONSTRUCTED SUCCESSFULLY" << endl;
}

bool SolverClass_ForwardScheme::Solve(const double r[], const double phi[],
                                      const double Phi[], const double Pi[],
                                      double A[], double delta[]){

    int i;
    double dr = r[1] - r[0];
    double D  = (double)DIM;

    // Solving delta
    // constructing matrix delta = f
    double *am = new double[gridSize-1];
    double *bm = new double[gridSize-1];
    double *cm = new double[gridSize-1];
    double *axVar = new double[gridSize-1]; // axVar = sin(2r)x(Pi^2 + Phi^2)

    bm[0] = 1; 
    cm[0] = 0;
    delta[0] = 0;

    for (i = 1; i < (gridSize-1); i++){
       am[i]    = -3; 
       bm[i]    =  4;
       cm[i]    = -1;
       axVar[i] = sin(2*r[i]) * (Pi[i]*Pi[i] + Phi[i]*Phi[i]);
       delta[i] = -dr * axVar[i];
    }
    // Due to Boundary condition for delta
    bm[gridSize-2] = 3;

    status = solveTridiagonalMatrix(delta, gridSize-1, am, bm, cm);
    // Boundary condition for delta
    delta[0] = 0; 
    delta[gridSize-1] = delta[gridSize-2];

    if (!status){
       return false;
    }
    ////////////////// DELTA IS SOLVED /////////////////////////
    // Solving A
    // constructing matrix A = f
    bm[0] = 1; 
    cm[0] = 0;
    A[0]  = 1;

    for (i = 1; i < (gridSize-1); i++){
       am[i] = -3;
       bm[i] = 4 + dr * ( axVar[i] 
                          + 4 * ( D - 2 * cos(r[i]) * cos(r[i]) ) 
                              / ( sin(r[i]) * sin(r[i]) ) 
                        );
       cm[i] = -1;
       A[i]  = dr * 4 * ( D - 2 * cos(r[i]) * cos(r[i]) ) 
                  / ( sin(r[i]) * sin(r[i]) ) ;
    }    
    // Due to Boundary condition for A [A(r=pi/2)=1]
    A[gridSize-2] += 1; 

    status = solveTridiagonalMatrix(A, gridSize-1, am, bm, cm);
    // Boundary condition for A
    A[0] = 1; 
    A[gridSize-1] = 1;

    if (!status){
       return false;
    }
    ////////////////// A IS SOLVED /////////////////////////

    // Realese allocated arrays
    delete [] am;
    delete [] bm;
    delete [] cm;
    delete [] axVar;

    return true;
}

