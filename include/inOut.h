#ifndef INOUT_H
#define INOUT_H

#include"essential_headers.h"

// ========================================================================
// inOut_print.c
// ========================================================================
void io_PrintN(long N, ...);
#define io_Print(...) io_PrintN(sizeof((long[]){__VA_ARGS__})/sizeof(long), __VA_ARGS__)
void io_PrintQN(char* string, long N, ...);
#define io_PrintQ(string, ...) io_PrintQN(string, sizeof((long[]){__VA_ARGS__})/sizeof(long), __VA_ARGS__)

void io_printN(long N, ...);
#define io_print(...) io_printN(sizeof((double[]){__VA_ARGS__})/sizeof(double), __VA_ARGS__)
void io_printQN(char* string, long N, ...);
#define io_printQ(string, ...) io_printQN(string, sizeof((double[]){__VA_ARGS__})/sizeof(double), __VA_ARGS__)

void io_PrintArrN(long Narr, long N, ...);
#define io_PrintArr(Narr, ...) io_PrintArrN(Narr, sizeof((long*[]){__VA_ARGS__})/sizeof(long*), __VA_ARGS__)
void io_PrintArrQN(char* string, long Narr, long N, ...);
#define io_PrintArrQ(string, Narr, ...) io_PrintArrQN(string, Narr, sizeof((long*[]){__VA_ARGS__})/sizeof(long*), __VA_ARGS__)

void io_printArrN(long Narr, long N, ...);
#define io_printArr(Narr, ...) io_printArrN(Narr, sizeof((double*[]){__VA_ARGS__})/sizeof(double*), __VA_ARGS__)
void io_printArrQN(char* string, long Narr, long N, ...);
#define io_printArrQ(string, Narr, ...) io_printArrQN(string, Narr, sizeof((double*[]){__VA_ARGS__})/sizeof(double*), __VA_ARGS__)

void io_printStr(char* s);
void io_PrintMtrx(long rows, long columns, long* matrix);
void io_printMtrx(long rows, long columns, double* matrix);


// ========================================================================
// inOut_read.c
// ========================================================================
long io_getNumRows(char* filename);
long io_getNumColumns(char* filename);
long* io_ReadMtrx(char* filename, long* rows, long* columns);
double* io_readMtrx(char* filename, long* rows, long* columns);
long* io_ReadMtrxBin(char* filename, long* rows, long* columns);
double* io_readMtrxBin(char* filename, long* rows, long* columns);
long* io_ReadMtrx3d(char* filename, long* rows, long* columns, long* heights);
double* io_readMtrx3d(char* filename, long* rows, long* columns, long* heights);


// ========================================================================
// inOut_write.c
// ========================================================================
void io_WriteArrN(char* filename, long Narr, long N, ...);
#define io_WriteArr(filename, Narr, ...) io_WriteArrN(filename, Narr, sizeof((long*[]){__VA_ARGS__})/sizeof(long*), __VA_ARGS__)
void io_writeArrN(char* filename, long Narr, long N, ...);
#define io_writeArr(filename, Narr, ...) io_writeArrN(filename, Narr, sizeof((double*[]){__VA_ARGS__})/sizeof(double*), __VA_ARGS__)

void io_WriteArrQN(char* filename, long Narr, long N, ...);
#define io_WriteArrQ(filename, Narr, ...) io_WriteArrQN(filename, Narr, sizeof((long*[]){__VA_ARGS__})/sizeof(long*), __VA_ARGS__)
void io_writeArrQN(char* filename, long Narr, long N, ...);
#define io_writeArrQ(filename, Narr, ...) io_writeArrQN(filename, Narr, sizeof((double*[]){__VA_ARGS__})/sizeof(double*), __VA_ARGS__)

void io_WriteMtrx(char* filename, long rows, long columns, long* matrix);
void io_writeMtrx(char* filename, long rows, long columns, double* matrix);
void io_WriteMtrx3d(char* filename, long rows, long columns, long heights, long* matrix);
void io_writeMtrx3d(char* filename, long rows, long columns, long heights, double* matrix);

void io_WriteArrBinN(char* filename, long Narr, long N, ...);
#define io_WriteArrBin(filename, Narr, ...) io_WriteArrBinN(filename, Narr, sizeof((long*[]){__VA_ARGS__})/sizeof(long*), __VA_ARGS__)
void io_writeArrBinN(char* filename, long Narr, long N, ...);
#define io_writeArrBin(filename, Narr, ...) io_writeArrBinN(filename, Narr, sizeof((double*[]){__VA_ARGS__})/sizeof(double*), __VA_ARGS__)

void io_WriteMtrxBin(char* filename, long rows, long columns, long* matrix);
void io_writeMtrxBin(char* filename, long rows, long columns, double* matrix);


// ========================================================================
// inOut_anomalous.c
// ========================================================================
void io_fcloseN(long N, ...);
#define io_fclose(...) io_fcloseN(sizeof((FILE**[]){__VA_ARGS__})/sizeof(FILE**), __VA_ARGS__)


#endif
