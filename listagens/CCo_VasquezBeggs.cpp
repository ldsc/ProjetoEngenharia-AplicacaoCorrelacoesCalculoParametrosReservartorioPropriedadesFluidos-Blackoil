#include "CCo_VasquezBeggs.h"

/**
@class CBo_VasquezBeggs
@file CBo_VasquezBeggs.cpp
 */
using namespace std;

/// Metodo para calculo do Co pela correlacao Vasquez e Beggs
vector<double> CCo_VasquezBeggs:: Co (CFluidoBlackOil& fluido,CRazaoSolubilidade& crs) {
    vco.resize(fluido.vpressao.size()); //mesmo tamanho

for (int i=0; i<fluido.vpressao.size(); i++){
        vco[i]= ( -1433.0 + 5.0*crs.vrs[i] + 17.2*fluido.temp - 1180.0*fluido.dgs + 12.61*fluido.api) / (fluido.vpressao[i] * 100000.0);
        }
    return vco;
}
