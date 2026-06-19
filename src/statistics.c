#include"private_statistics.h"

// A function for plotting histograms
double* st_hist(long sizeInput, double *input, long sizeBin, double *bin){
	double* output = ar_calloc(sizeBin);
	
	long net = 0, count = 0;
	double h = bin[1] - bin[0];
	double hInv = 1.0 / h;
	double binStart = bin[0];
	double epsilon = 0.01*h;
	
	// Bin the data
	for(long j = 0; j < sizeInput; j++){
		long temp = (long) ((input[j]-binStart+epsilon)*hInv);
		if(temp >= 0 && temp < sizeBin){
			net++;
			output[temp] += 1.0;
		} else {
			count++;
			// printf("out of range data : %lf\n", input[j]);
		}
	}
	
	// Print warning if data out of range
	if(count > 0){
		fprintf(stderr, "st_hist Warning: %ld entries out of range\n", count);
	}
	
	// Normalize the histogram
	if(net > 0){
		double normFactor = 1.0 / (net * h);
		for(long i = 0; i < sizeBin; i++){
			output[i] *= normFactor;
		}
	}
	
	return output;
}

// A function for plotting histograms returning void
void st_histVoid(double* output, long sizeInput, double *input, long sizeBin, double *bin){
	long net = 0, count = 0;
	double h = bin[1] - bin[0];
	double hInv = 1.0 / h;
	double binStart = bin[0];
	double epsilon = 0.01*h;
	
	// Bin the data
	for(long j = 0; j < sizeInput; j++){
		long temp = (long) ((input[j]-binStart+epsilon)*hInv);
		if(temp >= 0 && temp < sizeBin){
			net++;
			output[temp] += 1.0;
		} else {
			count++;
			// printf("out of range data : %lf\n", input[j]);
		}
	}
	
	// Print warning if data out of range
	if(count > 0){
		fprintf(stderr, "st_hist Warning: %ld entries out of range\n", count);
	}
	
	// Normalize the histogram
	if(net > 0){
		double normFactor = 1.0 / (net * h);
		for(long i = 0; i < sizeBin; i++){
			output[i] *= normFactor;
		}
	}
}

double* st_histCentered(long sizeInput, double *input, long sizeBin, double *bin){
	double* output = ar_calloc(sizeBin);
	
	long net = 0, count = 0;
	double h = bin[1] - bin[0];
	double hInv = 1.0 / h;
	double binStart = bin[0];
	double epsilon = 0.01 * h;
	
	// Bin the data (shift by half bin width so bin[i] is the center)
	for(long j = 0; j < sizeInput; j++){
		long temp = (long) ((input[j] - binStart + 0.5*h + epsilon) * hInv);
		if(temp >= 0 && temp < sizeBin){
			net++;
			output[temp] += 1.0;
		} else {
			count++;
		}
	}
	
	// Print warning if data out of range
	if(count > 0){
		fprintf(stderr, "st_hist_centered Warning: %ld entries out of range\n", count);
	}
	
	// Normalize the histogram
	if(net > 0){
		double normFactor = 1.0 / (net * h);
		for(long i = 0; i < sizeBin; i++){
			output[i] *= normFactor;
		}
	}
	
	return output;
}

void st_histCenteredVoid(double* output, long sizeInput, double *input, long sizeBin, double *bin){
	long net = 0, count = 0;
	double h = bin[1] - bin[0];
	double hInv = 1.0 / h;
	double binStart = bin[0];
	double epsilon = 0.01 * h;
	
	// Bin the data (shift by half bin width so bin[i] is the center)
	for(long j = 0; j < sizeInput; j++){
		long temp = (long) ((input[j] - binStart + 0.5*h + epsilon) * hInv);
		if(temp >= 0 && temp < sizeBin){
			net++;
			output[temp] += 1.0;
		} else {
			count++;
		}
	}
	
	// Print warning if data out of range
	if(count > 0){
		fprintf(stderr, "st_hist_centered Warning: %ld entries out of range\n", count);
	}
	
	// Normalize the histogram
	if(net > 0){
		double normFactor = 1.0 / (net * h);
		for(long i = 0; i < sizeBin; i++){
			output[i] *= normFactor;
		}
	}
}

