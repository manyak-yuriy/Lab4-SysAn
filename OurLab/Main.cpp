#include "MyForm.h"
#include "Main.h"
#include "tPoly.h"
#include <algorithm>
#include "math.h"

using namespace System;
using namespace System::Windows::Forms;
#pragma region Polys_arrays
tPoly Cheb[100];
tPoly Ermit[100];
tPoly Lezh[100];
tPoly Laher[100];

tPoly U_[100];
tPoly C_[100];
tPoly S_[100];

#pragma endregion
#define func_log tanh
double devLam = 0;
double deva = 0;
double devc = 0;

double magic_num = -0.99;

// !!! outdated
tPoly PSI_poly(int Vec_num, int Var_num, int q, const tVector XX[], const tVector &lambda,
	int p1, int p2, int p3, int dim1, int dim2, int dim3, int type)  // 0: 0..1   1: 0..1   2: 0..2
{
	tPoly res(0.0);
	switch (Vec_num)
	{

	case 0:
	{
			  // first vector
			  for (int k = 0; k < p1; k++)
				  res =  res + lambda.elem(k + p1 * (Var_num))
				  * Polynom(type, k);
			  break;
	}
	case 1:
	{
			  // second vector
			  for (int k = 0; k < p2; k++)
				  res = res + lambda.elem(k + dim1 * p1 + p2 * (Var_num))
				  * Polynom(type, k);
			  break;
	}
	case 2:
	{
			  // third vector
			  for (int k = 0; k < p3; k++)
				  res = res + lambda.elem(k + dim1 * p1 + dim2 * p2 + p3 * (Var_num))
				  * Polynom(type, k);
			  break;
	}

	}

	return res;
}

tVector get_c_vec(int Y_num, const tVector B[], const tVector XX[], const tVector &lambda, const tVector &a, int p1, int p2, int p3, int dim1, int dim2, int dim3, int q0, int type)
{
	tMatrix A(q0, 3);
	tVector x(3);
	tVector b(q0);
	for (int q = 0; q < q0; q++)
		b[q] = log( 1 +  B[q].elem(Y_num) );

	for (int q = 0; q < q0; q++)
	for (int j = 0; j < 3; j++)
	{
		A(q, j) = log(1 + PHI(j, q, XX, lambda, a, p1, p2, p3, dim1, dim2, dim3, type));
	}

	SolveIncomp(A, b, x);
	devc = get_f(A, b, x);
	return x;
}
	
double PHI(int Vec_num, int q, const tVector XX[], const tVector &lambda, const tVector &a, // Vec_num: 0..2
	int p1, int p2, int p3, int dim1, int dim2, int dim3, int type)
{
	double res = 0;
	switch (Vec_num)
	{
		case 0:
		{
				  for (int k = 0; k < dim1; k++)
					  res += a.elem(k) * log(1 + PSI(0, k, q, XX, lambda, p1, p2, p3, dim1, dim2, dim3, type) );
				  res = exp(res) - 1;
				  break;
		}
		case 1:
		{
				  for (int k = 0; k < dim2; k++)
					  res += a.elem(k + dim1) * log( 1 + PSI(1, k, q, XX, lambda, p1, p2, p3, dim1, dim2, dim3, type) );
				  res = exp(res) - 1;
				  break;
		}
		case 2:
		{
				  for (int k = 0; k < dim3; k++)
					  res += a.elem(k + dim1) * log( 1 + PSI(2, k, q, XX, lambda, p1, p2, p3, dim1, dim2, dim3, type) );
				  res = exp(res) - 1;
				  break; 
		}
	}
	return res;
}

tVector get_a_vec(int Y_num, const tVector B[], const tVector XX[], const tVector &lambda, int p1, int p2, int p3, int dim1, int dim2, int dim3, int q0, int type)
{
	int m = dim1 + dim2 + dim3;
	tMatrix A(q0, m);
	tVector b(q0);
	tVector x(m);

	for (int q = 0; q < q0; q++)
		b[q] =  log( 1 + B[q].elem(Y_num) );
	
	for (int q = 0; q < q0; q++)
	{
		for (int k = 0; k < dim1; k++)
		{
			A(q, k) = log( 1 + PSI(0, k, q, XX, lambda, p1, p2, p3, dim1, dim2, dim3, type) );
		}
		for (int k = 0; k < dim2; k++)
		{
			A(q, dim1 + k) = log( 1 + PSI(1, k, q, XX, lambda, p1, p2, p3, dim1, dim2, dim3, type) );
		}
		for (int k = 0; k < dim3; k++)
		{
			A(q, dim1 + dim2 + k) = log( 1 + PSI(2, k, q, XX, lambda, p1, p2, p3, dim1, dim2, dim3, type) );
		}
	}

	SolveIncomp(A, b, x);
	deva = get_f(A, b, x);
	return x;
}

