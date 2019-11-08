#ifndef BOUNDARYFIELD_H
#define BOUNDARYFIELD_H

#include "Node.h"

class BoundaryField : public Node
{
public:
    enum TYPE
    {
        FIXEDVALUE,
        NOSLIP,
        ZEROGRADIENT,
        ZEROGRADIENTNOSLIP
    };

public:
    BoundaryField(double x, double y, double U, double V, double P, TYPE type);
    ~BoundaryField();

    inline void PreCalculatePoissonSource(double dt)override{};
    

protected:
    TYPE cType;
};

#endif