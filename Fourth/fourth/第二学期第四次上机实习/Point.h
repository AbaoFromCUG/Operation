#pragma once
#include "Geometry.h"
class Point :
	public Geometry
{
public:
	Point(double xx=0,double yy=0);
	virtual ~Point();
	double GetX();
	double GetY(); \
	void SetX(double);
	void SetY(double);
	string GeometryType();
	double Distance(Geometry *p);
protected:
	double X;
	double Y;
};

