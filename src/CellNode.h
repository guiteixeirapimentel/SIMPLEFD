#ifndef CELLNODE_H
#define CELLNODE_H
#include "StaggeredNode.h"
#include "PressureNode.h"

class CellNode
{
public:
    CellNode(double dx, double dy, double xPressure, double yPressure, double initPressure, double initU,
    double initV, bool notused = false);
    
    ~CellNode();

    virtual void SetRightNeighbor(CellNode const* pRightNeighbor);
    virtual void SetLeftNeighbor(CellNode const* pLeftNeighbor);
    virtual void SetTopNeighbor(CellNode const* pTopNeighbor);
    virtual void SetBottomNeighbor(CellNode const* cBottomNeighbor);

public:
    PressureNode*  cPPressureNode;

    StaggeredNode*  cPRightStaggeredNode;
    StaggeredNode*  cPBottomStaggeredNode;

    CellNode const* cPRightNeighbor;
    CellNode const* cPBottomNeighbor;
    CellNode const* cPLeftNeighbor;
    CellNode const* cPTopNeighbor;
};

#endif