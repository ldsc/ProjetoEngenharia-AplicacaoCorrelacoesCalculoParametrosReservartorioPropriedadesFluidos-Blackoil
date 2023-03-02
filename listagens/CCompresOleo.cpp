#include "CCompresOleo.h"
#include "CGnuplot.h"

/**
@class CCompresOleo
@file CCompresOleo.cpp
 */

/// Metodo para gerar grafico
void CCompresOleo:: Plot(CFluidoBlackOil& fluido) {

static CGnuplot g2d;
g2d.Title("Pressao x Compressibilidade do Oleo");
g2d.XLabel("Pressao(psia)");
g2d.YLabel("Co(1/psi)");
g2d.Style("linespoints");
g2d.PlotVector(fluido.vpressao,vco);
}
