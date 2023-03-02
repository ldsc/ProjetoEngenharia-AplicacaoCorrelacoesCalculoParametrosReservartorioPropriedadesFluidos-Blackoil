#ifndef C3Parametros_h
#define C3Parametros_h

/**
@brief Classe responsavel pelos parametros da correlacao Vasquez e Beggs
@class C3Parametros
@file C3Parametros.h
 */
class C3Parametros{
///Atributos
protected:
    ///Parametros
    double c1, c2, c3;

/// Metodos set e get
public:
    void C1(double _c1){
       c1=_c1;
    };
    double C1(){
        return c1;
    };
    void C2(double _c2){
        c2=_c2;
    };
    double C2(){
        return c2;
    };
    void C3(double _c3){
        c3=_c3;
    };
    double C3(){
        return c3;
    };

};
#endif

