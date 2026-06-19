#ifndef STATISTICS_H
#define STATISTICS_H

#include"essential_headers.h"
#include"arrays.h"

//statistics.c ===========================================================
double* st_hist(long sizeInput, double *input, long sizeBin, double *bin);
void st_histVoid(double* output, long sizeInput, double *input, long sizeBin, double *bin);
double* st_histCentered(long sizeInput, double *input, long sizeBin, double *bin);
void st_histCenteredVoid(double* output, long sizeInput, double *input, long sizeBin, double *bin);

double* st_hist2d(long sizeInput, double *xInput, double *yInput, long sizeXBin, double *xBin, long sizeYBin, double *yBin);
void st_hist2dVoid(double* output, long sizeInput, double *xInput, double *yInput, long sizeXBin, double *xBin, long sizeYBin, double *yBin);
double* st_hist3d(long sizeInput, double *xInput, double *yInput, double *zInput, long sizeXBin, double *xBin, long sizeYBin, double *yBin, long sizeZBin, double *zBin);
void st_hist3dVoid(double* output, long sizeInput, double *xInput, double *yInput, double *zInput, long sizeXBin, double *xBin, long sizeYBin, double *yBin, long sizeZBin, double *zBin);

double* st_linearRegression(long N, double* x, double* y);
void st_linearRegressionVoid(double* output, long N, double* x, double* y);

double* st_stat(long Narr, double* arr);
void st_statVoid(double* output, long Narr, double* arr);

double* st_statDisbn(long N, double* x, double* disbnX);
void st_statDisbnVoid(double* output, long N, double* x, double* disbnX);
double* st_statDisbnQ(long N, double* x, double* disbnX);
void st_statDisbnQvoid(double* output, long N, double* x, double* disbnX);

double* st_rawMoments(long order, long Narr, double* arr);
void st_rawMomentsVoid(double* moments, long order, long Narr, double* arr);

double* st_rawMomentsDisbn(long order, long N, double* x, double* Ix);
void st_rawMomentsDisbnVoid(double* output, long order, long N, double* x, double* Ix);
double* st_rawMomentsDisbnQ(long order, long N, double* x, double* Ix);
void st_rawMomentsDisbnQvoid(double* output, long order, long N, double* x, double* Ix);

double* st_centralMomentsFromRawMoments(long order, double* rawMoments);
double * st_rawMomentsFromCentralMoments(long order, double* centralMoments, double mean);
void st_centralMomentsFromRawMomentsVoid(double* output, long order, double* rawMoments);
void st_rawMomentsFromCentralMomentsVoid(double* output, long order, double* centralMoments, double mean);

double* st_autoCorr(long order, long Narr, double* arr);
void st_autoCorrVoid(double* autoCorr, long order, long Narr, double* arr);

#endif
