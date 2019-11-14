#ifndef INLETFREESTREAMRIGHTTOPCELL_H
#define INLETFREESTREAMRIGHTTOPCELL_H
#include "RightTopBoundaryCell.h"

class InletFreestreamRightTopCell : public RightTopBoundaryCell
{
public:
	InletFreestreamRightTopCell(double dx, double dy, double xPressure, double yPressure, double initPressure);
	~InletFreestreamRightTopCell();

	virtual void CalculateNextPressure(double alfa = 1.0) override;
	virtual void CalculateNextVelocity(double dt, double rho, double mu) override;

};
#endif