#include"private_inOut.h"

// Printing N integers
void io_PrintN(long N, ...){
	va_list inputs;
	va_start(inputs,N);
	for(long i=0;i<N;i++){
		printf("%ld ",va_arg(inputs, long));
	}
	va_end(inputs);
	printf("\n");
}

void io_PrintQN(char* string, long N, ...){
	printf("%s : ",string);
	va_list inputs;
	va_start(inputs,N);
	for(long i=0;i<N;i++){
		printf("%ld ",va_arg(inputs, long));
	}
	va_end(inputs);
	printf("\n");
}

// Printing N doubles
void io_printN(long N, ...){
	va_list inputs;
	va_start(inputs,N);
	for(long i=0;i<N;i++){
		printf("%0.15lf ",va_arg(inputs, double));
	}
	va_end(inputs);
	printf("\n");
}

void io_printQN(char* string, long N, ...){
	printf("%s : ",string);
	va_list inputs;
	va_start(inputs,N);
	for(long i=0;i<N;i++){
		printf("%0.15lf ",va_arg(inputs, double));
	}
	va_end(inputs);
	printf("\n");
}


// Printing N long int arrays
void io_PrintArrN(long Narr, long N, ...){
	long* x[N];
	va_list inputs;
	va_start(inputs,N);
	for(long i=0;i<N;i++){
		x[i] = va_arg(inputs, long*);
	}
	va_end(inputs);
	for(long i=0;i<Narr;i++){
		for(long j=0;j<N;j++){
			printf("%ld ",*(x[j]+i));
		}
		printf("\n");
	}
}

void io_PrintArrQN(char* string, long Narr, long N, ...){
	printf("%s : \n",string);
	long* x[N];
	va_list inputs;
	va_start(inputs,N);
	for(long i=0;i<N;i++){
		x[i] = va_arg(inputs, long*);
	}
	va_end(inputs);
	for(long i=0;i<Narr;i++){
		for(long j=0;j<N;j++){
			printf("%ld ",*(x[j]+i));
		}
		printf("\n");
	}
}

// Printing N double arrays
void io_printArrN(long Narr, long N, ...){
	double* x[N];
	va_list inputs;
	va_start(inputs,N);
	for(long i=0;i<N;i++){
		x[i] = va_arg(inputs, double*);
	}
	va_end(inputs);
	for(long i=0;i<Narr;i++){
		for(long j=0;j<N;j++){
			printf("%0.15lf ",*(x[j]+i));
		}
		printf("\n");
	}
}

void io_printArrQN(char* string, long Narr, long N, ...){
	printf("%s : \n",string);
	double* x[N];
	va_list inputs;
	va_start(inputs,N);
	for(long i=0;i<N;i++){
		x[i] = va_arg(inputs, double*);
	}
	va_end(inputs);
	for(long i=0;i<Narr;i++){
		for(long j=0;j<N;j++){
			printf("%0.15lf ",*(x[j]+i));
		}
		printf("\n");
	}
}


// Printing a string
void io_printStr(char* s){
	printf("%s\n",s);
}

// Printing a matrix of long ints
void io_PrintMtrx(long rows, long columns, long* matrix){
	for(long i=0;i<rows;i++){
		for(long j=0;j<columns;j++){
			printf("%ld ",matrix[i*columns+j]);
		}
		printf("\n");
	}
}

// Printing a matrix of doubles
void io_printMtrx(long rows, long columns, double* matrix){
	for(long i=0;i<rows;i++){
		for(long j=0;j<columns;j++){
			printf("%0.15lf ",matrix[i*columns+j]);
		}
		printf("\n");
	}
}
