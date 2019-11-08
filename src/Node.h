#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node(double x, double y, double U, double V, double P);
    ~Node();

    double GetX() const;
    double GetY() const;
    double GetP() const;
    double GetU() const;
    double GetV() const;

    virtual double CalculatePRelax() = 0;
    virtual void CalculateU(double dt) = 0;
    virtual void CalculateV(double dt) = 0;
    virtual void PreCalculatePoissonSource(double dt) = 0;

    void EndStep();

protected:
    const double cX, cY;

    double cP, cU, cV, cPoissonSourceTerm;

    const double cRHO, cNU;

    double cNewU, cNewV;
};

#endif