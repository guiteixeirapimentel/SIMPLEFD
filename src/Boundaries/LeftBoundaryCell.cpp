#include "LeftBoundaryCell.h"

LeftBoundaryCell::LeftBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure, 
    double initU, double initV)
    :
    CellNode(dx, dy, xPressure, yPressure, initPressure, initU, initV, true)
{
    cPRightStaggeredNode = new StaggeredNode(xPressure + (dx/2.0), 
        yPressure, initU);

    cPBottomStaggeredNode = new StaggeredNode(xPressure, 
    yPressure + (dy/2.0), initV);
}

LeftBoundaryCell::~LeftBoundaryCell()
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

void LeftBoundaryCell::SetRightNeighbor(CellNode const* pRightNeighbor)
{
    cPRightNeighbor = pRightNeighbor;
}

void LeftBoundaryCell::SetTopNeighbor(CellNode const* pTopNeighbor)
{
    cPTopNeighbor = pTopNeighbor;
}
void LeftBoundaryCell::SetBottomNeighbor(CellNode const* cBottomNeighbor)
{
    cPBottomNeighbor = cPBottomNeighbor;
}