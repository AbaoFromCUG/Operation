#pragma once
#include "Polygon.h"

#define PI 3.14


class Circle :
	public Polygon
{
public:
	Circle(int rr,Point*p);
	virtual ~Circle();
	Point* GetRadius();


	//father
	virtual double GetArea() ; //面积
	virtual double GetPerimeter() ; //周长
	virtual Point* GetVertex(int num = 0);//获得端点
	virtual int GetVCount();			//获得端点的数量
	virtual Point *Centroid() ;			//获得重心
	virtual int GetECount() ;		//获得边的数量
	virtual Line* GetEdge(int n) ;  //获得边缘


	//grandfather
	virtual string GeometryType();
	virtual Rect Envelope();
	virtual double Distance(Geometry* g);


protected:
	Point* Center;
	double R;
};

