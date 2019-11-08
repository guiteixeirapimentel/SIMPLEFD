#include "WestBoundary.h"

WestBoundary::WestBoundary(double x, double y, double initValue)
:
BoundaryNode(x, y, initValue)
{}

WestBoundary::~WestBoundary()
{}

void WestBoundary::SetEastNode(Node const* pEastNode)
{
    cPEastNode = pEastNode;
}