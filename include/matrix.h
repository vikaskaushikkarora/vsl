#ifndef MATRIX_H
#define MATRIX_H

#include"essential_headers.h"

// =============================================================
// matrix_operations.c
// ============================================================= 

long mx_GetElement(long numRow, long numColumn, long rows, long columns, long* matrix);
void mx_ChangeElement(long input, long numRow, long numColumn, long rows, long columns, long* matrix);
double mx_getElement(long numRow, long numColumn, long rows, long columns, double* matrix);
void mx_changeElement(double input, long numRow, long numColumn, long rows, long columns, double* matrix);

long* mx_GetRow(long rowNumber, long rows, long columns, long* matrix);
double* mx_getRow(long rowNumber, long rows, long columns, double* matrix);
long* mx_GetColumn(long columnNumber, long rows, long columns, long* matrix);
double* mx_getColumn(long columnNumber, long rows, long columns, double* matrix);

void mx_GetRowVoid(long* output, long rowNumber, long rows, long columns, long* matrix);
void mx_getRowVoid(double* output, long rowNumber, long rows, long columns, double* matrix);
void mx_GetColumnVoid(long* output, long columnNumber, long rows, long columns, long* matrix);
void mx_getColumnVoid(double* output,long columnNumber, long rows, long columns, double* matrix);

long* mx_Scale(long N, long rows, long columns, long* matrix);
double* mx_scale(long N, long rows, long columns, double* matrix);
void mx_ScaleVoid(long* output, long N, long rows, long columns, long* matrix);
void mx_scaleVoid(double* output, long N, long rows, long columns, double* matrix);

// =============================================================
// matrix_pythonLike.c
// =============================================================

long* mx_Zeros(long rows, long columns);
double* mx_zeros(long rows, long columns);
long* mx_Ones(long rows, long columns);
double* mx_ones(long rows, long columns);

void mx_ZerosVoid(long* mx, long rows, long columns);
void mx_zerosVoid(double* mx, long rows, long columns);
void mx_OnesVoid(long* mx, long rows, long columns);
void mx_onesVoid(double* mx,long rows, long columns);


#endif
