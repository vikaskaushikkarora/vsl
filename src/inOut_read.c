#include"private_inOut.h"

// Getting to know the number of rows in a file
long io_getNumRows(char* filename){
	long Nrows=0;
	int c;
	FILE* fpR = fopen(filename,"r");
	if(fpR == NULL){
		fprintf(stderr, "io_getNumRows Error: could not open file %s\n", filename);
		return -1;
	}else{
		for(c=fgetc(fpR); c != EOF; c=fgetc(fpR)){
			if(c == '\n'){
				Nrows++;
			}
		}
	}
	fclose(fpR);
	return Nrows;
}

// Getting to know the number of columns in a file
long io_getNumColumns(char* filename){
	long Ncolumns=1;
	int c,c1;
	FILE* fpR = fopen(filename,"r");
	FILE* fpR1 = fopen(filename,"r");
	if(fpR == NULL){
		fprintf(stderr, "io_getNumColumns Error: could not open file %s\n", filename);
		return -1;
	}else{
		c=fgetc(fpR);
		if(c == '\n' || c == -1){
			return 0;
		}
		for(c=fgetc(fpR); c != '\n'; c=fgetc(fpR)){
			c1=fgetc(fpR1);
			if(c == ' ' || c == '\t'){
				Ncolumns++;
			}
		}
		c1=fgetc(fpR1);
	}
	if(c1 == ' ' || c1 == '\t'){
		Ncolumns--;
	}
	fclose(fpR);
	fclose(fpR1);
	return Ncolumns;
}

// Reading a matrix of long ints from a data file
long* io_ReadMtrx(char* filename, long* rows, long* columns){
	long Rows = io_getNumRows(filename);
	long Columns = io_getNumColumns(filename);
	*rows=Rows;
	*columns=Columns;
	long* matrix = ar_Alloc(Rows*Columns);
	FILE* fpR = fopen(filename,"r");
	for(long i=0;i<Rows;i++){
		for(long j=0;j<Columns;j++){
			{int var = fscanf(fpR,"%ld ",(matrix+Columns*i+j)); (void)var;}
		}
		{int var = fscanf(fpR,"\n"); (void) var;}
	}
	fclose(fpR);
	return matrix;
}

// Reading a matrix of doubles from a data file 
double* io_readMtrx(char* filename, long* rows, long* columns){
	long Rows = io_getNumRows(filename);
	long Columns = io_getNumColumns(filename);
	*rows=Rows;
	*columns=Columns;
	double* matrix = ar_alloc(Rows*Columns);
	FILE* fpR = fopen(filename,"r");
	for(long i=0;i<Rows;i++){
		for(long j=0;j<Columns;j++){
			{int var = fscanf(fpR,"%lf ",(matrix+Columns*i+j)); (void) var;}
		}
		{int var = fscanf(fpR,"\n"); (void) var;}
	}
	fclose(fpR);
	return matrix;
}

// Reading a 3d matrix of longs from a data file 
long* io_ReadMtrx3d(char* filename, long* rows, long* columns, long* heights){
	FILE* fp = fopen(filename, "r");
	if(fp == NULL){
		fprintf(stderr, "io_ReadMtrx3d Error: could not open file %s\n", filename);
		return NULL;
	}
	{int notReqd = fscanf(fp, "%ld %ld %ld\n", rows, columns, heights); (void) notReqd;}
	long* matrix = ar_Calloc((*rows) * (*columns) * (*heights));
	for(long k = 0; k < *heights; k++){
		for(long i = 0; i < *rows; i++){
			for(long j = 0; j < *columns; j++){
				{int notReqd = fscanf(fp,"%ld",&matrix[k * (*rows * *columns) + i * *columns + j]); (void) notReqd;}
			}
		}
	}
	fclose(fp);
	return matrix;
}

// Reading a 3d matrix of doubles from a data file 
double* io_readMtrx3d(char* filename, long* rows, long* columns, long* heights){
	FILE* fp = fopen(filename, "r");
	if(fp == NULL){
		fprintf(stderr, "io_readMtrx3d Error: could not open file %s\n", filename);
		return NULL;
	}
	{int notReqd = fscanf(fp, "%ld %ld %ld\n", rows, columns, heights); (void) notReqd;}
	double* matrix = ar_calloc((*rows) * (*columns) * (*heights));
	for(long k = 0; k < *heights; k++){
		for(long i = 0; i < *rows; i++){
			for(long j = 0; j < *columns; j++){
				{int notReqd = fscanf(fp, "%lf", &matrix[k * (*rows * *columns) + i * *columns + j]); (void) notReqd;}
			}
		}
	}
	fclose(fp);
	return matrix;
}

// Read a matrix of longs from a binary file 
long* io_ReadMtrxBin(char* filename, long* rows, long* columns){
	long Narr,N;
	FILE* fp = fopen(filename,"rb");
	if(fp == NULL){
		fprintf(stderr, "io_ReadMtrxBin Error: could not open file %s\n", filename);
		return NULL;
	}else{
		{int var = fread(&Narr,sizeof(long),1,fp); (void) var;}
		{int var = fread(&N,sizeof(long),1,fp); (void) var;}
		long* matrix = ar_Alloc(Narr*N);
		long* arr = ar_Alloc(Narr);
		for(long i=0;i<N;i++){
			{int dummy = fread(arr,sizeof(long),Narr,fp); (void) dummy;}
			for(long j=0;j<Narr;j++){
				matrix[j*N+i] = arr[j];
			}
		}
		free(arr);
		fclose(fp);
		*rows = Narr;
		*columns = N;
		return matrix;
	}
}

// Read a matrix of doubles from a binary file 
double* io_readMtrxBin(char* filename, long* rows, long* columns){
	long Narr,N;
	FILE* fp = fopen(filename,"rb");
	if(fp == NULL){
		fprintf(stderr, "io_readMtrxBin Error: could not open file %s\n", filename);
		return NULL;
	}else{
		{int var = fread(&Narr,sizeof(long),1,fp); (void) var;}
		{int var = fread(&N,sizeof(long),1,fp); (void) var;}
		double* matrix = ar_alloc(Narr*N);
		double* arr = ar_alloc(Narr);
		for(long i=0;i<N;i++){
			{int dummy = fread(arr,sizeof(double),Narr,fp); (void) dummy;}
			for(long j=0;j<Narr;j++){
				matrix[j*N+i] = arr[j];
			}
		}
		free(arr);
		fclose(fp);
		*rows = Narr;
		*columns = N;
		return matrix;
	}
}
