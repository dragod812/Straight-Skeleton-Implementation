#ifndef STRAIGHTSKELETON_H
#define STRAIGHTSKELETON_H
#include<vector>
#include<queue>
#include<utility>
#include "Point.h"
#include "Intersection.h"
#include "Vertex.h"
#include "Edge.h"
#include "CLL.h"
#include "CLLNode.h"
#define VPP vector< pair< Point<double>, Point<double> > >
class StraightSkeleton{
public:
	vector< Vertex* > VT;
	vector< Edge* > ET;
	vector< Ray* > RT;
    vector< pair< Point<double>, Point<double> > > Arc;
	struct OrderByDistance{
		bool operator() (Intersection &a, Intersection &b) {
            return a.distance > b.distance;
        }
    };
	priority_queue< Intersection, vector<Intersection>, OrderByDistance > PQ;
	double dist(Point<double> v1, Point<double> v2);
    void findNearestI(Vertex* vminus1, Vertex* v, Vertex* vplus1);
	StraightSkeleton(vector< Point<double> > P);
    void processIntersections();
};
#endif

