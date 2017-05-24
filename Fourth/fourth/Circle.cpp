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
//���
double Circle::GetArea() 
{
	return PI*R*R;
 }
//�ܳ�
double Circle::GetPerimeter() 
{
	return PI * 2 * R;
 }
//��ö˵�
Point* Circle::GetVertex(int num)
{
	return NULL;
 }
//��ö˵������
int Circle::GetVCount() 
{
	return -1;
 }
 //�������
Point *Circle::Centroid()
{
	return Center;
 }
 //��ñߵ�����
int Circle::GetECount() 
{
	return lineNum;
 }
 //��ñ�Ե
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
		//Line���е���Circle�ϣ��п�������
		if (m_d==R)
		{
			distance = 0;
		}
		//Line��Circle��
		if (m_d<R)
		{
			distance = m_d;
		}
	}

	Circle *c = dynamic_cast<Circle*>(g);
	if (c)
	{
		double m_a= c->Center->Distance(Center);
		//����
		if (m_a>(R+c->R))
		{
			distance=m_a - (R + c->R);
		}
		//����
		if (m_a==(R + c->R))
		{
			distance = 0;
		}
		//�ཻ
		if (m_a < (R + c->R)||m_a>(R-c->R))
		{
			distance = 0;
		}
		if (m_a<(R - c->R))
		{
			cout << "�ں�" << endl;
			distance = (R - c->R);
		}
	}
	return distance;
}