#include "BoundaryField.h"

BoundaryField::BoundaryField(double x, double y, double U, double V, double P,TYPE type)
:
Node(x, y, U, V, P),
cType(type)
{}

BoundaryField::~BoundaryField()
{}