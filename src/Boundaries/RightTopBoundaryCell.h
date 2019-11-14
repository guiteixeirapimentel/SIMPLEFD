#ifndef RIGHTTOPBOUNDARYCELL_H
#define RIGHTTOPBOUNDARYCELL_H

#include "../CellNode.h"
 
class RightTopBoundaryCell : public CellNode
{
public:
    RightTopBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure);
    ~RightTopBoundaryCell();

    void SetRightNeighbor(CellNode const* pRightNeighbor) override
    {cPLeftNeighbor = nullptr;};
    void SetLeftNeighbor(CellNode const* pLeftNeighbor) override;
    void SetTopNeighbor(CellNode const* pTopNeighbor) override;
    void SetBottomNeighbor(CellNode const* cBottomNeighbor) override
    {cPTopNeighbor = nullptr;};
    

	void CalculateNextVelocity(double dt, double rho, double mu) override;

	virtual double CalculatePCorrSource(double dt, double rho) override;
	virtual double RelaxatePCorr(double dt, double rho) override;

	virtual void CalculateNextPressure(double alfa = 1.0) override;
};

#endif