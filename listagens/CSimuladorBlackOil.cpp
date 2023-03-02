#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "CSimuladorBlackOil.h"

/**
@class CSimuladorBlackOil
@file CSimuladorBlackOil.cpp
 */
using namespace std;

 string linha = "___________________________________________________________________________________ \n";

 ///Menu de execucao
int CSimuladorBlackOil:: Executar()
{
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << "|              UNIVERSIDADE ESTADUAL DO NORTE FLUMINENSE -DARCY RIBEIRO               |" << endl;
    cout << "|                       CENTRO DE CIENCIAS E TECNOLOGIA - CCT                         |" << endl;
    cout << "|             LABORATORIO DE ENGENHARIA E EXPLORACAO DE PETROLEO - LENEP              |" << endl;
    cout << "|                     DISCIPLINA: PROPRAMACAO PRATICA - PROJETO C++                   |" << endl;
    cout << "|                           PROFESSOR: ANDRE DUARTE BUENO                             |" << endl;
    cout << "|                          ALUNOS: JOAO BOSCO MACIEL FILHO                            |" << endl;
    cout << "|                              SUSANE CHELLI CAIRES GOIS                              |" << endl;
    cout << "|   PROGRAMA PARA CALCULO DE PARAMETROS DE RESERVATORIO USANDO A MODELAGEM BLACK-OIL  |" << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;

    ///Solicita a entrada de dados
    EntradadeDados();

    ///Gera o vetor de pressoes, seja de um ponto especifico ou de um intervalo
    fblackoil.Gera_vp(fblackoil.p, fblackoil.pmax, fblackoil.deltap);

    int resp;
    do {
        do{
    cout << linha;
    cout << linha;
    cout << "Qual parametro calcular:" << endl;
    cout << " 1 - Pressao de bolha - Pb " << endl;
    cout << " 2 - Razao de Solubilidade - Rs" << endl;
    cout << " 3 - Fator Volume de Formacao do Oleo - Bo" << endl;
    cout << " 4 - Compressibilidade do oleo - co" << endl;
    cout << " 5 - Fator de Compressibilidade do gas - Z" << endl;
    cout << " 6 - Fator Volume Formacao do Gas - Bg" << endl;
    cout << " 0 - Sair" << endl;
    cout << linha;
    cin >> resp; cin.get();

        if((resp < 0) || (resp > 6))
        {cout << "Opcao Invalida!" << endl;};

        }while ((resp < 0) && (resp > 6));

    switch (resp) {

case 1: CalculoPressaoBolha();                break;

case 2: CalculoRazaodeSolubilidade();         break;

case 3: CalculoFatorVolumeFormacaoOleo();     break;

case 4: CalculoCompressibilidadeOleo();       break;

case 5: CalculoFatordeCompressibilidadeZ();   break;

case 6: CalculoFatorVolumeFormacaoGas();      break;

case 0 : return 0;

    }
   } while (resp != 0);
}

/// Metodo que solicita a entrada de dados pelo teclado ou pelo disco
void CSimuladorBlackOil::EntradadeDados(){
    string nomearquivo;
    char opcao;
    do {
    cout << linha;
    cout << "Como deseja entrar com os dados: \n";
    cout << " 1 - Teclado \n";
    cout << " 2 - Arquivo de disco \n";
    cout << linha;
    cin >> opcao; cin.get();

    ///Entrada de dados pelo teclado
    if(opcao == '1'){
        cout << linha;
        cout << " Entrada de dados pelo teclado" << endl;
        cout << linha;
        cin >> fblackoil;}
    /// Entrada de dados pelo disco
    else if (opcao == '2'){
        cout << linha;
        cout << " Entrada de dados por arquivo de disco" << endl;
        cout << linha;
        cout << " Informe o nome do arquivo com a extensao (ex: .txt, .dat)" << endl;
        getline(cin, nomearquivo);
        ifstream fin;
        fin.open(nomearquivo.c_str());
        fin >> fblackoil;}
    /// Mensagem de erro se a escolha for errada
    if ((opcao != '1') && (opcao!= '2'))
    {cout << "Opcao Invalida" << endl;}
    }while ((opcao != '1') && (opcao!= '2'));

}

///Metodo que calcula a pressao de bolha
void CSimuladorBlackOil:: CalculoPressaoBolha() {
    char resp1;
    do{
    cout << linha;
    cout << " 1 - Pressao de bolha - Pb " << endl;
    cout << linha;
    cout << "Qual correlacao deseja usar: " << endl;
    cout << " 1 - Standing \n";
    cout << " 2 - Vasquez e Beggs " << endl;
    cout << linha;
    cin >> resp1; cin.get();

        if((resp1!='1') && (resp1!='2'))
        {cout << "Opcao Invalida!" << endl;};

    }while((resp1!='1') && (resp1!='2'));

    switch (resp1) {
    /// Calculo da pressao de bolha por Standing
    case '1':

    cout << "Pb = " << standing_pb.Pb(fblackoil) << " psia" << endl;

        break;

    /// Calculo da pressao de bolha por Vasquez e Beggs
    case '2':

    cout << "Pb = " << vb_pb.Pb(fblackoil) << " psia" << endl;

        break;
    }

}

