#include "Vertex.h"
#include "Ray.h"

Ray::Ray(){}
Ray::Ray(Vertex* s, Direction dir){
	source = s;
	direction = dir;
}
Line Ray::getSupportingLine(){
	double a, b, c;
	a = -direction.deltaY;
	b = direction.deltaX;
	c = -a*source->coord.x - b*source->coord.y;
	Line L(a, b, c);
	return L;
}
void Ray::print(){
	cout << "(" << source->coord.x << "," << source->coord.y <<")" << endl;
	cout << direction.deltaX << ", " << direction.deltaY << endl;
}

