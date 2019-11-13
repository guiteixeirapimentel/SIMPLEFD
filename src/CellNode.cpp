#include "CellNode.h"

CellNode::CellNode(double dx, double dy, double xPressure, double yPressure, double initPressure, double initU,
    double initV, bool boundary)
    :
cPPressureNode(nullptr),
cPRightNeighbor(nullptr),
cPTopNeighbor(nullptr),
cPLeftNeighbor(nullptr),
cPBottomNeighbor(nullptr),
cPRightStaggeredNode(nullptr),
cPBottomStaggeredNode(nullptr),
cdx(dx),
cdy(dy)
{
    if(!boundary)
    {
        // Inicializa staggered nodes por padrão
        cPRightStaggeredNode = new StaggeredNode(xPressure + (dx/2.0), 
        yPressure, initU);

        cPBottomStaggeredNode = new StaggeredNode(xPressure, 
        yPressure + (dy/2.0), initV);
    }

    cPPressureNode = new PressureNode(xPressure, yPressure, initPressure);
}

CellNode::~CellNode()
{
    if(cPRightStaggeredNode)
    {
        delete cPRightStaggeredNode;
        cPRightStaggeredNode = nullptr;
    }
    if(cPBottomStaggeredNode)
    {
        delete cPBottomStaggeredNode;
        cPBottomStaggeredNode = nullptr;
    }
    if(cPPressureNode)
    {
        delete cPPressureNode;
        cPPressureNode = nullptr;
    }
}

 void CellNode::SetRightNeighbor(CellNode const* pRightNeighbor)
 {
     cPRightNeighbor = pRightNeighbor;
 }
 void CellNode::SetLeftNeighbor(CellNode const* pLeftNeighbor)
 {
     cPLeftNeighbor = pLeftNeighbor;
 }
 void CellNode::SetTopNeighbor(CellNode const* pTopNeighbor)
 {
     cPTopNeighbor = pTopNeighbor;
 }
 void CellNode::SetBottomNeighbor(CellNode const* pBottomNeighbor)
 {
     cPBottomNeighbor = pBottomNeighbor;
 }

CellNode const* CellNode::GetRightNeighbor() const
{
    return cPRightNeighbor;
}

CellNode const* CellNode::GetLeftNeighbor() const
{
    return cPLeftNeighbor;
}

CellNode const* CellNode::GetTopNeighbor() const
{
    return cPTopNeighbor;
}

CellNode const* CellNode::GetBottomNeighbor() const
{
    return cPBottomNeighbor;
}    

void CellNode::SetRightNeighbor(CellNode const* pRightNeighbor)
{
    cPRightNeighbor = pRightNeighbor;
}
void CellNode::SetLeftNeighbor(CellNode const* pLeftNeighbor)
{
    cPLeftNeighbor = pLeftNeighbor;
}

void CellNode::SetTopNeighbor(CellNode const* pTopNeighbor)
{
    cPTopNeighbor = pTopNeighbor;
}
void CellNode::SetBottomNeighbor(CellNode const* pBottomNeighbor)
{
    cPBottomNeighbor = pBottomNeighbor;
}