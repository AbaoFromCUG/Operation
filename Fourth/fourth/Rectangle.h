#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H


#include "Polygon.h"
class Rectangle :
	public Polygon
{
public:
	Rectangle(Line* head);
	Rectangle();
	virtual ~Rectangle();
	double GetWidth();
	double GetHeight();
	double GetDiagonal();
	Line* GetDiagonal(int num);

	void SetPoint(Point* p1, Point* p2, Point* p3, Point* p4);


	//father
	virtual double GetArea(); //面积
	virtual double GetPerimeter(); //周长


	virtual Point* GetVertex(int num = 0);//获得端点,左上为第一个，右上为第二个
	virtual int GetVCount();			//获得端点的数量
	virtual Point *Centroid();			//获得重心
	virtual int GetECount();		//获得边的数量
	virtual Line* GetEdge(int n);  //获得边缘


							  //grandfather
	virtual string GeometryType();
	virtual Rect Envelope();
	virtual double Distance(Geometry* g);
protected:
	double width;
	double high;
		
		
};

#endif // !RECTANGLE_H