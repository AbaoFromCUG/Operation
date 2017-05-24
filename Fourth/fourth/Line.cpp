#include "Line.h"

bool judge(Line* L1, Line* L2);

Line::Line(int length)
{
	pntNum = length;
	ptPoint = new Point[length];
	for (int i = 0; i < length; i++)
	{
		ptPoint[i].SetX(0);
		ptPoint[i].SetY(0);
	}
}

Line::Line(Point* head, int len)
{
	ptPoint = new Point[len];
	for (int i = 0; i < len; i++)
	{
		ptPoint[i].SetX(head[i].GetX());
		ptPoint[i].SetY(head[i].GetY());
	}
}
Line::Line( Line& l)
{
	pntNum = l.GetCount();
	ptPoint = new Point[pntNum];
	for (int i = 0; i < pntNum; i++)
	{

		ptPoint[i].SetX(l.GetVertex(i)->GetX());
		ptPoint[i].SetY(l.GetVertex(i)->GetY());
	}

}


Line::~Line()
{
	delete[] ptPoint;
}


Point* Line::GetVertex(int n)
{
	return &ptPoint[n-1];
}


double Line::GetLength()
{
	double length = 0;
	for (int i = 0; i < pntNum - 1; i++)
	{
		ptPoint[i + 1];
		length += ptPoint[i].Distance(&ptPoint[i+1]);
	}

	return length;
	
}


int Line::GetCount()
{
	return pntNum;
}


string Line::GeometryType()
{
	return "Line";
}
Rect Line::Envelope()
{
	Rect rect;
	rect.xmax = this->ptPoint[0].GetX();
	rect.xmin = this->ptPoint[0].GetX();
	rect.ymax = this->ptPoint[0].GetY();
	rect.ymin = this->ptPoint[0].GetY();
	for (int i = 0; i < pntNum; i++)
	{
		if (this->ptPoint[i].GetX() > rect.xmax)
		{
			rect.xmax = this->ptPoint[i].GetX();
		}
		if (this->ptPoint[i].GetX() < rect.xmin)
		{
			rect.xmin = this->ptPoint[i].GetX();
		}
		if (this->ptPoint[i].GetY() > rect.ymax)
		{
			rect.ymax = this->ptPoint[i].GetY();
		}
		if (this->ptPoint[i].GetY() < rect.ymin)
		{
			rect.ymin = this->ptPoint[i].GetY();
		}
	}
	return rect;
}
double Line::Distance(Geometry* g)
{
	double distance = 0;


	Point *p = dynamic_cast<Point*>(g);
	if (p)
	{
		distance=p->Distance(this);
	}

	Line *line = dynamic_cast<Line*>(g);
	if (line)
	{
		bool m_bool = true;
		
		for (int i = 0; i < line->pntNum; i++)
		{
			for (int j = 0; j < this->pntNum; j++)
			{
				Line m_la(line->GetVertex(i + 1), 2);
				Line m_lb(this->GetVertex(j + 1), 2);
				if (judge(&m_la, &m_lb))
				{
					distance = 0;
					m_bool = false;
					break;
				}
				else
				{
					continue;
				}
			}
			break;
		}

		if (m_bool)
		{
			//此处划水严重，请忽略
			distance= line->GetVertex(1)->Distance(this->GetVertex(1));
		}
	}
	//测试代码，请忽略
	/*
	Line* l=new Line[2];
	l[0].GetVertex(1)->SetX(1);
	l[0].GetVertex(1)->SetY(1);
	l[0].GetVertex(2)->SetX(2);
	l[0].GetVertex(2)->SetY(2);


	l[1].GetVertex(1)->SetX(1);
	l[1].GetVertex(1)->SetY(2);
	l[1].GetVertex(2)->SetX(2);
	l[1].GetVertex(2)->SetY(1);
	if (judge(&l[0], &l[1]))
	{
		//throw "出错";
	}

	*/
	return distance;
}


//求两条直线段间的最小距离

double LineToLine(Line *la, Line* lb)
{
	double  distance = 0;
	if ((la->GetCount()!=2)||(lb->GetCount()!=2))
	{
		throw "传入的两条线段非法";
	}
	else
	{
		Point* pa1 = la->GetVertex(1);
		Point* pa2 = la->GetVertex(2);
		Point* pb1 = lb->GetVertex(1);
		Point* pb2 = lb->GetVertex(2);


		if (true)
		{
			distance = 0;
		}

		else
		{
			distance = (pa1->Distance(pb1) > pa1->Distance(pb2) ? pa1->Distance(pb2) : pa1->Distance(pb1))
						> 
						(pa2->Distance(pb1) > pa2->Distance(pb2) ? pa2->Distance(pb2) : pa2->Distance(pb1));
		}
	}
	return distance;
}


//求判断两线段是否相交的代码块
double min1(Line* L)
{
	return L->GetVertex(1)->GetX() < L->GetVertex(2)->GetX() ? L->GetVertex(1)->GetX() : L->GetVertex(2)->GetX();
}
double max1(Line* L)
{
	return L->GetVertex(1)->GetX() > L->GetVertex(2)->GetX() ? L->GetVertex(1)->GetX() : L->GetVertex(2)->GetX();
}
double min2(Line* L)
{
	return L->GetVertex(1)->GetY() < L->GetVertex(2)->GetY() ? L->GetVertex(1)->GetY() : L->GetVertex(2)->GetY();
}
double max2(Line* L)
{
	return L->GetVertex(1)->GetY() > L->GetVertex(2)->GetY() ? L->GetVertex(1)->GetY() : L->GetVertex(2)->GetY();
}
bool onsegment(Line* L, Point* p)
{
	if (min1(L) <= p->GetX() && p->GetX() <= max1(L))
	{
		if (min2(L) <= p->GetY() && p->GetY() <= max2(L))
		{
			return true;
		}
	}
	return false;
}
double direction(Line* L, Point* p)
{
	return (L->GetVertex(1)->GetX() - p->GetX())*(L->GetVertex(1)->GetY() - L->GetVertex(2)->GetY()) - (L->GetVertex(1)->GetY() - p->GetY())*(L->GetVertex(1)->GetX() - L->GetVertex(2)->GetX());
}
bool judge(Line* L1, Line* L2)
{
	double d1 = direction(L2, L1->GetVertex(1));
	double d2 = direction(L2, L1->GetVertex(2));
	double d3 = direction(L1, L2->GetVertex(1));
	double d4 = direction(L1, L2->GetVertex(2));
	if (d1*d2<0 && d3*d4<0)
		return true;
	if (d1 == 0 && onsegment(L2, L1->GetVertex(1)))
		return true;
	if (d2 == 0 && onsegment(L2, L1->GetVertex(2)))
		return true;
	if (d3 == 0 && onsegment(L1, L2->GetVertex(1)))
		return true;
	if (d4 == 0 && onsegment(L1, L2->GetVertex(2)))
		return true;
	return false;
}
