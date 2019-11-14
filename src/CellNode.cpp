#include "CellNode.h"
#include <cmath>

CellNode::CellNode(double dx, double dy, double xPressure, double yPressure, double initPressure, double initU,
    double initV, bool boundary)
    :
cPPressureNode(nullptr),
cPRightStaggeredNode(nullptr),
cPTopStaggeredNode(nullptr),
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

        cPTopStaggeredNode = new StaggeredNode(xPressure, 
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
    if(cPTopStaggeredNode)
    {
        delete cPTopStaggeredNode;
		cPTopStaggeredNode = nullptr;
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
StaggeredNode const* CellNode::GetPTopStaggeredNode() const
{
    return cPTopStaggeredNode;
}

void CellNode::CalculateNextVelocity(double dt, double rho, double mu)
{
    const double Uipthreehalfj = cPRightNeighbor->GetPRightStaggeredNode()->cValue;
    const double Uimhalfj = cPLeftNeighbor->GetPRightStaggeredNode()->cValue;
    const double Uiphalfjp = cPTopNeighbor->GetPRightStaggeredNode()->cValue;
    const double Uiphalfjm = cPBottomNeighbor->GetPRightStaggeredNode()->cValue;    
    const double Uiphalfj = cPRightStaggeredNode->cValue;

    const double VBiphalfjp = 0.5 * (cPTopStaggeredNode->cValue + cPRightNeighbor->GetPTopStaggeredNode()->cValue);
    const double Viphalfjm = 0.5 * (cPBottomNeighbor->GetPTopStaggeredNode()->cValue + 
		cPRightNeighbor->cPBottomNeighbor->GetPTopStaggeredNode()->cValue);

    const double Pipj = cPRightNeighbor->GetPPressureNode()->cP;
    const double Pij = cPPressureNode->cP;
    
    const double AStar = 
    -(
        (((rho * Uipthreehalfj*Uipthreehalfj) - (rho * Uimhalfj*Uimhalfj))/(2.0 * cdx))
        +
        (((rho*Uiphalfjp*VBiphalfjp)-(rho*Uiphalfjm*Viphalfjm))/(2.0*cdy))
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

    cPRightStaggeredNode->cValueNp = ((rho * Uiphalfj)+ (AStar*dt)-
    ((dt/cdx)*(Pipj-Pij))) / rho;
	
    const double Vijphalf = cPTopStaggeredNode->cValue;
    const double Vipjphalf = cPRightNeighbor->GetPTopStaggeredNode()->cValue;
    const double Vimjphalf = cPLeftNeighbor->GetPTopStaggeredNode()->cValue;
    const double Vijpthreehalf = cPTopNeighbor->GetPTopStaggeredNode()->cValue;
    const double Vijmhalf = cPBottomNeighbor->GetPTopStaggeredNode()->cValue;

	const double UBipjphalf = 0.5*(cPRightStaggeredNode+cPTopNeighbor->GetPRightStaggeredNode()->cValue);
	const double Uimjphalf = 0.5*(cPLeftNeighbor->GetPRightStaggeredNode()->cValue +
		cPTopNeighbor->GetLeftNeighbor()->GetPRightStaggeredNode()->cValue);

	const double BStar =
		-(
		(((rho * vipjphalf*UBipjphalf) - (rho * Vimjphalf*Uimjphalf)) / (2.0 * cdx))
			+
			(((rho*Vijpthreehalf*Vijpthreehalf) - (rho*Vijmhalf*Vijmhalf)) / (2.0*cdy))
			)

		+
		(mu
			*
			(
			((Vipjphalf - (2.0*Vijphalf) + Vimjphalf) / (cdx*cdx))
				+
				((Vijpthreehalf - (2.0*Vijphalf) + Vijmhalf) / (cdy*cdy))

				)
			);

	cPTopStaggeredNode->cValueNp = (rho*Vijphalf) + (BStar*dt) - ((dt / dx)*(Pijp - Pij);
}
    
double CellNode::RelaxatePCorr(double dt, double rho)
{
	const double PPipj = cPRightNeighbor->GetPPressureNode()->cPCorr;
	const double PPimj = cPLeftNeighbor->GetPPressureNode()->cPCorr;
	const double PPijp = cPTopNeighbor->GetPPressureNode()->cPCorr;
	const double PPijm = cPBottomNeighbor->GetPPressureNode()->cPCorr;

	const double B = cPPressureNode->cB;
	const double A = cPPressureNode->cA;
	const double C = cPPressureNode->cC;
	const double D = cPPressureNode->cD;

	const double temp = cPPressureNode->cPCorr;

	cPPressureNode->cPCorr = -(B*PPipj) - (B*PPimj) - (C*PPijp) - (C*PPijm) - D;

	return abs((temp - cPPressureNode->cPCorr) / temp);
}

double CellNode::CalculatePCorrSource(double dt, double rho)
{
	cPRightStaggeredNode->cValue = cPRightStaggeredNode->cValueNp;
	cPTopStaggeredNode->cValue = cPTopStaggeredNode->cValueNp;

	const double Uiphalfj = cPRightStaggeredNode->cValue;
	const double Uimhalfj = cPLeftNeighbor->GetPRightStaggeredNode()->cValue;

	const double Vijphalf = cPTopStaggeredNode->cValue;
	const double Vijmhalf = cPBottomNeighbor->GetPTopStaggeredNode()->cValue;

	cPPressureNode->cA = 2.0 *dt*((1.0 / (cdx*cdx)) + (1.0 / (cdy*cdy)));
	cPPressureNode->cB = -dt / (cdx*cdx);
	cPPressureNode->cC = -dt / (cdy*cdy);
	cPPressureNode->cD = rho * (((Uiphalfj - Uimhalfj) / cdx) + ((Vijphalf - Vijmhalf)) / cdy);

	return cPPressureNode->cD;
}

void CellNode::CalculateNextPressure(double alfa)
{
	cPPressureNode->cP += (alfa * cPPressureNode->cPCorr);
}