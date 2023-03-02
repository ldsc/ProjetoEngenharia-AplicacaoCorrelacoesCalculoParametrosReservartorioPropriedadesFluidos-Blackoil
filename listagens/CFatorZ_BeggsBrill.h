#ifndef CFatorZ_BeggsBrill_h
#define CFatorZ_BeggsBrill_h

#include <iostream>
#include <vector>

#include "CFatorZComp.h"

/**
@brief Classe responsavel pelo calculo do Fator Z de compressibilidade do gas pela correlacao Beggs e Brill
@class CFatorZ_BeggsBrill
@file CFatorZ_BeggsBrill.h
 */
class CFatorZ_BeggsBrill : public CFatorZComp       ///Herdeira da classe CFatorZComp
{

///Atributos
private:
    ///Parametros da formula de Beggs e Brill(nao variam com a pressao)
    double a, c, d;
    /// Vetor de Paramentro de Beggs e Brill (varia com a pressao)
    std::vector<double> b;

///Metodos
public:
    ///Construtor default
    CFatorZ_BeggsBrill  () {};
    ///Destrutor
    ~CFatorZ_BeggsBrill () {};

    ///Metodo para calculo do fator Z pela correlacao Beggs e Brill
    std::vector<double> Z (CSutton& prtr);
};

#endif // CFatorZ_BeggsBrill_h
