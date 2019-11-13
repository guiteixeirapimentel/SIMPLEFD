#ifndef CELLNODE_H
#define CELLNODE_H
#include "StaggeredNode.h"
#include "PressureNode.h"

class CellNode
{
public:
    CellNode(double dx, double dy, double xPressure, double yPressure, double initPressure,
     double initU, double initV, bool notused = false);
    
    ~CellNode();

    virtual void SetRightNeighbor(CellNode const* pRightNeighbor);
    virtual void SetLeftNeighbor(CellNode const* pLeftNeighbor);
    virtual void SetTopNeighbor(CellNode const* pTopNeighbor);
    virtual void SetBottomNeighbor(CellNode const* pBottomNeighbor);

    CellNode const* GetRightNeighbor() const;
    CellNode const* GetLeftNeighbor() const;
    CellNode const* GetTopNeighbor() const;
    CellNode const* GetBottomNeighbor() const;

    PressureNode const* GetPPressureNode() const;
    StaggeredNode const* GetPRightStaggeredNode() const;  //V
    StaggeredNode const* GetPBottomStaggeredNode() const; //U

    void CalculateNextVelocity(double dt, double rho, double mu);
    
    double Relax(double dt, double rho);

    void CalculateNextPressure(double alfa = 0.8); 

protected:
    PressureNode*  cPPressureNode;

    StaggeredNode*  cPRightStaggeredNode;  //V
    StaggeredNode*  cPBottomStaggeredNode; //U

    CellNode const* cPRightNeighbor;
    CellNode const* cPBottomNeighbor;
    CellNode const* cPLeftNeighbor;
    CellNode const* cPTopNeighbor;

    const double cdx;
    const double cdy;
};

#endif