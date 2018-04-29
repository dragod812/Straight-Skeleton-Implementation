#ifndef VERTEX_H
#define VERTEX_H
class Vertex;
#include "Point.h"
#include "CLLNode.h"
#include<memory>
#include "Ray.h"
#include "Edge.h"
#include "Direction.h"
enum Type { EDGE, SPLIT };
class Vertex{
public:
	Point<double> coord;
	Ray* bisector;
	Edge* inEdge;
	Edge* outEdge;
    CLLNode* cllNode;
	bool processed;
	Type type;
	Vertex(double x, double y);
	Vertex(Point<double> X);
	Vertex operator - (const Vertex &rhs);
	double operator * (const Vertex &rhs);
	Type getType();
    void calculateBisector();
};
#endif