void FillPoly(int p1, int p2, int p3, int type) // Cheb - 0; Ermit - 1; Lezh - 2; Laher - 3;
{
	int power = max(p1, max(p2, p3));
	if (power > 100)
		throw "Polynom power is too big";
	type = 0;
	switch (type)
	{
	case 0: // Cheb
	{
				Cheb[0] = tPoly(1.0);
				Cheb[1] = tPoly(2.0, -1.0); // -1 + 2 * x
				for (int i = 2; i <= power; i++)
					Cheb[i] = 2 * tPoly(2.0, -1.0) * Cheb[i - 1] - Cheb[i - 2];
				Cheb[0] = tPoly(0.5);
				
				/*
				Cheb[0] = tPoly(1.0);
				Cheb[1] = tPoly(4.0, -2.0);
				for (int i = 1; i <= power; i++)
					Cheb[i + 1] = tPoly(4.0, -2.0) * Cheb[i] - Cheb[i - 1];
				Cheb[0] = tPoly(0.5);*/
	}
	case 1: // Ermit
	{
				Ermit[0] = tPoly(1.0);
				Ermit[1] = tPoly(2.0, 0.0);
				for (int i = 1; i <= power; i++)
					Ermit[i + 1] = 2 * tPoly(2.0, 0.0) * Ermit[i] - 2 * i * Ermit[i - 1];
				
	}
	case 2: // Lezh
	{
				Lezh[0] = tPoly(1.0);
				Lezh[1] = tPoly(1.0, 0.0);
				for (int i = 1; i <= power; i++)
					Lezh[i + 1] = (1.0 / (i + 1))*((2 * i + 1) * tPoly(1.0, 0.0) * Lezh[i] - i * Lezh[i - 1]);
				
	}
	case 3: // Laher
	{
				Laher[0] = tPoly(1.0);
				Laher[1] = tPoly(-1.0, 1.0);
				for (int i = 1; i <= power; i++)
					Laher[i + 1] = tPoly(-1.0, 2 * i + 1) * Laher[i] - i * i * Laher[i - 1];
				
	}
	case 4: // U(x)
	{
				U_[0] = tPoly(1.0);
				U_[1] = tPoly(2.0, 0.0);
				for (int i = 1; i <= power; i++)
					U_[i + 1] = tPoly(2.0, 0.0) * U_[i] - U_[i - 1];
				U_[0] = tPoly(0.5);
				
	}
	case 5: // C*(x)
	{
				C_[0] = tPoly(2.0);
				C_[1] = tPoly(1.0, 0.0);
				for (int i = 1; i <= power; i++)
					C_[i + 1] = tPoly(1.0, 0.0) * C_[i] - C_[i - 1];
				C_[0] = tPoly(1.0);
				
	}
	case 6: // S*(x)
	{
				S_[0] = tPoly(1.0);
				S_[1] = tPoly(1.0, 0.0);
				for (int i = 1; i <= power; i++)
					S_[i + 1] = tPoly(1.0, 0.0) * S_[i] - S_[i - 1];
				S_[0] = tPoly(0.5);
				
	}
	}
}

tPoly Polynom(int type, int n, double a, double den)
{
	tPoly term(1.0 / den, a / den);
	tPoly accum(1.0);
	tPoly pattern = Polynom(type, n);
	tPoly res(0.0);
	for (int p = 0; p <= n; p++)
	{
		res = res + pattern[p] * accum;
		accum = accum * term;
	}
	return res;
}

tPoly& Polynom(int type, int n) // Cheb - 0; Ermit - 1; Lezh - 2; Laher - 3; U - 4; C - 5; S - 6;
{
	switch (type)
	{
		case 0: return Cheb[n];
		case 1: return Ermit[n];
		case 2: return Lezh[n];
		case 3: return Laher[n];
		case 4: return Cheb[n];//U_[n];
		case 5: return C_[n];
		case 6: return S_[n];
	}
}
double Polynom(int type, int n, double x)
{
	return Polynom(type, n).eval(x);
}

