#include <vector>
using namespace std;
#ifndef RESULTAT_H_INCLUDED
#define RESULTAT_H_INCLUDED

void fillTab1DFromFile(vector<double>& tab, char* filename);
vector<double> AvgSigmaTab1D(vector<double> const& tab);
vector<vector<double> > Histogramme(int bins, double valMax, vector<double> const& tab);

#endif // RESULTAT_H_INCLUDED
