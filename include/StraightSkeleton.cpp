#include<vector>
#include<queue>
#include "StraightSkeleton.h"
#include "Point.h"
#include "Intersection.h"
#include "Vertex.h"
#include "Edge.h"
double StraightSkeleton::dist(Point<double> v1, Point<double> v2){
    double dx = v1.x - v2.x, dy = v1.y - v2.y;
    return sqrt(dx*dx + dy*dy);
}
void StraightSkeleton::findNearestI(Vertex* vminus1, Vertex* v, Vertex* vplus1){
    Intersection Iminus1(vminus1->bisector, v->bisector);
    Intersection res;
    if(Iminus1.intersect)
        res = Iminus1;
    Intersection Iplus1(v->bisector, vplus1->bisector);

    if(Iplus1.intersect &&  dist(res.P, v->coord) > dist(Iplus1.P, v->coord))
        res = Iplus1;
    if(Iminus1.intersect || Iplus1.intersect)
        PQ.push(res);
}
StraightSkeleton::StraightSkeleton(vector< Point<double> > P){
    cout << "//created Vertices from points" << endl;
    for(int i = 0;i<P.size();i++){
         Vertex*  Vi(new Vertex(P[i]));
        VT.push_back(Vi);
    }
    cout << "//add the vertices to the circular linked list" << endl;
    CLL* lav(new CLL());
    cout << "YES" << endl;
    for(int i = 0;i<VT.size();i++){
        VT[i]->coord.print();
        lav->addLast(VT[i]);
    }

    cout << "//link edges one by one" << endl;
    Edge* En(new Edge(VT[VT.size() - 1], VT[0]));
    ET.push_back(En);
    VT[0]->inEdge = En;
    cout << VT[0]->coord.toString()<< "inEdge"  <<  VT[0]->inEdge->start->coord.toString() <<VT[0]->inEdge->end->coord.toString() << endl;

    VT[VT.size() - 1]->outEdge = En;
    cout << VT[VT.size()-1]->coord.toString()<< "outEdge"  <<  VT[VT.size() - 1]->outEdge->start->coord.toString() <<VT[VT.size() - 1]->outEdge->end->coord.toString() << endl;
    for(int i = 1;i<VT.size();i++){
        Edge* Ei(new Edge(VT[i-1], VT[i]));
        VT[i]->inEdge = Ei;
    cout << VT[i]->coord.toString()<< "inEdge"  <<  VT[i]->inEdge->start->coord.toString() <<VT[i]->inEdge->end->coord.toString() << endl;
        VT[i-1]->outEdge = Ei;
    cout << VT[i-1]->coord.toString()<< "outEdge"  <<  VT[i-1]->outEdge->start->coord.toString() <<VT[i-1]->outEdge->end->coord.toString() << endl;
        ET.push_back(Ei);
    }
    cout << "//calculate bisector of all vertices" << endl;
    for(int i = 0;i<VT.size();i++){
        VT[i]->calculateBisector();
    }

    cout << "//for each vertex V compute the nearer intersection of the bisector bi with adjacent vertex bisectors bi-1 and bi+1" << endl;
    int N = VT.size();
    findNearestI(VT[N-2], VT[N-1], VT[0]);
    findNearestI(VT[N-1], VT[0], VT[1]);
    for(int i = 1;i<N-1;i++){

        findNearestI(VT[i-1], VT[i], VT[i+1]);
    }
    processIntersections();

}
void StraightSkeleton::processIntersections(){
    while(!PQ.empty()){
        Intersection X = PQ.top();
        PQ.pop();
        if(X.isProcessed())
            continue;
        if(X.createArc(Arc))
            continue;
        cout << "//mark va, vb as processed" << endl;
        X.Va->item->processed = true;
        X.Vb->item->processed = true;
        cout << "//create new vertex for intersection and return a CLLNode" << endl;
        CLLNode* cllnv = X.modifyLav();
        cout << "//compute the nearer intersection of the bisector bi with adjacent vertex bisectors bi-1 and bi+1" << endl;
        cout << "//push it into the priority queue" << endl;
        findNearestI(cllnv->back->item, cllnv->item, cllnv->forward->item);
    }
}
