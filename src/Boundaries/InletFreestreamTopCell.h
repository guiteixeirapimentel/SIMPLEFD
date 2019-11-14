#ifndef INLETFREESTREAMTOPCELL_H
#define INLETFREESTREAMTOPCELL_H
#include "TopBoundaryCell.h"

class InletFreestreamRightTopCell : public TopBoundaryCell
{
public:
	InletFreestreamRightTopCell(double dx, double dy, double xPressure, double yPressure, double initPressure,
		double initU);
	~InletFreestreamRightTopCell();

	virtual void CalculateNextPressure(double alfa = 1.0) override;
	virtual void CalculateNextVelocity(double dt, double rho, double mu) override;

};
#endif