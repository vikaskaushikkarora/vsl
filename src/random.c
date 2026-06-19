#include"private_random.h"

// ============================================================
//  PCG32 internals — static, hidden from all other files
// ============================================================

// Proceed the RNG state
static inline uint32_t vsl_pcg32_random_r(vsl_pcg32_random_t *rng){
	uint64_t oldstate   = rng->state;
	rng->state          = oldstate * 6364136223846793005ULL + (rng->inc | 1);
	uint32_t xorshifted = ((oldstate >> 18u) ^ oldstate) >> 27u;
	uint32_t rot        = oldstate >> 59u;
	return (xorshifted >> rot) | (xorshifted << ((-rot) & 31));
}

// Initiate the RNG state
static inline void vsl_pcg32_srandom_r(vsl_pcg32_random_t *rng, uint64_t seed, uint64_t stream){
	rng->state = 0u;
	rng->inc   = (stream << 1u) | 1u;
	vsl_pcg32_random_r(rng);
	rng->state += seed;
	vsl_pcg32_random_r(rng);
}

// Single global RNG for single-threaded use
static vsl_pcg32_random_t global_rng;

// Core uniform double in [0, 1) — used internally by all rd_* functions
static inline double rd_raw(void){
	return vsl_pcg32_random_r(&global_rng) / (double)UINT32_MAX;
}

// Internal version that takes an explicit rng — used by parallel functions
static inline double rd_rawP(vsl_pcg32_random_t *rng){
	return vsl_pcg32_random_r(rng) / (double)UINT32_MAX;
}

// ============================================================
//  Seeding
// ============================================================


// Seeds the global RNG using the current time
// Call once at the start of your program
void rd_seed(void){
	vsl_pcg32_srandom_r(&global_rng, (uint64_t)time(NULL), 1u);
}

// Seeds the global RNG with explicit values for reproducible runs
// Use during debugging or unit tests.
void rd_seed_fixed(uint64_t seed, uint64_t stream){
	vsl_pcg32_srandom_r(&global_rng, seed, stream);
}

// Seeds an external vsl_pcg32_random_t for use in parallel code
// Each thread should have its own vsl_pcg32_random_t and a unique stream number

void rd_seed_thread(vsl_pcg32_random_t *rng, uint64_t stream){
	vsl_pcg32_srandom_r(rng, (uint64_t)time(NULL), stream);
}

// ============================================================
//  Single-threaded public API — all use global_rng
// ============================================================


long rd_int(long lowerLimit, long upperLimit){
	long range = upperLimit - lowerLimit + 1;
	return lowerLimit + (long)(rd_raw()*range);
}

long *rd_intArr(long Narr, long lowerLimit, long upperLimit){
	long *arr = ar_Alloc(Narr);
	long range = upperLimit - lowerLimit + 1;
	for (long i = 0; i < Narr; i++){
		arr[i] = lowerLimit + (long)(rd_raw()*range);
	}
	return arr;
}

double rd_uniform(double lowerLimit, double upperLimit){
	return lowerLimit+(upperLimit-lowerLimit)*rd_raw();
}

double *rd_uniformArr(long Narr, double lowerLimit, double upperLimit){
	double *arr = ar_alloc(Narr);
	double range = upperLimit - lowerLimit;
	for (long i = 0; i < Narr; i++){
		arr[i] = lowerLimit+range*rd_raw();
	}
	return arr;
}

double rd_gauss(double mu, double std){
	static int    has_spare = 0;
	static double spare;
	if(has_spare){
        	has_spare = 0;
        	return mu + std * spare;
        }
        
        double u, v, mag;
        do { u = rd_raw(); } while (u == 0.0);
        v = rd_raw();
        mag = sqrt(-2.0 * log(u));
        spare     = mag * cos(2.0 * M_PI * v);
        has_spare = 1;
        return mu + std * (mag * sin(2.0 * M_PI * v));
}

double *rd_gaussArr(long Narr, double mu, double s){
	double *arr = ar_alloc(Narr);
	for (long i = 0; i < Narr; i++){
		arr[i] = rd_gauss(mu,s);
	}
	return arr;
}

double rd_johnsonSU(double* params){
	double z = rd_gauss(0.0, 1.0);
	return params[0] + params[1] * sinh((z - params[2]) / params[3]);
}

double rd_johnsonSB(double* params){
	double z = rd_gauss(0.0,1.0);
	double t = (z-params[2])/params[3];
	return params[0] + params[1] * ( t >= 0.0 ? 1.0/(1.0+exp(-t)) : exp(t)/(1.0+exp(t)) );
}

double* rd_johnsonSUarr(long Narr, double* params){
	double* arr = ar_alloc(Narr);
	for(long i = 0; i < Narr; i++){
		arr[i] = rd_johnsonSU(params);
	}
	return arr;
}

