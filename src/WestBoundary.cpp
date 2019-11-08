#include "WestBoundary.h"

WestBoundary::WestBoundary(double x, double y, double U, double V, double P, TYPE type)
:
BoundaryField(x, y, U, V, P, type)
{}

WestBoundary::~WestBoundary()
{}

double WestBoundary::CalculatePRelax()
{
    switch(cType)
    {
        case ZEROGRADIENTNOSLIP:
        {
            cP = cPEastNode->GetP();
        }
        break;
        case ZEROGRADIENT:
        {
            cP = cPEastNode->GetP();
        }
        break;
    }

    return 0.0;
}
void WestBoundary::CalculateU(double dt)
{
    switch(cType)
    {
        
        case ZEROGRADIENT:
        {
            cU = cPEastNode->GetU();
        }
        break;
    }
}
void WestBoundary::CalculateV(double dt)
{
    switch(cType)
    {
        case ZEROGRADIENT:
        {
            cV = cPEastNode->GetV();
        }
        break;
    }
}

void WestBoundary::SetEastNode(Node const* pEastNode)
{
    cPEastNode = pEastNode;
}