tVector get_lambda_break_down(int Y_num, const tVector B[], const tVector XX[], int type, int p1, int p2, int p3, int dim1, int dim2, int dim3, int q0)
{
	int m = p1 * dim1 + p2 * dim2 + p3 * dim3;
	tVector lambda(m);

	tVector lambda1(p1 * dim1);
	tVector b1(q0);
	tMatrix A1(q0, p1 * dim1);

	for (int i = 0; i < q0; i++)
		b1[i] = log( 1 + B[i].elem(Y_num) );

	for (int i = 0; i < q0; i++)
	   for (int X_var = 0; X_var < dim1; X_var++)
	      for (int k = 0; k < p1; k++)
		     A1(i, k + p1 * (X_var)) = log( 1 + Polynom(type, k, XX[i].elem(X_var)) );

   SolveIncomp(A1, b1, lambda1);
   devLam = get_f(A1, b1, lambda1);
   tVector lambda2(p2 * dim2);
   tVector b2(b1);
   tMatrix A2(q0, p2 * dim2);

   for (int i = 0; i < q0; i++)
   for (int X_var = 0; X_var < dim2; X_var++)
   for (int k = 0; k < p2; k++)
	   A2(i, k + p2 * (X_var)) = log( 1 + Polynom(type, k, XX[i].elem(X_var)) );

   SolveIncomp(A2, b2, lambda2);

   tVector lambda3(p3 * dim3);
   tVector b3(b1);
   tMatrix A3(q0, p3 * dim3);

   for (int i = 0; i < q0; i++)
   for (int X_var = 0; X_var < dim3; X_var++)
   for (int k = 0; k < p3; k++)
	   A3(i, k + p3 * (X_var)) = log( 1 + Polynom(type, k, XX[i].elem(X_var)) );

   SolveIncomp(A3, b3, lambda3);

   for (int X_var = 0; X_var < dim1; X_var++)
   for (int k = 0; k < p1; k++)
	   lambda[k + p1 * (X_var)] = lambda1.elem(k + p1 * (X_var));

   for (int X_var = 0; X_var < dim2; X_var++)
   for (int k = 0; k < p2; k++)
	   lambda[k + dim1 * p1 + p2 * (X_var)] = lambda2.elem(k + p2 * (X_var));

   for (int X_var = 0; X_var < dim3; X_var++)
   for (int k = 0; k < p3; k++)
	   lambda[k + dim1 * p1 + dim2 * p2 + p3 * (X_var)] = lambda3.elem(k + p3 * (X_var));

   return lambda;
}




tVector get_lambda(int Y_num, const tVector B[], const tVector XX[], int type, int p1, int p2, int p3, int dim1, int dim2, int dim3, int q0)
{
	int m = p1 * dim1 + p2 * dim2 + p3 * dim3;
	tMatrix A(q0, m);
	tVector lambda(m);
	tVector b(q0);
	
	for (int i = 0; i < q0; i++)
		double view = b[i] = log(B[i].elem(Y_num) + 1);

	for (int i = 0; i < q0; i++)
	{
		// first vector
		for (int X_var = 0; X_var < dim1; X_var++)
		for (int k = 0; k < p1; k++)
		{
			double po = Polynom(type, k, XX[i].elem(X_var));
			if (po < magic_num)
				po = magic_num;
			double view = A(i, k + p1 * (X_var)) = func_log(1 + po);
		}
		// second vector
		for (int X_var = 0; X_var < dim2; X_var++)
		for (int k = 0; k < p2; k++)
		{
			double po = Polynom(type, k, XX[i].elem(dim1 + X_var));
			if (po < magic_num)
				po = magic_num;
			double view = A(i, k + dim1 * p1 + p2 * (X_var)) = func_log(1 + po);
		}
		// third vector
		for (int X_var = 0; X_var < dim3; X_var++)
		for (int k = 0; k < p3; k++)
		{
			double po = Polynom(type, k, XX[i].elem(dim1 + dim2 + X_var));
			if (po < magic_num)
				po = magic_num;
			double view = A(i, k + dim1 * p1 + dim2 * p2 + p3 * (X_var)) = func_log(1 + po);
		}
	}

	SolveIncomp(A, b, lambda);
	devLam = get_f(A, b, lambda);
	return lambda;
}

