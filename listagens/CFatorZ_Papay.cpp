#include <cmath>

#include "CFatorZ_Papay.h"

/**
@class CFatorZ_Papay
@file CFatorZ_Papay.cpp
 */
using namespace std;

///Metodo para calculo do fator Z pela correlacao Papay
std::vector<double> CFatorZ_Papay :: Z (CSutton& prtr){

vz.resize(prtr.vpr.size()); //mesmo tamanho

for (int i=0; i < prtr.vpr.size(); i++){
        vz[i] =  1 - (3.52 * prtr.vpr[i])/( pow(10.0, (0.9813* prtr.tr))) + (0.274 * prtr.vpr[i] * prtr.vpr[i]) / (pow(10.0,(0.8157* prtr.tr)));
    }

    return vz;
}
