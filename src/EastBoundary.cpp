#include "EastBoundary.h"

EastBoundary::EastBoundary(double x, double y, double U, double V, double P, TYPE type)
:
BoundaryField(x, y, U, V, P, type)
{}

EastBoundary::~EastBoundary()
{}

double EastBoundary::CalculatePRelax()
{
    switch(cType)
    {
        case ZEROGRADIENTNOSLIP:
        {
            cP = cPWestNode->GetP();
        }
        break;
        case ZEROGRADIENT:
        {
            cP = cPWestNode->GetP();
        }
        break;
    }

    return 0.0;
}
void EastBoundary::CalculateU(double dt)
{
    switch(cType)
    {
        case ZEROGRADIENT:
        {
            cU = cPWestNode->GetU();
        }
        break;
    }
}
void EastBoundary::CalculateV(double dt)
{
    switch(cType)
    {
        case ZEROGRADIENT:
        {
            cV = cPWestNode->GetV();
        }
        break;
    }
}

void EastBoundary::SetWestBoundary(Node const* pWestNode)
{
    cPWestNode = pWestNode;
}