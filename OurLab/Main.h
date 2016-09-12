#pragma once
#include "tMatrix.h"
#include "tVector.h"
#include "tPoly.h"
#include "globals.h"
#include <chrono>
#include <random>

extern double devLam;
extern double deva;
extern double devc;

double get_f(const tMatrix &A, const tVector &b, const tVector &x);
double _get_f(const tMatrix &A, const tVector &b, const tVector &x);
double get_rand_double(double a, double b);
tVector get_rand_vec(int n);
void SolveIncomp(const tMatrix &A, const tVector &b, tVector &x);


System::String^ toM(std::string str);
string toS(System::String^ s);

void normalizeX(const tVector X[], tVector XX[], int q0, int dim1, int dim2, int dim3);
void normalizeYtoB(const tVector Y[], tVector B[], int q0, int dimY);
void normalizeYtoB_average(const tVector Y[], tVector B[], int q0, int dimY);
void Read_X_Y(std::string filename, tVector X[], tVector Y[], int dim1, int dim2, int dim3, int dimY, int q0);

tPoly& Polynom(int type, int n); // Cheb - 0; Ermit - 1; Lezh - 2; Laher - 3;
double Polynom(int type, int n, double x);
void FillPoly(int p1, int p2, int p3, int type);

tVector get_lambda(int i, const tVector B[], const tVector XX[], int type, int p1, int p2, int p3, int dim1, int dim2, int dim3, int q0);
tVector get_lambda_break_down(int Y_num, const tVector B[], const tVector XX[], int type, int p1, int p2, int p3, int dim1, int dim2, int dim3, int q0);
tVector get_a_vec(int Y_num, const tVector B[], const tVector XX[], const tVector &lambda, int p1, int p2, int p3, int dim1, int dim2, int dim3, int q0, int type);
double PSI(int Vec_num, int Var_num, int q, const tVector XX[], const tVector &lambda,
	int p1, int p2, int p3, int dim1, int dim2, int dim3, int type); // 0: 0..1   1: 0..1   2: 0..2
double PHI(int Vec_num, int q, const tVector XX[], const tVector &lambda, const tVector &a, // Vec_num: 0..2
	int p1, int p2, int p3, int dim1, int dim2, int dim3, int type);

tVector get_c_vec(int Y_num, const tVector B[], const tVector XX[], const tVector &lambda, const tVector &a, int p1, int p2, int p3, int dim1, int dim2, int dim3, int q0, int type);

tPoly PSI_poly(int Vec_num, int Var_num, int q, const tVector XX[], const tVector &lambda,
	int p1, int p2, int p3, int dim1, int dim2, int dim3, int type);

std::string PHI_poly(int Vec_num, int q, const tVector XX[], const tVector &lambda, const tVector &a, // Vec_num: 0..2
	int p1, int p2, int p3, int dim1, int dim2, int dim3, int type);

void F_poly(std::string &Poly_form, std::string &Koef_form, std::string &Norm_koef_form,
	const tVector &lambda, const tVector &a, const tVector &c,
	int p1, int p2, int p3, int dim1, int dim2, int dim3, int type,
	int q, tVector XX[], tVector X[]);

double F_eval(const tVector &lambda, const tVector &a, const tVector &c,
	int p1, int p2, int p3, int dim1, int dim2, int dim3, int type,
	int q, tVector XX[]);

std::string PHI_str(int Vec_num, int q, const tVector XX[], const tVector &lambda, const tVector &a, // Vec_num: 0..2
	int p1, int p2, int p3, int dim1, int dim2, int dim3, int type);

std::string PSI_str(int Vec_num, int Var_num, int q, const tVector XX[], const tVector &lambda,
	int p1, int p2, int p3, int dim1, int dim2, int dim3, int type);  // 0: 0..1   1: 0..1   2: 0..2

std::string F_str_of_PSI(const tVector &lambda, const tVector &a, const tVector &c,
	int p1, int p2, int p3, int dim1, int dim2, int dim3, int type,
	int q, tVector XX[]);

std::string F_str_of_PHI(const tVector &lambda, const tVector &a, const tVector &c,
	int p1, int p2, int p3, int dim1, int dim2, int dim3, int type,
	int q, tVector XX[]);

std::string F_str_of_poly(const tVector &lambda, const tVector &a, const tVector &c,
	int p1, int p2, int p3, int dim1, int dim2, int dim3, int type,
	int q, tVector XX[]);

tPoly Polynom(int type, int n, double a, double den);



