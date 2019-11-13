#ifndef RIGHTBOUNDARYCELL_H
#define RIGHTBOUNDARYCELL_H

#include "../CellNode.h"
 
class RightBoundaryCell : public CellNode
{
public:
    RightBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure, 
    double initV);
    ~RightBoundaryCell();

    void SetRightNeighbor(CellNode const* pRightNeighbor) override
    {cPLeftNeighbor = nullptr;};
    void SetLeftNeighbor(CellNode const* pLeftNeighbor) override;
    void SetTopNeighbor(CellNode const* pTopNeighbor) override;
    void SetBottomNeighbor(CellNode const* cBottomNeighbor) override
    {cPTopNeighbor = nullptr;};

public:

};

#endif