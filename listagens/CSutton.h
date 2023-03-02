#ifndef CSutton_h
#define CSutton_h

#include <iostream>
#include <vector>

#include "CFluidoBlackOil.h"

/**
@brief Classe responsavel pelo calculo da Pressao e Temperatura pseudo-reduzida do gas pela correlacao Sutton
@class CSutton
@file CSutton.h
 */
class CSutton {
///Atributos
public:
    /// Vetor de Pressao pseudo-reduzida
    std::vector<double> vpr;
    /// Temperatura pseudo-reduzida
    double tr;

///Metodos
public:
    ///Construtor default
    CSutton  () {};
    ///Destrutor
    ~CSutton () {};

    /// Metodos get e set
    void Vpr(std::vector<double> _vpr) {vpr = _vpr;}
    std::vector<double> Vpr()          {return vpr;}

    void Tr(double _tr)     {tr = _tr;}
    double Tr()             {return tr;}

    ///Metodo para o calculo da pressao pseudo-reduzida pela correlacao Sutton
    std::vector<double> Pr (CFluidoBlackOil& fluido);

    ///Metodo para o calculo da temperatura pseudo-reduzida pela correlacao Sutton
    double Tr (CFluidoBlackOil& fluido);

};
#endif // CSutton_h
