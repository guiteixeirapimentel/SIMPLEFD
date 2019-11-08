#ifndef SOUTHBOUNDARY_H
#define SOUTHBOUNDARY_H
#include "BoundaryField.h"

class SouthBoundary : public BoundaryField
{
public:
    SouthBoundary(double x, double y, double U, double V, double P, TYPE type);
    ~SouthBoundary();

    void SetNorthNode(Node const* pNorthNode);

    virtual double CalculatePRelax() override;
    virtual void CalculateU(double dt) override;
    virtual void CalculateV(double dt) override;


private:
    const Node* cPNorthNode;
};

#endif