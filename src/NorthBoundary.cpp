#include "NorthBoundary.h"

NorthBoundary::NorthBoundary(double x, double y, double U, double V, double P, TYPE type)
:
BoundaryField(x, y, U, V, P, type)
{}

NorthBoundary::~NorthBoundary()
{}

double NorthBoundary::CalculatePRelax()
{
    switch(cType)
    {
        case ZEROGRADIENTNOSLIP:
        {
            cP = cPSouthNode->GetP();
        }
        break;
        case ZEROGRADIENT:
        {
            cP = cPSouthNode->GetP();
        }
        break;
    }

    return 0.0;
}
void NorthBoundary::CalculateU(double dt)
{
    switch(cType)
    {
        case ZEROGRADIENT:
        {
            cU = cPSouthNode->GetU();
        }
        break;
    }
}
void NorthBoundary::CalculateV(double dt)
{
    switch(cType)
    {
        case ZEROGRADIENT:
        {
            cV = cPSouthNode->GetV();
        }
        break;
    }
}

void NorthBoundary::SetSouthNode(Node const* pSouthNode)
{
    cPSouthNode = pSouthNode;
}