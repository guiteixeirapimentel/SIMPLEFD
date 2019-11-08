#include "EastBoundary.h"

EastBoundary::EastBoundary(double x, double y, double initValue)
:
BoundaryField(x, y, initValue)
{}

EastBoundary::~EastBoundary()
{}

void EastBoundary::SetWestBoundary(Node const* pWestNode)
{
    cPWestNode = pWestNode;
}