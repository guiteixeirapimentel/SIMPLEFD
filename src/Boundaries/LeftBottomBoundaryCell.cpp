#include "LeftBottomBoundaryCell.h"

LeftBottomBoundaryCell::LeftBottomBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure, 
    double initU)
    :
    CellNode(dx, dy, xPressure, yPressure, initPressure, initU, 0.0, true)
{
    cPRightStaggeredNode = new StaggeredNode(xPressure + (dx/2.0), 
        yPressure, initU);
}

LeftBottomBoundaryCell::~LeftBottomBoundaryCell()
{
    if(cPRightStaggeredNode)
    {
        delete cPRightStaggeredNode;
        cPRightStaggeredNode = nullptr;
    }
}

void LeftBottomBoundaryCell::SetRightNeighbor(CellNode const* pRightNeighbor)
{
    cPRightNeighbor = pRightNeighbor;
}
void LeftBottomBoundaryCell::SetTopNeighbor(CellNode const* pTopNeighbor)
{
    cPTopNeighbor = pTopNeighbor;
}