///Metodo que calcula a razao de solubilidade
void CSimuladorBlackOil:: CalculoRazaodeSolubilidade() {
    char resp2;
    do{
    cout << linha;
    cout << " 2 - Razao de Solubilidade - Rs" << endl;
    cout << linha;
    cout << "Qual correlacao se desejar usar: " << endl;
    cout << " 1 - Standing \n";
    cout << " 2 - Vasquez e Beggs " << endl;
    cout << linha;
    cin >> resp2; cin.get();

        if((resp2!='1') && (resp2!='2'))
        {cout << "Opcao Invalida!" << endl;};

    }while((resp2!='1') && (resp2!='2'));

    switch (resp2) {

    /// Calculo da Razao de solubilidade por Standing.
    /// Sera necessario o calculo de outras propriedades, estas tambem serao calculadas por Standing
    case '1':
        standing_pb.Pb(fblackoil);
        cout << "Pb = " << standing_pb.pb << " psia" << endl;
        standing_rs.Rs(fblackoil, standing_pb);

        cout << setw(20) << left << "Pressao (psia)" << left << setw(15) << "Razao Solubilidade (scf/STB)" << endl;
        for(int i = 0; i<fblackoil.vpressao.size(); i++){
        cout << setw(20) << left << fblackoil.vpressao[i] << left << setw(15) << standing_rs.vrs[i] << endl;}
        standing_rs.Plot(fblackoil);

    break;

    /// Calculo da Razao de solubilidade por Vasquez e Beggs.
    /// Sera necessario o calculo de outras propriedades, estas tambem serao calculadas por Vasquez e Beggs
    case '2':

        cout << "Pb = " << vb_pb.Pb(fblackoil) << " psia" << endl;
        vb_rs.Rs(fblackoil, vb_pb);

        cout << left << setw(20) << "Pressao (psia)" << left << setw(15) << "Razao Solubilidade (scf/STB)" << endl;
        for(int i = 0; i<fblackoil.vpressao.size(); i++){
            cout << setw(20) << left << fblackoil.vpressao[i] << left << setw(15) << vb_rs.vrs[i] << endl;}
        vb_rs.Plot(fblackoil);

    break;
    }
}

///Metodo que calcula o fator volume de formacao do oleo
void CSimuladorBlackOil::CalculoFatorVolumeFormacaoOleo() {
    char resp3;
    do{
    cout << linha;
    cout << " 3 - Fator Volume de Formacao do Oleo - Bo" << endl;
    cout << linha;
    cout << "Qual correlacao se desejar usar: " << endl;
    cout << " 1 - Standing \n";
    cout << " 2 - Vasquez e Beggs " << endl;
    cout << linha;
    cin >> resp3; cin.get();

        if((resp3!='1') && (resp3!='2'))
        {cout << "Opcao Invalida!" << endl;};

    }while((resp3!='1') && (resp3!='2'));

    switch (resp3) {

    /// Calculo do Fator volume de formacao do oleo no ponto de bolha por Standing,
    case '1':

        standing_bo.Bob(fblackoil);
        cout << "Fator Volume de Formacao do Oleo no ponto de bolha" << endl;
        cout << "Bob = " << standing_bo.bob << " bbl/STB" << endl;

    break;

    /// Calculo do Fator volume de formacao do oleo por Vasquez e Beggs.
    /// Sera necessario o calculo de outras propriedades, estas tambem serao calculadas por Vasquez e Beggs
    case '2':

        vb_pb.Pb(fblackoil);
        vb_rs.Rs(fblackoil, vb_pb);
        vb_co.Co(fblackoil,vb_rs);
        vb_bo.Bo(fblackoil, vb_pb, vb_rs, vb_co);
        cout << "Pressao no ponto de bolha" << endl;
        cout << "Pb = " << vb_pb.pb << " psia" << endl;
        cout << "Fator Volume de Formacao do Oleo no ponto de bolha" << endl;
        cout << "Bob = " << vb_bo.bob << " bbl/STB" << endl;
        cout << left << setw(20) << "Pressao (psia)" << left << setw(15) << "Fator Volume de Formacao do Oleo (bbl/STB)" << endl;
        for(int i = 0; i<fblackoil.vpressao.size(); i++){
            cout << setw(20) << left << fblackoil.vpressao[i] << left << setw(15) << vb_bo.vbo[i] << endl;}
        vb_bo.Plot(fblackoil);

    break;
    }
}

