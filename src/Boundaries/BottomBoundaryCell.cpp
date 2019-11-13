#include "BottomBoundaryCell.h"

BottomBoundaryCell::BottomBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure, 
    double initU)
    :
    CellNode(dx, dy, xPressure, yPressure, initPressure, initU, 0.0, true)
{
    cPRightStaggeredNode = new StaggeredNode(xPressure + (dx/2.0), 
        yPressure, initU);
}
BottomBoundaryCell::~BottomBoundaryCell()
{
    if(cPRightNeighbor)
    {
        delete cPRightNeighbor;
        cPRightNeighbor = nullptr;
    }
}

void BottomBoundaryCell::SetRightNeighbor(CellNode const* pRightNeighbor)
{
    cPRightNeighbor = pRightNeighbor;
}
void BottomBoundaryCell::SetLeftNeighbor(CellNode const* pLeftNeighbor)
{
    cPLeftNeighbor = pLeftNeighbor;
}
void BottomBoundaryCell::SetTopNeighbor(CellNode const* pTopNeighbor)
{
    cPTopNeighbor = pTopNeighbor;
}