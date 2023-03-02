#include <iostream>
#include <cmath>

#include "CFatorZ_BeggsBrill.h"

/**
@class CFatorZ_BeggsBrill
@file CFatorZ_BeggsBrill.cpp
 */
using namespace std;

///Metodo para calculo do fator Z pela correlacao Beggs e Brill
vector<double> CFatorZ_BeggsBrill :: Z (CSutton& prtr) {
        /// Calculo dos parametros independentes da pressao
        a = 1.39 * (pow((prtr.tr - 0.92), 0.5)) - 0.36 * prtr.tr - 0.1;
        c = 0.132-0.32*log10(prtr.tr);
        d = pow(10, (0.3106 - (0.49 * prtr.tr) + (0.1824 * prtr.tr * prtr.tr)));

            b.resize(prtr.vpr.size());  //mesmo tamanho
            vz.resize(prtr.vpr.size()); //mesmo tamanho
        /// Calculo do paramentro dependente da pressao e do Fator Z
for (int i=0; i<prtr.vpr.size(); i++){
        b[i] = ( 0.62 - (0.23 * prtr.tr)) * prtr.vpr[i] + ((0.066/(prtr.tr - 0.86)) - 0.037) * prtr.vpr[i] * prtr.vpr[i] + (0.32 / (pow(10, (9 *(prtr.tr-1))))) * (pow(prtr.vpr[i],6));

        vz[i] =  a + ((1-a)/ exp(b[i])) + (c * pow(prtr.vpr[i],d));

    }
    return vz;
}
