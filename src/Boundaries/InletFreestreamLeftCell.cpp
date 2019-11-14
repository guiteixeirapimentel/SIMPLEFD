#include "InletFreestreamLeftCell.h"

InletFreestreamLeftCell::InletFreestreamLeftCell(double dx, double dy, double xPressure, double yPressure, double initPressure,
	double initU, double initV)
	:
	LeftBoundaryCell(dx, dy, xPressure, yPressure, initPressure, initU, initV)
{}

InletFreestreamLeftCell::~InletFreestreamLeftCell()
{}

void InletFreestreamLeftCell::CalculateNextPressure(double alfa = 1.0)
{}
void InletFreestreamLeftCell::CalculateNextVelocity(double dt, double rho, double mu)
{}