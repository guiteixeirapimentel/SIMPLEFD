#include "CellNode.h"

CellNode::CellNode(double dx, double dy, double xPressure, double yPressure, double initPressure, double initU,
    double initV, bool boundary)
    :
cPPressureNode(nullptr),
cPRightStaggeredNode(nullptr),
cPBottomStaggeredNode(nullptr),
cPRightNeighbor(nullptr),
cPBottomNeighbor(nullptr),
cPLeftNeighbor(nullptr),
cPTopNeighbor(nullptr),
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

PressureNode const* CellNode::GetPPressureNode() const
{
    return cPPressureNode;
}
StaggeredNode const* CellNode::GetPRightStaggeredNode() const
{
    return cPRightStaggeredNode;
}
StaggeredNode const* CellNode::GetPBottomStaggeredNode() const
{
    return cPBottomStaggeredNode;
}

void CellNode::CalculateNextVelocity(double dt, double rho, double mu)
{
    const double Uipthreehalfj = cPRightNeighbor->GetPRightStaggeredNode()->cValue;
    const double Uimhalfj = cPLeftNeighbor->GetPRightStaggeredNode()->cValue;
    const double Uiphalfjp = cPTopNeighbor->GetPRightStaggeredNode()->cValue;
    const double Uiphalfjm = cPBottomNeighbor->GetPRightStaggeredNode()->cValue;    
    const double Uiphalfj = cPRightStaggeredNode->cValue;

    const double VBiphalfjp = 0.5 * (cPTopNeighbor->GetPBottomStaggeredNode()->cValue + cPTopNeighbor->GetRightNeighbor()->GetPBottomStaggeredNode()->cValue);
    const double Viphalfjm = 0.5 * (cPBottomStaggeredNode->cValue + cPRightNeighbor->GetPBottomStaggeredNode()->cValue);

    const double Pipj = cPRightNeighbor->GetPPressureNode()->cP;
    const double Pij = cPPressureNode->cP;
    
    const double AStar = 
    -(
        (((rho * Uipthreehalfj*Uipthreehalfj) - (rho * Uimhalfj*Uimhalfj))/(2.0 * cdx))
        +
        (((rho*Uiphalfjp*VBiphalfjp)-(rho*Uiphalfjm))/(2.0*cdy))
    )
    
    +
    (mu 
    * 
    (
        ((Uipthreehalfj-(2.0*Uiphalfj)+Uimhalfj)/(cdx*cdx))
        +
        ((Uiphalfjp - (2.0*Uiphalfj)+Uiphalfjm)/(cdy*cdy))       
    
    )
    );

    cPRightStaggeredNode->cValueNp = (rho * Uiphalfj)+ (AStar*dt)-
    ((dt/cdx)*(Pipj-Pij));

    // To do: Alterar bottom to top (CELL NODE POSSUI TOP E RIGHT STAGGERED NODE)
    // TODO: Ajustar cada classe de boundary para ajustar a essa mudança.
    // to do: Escrever Equação 6.95.

    const double Vijphalf = cPTopNeighbor->GetPBottomStaggeredNode()->cValue;
    const double Vipjphalf = cPRightNeighbor->GetTopNeighbor()->GetPBottomStaggeredNode()->cValue;
    const double Vimjphalf = cPLeftNeighbor->GetTopNeighbor()->GetPBottomStaggeredNode()->cValue;
    const double Vijpthreehalf = cPTopNeighbor->GetTopNeighbor()->GetPBottomStaggeredNode()->cValue;
    const double Vijmhalf = cPBottomStaggeredNode->cValue;
}
    
double CellNode::Relax(double dt, double rho);

void CellNode::CalculateNextPressure(double alfa = 0.8); 