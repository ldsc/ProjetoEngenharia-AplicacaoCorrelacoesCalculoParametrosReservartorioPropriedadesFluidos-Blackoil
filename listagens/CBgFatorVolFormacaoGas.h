#ifndef CBgFatorVolFormacaoGas_h
#define CBgFatorVolFormacaoGas_h

#include <vector>

#include "CFluidoBlackOil.h"
#include "CFatorZComp.h"

/**
@brief Classe responsavel pelo calculo do Fator volume de formacao do gas
@class CBgFatorVolFormacaoGas
@file CBgFatorVolFormacaoGas.h
 */

class CBgFatorVolFormacaoGas {
///Atributos
public:
    /// Vetor de Fator volume de formacao do gas Bg
    std::vector<double> vbg;

///Metodos
public:
    ///Construtor default
    CBgFatorVolFormacaoGas  () {};
    ///Destrutor
    ~CBgFatorVolFormacaoGas () {};

    /// Metodos get e set
    void Vbg(std::vector<double> _vbg) {vbg = _vbg;}
    std::vector<double> Vbg()         {return vbg;}

    /// Metodo para calcular o fator volume de formacao do gas
    std::vector<double> Bg (CFluidoBlackOil& fluido, CFatorZComp& fcz);

    /// Metodo para gerar grafico
    void Plot(CFluidoBlackOil& fluido);
};

#endif // CBgFatorVolFormacaoGas_h
