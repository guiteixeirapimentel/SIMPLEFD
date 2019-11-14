#ifndef RIGHTBOTTOMBOUNDARYCELL_H
#define RIGHTBOTTOMBOUNDARYCELL_H

#include "../CellNode.h"

class RightBottomBoundaryCell : public CellNode
{
public:
    RightBottomBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure, double initV);
    ~RightBottomBoundaryCell();

    void SetRightNeighbor(CellNode const* pRightNeighbor) override
    {cPRightNeighbor = nullptr;};
    void SetLeftNeighbor(CellNode const* pLeftNeighbor) override;
    void SetTopNeighbor(CellNode const* pTopNeighbor) override;
    void SetBottomNeighbor(CellNode const* cBottomNeighbor) override
    {cPBottomNeighbor = nullptr;};

};

#endif