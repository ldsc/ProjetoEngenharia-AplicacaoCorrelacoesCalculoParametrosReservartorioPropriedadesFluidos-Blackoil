#ifndef CBo_Standing_h
#define CBo_Standing_h

#include "CBoFatorVolFormacaoOleo.h"

/**
@brief Classe responsavel pelo calculo do Fator volume de formacao do oleo pela correlacao Standing
@class CBo_Standing
@file CBo_Standing.h
 */
class CBo_Standing : public CBoFatorVolFormacaoOleo    ///Herdeira da classe CFatorVolumeFormacaoOleo
{
///Metodos
public:
    ///Construtor default
    CBo_Standing (){};
    ///Destrutor
    ~CBo_Standing(){};

    /// Metodo para calculo do Bo no ponto de bolha pela correlacao Standing
    double Bob(CFluidoBlackOil& fluido);
};

#endif // CBo_Standing_h
