#ifndef LEFTBOUNDARYCELL_H
#define LEFTBOUNDARYCELL_H

#include "../CellNode.h"

class LeftBoundaryCell : public CellNode
{
public:
    LeftBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure, 
    double initU, double initV);
    ~LeftBoundaryCell();

    void SetRightNeighbor(CellNode const* pRightNeighbor) override;
    void SetLeftNeighbor(CellNode const* pLeftNeighbor) override
    {cPLeftNeighbor = nullptr;};
    void SetTopNeighbor(CellNode const* pTopNeighbor) override;
    void SetBottomNeighbor(CellNode const* cBottomNeighbor) override;

	void CalculateNextVelocity(double dt, double rho, double mu) override;

	virtual double CalculatePCorrSource(double dt, double rho) override;
	virtual double RelaxatePCorr(double dt, double rho) override;

	virtual void CalculateNextPressure(double alfa = 1.0) override;
};


#endif