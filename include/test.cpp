#include<iostream>
#include<memory>
#include "StraightSkeleton.h"
using namespace std;
int main(){
/*
	Point<double> p1(0, 0), q1(1,1), p2(1,0), q2(0,1);
	Direction d1(p1, q1), d2(p2, q2);
	shared_ptr< Vertex > v1(new Vertex(p1)), v2(new Vertex(p2));
	shared_ptr< Edge > E(new Edge(v1, v2));
	v1->outEdge = E;
    cout << d1.deltaX<< "|" << d1.deltaY << endl;
    cout << d2.deltaX << "|" << d2.deltaY << endl;
	shared_ptr<Ray> r1(new Ray(v1, d1)), r2(new Ray(v2, d2));
	Intersection I(r1, r2);
	cout << "Dist:" <<  I.getDistance() << endl;
	if(I.intersect){
		I.P.print();
	}
*/

/*	Point<double> p1(0, 0), q2(0,1), q1(1,0);
	shared_ptr< Vertex > u1(new Vertex(p1)), v1(new Vertex(q1)) , v2(new Vertex(q2));
	shared_ptr< Edge > E1(new Edge(u1,v1)), E2(new Edge(v2,u1));
	u1->inEdge = E2;
	u1->outEdge = E1;
	u1->calculateBisector();
	//u1->bisector->source = u1;
	u1->bisector->print();
*/
    vector< Point<double> > arr;
    Point<double> C(0,6); arr.push_back(C);
    Point<double> c(-1,3); arr.push_back(c);
    Point<double> D(0,0); arr.push_back(D);
    Point<double> A(3,0); arr.push_back(A);
    Point<double> a(4,3); arr.push_back(a);
    Point<double> B(3,6); arr.push_back(B);
    StraightSkeleton SS(arr);
    for(int i = 0;i<SS.Arc.size();i++){
        cout << SS.Arc[i].first.toString() << " " << SS.Arc[i].second.toString() << endl;
    }
	return 0;
}
