#ifndef ARRAYS_H
#define ARRAYS_H

#include"essential_headers.h"


// ==============================================================================
// arrays_memory.c
// ==============================================================================
long* ar_Alloc(long Narr);
long* ar_Calloc(long Narr);
double* ar_alloc(long Narr);
double* ar_calloc(long Narr);

long* ar_Realloc(long Narr, long** arr);
double* ar_realloc(long Narr, double** arr);

void ar_FreeN(long N, ...);
void ar_freeN(long N, ...);
// ar_Free(&arrayPointer1,&arrayPointer2,...) (For long int arrays)
#define ar_Free(...) ar_FreeN(sizeof((long**[]){__VA_ARGS__})/sizeof(long**), __VA_ARGS__)
// ar_free(&arrayPointer1,&arrayPointer2,...) (For long double arrays)
#define ar_free(...) ar_freeN(sizeof((double**[]){__VA_ARGS__})/sizeof(double**), __VA_ARGS__)


// =============================================================================
// arrays_anomalous.c
// =============================================================================
double ar_integrate(long Nx, double* x, double* Ix);
double ar_integrateQ(long Nx, double* x, double* Ix);
void ar_normalize(long Nx, double* x, double* Ix);
void ar_normalizeQ(long Nx, double* x, double* Ix);

long* ar_Copy(long Narr, long* arr);
double* ar_copy(long Narr, double* arr);
void ar_CopyVoid(long* output, long Narr, long* arr);
void ar_copyVoid(double* output, long Narr, double* arr);

long* ar_Func(long (*func)(long), long Narr, long* arr);
double* ar_func(double (*func)(double), long Narr, double* arr);
void ar_FuncVoid(long* output, long (*func)(long), long Narr, long* arr);
void ar_funcVoid(double* output, double (*func)(double), long Narr, double* arr);

long* ar_Func2(long (*func)(long,long), long Narr, long* arr1, long* arr2);
double* ar_func2(double (*func)(double,double), long Narr, double* arr1, double* arr2);
void ar_Func2Void(long* output, long (*func)(long,long), long Narr, long* arr1, long* arr2);
void ar_func2Void(double* output, double (*func)(double,double), long Narr, double* arr1, double* arr2);

long* ar_Func3(long (*func)(long,long,long), long Narr, long* arr1, long* arr2, long* arr3);
double* ar_func3(double (*func)(double,double,double), long Narr, double* arr1, double* arr2, double* arr3);
void ar_Func3Void(long* output, long (*func)(long,long,long), long Narr, long* arr1, long* arr2, long* arr3);
void ar_func3Void(double* output, double (*func)(double,double,double), long Narr, double* arr1, double* arr2, double* arr3);

double* ar_gauss(long Nx, double* x, double mean, double std);
void ar_gaussVoid(double* output, long Nx, double* x, double mean, double std);


// =============================================================================
// arrays_operations.c
// =============================================================================
long* ar_Scale(long num, long Narr, long* arr);
void ar_ScaleVoid(long* output, long num, long Narr, long* arr);
double* ar_scale(double num, long Narr, double* arr);
void ar_scaleVoid(double* output, double num, long Narr, double* arr);
double* ar_scaleLong(double num, long Narr, long* arr);

long ar_SumPartial(long Narr, long* arr, long initial, long final);
double ar_sumPartial(long Narr, double* arr, long initial, long final);
long ar_Sum(long Narr, long* arr);
double ar_sum(long Narr, double* arr);
double ar_Average(long Narr, long* arr);
double ar_average(long Narr, double* arr);

