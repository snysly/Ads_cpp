template <class TimeEvolution>
bool TimeSolverClass<TimeEvolution>::EvolveFieldOneTimeStep(
                             const double r[], double phi[],
                             double Phi[], double Pi[],
                             double A[], double delta[]){
   return TE.SolveField(r, phi, Phi, Pi, A, delta);
}