double PSI(int Vec_num, int Var_num, int q, const tVector XX[], const tVector &lambda,
	int p1, int p2, int p3, int dim1, int dim2, int dim3, int type)  // 0: 0..1   1: 0..1   2: 0..2
{
	double res = 0;
	switch (Vec_num)
	{

	case 0:
	{
		// first vector
		for (int k = 0; k < p1; k++)
		{
			double po = Polynom(type, k, XX[q].elem(Var_num));
			if (po < magic_num)
				po = magic_num;
			res += lambda.elem(k + p1 * (Var_num))
					  * log(1 + po);
		}
		res = exp(res) - 1;
		break;
	}
	case 1:
	{
	   // second vector
			  for (int k = 0; k < p2; k++)
			  {
				  double po = Polynom(type, k, XX[q].elem(dim1 + Var_num));
				  if (po < magic_num)
					  po = magic_num;
				  res += lambda.elem(k + dim1 * p1 + p2 * (Var_num))
					  * log(1 + po);
			  }
		res = exp(res) - 1;
		break;
	}
	case 2:
	{
	    // third vector
			  for (int k = 0; k < p3; k++)
			  {
				  double po = Polynom(type, k, XX[q].elem(dim1 + dim2 + Var_num));
				  if (po < magic_num)
					  po = magic_num;
				  res += lambda.elem(k + dim1 * p1 + dim2 * p2 + p3 * (Var_num))
					  * log(1 + po);
			  }
		res = exp(res) - 1;
		break;
	}

	}

	return res;
}
/// outdated
std::string PHI_poly(int Vec_num, int q, const tVector XX[], const tVector &lambda, const tVector &a, // Vec_num: 0..2
	int p1, int p2, int p3, int dim1, int dim2, int dim3, int type)
{
	std::string res;
	switch (Vec_num)
	{
	case 0:
	{
			  for (int k = 0; k < dim1; k++)
			  {
				  res = res + (a.elem(k) * PSI_poly(0, k, q, XX, lambda, p1, p2, p3, dim1, dim2, dim3, type)).str("x1" + toS((k + 1).ToString()));
				  if (k != dim1 - 1)
					  res += " + ";
			  }
			  break;
	}
	case 1:
	{
			  for (int k = 0; k < dim2; k++)
			  {
				  res = res + (a.elem(k + dim1) * PSI_poly(1, k, q, XX, lambda, p1, p2, p3, dim1, dim2, dim3, type)).str("x2" + toS((k + 1).ToString()));
				  if (k != dim2 - 1)
					  res += " + ";
			  }
			  break;
	}
	case 2:
	{
			  for (int k = 0; k < dim3; k++)
			  {
				  res = res + (a.elem(k + dim1) * PSI_poly(2, k, q, XX, lambda, p1, p2, p3, dim1, dim2, dim3, type)).str("x3" + toS((k + 1).ToString()));
				  if (k != dim3 - 1)
					  res += " + ";
			  }
			  break;
	}
	}
	return res;
}

