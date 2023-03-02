#ifndef CRs_Standing_h
#define CRs_Standing_h

#include "CRazaoSolubilidade.h"

/**
@brief Classe responsavel pelo calculo da Razao de Solubilidade pela correlacao Standing
@class CRs_Standing
@file CRs_Standing.h
 */
class CRs_Standing : public CRazaoSolubilidade  ///Herdeira da classe CRazaoSolubilidade
{

///Metodos
public:
    ///Construtor default
    CRs_Standing  () {};
    ///Destrutor
    ~CRs_Standing () {};

    /// Metodo para calculo da razao de solubilidade pela correlacao de Standing
    std::vector<double> Rs(CFluidoBlackOil& fluido, CPressaoBolha& cpb);
};

#endif // CRs_Standing_h
