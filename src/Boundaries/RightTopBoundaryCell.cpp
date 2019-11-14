#include "RightTopBoundaryCell.h"

RightTopBoundaryCell::RightTopBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure)
    :
CellNode(dx, dy, xPressure, yPressure, initPressure, 0.0, 0.0, true)
{}

RightTopBoundaryCell::~RightTopBoundaryCell()
{}

void RightTopBoundaryCell::SetLeftNeighbor(CellNode const* pLeftNeighbor)
{
    cPLeftNeighbor = pLeftNeighbor;
}

void RightTopBoundaryCell::SetTopNeighbor(CellNode const* pTopNeighbor) 
{
    cPTopNeighbor = pTopNeighbor;
}