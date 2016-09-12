#include "stdafx.h"
#include <math.h>

#include "globals.h"

#define EPS0 1e-15

int len(double a)
{
   int res = 0;
   if (a < 0)
	  a = -a;
   while (a > 1)
   {
	  res++;
	  a /= 10;
   }
   return res + (PREC);
}

int is_zero(double a)
{
   if ( fabs(a) < EPS0 )
	  return 1;
   return 0;
}

int sign(double a)
{
   if ( abs(a) < EPS )
      return 0;
   if ( a > 0 )
	  return 1;
   return -1;
}
