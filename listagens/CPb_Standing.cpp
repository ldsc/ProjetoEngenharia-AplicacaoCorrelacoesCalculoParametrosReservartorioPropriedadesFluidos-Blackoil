#include <cmath>

#include "CPb_Standing.h"

/**
@class CPb_Standing
@file CPb_Standing.cpp
 */
using namespace std;

/// Metodo para calculo da pressao de bolha usando a correlação Standing
double CPb_Standing::Pb(CFluidoBlackOil& fluido){

pb =18.2*((1.0/(pow(10.0,(0.0125*fluido.api-0.00091*fluido.temp)))*(pow(fluido.rsb/fluido.dg,0.83)))-1.4);

return pb;

}

