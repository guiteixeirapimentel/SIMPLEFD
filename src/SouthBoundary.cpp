#include "SouthBoundary.h"

SouthBoundary::SouthBoundary(double x, double y, double U, double V, double P, TYPE type)
:
BoundaryField(x, y, U, V, P, type)
{}

SouthBoundary::~SouthBoundary()
{}

double SouthBoundary::CalculatePRelax()
{
    switch(cType)
    {
        case ZEROGRADIENTNOSLIP:
        {
            cP = cPNorthNode->GetP();
        }
        break;
        case ZEROGRADIENT:
        {
            cP = cPNorthNode->GetP();
        }
        break;
    }

    return 0.0;
}
void SouthBoundary::CalculateU(double dt)
{
    switch(cType)
    {
        case ZEROGRADIENT:
        {
            cU = cPNorthNode->GetU();
        }
        break;
    }
}
void SouthBoundary::CalculateV(double dt)
{
    switch(cType)
    {
        case ZEROGRADIENT:
        {
            cV = cPNorthNode->GetV();
        }
        break;
    }
}

void SouthBoundary::SetNorthNode(Node const* pNorthNode)
{
    cPNorthNode = pNorthNode;
}