#include "StaggeredNode.h"

StaggeredNode::StaggeredNode(double x, double y, double initValue)
:
Node(x, y),
cValue(initValue),
cValueNp(cValue)
{}

StaggeredNode::~StaggeredNode()
{}