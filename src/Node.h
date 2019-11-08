#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node(double x, double y, double initValue);
    ~Node();

    double GetX() const;
    double GetY() const;
    double GetValue() const;
	
public:
    const double cX, cY;

    double cValue;
};

#endif