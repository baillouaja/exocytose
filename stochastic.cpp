#include "std_include.h"

double k_nc (double y){
    double delta_e=e_n(y)-e_c(y);
    if(delta_e < 0) return k*exp(delta_e);
    else return k;
}
double W_nc (int N, int Nc, double y, double dt){
    return (N-Nc)*k_nc(y)*dt;
}

double k_cn (double y){
    double delta_e=e_c(y)-e_n(y);
    if (delta_e<0) return k*exp(delta_e);
    else return k;
}
double W_cn (int N, int Nc, double y, double dt){
    return Nc*k_cn(y)*dt;
}

int dNc(int N, int Nc, double y, double dt)
{
    double rdm_var=rdm_unif();
    double proba_nc = W_nc(N,Nc,y,dt);
    double proba_cn = W_cn(N,Nc,y,dt);

    if (rdm_var<proba_nc) return +1;
    else if (rdm_var <proba_nc+proba_cn) return -1;
    else return 0;
}

double dy(int N, int Nc, double y, double dt){
    return (F_snare(N,Nc,y)+F_fusion(y))*dt+F_white_noise()*sqrt(dt);
}


double k_bound (double y){
    double delta_e=e_syn(y);
    if(delta_e < 0) return ksyn;
    else return ksyn*exp(-delta_e);
}
double W_bound (int Nsyn, int Nbound, double y, double dt){
    return (Nsyn-Nbound)*k_bound(y)*dt;
}

double k_unbound (double y){
    double delta_e=e_syn(y);
    if (delta_e<0) return ksyn*exp(delta_e);
    else return ksyn;
}
double W_unbound (int Nsyn, int Nbound, double y, double dt){
    return Nbound*k_unbound(y)*dt;
}

int dNbound(int Nsyn, int Nbound, double y, double dt)
{
    double rdm_var=rdm_unif();
    double proba_bound = W_bound(Nsyn,Nbound,y,dt);
    double proba_unbound = W_unbound(Nsyn,Nbound,y,dt);

    if (rdm_var<proba_bound) return +1;
    else if (rdm_var <proba_bound+proba_unbound) return -1;
    else return 0;
}

double dySyn(int Nsnare, int Nc, int Nbound, double y, double dt){
    return (F_snare(Nsnare,Nc,y)+F_fusion(y)+Nbound*f_syn(y))*dt+F_white_noise()*sqrt(dt);
}
