#include <cmath>

#include "CBo_Standing.h"

/**
@class CBo_Standing
@file CBo_Standing.cpp
 */
using namespace std;

/// Metodo para calculo do Bo no ponto de bolha pela correlacao Standing
double CBo_Standing::Bob(CFluidoBlackOil& fluido){

    bob= 0.972 + 1.47*pow(10.0, -4.0)*pow((fluido.rsb*(pow((fluido.dg/fluido.d_o), 0.5))+1.25*fluido.temp), 1.175);

    return bob;
}

