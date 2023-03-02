#ifndef CCo_VasquezBeggs_h
#define CCo_VasquezBeggs_h

#include <iostream>
#include <vector>

#include "CCompresOleo.h"

/**
@brief Classe responsavel pelo calculo da compressibilidade do oleo pela correlacao Vasquez e Beggs
@class CCo_VazquezBeggs
@file CCo_VasquezBeggs.h
 */
class CCo_VasquezBeggs: public CCompresOleo {       ///Herdeira da classe CCompresOleo

///Metodos
public:
    ///Construtor default
    CCo_VasquezBeggs  () {};
    ///Destrutor
    ~CCo_VasquezBeggs () {};

 /// Metodo para calculo do Co pela correlacao Vasquez e Beggs
 std::vector<double> Co (CFluidoBlackOil& fluido,CRazaoSolubilidade& crs);

};
#endif // CCo_VasquezBeggs_h
