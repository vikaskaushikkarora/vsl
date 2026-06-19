#include"private_arrays.h"

//======================================================================================
//======================================================================================

// Integrating an array with respect to a given array for x-variable
// Note: Assumes uniform step-size. User is responsible for ensuring this.
double ar_integrate(long Nx, double* x, double* Ix){
	double h = x[1] - x[0];
	double sum = 0.0;
	
	if(Nx % 2 == 1){
		// Odd points: pure Simpson's 1/3 rule
		sum = Ix[0] + Ix[Nx - 1];
		for(long i = 1; i < Nx - 1; i++){
			sum += (i % 2 == 0) ? 2.0 * Ix[i] : 4.0 * Ix[i];
		}
		sum *= h / 3.0;
	}else{
		// Even points: Simpson's 1/3 on bulk + Simpson's 3/8 on last 4 points
		long N13 = Nx - 3;
		sum = Ix[0] + Ix[N13 - 1];
		for(long i = 1; i < N13 - 1; i++){
			sum += (i % 2 == 0) ? 2.0 * Ix[i] : 4.0 * Ix[i];
		}
		sum *= h / 3.0;
		long j = Nx - 4;
		sum += (3.0 * h / 8.0) * (Ix[j] + 3.0*Ix[j+1] + 3.0*Ix[j+2] + Ix[j+3]);
	}
	return sum;
}

// Integrating an array with respect to a given array for x-variable when stepsize is not uniform
double ar_integrateQ(long Nx, double* x, double* Ix){
	double sum = 0.0;
	long i;
	for(i = 0; i < Nx - 2; i += 2){
		double h1 = x[i+1] - x[i];
		double h2 = x[i+2] - x[i+1];
		// Non-uniform Simpson's coefficients
		sum += (h1 + h2) / 6.0 * ( (2.0 - h2/h1) * Ix[i] + (h1 + h2)*(h1 + h2) / (h1 * h2) * Ix[i+1] + (2.0 - h1/h2) * Ix[i+2] );
	}
	// If even number of intervals remain, patch with trapezoidal
	if(i == Nx - 2){
		double h = x[Nx-1] - x[Nx-2];
		sum += 0.5 * h * (Ix[Nx-2] + Ix[Nx-1]);
	}
	return sum;
}

// Normalizing an array with respect to a given array for x-variable
void ar_normalize(long Nx, double* x, double* Ix){
	double factor = 1.0/ar_integrate(Nx,x,Ix);
	for(long i=0;i<Nx;i++){
		Ix[i] *= factor;
	}
}

// Normalizing an array with respect to a given array for x-variable when stepsize is not uniform
void ar_normalizeQ(long Nx, double* x, double* Ix){
	double factor = 1.0/ar_integrateQ(Nx,x,Ix);
	for(long i=0;i<Nx;i++){
		Ix[i] *= factor;
	}
}


//======================================================================================
//======================================================================================

// Copying arrays
long* ar_Copy(long Narr, long* arr){
	long* output = ar_Alloc(Narr);
	memcpy(output,arr,Narr*sizeof(long));
	return output;
}

double* ar_copy(long Narr, double* arr){
	double* output = ar_alloc(Narr);
	memcpy(output,arr,Narr*sizeof(double));
	return output;
}

void ar_CopyVoid(long* output, long Narr, long* arr){
	memcpy(output,arr,Narr*sizeof(long));
}

void ar_copyVoid(double* output, long Narr, double* arr){
	memcpy(output,arr,Narr*sizeof(double));
}

//======================================================================================
//======================================================================================

// Making the function for a long array
long* ar_Func(long (*func)(long), long Narr, long* arr){
	long* output = ar_Alloc(Narr);
	for(long i=0;i<Narr;i++){
		output[i] = func(arr[i]);
	}
	return output;
}

// Making the function for a double array
double* ar_func(double (*func)(double), long Narr, double* arr){
	double* output = ar_alloc(Narr);
	for(long i=0;i<Narr;i++){
		output[i] = func(arr[i]);
	}
	return output;
}

// Making the function for a long array returning void
void ar_FuncVoid(long* output, long (*func)(long), long Narr, long* arr){
	for(long i=0;i<Narr;i++){
		output[i] = func(arr[i]);
	}
}

// Making the function for a double array returning void
void ar_funcVoid(double* output, double (*func)(double), long Narr, double* arr){
	for(long i=0;i<Narr;i++){
		output[i] = func(arr[i]);
	}
}

// Making the function2 for a long array
long* ar_Func2(long (*func)(long,long), long Narr, long* arr1, long* arr2){
	long* output = ar_Alloc(Narr);
	for(long i=0;i<Narr;i++){
		output[i] = func(arr1[i],arr2[i]);
	}
	return output;
}

// Making the function2 for a double array
double* ar_func2(double (*func)(double,double), long Narr, double* arr1, double* arr2){
	double* output = ar_alloc(Narr);
	for(long i=0;i<Narr;i++){
		output[i] = func(arr1[i],arr2[i]);
	}
	return output;
}

// Making the function2 for a long array returning void
void ar_Func2Void(long* output, long (*func)(long,long), long Narr, long* arr1, long* arr2){
	for(long i=0;i<Narr;i++){
		output[i] = func(arr1[i],arr2[i]);
	}
}

// Making the function2 for a double array returning void
void ar_func2Void(double* output, double (*func)(double,double), long Narr, double* arr1, double* arr2){
	for(long i=0;i<Narr;i++){
		output[i] = func(arr1[i],arr2[i]);
	}
}

// Making the function3 for a long array
long* ar_Func3(long (*func)(long,long,long), long Narr, long* arr1, long* arr2, long* arr3){
	long* output = ar_Alloc(Narr);
	for(long i=0;i<Narr;i++){
		output[i] = func(arr1[i],arr2[i],arr3[i]);
	}
	return output;
}

// Making the function3 for a double array
double* ar_func3(double (*func)(double,double,double), long Narr, double* arr1, double* arr2, double* arr3){
	double* output = ar_alloc(Narr);
	for(long i=0;i<Narr;i++){
		output[i] = func(arr1[i],arr2[i],arr3[i]);
	}
	return output;
}

// Making the function3 for a long array returning void
void ar_Func3Void(long* output, long (*func)(long,long,long), long Narr, long* arr1, long* arr2, long* arr3){
	for(long i=0;i<Narr;i++){
		output[i] = func(arr1[i],arr2[i],arr3[i]);
	}
}

// Making the function3 for a double array returning void
void ar_func3Void(double* output, double (*func)(double,double,double), long Narr, double* arr1, double* arr2, double* arr3){
	for(long i=0;i<Narr;i++){
		output[i] = func(arr1[i],arr2[i],arr3[i]);
	}
}

//==========================================================================================
//==========================================================================================

// Gaussian function for Arrays
double* ar_gauss(long Nx, double* x, double mean, double std){
	double* arr = ar_alloc(Nx);
	double factor0 = 1.0/sqrt(2*M_PI*std*std);
	double factor = 1.0/(2*std*std);
	for(long i=0;i<Nx;i++){
		arr[i]=factor0*exp(-factor*(x[i]-mean)*(x[i]-mean));
	}
	return arr;
}

// Gaussian function for arrays, returns void
void ar_gaussVoid(double* output, long Nx, double* x, double mean, double std){
	double factor0 = 1.0/sqrt(2*M_PI*std*std);
	double factor = 1.0/(2*std*std);
	for(long i=0;i<Nx;i++){
		output[i]=factor0*exp(-factor*(x[i]-mean)*(x[i]-mean));
	}
}

