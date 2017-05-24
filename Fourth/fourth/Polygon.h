#pragma once
#include "Geometry.h"
#include"Point.h"
#include"Line.h"
class Polygon :
	public Geometry
{
public:
	Polygon();
	virtual ~Polygon();

	virtual double GetArea()=0; //面积
	virtual double GetPerimeter() = 0; //周长
	virtual Point* GetVertex(int num = 0) = 0;//获得端点
	virtual int GetVCount() = 0;			//获得端点的数量
	virtual Point *Centroid() = 0;			//获得重心
	virtual int GetECount() = 0;		//获得边的数量
	virtual Line* GetEdge(int n) = 0;  //获得边缘

	

protected:
	long lineNum;
	Line *ptLine;

};

