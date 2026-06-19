#include"private_matrix.h"

// np.zeros for a matrix with long ints
long* mx_Zeros(long rows, long columns){
	long* x = ar_Calloc(rows*columns);
	return x;
}

// np.zero for a matrix with doubles
double* mx_zeros(long rows, long columns){
	double* x = ar_calloc(rows*columns);
	return x;
}

// np.ones for a matrix with long ints
long* mx_Ones(long rows, long columns){
	long* x = ar_Alloc(rows*columns);
	for(long i=0;i<rows;i++){
		for(long j=0;j<columns;j++){
			x[i*columns+j] = 1;
		}
	}
	return x;
}

// np.ones for a matrix with doubles
double* mx_ones(long rows, long columns){
	double* x = ar_alloc(rows*columns);
	for(long i=0;i<rows;i++){
		for(long j=0;j<columns;j++){
			x[i*columns+j] = 1;
		}
	}
	return x;
}

// np.zeros for a matrix with long ints returning void
void mx_ZerosVoid(long* mx, long rows, long columns){
	for(long i=0;i<rows*columns;i++){
		mx[i] = 0;
	}
}

// np.zero for a matrix with doubles returning void
void mx_zerosVoid(double* mx, long rows, long columns){
	for(long i=0;i<rows*columns;i++){
		mx[i] = 0.0;
	}
}

// np.ones for a matrix with long ints returning void
void mx_OnesVoid(long* mx, long rows, long columns){
	for(long i=0;i<rows*columns;i++){
			mx[i] = 1;
	}
}

// np.ones for a matrix with doubles returning void 
void mx_onesVoid(double* mx, long rows, long columns){
	for(long i=0;i<rows*columns;i++){
			mx[i] = 1.0;
	}
}
