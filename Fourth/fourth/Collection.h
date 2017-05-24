#pragma once
#include "Geometry.h"
#include"Line.h"
#include"Circle.h"
#include"Rectangle.h"

struct node {
	node* next;
	Geometry* me;
};
/*
为了满足需要，我计划将其设计为类似链表的结构
所以没有按照要求来做，仅仅作为尝试

*/
class Collection :
	public Geometry
{
public:
	Collection();
	virtual ~Collection();
	int GetCount();
	Geometry* GetGeometry(int num);
	double GetAllArea();
	double GetAllLength();


	void AddGeometry(Geometry* g);

	//grandfather
	virtual string GeometryType();
	virtual Rect Envelope();
	virtual double Distance(Geometry* g);


protected:
	long geoNum;
	node *head;
};

