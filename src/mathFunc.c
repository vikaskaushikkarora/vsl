#include"private_mathFunc.h"

// Combination function nCr
long mf_nCr(long n, long r){
	if (r > n - r) r = n - r;  // use smaller r for efficiency
	long result = 1;
	for (int i = 0; i < r; i++){
		result *= (n - i);
		result /= (i + 1);
	}
	return result;
}

// Gaussian function
double mf_gauss(double x, double mean, double std){
	return exp(-(x-mean)*(x-mean)/(2*std*std))/sqrt(2*M_PI*std*std);
}

// Log normal
double mf_lognormal(double x, double loc, double scale, double shape){
	if (shape <= 0.0 || scale <= 0.0 || x <= loc) return 0.0;
	double z = (x - loc) / scale;
	double logf = -log(z) - log(shape) - 0.5*log(2.0*M_PI) - (log(z)*log(z))/(2.0*shape*shape);
	return exp(logf)/scale;
}

// Gamma function
double mf_gamma(double x, double loc, double scale, double shape){
	if (x <= loc || shape <= 0.0 || scale <= 0.0) return 0.0;
	double logf = (shape-1.0)*log(x-loc) - ((x-loc)/scale) - lgamma(shape) - shape*log(scale);
    return exp(logf);
}

// Gumbel function
double mf_gumbel(double x, double loc, double scale){
	double z = (x-loc)/scale;
	return exp( -z-exp(-z) )/scale;
}

// Johnson SU function
double mf_johnsonSU(double x, double* params){
	double y1 = (x-params[0])/params[1];
	double z1 = 1/sqrt( 1 + y1*y1 );
	double y2 = params[2] + params[3]*asinh(y1);
	double z2 = exp(-0.5*y2*y2);
	double normFactor = params[3]/(params[1]*sqrt(2*M_PI));
	return normFactor*z1*z2;
}

// Johnson SB function
double mf_johnsonSB(double x, double* params){
	if (x <= params[0] || x >= params[0] + params[1]) return 0.0;
	double y1 = (x-params[0])/(params[0]+params[1]-x);
	double z1 = 1.0/((x-params[0])*(params[0]+params[1]-x));
	double y2 = params[2] +params[3]*log(y1);
	double z2 = exp(-0.5*y2*y2);
	double normFactor = params[3]*params[1]/sqrt(2*M_PI);
	return normFactor*z1*z2;
}
