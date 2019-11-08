#ifndef WESTBOUNDARY_H
#define WESTBOUNDARY_H
#include "BoundaryField.h"

class WestBoundary : public BoundaryField
{
public:
    WestBoundary(double x, double y, double U, double V, double P, TYPE type);
    ~WestBoundary();

    void SetEastNode(Node const* pSetEastNode);

    virtual double CalculatePRelax() override;
    virtual void CalculateU(double dt) override;
    virtual void CalculateV(double dt) override;
private:
    Node const* cPEastNode;
};

#endif