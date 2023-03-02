#ifndef CFatorZComp_h
#define CFatorZComp_h


#include <iostream>
#include <vector>

#include "CFluidoBlackOil.h"
#include "CSutton.h"

/**
@brief Classe responsavel pelo calculo do Fator Z de compressibilidade do gas
@class CFatorZComp
@file CFatorZComp.h
 */
class CFatorZComp {
///Atributos
public:
    ///Vetor de Fator Z
    std::vector<double> vz;

///Metodos
public:
    ///Construtor default
    CFatorZComp ()  {};
    ///Destrutor
    ~CFatorZComp () {};

    /// Metodos get e set
    void Vz(std::vector<double> _vz) {vz = _vz;}
    std::vector<double> Vz()         {return vz;}

    ///Metodo para o calculo do Fator de compressibilidade do gas Z
    std::vector<double> Vz(CSutton&) {return vz;}

    /// Metodo para gerar grafico
    void Plot(CFluidoBlackOil&);

};

#endif // CFatorZComp_h
