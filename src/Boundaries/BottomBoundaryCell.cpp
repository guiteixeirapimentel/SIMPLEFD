#include "BottomBoundaryCell.h"

BottomBoundaryCell::BottomBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure, 
    double initU, double initV)
    :
    CellNode(dx, dy, xPressure, yPressure, initPressure, initU, initV, true)
{
    cPRightStaggeredNode = new StaggeredNode(xPressure + (dx/2.0), 
        yPressure, initU);

	cPTopStaggeredNode = new StaggeredNode(xPressure, yPressure + (dy / 2.0), initV);
}
BottomBoundaryCell::~BottomBoundaryCell()
{
    if(cPRightStaggeredNode)
    {
        delete cPRightStaggeredNode;
		cPRightStaggeredNode = nullptr;
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