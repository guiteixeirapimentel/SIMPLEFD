#ifndef BOTTOMBOUNDARYCELL_H
#define BOTTOMBOUNDARYCELL_H

#include "../CellNode.h"

class BottomBoundaryCell : public CellNode
{
public:
    BottomBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure, 
    double initU, double initV);
    ~BottomBoundaryCell();

    void SetRightNeighbor(CellNode const* pRightNeighbor) override;
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