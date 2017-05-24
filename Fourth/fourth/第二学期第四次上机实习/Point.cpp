#include "stdafx.h"
#include "Point.h"


Point::Point(double xx = 0, double yy = 0)
{
	X = xx;
	Y = yy;
}


Point::~Point()
{
}

string Point::GeometryType() {
	return "Point";
}

double Point::Distance(Geometry* p) {
	Point* t = (Point*)p;
	return sqrt((t->GetX() - this->GetX())*(t->GetX()-this->GetX())+ (t->GetY() - this->GetY())*(t->GetY() - this->GetY()));
}
