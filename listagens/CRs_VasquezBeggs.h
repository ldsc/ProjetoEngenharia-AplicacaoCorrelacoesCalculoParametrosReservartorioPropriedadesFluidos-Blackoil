#ifndef CRs_VasquezBeggs_h
#define CRs_VasquezBeggs_h

#include "CRazaoSolubilidade.h"
#include "C3Parametros.h"

/**
@brief Classe responsavel pelo calculo da Razao de solubilidade pela correlacao Vasquez e Beggs
@class CRs_VazquezBeggs
@file CRs_VasquezBeggs.h
 */
class CRs_VasquezBeggs: public CRazaoSolubilidade, C3Parametros ///Herdeira das classes CRazaoSolubilidade e C3Parametros
{

///Metodos
public:
    ///Construtor default
    CRs_VasquezBeggs  () {};
    ///Destrutor
    ~CRs_VasquezBeggs () {};

    /// Metodo para calculo da razao de solubilidade pela correlacao de Vasquez e beggs
    std::vector<double> Rs(CFluidoBlackOil& fluido, CPressaoBolha& cpb);

};

#endif // CRs_VasquezBeggs_h
