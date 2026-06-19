#ifndef MATHFUNC_H
#define MATHFUNC_H

#include"essential_headers.h"

// =============================================================
// mathFunc.c
// =============================================================

long mf_nCr(long n, long r);
double mf_gauss(double x, double mean, double std);
double mf_lognormal(double x, double loc, double scale, double shape);
double mf_gamma(double x, double loc, double scale, double shape);
double mf_gumbel(double x, double loc, double scale);
double mf_johnsonSU(double x, double* params);
double mf_johnsonSB(double x, double* params);


#endif
