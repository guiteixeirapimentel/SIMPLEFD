#ifndef NORTHBOUNDARY_H
#define NORTHBOUNDARY_H
#include "BoundaryNode.h"

class NorthBoundary : public BoundaryNode
{
public:
    NorthBoundary(double x, double y, double initValue);
    ~NorthBoundary();

    void SetSouthNode(Node const* pSouthNode);

public:
    Node const* cPSouthNode;
};

#endif