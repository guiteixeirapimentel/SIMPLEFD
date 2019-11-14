#include "InletFreestreamBottomCell.h"

InletFreestreamBottomCell::InletFreestreamBottomCell(double dx, double dy, double xPressure, double yPressure, double initPressure,
	double initU, double initV)
	:
	BottomBoundaryCell(dx, dy, xPressure, yPressure, initPressure, initU, initV)
{}

InletFreestreamBottomCell::~InletFreestreamBottomCell()
{}

void InletFreestreamBottomCell::CalculateNextPressure(double alfa = 1.0)
{}
void InletFreestreamBottomCell::CalculateNextVelocity(double dt, double rho, double mu)
{}