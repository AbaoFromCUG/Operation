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
Ϊ��������Ҫ���Ҽƻ��������Ϊ��������Ľṹ
����û�а���Ҫ��������������Ϊ����

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