///Metodo que calcula a compressibilidade do oleo
void CSimuladorBlackOil::CalculoCompressibilidadeOleo(){
    cout << linha;
    cout << " 4 - Compressibilidade do oleo - co" << endl;

    /// Calculo da Compressibilidade do oleo por Vasquez e Beggs.
    /// Sera necessario o calculo de outras propriedades, estas tambem serao calculadas por Vasquez e Beggs
    vb_pb.Pb(fblackoil);
    vb_rs.Rs(fblackoil, vb_pb);
    vb_co.Co(fblackoil,vb_rs);
    cout << left << setw(20) << "Pressao (psia)" << left << setw(15) << "Compressibilidade do Oleo (1/psia)" << endl;
    for(int i = 0; i<fblackoil.vpressao.size(); i++){
    cout << setw(20) << left << fblackoil.vpressao[i] << left << setw(15) << vb_co.vco[i] << endl;}
    vb_co.Plot(fblackoil);

}

///Metodo que calcula o fator de compressibilidade do gas Z
void CSimuladorBlackOil::CalculoFatordeCompressibilidadeZ() {
    char resp4;
    do{
    cout << linha;
    cout << " 5 - Fator de Compressibilidade do gas - Z" << endl;
    cout << linha;
    cout << "Qual correlacao se desejar usar: " << endl;
    cout << " 1 - Papay \n";
    cout << " 2 - Beggs e Brill " << endl;
    cout << linha;
    cin >> resp4; cin.get();

        if((resp4!='1') && (resp4!='2'))
        {cout << "Opcao Invalida!" << endl;};

    }while((resp4!='1') && (resp4!='2'));

    /// Calculo da Pressao e Temperatura pseudo-reduzida por Sutton
        sutton_prtr.Pr(fblackoil);
        sutton_prtr.Tr(fblackoil);

    switch (resp4) {

    /// Calculo do Fator Z de compressibilidade do gas por Papay
    case '1':

    papay_z.Z(sutton_prtr);
    cout << left << setw(20) << "Pressao (psia)" << left << setw(15) << "Fator de Compressibilidade do Gas" << endl;
    for(int i = 0; i<fblackoil.vpressao.size(); i++){
    cout << setw(20) << left << fblackoil.vpressao[i] << left << setw(15) <<  papay_z.vz[i] << endl;}
    papay_z.Plot(fblackoil);

        break;

    /// Calculo do Fator Z de compressibilidade do gas por Beggs e Brill
    case '2':

    bb_z.Z(sutton_prtr);
    cout << left << setw(20) << "Pressao (psia)" << left << setw(15) << "Fator de Compressibilidade do Gas" << endl;
    for(int i = 0; i<fblackoil.vpressao.size(); i++){
    cout << setw(20) << left << fblackoil.vpressao[i] << left << setw(15) << bb_z.vz[i] << endl;}
    bb_z.Plot(fblackoil);

        break;
    }

}

///Metodo que calcula o fator volume de formacao do gas
void CSimuladorBlackOil::CalculoFatorVolumeFormacaoGas() {

    cout << linha;
    cout << " 6 - Fator Volume Formacao do Gas - Bg" << endl;
    cout << linha;
    cout << "Necessario o calculo de Z, qual correlacao deseja usar: " << endl;
    char resp4;
    do{
    cout << linha;
    cout << " Fator de Compressibilidade do gas - Z" << endl;
    cout << " 1 - Papay \n";
    cout << " 2 - Beggs e Brill " << endl;
    cout << linha;
    cin >> resp4; cin.get();

        if((resp4!='1') && (resp4!='2'))
        {cout << "Opcao Invalida!" << endl;};

    }while((resp4!='1') && (resp4!='2'));

    /// Calculo da Pressao e Temperatura pseudo-reduzida por Sutton
        sutton_prtr.Pr(fblackoil);
        sutton_prtr.Tr(fblackoil);

    switch (resp4) {

    /// Calculo do Fator volume de formacao do gas usando o Fator Z calculado por Papay
    case '1':

    papay_z.Z(sutton_prtr);
    bg.Bg(fblackoil, papay_z);
    cout << left << setw(20) << "Pressao (psia)" << left << setw(15) << "Fator Volume de Formacao do Gas (bbl/scf)" << endl;
    for(int i = 0; i<fblackoil.vpressao.size(); i++){
    cout << setw(20) << left << fblackoil.vpressao[i] << left << setw(15) << bg.vbg[i] << endl;}
    bg.Plot(fblackoil);

        break;

    /// Calculo do Fator volume de formacao do gas usando o Fator Z calculado por Beggs e Brill
    case '2':

    bb_z.Z(sutton_prtr);
    bg.Bg(fblackoil, bb_z);
    cout << left << setw(20) << "Pressao (psia)" << left << setw(15) << "Fator Volume de Formacao do Gas (bbl/scf)" << endl;
    for(int i = 0; i<fblackoil.vpressao.size(); i++){
    cout << setw(20) << left << fblackoil.vpressao[i] << left << setw(15) << bg.vbg[i] << endl;}
    bg.Plot(fblackoil);

        break;
    }
}




