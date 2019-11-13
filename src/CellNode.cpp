#include "CellNode.h"

CellNode::CellNode(double dx, double dy, double xPressure, double yPressure, double initPressure, double initU,
    double initV, bool boundary)
    :
cPPressureNode(nullptr),
cPRightNeighbor(nullptr),
cPTopNeighbor(nullptr),
cPLeftNeighbor(nullptr),
cPBottomNeighbor(nullptr),
cPRightStaggeredNode(nullptr),
cPBottomStaggeredNode(nullptr)
{
    if(!boundary)
    {
        // Inicializa staggered nodes por padrão
        cPRightStaggeredNode = new StaggeredNode(xPressure + (dx/2.0), 
        yPressure, initU);

        cPBottomStaggeredNode = new StaggeredNode(xPressure, 
        yPressure + (dy/2.0), initV);
    }

    cPPressureNode = new PressureNode(xPressure, yPressure, initPressure);
}