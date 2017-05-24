#include "Rectangle.h"



Rectangle::Rectangle(Line* head)
{
	lineNum = 4;
	ptLine = new Line[4];
	if (head->GetCount()!=4)
	{
		throw "The Line's Number mustbe 4";
	}
	for (int i = 0; i < 4; i++)
	{
		ptLine[i].GetVertex(i)->SetX(head[i].GetVertex(i)->GetX());
	}
	width = ptLine[0].GetVertex(1)->Distance(ptLine[0].GetVertex(2));
	high= ptLine[1].GetVertex(1)->Distance(ptLine[1].GetVertex(2));
}

Rectangle::Rectangle()
{
	ptLine = new Line[4];
	lineNum = 4;
}


Rectangle::~Rectangle()
{
}

double Rectangle::GetWidth()
{
	return width;
}

double Rectangle::GetHeight()
{
	return high;
}

double Rectangle::GetDiagonal()
{
	return ptLine[0].GetVertex(1)->Distance(ptLine[2].GetVertex(1));
}
Line* Rectangle::GetDiagonal(int num)
{
	Line l(2);
	switch (num)
	{
	case 1:
		l.GetVertex(1)->SetX(ptLine[0].GetVertex(1)->GetX());
		l.GetVertex(1)->SetY(ptLine[0].GetVertex(1)->GetY());
		l.GetVertex(2)->SetX(ptLine[2].GetVertex(1)->GetX());
		l.GetVertex(1)->SetX(ptLine[2].GetVertex(1)->GetY());
		break;
	case 2:
		l.GetVertex(1)->SetX(ptLine[1].GetVertex(1)->GetX());
		l.GetVertex(1)->SetY(ptLine[1].GetVertex(1)->GetY());
		l.GetVertex(2)->SetX(ptLine[3].GetVertex(1)->GetX());
		l.GetVertex(1)->SetX(ptLine[3].GetVertex(1)->GetY());
		break;
	default:
		break;
	}
	return &l;
}

void Rectangle::SetPoint(Point * p1, Point * p2, Point * p3, Point * p4)
{
	ptLine[0].GetVertex(1)->SetX(p1->GetX());
	ptLine[0].GetVertex(1)->SetY(p1->GetY());
	ptLine[0].GetVertex(2)->SetX(p2->GetX());
	ptLine[0].GetVertex(2)->SetY(p2->GetY());


	ptLine[1].GetVertex(1)->SetX(p2->GetX());
	ptLine[1].GetVertex(1)->SetY(p2->GetY());
	ptLine[1].GetVertex(2)->SetX(p3->GetX());
	ptLine[1].GetVertex(2)->SetY(p3->GetY());

	ptLine[2].GetVertex(1)->SetX(p3->GetX());
	ptLine[2].GetVertex(1)->SetY(p3->GetY());
	ptLine[2].GetVertex(2)->SetX(p4->GetX());
	ptLine[2].GetVertex(2)->SetY(p4->GetY());

	ptLine[3].GetVertex(1)->SetX(p4->GetX());
	ptLine[3].GetVertex(1)->SetY(p4->GetY());
	ptLine[3].GetVertex(2)->SetX(p1->GetX());
	ptLine[3].GetVertex(2)->SetY(p1->GetY());
	width = ptLine[0].GetVertex(1)->Distance(ptLine[0].GetVertex(2));
	high = ptLine[1].GetVertex(1)->Distance(ptLine[1].GetVertex(2));
}


//father
//面积
double Rectangle::GetArea()
{
	return width*high;
 }
//周长
double Rectangle::GetPerimeter()
{
	return 2 * (width + high);
 }
 //获得端点
Point* Rectangle::GetVertex(int num)
{
	//获得1~4号位的点
	switch (num)
	{
	case 1:
		return ptLine[1].GetVertex(1);
		break;
	case 2:
		return ptLine[1].GetVertex(2);
		break;
	case 3:
		return ptLine[3].GetVertex(1);
		break;
	case 4:
		return ptLine[3].GetVertex(1);
		break;
	default:
		break;
	}
	return NULL;
 }
//获得端点的数量
int Rectangle::GetVCount()
{
	return 4;
 }
//获得重心
Point* Rectangle::Centroid()
{
	Point p;
	p.SetX((ptLine[1].GetVertex(1)->GetX() + ptLine[3].GetVertex(1)->GetX()) / 2);
	p.SetY((ptLine[1].GetVertex(1)->GetY() + ptLine[3].GetVertex(1)->GetY()) / 2);
	return &p;
 }
//获得边的数量
int Rectangle::GetECount()
{
	return 4;
 }
//获得边缘
Line* Rectangle::GetEdge(int n)
{
	return &ptLine[n - 1];
}


						  //grandfather
string Rectangle::GeometryType()
{
	return "Rectangle";
 }
Rect Rectangle::Envelope()
{
	Rect rect;
	rect.xmax = ptLine[1].GetVertex(1)->GetX();
	rect.xmin = ptLine[3].GetVertex(2)->GetX();
	rect.ymax = ptLine[1].GetVertex(1)->GetY();
	rect.ymin = ptLine[3].GetVertex(2)->GetY();
	return rect;
 }
double Rectangle::Distance(Geometry* g)
{
	double distance = 0;


	Point *p = dynamic_cast<Point*>(g);
	if (p)
	{
		distance = p->Distance(&ptLine[0]);
		for (int i = 0; i < this->lineNum; i++)
		{
			if (p->Distance(&ptLine[i])<distance)
			{
				distance = p->Distance(&ptLine[i]);
			}
		}
		
	}
	return distance;
 }