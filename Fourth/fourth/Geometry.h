#pragma once
#include<string>

using namespace std;

struct Rect
{
	double xmin;
	double ymin;
	double xmax;
	double ymax;
};


class Geometry
{
public:
	Geometry();
	virtual ~Geometry();



	virtual string GeometryType() = 0;
	virtual Rect Envelope() = 0;
	virtual double Distance(Geometry* g) = 0;
};

