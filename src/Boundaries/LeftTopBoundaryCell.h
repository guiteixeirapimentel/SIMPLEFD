#ifndef LEFTTOPBOUNDARYCELL_H
#define LEFTTOPBOUNDARYCELL_H

#include "../CellNode.h"

class LeftTopBoundaryCell : public CellNode
{
public:
    LeftTopBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure, 
    double initU);
    ~LeftTopBoundaryCell();

    void SetRightNeighbor(CellNode const* pRightNeighbor) override;
    void SetLeftNeighbor(CellNode const* pLeftNeighbor) override
    {cPLeftNeighbor = nullptr;};
    void SetTopNeighbor(CellNode const* pTopNeighbor) override
    {cPTopNeighbor = nullptr;};
    void SetBottomNeighbor(CellNode const* cBottomNeighbor) override;

	void CalculateNextVelocity(double dt, double rho, double mu) override;

	virtual double CalculatePCorrSource(double dt, double rho) override;
	virtual double RelaxatePCorr(double dt, double rho) override;

	virtual void CalculateNextPressure(double alfa = 1.0) override;
};


#endif