#ifndef BOTTOMBOUNDARYCELL_H
#define BOTTOMBOUNDARYCELL_H

#include "../CellNode.h"

class BottomBoundaryCell : public CellNode
{
public:
    BottomBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure, 
    double initU);
    ~BottomBoundaryCell();

    void SetRightNeighbor(CellNode const* pRightNeighbor) override;
    void SetLeftNeighbor(CellNode const* pLeftNeighbor) override;
    void SetTopNeighbor(CellNode const* pTopNeighbor) override;
    void SetBottomNeighbor(CellNode const* cBottomNeighbor) override
    {cPBottomNeighbor = nullptr;};

public:

};

#endif