#include "std_include.h"

void fillTab1DFromFile(vector<double>& tab, char* filename)
{
    int id;
    double temp2;
    double temp;
    ifstream fichier(filename);
    while(!(fichier.eof()))
    {
        fichier >> id >> temp2 >> temp;
        cout << id << endl;
        //cout << id << " " << id << " " << temp << endl;
        tab.push_back(temp);

    }
}

vector<double> AvgSigmaTab1D(vector<double> const& tab)
{
    vector<double> answer;
    int N=tab.size();
    long double sum=0;
    double moyenne;
    double sigma_up;
    double sigma_down;
    int counter=0;
    for(int i=0; i<N;i++)
    {
        sum+=tab[i];
    }
    moyenne=sum/N;

    sum=0;
    counter=0;
    for(int i=0;i<N;i++)
    {
        if (tab[i]>moyenne)
        {
            counter++;
            sum+=(tab[i]-moyenne)*(tab[i]-moyenne);
        }
    }
    sigma_up=sqrt(sum/counter);

    sum=0;
    counter=0;
    for(int i=0;i<N;i++)
    {
        if (tab[i]<moyenne)
        {
            counter++;
            sum+=(tab[i]-moyenne)*(tab[i]-moyenne);
        }
    }
    sigma_down=sqrt(sum/counter);

    answer.push_back(N);
    answer.push_back(moyenne);
    answer.push_back(sigma_up);
    answer.push_back(sigma_down);
    return answer;
}

vector<vector<double> > Histogramme(int bins, double valMax, vector<double> const& tab)
{
    vector<vector<double> > histo;
    int N=tab.size();

    for(int i=0;i<(valMax/bins);i++)
    {
        histo.push_back(vector<double>(2));
        histo[i][0]=bins*i+bins/2;
        histo[i][1]=0;
    }

    for(int i=0;i<N;i++)
    {
        if(tab[i] <= valMax)
        histo[tab[i]/bins][1]++;
    }

    return histo;

}
