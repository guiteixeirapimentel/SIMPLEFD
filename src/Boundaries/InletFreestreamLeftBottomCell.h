#ifndef INLETFREESTREAMLEFTBOTTOMCELL_H
#define INLETFREESTREAMLEFTBOTTOMCELL_H
#include "LeftBottomBoundaryCell.h"

class InletFreestreamLeftBottomCell : public LeftBottomBoundaryCell
{
public:
	InletFreestreamLeftBottomCell(double dx, double dy, double xPressure, double yPressure, double initPressure,
		double initU, double initV);
	~InletFreestreamLeftBottomCell();

	virtual void CalculateNextPressure(double alfa = 1.0) override;
	virtual void CalculateNextVelocity(double dt, double rho, double mu) override;

};
#endif