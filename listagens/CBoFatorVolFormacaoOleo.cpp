#include "CBoFatorVolFormacaoOleo.h"
#include "CGnuplot.h"

/**
@class CBoFatorVolFormacaoOleo
@file CBoFatorVolFormacaoOleo.cpp
 */

/// Metodo para gerar grafico
void CBoFatorVolFormacaoOleo :: Plot (CFluidoBlackOil& fluido) {

static CGnuplot g2d;
g2d.Title("Pressao x Fator Volume de Formacao do Oleo");
g2d.XLabel("Pressao(psia)");
g2d.YLabel("Bo(bbl/STB)");
g2d.Style("linespoints");
g2d.PlotVector(fluido.vpressao,vbo);

}
