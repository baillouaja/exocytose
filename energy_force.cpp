#include "std_include.h"

double phi(double y, int N_snare, int N_site)
{
    return E_free(N_snare,y)+J_syn(N_site,y)+E_fusion(y);
}

double J_syn(int N, double y){
    return -N*log(1+exp(-e_syn(y)));
}
double E_free(int N, double y){
    return -N*log(exp(-e_c(y))+exp(-e_n(y)));
}

double e_syn(double y){
    if(y<y_syn)
        return k_syn*0.5*(y-y_syn)*(y-y_syn)+e_bond;
    else
        return e_bond;
}

double f_syn(double y){
    if(y<y_syn)
        return -k_syn*(y-y_syn);
    else
        return 0;
}

double e_n(double y){
    return kn*0.5*(y-1.0)*(y-1.0)+e0;
}
double f_n(double y){
    return -kn*(y-1.0);
}

double e_c(double y){
    return kc*0.5*y*y;
}
double f_c(double y){
    return -kc*y;
}

double E_snare(int N, double Nc, double y){
    return Nc*e_c(y)+(N-Nc)*e_n(y);
}
double F_snare(int N, int Nc, double y){
    return Nc*f_c(y)+(N-Nc)*f_n(y);
}

double E_fusion(double y){
    return ef*exp(-(y-yf)*(y-yf)/(2.0*sigmaf*sigmaf));
}
double F_fusion(double y){
    return (y-yf)/(sigmaf*sigmaf)*E_fusion(y);
}

double F_white_noise(){
    return rdm_gauss(1)*sqrt(2);
}
