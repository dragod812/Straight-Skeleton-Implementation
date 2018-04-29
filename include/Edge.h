#ifndef	EDGE_H
#define EDGE_H
class Edge;
#include "Vertex.h"
#include<memory>
class Edge{
	public:
	Vertex* start;
	Vertex* end;
	Edge(){

	}
	Edge(Vertex* start, Vertex* end){
		this->start = start;
		this->end = end;
	}
};
#endif
