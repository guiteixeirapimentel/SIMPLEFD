#ifndef INTERNALFIELD_H
#define INTERNALFIELD_H
#include "Node.h"
#include <vector>

class InternalField : public Node
{
public:
    InternalField(double x, double y, double U, double V, double P);
    ~InternalField();
    
    virtual void PreCalculatePoissonSource(double dt) override;
    virtual double CalculatePRelax() override;
    virtual void CalculateU(double dt) override;
    virtual void CalculateV(double dt) override;

    void SetNorthNode(Node* const pNorthNode);
    void SetSouthNode(Node* const pSouthNode);
    void SetEastNode(Node* const pEastNode);
    void SetWestNode(Node* const pWestNode);

    Node const* GetNorthNode() const;
    Node const* GetSouthNode() const;
    Node const* GetEastNode() const;
    Node const* GetWestNode() const;

private:
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