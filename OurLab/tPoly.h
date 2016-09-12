#ifndef POLY_H
#define POLY_H

/*
   Yuriy Manyak
   KA-23
   IASA-2014
*/

#include <string>
#include <sstream>
using namespace std;

class tPoly
{
   private:
	  double *koeff;
	  int n;
   public:
	  tPoly();
	  tPoly(int n);
	  tPoly(int n, const double *koeff);
	  tPoly(double a0);
	  tPoly(double a1, double a0);
	  tPoly(double a2, double a1, double a0);
	  tPoly(tPoly &other);
	  tPoly(const tPoly &other);

	  inline int power() const { return n; }

	  double eval(double x);
	  string str(const string &varname);

	  friend tPoly der(tPoly P);
	  double operator[] (int i);
	  double operator[] (int i) const;
	  friend tPoly operator+(tPoly P, tPoly Q);
	  friend tPoly operator-(tPoly P, tPoly Q);
	  friend tPoly operator+(double a, tPoly Q);
	  friend tPoly operator+(tPoly Q, double a);
	  friend tPoly operator*(const tPoly &P, const tPoly &Q);
	  friend tPoly operator*(double k, const tPoly &Q);
	  friend tPoly operator/(const tPoly &Q, const double k);
	  friend void swapPoly(tPoly &P, tPoly &Q);
	  tPoly& operator=(const tPoly &other);

	  ~tPoly();
};

class tExc
{
   private:
	  string *err;
   public:
	  tExc(const char *str)
	  {
	     err = new string(str);
	  }

	  string message() const
	  {
		 return *err;
	  }

	  ~tExc()
	  {
		 delete err;
	  }
};

#endif                        


