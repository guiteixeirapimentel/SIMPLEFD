#ifndef INLETFREESTREAMLEFTCELL_H
#define INLETFREESTREAMLEFTCELL_H
#include "LeftBoundaryCell.h"

class InletFreestreamLeftCell : public LeftBoundaryCell
{
public:
	InletFreestreamLeftCell(double dx, double dy, double xPressure, double yPressure, double initPressure,
		double initU, double initV);
	~InletFreestreamLeftCell();

	virtual void CalculateNextPressure(double alfa = 1.0) override;
	virtual void CalculateNextVelocity(double dt, double rho, double mu) override;

};
#endif