#include "LeftBottomBoundaryCell.h"

LeftBottomBoundaryCell::LeftBottomBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure, 
    double initU, double initV)
    :
    CellNode(dx, dy, xPressure, yPressure, initPressure, initU, initV, true)
{
    cPRightStaggeredNode = new StaggeredNode(xPressure + (dx/2.0), 
        yPressure, initU);
	cPTopStaggeredNode = new StaggeredNode(xPressure, yPressure + (dy / 2.0), initV);

}

LeftBottomBoundaryCell::~LeftBottomBoundaryCell()
{
    if(cPRightStaggeredNode)
    {
        delete cPRightStaggeredNode;
        cPRightStaggeredNode = nullptr;
    }
	if (cPTopStaggeredNode)
	{
		delete cPTopStaggeredNode;
		cPTopStaggeredNode = nullptr;
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