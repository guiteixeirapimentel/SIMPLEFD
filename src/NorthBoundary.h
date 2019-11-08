#ifndef NORTHBOUNDARY_H
#define NORTHBOUNDARY_H
#include "BoundaryField.h"

class NorthBoundary : public BoundaryField
{
public:
    NorthBoundary(double x, double y, double U, double V, double P, TYPE type);
    ~NorthBoundary();

    void SetSouthNode(Node const* pSouthNode);

    virtual double CalculatePRelax() override;
    virtual void CalculateU(double dt) override;
    virtual void CalculateV(double dt) override;


private:
    Node const* cPSouthNode;
};

#endif