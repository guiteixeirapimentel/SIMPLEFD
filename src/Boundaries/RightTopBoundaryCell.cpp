#include "RightTopBoundaryCell.h"

RightTopBoundaryCell::RightTopBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure, 
    double initV)
    :
CellNode(dx, dy, xPressure, yPressure, initPressure, 0.0, initV, true)
{
    cPBottomStaggeredNode = new StaggeredNode(xPressure, 
      yPressure + (dy/2.0), initV);
}

RightTopBoundaryCell::~RightTopBoundaryCell()
{
    if(cPBottomStaggeredNode)
    {
        delete cPBottomStaggeredNode;
        cPBottomStaggeredNode = nullptr;
    }
}

void RightTopBoundaryCell::SetLeftNeighbor(CellNode const* pLeftNeighbor)
{
    cPLeftNeighbor = pLeftNeighbor;
}

void RightTopBoundaryCell::SetTopNeighbor(CellNode const* pTopNeighbor) 
{
    cPTopNeighbor = pTopNeighbor;
}