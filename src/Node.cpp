#include "Node.h"
#include <iostream>

Node::Node(double x, double y, double initValue)
:
cX(x),
cY(y),
cValue(initValue)
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

double Node::GetValue() const
{
    return cValue;
}
}