#include "Collection.h"



Collection::Collection()
{
	geoNum = 0;
	head = NULL;
}


Collection::~Collection()
{
	delete[] head;
}

int Collection::GetCount()
{
	return geoNum;
}



Geometry* Collection::GetGeometry(int num)
{
	node* onenote = head;
	for (int i = 0; i < num; i++)
	{
		onenote = onenote->next;
	}
	return onenote->me;
}
double Collection::GetAllArea()
{
	double AllArea = 0;
	node* last = head;
	while (last)
	{
		Geometry* g = last->me;
		Line *l = dynamic_cast<Line*>(g);
		if (l)
		{
			AllArea += 0;
		}
		Circle *c = dynamic_cast<Circle*>(g);
		if (c)
		{
			AllArea += c->GetArea();
		}
		Rectangle *r = dynamic_cast<Rectangle*>(g);
		if (r)
		{
			AllArea += r->GetArea();
		}
		last = last->next;
	}
	return AllArea;
}
double Collection::GetAllLength()
{
	double AllLength = 0;

	node* last = head;
	while (last)
	{
		Geometry* g=last->me;
		Line *l = dynamic_cast<Line*>(g);
		if (l)
		{
			AllLength += l->GetLength();
		}
		Circle *c = dynamic_cast<Circle*>(g);
		if (c)
		{
			AllLength += c->GetPerimeter();
		}
		Rectangle *r = dynamic_cast<Rectangle*>(g);
		if (r)
		{
			AllLength += r->GetPerimeter();
		}
		last = last->next;
	}
	return AllLength;
}


void Collection::AddGeometry(Geometry* g)
{
	geoNum++;
	if (geoNum==1)
	{
		head = new node;
		head->me = g;
		head->next=NULL;
	}
	else
	{
		node* last =head;
		while (last->next )
		{
			last = last->next;
		}
		last->next = new node;
		last->next->me = g;
		last->next->next  = NULL;
	}
}

string Collection::GeometryType()
{
	return "Collection";
}

Rect Collection::Envelope()
{
	Rect rect;
	rect.xmax = 0;
	rect.ymax = 0;
	rect.xmin = 0;
	rect.ymin = 0;
	return rect;
}

double Collection::Distance(Geometry * g)
{
	return 0.0;
}
