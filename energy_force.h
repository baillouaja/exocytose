#ifndef ENERGY_FORCE_H_INCLUDED
#define ENERGY_FORCE_H_INCLUDED

/* Potential energy of a snare and force (-derivate of energy) */
// Half-Zipped (state n)
double e_n(double y);
double f_n(double y);
// Fully-Zipped (state c)
double e_c(double y);
double f_c(double y);

double e_syn(double y);
double f_syn(double y);

double E_free(int N, double y);
double J_syn(int N, double y);

/* Potentiel energy of the system of N snares and force (-derivate of energy) */
double E_snare(int N, double Nc, double y);
double F_snare(int N, int Nc, double y);

/* Energy barrier for the fusion and force (-derivate of energy) */
double E_fusion(double y);
double F_fusion(double y);

/* Kind of force due to thermal agitation - White noise */
double F_white_noise();
double phi(double y, int N_snare, int N_site);
#endif // ENERGY_FORCE_H_INCLUDED
