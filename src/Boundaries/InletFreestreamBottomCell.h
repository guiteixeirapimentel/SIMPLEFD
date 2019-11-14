#ifndef INLETFREESTREAMBOTTOMCELL_H
#define INLETFREESTREAMBOTTOMCELL_H
#include "BottomBoundaryCell.h"

class InletFreestreamBottomCell : public BottomBoundaryCell
{
public:
	InletFreestreamBottomCell(double dx, double dy, double xPressure, double yPressure, double initPressure,
		double initU, double initV);
	~InletFreestreamBottomCell();

	virtual void CalculateNextPressure(double alfa = 1.0) override;
	virtual void CalculateNextVelocity(double dt, double rho, double mu) override;

private:
};
#endif // !INLETFREESTREAMBOTTOMCELL_H