double* rd_johnsonSBArr(long Narr, double* params){
	double* arr = ar_alloc(Narr);
	for(long i = 0; i < Narr; i++){
		double z = rd_gauss(0.0,1.0);
		double t = (z-params[2])/params[3];
		arr[i] = params[0] + params[1] * ( t >= 0.0 ? 1.0/(1.0+exp(-t)) : exp(t)/(1.0+exp(t)) );
	}
	return arr;
}

double rd_corrGaussAR1(double mean, double std, double prevNum, double corrFac){
	return mean + corrFac*(prevNum-mean) + std*sqrt(1-corrFac*corrFac)*rd_gauss(0,1);
}

double* rd_corrGaussAR1arr(long Narr, double mean, double std, double corrFac){
	double* output = ar_alloc(Narr);
	output[0] = rd_gauss(mean,std);
	if(Narr == 1){
		return output;
	}else{
		for(long i=1;i<Narr;i++){
			output[i] = rd_corrGaussAR1(mean,std,output[i-1],corrFac);
		}
		return output;
	}
}

// ============================================================
//  Parallel API — caller passes their own vsl_pcg32_random_t
// ============================================================ */

long rd_intP(vsl_pcg32_random_t *rng, long lowerLimit, long upperLimit){
	long range = upperLimit - lowerLimit + 1;
	return lowerLimit + (long)(rd_rawP(rng)*range);
}

double rd_uniformP(vsl_pcg32_random_t *rng, double lowerLimit, double upperLimit){
	return lowerLimit+(upperLimit-lowerLimit)*rd_rawP(rng);
}

double rd_gaussP(vsl_pcg32_random_t *rng, double mu, double s){
	double u, v, mag;
	do { u = rd_rawP(rng); } while (u == 0.0);
	v = rd_rawP(rng);
	mag = sqrt(-2.0 * log(u));
	// no spare caching here — static variables are not thread safe
	return mu + s * (mag * sin(2.0 * M_PI * v));
}

long *rd_intArrP(vsl_pcg32_random_t *rng, long Narr, long lowerLimit, long upperLimit){
	long *arr = ar_Alloc(Narr);
	long range = upperLimit - lowerLimit + 1;
	for (long i = 0; i < Narr; i++){
		arr[i] = lowerLimit + (long)(rd_rawP(rng) * range);
	}
	return arr;
}

double *rd_uniformArrP(vsl_pcg32_random_t *rng, long Narr, double lowerLimit, double upperLimit){
	double *arr = ar_alloc(Narr);
	double range = upperLimit - lowerLimit;
	for(long i = 0; i < Narr; i++){
		arr[i] = lowerLimit+range*rd_rawP(rng);
	}
	return arr;
}

double *rd_gaussArrP(vsl_pcg32_random_t *rng, long Narr, double mu, double std){
	double *arr = ar_alloc(Narr);
	
	//Box-Muller with spare caching — safe here because the spare
	//is local to this function call, not a static variable,
	//so there is no sharing between threads
	
	double spare;
	int has_spare = 0;   // regular local variable this time, not static
		
	for (long i = 0; i < Narr; i++){
		if (has_spare){
			has_spare = 0;
			arr[i] = mu+std*spare;
		}else {
			double u, v, mag;
			do { u = rd_rawP(rng); } while (u == 0.0);
			v = rd_rawP(rng);
			mag = sqrt(-2.0 * log(u));
			spare = mag * cos(2.0 * M_PI * v);
			has_spare = 1;
			arr[i] = mu+std*(mag*sin(2.0*M_PI*v));
		}
	}
	return arr;
}

double rd_johnsonSUP(vsl_pcg32_random_t *rng, double* params){
	double z = rd_gaussP(rng, 0.0, 1.0);
	return params[0] + params[1] * sinh((z - params[2]) / params[3]);
}

double *rd_johnsonSUarrP(vsl_pcg32_random_t *rng, long Narr, double* params){
    /* Uses local spare caching (same pattern as rd_gaussArrP) so the
     * two normals produced by each Box-Muller pair are both consumed,
     * cutting the number of PCG32 draws roughly in half.            */
    double *arr = ar_alloc(Narr);
    double spare;
    int has_spare = 0;

    for (long i = 0; i < Narr; i++){
        double z;
        if (has_spare){
            has_spare = 0;
            z = spare;
        } else {
            double u, v, mag;
            do { u = rd_rawP(rng); } while (u == 0.0);
            v   = rd_rawP(rng);
            mag = sqrt(-2.0 * log(u));
            spare     = mag * cos(2.0 * M_PI * v);
            has_spare = 1;
            z         = mag * sin(2.0 * M_PI * v);
        }
        arr[i] = params[0] + params[1] * sinh((z - params[2]) / params[3]);
    }
    return arr;
}

