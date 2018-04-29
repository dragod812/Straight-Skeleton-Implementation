#include "Vertex.h"
#include "Ray.h"

Vertex::Vertex(double x, double y){
	Point<double> P(x, y);
	coord = P;
	Ray* r(new Ray());
	bisector = r;
}
Vertex::Vertex(Point<double> X){
	coord = X;
	Ray* r(new Ray());
	bisector = r;
}
Vertex Vertex::operator - (const Vertex &rhs){
	Point<double> P(coord.x-rhs.coord.x,coord.y-rhs.coord.y);
	return Vertex(P);
}
double Vertex::operator * (const Vertex &rhs){
	return (coord.x*rhs.coord.y - coord.y*rhs.coord.x);
}
Type Vertex::getType(){
	Direction in(inEdge->start->coord, inEdge->end->coord), out(outEdge->start->coord, outEdge->end->coord);
	if((in * out) > 0)
		type = EDGE;
	else
		type = SPLIT;
	return type;
}
void Vertex::calculateBisector(){
    cout << "Calculate Bisector for " << coord.toString() << endl;
	cout << inEdge->end->coord.toString() <<  inEdge->start->coord.toString()<< endl;
	cout << outEdge->end->coord.toString() <<  outEdge->start->coord.toString()<< endl;

	Direction Din(inEdge->end->coord, inEdge->start->coord);
	Direction Dout(outEdge->start->coord, outEdge->end->coord);

	Din.makeUnit();
	Dout.makeUnit();
	Din.deltaX = (Din.deltaX + Dout.deltaX)/2;
	Din.deltaY = (Din.deltaY + Dout.deltaY)/2;
	bisector->source = this;
	bisector->direction = Din;
}



