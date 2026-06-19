#include"private_calculus.h"

//=================================================================================================================
// Differentiation of a function===================================================================================

// Central Difference Method O(h^2) : less accurate, but faster 
double cl_diff(double (*func)(double), double x, double h){
	return (func(x + h) - func(x - h)) / (2.0 * h);
}

// Five point stencil method O(h^4) : more accurate, but slower
double cl_diffAccurate(double (*func)(double), double x, double h){
	double f_minus2 = func(x - 2.0*h);
	double f_minus1 = func(x - h);
	double f_plus1 = func(x + h);
	double f_plus2 = func(x + 2.0*h);

    return (-f_plus2 + 8.0*f_plus1 - 8.0*f_minus1 + f_minus2) / (12.0 * h);
}


//=================================================================================================================
// Integration of a function ======================================================================================

// Simpson's Integration
double cl_intg(double (*func)(double), double initial, double final, long n){
	if(n <= 0) return 0.0;

	// Make n even
	if(n % 2 != 0) n++;

	double h = (final - initial) / n;
	double sum = func(initial) + func(final);
	double x = initial + h;

	// Odd indices: weight 4
	for(long i = 1; i < n; i += 2){
		sum += 4.0 * func(x);
		x += 2.0 * h;
	}

	x = initial + 2.0 * h;
	// Even indices: weight 2
	for(long i = 2; i < n; i += 2){
		sum += 2.0 * func(x);
		x += 2.0 * h;
	}

	return sum * h / 3.0;
}

// Adaptive integration : more accurate, but slower - automatically adjusts stepsize
double cl_intgAdaptive(double (*func)(double), double initial, double final, double tol){
	// Simple recursive adaptive quadrature
	double c = (initial + final) / 2.0;
	double h = final - initial;

	// Estimate with one interval
	double S = h * (func(initial) + 4.0*func(c) + func(final)) / 6.0;

	// Estimate with two intervals
	double c1 = (initial + c) / 2.0;
	double c2 = (c + final) / 2.0;
	double S1 = (h/2.0) * (func(initial) + 4.0*func(c1) + func(c)) / 6.0;
	double S2 = (h/2.0) * (func(c) + 4.0*func(c2) + func(final)) / 6.0;

	if(fabs(S - (S1 + S2)) < 15.0 * tol){
		return S1 + S2 + (S1 + S2 - S) / 15.0;
	}

	// Recurse with tighter tolerance
	return cl_intgAdaptive(func, initial, c, tol/2.0) + cl_intgAdaptive(func, c, final, tol/2.0);
}

