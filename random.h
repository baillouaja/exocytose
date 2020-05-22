#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED

/* Generation of a long-period and "precised" random number between 0 and 1 (uniform distribution) */
double ran2(long *idum);

double rdm_unif(); // Returns random uniform number between 0 and 1 (using ran2)
double rdm_gauss(double sigma); // Returns random gaussian number


#endif // RANDOM_H_INCLUDED
