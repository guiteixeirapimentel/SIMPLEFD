#ifndef BOUNDARYFIELD_H
#define BOUNDARYFIELD_H

#include "Node.h"

class BoundaryNode : public Node
{
public:
	BoundaryNode(double x, double y, double initValue);
    ~BoundaryNode();

};

#endif