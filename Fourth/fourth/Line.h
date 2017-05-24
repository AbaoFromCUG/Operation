#pragma once
#ifndef LINE_H
#define LINE_H


#include "Geometry.h"
#include"Point.h"
class Line :
	public Geometry
{
public:
	Line(Point* head, int len);
	Line(int length=2);
	Line(Line& l);
	virtual ~Line();


	Point* GetVertex(int n);
	double GetLength();
	int GetCount();


	virtual string GeometryType();
	virtual Rect Envelope();
	virtual double Distance(Geometry* g);
protected:
	long pntNum;
	Point *ptPoint;
};


#endif // !LINE_H
