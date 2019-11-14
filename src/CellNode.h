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
    StaggeredNode const* GetPRightStaggeredNode() const;  //U i+1/2
    StaggeredNode const* GetPTopStaggeredNode() const; //V j+1/2

    virtual void CalculateNextVelocity(double dt, double rho, double mu);
    
	virtual double CalculatePCorrSource(double dt, double rho);
    virtual double RelaxatePCorr(double dt, double rho);
	
    virtual void CalculateNextPressure(double alfa = 1.0); 

protected:
    PressureNode*  cPPressureNode;

    StaggeredNode*  cPRightStaggeredNode;  //U i+1/2
    StaggeredNode*  cPTopStaggeredNode; //V j+1/2

    CellNode const* cPRightNeighbor;
    CellNode const* cPBottomNeighbor;
    CellNode const* cPLeftNeighbor;
    CellNode const* cPTopNeighbor;

    const double cdx;
    const double cdy;
};

#endif