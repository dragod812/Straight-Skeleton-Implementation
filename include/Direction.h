#ifndef DIRECTION_H 
#define DIRECTION_H
#include "Point.h"
#include<iostream> 
#include<math.h>
class Direction{
	public:
	double deltaX, deltaY;
	Direction(){
	}
	Direction(Point<double> start, Point<double> end)
	{
		Point<double> P = end - start;
		deltaX = P.x;
		deltaY = P.y;
	}
	Direction(double deltaX, double deltaY){
		this->deltaX = deltaX;
		this->deltaY = deltaY;
	}
    void makeUnit(){
        double M = mod();
		cout << M << endl;
        deltaX = deltaX/M;
        deltaY = deltaY/M;
    }
        
	double mod(){
		return sqrt(deltaX*deltaX + deltaY*deltaY);
	}
    double operator * (const Direction &rhs){
		return (deltaX*rhs.deltaY - deltaY*rhs.deltaX);
	} 
};
#endif
