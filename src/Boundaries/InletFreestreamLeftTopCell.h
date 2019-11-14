#ifndef INLETFREESTREAMLEFTTOPCELL_H
#define INLETFREESTREAMLEFTTOPCELL_H
#include "LeftTopBoundaryCell.h"

class InletFreestreamLeftTopCell : public LeftBoundaryTopCell
{
public:
	InletFreestreamLeftTopCell(double dx, double dy, double xPressure, double yPressure, double initPressure,
		double initU);
	~InletFreestreamLeftTopCell();

	virtual void CalculateNextPressure(double alfa = 1.0) override;
	virtual void CalculateNextVelocity(double dt, double rho, double mu) override;

};
#endif