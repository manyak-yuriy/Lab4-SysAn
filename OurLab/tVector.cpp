#include "stdafx.h"
#include "tVector.h"
#include <fstream>
#include "globals.h"
#include <iomanip>
#include <sstream>

tVector :: tVector()
{
   this -> n = 0;
   this -> v = 0;
}

tVector :: tVector(double x, double y)
{
   this -> n = 2;
   v = new double[2];
   v[0] = x;
   v[1] = y;
}

tVector :: tVector(double x, double y, double z)
{
   this -> n = 3;
   v = new double[3];
   v[0] = x;
   v[1] = y;
   v[2] = z;
}

tVector :: tVector(int n)
{
   this -> n = n;
   v = new double[n];
   for (int i = 0; i < n; i++)
      v[i] = 0;
}

double & tVector :: operator[](int i)
{
   if (i >= this -> n)
	  throw "tVector: out of range.";
   return v[i];
}

double tVector :: elem(int i) const
{
   if (i >= this -> n)
	  throw "tVector: out of range.";
   return v[i];
}

tVector :: ~tVector()
{
   if (v)
	  delete[] v;
   this -> n = 0;
   v = 0;
}

tVector :: tVector(const tVector &Vec)
{
   this -> n = Vec.n;
   this -> v = new double[n];
   for (int i = 0; i < n; i++)
	  (*this)[i] = Vec.elem(i);
}

tVector tVector :: operator=(const tVector &Vec)
{
   if ( this -> n != Vec.n )
   {
	  if (v)
		 delete[] v;
	  v = new double[Vec.size()];
	  this -> n = Vec.size();
   }
   for (int i = 0; i < n; i++)
	  (*this)[i] = Vec.elem(i);
   return *this;
}


tVector :: tVector(const char *filename)
{
   ifstream file(filename);
   file >> n;
   this -> n = n;
   this -> v = new double[n];
   for (int i = 0; i < n; i++)
      file >> (*this)[i];
}

void tVector :: print(const char *hint, const char *filename) const
{
   int dig;
   int max_len = 0;

   for (int i = 0; i < size(); i++)
	  if ( ( dig = len( (*this).elem(i) ) ) > max_len  )
	     max_len = dig;

   ofstream file(filename);
   double num;

   if (max_len > MAX_WDTH)
	  max_len = MAX_WDTH;

   file << hint << endl;
   file << '(';
   for (int i = 0; i < size(); i++)
   {
	  num = (*this).elem(i);
	  /*if ( abs(num) < EPS )
		 num = 0; */
	  file << setw(max_len + 3) << setprecision(PREC) << num << ' ';
	  if (i != size() - 1)
	     file << ", ";
   }
   file << ')';
   file << endl;
}

std::string tVector::toStr(void)
{
	int dig;
	int max_len = 0;

	for (int i = 0; i < size(); i++)
	if ((dig = len((*this).elem(i))) > max_len)
		max_len = dig;

	std::stringstream file;
	double num;

	if (max_len > MAX_WDTH)
		max_len = MAX_WDTH;

	file << '(';
	for (int i = 0; i < size(); i++)
	{
		num = (*this).elem(i);
		/*if ( abs(num) < EPS )
		num = 0; */
		file << setw(max_len + 3) << setprecision(PREC) << num << ' ';
		if (i != size() - 1)
			file << ", ";
	}
	file << ')';
	file << endl;
	return file.str();
}


tVector operator-(const tVector &Vec1, const tVector &Vec2)
{
   if ( Vec1.size() != Vec2.size() )
	  throw "Can't substract two vectors with different dimensions.";
   tVector Vec(Vec1);
   for (int i = 0; i < Vec1.size(); i++)
	  Vec[i] -= Vec2.elem(i);
   return Vec;
}

tVector operator+(const tVector &Vec1, const tVector &Vec2)
{
   if ( Vec1.size() != Vec2.size() )
	  throw "Can't add two vectors with different dimensions.";
   tVector Vec(Vec1);
   for (int i = 0; i < Vec1.size(); i++)
	  Vec[i] += Vec2.elem(i);
   return Vec;
}

double operator*(const tVector &Vec1, const tVector &Vec2)
{
   if ( Vec1.size() != Vec2.size() )
	  throw "Can't multiply two vectors with different dimensions.";
   double res = 0;
   for (int i = 0; i < Vec1.size(); i++)
	  res += Vec1.elem(i) * Vec2.elem(i);
   return res;
}

tVector operator*(double k, const tVector &Vec1)
{
	tVector Res(Vec1.size());
	for (int j = 0; j < Vec1.size(); j++)
		Res[j] = k * Vec1.elem(j);
	return Res;
} 

double tVector :: norm(void) const
{
   double res = 0;
   for (int i = 0; i < this -> size(); i++)
	  res += sqr(this -> elem(i));
   return sqrt(res);
}

void tVector :: normalize(void)
{
	double res = 0;
	for (int i = 0; i < this->size(); i++)
		res += sqr(this->elem(i));

	for (int i = 0; i < this->size(); i++)
	    (*this)[i] /= sqrt(res);
}

ostream &operator<<(ostream &file, tVector Vec)
{
   int dig;
   int max_len = 0;

   for (int i = 0; i < Vec.size(); i++)
	  if ( ( dig = len( Vec.elem(i) ) ) > max_len  )
		 max_len = dig;

   double num;

   if (max_len > MAX_WDTH)
	  max_len = MAX_WDTH;

   file << '(';
   for (int i = 0; i < Vec.size(); i++)
   {
	  num = Vec.elem(i);
	  /*if ( abs(num) < EPS )
		 num = 0; */
	  file << setw(max_len + 3) << setprecision(PREC) << num << ' ';
	  if (i != Vec.size() - 1)
	     file << ", ";
   }
   file << ')';
   file << endl;
   return file;
}

