#include"private_inOut.h"

// Write N 1D arrays of doubles in a file column by column
void io_WriteArrN(char* filename, long Narr, long N, ...){
	FILE* fp = fopen(filename,"w");
	if(fp == NULL){
		fprintf(stderr,"io_WriteArrN Error: could not open file %s\n",filename);
		return;
	}
	long** x = malloc(N*sizeof(long*));
	va_list inputs;
	va_start(inputs,N);
	for(long i=0;i<N;i++){
		x[i] = va_arg(inputs, long*);
	}
	va_end(inputs);
	for(long i=0;i<Narr;i++){
		for(long j=0;j<N;j++){
			fprintf(fp,"%ld ",*(x[j]+i));
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
	free(x);
}


// Write N 1D arrays of doubles in a file column by column
void io_writeArrN(char* filename, long Narr, long N, ...){
	FILE* fp = fopen(filename,"w");
	if(fp == NULL){
		fprintf(stderr,"io_writeArrN Error: could not open file %s\n",filename);
		return;
	}
	double** x = malloc(N*sizeof(double*));
	va_list inputs;
	va_start(inputs,N);
	for(long i=0;i<N;i++){
		x[i] = va_arg(inputs, double*);
	}
	va_end(inputs);
	for(long i=0;i<Narr;i++){
		for(long j=0;j<N;j++){
			fprintf(fp,"%0.15lf ",*(x[j]+i));
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
	free(x);
}

// Write N 1D arrays of long ints in a file row by row
void io_WriteArrQN(char* filename, long Narr, long N, ...){
	FILE* fp = fopen(filename,"w");
	if(fp == NULL){
		fprintf(stderr,"io_WriteArrQN Error: could not open file %s\n",filename);
		return;
	}
	va_list inputs;
	va_start(inputs,N);
	for(long i=0;i<N;i++){
		long* x = va_arg(inputs,long*);
		for(long j=0;j<Narr;j++){
			fprintf(fp,"%ld ",x[j]);
		}
		fprintf(fp,"\n");
	}
	va_end(inputs);
	fclose(fp);
}

// Write N 1D arrays of doubles in a file row by row
void io_writeArrQN(char* filename, long Narr, long N, ...){
	FILE* fp = fopen(filename,"w");
	if(fp == NULL){
		fprintf(stderr,"io_writeArrQN Error: could not open file %s\n",filename);
		return;
	}
	va_list inputs;
	va_start(inputs,N);
	for(long i=0;i<N;i++){
		double* x = va_arg(inputs,double*);
		for(long j=0;j<Narr;j++){
			fprintf(fp,"%0.15lf ",x[j]);
		}
		fprintf(fp,"\n");
	}
	va_end(inputs);
	fclose(fp);
}

// Write a matrix of long ints in a file
void io_WriteMtrx(char* filename, long rows, long columns, long* matrix){
	FILE* fp = fopen(filename,"w");
	if(fp == NULL){
		fprintf(stderr,"io_WriteMtrx Error: could not open file %s\n",filename);
		return;
	}
	for(long i=0;i<rows;i++){
		for(long j=0;j<columns;j++){
			fprintf(fp,"%ld ",matrix[i*columns+j]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
}

// Write a matrix of doubles in a file
void io_writeMtrx(char* filename, long rows, long columns, double* matrix){
	FILE* fp = fopen(filename,"w");
	if(fp == NULL){
		fprintf(stderr,"io_writeMtrx Error: could not open file %s\n",filename);
		return;
	}
	for(long i=0;i<rows;i++){
		for(long j=0;j<columns;j++){
			fprintf(fp,"%0.15lf ",matrix[i*columns+j]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
}

// Write a 3d matrix of long ints in a file
void io_WriteMtrx3d(char* filename, long rows, long columns, long heights, long* matrix){
	FILE* fp = fopen(filename,"w");
	if(fp == NULL){
		fprintf(stderr,"io_WriteMtrx3d Error: could not open file %s\n",filename);
		return;
	}
	fprintf(fp,"%ld %ld %ld\n\n",rows,columns,heights);
	for(long k=0;k<heights;k++){
		for(long i=0;i<rows;i++){
			for(long j=0;j<columns;j++){
				fprintf(fp,"%ld ",matrix[k*(rows*columns)+i*columns+j]);
			}
			fprintf(fp,"\n");
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
}

// Write a 3d matrix of doubles in a file
void io_writeMtrx3d(char* filename, long rows, long columns, long heights, double* matrix){
	FILE* fp = fopen(filename,"w");
	if(fp == NULL){
		fprintf(stderr,"io_writeMtrx3d Error: could not open file %s\n",filename);
		return;
	}
	fprintf(fp,"%ld %ld %ld\n\n",rows,columns,heights);
	for(long k=0;k<heights;k++){
		for(long i=0;i<rows;i++){
			for(long j=0;j<columns;j++){
				fprintf(fp,"%0.15lf ",matrix[k*(rows*columns)+i*columns+j]);
			}
			fprintf(fp,"\n");
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
}

// Write N 1D arrays of longs in a file in binary form
void io_WriteArrBinN(char* filename, long Narr, long N, ...){
	FILE* fp = fopen(filename,"wb");
	if(fp == NULL){
		fprintf(stderr,"io_WriteArrBinN Error: could not open file %s\n",filename);
		return;
	}
	fwrite(&Narr,sizeof(long),1,fp);
	fwrite(&N,sizeof(long),1,fp);
	va_list inputs;
	va_start(inputs,N);
	for(long j=0;j<N;j++){
		long* arr = va_arg(inputs, long*);
		fwrite(arr,sizeof(long),Narr,fp);

	}
	fclose(fp); //Arrays are written as the columns of matrix
}

// Write N 1D arrays of doubles in a file in binary form
void io_writeArrBinN(char* filename, long Narr, long N, ...){
	FILE* fp = fopen(filename,"wb");
	if(fp == NULL){
		fprintf(stderr,"io_writeArrBinN Error: could not open file %s\n",filename);
		return;
	}
	fwrite(&Narr,sizeof(long),1,fp);
	fwrite(&N,sizeof(long),1,fp);
	va_list inputs;
	va_start(inputs,N);
	for(long j=0;j<N;j++){
		double* arr = va_arg(inputs, double*);
		fwrite(arr,sizeof(double),Narr,fp);
	}
	fclose(fp); //Arrays are written as the columns of matrix
}

// Write a matrix of longs in a file in binary form
void io_WriteMtrxBin(char* filename, long rows, long columns, long* matrix){
	FILE* fp = fopen(filename,"wb");
	if(fp == NULL){
		fprintf(stderr,"io_WriteMtrxBin Error: could not open file %s\n",filename);
		return;
	}
	fwrite(&rows,sizeof(long),1,fp); // Narr = rows
	fwrite(&columns,sizeof(long),1,fp); // N = columns
	for(long i=0;i<columns;i++){
		for(long j=0;j<rows;j++){
			fwrite(matrix+(j*columns)+i,sizeof(long),1,fp);
		}
	}
	fclose(fp);
}

// Write a matrix of doubles in a file in binary form
void io_writeMtrxBin(char* filename, long rows, long columns, double* matrix){
	FILE* fp = fopen(filename,"wb");
	if(fp == NULL){
		fprintf(stderr,"io_writeMtrxBin Error: could not open file %s\n",filename);
		return;
	}
	fwrite(&rows,sizeof(long),1,fp);
	fwrite(&columns,sizeof(long),1,fp);
	for(long i=0;i<columns;i++){
		for(long j=0;j<rows;j++){
			fwrite(matrix+(j*columns)+i,sizeof(double),1,fp);
		}
	}
	fclose(fp);
}

