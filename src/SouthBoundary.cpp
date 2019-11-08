#include "SouthBoundary.h"

SouthBoundary::SouthBoundary(double x, double y, double initValue)
:
	BoundaryNode(x, y, initValue)
{}

SouthBoundary::~SouthBoundary()
{}

void SouthBoundary::SetNorthNode(Node const* pNorthNode)
{
    cPNorthNode = pNorthNode;
}