#ifndef __DERIVATIVE_TEMPLATE__
#define __DERIVATIVE_TEMPLATE__

// Defined derivative schemes
#include "Derivative_ForwardScheme.h"

template <class scheme>
class Derivative{
   public:
      
      double derivative(const double f[], int index, double dx){
         return derivativeScheme.derivative(f, index, dx);
      }

   private:
      scheme derivativeScheme;
};


#endif
