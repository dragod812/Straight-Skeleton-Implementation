#include "Intersection.h"
#include "Direction.h"
#include "Vertex.h"
#include "Line.h"
#include "Point.h"
#include "Ray.h"

//ray1 is the angular bisector of current node vi
Intersection::Intersection()
{
}
Intersection::Intersection(Ray* ray1, Ray* ray2){
    Line L1 = ray1->getSupportingLine();
    cout << L1.a << " "<< L1.b << " "<< L1.c << endl;
    Line L2 = ray2->getSupportingLine();
    double det = L1.a*L2.b - L2.a*L1.b;
    double x, y;
    if(det == 0){
        intersect = false;
    }
    else{
        intersect = true;
        x = (L1.b*L2.c - L2.b*L1.c)/det;
        y = (L2.a*L1.c - L1.a*L2.c)/det;
    }
    P.x = x;
    P.y = y;
    Va = ray1->source->cllNode;
    Vb = ray2->source->cllNode;

    //calculate the distance from Ei
    getDistance();
}
double Intersection::getDistance(){
    Point<double> V = Va->item->coord;
    Point<double> E = Va->item->outEdge->end->coord;
    Direction VE(V, E);
    Direction VP(V, P);
    distance = (VP*VE)/(VE.mod());
    if(distance < 0)
        distance = -1*distance;
    return distance;
}
bool Intersection::isProcessed(){
    //According to Paper Va->processed && Vb->processed
    return ( Va->item->processed || Vb->item->processed);
}
bool Intersection::createArc( VPP &Arc ){
    Point<double> Pa=Va->item->coord;
    Point<double> Pb=Vb->item->coord;
    if( Va->back->back->item == Vb->item ){
        Point<double> Pc=Va->back->item->coord;
        Arc.push_back(make_pair(Pa, P));
        Arc.push_back(make_pair(Pb, P));
        Arc.push_back(make_pair(Pc, P));
        return true;
    }
    Arc.push_back(make_pair(Pa, P));
    Arc.push_back(make_pair(Pb, P));
    return false;
}
CLLNode* Intersection::modifyLav(){
    CLL* lav = Va->container;
    Vertex* v(new Vertex(P));
    CLLNode* cllv(new CLLNode(v));
    cllv->insertBetween(lav, Va->back, Vb->forward);
    v->inEdge = Va->item->inEdge;
    v->outEdge = Vb->item->outEdge;
    v->calculateBisector();
    return cllv;
}

