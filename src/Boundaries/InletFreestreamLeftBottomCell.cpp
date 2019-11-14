#include "InletFreestreamLeftBottomCell.h"

InletFreestreamLeftBottomCell::InletFreestreamLeftBottomCell(double dx, double dy, double xPressure, double yPressure, double initPressure,
	double initU, double initV)
	:
	LeftBottomBoundaryCell(dx, dy, xPressure, yPressure, initPressure, initU, initV)
{}
InletFreestreamLeftBottomCell::~InletFreestreamLeftBottomCell()
{}

void InletFreestreamLeftBottomCell::CalculateNextPressure(double alfa = 1.0)
{}

void InletFreestreamLeftBottomCell::CalculateNextVelocity(double dt, double rho, double mu)
{}