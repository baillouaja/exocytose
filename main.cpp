#include "std_include.h"
#include <ctime>
#include <iomanip>

int main()
{
    /* Parameters */
    srand(time(NULL));
    double dt=pow(10,-5);
    int N;
    int sampling=10000;
    int Nsnare;
    int Nsyn;
    int Nexp=500;
    omp_set_num_threads(8);

    //y_Nc_function_of_t(N,dt,sampling=1000);
    //convergence_tau_N(N=2,Nexp=300);
    //convergence_tau_N(N=3,Nexp=1000);
    //convergence_tau_N(N=4,Nexp=300);
    //convergence_tau_N(N=5,Nexp=300);
    //tau1_tau(N=2,dt,Nexp=500);
    tau1_tau(N=3,dt,Nexp=5000);
    //tau1_tau(N=4,dt,Nexp=500);
    //tau1_tau(N=5,dt,Nexp=500);
    //tau1_tau(N=6,dt,Nexp=500);
//y_Nc_function_of_t(int Nsnare, int Nsyn, double dt, int sampling)
//y_Nc_function_of_tSyn(5, 3, dt, sampling);
    //tau_function_of_N_dtSyn( Nsnare=4, Nsyn=3, dt, Nexp=100);
    //tau_function_of_N_dtSyn( Nsnare=5, Nsyn=3, dt, Nexp=500);
    //tau_function_of_N_dtSyn( Nsnare=6, Nsyn=3, dt, Nexp=500);
    //tau_function_of_N_dtSyn( Nsnare=7, Nsyn=3, dt, Nexp=500);

    /*vector<double> tab;
    vector<double> avg_sigma;
    fillTab1DFromFile(tab,"datas/archives/convergence/3snare/tau_with_3snares_and_dt_power-5.dat");
    avg_sigma=AvgSigmaTab1D(tab);
    cout << "Nelement : " << avg_sigma[0] << " moyenne : " <<avg_sigma[1] << " sigma_up : " << avg_sigma[2] << " " << " sigma_down : " << avg_sigma[3]<< endl;
    */

    /*vector<double> tab;
    fillTab1DFromFile(tab,"datas/tau_with_3snares.dat");
    ostringstream filename;
    filename << "datas/tau_histo_3snares.dat";
    ofstream file(filename.str().c_str());

    vector<vector<double> > histo=Histogramme(50, 700, tab);

    for(int i=0;i<histo.size();i++)
    {
        cout << histo[i][0] << " " << histo[i][1] << endl;
        file << histo[i][0] << " " << histo[i][1] << endl;
    }*/

    //energy_landscape(10,6);
    return 0;
}