// !!! outdated
// returns three forms: Poly_form, Koef_form, Norm_koef_form
void F_poly(std::string &Poly_form, std::string &Koef_form, std::string &Norm_koef_form, 
	const tVector &lambda, const tVector &a,const tVector &c, 
	int p1, int p2, int p3, int dim1, int dim2, int dim3, int type,
	int q, tVector XX[], tVector X[])
{
	Koef_form = "";

	// first vector
			  for (int vec_num = 0; vec_num < dim1; vec_num++)
			  {
				  Koef_form = Koef_form + (c.elem(0) * a.elem(vec_num) * PSI_poly(0, vec_num, q, X, lambda, p1-1, p2-1, p3-1, dim1, dim2, dim3, type)).str("x1" + toS((vec_num + 1).ToString()));
				  if (vec_num != dim1 - 1)
					  Koef_form += " + ";
			  }
			 
	// second vector
			  for (int vec_num = 0; vec_num < dim2; vec_num++)
			  {
				  Koef_form = Koef_form + (c.elem(1) * a.elem(vec_num + dim1) * PSI_poly(1, vec_num, q, X, lambda, p1-1, p2-1, p3-1, dim1, dim2, dim3, type)).str("x2" + toS((vec_num + 1).ToString()));
				  if (vec_num != dim2 - 1)
					  Koef_form += " + ";
			  }
	// third vector
			  for (int vec_num = 0; vec_num < dim3; vec_num++)
			  {
				  Koef_form = Koef_form + (c.elem(2) * a.elem(vec_num + dim1 + dim2) * PSI_poly(2, vec_num, q, X, lambda, p1-1, p2-1, p3-1, dim1, dim2, dim3, type)).str("x3" + toS((vec_num + 1).ToString()));
				  if (vec_num != dim3 - 1)
					  Koef_form += " + ";
			  }

    Norm_koef_form = "";
	//Str!!!
	// first vector
	for (int vec_num = 0; vec_num < dim1; vec_num++)
	{
		Norm_koef_form = Norm_koef_form + (c.elem(0) * a.elem(vec_num) * PSI_poly(0, vec_num, q, XX, lambda, p1, p2, p3, dim1, dim2, dim3, type)).str("x1" + toS((vec_num + 1).ToString()));
		if (vec_num != dim1 - 1)
			Norm_koef_form += " + ";
	}

	// second vector
	for (int vec_num = 0; vec_num < dim2; vec_num++)
	{
		Norm_koef_form = Norm_koef_form + (c.elem(1) * a.elem(vec_num + dim1) * PSI_poly(1, vec_num, q, XX, lambda, p1, p2, p3, dim1, dim2, dim3, type)).str("x2" + toS((vec_num + 1).ToString()));
		if (vec_num != dim2 - 1)
			Norm_koef_form += " + ";
	}
	// third vector
	for (int vec_num = 0; vec_num < dim3; vec_num++)
	{
		Norm_koef_form = Norm_koef_form + (c.elem(2) * a.elem(vec_num + dim1 + dim2) * PSI_poly(2, vec_num, q, XX, lambda, p1, p2, p3, dim1, dim2, dim3, type)).str("x3" + toS((vec_num + 1).ToString()));
		if (vec_num != dim3 - 1)
			Norm_koef_form += " + ";
	}

	
			  Poly_form = "";
	// first vector
			  for (int Var_num = 0; Var_num < dim1; Var_num++)
			  for (int k = 0; k < p1; k++)
			      Poly_form = Poly_form + toS(lambda.elem(k + p1 * (Var_num)).ToString()) +
				    " * T[" + toS(k.ToString()) + "](" + "x1" + toS((Var_num + 1).ToString()) + ") + ";
					
	// second vector
			  for (int Var_num = 0; Var_num < dim2; Var_num++)
			  for (int k = 0; k < p2; k++)
				  Poly_form = Poly_form + toS(lambda.elem(k + p1 + p2 * (Var_num)).ToString()) +
				  " * T[" + toS(k.ToString()) + "](" + "x2" + toS((Var_num + 1).ToString()) + ") + ";
		
	// third vector
			  for (int Var_num = 0; Var_num < dim3; Var_num++)
			  for (int k = 0; k < p3; k++)
				  Poly_form = Poly_form + toS(lambda.elem(k + p1 + p2 + p3 * (Var_num)).ToString()) +
				  " * T[" + toS(k.ToString()) + "](" + "x3" + toS((Var_num + 1).ToString()) + ")" + ((k==p3-1)? "" : " + ");
}



string toS(System::String^ s)
{
	msclr::interop::marshal_context context;
	std::string standardString = context.marshal_as<std::string>(s);
	return standardString;
}

String^ toM(string str)
{
	String^ str3 = gcnew String(str.c_str());
	return str3;
}

void normalizeX(const tVector X[], tVector XX[], int q0, int dim1, int dim2, int dim3)
{
	for (int q = 0; q < q0; q++)
		XX[q] = tVector(dim1 + dim2 + dim3);

	for (int j = 0; j < dim1 + dim2 + dim3; j++)
	{
		double minxj = X[0].elem(j);
		double maxxj = X[0].elem(j);
		for (int q = 0; q < q0; q++)
		{
			if (X[q].elem(j) < minxj)
				minxj = X[q].elem(j);
			if (X[q].elem(j) > maxxj)
				maxxj = X[q].elem(j);
		}

		for (int q = 0; q < q0; q++)
		{
			XX[q][j] = (X[q].elem(j) - minxj) / (maxxj - minxj);
		}
	}
	
}

void normalizeYtoB(const tVector Y[], tVector B[], int q0, int dimY)
{
	for (int q = 0; q < q0; q++)
		B[q] = tVector(dimY);

	for (int j = 0; j < dimY; j++)
	{
		double minyj = Y[0].elem(j);
		double maxyj = Y[0].elem(j);
		for (int q = 0; q < q0; q++)
		{
			if (Y[q].elem(j) < minyj)
				minyj = Y[q].elem(j);
			if (Y[q].elem(j) > maxyj)
				maxyj = Y[q].elem(j);
		}

		for (int q = 0; q < q0; q++)
		{
			B[q][j] = (Y[q].elem(j) - minyj) / (maxyj - minyj);
		}
	}
}

