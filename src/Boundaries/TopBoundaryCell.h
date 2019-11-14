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

	void CalculateNextVelocity(double dt, double rho, double mu) override;

	virtual double CalculatePCorrSource(double dt, double rho) override;
	virtual double RelaxatePCorr(double dt, double rho) override;

	virtual void CalculateNextPressure(double alfa = 1.0) override;
};

#endif