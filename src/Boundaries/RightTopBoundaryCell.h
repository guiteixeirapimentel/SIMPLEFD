#ifndef RIGHTTOPBOUNDARYCELL_H
#define RIGHTTOPBOUNDARYCELL_H

#include "../CellNode.h"
 
class RightTopBoundaryCell : public CellNode
{
public:
    RightTopBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure);
    ~RightTopBoundaryCell();

    void SetRightNeighbor(CellNode const* pRightNeighbor) override
    {cPLeftNeighbor = nullptr;};
    void SetLeftNeighbor(CellNode const* pLeftNeighbor) override;
    void SetTopNeighbor(CellNode const* pTopNeighbor) override;
    void SetBottomNeighbor(CellNode const* cBottomNeighbor) override
    {cPTopNeighbor = nullptr;};
    
};

#endif