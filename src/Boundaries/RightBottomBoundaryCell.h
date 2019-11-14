#ifndef RIGHTBOTTOMBOUNDARYCELL_H
#define RIGHTBOTTOMBOUNDARYCELL_H

#include "../CellNode.h"

class RightBottomBoundaryCell : public CellNode
{
public:
    RightBottomBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure, double initV);
    ~RightBottomBoundaryCell();

    void SetRightNeighbor(CellNode const* pRightNeighbor) override
    {cPRightNeighbor = nullptr;};
    void SetLeftNeighbor(CellNode const* pLeftNeighbor) override;
    void SetTopNeighbor(CellNode const* pTopNeighbor) override;
    void SetBottomNeighbor(CellNode const* cBottomNeighbor) override
    {cPBottomNeighbor = nullptr;};

	void CalculateNextVelocity(double dt, double rho, double mu) override;

	virtual double CalculatePCorrSource(double dt, double rho) override;
	virtual double RelaxatePCorr(double dt, double rho) override;

	virtual void CalculateNextPressure(double alfa = 1.0) override;
};

#endif