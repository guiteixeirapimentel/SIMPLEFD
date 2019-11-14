#ifndef INLETFREESTREAMRIGHTCELL_H
#define INLETFREESTREAMRIGHTCELL_H
#include "RightBoundaryCell.h"

class InletFreestreamRightCell : public RightBoundaryCell
{
public:
	InletFreestreamRightCell(double dx, double dy, double xPressure, double yPressure, double initPressure,
		double initV);
	~InletFreestreamRightCell();

	virtual void CalculateNextPressure(double alfa = 1.0) override;
	virtual void CalculateNextVelocity(double dt, double rho, double mu) override;

};
#endif