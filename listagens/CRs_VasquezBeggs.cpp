#include <vector>
#include <cmath>

#include "CRs_VasquezBeggs.h"

/**
@class CRs_VasquezBeggs
@file CRs_VasquezBeggs.cpp
 */
using namespace std;

/// Metodo para calculo da pressão de bolha usando a correlação Vasquez e Beggs
vector<double> CRs_VasquezBeggs::Rs(CFluidoBlackOil& fluido, CPressaoBolha& cpb){
    /// Seta os parametros da correlacao C3Parametros
    if (fluido.api <= 30.0){
        c1 = 0.0362;
        c2 = 1.0937;
        c3 = 25.724;
    }
    else {
        c1 = 0.0178;
        c2 = 1.187;
        c3 = 23.931;
    }

    vrs.resize(fluido.vpressao.size()); //mesmo tamanho

for (int i=0; i<fluido.vpressao.size(); i++){
        /// Para pressoes abaixo do Pb a razao de solubilidade e calculada, para pressoes acima do Pb o Rs se mantem constante e igual ao Rsb
        if (fluido.vpressao[i] <= cpb.pb){
        vrs[i] = c1*fluido.dgs*pow(fluido.vpressao[i], c2)*exp((c3*fluido.api)/(fluido.temp+459.67));
        }
       else
          vrs[i] = fluido.rsb;

    }
    return vrs;
}
