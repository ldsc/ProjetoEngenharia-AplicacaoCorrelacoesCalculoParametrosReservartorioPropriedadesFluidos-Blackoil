#include <vector>
#include <cmath>

#include "CRs_Standing.h"

/**
@class CRs_Standing
@file CRs_Standing.cpp
 */
using namespace std;

 /// Metodo para calculo da razao de solubilidade pela correlacao de Standing
vector<double> CRs_Standing:: Rs(CFluidoBlackOil& fluido, CPressaoBolha& cpb){
    vrs.resize(fluido.vpressao.size()); //mesmo tamanho

/// Para pressoes abaixo do Pb a razao de solubilidade e calculada, para pressoes acima do Pb o Rs se mantem constante e igual ao Rsb
for (int i=0; i<fluido.vpressao.size(); i++)
    {
        if (fluido.vpressao[i] <= cpb.pb){
            vrs[i] = fluido.dg*(pow(((fluido.vpressao[i]/18.2+1.4)*(pow(10.0, (0.0125*fluido.api-0.00091*fluido.temp)))), 1.2048));
            }
        else
          vrs[i] = fluido.rsb;
    }
    return vrs;
}
