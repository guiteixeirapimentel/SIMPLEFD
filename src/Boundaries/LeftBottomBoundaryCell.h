#ifndef LEFTBOTTOMBOUNDARYCELL_H
#define LEFTBOTTOMBOUNDARYCELL_H

#include "../CellNode.h"

class LeftBottomBoundaryCell : public CellNode
{
public:
    LeftBottomBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure, 
    double initU, double initV);
    ~LeftBottomBoundaryCell();

    void SetRightNeighbor(CellNode const* pRightNeighbor) override;
    void SetLeftNeighbor(CellNode const* pLeftNeighbor) override
    {cPLeftNeighbor = nullptr;};
    void SetTopNeighbor(CellNode const* pTopNeighbor) override;
    void SetBottomNeighbor(CellNode const* cBottomNeighbor) override
    {cPBottomNeighbor = nullptr;};

	void CalculateNextVelocity(double dt, double rho, double mu) override;

	virtual double CalculatePCorrSource(double dt, double rho) override;
	virtual double RelaxatePCorr(double dt, double rho) override;

	virtual void CalculateNextPressure(double alfa = 1.0) override;

};

#endif