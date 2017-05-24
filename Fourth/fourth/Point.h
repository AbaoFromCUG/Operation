 #pragma once
#ifndef POINT_H
#define POINT_H


#include "Geometry.h"


class Point :
	public Geometry
{
public:
	Point(double xx = 0, double yy = 0);
	virtual ~Point();

	double GetX();
	double GetY();
	void SetX(double xx);
	void SetY(double yy);


	virtual string GeometryType();
	virtual Rect Envelope();
	virtual double Distance(Geometry* g);
protected:

	double X;
	double Y;
};



#endif // !POINT_H