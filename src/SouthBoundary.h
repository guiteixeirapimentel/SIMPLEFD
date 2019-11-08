#ifndef SOUTHBOUNDARY_H
#define SOUTHBOUNDARY_H
#include "BoundaryNode.h"

class SouthBoundary : public BoundaryNode
{
public:
	SouthBoundary(double x, double y, double initValue);
    ~SouthBoundary();

    void SetNorthNode(Node const* pNorthNode);
	
public:
    const Node* cPNorthNode;
};

#endif