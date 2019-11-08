#ifndef WESTBOUNDARY_H
#define WESTBOUNDARY_H
#include "BoundaryNode.h"

class WestBoundary : public BoundaryNode
{
public:
    WestBoundary(double x, double y, double initValue);
    ~WestBoundary();

    void SetEastNode(Node const* pSetEastNode);

private:
    Node const* cPEastNode;
};

#endif