#ifndef PRESSURENODE_H
#define PRESSURENODE_H

#include "Node.h"

class PressureNode : public Node
{
public:
    PressureNode(double x, double y, double initP);
    ~PressureNode();

public:
    double cP;
    double cPCorr;
};

#endif