// A function for plotting 2D histograms
double* st_hist2d(long sizeInput, double *xInput, double *yInput, long sizeXBin, double *xBin, long sizeYBin, double *yBin){
	double *output = ar_calloc(sizeXBin * sizeYBin);

	double hx = xBin[1] - xBin[0];
	double hy = yBin[1] - yBin[0];
	double hxInv = 1.0 / hx;
	double hyInv = 1.0 / hy;

	double xStart = xBin[0];
	double yStart = yBin[0];

	double epsilonX = 0.01 * hx;
	double epsilonY = 0.01 * hy;

	long net = 0, count = 0;

	for(long k=0;k<sizeInput;k++){
		long ix = (long)((xInput[k] - xStart + epsilonX) * hxInv);
		long iy = (long)((yInput[k] - yStart + epsilonY) * hyInv);

		if (ix >= 0 && ix < sizeXBin && iy >= 0 && iy < sizeYBin) {
			output[ix * sizeYBin + iy] += 1.0;   /* row-major: x is the row */
			net++;
		} else {
			count++;
		}
	}

	if (count > 0) {
		fprintf(stderr,"st_hist2d Warning: %ld entries out of range\n", count);
	}

	if (net > 0) {
		double normFactor = 1.0 / ((double)net * hx * hy);
		long total = sizeXBin * sizeYBin;
		for (long i = 0; i < total; i++) {
			output[i] *= normFactor;
		}
	}

	return output;
}

// A function for plotting 2D histograms returning void
void st_hist2dVoid(double* output, long sizeInput, double *xInput, double *yInput, long sizeXBin, double *xBin, long sizeYBin, double *yBin){
	double hx = xBin[1] - xBin[0];
	double hy = yBin[1] - yBin[0];
	double hxInv = 1.0 / hx;
	double hyInv = 1.0 / hy;

	double xStart = xBin[0];
	double yStart = yBin[0];

	double epsilonX = 0.01 * hx;
	double epsilonY = 0.01 * hy;

	long net = 0, count = 0;

	for(long k=0;k<sizeInput;k++){
		long ix = (long)((xInput[k] - xStart + epsilonX) * hxInv);
		long iy = (long)((yInput[k] - yStart + epsilonY) * hyInv);

		if (ix >= 0 && ix < sizeXBin && iy >= 0 && iy < sizeYBin) {
			output[ix * sizeYBin + iy] += 1.0;   /* row-major: x is the row */
			net++;
		} else {
			count++;
		}
	}

	if (count > 0) {
		fprintf(stderr,"st_hist2d Warning: %ld entries out of range\n", count);
	}

	if (net > 0) {
		double normFactor = 1.0 / ((double)net * hx * hy);
		long total = sizeXBin * sizeYBin;
		for (long i = 0; i < total; i++) {
			output[i] *= normFactor;
		}
	}
}

// A function for plotting 3D histograms
double* st_hist3d(long sizeInput, double *xInput, double *yInput, double *zInput, long sizeXBin, double *xBin, long sizeYBin, double *yBin, long sizeZBin, double *zBin){
	double *output = ar_calloc(sizeXBin * sizeYBin * sizeZBin);

	double hx = xBin[1] - xBin[0];
	double hy = yBin[1] - yBin[0];
	double hz = zBin[1] - zBin[0];
	double hxInv = 1.0 / hx;
	double hyInv = 1.0 / hy;
	double hzInv = 1.0 / hz;

	double xStart = xBin[0];
	double yStart = yBin[0];
	double zStart = zBin[0];

	double epsilonX = 0.01 * hx;
	double epsilonY = 0.01 * hy;
	double epsilonZ = 0.01 * hz;

	long net = 0, count = 0;

	for(long k=0;k<sizeInput;k++){
		long ix = (long)((xInput[k] - xStart + epsilonX) * hxInv);
		long iy = (long)((yInput[k] - yStart + epsilonY) * hyInv);
		long iz = (long)((zInput[k] - zStart + epsilonZ) * hzInv);

		if (ix >= 0 && ix < sizeXBin && iy >= 0 && iy < sizeYBin && iz >= 0 && iz < sizeZBin) {
			output[iz*(sizeXBin*sizeYBin)+ix*sizeYBin+iy] += 1.0;   /* row-major: x is the row */
			net++;
		} else {
			count++;
		}
	}

	if (count > 0) {
		fprintf(stderr,"st_hist3d Warning: %ld entries out of range\n", count);
	}

	if (net > 0) {
		double normFactor = 1.0/((double)net*hx*hy*hz);
		long total = sizeXBin*sizeYBin*sizeZBin;
		for(long i=0;i<total;i++){
			output[i] *= normFactor;
		}
	}

	return output;
}

