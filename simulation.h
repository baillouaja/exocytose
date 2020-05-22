#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED

/* Updating to Nc(t+dt), y(t+dt) and t+dt from Nc(t), y(t) and t */
void updateSystem(int N, int &Nc, double &y, double &t, double dt);

void y_Nc_function_of_t(int N, double dt, int sampling);

void tau1_tau(int N, double dt, int Nexp);

void tau_function_of_N_dt(int N, double dt_power, int Nexp);

void convergence_tau_N(int N, int Nexp);

void energy_landscape(int N_snare,int N_ads);
#endif // SIMULATION_H_INCLUDED
