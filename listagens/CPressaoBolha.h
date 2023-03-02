#ifndef CPressaoBolha_h
#define CPressaoBolha_h

#include "CFluidoBlackOil.h"

/**
@brief Classe responsavel pelo calculo da Pressao de bolha
@class CPressaoBolha
@file CPressaoBolha.h
 */
class CPressaoBolha  {

///Atributos
public:
    /// Pressao de bolha
    double pb;

 ///Metodos
public:
    ///Construtor default
    CPressaoBolha  () {};
    ///Destrutor
    ~CPressaoBolha () {};

    /// Metodos get e set
    void Pb(double _pb) {pb = _pb;}
    double Pb()         {return pb;}

    /// Metodo para calculo da pressão de bolha
    double Pb(CFluidoBlackOil&) { return pb; }

};

#endif // CPressaoBolha_h
