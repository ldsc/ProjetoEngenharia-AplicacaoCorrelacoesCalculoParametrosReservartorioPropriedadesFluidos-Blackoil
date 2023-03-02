#include <iostream>
#include <fstream>

#include "CFluidoBlackOil.h"

/**
@brief Classe que representa as caracteristicas do fluido blackoil
@class CFluidoBlackOil
@file CFluidoBlackOil.cpp
 */

using namespace std;

///Sobrecarga do operador >>, entrada de dados pelo teclado
istream& operator >> (istream& in, CFluidoBlackOil& obj){

    cout << "Entre com os valores das variaveis conforme sequencia:\n";
    cout << " 1 - Grau API \n";
    in >> obj.api; in.get();
    cout << " \n2 - Temperatura no Reservatorio (em Fahrenheit) \n ";
    in >> obj.temp; in.get();
    cout << " \n3 - Razao de Solubilidade no ponto de bolha = Rsb (em scf/STB) \n";
    in >> obj.rsb; in.get();
    cout << " \n4 - Pressao do ponto desejado (em Psia) (caso queira calcular de varios pontos digitar 0 para essa variavel) \n";
    in >> obj.p; in.get();
    cout << " \n5 - Pressao maxima do reservatorio (caso queira calcular em um unico ponto digitar 0 para essa variavel) \n";
    in >> obj.pmax; in.get();
    cout << " \n6 - Variacao de pressao desejada para acrescimo de pressao \n";
    in >> obj.deltap; in.get();
    cout << " \n7 - Densidade do gas no separador \n";
    in >> obj.dgs; in.get();
    cout << " \n8 - Densidade do gas \n";
    in >> obj.dg; in.get();
    cout << " \n9 - Densidade do oleo\n";
    in >> obj.d_o; in.get();

    return in;
}
///Sobrecarga do operador >>, entrada de dados pelo disco
ifstream& operator >> (ifstream& fin, CFluidoBlackOil& obj){

    fin.ignore(500,'\n');
    fin>>obj.p;
    fin.ignore(500,'\n');
    fin>>obj.pmax;
    fin.ignore(500,'\n');
    fin>>obj.deltap;
    fin.ignore(500,'\n');
    fin>>obj.api;
    fin.ignore(500,'\n');
    fin>>obj.dg;
    fin.ignore(500,'\n');
    fin>>obj.temp;
    fin.ignore(500,'\n');
    fin>> obj.dgs;
    fin.ignore (500,'\n');
    fin>>obj.rsb;
    fin.ignore(500,'\n');
    fin>>obj.d_o;
    fin.close();
    return fin;
}
/// Metodo para criar o vetor de pressoes
vector<double> CFluidoBlackOil :: Gera_vp(double p, double pmax, double deltap) {

/// Caso o calculo seja para um vetor de pressoes
if (p==0.0) {
    for(double i =14.7; i<= pmax; i += deltap) {
       vpressao.push_back(i);
        }
    }
/// Caso o calculo seja para um unico de valor de pressao
if(pmax==0.0 && deltap ==0.0){
        vpressao.push_back(p);
        }
/// Teste e instrucoes para entrada de dados
if (((p!=0.0) && (pmax!=0.0) && (deltap!=0.0)) || ((p==0.0) && (pmax==0.0) && (deltap==0.0)))
        {
         cout << "\nDados inseridos incorretamente! \nFavor digitar 0 e verificar regras para calculo em um ponto ou em vetor.\n";
         cout << "- Caso queira calcular os parametros em um unico valor de pressao,\ninserir 0 em pressao maxima e 0 em variacao de pressao.\n";
         cout << "- Caso queira calcular os parametros em diversos valores de pressao inserir 0 em Pressao do ponto desejado.\n" << endl;
         }
    return vpressao;
}