void normalizeYtoB_average(const tVector Y[], tVector B[], int q0, int dimY)
{
	if (Y != B)
	for (int q = 0; q < q0; q++)
		B[q] = tVector(dimY);
	for (int q = 0; q < q0; q++)
	{
		double max = Y[q].elem(0);
		double min = Y[q].elem(0);
		for (int j = 0; j < dimY; j++)
		{
			if (Y[q].elem(j) > max)
				max = Y[q].elem(j);
			if (Y[q].elem(j) < min)
				min = Y[q].elem(j);
		}
		for (int j = 0; j < dimY; j++)
		{
			B[q][j] = (max + min) / 2.0;
		}
	}
}

double get_f(const tMatrix &A, const tVector &b, const tVector &x)
{
	double delta_max = 0;
	//const double MAG = 1E+10;
	for (int i = 0; i < A.row_cnt(); i++)
	{
		double delta = 0;
		for (int j = 0; j < A.col_cnt(); j++)
			delta += A.at(i, j) * x.elem(j);
		delta -= b.elem(i);
		delta = abs(delta);
		if (delta > delta_max)
			delta_max = delta;
	}
	return delta_max;
	//return _get_f(A,b,x);
}

double _get_f(const tMatrix &A, const tVector &b, const tVector &x)
{
	double delta_sum = 0;
	const double MAG = 1E+10;
	for (int i = 0; i < A.row_cnt(); i++)
	{
		double delta = 0;
		for (int j = 0; j < A.col_cnt(); j++)
			delta += MAG * A.at(i, j) * x.elem(j);
		delta -= MAG * b.elem(i);
		delta = abs(delta);
		delta_sum += delta * delta;
	}
	return delta_sum;
}

static unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
static std::default_random_engine generator(seed);

double get_rand_double(double a, double b)
{
	
	std::uniform_real_distribution<double> distribution(a, b);
	double res = distribution(generator);
	return res;
}

tVector get_rand_vec(int n)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<double> distribution(0.0, 1000000.0);

	tVector V(n);
	for (int i = 0; i < n; i++)
	{
		V[i] = distribution(generator);
	}

	V.normalize();

	return V;
}

void SolveIncomp(const tMatrix &A, const tVector &b, tVector &x)
{
	double g = 0.01;
	double lambda_max = 0.01;
	const int m = 8;
	const double MAGN = 1E+30;

	tVector KSI[m];
	double delta_f[m];

	double prev = _get_f(A, b, x);
	double curr;
	int hits = 0;

	for (int iter = 0; iter < 100000; iter++)
	{
		for (int j = 0; j < m; j++)
			KSI[j] = get_rand_vec(x.size());

		for (int j = 0; j < m; j++)
		{
			double d1 = MAGN * _get_f(A, b, x + g * KSI[j]);
			double d2 = MAGN * _get_f(A, b, x);
			delta_f[j] = d1 - d2;
		}

		tVector grad(x.size());
		for (int j = 0; j < m; j++)
			grad = grad + delta_f[j] * KSI[j];

		grad.normalize();

		double lambda;
		double lambda_OPT = lambda_max;



		int n = A.row_cnt();
		int mm = A.col_cnt();

		double nom, den;
		nom = 0;
		den = 0;

		for (int i = 0; i < n; i++)
		{
			double aa = 0;
			double bb = 0;
			double cc = 0;

			for (int j = 0; j < mm; j++)
			{
				aa += A.at(i, j) * grad.elem(j);
				bb += A.at(i, j) * x.elem(j);
				cc = aa;
			}
			bb -= b.elem(i);
			nom += aa * bb;
			den += cc * cc;
		}

		lambda_OPT = nom / den;
		lambda_OPT = get_rand_double(0, lambda_max);
		tVector x_new = x - lambda_OPT * grad;
		x = x_new;

		curr = _get_f(A, b, x);

		if (curr > prev)
			hits++;
		else
			hits = 0;

		if (hits > 4)
		{
			//cout << "broken" << endl;
			break;
		}

		prev = curr;
		//cout << prev << endl;
	}
	//cout << x << endl;
	//cout << prev << endl;
}

void Read_X_Y(std::string filename, tVector X[], tVector Y[], int dim1, int dim2, int dim3, int dimY, int q0)
{
	ifstream myfile(filename);

	for (int q = 0; q < q0; q++)
	{
		X[q] = tVector(dim1 + dim2 + dim3);
		for (int j = 0; j < dim1 + dim2 + dim3; j++)
		{
			double a;
			myfile >> a;
			X[q][j] = a;
		}
	}

	std::string dummy;
	std::getline(myfile, dummy);

	for (int q = 0; q < q0; q++)
	{
		Y[q] = tVector(dimY);
		for (int j = 0; j < dimY; j++)
		{
			double a;
			myfile >> a;
			Y[q][j] = a;
		}
	}
	
}

