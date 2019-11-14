#include "RightBoundaryCell.h"

RightBoundaryCell::RightBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure, 
    double initV)
    :
CellNode(dx, dy, xPressure, yPressure, initPressure, 0.0, initV, true)
{
    cPTopStaggeredNode = new StaggeredNode(xPressure, 
      yPressure + (dy/2.0), initV);
}

RightBoundaryCell::~RightBoundaryCell()
{
    if(cPTopStaggeredNode)
    {
        delete cPTopStaggeredNode;
		cPTopStaggeredNode = nullptr;
    }
}

void RightBoundaryCell::SetLeftNeighbor(CellNode const* pLeftNeighbor) 
{
    cPLeftNeighbor = pLeftNeighbor;
}

void RightBoundaryCell::SetTopNeighbor(CellNode const* pTopNeighbor)
{
    cPTopNeighbor = pTopNeighbor;
}