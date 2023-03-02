#ifndef CFatorZ_Papay_h
#define CFatorZ_Papay_h

#include "CFatorZComp.h"

/**
@brief Classe responsavel pelo calculo do Fator Z de compressibilidade do gas pela correlacao Papay
@class CFatorZ_Papay
@file CFatorZ_Papay.h
 */
class CFatorZ_Papay: public CFatorZComp     ///Herdeira da classe CFatorZComp
{
///Metodos
public:
    ///Construtor default
    CFatorZ_Papay  () {};
    ///Destrutor
    ~CFatorZ_Papay () {};

    ///Metodo para calculo do fator Z pela correlacao Papay
    std::vector<double> Z (CSutton& prtr);

};
#endif // CFatorZ_Papay_h
