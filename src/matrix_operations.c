#include"private_matrix.h"

// ========================================================================
// Elements of a matrix
// ========================================================================

// Accessing the (a,b) element of a matrix with long ints
long mx_GetElement(long numRow, long numColumn, long rows, long columns, long* matrix){
	return matrix[numRow*columns+numColumn];
}

// Changing the (a,b) element of a matrix with long ints
void mx_ChangeElement(long input, long numRow, long numColumn, long rows, long columns, long* matrix){
	matrix[numRow*columns+numColumn]=input;
}

// Accessing the (a,b) element of a matrix with doubles
double mx_getElement(long numRow, long numColumn, long rows, long columns, double* matrix){
	return matrix[numRow*columns+numColumn];
}

// Changing the (a,b) element of a matrix with doubles
void mx_changeElement(double input, long numRow, long numColumn, long rows, long columns, double* matrix){
	matrix[numRow*columns+numColumn]=input;
}

// ========================================================================
// Rows and Columns of a matrix
// ========================================================================

// Extract row from a matrix of long ints
long* mx_GetRow(long rowNumber, long rows, long columns, long* matrix){
	long* arr = ar_Alloc(columns);
	for(long j=0;j<columns;j++){
		arr[j] = matrix[rowNumber*columns+j];
	}
	return arr;
}

// Extract row from a matrix of double
double* mx_getRow(long rowNumber, long rows, long columns, double* matrix){
	double* arr = ar_alloc(columns);
	for(long j=0;j<columns;j++){
		arr[j] = matrix[rowNumber*columns+j];
	}
	return arr;
}

// Extract column from a matrix of long ints ----------------------------------------
long* mx_GetColumn(long columnNumber, long rows, long columns, long* matrix){
	long* arr = ar_Alloc(rows);
	for(long i=0;i<rows;i++){
		arr[i] = matrix[columns*i+columnNumber];
	}
	return arr;
}

// Extract column from a matrix of double -------------------------------------------
double* mx_getColumn(long columnNumber, long rows, long columns, double* matrix){
	double* arr = ar_alloc(rows);
	for(long i=0;i<rows;i++){
		arr[i] = matrix[columns*i+columnNumber];
	}
	return arr;
}

// Extract row from a matrix of long ints return void
void mx_GetRowVoid(long* output, long rowNumber, long rows, long columns, long* matrix){
	for(long j=0;j<columns;j++){
		output[j] = matrix[rowNumber*columns+j];
	}
}

// Extract row from a matrix of double returns void
void mx_getRowVoid(double* output, long rowNumber, long rows, long columns, double* matrix){
	for(long j=0;j<columns;j++){
		output[j] = matrix[rowNumber*columns+j];
	}
}

// Extract column from a matrix of long ints return void
void mx_GetColumnVoid(long* output, long columnNumber, long rows, long columns, long* matrix){
	for(long i=0;i<rows;i++){
		output[i] = matrix[columns*i+columnNumber];
	}
}

// Extract column from a matrix of double reutns void
void mx_getColumnVoid(double* output, long columnNumber, long rows, long columns, double* matrix){
	for(long i=0;i<rows;i++){
		output[i] = matrix[columns*i+columnNumber];
	}
}

// ========================================================================
// Scaling the entries of a matrix
// ========================================================================

// Scaling the entries of a matrix of long ints by a number --------------------
long* mx_Scale(long N, long rows, long columns, long* matrix){
	long* output = ar_Alloc(rows*columns);
	for(long i=0;i<rows;i++){
		for(long j=0;j<columns;j++){
			output[i*columns+j] = N*matrix[i*columns+j];
		}
	}
	return output;
}

// Scaling the entries of a matrix of double by a number -----------------------
double* mx_scale(long N, long rows, long columns, double* matrix){
	double* output = ar_alloc(rows*columns);
	for(long i=0;i<rows;i++){
		for(long j=0;j<columns;j++){
			output[i*columns+j] = N*matrix[i*columns+j];
		}
	}
	return output;
}

// Scaling the entries of a matrix of long ints by a number --------------------
void mx_ScaleVoid(long* output, long N, long rows, long columns, long* matrix){
	for(long i=0;i<rows;i++){
		for(long j=0;j<columns;j++){
			output[i*columns+j] = N*matrix[i*columns+j];
		}
	}
}

// Scaling the entries of a matrix of double by a number -----------------------
void mx_scaleVoid(double* output, long N, long rows, long columns, double* matrix){
	for(long i=0;i<rows;i++){
		for(long j=0;j<columns;j++){
			output[i*columns+j] = N*matrix[i*columns+j];
		}
	}
}
