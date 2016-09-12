#ifndef GLOBALS_H
#define GLOBALS_H

const double EPS = 1e-5;
const int PREC = 6;
const double MAX_WDTH = 15;

#define sqr(a) ( (a) * (a) )

extern "C"
{
   int len(double number);
   int is_zero(double number);
   int sign(double a);
}

#endif

