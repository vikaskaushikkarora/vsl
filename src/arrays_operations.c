#include"private_arrays.h"

// ===================================================================================
// Scaling Arrays
// ===================================================================================

// Scale an integer array by a number
long* ar_Scale(long num, long Narr, long* arr){
	long* newArr = ar_Alloc(Narr);
	for(long i=0;i<Narr;i++){
		newArr[i] = num*arr[i];
	}
	return newArr;
}

// Scale an integer array by a number return no array
void ar_ScaleVoid(long* output, long num, long Narr, long* arr){
	for(long i=0;i<Narr;i++){
		output[i] = num*arr[i];
	}
}

// Scale a double array by a number
double* ar_scale(double num, long Narr, double* arr){
	double* newArr = ar_alloc(Narr);
	for(long i=0;i<Narr;i++){
		newArr[i] = num*arr[i];
	}
	return newArr;
}

// Scale a double array by a number return no array 
void ar_scaleVoid(double* output, double num, long Narr, double* arr){
    for(long i=0;i<Narr;i++){
		output[i] = num*arr[i];
	}
}

// Scale a long array by a double number
double* ar_scaleLong(double num, long Narr, long* arr){
	double* newArr = ar_alloc(Narr);
	for(long i=0;i<Narr;i++){
		newArr[i] = num*arr[i];
	}
	return newArr;
}

// ==================================================================================
// Summing the elements of an array
// ==================================================================================

// Partial sum an array of long ints 
long ar_SumPartial(long Narr, long* arr, long initial, long final){
    (void)Narr;
	long sum=0;
	for(long i=initial;i<final;i++){
		sum += arr[i];
	}
	return sum;
}

// Partial sum an array of doubles 
double ar_sumPartial(long Narr, double* arr, long initial, long final){
    (void)Narr;
	double sum=0;
	for(long i=initial;i<final;i++){
		sum += arr[i];
	}
	return sum;
}

// Full sum an array of long ints
long ar_Sum(long Narr, long* arr){
	long sum=0;
	for(long i=0;i<Narr;i++){
		sum += arr[i];
	}
	return sum;
}

// Full sum an array of doubles 
double ar_sum(long Narr, double* arr){
	double sum=0;
	for(long i=0;i<Narr;i++){
		sum += arr[i];
	}
	return sum;
}

double ar_Average(long Narr, long* arr){
    double average = ar_Sum(Narr,arr);
    average /= Narr;
    return average;
}

double ar_average(long Narr, double* arr){
    double average = ar_sum(Narr,arr);
    average /= Narr;
    return average;
}

// ==================================================================================
// Array operations for two arrays
// ==================================================================================

// Add two long arrays
long* ar_Add(long Narr, long* arr1, long* arr2){
	long* newArr = ar_Alloc(Narr);
	for(long i=0;i<Narr;i++){
		newArr[i] = arr1[i]+arr2[i];
	}
	return newArr;
}

// Add two double arrays
double* ar_add(long Narr, double* arr1, double* arr2){
	double* newArr = ar_alloc(Narr);
	for(long i=0;i<Narr;i++){
		newArr[i] = arr1[i]+arr2[i];
	}
	return newArr;
}

// Add two long arrays returning void
void ar_AddVoid(long* output, long Narr, long* arr1, long* arr2){
	for(long i=0;i<Narr;i++){
		output[i] = arr1[i]+arr2[i];
	}
}

// Add two double arrays returning void
void ar_addVoid(double* output, long Narr, double* arr1, double* arr2){
	for(long i=0;i<Narr;i++){
		output[i] = arr1[i]+arr2[i];
	}
}

// Subtract long arrays
long* ar_Sub(long Narr, long* arr1, long* arr2){
	long* newArr = ar_Alloc(Narr);
	for(long i=0;i<Narr;i++){
		newArr[i] = arr1[i]-arr2[i];
	}
	return newArr;
}

// Subtract double arrays
double* ar_sub(long Narr, double* arr1, double* arr2){
	double* newArr = ar_alloc(Narr);
	for(long i=0;i<Narr;i++){
		newArr[i] = arr1[i]-arr2[i];
	}
	return newArr;
}

// Subtract long arrays returning no pointer
void ar_SubVoid(long* output, long Narr, long* arr1, long* arr2){
	for(long i=0;i<Narr;i++){
		output[i] = arr1[i]-arr2[i];
	}
}

// Subtract double arrays returning no pointer
void ar_subVoid(double* output, long Narr, double* arr1, double* arr2){
	for(long i=0;i<Narr;i++){
		output[i] = arr1[i]-arr2[i];
	}
}

// Add two long arrays
long* ar_Mul(long Narr, long* arr1, long* arr2){
	long* newArr = ar_Alloc(Narr);
	for(long i=0;i<Narr;i++){
		newArr[i] = arr1[i]*arr2[i];
	}
	return newArr;
}

// Add two double arrays
double* ar_mul(long Narr, double* arr1, double* arr2){
	double* newArr = ar_alloc(Narr);
	for(long i=0;i<Narr;i++){
		newArr[i] = arr1[i]*arr2[i];
	}
	return newArr;
}

