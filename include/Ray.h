#ifndef RAY_H
#define RAY_H
class Ray;
#include "Vertex.h"
#include "Direction.h"
#include "Line.h"
class Ray{
public:
	Vertex* source;
	Direction direction;
    Ray();
	Ray(Vertex* s, Direction dir);
	Line getSupportingLine();
	void print();
};
#endif
