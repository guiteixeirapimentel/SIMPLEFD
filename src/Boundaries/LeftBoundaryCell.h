#ifndef LEFTBOUNDARYCELL_H
#define LEFTBOUNDARYCELL_H

#include "../CellNode.h"

class LeftBoundaryCell : public CellNode
{
public:
    LeftBoundaryCell(double dx, double dy, double xPressure, double yPressure, double initPressure, 
    double initU, double initV);
    ~LeftBoundaryCell();

    void SetRightNeighbor(CellNode const* pRightNeighbor) override;
    void SetLeftNeighbor(CellNode const* pLeftNeighbor) override
    {cPLeftNeighbor = nullptr;};
    void SetTopNeighbor(CellNode const* pTopNeighbor) override;
    void SetBottomNeighbor(CellNode const* cBottomNeighbor) override;

public:

};


#endif