// Add two long arrays returning void
void ar_MulVoid(long* output, long Narr, long* arr1, long* arr2){
	for(long i=0;i<Narr;i++){
		output[i] = arr1[i]*arr2[i];
	}
}

// Add two double arrays returning void
void ar_mulVoid(double* output, long Narr, double* arr1, double* arr2){
	for(long i=0;i<Narr;i++){
		output[i] = arr1[i]*arr2[i];
	}
}

// Divide integer arrays
double* ar_Div(long Narr, long* arr1, long* arr2){
	double* newArr = ar_alloc(Narr);
	for(long i=0;i<Narr;i++){
		newArr[i] = arr1[i]/arr2[i];
	}
	return newArr;
}

// Divide double arrays
double* ar_div(long Narr, double* arr1, double* arr2){
	double* newArr = ar_alloc(Narr);
	for(long i=0;i<Narr;i++){
		newArr[i] = arr1[i]/arr2[i];
	}
	return newArr;
}

// Divide two double arrays returning no pointer
void ar_DivVoid(double* output, long Narr, long* arr1, long* arr2){
	for(long i=0;i<Narr;i++){
		output[i] = arr1[i]/arr2[i];
	}
}

// Divide two double arrays returning no pointer
void ar_divVoid(double* output, long Narr, double* arr1, double* arr2){
	for(long i=0;i<Narr;i++){
		output[i] = arr1[i]/arr2[i];
	}
}

// ==================================================================================
// Array operations for N arrays
// ==================================================================================

// Addition of N long arrays
long* ar_AddXN(long Narr, long N, ...){
	long* Sum = ar_Calloc(Narr);
	va_list inputs;
	va_start(inputs,N);
	for(long j=0;j<N;j++){
		long* x = va_arg(inputs, long*);
	        for(long k=0;k<Narr;k++){
	        	Sum[k] += x[k];
	        }
	}
    return Sum;
}

// Addition of N double arrays
double* ar_addXN(long Narr, long N, ...){
	double* sum = ar_calloc(Narr);
	va_list inputs;
	va_start(inputs,N);
	for(long j=0;j<N;j++){
		double* x = va_arg(inputs, double*);
	        for(long k=0;k<Narr;k++){
	        	sum[k] += x[k];
	        }
	}
    return sum;
}

// Multiplication of N long arrays
long* ar_MulXN(long Narr, long N, ...){
	long* Result = ar_Ones(Narr);
	va_list inputs;
	va_start(inputs,N);
	for(long j=0;j<N;j++){
		long* x = va_arg(inputs, long*);
	        for(long k=0;k<Narr;k++){
	        	Result[k] *= x[k];
	        }
	}
    return Result;
}

// multiplication of n double arrays
double* ar_mulXN(long Narr, long N, ...){
	double* result = ar_ones(Narr);
	va_list inputs;
	va_start(inputs,N);
	for(long j=0;j<N;j++){
		double* x = va_arg(inputs, double*);
	        for(long k=0;k<Narr;k++){
	        	result[k] *= x[k];
	        }
	}
    return result;
}

// Addition of N long arrays returning void
void ar_AddXVoidN(long* output, long Narr, long N, ...){
	long* Result = ar_Zeros(Narr);	
	va_list inputs;
	va_start(inputs,N);
	for(long j=0;j<N;j++){
		long* x = va_arg(inputs, long*);
	        for(long k=0;k<Narr;k++){
	        	Result[k] += x[k];
	        }
	}
	memcpy(output,Result,Narr*sizeof(long));
	free(Result);
}

// Addition of N double arrays returning void
void ar_addXVoidN(double* output, long Narr, long N, ...){
	double* result = ar_zeros(Narr);
	va_list inputs;
	va_start(inputs,N);
	for(long j=0;j<N;j++){
		double* x = va_arg(inputs, double*);
	        for(long k=0;k<Narr;k++){
	        	result[k] += x[k];
	        }
	}
	memcpy(output,result,Narr*sizeof(double));
	free(result);
}

// Multiplication of N long arrays returning void
void ar_MulXVoidN(long* output, long Narr, long N, ...){
	long* Result = ar_Ones(Narr);	
	va_list inputs;
	va_start(inputs,N);
	for(long j=0;j<N;j++){
		long* x = va_arg(inputs, long*);
	        for(long k=0;k<Narr;k++){
	        	Result[k] *= x[k];
	        }
	}
	memcpy(output,Result,Narr*sizeof(long));
	free(Result);
}

// multiplication of n double arrays
void ar_mulXVoidN(double* output, long Narr, long N, ...){
	double* result = ar_ones(Narr);
	va_list inputs;
	va_start(inputs,N);
	for(long j=0;j<N;j++){
		double* x = va_arg(inputs, double*);
	        for(long k=0;k<Narr;k++){
	        	result[k] *= x[k];
	        }
	}
	memcpy(output,result,Narr*sizeof(double));
	free(result);
}

