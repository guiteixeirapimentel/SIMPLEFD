#include "Node.h"
#include <iostream>
Node::Node(double x, double y, double U, double V, double P)
:
cX(x),
cY(y),
cP(P),
cU(U),
cV(V),
cRHO(1.0),
cNU(1.0),
cPoissonSourceTerm(0.0),
cNewU(0.0), 
cNewV(0.0)
{}

Node::~Node()
{}

double Node::GetX() const
{
    return cX;
}

double Node::GetY() const
{
    return cY;
}

double Node::GetP() const
{
    return cP;
}

double Node::GetU() const
{
    return cU;
}

double Node::GetV() const
{
    return cV;
}

void Node::EndStep()
{
    cU = cNewU;
    cV = cNewV;
}