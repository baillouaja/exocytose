#ifndef STOCHASTIC_H_INCLUDED
#define STOCHASTIC_H_INCLUDED

/* Transition + : n->c */
double k_nc (double y);//k+
double W_nc (int N, int Nc, double y, double dt);//W+1
/* Transition - : c->n */
double k_cn (double y);//k-
double W_cn (int N, int Nc, double y, double dt);//W-1

/* Evaluating Nc(t+dt)-Nc(t) from transition rate */
int dNc(int N, int Nc, double y, double dt);

/* Evaluating y(t+dt)-y(t) from Langevin with Euler method */
double dy(int N, int Nc, double y, double dt);


int dNbound(int Nsyn, int Nbound, double y, double dt);
double dySyn(int Nsnare, int Nc, int Nbound, double y, double dt);
#endif // STOCHASTIC_H_INCLUDED
