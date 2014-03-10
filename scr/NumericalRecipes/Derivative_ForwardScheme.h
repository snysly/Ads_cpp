#ifndef __DERIVATIVE_FORWARDSCHEME__
#define __DERIVATIVE_FORWARDSCHEME__

class Derivative_ForwardScheme{
   public:
      double derivative(const double f[], int index, double dx){
         return (-1.5*f[index-1]+2*f[index]-0.5*f[index+1])/dx;
      }
};

#endif