// A function for plotting 3D histograms returns void
void st_hist3dVoid(double* output, long sizeInput, double *xInput, double *yInput, double *zInput, long sizeXBin, double *xBin, long sizeYBin, double *yBin, long sizeZBin, double *zBin){
	double hx = xBin[1] - xBin[0];
	double hy = yBin[1] - yBin[0];
	double hz = zBin[1] - zBin[0];
	double hxInv = 1.0 / hx;
	double hyInv = 1.0 / hy;
	double hzInv = 1.0 / hz;

	double xStart = xBin[0];
	double yStart = yBin[0];
	double zStart = zBin[0];

	double epsilonX = 0.01 * hx;
	double epsilonY = 0.01 * hy;
	double epsilonZ = 0.01 * hz;

	long net = 0, count = 0;

	for(long k=0;k<sizeInput;k++){
		long ix = (long)((xInput[k] - xStart + epsilonX) * hxInv);
		long iy = (long)((yInput[k] - yStart + epsilonY) * hyInv);
		long iz = (long)((zInput[k] - zStart + epsilonZ) * hzInv);

		if (ix >= 0 && ix < sizeXBin && iy >= 0 && iy < sizeYBin && iz >= 0 && iz < sizeZBin) {
			output[iz*(sizeXBin*sizeYBin)+ix*sizeYBin+iy] += 1.0;   /* row-major: x is the row */
			net++;
		} else {
			count++;
		}
	}

	if (count > 0) {
		fprintf(stderr,"st_hist3d Warning: %ld entries out of range\n", count);
	}

	if (net > 0) {
		double normFactor = 1.0/((double)net*hx*hy*hz);
		long total = sizeXBin*sizeYBin*sizeZBin;
		for(long i=0;i<total;i++){
			output[i] *= normFactor;
		}
	}
}

// Linear Fit and Pearson Coefficient for two given arrays
double* st_linearRegression(long N, double* x, double* y){
	double* output = ar_alloc(3);
	double xbar=0;
	double ybar=0;
	double Sxy=0,Sxx=0,Syy=0;
	for(long i=0;i<N;i++){
		xbar += x[i];
		ybar += y[i];
	}
	xbar /= N;
	ybar /= N;
	for(long i=0;i<N;i++){
		Sxx += (x[i]-xbar)*(x[i]-xbar);
		Syy += (y[i]-ybar)*(y[i]-ybar);
		Sxy += (x[i]-xbar)*(y[i]-ybar);
	}
	Sxx /= N-1; // variance in x
	Syy /= N-1; // variance in y
	Sxy /= N-1; // correlation of x and y
	output[0] = Sxy/Sxx; // slope
	output[1] = ybar - output[0]*xbar; // intercept
	output[2] = Sxy/sqrt(Sxx*Syy); // pearson coefficent
	return output;
}

// Linear Fit and Pearson Coefficient for two given arrays; returns void
void st_linearRegressionVoid(double* output, long N, double* x, double* y){
	double xbar=0;
	double ybar=0;
	double Sxy=0,Sxx=0,Syy=0;
	for(long i=0;i<N;i++){
		xbar += x[i];
		ybar += y[i];
	}
	xbar /= N;
	ybar /= N;
	for(long i=0;i<N;i++){
		Sxx += (x[i]-xbar)*(x[i]-xbar);
		Syy += (y[i]-ybar)*(y[i]-ybar);
		Sxy += (x[i]-xbar)*(y[i]-ybar);
	}
	Sxx /= N-1; // variance in x
	Syy /= N-1; // variance in y
	Sxy /= N-1; // correlation of x and y
	output[0] = Sxy/Sxx; // slope
	output[1] = ybar - output[0]*xbar; // intercept
	output[2] = Sxy/sqrt(Sxx*Syy); // pearson coefficent
}

//Mean, Standard Deviation, Skewness and Excess Kurtosis for a given array
double* st_stat(long Narr, double* arr) {
	double* reqdArr = ar_alloc(4);
	double sum = 0.0;
	for(long i = 0; i < Narr; i++) {
		sum += arr[i];
	}
	double mean = sum / Narr;
	
	double M2 = 0.0;  // For variance
	double M3 = 0.0;  // For skewness
	double M4 = 0.0;  // For kurtosis
	
	for(long i = 0; i < Narr; i++) {
		M2 += (arr[i] - mean)*(arr[i] - mean);
		M3 += (arr[i] - mean)*(arr[i] - mean)*(arr[i] - mean); 
		M4 += (arr[i] - mean)*(arr[i] - mean)*(arr[i] - mean)*(arr[i] - mean);
	}
		
	reqdArr[0] = mean;
	reqdArr[1] = sqrt((M2)/Narr);
	reqdArr[2] = (M3/Narr)*pow(reqdArr[1],-3);
	reqdArr[3] = ((M4/Narr)*pow(reqdArr[1],-4))-3;
	
	return reqdArr;
}

