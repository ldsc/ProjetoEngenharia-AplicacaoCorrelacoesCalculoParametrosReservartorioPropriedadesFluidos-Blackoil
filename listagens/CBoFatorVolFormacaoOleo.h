#ifndef CBoFatorVolFormacaoOleo_h
#define CBoFatorVolFormacaoOleo_h

#include <vector>

#include "CFluidoBlackOil.h"
#include "CRazaoSolubilidade.h"
#include "CCompresOleo.h"
#include "CPressaoBolha.h"

/**
@brief Classe responsavel pelo calculo do Fator volume de formacao do oleo
@class CBoFatorVolFormacaoOleo
@file CBoFatorVolFormacaoOleo.h
 */
class CBoFatorVolFormacaoOleo{

///Atributos
public:
    /// Fator volume de formacao no ponto de bolha
    double bob;
    /// Vetor de Fator volume de formacao em outros pontos
    std::vector<double> vbo;

///Metodos
public:
    ///Construtor default
    CBoFatorVolFormacaoOleo  (){};
    ///Destrutor
    ~CBoFatorVolFormacaoOleo (){};

    /// Metodos get e set
    void Bob(double _bob) {bob = _bob;}
    double Bob()         {return bob;}

    void Vbo(std::vector<double> _vbo) {vbo = _vbo;}
    std::vector<double> Vbo()          {return vbo;}


    /// Metodo para calculo do Bo no ponto de bolha
    double Bob(CFluidoBlackOil&) { return bob; }

    /// Metodo para calculo do Bo em varios pontos
    std::vector<double> Bo(CFluidoBlackOil&, CPressaoBolha&, CRazaoSolubilidade&, CCompresOleo&) { return vbo; }

    /// Metodo para gerar grafico
    void Plot(CFluidoBlackOil& fluido);
};

#endif // CBoFatorVolFormacaoOleo_h
