#include "RightBottomBoundaryCell.h"

RightBottomBoundaryCell::RightBottomBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure)
:
CellNode(dx, dy, xPressure, yPressure, initPressure, 0.0, 0.0, true)
{}

RightBottomBoundaryCell::~RightBottomBoundaryCell()
{}

void RightBottomBoundaryCell::SetLeftNeighbor(CellNode const* pLeftNeighbor) 
{
    cPLeftNeighbor = pLeftNeighbor;
}

void RightBottomBoundaryCell::SetTopNeighbor(CellNode const* pTopNeighbor) 
{
    cPTopNeighbor = pTopNeighbor;
}