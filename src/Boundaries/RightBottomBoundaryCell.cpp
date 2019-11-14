#include "RightBottomBoundaryCell.h"

RightBottomBoundaryCell::RightBottomBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure,
	double initV)
:
CellNode(dx, dy, xPressure, yPressure, initPressure, 0.0, initV, true)
{
	cPTopStaggeredNode = new StaggeredNode(xPressure, yPressure + (dy / 2.0), initV);
}

RightBottomBoundaryCell::~RightBottomBoundaryCell()
{
	if (cPTopStaggeredNode)
	{
		delete cPTopStaggeredNode;
		cPTopStaggeredNode = nullptr;
	}
}

void RightBottomBoundaryCell::SetLeftNeighbor(CellNode const* pLeftNeighbor) 
{
    cPLeftNeighbor = pLeftNeighbor;
}

void RightBottomBoundaryCell::SetTopNeighbor(CellNode const* pTopNeighbor) 
{
    cPTopNeighbor = pTopNeighbor;
}
