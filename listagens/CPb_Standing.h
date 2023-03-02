#ifndef CPb_Standing_h
#define CPb_Standing_h

#include "CPressaoBolha.h"
#include "CFluidoBlackOil.h"

/**
@brief Classe responsavel pelo calculo da Pressao de bolha pela correlacao Standing
@class CPb_Standing
@file CPb_Standing.h
 */
class CPb_Standing : public CPressaoBolha ///Herdeira da classe CPressaoBolha
{

///Metodos
public:
    ///Construtor default
    CPb_Standing () {};
    ///Destrutor
    ~CPb_Standing () {};

    /// Metodo para calculo da pressao de bolha usando a correlacao Standing
    double Pb(CFluidoBlackOil& fluido);

};

#endif // CPb_Standing_h
