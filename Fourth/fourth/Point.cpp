#include "Point.h"
#include"Line.h"
#include<iostream>
using namespace std;
double PointToLine(Point* p, Line* l);

Point::Point(double xx, double yy):X(0),Y(0)
{
	X = xx;
	Y = yy;
}


Point::~Point()
{
}


double Point::GetX()
{
	return X;

}
double Point::GetY()
{
	return Y;

}
void Point::SetX(double xx)
{
	X = xx;
}
void Point::SetY(double yy)
{
	Y = yy;
}





string Point::GeometryType()
{
	return "Point";
}
Rect Point::Envelope()
{
	Rect rect;
	rect.xmax = X;
	rect.xmin = X;
	rect.ymax = Y;
	rect.ymin = Y;
	return rect;
}
double Point::Distance(Geometry* g)
{
	double length = 0;

	Point *p = dynamic_cast<Point*>(g);
	if (p)
	{
		
		length = sqrt((p->GetX() - this->GetX())*(p->GetX() - this->GetX()) + (p->GetY() - this->GetY())*(p->GetY() - this->GetY()));
	}



	//dynamic_cast³¢ÊÔ×ª»»£¬Èô×ª»»Ê§°ÜtÎª0£¨NULL£©
	Line *t = dynamic_cast<Line*>(g);
	
	if (t)
	{
		
		Line *m_La = new Line(2);
		m_La->GetVertex(1)->SetX(t->GetVertex(1)->GetX());
		m_La->GetVertex(1)->SetY(t->GetVertex(1)->GetY());
		m_La->GetVertex(2)->SetX(t->GetVertex(2)->GetX());
		m_La->GetVertex(2)->SetY(t->GetVertex(2)->GetY());
		length = PointToLine(this, m_La);
	
		for (int i = 0; i < t->GetCount()-1; i++)
		{
			m_La->GetVertex(1)->SetX(t->GetVertex(i+1)->GetX());
			m_La->GetVertex(1)->SetY(t->GetVertex(i + 1)->GetY());
			m_La->GetVertex(2)->SetX(t->GetVertex(i + 2)->GetX());
			m_La->GetVertex(2)->SetY(t->GetVertex(i + 2)->GetY());
			if (length>PointToLine(this, m_La))
			{
				length = PointToLine(this, m_La);
			}
			
		}
		
	}
	typeid(g);


	return length;
}




double PointToLine(Point* p, Line* l) {
	if (l->GetCount() != 2)
	{
		throw "Aerr";
	
	}
	
	double cross = (l->GetVertex(2)->GetX() - l->GetVertex(1)->GetX()) * (p->GetX() - l->GetVertex(1)->GetX()) + (l->GetVertex(2)->GetY() - l->GetVertex(1)->GetY()) * (p->GetY() - l->GetVertex(1)->GetY());
	if (cross <= 0)
		return sqrt((p->GetX() - l->GetVertex(1)->GetX()) * (p->GetX() - l->GetVertex(1)->GetX()) + (p->GetY() - l->GetVertex(1)->GetY()) * (p->GetY() - l->GetVertex(1)->GetY()));

	double d2 = (l->GetVertex(2)->GetX() - l->GetVertex(1)->GetX()) * (l->GetVertex(2)->GetX() - l->GetVertex(1)->GetX()) + (l->GetVertex(2)->GetY() - l->GetVertex(1)->GetY()) * (l->GetVertex(2)->GetY() - l->GetVertex(1)->GetY());
	if (cross >= d2)
		return sqrt((p->GetX() - l->GetVertex(2)->GetX()) * (p->GetX() - l->GetVertex(2)->GetX()) + (p->GetY() - l->GetVertex(2)->GetY()) * (p->GetY() - l->GetVertex(2)->GetY()));

	double r = cross / d2;
	double px = l->GetVertex(1)->GetX() + (l->GetVertex(2)->GetX() - l->GetVertex(1)->GetX()) * r;
	double py = l->GetVertex(1)->GetY() + (l->GetVertex(2)->GetY() - l->GetVertex(1)->GetY()) * r;
	return sqrt((p->GetX() - px) * (p->GetX() - px) + (p->GetY() - py) * (p->GetY() - py));
	
}