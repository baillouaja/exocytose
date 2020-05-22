#include "std_include.h"

void updateSystem(int N, int &Nc, double &y, double &t, double dt)
{
    int dNc_var;
    double dy_var;
    dNc_var=dNc(N,Nc,y,dt);
    dy_var=dy(N,Nc,y,dt);
    Nc+=dNc_var;
    y+=dy_var;
    t+=dt;
}

void y_Nc_function_of_t(int N, double dt, int sampling)
{
    /* Ouverture du fichier de sauvegarde */
    ostringstream filename;
    filename << "datas/y_Nc_function_of_t_with_" << N << "snares.dat";
    ofstream file(filename.str().c_str());

    /* Initialization */
    int Nc=0;
    double y=1.0;
    double t=0.0;
    int counter=1;
    file << t*tau_eta << " " << y*a << " " << Nc << endl;

    while(y>yf)
    {
        updateSystem(N,Nc,y,t,dt);
        counter++;
        if(counter%sampling==0)
        {
            counter=1;
            file << t*tau_eta << " " << y*a << " " << Nc << endl;
        }
    }

    file << t*tau_eta << " " << y*a << " " << Nc << endl;

    cout << t*tau_eta << endl;
}

void tau1_tau(int N, double dt, int Nexp)
{
    /* Ouverture du fichier de sauvegarde */
    ostringstream filename;
    filename << "datas/tau_with_" << N << "snares.dat";
    ofstream file(filename.str().c_str());

    /* Declaration */
    #pragma omp parallel for schedule(dynamic)
    for(int i=0;i<Nexp;i++)
    {
        #pragma omp critical
        {
            cout << "Début :" << i << endl;
        }

        /* Initialization */
        int Nc=0;
        double y=1.0,t=0.0,tau1=0.0;


        while(y>yf)
        {
            updateSystem(N,Nc,y,t,dt);
            if(tau1==0.0 and y<y_transition)
                tau1=t;
        }

        #pragma omp critical
        {
            cout << "Fin :"<< i << endl;
            file << i << " " << tau1*tau_eta << " " << t*tau_eta << endl;
        }
    }
}

void tau_function_of_N_dt(int N, double dt_power, int Nexp)
{
    double dt=pow(10,dt_power);

    /* Ouverture du fichier de sauvegarde */
    ostringstream filename;
    filename << "datas/tau_with_" << N << "snares_and_dt_power" << dt_power << ".dat";
    ofstream file(filename.str().c_str());

    /* Declaration */
    #pragma omp parallel for schedule(dynamic)
    for(int i=0;i<Nexp;i++)
    {
        /* Initialization */
        int Nc=0;
        double y=1.0;
        double t=0.0;

        while(y>yf)
        {
            updateSystem(N,Nc,y,t,dt);
        }
        #pragma omp critical
        {
            file << i << " " << t*tau_eta << endl;
            cout << i << " " << t*tau_eta << " " << dt << endl;
        }
    }
}
void convergence_tau_N(int N, int Nexp)
{
    for(double dt_power=6.5; dt_power<=7; dt_power+=0.5)
        tau_function_of_N_dt(N,-dt_power,Nexp);
}

void energy_landscape(int N_snare, int N_ads)
{
    /* Ouverture du fichier de sauvegarde */
    ostringstream filename;
    filename << "datas/energy_landscape_" << N_snare << "snares" << N_ads << "Nads " << "k_syn" << k_syn << "y_syn" << y_syn_std_unit << "e_bond" << e_bond_std_unit << ".dat";
    ofstream file(filename.str().c_str());

    for(double y=0;y<1.5;y+=0.01)
        file << y << " " << E_free(N_snare,y)+J_syn(N_ads,y)+E_fusion(y) << " " << E_free(N_snare,y) << " " << J_syn(N_ads,y) << " " << E_fusion(y) << endl;
}
