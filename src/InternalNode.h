#ifndef INTERNALFIELD_H
#define INTERNALFIELD_H
#include "Node.h"
#include <vector>

class InternalNode : public Node
{
public:
    InternalNode(double x, double y, double initValue);
    ~InternalNode();
    
    void SetNorthNode(Node* const pNorthNode);
    void SetSouthNode(Node* const pSouthNode);
    void SetEastNode(Node* const pEastNode);
    void SetWestNode(Node* const pWestNode);

    Node const* GetNorthNode() const;
    Node const* GetSouthNode() const;
    Node const* GetEastNode() const;
    Node const* GetWestNode() const;

public:
    Node const *cPNorthNode;
    Node const *cPSouthNode;
    Node const *cPEastNode;
    Node const *cPWestNode;

    double cdxE;
    double cdxW;
    double cdyN;
    double cdyS;
};
#endif