#ifndef EASTBOUNDARY_H
#define EASTBOUNDARY_H
#include "BoundaryField.h"

class EastBoundary : public BoundaryField
{
public:
    EastBoundary(double x, double y, double U, double V, double P, TYPE type);
    ~EastBoundary();

    void SetWestBoundary(Node const* pWestNode);


    virtual double CalculatePRelax() override;
    virtual void CalculateU(double dt) override;
    virtual void CalculateV(double dt) override;


private:
    Node const* cPWestNode;
};

#endif