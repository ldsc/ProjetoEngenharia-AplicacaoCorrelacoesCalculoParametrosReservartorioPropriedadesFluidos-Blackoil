#include <cmath>

#include "CBo_VasquezBeggs.h"

/**
@class CBo_VasquezBeggs
@file CBo_VasquezBeggs.cpp
 */
using namespace std;

/// Metodo para calculo do Bo pela correlacao Vasquez e Beggs
vector<double> CBo_VasquezBeggs::Bo(CFluidoBlackOil& fluido, CPressaoBolha& cpb, CRazaoSolubilidade& crs, CCompresOleo& cco){
    /// Seta os parametros da correlacao C3Parametros
    if (fluido.api <= 30.0){
        c1 = 0.0004677;
        c2 = 0.00001751;
        c3 = -0.00000001811;
    }
    else {
        c1 = 0.0004677;
        c2 = 0.000011;
        c3 = -0.000000001377;
    }

        /// Calculo do Bo no ponto de bolha
        bob = 1+c1*fluido.rsb+c2*(fluido.temp-60.0)*(fluido.api/fluido.dgs)+c3*fluido.rsb*(fluido.temp-60.0)*(fluido.api/fluido.dgs);

    vbo.resize(fluido.vpressao.size()); //mesmo tamanho

    /// Calculo do Bo acima do ponto de bolha e diferente do calculo para abaixo do ponto de bolha
    for (int i=0; i<fluido.vpressao.size(); i++){

        ///Verifica se a pressao esta acima ou abaixo do ponto de bolha
        if (fluido.vpressao[i] <= cpb.pb)
            vbo[i] = 1.0+c1*crs.vrs[i]+c2*(fluido.temp-60.0)*(fluido.api/fluido.dgs)+c3*crs.vrs[i]*(fluido.temp-60.0)*(fluido.api/fluido.dgs);

        else
            vbo[i] = bob*exp(cco.vco[i]*(cpb.pb - fluido.vpressao[i]));
    }

    return vbo;
}
