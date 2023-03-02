#ifndef CFluidoBlackOil_h
#define CFluidoBlackOil_h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/**
@brief Classe que representa as caracteristicas do fluido blackoil
@class CFluidoBlackOil
@file CFluidoBlackOil.h
 */
class CFluidoBlackOil {

///Atributos
public:
    /// Grau API do oleo
    double api;
    /// Temperatura do fluido
    double temp;
    /// Razao de solubilidade do gas no oleo no ponto de bolha
    double rsb;
    /// Pressao no ponto desejado
    double p;
    /// Pressao maxima do reservatorio
    double pmax;
    /// Variacao de pressao desejada
    double deltap;
    /// Densidade do gas no separador
    double dgs;
    /// Densidade do gas
    double dg;
    /// Densidade do oleo
    double d_o;
    /// Vetor com as pressoes
    std::vector<double> vpressao;

///Metodos
public:
    ///Construtor default
    CFluidoBlackOil(){};
    ///Destrutor
    ~CFluidoBlackOil (){};

    /// Metodo para criar o vetor de pressoes
   std::vector<double> Gera_vp (double p, double pmax, double deltap);

    /// Metodos set e get
    double P(){    return p;    }
    void P(double _p){        p=_p;    }

    double PMax(){    return pmax;    }
    void PMax(double _pm){        pmax=_pm;    }

    double API(){        return api;    }
    void API(double _API){        api=_API;    }

    double Temp(){        return temp;    }
    void Temp(double _Temp){        temp=_Temp;    }

    double Rsb(){        return rsb;    }
    void Rsb(double _Rsb){        rsb=_Rsb;    }

    double Dg(){        return dg;    }
    void Dg(double _Dg){        dg=_Dg;    }

    double Dgs(){        return dgs;    }
    void Dgs(double _Dgs){        dgs=_Dgs;    }

    double D_o(){        return d_o;    }
    void D_o(double _d_o){        d_o=_d_o;    }

    /// Sobrecarga de operadores >>, entrada de dados pelo disco e teclado
    friend std::istream& operator >> (std::istream& in, CFluidoBlackOil& obj);
    friend std::ifstream& operator >> (std::ifstream& fin, CFluidoBlackOil& obj);

};
#endif // CFluidoBlackOil_h
