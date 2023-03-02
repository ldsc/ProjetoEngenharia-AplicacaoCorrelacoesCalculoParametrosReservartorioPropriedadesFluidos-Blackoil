#ifndef CRazaoSolubilidade_h
#define CRazaoSolubilidade_h

#include <vector>

#include "CFluidoBlackOil.h"
#include "CPressaoBolha.h"

/**
@brief Classe responsavel pelo calculo da Razao de Solubilidade
@class CRazaoSolubilidade
@file CRazaoSolubilidade.h
 */
class CRazaoSolubilidade {

///Atributo
public:
    /// Vetor de Razao de Solubilidade
    std::vector <double> vrs;

///Metodos
public:
    ///Construtor default
    CRazaoSolubilidade  () {};
    ///Destrutor
    ~CRazaoSolubilidade () {};

    /// Metodos get e set
    void Vrs(std::vector<double> _vrs) {vrs = _vrs;}
    std::vector<double> Vrs()          {return vrs;}

    /// Metodo para calculo da razao de solubilidade
    std::vector<double> Rs(CFluidoBlackOil&, CPressaoBolha&) {return vrs; }

    /// Metodo para gerar grafico
    void Plot(CFluidoBlackOil& fluido);

};
#endif // CRazaoSolubilidade_h
