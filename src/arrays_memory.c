#include"private_arrays.h"

// =============================================================================================
// Memory allocations 
// =============================================================================================

// Malloc memory for an array with long ints (Safer)
long* ar_Alloc(long Narr){
	long* arr = malloc(Narr * sizeof(long));
	if(arr == NULL){
		fprintf(stderr, "ar_Alloc: Error! Memory allocation failed for long int array of size %ld\n", Narr);
		return NULL;
	}
	return arr;
}

// Calloc memory for long ints
long* ar_Calloc(long Narr){
	long* arr = calloc(Narr, sizeof(long));
	if(arr == NULL){
		fprintf(stderr, "ar_Calloc: Error! Memory allocation failed for long int array of size %ld\n", Narr);
		return NULL;
	}
	return arr;
}

// Malloc memory for an array with doubles (safer)
double* ar_alloc(long Narr){
	double* arr = malloc(Narr * sizeof(double));
	if(arr == NULL){
		fprintf(stderr, "ar_alloc: Error! Memory allocation failed for double array of size %ld\n", Narr);
		return NULL;
	}
	return arr;
}

// Calloc memory for an array with doubles
double* ar_calloc(long Narr){
	double* arr = calloc(Narr, sizeof(double));
	if(arr == NULL){
		fprintf(stderr, "ar_calloc: Error! Memory allocation failed for double array of size %ld\n", Narr);
		return NULL;
	}
	return arr;
}


// =============================================================================================
// Memory re-allocations 
// =============================================================================================

// Reallocating memory to previous allocated int array
long* ar_Realloc(long Narr, long** arr){
	long* new_arr = realloc(*arr, Narr * sizeof(long));
	if(new_arr == NULL){
		fprintf(stderr, "ar_Relloc: Error! Memory reallocation failed\n");
        	// Original pointer still valid
        	return NULL;
        }else{
        	*arr = NULL;
        }
        return new_arr;
}

// Reallocating memory to previous allocated double array
double* ar_realloc(long Narr, double** arr){
	double* new_arr = realloc(*arr, Narr * sizeof(double));
	if(new_arr == NULL){
		fprintf(stderr, "ar_realloc: Error! Memory reallocation failed\n");
        	// Original pointer still valid
        	return NULL;
        }
        else{
        	*arr = NULL;
        }
        return new_arr;
}

// =============================================================================================
// Memory Freeing
// =============================================================================================

// Please give a pointer to arrays you want to free in pt_Free() and pt_free() functions 
// Free N pointers to long int pointers/arrays
void ar_FreeN(long N, ...){
	va_list inputs;
	va_start(inputs,N);
	for(long j = 0; j < N; j++){
		long** x = va_arg(inputs, long**);
		if( x== NULL || *x == NULL ){
			fprintf(stderr,"ar_Free: Error! Either the input pointer is NULL or the pointer it points to is NULL.\n");
		}else{
			free(*x);
			*x = NULL;
		}
	}
	va_end(inputs);
}

// Free N pointers to double pointers/arrays
void ar_freeN(long N, ...){
	va_list inputs;
	va_start(inputs,N);
	for(long j = 0; j < N; j++){
		double** x = va_arg(inputs, double**);
		if( x == NULL || *x == NULL ){
			fprintf(stderr,"ar_free: Error! Either the input pointer is NULL or the pointer it points to is NULL.\n");
		}else{
			free(*x);
			*x = NULL;
		}
	}
	va_end(inputs);
}
