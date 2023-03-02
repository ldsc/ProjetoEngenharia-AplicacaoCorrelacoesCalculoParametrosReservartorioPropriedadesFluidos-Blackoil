#ifndef CPb_VasquezBeggs_h
#define CPb_VasquezBeggs_h

#include "CPressaoBolha.h"
#include "C3Parametros.h"

/**
@brief Classe responsavel pelo calculo da Pressao de bolha pela correlacao Vasquez e Beggs
@class CPb_VasquezBeggs
@file CPb_VasquezBeggs.h
 */
class CPb_VasquezBeggs: public CPressaoBolha , C3Parametros ///Herdeira das classes CPressaBolha e C3Parametros
{
///Metodos
public:
    ///Construtor default
    CPb_VasquezBeggs() {} ;
    ///Destrutor
    ~CPb_VasquezBeggs () {};

    ///Metodo para calculo da pressao de bolha usando a correlacao Vasquez e Beggs
   double Pb(CFluidoBlackOil& fluido);

};

#endif // CPb_VasquezBeggs_h