long* ar_Add(long Narr, long* arr1, long* arr2);
double* ar_add(long Narr, double* arr1, double* arr2);
void ar_AddVoid(long* output, long Narr, long* arr1, long* arr2);
void ar_addVoid(double* output, long Narr, double* arr1, double* arr2);
long* ar_Sub(long Narr, long* arr1, long* arr2);
double* ar_sub(long Narr, double* arr1, double* arr2);
void ar_SubVoid(long* output, long Narr, long* arr1, long* arr2);
void ar_subVoid(double* output, long Narr, double* arr1, double* arr2);
long* ar_Mul(long Narr, long* arr1, long* arr2);
double* ar_mul(long Narr, double* arr1, double* arr2);
void ar_MulVoid(long* output, long Narr, long* arr1, long* arr2);
void ar_mulVoid(double* output, long Narr, double* arr1, double* arr2);
double* ar_Div(long Narr, long* arr1, long* arr2);
double* ar_div(long Narr, double* arr1, double* arr2);
void ar_DivVoid(double* output, long Narr, long* arr1, long* arr2);
void ar_divVoid(double* output, long Narr, double* arr1, double* arr2);

long* ar_AddXN(long Narr, long N, ...);
#define ar_AddX(Narr, ...) ar_AddXN(Narr, sizeof((long*[]){__VA_ARGS__})/sizeof(long*), __VA_ARGS__)
double* ar_addXN(long Narr ,long N, ...);
#define ar_addX(Narr, ...) ar_addXN(Narr, sizeof((double*[]){__VA_ARGS__})/sizeof(double*), __VA_ARGS__)
long* ar_MulXN(long Narr,long N, ...);
#define ar_MulX(Narr, ...) ar_MulXN(Narr, sizeof((long*[]){__VA_ARGS__})/sizeof(long*), __VA_ARGS__)
double* ar_mulXN(long Narr, long N, ...);
#define ar_mulX(Narr, ...) ar_mulXN(Narr, sizeof((double*[]){__VA_ARGS__})/sizeof(double*), __VA_ARGS__)

void ar_AddXVoidN(long* output, long Narr, long N, ...);
void ar_addXVoidN(double* output, long Narr, long N, ...);
void ar_MulXVoidN(long* output, long Narr, long N, ...);
void ar_mulXVoidN(double* output, long Narr, long N, ...);
#define ar_AddXVoid(output, Narr, ...) ar_AddXVoidN(output, Narr, sizeof((long*[]){__VA_ARGS__})/sizeof(long*), __VA_ARGS__)
#define ar_addXVoid(output, Narr, ...) ar_addXVoidN(output, Narr, sizeof((double*[]){__VA_ARGS__})/sizeof(double*), __VA_ARGS__)
#define ar_MulXVoid(output, Narr, ...) ar_MulXVoidN(output, Narr, sizeof((long*[]){__VA_ARGS__})/sizeof(long*), __VA_ARGS__)
#define ar_mulXVoid(output, Narr, ...) ar_mulXVoidN(output, Narr, sizeof((double*[]){__VA_ARGS__})/sizeof(double*), __VA_ARGS__)


// ============================================================================
// arrays_pythonLike.c
// ============================================================================
double* ar_arange(long Narr, double initial, double stepSize);
long* ar_Arange(long Narr, long initial, long stepSize);
void ar_arangeVoid(double* arr, long Narr, double initial, double stepSize);
void ar_ArangeVoid(long* arr, long Narr, long initial, long stepSize);
double* ar_linspace(long Narr, double initial, double final);
void ar_linspaceVoid(double* arr, long Narr, double initial, double final);
long* ar_Zeros(long Narr);
double* ar_zeros(long Narr);
void ar_ZerosVoid(long* arr, long Narr);
void ar_zerosVoid(double* arr, long Narr);
long* ar_Ones(long Narr);
double* ar_ones(long Narr);
void ar_OnesVoid(long* arr, long Narr);
void ar_onesVoid(double* arr, long Narr);
long* ar_Nums(long num, long Narr);
double* ar_nums(double num, long Narr);
void ar_NumsVoid(long* arr, long num, long Narr);
void ar_numsVoid(double* arr, double num, long Narr);

#endif

