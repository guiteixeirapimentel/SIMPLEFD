#ifndef LEFTBOTTOMBOUNDARYCELL_H
#define LEFTBOTTOMBOUNDARYCELL_H

#include "../CellNode.h"

class LeftBottomBoundaryCell : public CellNode
{
public:
    LeftBottomBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure, 
    double initU);
    ~LeftBottomBoundaryCell();

    void SetRightNeighbor(CellNode const* pRightNeighbor) override;
    void SetLeftNeighbor(CellNode const* pLeftNeighbor) override
    {cPLeftNeighbor = nullptr;};
    void SetTopNeighbor(CellNode const* pTopNeighbor) override;
    void SetBottomNeighbor(CellNode const* cBottomNeighbor) override
    {cPBottomNeighbor = nullptr;};

public:

};

#endif