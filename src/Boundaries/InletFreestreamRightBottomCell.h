#ifndef INLETFREESTREAMRIGHTBOTTOMCELL_H
#define INLETFREESTREAMRIGHTBOTTOMCELL_H
#include "RightBottomBoundaryCell.h"

class InletFreestreamRightBottomCell : public RightBottomBoundaryCell
{
public:
	InletFreestreamRightBottomCell(double dx, double dy, double xPressure, double yPressure, double initPressure,
		double initV);
	~InletFreestreamRightBottomCell();

	virtual void CalculateNextPressure(double alfa = 1.0) override;
	virtual void CalculateNextVelocity(double dt, double rho, double mu) override;

};
#endif