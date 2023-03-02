#include "CRazaoSolubilidade.h"
#include "CGnuplot.h"

/**
@class CRazaoSolubilidade
@file CRazaoSolubilidade.cpp
 */

/// Metodo para gerar grafico
void CRazaoSolubilidade:: Plot(CFluidoBlackOil& fluido) {

static CGnuplot g2d;
g2d.Title("Pressao x Razao de Solubilidade");
g2d.XLabel("Pressao(psia)");
g2d.YLabel("Rs(scf/STB)");
g2d.Style("linespoints");
g2d.PlotVector(fluido.vpressao,vrs);
}
