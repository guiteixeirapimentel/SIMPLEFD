#include "PipeSim.h"

#include "Boundaries/BottomBoundaryCell.cpp"
#include "Boundaries/LeftBottomBoundaryCell.cpp"
#include "Boundaries/LeftBoundaryCell.cpp"
#include "Boundaries/LeftTopBoundaryCell.cpp"
#include "Boundaries/RightBottomBoundaryCell.cpp"
#include "Boundaries/RightBoundaryCell.cpp"
#include "Boundaries/RightTopBoundaryCell.cpp"
#include "Boundaries/TopBoundaryCell.cpp"

PipeSim::PipeSim(double length, double diameter, double dx, double dy)
	:
	cdx(dx),
	cdy(dy),
	cLength(length),
	cDiameter(diameter),
	cNX((cLength/dx) + 1),
	cNY((cDiameter/dy) + 1)
{
	cGrid.resize(cNX * cNY);

	cGrid[0] = new LeftTopBoundaryCell(cdx, cdy, 0.0, 0.0, 0.0, )
}

PipeSim::~PipeSim()
{

}

void PipeSim::Simulate(double dt)
{

}