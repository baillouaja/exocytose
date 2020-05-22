#ifndef SIMULATION_SYN_H_INCLUDED
#define SIMULATION_SYN_H_INCLUDED

void updateSystemSyn(int Nsnare, int Nsyn, int &Nc, int &Nbound, double &y, double &t, double dt);

void y_Nc_function_of_tSyn(int Nsnare, int Nsyn, double dt, int sampling);

void tau_function_of_N_dtSyn(int Nsnare, int Nsyn, double dt, int Nexp);
#endif // SIMULATION_SYN_H_INCLUDED
