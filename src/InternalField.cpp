#include "InternalField.h"
#include <math.h>
#include <cassert>
#include <iostream>

InternalField::InternalField(double x, double y, double U, double V, double P)
     :
     Node(x, y, U, V, P)
     {}

InternalField::~InternalField()
{}

void InternalField::PreCalculatePoissonSource(double dt)
{
    cPoissonSourceTerm = 
    (-cRHO * (
        pow((cPEastNode->GetU() - cPWestNode->GetU())/(cdxE+cdxW), 2)
        + (2.0*
            ((cPSouthNode->GetU() - cPNorthNode->GetU())/(cdyN+cdyS)) * 
            (cPEastNode->GetV() - cPWestNode->GetV())/(cdxE+cdxW))
        
        + pow((cPSouthNode->GetV()-cPNorthNode->GetV())/(cdyS+cdyN), 2))
        )

        + (
            (cRHO/dt)*(

                ((cPEastNode->GetU()-cPWestNode->GetU()) / (cdxE+cdxW)) 
                + ((cPSouthNode->GetV() - cPNorthNode->GetV())/(cdyN+cdyS))

                )

        );
}

double InternalField::CalculatePRelax()
{
    double nP = 0.0;

    nP = (
        (cdxE*cdxW*(cPSouthNode->GetP() + cPNorthNode->GetP()))
        +
        (cdyN*cdyS*(cPEastNode->GetP()+cPWestNode->GetP()))
        -
        (cdxE*cdxW*cdyN*cdyS*cPoissonSourceTerm)
        )/ (2.0*((cdxE*cdxW)+(cdyN*cdyS)));

    double dif = abs(nP - cP);

    cP = nP;

    return dif;
}
void InternalField::CalculateU(double dt)
{
    cNewU = cU - ((cU * dt / cdxW) * (cU - cPWestNode->GetU()))
    - ((cV * dt / cdyS)*(cU - cPNorthNode->GetU()))
    - (((dt/(cRHO*(cdxW+cdxE)))*(cPEastNode->GetP() - cPWestNode->GetP())))
    + (cNU * dt * (
        ((cPEastNode->GetU() - (2.0 * cU) + cPWestNode->GetU())/(cdxE*cdxW))
        + 
        (((cPSouthNode->GetU() - (2.0*cU) + cPNorthNode->GetU())/(cdyS*cdyN)))
        )
    );

	//std::cout << "cNewU: " << cNewU << std::endl;
	//std::cout << "Press Term: " << cPEastNode->GetP() - cPWestNode->GetP() << std::endl;
	//std::cout << "Pressao West: " << cPWestNode->GetP() << std::endl;
}
void InternalField::CalculateV(double dt)
{
    cNewV = cV - ((cU * dt / cdxW) * (cV - cPWestNode->GetV()))
    - ((cV * dt / cdyS)*(cV - cPNorthNode->GetV()))
    - ((dt/(cRHO*(cdyN+cdyS))*(cPSouthNode->GetP() - cPNorthNode->GetP())))
    + (cNU * dt * (
        ((cPEastNode->GetV() - (2.0 * cV) + cPWestNode->GetV())/(cdxE*cdxW))
        + 
        (((cPSouthNode->GetV() - (2.0*cV) + cPNorthNode->GetV())/(cdyS*cdyN)))
        )
    );
}

Node const * InternalField::GetNorthNode() const
{
    return cPNorthNode;
}
const Node* InternalField::GetSouthNode() const
{
    return cPSouthNode;
}
const Node* InternalField::GetEastNode() const
{
    return cPEastNode;
}
const Node* InternalField::GetWestNode() const
{
    return cPWestNode;
}

void InternalField::SetNorthNode(Node* const pNorthNode)
{
    cPNorthNode = pNorthNode;

    cdyN = cY - pNorthNode->GetY();

    //assert(cdyN > 0.009 && cdyN < 0.011);
}
void InternalField::SetSouthNode(Node* const pSouthNode)
{
    cPSouthNode = pSouthNode;

    cdyS = pSouthNode->GetY() - cY;

   // assert(cdyS > 0.009 && cdyS < 0.011);
}
void InternalField::SetEastNode(Node* const pEastNode)
{
    cPEastNode = pEastNode;

    cdxE = pEastNode->GetX() - cX;

    //assert(cdxE > 0.009 && cdxE < 0.011);
}
void InternalField::SetWestNode(Node* const pWestNode)
{
    cPWestNode = pWestNode;

    cdxW = cX - pWestNode->GetX();

    //assert(cdxW > 0.009 && cdxW < 0.011);
}