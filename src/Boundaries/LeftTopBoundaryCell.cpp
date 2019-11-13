#include "LeftTopBoundaryCell.h"

LeftTopBoundaryCell::LeftTopBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure, 
    double initU, double initV)
    :
    CellNode(dx, dy, xPressure, yPressure, initPressure, initU, initV, true)
{
    cPRightStaggeredNode = new StaggeredNode(xPressure + (dx/2.0), 
        yPressure, initU);

    cPBottomStaggeredNode = new StaggeredNode(xPressure, 
    yPressure + (dy/2.0), initV);
}

LeftTopBoundaryCell::~LeftTopBoundaryCell()
{
    if(cPRightStaggeredNode)
    {
        delete cPRightStaggeredNode;
        cPRightStaggeredNode = nullptr;
    }
    if(cPBottomStaggeredNode)
    {
        delete cPBottomStaggeredNode;
        cPBottomStaggeredNode = nullptr;
    }
}

void LeftTopBoundaryCell::SetRightNeighbor(CellNode const* pRightNeighbor) 
{
    cPRightNeighbor = pRightNeighbor;
}

void LeftTopBoundaryCell::SetBottomNeighbor(CellNode const* cBottomNeighbor)
{
    cPLeftNeighbor = cPLeftNeighbor;
}