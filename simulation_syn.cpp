#include "std_include.h"
#include <iomanip>
void updateSystemSyn(int Nsnare, int Nsyn, int &Nc, int &Nbound, double &y, double &t, double dt)
{
    int dNc_var,dNbound_var;
    double dy_var;
    dNc_var=dNc(Nsnare,Nc,y,dt);
    dy_var=dySyn(Nsnare,Nc,Nbound,y,dt);
    dNbound_var=dNbound(Nsyn,Nbound,y,dt);
    Nbound+=dNbound_var;
    Nc+=dNc_var;
    y+=dy_var;
    t+=dt;
}

void y_Nc_function_of_tSyn(int Nsnare, int Nsyn, double dt, int sampling)
{
    /* Ouverture du fichier de sauvegarde */
    ostringstream filename;
    filename << "datas/y_Nc_function_of_tSyn_with_" << Nsnare << "snares.dat";
    ofstream file(filename.str().c_str());

    /* Initialization */
    int Nc=0;
    int Nbound=Nsyn;
    double y=1.0;
    double t=0.0;
    int counter=1;
    file << t*tau_eta << " " << y << " " << Nc << " " << Nbound << " " << phi( y, Nsnare, Nsyn) << endl;

    while(y>yf)
    {
        updateSystemSyn(Nsnare,Nsyn,Nc,Nbound,y,t,dt);
        counter++;
        if(counter%sampling==0)
        {
            counter=1;
            cout << t*tau_eta << endl;
            file << t*tau_eta << " " << y << " " << Nc << " " << Nbound << " " << phi( y, Nsnare, Nsyn) << endl;
        }
    }

    file << t*tau_eta << " " << y << " " << Nc << " " << Nbound << " " << phi( y, Nsnare, Nsyn) << endl;

    cout << t*tau_eta << endl;
}

void tau_function_of_N_dtSyn(int Nsnare, int Nsyn, double dt, int Nexp)
{
    /* Ouverture du fichier de sauvegarde */
    ostringstream filename;
    filename << "datas/tau_with_" << Nsnare << "snares" << Nsyn << "syn.dat";
    ofstream file(filename.str().c_str());
    file << fixed << showpoint;
    file << setprecision(2);
    #pragma omp parallel for schedule(dynamic)
    for(int i=0;i<Nexp;i++)
    {
        /* Initialization */
        int Nc=Nsnare;
        int Nbound=Nsyn;
        double y=y_syn;
        double t=0.0;
        double tau1=0.0;
        double tau_s=0.0;

        while(y>yf)
        {
            updateSystemSyn(Nsnare,Nsyn,Nc,Nbound,y,t,dt);
            if(tau1==0.0 && Nc==Nsnare)
                tau1=t;
            if(tau_s==0.0 && Nbound==0)
                tau_s=t-tau1;
        }
        #pragma omp critical
        {
            cout << "Fin " << i << " tfusion=" << t*tau_eta << endl;
            file << i << " " << t*tau_eta << " " << tau1*tau_eta << " " << tau_s*tau_eta << endl;
        }
    }
}
