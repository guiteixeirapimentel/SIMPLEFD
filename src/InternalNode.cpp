#include "InternalNode.h"
#include <math.h>
#include <cassert>
#include <iostream>

InternalNode::InternalNode(double x, double y, double initValue)
     :
     Node(x, y, initValue)
     {}

InternalNode::~InternalNode()
{}

Node const * InternalNode::GetNorthNode() const
{
    return cPNorthNode;
}
const Node* InternalNode::GetSouthNode() const
{
    return cPSouthNode;
}
const Node* InternalNode::GetEastNode() const
{
    return cPEastNode;
}
const Node* InternalNode::GetWestNode() const
{
    return cPWestNode;
}

void InternalNode::SetNorthNode(Node* const pNorthNode)
{
    cPNorthNode = pNorthNode;

    cdyN = cY - pNorthNode->GetY();

    //assert(cdyN > 0.009 && cdyN < 0.011);
}
void InternalNode::SetSouthNode(Node* const pSouthNode)
{
    cPSouthNode = pSouthNode;

    cdyS = pSouthNode->GetY() - cY;

   // assert(cdyS > 0.009 && cdyS < 0.011);
}
void InternalNode::SetEastNode(Node* const pEastNode)
{
    cPEastNode = pEastNode;

    cdxE = pEastNode->GetX() - cX;

    //assert(cdxE > 0.009 && cdxE < 0.011);
}
void InternalNode::SetWestNode(Node* const pWestNode)
{
    cPWestNode = pWestNode;

    cdxW = cX - pWestNode->GetX();

    //assert(cdxW > 0.009 && cdxW < 0.011);
}