#include "PressureNode.h"

PressureNode::PressureNode(double x, double y, double initP)
:
Node(x, y),
cP(initP),
cPCorr(0.0)
{}

PressureNode::~PressureNode()
{}