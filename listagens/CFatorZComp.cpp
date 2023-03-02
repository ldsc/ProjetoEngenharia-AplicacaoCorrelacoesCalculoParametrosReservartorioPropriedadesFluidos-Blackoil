#include "CFatorZComp.h"
#include "CGnuplot.h"

/**
@class CFatorZComp
@file CFatorZComp.cpp
 */

/// Metodo para gerar grafico
void CFatorZComp:: Plot(CFluidoBlackOil& fluido){

static CGnuplot g2d;
g2d.Title("Pressao x Fator de Compressibilidade do Gas");
g2d.XLabel("Pressao(psia)");
g2d.YLabel("Z");
g2d.Style("linespoints");
g2d.PlotVector(fluido.vpressao,vz);
}
