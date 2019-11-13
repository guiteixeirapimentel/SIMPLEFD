#ifndef LEFTTOPBOUNDARYCELL_H
#define LEFTTOPBOUNDARYCELL_H

#include "../CellNode.h"

class LeftTopBoundaryCell : public CellNode
{
public:
    LeftTopBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure, 
    double initU, double initV);
    ~LeftTopBoundaryCell();

    void SetRightNeighbor(CellNode const* pRightNeighbor) override;
    void SetLeftNeighbor(CellNode const* pLeftNeighbor) override
    {cPLeftNeighbor = nullptr;};
    void SetTopNeighbor(CellNode const* pTopNeighbor) override
    {cPTopNeighbor = nullptr;};
    void SetBottomNeighbor(CellNode const* cBottomNeighbor) override;

};


#endif