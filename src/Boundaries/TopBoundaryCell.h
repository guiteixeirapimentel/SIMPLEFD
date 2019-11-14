#ifndef TOPBOUNDARYCELL_H
#define TOPBOUNDARYCELL_H

#include "../CellNode.h"

class TopBoundaryCell : public CellNode
{
public:
	TopBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure,
		double initU);
	~TopBoundaryCell();

	void SetRightNeighbor(CellNode const* pRightNeighbor) override;
	void SetLeftNeighbor(CellNode const* pLeftNeighbor) override;
	void SetTopNeighbor(CellNode const* pTopNeighbor) override
	{
		cPTopNeighbor = nullptr;
	};
	void SetBottomNeighbor(CellNode const* cBottomNeighbor) override;

};

#endif