#ifndef CBo_VasquezBeggs_h
#define CBo_VasquezBeggs_h

#include <vector>

#include "CBoFatorVolFormacaoOleo.h"
#include "C3Parametros.h"

/**
@brief Classe responsavel pelo calculo do Fator volume de formacao do oleo pela correlacao Vasquez e Beggs
@class CRs_VazquezBeggs
@file CRs_VasquezBeggs.h
 */
class CBo_VasquezBeggs: public CBoFatorVolFormacaoOleo, C3Parametros ///Herdeira das classes CFatorVolumeFormacaoOleo e C3Parametros
{
///Metodos
public:
    ///Construtor default
    CBo_VasquezBeggs () {} ;
    ///Destrutor
    ~CBo_VasquezBeggs() {} ;

    /// Metodo para calculo do Bo pela correlacao Vasquez e Beggs
    std::vector<double> Bo(CFluidoBlackOil& fluido, CPressaoBolha& cpb, CRazaoSolubilidade& crs, CCompresOleo& cco);

};
#endif // CBo_VasquezBeggs_h
