#include"private_arrays.h"

// Arange implementation in C
double* ar_arange(long Narr, double initial, double stepSize){
	double* arr = ar_alloc(Narr);
	for(long i=0;i<Narr;i++){
		arr[i] = initial + i*stepSize;
	}
	return arr;
}

// Arange implementation in C for long
long* ar_Arange(long Narr, long initial, long stepSize){
	long* arr = ar_Alloc(Narr);
	for(long i=0;i<Narr;i++){
		arr[i] = initial + i*stepSize;
	}
	return arr;
}

// Arange implementation in C, returns void
void ar_arangeVoid(double* arr, long Narr, double initial, double stepSize){
	for(long i=0;i<Narr;i++){
		arr[i] = initial + i*stepSize;
	}
}

// Arange implementation in C for long returns void
void ar_ArangeVoid(long* arr, long Narr, long initial, long stepSize){
	for(long i=0;i<Narr;i++){
		arr[i] = initial + i*stepSize;
	}
}

// Linspace implementation for C
double* ar_linspace(long Narr, double initial, double final){
	double* arr = ar_alloc(Narr);
	double stepSize=(final-initial)/(Narr-1);
	for(long i=0;i<Narr;i++){
		arr[i]=initial+i*stepSize;
	}
	return arr;
}

// Linspace implementation for C, returns void
void ar_linspaceVoid(double* arr, long Narr, double initial, double final){
	double stepSize=(final-initial)/(Narr-1);
	for(long i=0;i<Narr;i++){
		arr[i]=initial+i*stepSize;
	}
}

// np.zeros for an array with long ints
long* ar_Zeros(long Narr){
	long* arr = ar_Calloc(Narr);
	return arr;
}

// np.zeros for an array with doubles
double* ar_zeros(long Narr){
	double* arr = ar_calloc(Narr);
	return arr;
}

// np.zeros for an array with long ints, returns void
void ar_ZerosVoid(long* arr, long Narr){
	for(long j=0;j<Narr;j++){
		arr[j]=0;
	}
}

// np.zeros for an array with doubles, returns void
void ar_zerosVoid(double* arr, long Narr){
	for(long j=0;j<Narr;j++){
		arr[j]=0;
	}
}

// np.ones for an array with long ints
long* ar_Ones(long Narr){
	long* arr = ar_Alloc(Narr);
	for(long i=0;i<Narr;i++){
		arr[i] = 1;
	}
	return arr;
}

// np.ones for an array with doubles
double* ar_ones(long Narr){
	double* arr = ar_alloc(Narr);
	for(long i=0;i<Narr;i++){
		arr[i] = 1;
	}
	return arr;
}

// np.ones for an array with long ints, returns void
void ar_OnesVoid(long* arr, long Narr){
	for(long j=0;j<Narr;j++){
		arr[j]=1;
	}
}

// np.ones for an array with doubles, returns void
void ar_onesVoid(double* arr, long Narr){
	for(long j=0;j<Narr;j++){
		arr[j]=1;
	}
}

// np.nums for long ints
long* ar_Nums(long num, long Narr){
	long* output = ar_Alloc(Narr);
	for(long i=0;i<Narr;i++){
		output[i] = num;
	}
	return output;
}

// np.nums for doubles
double* ar_nums(double num, long Narr){
	double* output = ar_alloc(Narr);
	for(long i=0;i<Narr;i++){
		output[i] = num;
	}
	return output;
}

// np.nums for long ints returning void
void ar_NumsVoid(long* output, long num, long Narr){
	for(long i=0;i<Narr;i++){
		output[i] = num;
	}
}

// np.nums for doubles returning void
void ar_numsVoid(double* output, double num, long Narr){
	for(long i=0;i<Narr;i++){
		output[i] = num;
	}
}
