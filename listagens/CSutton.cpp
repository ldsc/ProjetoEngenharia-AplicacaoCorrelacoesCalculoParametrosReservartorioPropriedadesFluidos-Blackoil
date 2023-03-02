#include "CSutton.h"

/**
@class CSutton
@file CSutton.cpp
 */
using namespace std;

///Metodo para o calculo da pressao pseudo-reduzida pela correlacao Sutton
vector<double> CSutton :: Pr (CFluidoBlackOil& fluido) {
vpr.resize(fluido.vpressao.size()); //mesmo tamanho

for (int i=0; i<fluido.vpressao.size(); i++){
        vpr[i] = fluido.vpressao[i]/(671.1 + (14.0 - 34.3*fluido.dg)*fluido.dg);
        }
    return vpr;
}

///Metodo para o calculo da temperatura pseudo-reduzida pela correlacao Sutton
double CSutton :: Tr(CFluidoBlackOil& fluido) {

    tr = (fluido.temp + 459.67) / (120.1 + (429.0 - 62.9*fluido.dg)*fluido.dg);
    return tr;
}