//Mean, Standard Deviation, Skewness and Excess Kurtosis for a given array; returns void
void st_statVoid(double* output, long Narr, double* arr) {
	double sum = 0.0;
	for(long i = 0; i < Narr; i++) {
		sum += arr[i];
	}
	double mean = sum / Narr;
	
	double M2 = 0.0;  // For variance
	double M3 = 0.0;  // For skewness
	double M4 = 0.0;  // For kurtosis
	
	for(long i = 0; i < Narr; i++) {
		M2 += (arr[i] - mean)*(arr[i] - mean);
		M3 += (arr[i] - mean)*(arr[i] - mean)*(arr[i] - mean); 
		M4 += (arr[i] - mean)*(arr[i] - mean)*(arr[i] - mean)*(arr[i] - mean);
	}
		
	output[0] = mean;
	output[1] = sqrt((M2)/Narr);
	output[2] = (M3/Narr)*pow(output[1],-3);
	output[3] = ((M4/Narr)*pow(output[1],-4))-3;
}

//Mean, Standard Deviation, Skewness and Excess-Kurtosis for a distribution given in the form of an array with uniform stepsize
double* st_statDisbn(long N, double* x, double* disbnX){
	double* disbnXNorm = ar_copy(N,disbnX);
	ar_normalize(N,x,disbnXNorm);
	double* output = ar_calloc(4);
	
	double* reqdArr = ar_mul(N,x,disbnXNorm);
	double mean = ar_integrate(N,x,reqdArr);
	output[0] = mean;
	
	double* reqdArr1 = ar_nums(mean,N);
	ar_subVoid(reqdArr1,N,x,reqdArr1);
	ar_mulVoid(reqdArr,N,reqdArr1,reqdArr1);
	ar_mulVoid(reqdArr,N,reqdArr,disbnXNorm);
	output[1] = ar_integrate(N,x,reqdArr);
	output[1] = sqrt(output[1]);
	
	ar_mulVoid(reqdArr,N,reqdArr,reqdArr1);
	output[2] = ar_integrate(N,x,reqdArr);
	output[2] *= pow(output[1],-3.0);
	
	ar_mulVoid(reqdArr,N,reqdArr,reqdArr1);
	output[3] = ar_integrate(N,x,reqdArr);
	output[3] *= pow(output[1],-4.0);
	output[3] -= 3.0;
	
	ar_free(&disbnXNorm,&reqdArr,&reqdArr1);
	return output;
}

//Mean, Standard Deviation, Skewness and Excess-Kurtosis for a distribution given in the form of an array with uniform stepsize; return void
void st_statDisbnVoid(double* output, long N, double* x, double* disbnX){
	double* disbnXNorm = ar_copy(N,disbnX);
	ar_normalize(N,x,disbnXNorm);
	
	double* reqdArr = ar_mul(N,x,disbnXNorm);
	double mean = ar_integrate(N,x,reqdArr);
	output[0] = mean;
	
	double* reqdArr1 = ar_nums(mean,N);
	ar_subVoid(reqdArr1,N,x,reqdArr1);
	ar_mulVoid(reqdArr,N,reqdArr1,reqdArr1);
	ar_mulVoid(reqdArr,N,reqdArr,disbnXNorm);
	output[1] = ar_integrate(N,x,reqdArr);
	output[1] = sqrt(output[1]);
	
	ar_mulVoid(reqdArr,N,reqdArr,reqdArr1);
	output[2] = ar_integrate(N,x,reqdArr);
	output[2] *= pow(output[1],-3.0);
	
	ar_mulVoid(reqdArr,N,reqdArr,reqdArr1);
	output[3] = ar_integrate(N,x,reqdArr);
	output[3] *= pow(output[1],-4.0);
	output[3] -= 3.0;
	ar_free(&disbnXNorm,&reqdArr,&reqdArr1);
}

