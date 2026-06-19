#include"private_inOut.h"

// Closing N file pointers at once
void io_fcloseN(long N, ...){
	va_list inputs;
	va_start(inputs,N);
	for(long j = 0; j < N; j++){
		FILE** x = va_arg(inputs, FILE**);
		if( x == NULL || *x == NULL ){
			fprintf(stderr,"ar_free: Error! Either the input pointer is NULL or the pointer it points to is NULL.\n");
		}else{
			fclose(*x);
			*x = NULL;
		}
	}
	va_end(inputs);
}
