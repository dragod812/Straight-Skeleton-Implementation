#ifndef INTERSECTION_H
#define INTERSECTION_H
#include<vector>
#include<utility>
#include "Vertex.h"
#include "CLLNode.h"
#include "CLL.h"
#include "Point.h"
#include "Ray.h"
#define VPP vector< pair< Point<double>, Point<double> > >

class Intersection{
	public:
	bool intersect;
	Point<double> P;
	//Va is the current node
	 CLLNode* Va;
	 CLLNode* Vb;
	double distance;
    Intersection();
	//ray1 is the angular bisector of current node vi
	Intersection(Ray* ray1, Ray* ray2);
	double getDistance();
    bool isProcessed();
    bool createArc( VPP &Arc );
    CLLNode* modifyLav();
};
#endif
