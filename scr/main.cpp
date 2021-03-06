/************************************************  
**  Arya Farahi - aryaf@umich.edu              **
**  EECS 402 - Winter 2014                     **
**  Project 4                                  **
************************************************/
/////////////////////////////////////////////////
/////////////////////////////////////////////////
// Libraries ////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////

#include <iostream>
using namespace std;
#include "constants.h"
#include "FieldClass.h"


/////////////////////////////////////////////////
/////////////////////////////////////////////////
// Main Code ////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
int main(void){

   bool status = false;

   FieldClass F;
   
   status = F.Initialize();
   //status = F.saveSnapShot("./output/snapshots/IC_Snapshot.txt");
   status = F.solveForOneTimeStep();
   //status = F.saveSnapShot("./output/snapshots/1_Snapshot.txt");
   status = F.solveForOneTimeStep();
   //status = F.saveSnapShot("./output/snapshots/2_Snapshot.txt");
   status = F.solveForOneTimeStep();
   //status = F.saveSnapShot("./output/snapshots/3_Snapshot.txt");
   status = F.solveForOneTimeStep();
   status = F.solveForOneTimeStep();
   status = F.solveForOneTimeStep();
   status = F.solveForOneTimeStep();
   status = F.solveForOneTimeStep();
   status = F.solveForOneTimeStep();
   status = F.solveForOneTimeStep();
   status = F.saveSnapShot("./output/snapshots/10_Snapshot.txt");

   cout << "\n Thanks for using Gravitational Collapse Code!\n";
   return 0;
}




