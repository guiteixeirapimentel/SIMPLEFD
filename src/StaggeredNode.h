#ifndef STAGGEREDNODE_H
#define STAGGEREDNODE_H
#include "Node.h"

class StaggeredNode : public Node
{
public:
    StaggeredNode(double x, double y, double initValue);
    ~StaggeredNode();


public:
    double cValue;
    double cValueNp;
};

#endif