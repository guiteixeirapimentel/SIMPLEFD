#ifndef PIPESIM_H
#define PIPESIM_H

#include <vector>
#include "CellNode.h"

class PipeSim
{
public:
	PipeSim(double length, double diameter, double dx, double dy, double pressInlet, double pressOutlet);
	~PipeSim();

	void Simulate(double dt);

private:
	const double cdx;
	const double cdy;
	const double cLength;
	const double cDiameter;
	
	const size_t cNX;
	const size_t cNY;

	std::vector<CellNode*> cGrid;
};

#endif