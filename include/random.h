#ifndef RANDOM_H
#define RANDOM_H

#include"essential_headers.h"

// ============================================================
// PCG32 state struct — public so parallel code can declare
// its own vsl_pcg32_random_t variables and pass them to rd_*_r
// functions. The algorithm internals remain hidden in random.c
// The structs and functions have prefix as vsl in order to
// avoid conflicts if pcg32 library is used externally.
// ============================================================

typedef struct { uint64_t state; uint64_t inc; } vsl_pcg32_random_t;

// ============================================================
//  Seeding for serial and parallel code
// ============================================================

// Seeds the global RNG from the current time — call once at program start
void rd_seed(void);

// Seeds the global RNG with fixed values for reproducible run
void rd_seed_fixed(uint64_t seed, uint64_t stream);

// Seeds an external RNG struct for parallel use — give each thread its own vsl_pcg32_random_t and a unique stream number
void rd_seed_thread(vsl_pcg32_random_t *rng, uint64_t stream);

// ============================================================
//  Single-threaded API — use these in non-parallel code
// ============================================================

// Uniform integer in [lowerLimit, upperLimit]
long rd_int(long lowerLimit, long upperLimit);

// Array of Narr uniform integers in [lowerLimit, upperLimit] — caller frees */
long* rd_intArr(long Narr, long lowerLimit, long upperLimit);

// Uniform double in [0, 1)
double rd_uniform(double lowerLimit, double upperLimit);

// Array of Narr uniform doubles in [0, 1)
double* rd_uniformArr(long Narr, double lowerLimit, double upperLimit);

// Gaussian double
double rd_gauss(double mu, double s);

// Array of Narr Gaussian doubles with mean mu and standard deviation s
double* rd_gaussArr(long Narr, double mu, double s);

// Johnson SU double
double  rd_johnsonSU(double* params);

// Johnson SB double
double rd_johnsonSB(double* params);

// An array of Johnson SU doubles
double *rd_johnsonSUarr(long Narr, double* params);

// An array of Johnson SB doubles
double* rd_johnsonSBArr(long Narr, double* params);

// Correlated random Gaussian number using auto-regression(1) algorithm
double rd_corrGaussAR1(double mean, double std, double prevNum, double corrFac);

// An array of correlated random Gaussian numbers using auto-regression(1) algorithm
double* rd_corrGaussAR1arr(long Narr, double mean, double std, double corrFac);

// ============================================================
//  Multi-threaded API — use these in parallel code
// ============================================================

long rd_intP(vsl_pcg32_random_t *rng, long lowerLimit, long upperLimit);
double rd_uniformP(vsl_pcg32_random_t *rng, double lowerLimit, double upperLimit);
double rd_gaussP(vsl_pcg32_random_t *rng, double mu, double std);
long* rd_intArrP(vsl_pcg32_random_t *rng, long Narr, long lowerLimit, long upperLimit);
double* rd_uniformArrP(vsl_pcg32_random_t *rng, long Narr, double lowerLimit, double upperLimit);
double* rd_gaussArrP(vsl_pcg32_random_t *rng, long Narr, double mu, double std);
double  rd_johnsonSUP(vsl_pcg32_random_t *rng, double* params);
double *rd_johnsonSUarrP(vsl_pcg32_random_t *rng, long Narr, double* params);


/* ============================================================
Example usage for rng in parallel
#define NTHREADS  4
#define NSAMPLES  5

typedef struct {
    int            thread_id;
    double         mu;
    double         s;
    vsl_pcg32_random_t rng;
} thread_data_t;

void *worker(void *arg)
{
    thread_data_t *d = (thread_data_t *)arg;

    for (long i = 0; i < NSAMPLES; i++) {
        double x = rd_gaussP(&d->rng, d->mu, d->s);
        printf("Thread %d: %f\n", d->thread_id, x);
    }

    return NULL;
}

int main(void)
{
    pthread_t     threads[NTHREADS];
    thread_data_t tdata[NTHREADS];

    for (int t = 0; t < NTHREADS; t++) {
        tdata[t].thread_id = t;
        tdata[t].mu        = 0.0;
        tdata[t].s         = 1.0;
        rd_seed_thread(&tdata[t].rng, (uint64_t)t + 1);
        pthread_create(&threads[t], NULL, worker, &tdata[t]);
    }

    for (int t = 0; t < NTHREADS; t++)
        pthread_join(threads[t], NULL);

    return 0;
}
============================================================*/

#endif
