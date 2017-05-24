#include "Circle.h"
#include<iostream>
using namespace std;


Circle::Circle(int rr,Point* p):R(rr)
{
	lineNum = -1;
	ptLine = NULL;
	Center = new Point(p->GetX(), p->GetY());
}


Circle::~Circle()
{
	delete Center;
	Center = NULL;
}

Point* Circle::GetRadius()
{
	return Center;
}



//father
//面积
double Circle::GetArea() 
{
	return PI*R*R;
 }
//周长
double Circle::GetPerimeter() 
{
	return PI * 2 * R;
 }
//获得端点
Point* Circle::GetVertex(int num)
{
	return NULL;
 }
//获得端点的数量
int Circle::GetVCount() 
{
	return -1;
 }
 //获得重心
Point *Circle::Centroid()
{
	return Center;
 }
 //获得边的数量
int Circle::GetECount() 
{
	return lineNum;
 }
 //获得边缘
Line* Circle::GetEdge(int n)
{
	return NULL;
 }


							  //grandfather
string Circle::GeometryType()
{
	return "Circle";
 }
Rect Circle::Envelope()
{
	Rect rect;
	rect.xmax = Center->GetX() + R;
	rect.xmin = Center->GetX() - R;
	rect.ymax = Center->GetY() + R;
	rect.ymin = Center->GetY() - R;
	return rect;
 }
double Circle::Distance(Geometry* g)
{
	double distance = 0;

	Point *p = dynamic_cast<Point*>(g);
	if (p)
	{
		double d=p->Distance(this->Center);
		if (d > R)
		{
			distance = d - R;
		}
		else if (d==R)
		{
			distance = 0;
		}
		else
		{
			distance = d;
		}
	}

	Line *l = dynamic_cast<Line*>(g);
	if (l)
	{
		double m_d=Center->Distance(l);
		if (m_d>R)
		{
			distance = m_d - R;
		}
		//Line上有点在Circle上，有可能相切
		if (m_d==R)
		{
			distance = 0;
		}
		//Line在Circle内
		if (m_d<R)
		{
			distance = m_d;
		}
	}

	Circle *c = dynamic_cast<Circle*>(g);
	if (c)
	{
		double m_a= c->Center->Distance(Center);
		//相离
		if (m_a>(R+c->R))
		{
			distance=m_a - (R + c->R);
		}
		//相切
		if (m_a==(R + c->R))
		{
			distance = 0;
		}
		//相交
		if (m_a < (R + c->R)||m_a>(R-c->R))
		{
			distance = 0;
		}
		if (m_a<(R - c->R))
		{
			cout << "内含" << endl;
			distance = (R - c->R);
		}
	}
	return distance;
}