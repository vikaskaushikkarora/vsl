#ifndef CALCULUS_H
#define CALCULUS_H

#include"essential_headers.h"

// =============================================================
// calculus.c
// =============================================================

double cl_diff(double (*func)(double), double x, double h);
double cl_diffAccurate(double (*func)(double), double x, double h);
double cl_intg(double (*func)(double), double initial, double final, long n);
double cl_intgAdaptive(double (*func)(double), double initial, double final, double tol);

#endif
