#ifndef EASTBOUNDARY_H
#define EASTBOUNDARY_H
#include "BoundaryNode.h"
#include "InternalNode.h"

class EastBoundary : public BoundaryNode
{
public:
    EastBoundary(double x, double y, double initValue);
    ~EastBoundary();

    void SetWestBoundary(Node const* pWestNode);

public:
    InternalNode const* cPWestNode;

};

#endif