double F_eval(const tVector &lambda, const tVector &a, const tVector &c,
	int p1, int p2, int p3, int dim1, int dim2, int dim3, int type,
	int q, tVector XX[])
{
	double res = 0;
	// first vector
	for (int vec_num = 0; vec_num < dim1; vec_num++)
	{
		double ln = log(1 + PSI(0, vec_num, q, XX, lambda, p1, p2, p3, dim1, dim2, dim3, type));
		res += (c.elem(0) * a.elem(vec_num) * ln);
	}

	// second vector
	for (int vec_num = 0; vec_num < dim2; vec_num++)
	{
		double ln = PSI(1, vec_num, q, XX, lambda, p1, p2, p3, dim1, dim2, dim3, type);
		res += (c.elem(1) * a.elem(vec_num + dim1) * ln);
	}
	// third vector
	for (int vec_num = 0; vec_num < dim3; vec_num++)
	{
		double ln = PSI(2, vec_num, q, XX, lambda, p1, p2, p3, dim1, dim2, dim3, type);
		res += (c.elem(2) * a.elem(vec_num + dim1 + dim2) * ln);
	}
	res = exp(res) - 1;
	return res;
}

std::string PHI_str(int Vec_num, int q, const tVector XX[], const tVector &lambda, const tVector &a, // Vec_num: 0..2
	int p1, int p2, int p3, int dim1, int dim2, int dim3, int type)
{
	std::string res;
	switch (Vec_num)
	{
	case 0:
	{
			  for (int k = 0; k < dim1; k++)
			  {
				  res = res + "[ 1 + " + "PSI(x" + toS((Vec_num + 1).ToString()) + toS((k + 1).ToString()) + ")" + "]^" + toS(a.elem(k).ToString());
				  if (k != dim1 - 1)
					  res += " * ";
			  }
			  res = res + " - 1";
			  break;
	}
	case 1:
	{
			  for (int k = 0; k < dim2; k++)
			  {
				  res = res + "[ 1 + " + "PSI(x" + toS((Vec_num + 1).ToString()) + toS((k + 1).ToString()) + ")" + "]^" + toS(a.elem(dim1 + k).ToString());
				  if (k != dim2 - 1)
					  res += " * ";
			  }
			  res = res + " - 1";
			  break;
	}
	case 2:
	{
			  for (int k = 0; k < dim3; k++)
			  {
				  res = res + "[ 1 + " + "PSI(x" + toS((Vec_num + 1).ToString()) + toS((k + 1).ToString()) + ")" + "]^" + toS(a.elem(dim1 + dim2 + k).ToString());
				  if (k != dim3 - 1)
					  res += " * ";
			  }
			  res = res + " - 1";
			  break;
	}
	}
	return res;
}

std::string PSI_str(int Vec_num, int Var_num, int q, const tVector XX[], const tVector &lambda,
	int p1, int p2, int p3, int dim1, int dim2, int dim3, int type)  // 0: 0..1   1: 0..1   2: 0..2
{
	std::string res;
	std::string vec_str = toS((Vec_num + 1).ToString());
	std::string var_str = toS((Var_num + 1).ToString());
	switch (Vec_num)
	{

	case 0:
	{
			  // first vector
			  for (int k = 0; k < p1; k++)
			  {
				  res = res + "[ 1 + " + Polynom(type, k).str("x" + vec_str + var_str) + " ] ^ " +
					 toS(lambda.elem(k + p1 * (Var_num)).ToString());
				  if (k != p1 - 1)
					  res += " * ";
			  }
			  res = res + " - 1";
			  break;
	}
	case 1:
	{
			  // second vector
			  for (int k = 0; k < p2; k++)
			  {
				  res = res + "[ 1 + " + Polynom(type, k).str("x" + vec_str + var_str) + " ] ^ " +
					  toS(lambda.elem(k + dim1 * p1 + p2 * (Var_num)).ToString());
				  if (k != p2 - 1)
					  res += " * ";
			  }
			  res = res + " - 1";
			  break;
	}
	case 2:
	{
			  // third vector
			  for (int k = 0; k < p3; k++)
			  {
				  res = res + "[ 1 + " + Polynom(type, k).str("x" + vec_str + var_str) + " ] ^ " +
					  toS(lambda.elem(k + dim1 * p1 + dim2 * p2 + p3 * (Var_num)).ToString());
				  if (k != p3 - 1)
					  res += " * ";
			  }
			  res = res + " - 1";
			  break;
	}

	}

	return res;
}


