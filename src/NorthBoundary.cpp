#include "NorthBoundary.h"

NorthBoundary::NorthBoundary(double x, double y, double initValue)
:
BoundaryNode(x, y, initValue)
{}

NorthBoundary::~NorthBoundary()
{}

void NorthBoundary::SetSouthNode(Node const* pSouthNode)
{
    cPSouthNode = pSouthNode;
}