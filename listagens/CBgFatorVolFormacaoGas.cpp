#include "CBgFatorVolFormacaoGas.h"
#include "CGnuplot.h"

/**
@class CBgFatorVolFormacaoGas
@file CBgFatorVolFormacaoGas.cpp
 */
using namespace std;

/// Metodo para calcular o fator volume de formacao do gas
vector<double> CBgFatorVolFormacaoGas :: Bg(CFluidoBlackOil& fluido, CFatorZComp& fcz){
    vbg.resize(fluido.vpressao.size()); //mesmo tamanho

for (int i=0; i<fluido.vpressao.size(); i++){
        vbg[i] = (0.00504 * fcz.vz[i] * (fluido.temp + 459.67)) / fluido.vpressao[i];
        }

    return vbg;
}
/// Metodo para gerar grafico
void CBgFatorVolFormacaoGas:: Plot(CFluidoBlackOil& fluido){

static CGnuplot g2d;
g2d.Title("Pressao x Fator Volume de Formacao do Gas");
g2d.XLabel("Pressao(psia)");
g2d.YLabel("Bg (bbl/scf)");
g2d.Style("linespoints");
g2d.PlotVector(fluido.vpressao,vbg);

}