std::string F_str_of_PHI(const tVector &lambda, const tVector &a, const tVector &c,
	int p1, int p2, int p3, int dim1, int dim2, int dim3, int type,
	int q, tVector XX[])
{
	std::string res;

	for (int vec_num = 0; vec_num < 3; vec_num++)
	{
		res = res +  "[ 1 + PHI(x" + toS((vec_num + 1).ToString()) + ") ] ^ " + toS(c.elem(vec_num).ToString());
		if (vec_num != 2)
			res += " * ";
	}
	res = res + " - 1";
	
	return res;
}

std::string F_str_of_PSI(const tVector &lambda, const tVector &a, const tVector &c,
	int p1, int p2, int p3, int dim1, int dim2, int dim3, int type,
	int q, tVector XX[])
{
	std::string res;
	// first vector 
	int Vec_num = 0;
	for (int var_num = 0; var_num < dim1; var_num++)
	{
		double power = c.elem(0) * a.elem(var_num);
		res = res + "[ 1 + " + "PSI(x" + toS((Vec_num + 1).ToString()) + toS((var_num + 1).ToString()) + ")" + " ] ^ " + toS(power.ToString());

		res += " * ";
	}

	// second vector
	Vec_num = 1;
	for (int var_num = 0; var_num < dim2; var_num++)
	{
		double power = c.elem(1) * a.elem(var_num + dim1);
		res = res + "[ 1 + " + "PSI(x" + toS((Vec_num + 1).ToString()) + toS((var_num + 1).ToString()) + ")" + " ] ^ " + toS(power.ToString());

		res += " * ";
	}

	// third vector
	Vec_num = 2;
	for (int var_num = 0; var_num < dim3; var_num++)
	{
		double power = c.elem(2) * a.elem(var_num + dim1 + dim2);
		res = res + "[ 1 + " + "PSI(x" + toS((Vec_num + 1).ToString()) + toS((var_num + 1).ToString()) + ")" + " ] ^ " + toS(power.ToString());
		if (var_num != dim3 - 1)
			res += " * ";
	}

	res += " - 1";
	return res;
}

std::string F_str_of_poly(const tVector &lambda, const tVector &a, const tVector &c,
	int p1, int p2, int p3, int dim1, int dim2, int dim3, int type,
	int q, tVector XX[])
{
	std::string res;
	// first vector 
	int Vec_num = 0;
	for (int var_num = 0; var_num < dim1; var_num++)
	{
		std::string vec_str = toS((Vec_num + 1).ToString());
		std::string var_str = toS((var_num + 1).ToString());

		for (int k = 0; k < p1; k++)
		{
			double power = c.elem(0) * a.elem(var_num) * lambda.elem(k + p1 * (var_num));
			res = res + "[ 1 + " + Polynom(type, k).str("x" + vec_str + var_str) + " ] ^ "
				+ toS(power.ToString());
			res += " * ";
		}
	}

	// second vector
	Vec_num = 1;
	for (int var_num = 0; var_num < dim2; var_num++)
	{
		std::string vec_str = toS((Vec_num + 1).ToString());
		std::string var_str = toS((var_num + 1).ToString());

		for (int k = 0; k < p2; k++)
		{
			double power = c.elem(1) * a.elem(var_num) * lambda.elem(k + p1 * dim1 + p2 * (var_num));
			res = res + "[ 1 + " + Polynom(type, k).str("x" + vec_str + var_str) + " ] ^ "
				+ toS(power.ToString());
			res += " * ";
		}
	}

	// third vector
	Vec_num = 2;
	for (int var_num = 0; var_num < dim3; var_num++)
	{
		std::string vec_str = toS((Vec_num + 1).ToString());
		std::string var_str = toS((var_num + 1).ToString());

		for (int k = 0; k < p3; k++)
		{
			double power = c.elem(2) * a.elem(var_num) * lambda.elem(k + p1 * dim1 + p2 * dim2 + p3 * (var_num));
			res = res + "[ 1 + " + Polynom(type, k).str("x" + vec_str + var_str) + " ] ^ "
				+ toS(power.ToString());
			if ( (var_num != dim3 - 1) || (k != p3- 1) )
				res += " * ";
		}
	}

	res += " - 1";
	return res;
}

[STAThread]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	OurLab::MyForm form;
	Application::Run(%form);
	return 0;
}