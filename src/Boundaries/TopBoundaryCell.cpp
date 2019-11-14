#include "TopBoundaryCell.h"

TopBoundaryCell::TopBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure,
	double initU)
	:
	CellNode(dx, dy, xPressure, yPressure, initPressure, initU, 0.0, true)
{
	cPRightStaggeredNode = new StaggeredNode(xPressure + (dx / 2.0),
		yPressure, initU);
}

TopBoundaryCell::~TopBoundaryCell()
{
	if (cPRightStaggeredNode)
	{
		delete cPRightStaggeredNode;
		cPRightStaggeredNode = nullptr;
	}
}

void TopBoundaryCell::SetRightNeighbor(CellNode const* pRightNeighbor)
{
	cPRightNeighbor = pRightNeighbor;
}

void TopBoundaryCell::SetBottomNeighbor(CellNode const* cBottomNeighbor)
{
	cPBottomNeighbor = cBottomNeighbor;
}

vodi TopBoundaryCell::SetLeftNeighbor(CellNode const* cLeftNeighbor)
{
	cPLeftNeighbor = cLeftNeighbor;
}