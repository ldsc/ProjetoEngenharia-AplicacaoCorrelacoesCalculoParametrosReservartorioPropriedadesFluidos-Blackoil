#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "CFluidoBlackOil.h"
#include "CPressaoBolha.h"
#include "CPb_Standing.h"
#include "CPb_VasquezBeggs.h"
#include "CRazaoSolubilidade.h"
#include "CRs_Standing.h"
#include "CRs_VasquezBeggs.h"
#include "CBoFatorVolFormacaoOleo.h"
#include "CBo_Standing.h"
#include "CBo_VasquezBeggs.h"
#include "CCompresOleo.h"
#include "CCo_VasquezBeggs.h"
#include "CFatorZComp.h"
#include "CSutton.h"
#include "CFatorZ_Papay.h"
#include "CFatorZ_BeggsBrill.h"
#include "CBgFatorVolFormacaoGas.h"

using namespace std;

/**
@brief Classe que simula o calculo de todos as propriedades do fluido blackoil
@class CSimuladorBlackOil
@file CSimuladorBlackOil.h
 */
class CSimuladorBlackOil {
///Atributos
public:
    ///Objeto da classe CFluidoBlackOil
    CFluidoBlackOil fblackoil;
    ///Objeto da classe CPb_Standing
    CPb_Standing standing_pb;
    ///Objeto da classe CPb_VasquezBeggs
    CPb_VasquezBeggs vb_pb;
    ///Objeto da classe CRs_Standing
    CRs_Standing standing_rs;
    ///Objeto da classe CRs_VasquezBeggs
    CRs_VasquezBeggs vb_rs;
    ///Objeto da classe CBo_Standing
    CBo_Standing standing_bo;
    ///Objeto da classe CBo_VasquezBeggs
    CBo_VasquezBeggs vb_bo;
    ///Objeto da classe CCo_VasquezBeggs
    CCo_VasquezBeggs vb_co;
    ///Objeto da classe CSutton
    CSutton sutton_prtr;
    ///Objeto da classe CFatorZ_Papay
    CFatorZ_Papay papay_z;
    ///Objeto da classe CFatorZ_BeggsBrill
    CFatorZ_BeggsBrill bb_z;
    ///Objeto da classe CFatorVolumeFormacaoGas
    CBgFatorVolFormacaoGas bg;

///Metodos
public:
    ///Construtor default
    CSimuladorBlackOil () {};
    ///Destrutor
    ~CSimuladorBlackOil() {};

///Menu de execucao
int Executar();

/// Metodo que solicita a entrada de dados pelo teclado ou pelo disco
void EntradadeDados();

///Metodo que calcula a pressao de bolha
void CalculoPressaoBolha();

///Metodo que calcula a razao de solubilidade
void CalculoRazaodeSolubilidade();

///Metodo que calcula o fator volume de formacao do oleo
void CalculoFatorVolumeFormacaoOleo();

///Metodo que calcula a compressibilidade do oleo
void CalculoCompressibilidadeOleo();

///Metodo que calcula o fator de compressibilidade do gas Z
void CalculoFatordeCompressibilidadeZ();

///Metodo que calcula o fator volume de formacao do gas
void CalculoFatorVolumeFormacaoGas();

};
