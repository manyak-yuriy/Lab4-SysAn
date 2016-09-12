/*
   Yuriy Manyak
   KA-23
   IASA-2014
*/

#include "stdafx.h"
#include "tPoly.h"
#include <iomanip>
#include "globals.h"


const int prec = 15;

tPoly der(tPoly one)
{
   tPoly res(one.power() - 1);
   for (int i = 0; i <= one.power() - 1; i++)
	  res.koeff[i] = one[i + 1] * (i + 1);
   return res;
}

void swapPoly(tPoly &P, tPoly &Q)
{
   int t = P.n;
   P.n = Q.n;
   Q.n = t;

   double *s = P.koeff;
   P.koeff = Q.koeff;
   Q.koeff = s;
}

tPoly :: tPoly(int n, const double *koeff)
{
   this -> n = n;
   this -> koeff = new double[n + 1];
   for (int i = 0; i <= n; i++)
	  (this -> koeff)[i] = koeff[i];
}

tPoly :: tPoly()
{
   this -> n = -1;
   this -> koeff = 0;
}

double tPoly :: eval(double x)
{
   double value = 0;
   for (int i = n; i >= 0; i--)
	  value = value * x + koeff[i];
   return value;
}

string tPoly::str(const string &varname)
{
   stringstream stream;
   for (int i = n; i >= 0; i--)
   {
	 stream << setprecision(prec) << koeff[i];
	 switch (i)
	 {
		case 0:
		   {
			  break;
		   }
		case 1:
		   {
			  stream << " * " + varname + " + ";
			  break;
		   }
		default:
		   {
			  stream << " * " + varname + "^" << i << " + ";
			  break;
		   }
	 }
   }
   return stream.str();
}

tPoly :: ~tPoly()
{
   this -> n = -1;
   delete[] this -> koeff;
}

tPoly :: tPoly(double a0)
{
   this -> n = 0;
   koeff = new double[1];
   koeff[0] = a0;
}

tPoly :: tPoly(double a1, double a0)
{
   this -> n = 1;
   koeff = new double[2];
   koeff[0] = a0;
   koeff[1] = a1;
}

tPoly :: tPoly(double a2, double a1, double a0)
{
   this -> n = 2;
   koeff = new double[3];
   koeff[0] = a0;
   koeff[1] = a1;
   koeff[2] = a2;
}

tPoly :: tPoly(int n)
{
   this -> n = n;
   this -> koeff = new double[n + 1];
   for (int i = 0; i <= n; i++)
	  koeff[i] = 0;
}

tPoly :: tPoly(tPoly &other)
{
   this -> n = other.power();
   /*if (koeff)
	  delete[] koeff;  */
   koeff = new double[other.power() + 1];
   for (int i = 0; i <= n; i++)
	  koeff[i] = other[i];
}

tPoly& tPoly :: operator=(const tPoly &other)
{
   this -> n = other.power();
   if (koeff)
	  delete[] koeff;
   koeff = new double[other.power() + 1];
   for (int i = 0; i <= n; i++)
	  koeff[i] = other[i];
   return *this;
}

tPoly :: tPoly(const tPoly &other)
{
   this -> n = other.power();
   /*if (koeff)
	  delete[] koeff;        */
   koeff = new double[other.power() + 1];
   for (int i = 0; i <= n; i++)
	  koeff[i] = other[i];
}

 double tPoly :: operator[](int i)
 {
	if (i > this -> power())
	   throw new tExc("This coefficient of polynomial is not defined!");
	return (this -> koeff)[i];
 }

 double tPoly :: operator[](int i) const
 {
	if (i > this -> power())
	   throw new tExc("This coefficient of polynomial is not defined!");
	return (this -> koeff)[i];
 }

tPoly operator+(tPoly P, tPoly Q)
{
	if (Q.power() > P.power())
	   swapPoly(P, Q);
	tPoly Res(P);
	for (int i = 0; i <= Q.power(); i++)
	   Res.koeff[i] += Q.koeff[i];
	return Res;
}

tPoly operator-(tPoly P, tPoly Q)
{
	tPoly Res(P);
	for (int i = 0; i <= Q.power(); i++)
		Res.koeff[i] -= Q.koeff[i];
	return Res;
}

tPoly operator*(const tPoly &P, const tPoly &Q)
{
	tPoly R(P.power() + Q.power());
	for (int i = 0; i <= P.power(); i++)
	   for (int j = 0; j <= Q.power(); j++)
		  R.koeff[i + j] = R[i + j] + P[i] * Q[j];
	return R;
}

tPoly operator*(double k, const tPoly &P)
{
   tPoly res(P.power());
   for (int i = 0; i <= P.power(); i++)
	  res.koeff[i] = k * P.koeff[i];
   return res;
}

tPoly operator/(const tPoly &P, const double k)
{
   tPoly res(P.power());
   for (int i = 0; i <= P.power(); i++)
	  res.koeff[i] = P.koeff[i] / k;
   return res;
}

tPoly operator+(double a, tPoly Q)
{
   tPoly res(Q);
   Q.koeff[0] += a;
   return res;
}

tPoly operator+(tPoly Q, double a)
{
   return operator+(a, Q);
}
