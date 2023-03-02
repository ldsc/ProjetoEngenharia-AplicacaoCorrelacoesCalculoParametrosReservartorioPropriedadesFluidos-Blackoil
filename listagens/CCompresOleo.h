#ifndef CCompresOleo_h
#define CCompresOleo_h

#include <iostream>
#include <vector>

#include "CFluidoBlackOil.h"
#include "CRazaoSolubilidade.h"

/**
@brief Classe responsavel pelo calculo da Compressibilidade do Oleo
@class CCompresOleo
@file CCompresoleo.h
 */
class CCompresOleo {

///Atributos
public:
  /// Vetor de compressibilidade do oleo
  std::vector<double> vco;

///Metodos
public:
    ///Construtor default
   CCompresOleo   (){};
   ///Destrutor
    ~CCompresOleo (){};

    /// Metodos get e set
    void Vco(std::vector<double> _vco) {vco = _vco;}
    std::vector<double> Vco()          {return vco;}

    /// Metodo para calculo da compressibilidade do oleo
    std::vector<double> Co(CFluidoBlackOil&, CRazaoSolubilidade&) {return vco; }

    /// Metodo para gerar grafico
    void Plot(CFluidoBlackOil& fluido);

};
#endif // CCompres_Oleo_h