//Mean, Standard Deviation, Skewness and Excess-Kurtosis for a distribution given in the form of an array with non-uniform stepsize
double* st_statDisbnQ(long N, double* x, double* disbnX){
	double* disbnXNorm = ar_copy(N,disbnX);
	ar_normalizeQ(N,x,disbnXNorm);
	double* output = ar_calloc(4);
	
	double* reqdArr = ar_mul(N,x,disbnXNorm);
	double mean = ar_integrateQ(N,x,reqdArr);
	output[0] = mean;
	
	double* reqdArr1 = ar_nums(mean,N);
	ar_subVoid(reqdArr1,N,x,reqdArr1);
	ar_mulVoid(reqdArr,N,reqdArr1,reqdArr1);
	ar_mulVoid(reqdArr,N,reqdArr,disbnXNorm);
	output[1] = ar_integrateQ(N,x,reqdArr);
	output[1] = sqrt(output[1]);
	
	ar_mulVoid(reqdArr,N,reqdArr,reqdArr1);
	output[2] = ar_integrateQ(N,x,reqdArr);
	output[2] *= pow(output[1],-3.0);
	
	ar_mulVoid(reqdArr,N,reqdArr,reqdArr1);
	output[3] = ar_integrateQ(N,x,reqdArr);
	output[3] *= pow(output[1],-4.0);
	output[3] -= 3.0;
	
	ar_free(&disbnXNorm,&reqdArr,&reqdArr1);
	return output;
}

//Mean, Standard Deviation, Skewness and Excess-Kurtosis for a distribution given in the form of an array with non-uniform stepsize; return void
void st_statDisbnQvoid(double* output, long N, double* x, double* disbnX){
	double* disbnXNorm = ar_copy(N,disbnX);
	ar_normalizeQ(N,x,disbnXNorm);
	
	double* reqdArr = ar_mul(N,x,disbnXNorm);
	double mean = ar_integrateQ(N,x,reqdArr);
	output[0] = mean;
	
	double* reqdArr1 = ar_nums(mean,N);
	ar_subVoid(reqdArr1,N,x,reqdArr1);
	ar_mulVoid(reqdArr,N,reqdArr1,reqdArr1);
	ar_mulVoid(reqdArr,N,reqdArr,disbnXNorm);
	output[1] = ar_integrateQ(N,x,reqdArr);
	output[1] = sqrt(output[1]);
	
	ar_mulVoid(reqdArr,N,reqdArr,reqdArr1);
	output[2] = ar_integrateQ(N,x,reqdArr);
	output[2] *= pow(output[1],-3.0);
	
	ar_mulVoid(reqdArr,N,reqdArr,reqdArr1);
	output[3] = ar_integrateQ(N,x,reqdArr);
	output[3] *= pow(output[1],-4.0);
	output[3] -= 3.0;
	ar_free(&disbnXNorm,&reqdArr,&reqdArr1);
}

// An array of raw moments from the given data
double* st_rawMoments(long order, long Narr, double* arr){
	double* moments = ar_alloc(order);
	moments[0] = 1.0;
	for (long i = 0; i < Narr; i++) {
		double p = arr[i];
		for (long r = 1; r < order; r++) {
			moments[r] += p;
			p *= arr[i];
		}
	}
	for (long r = 1; r < order; r++) moments[r] /= Narr;
	return moments;
}

// An array of raw moments from the given data returning void
void st_rawMomentsVoid(double* moments, long order, long Narr, double* arr){
	moments[0] = 1.0;
	for (long i = 0; i < Narr; i++) {
		double p = arr[i];
		for (long r = 1; r < order; r++) {
			moments[r] += p;
			p *= arr[i];
		}
	}
	for (long r = 1; r < order; r++) moments[r] /= Narr;
}

// An array of raw moments from a distribution
double* st_rawMomentsDisbn(long order, long N, double* x, double* Ix){
	double* output = ar_alloc(order);
	double* IxNorm = ar_copy(N,Ix);
	ar_normalize(N,x,IxNorm);
	
	output[0] = 1.0;
	double* reqdArr = ar_copy(N,Ix);
	for(long i=1;i<order;i++){
		ar_mulVoid(reqdArr,N,x,reqdArr);
		output[i] = ar_integrate(N,x,reqdArr);
	}
	
	ar_free(&IxNorm,&reqdArr);
	return output;
}

