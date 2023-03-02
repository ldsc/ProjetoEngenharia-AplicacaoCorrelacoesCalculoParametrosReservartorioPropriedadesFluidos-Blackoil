#include <cmath>

#include "CPb_VasquezBeggs.h"
#include "CSimuladorBlackOil.h"

/**
@class CPb_VasquezBeggs
@file CPb_VasquezBeggs.cpp
 */
using namespace std;

 /// Metodo para calculo da pressão de bolha usando a correlação Vasquez e Beggs
double CPb_VasquezBeggs::Pb(CFluidoBlackOil& fluido){
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

    pb=pow((fluido.rsb/(c1*fluido.dgs* exp((c3*fluido.api)/(fluido.temp+459.67)))),(1.0/c2));

    return pb;
}