// An array of raw moments from a distribution; returns void
void st_rawMomentsDisbnVoid(double* output, long order, long N, double* x, double* Ix){
	double* IxNorm = ar_copy(N,Ix);
	ar_normalize(N,x,IxNorm);
	
	output[0] = 1.0;
	double* reqdArr = ar_copy(N,Ix);
	for(long i=1;i<order;i++){
		ar_mulVoid(reqdArr,N,x,reqdArr);
		output[i] = ar_integrate(N,x,reqdArr);
	}
	
	ar_free(&IxNorm,&reqdArr);
}

// An array of raw moments from a distribution with non-uniform stepsize
double* st_rawMomentsDisbnQ(long order, long N, double* x, double* Ix){
	double* output = ar_alloc(order);
	double* IxNorm = ar_copy(N,Ix);
	ar_normalizeQ(N,x,IxNorm);
	
	output[0] = 1.0;
	double* reqdArr = ar_copy(N,Ix);
	for(long i=1;i<order;i++){
		ar_mulVoid(reqdArr,N,x,reqdArr);
		output[i] = ar_integrateQ(N,x,reqdArr);
	}
	
	ar_free(&IxNorm,&reqdArr);
	return output;
}

// An array of raw moments from a distribution with non uniform stepsize; returns void
void st_rawMomentsDisbnQvoid(double* output, long order, long N, double* x, double* Ix){
	double* IxNorm = ar_copy(N,Ix);
	ar_normalizeQ(N,x,IxNorm);
	
	output[0] = 1.0;
	double* reqdArr = ar_copy(N,Ix);
	for(long i=1;i<order;i++){
		ar_mulVoid(reqdArr,N,x,reqdArr);
		output[i] = ar_integrateQ(N,x,reqdArr);
	}
	
	ar_free(&IxNorm,&reqdArr);
}

// Getting central moments from raw moments
double* st_centralMomentsFromRawMoments(long order, double* rawMoments){
	double* output = ar_alloc(order);
	double mean = rawMoments[1];
	for(long k=0;k<order;k++){
		for(long i =0;i<= k;i++){
			output[k] += mf_nCr(k,i)*rawMoments[i]*pow(-mean,k-i);
		}
	}
	return output;
}

// Getting raw moments from central moments
double * st_rawMomentsFromCentralMoments(long order, double* centralMoments, double mean){
	double* output = ar_alloc(order);
	for(long k=0;k<order;k++){
		for(long i=0;i<=k;i++){
			output[k] += mf_nCr(k,i)*centralMoments[i]*pow(mean,k-i);
		}
	}
	return output;
}

// Getting central moments from raw moments; returns void
void st_centralMomentsFromRawMomentsVoid(double* output, long order, double* rawMoments){
	double mean = rawMoments[1];
	for(long k=0;k<order;k++){
		for(long i =0;i<= k;i++){
			output[k] += mf_nCr(k,i)*rawMoments[i]*pow(-mean,k-i);
		}
	}
}

// Getting raw moments from central moments; returns void
void st_rawMomentsFromCentralMomentsVoid(double* output, long order, double* centralMoments, double mean){
	for(long k=0;k<order;k++){
		for(long i=0;i<=k;i++){
			output[k] += mf_nCr(k,i)*centralMoments[i]*pow(mean,k-i);
		}
	}
}

// Autocorrelations for a random number array
double* st_autoCorr(long order, long Narr, double* arr){
	double* autoCorr = ar_alloc(order);
	double mean = ar_sum(Narr,arr)/Narr;
	double var = 0.0;
	
	for(long i=0;i<Narr;i++){
		var += (arr[i]-mean)*(arr[i]-mean);
	}
	var /= Narr;
	
	for(long k=0;k<order;k++){
		long num = Narr-k;
		double sum = 0.0;
		for(long i=0;i<num;i++){
			sum += (arr[i]-mean)*(arr[i+k]-mean);
		}
		autoCorr[k] = (sum/num)/var;
	}
	
	return autoCorr;
}

// Autocorrelations for a random number array returns void
void st_autoCorrVoid(double* autoCorr, long order, long Narr, double* arr){
	double mean = ar_sum(Narr,arr)/Narr;
	double var = 0.0;
	
	for(long i=0;i<Narr;i++){
		var += (arr[i]-mean)*(arr[i]-mean);
	}
	var /= Narr;
	
	for(long k=0;k<order;k++){
		long num = Narr-k;
		double sum = 0.0;
		for(long i=0;i<num;i++){
			sum += (arr[i]-mean)*(arr[i+k]-mean);
		}
		autoCorr[k] = (sum/num)/var;
	}
}

