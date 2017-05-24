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
	virtual double GetArea() ; //���
	virtual double GetPerimeter() ; //�ܳ�
	virtual Point* GetVertex(int num = 0);//��ö˵�
	virtual int GetVCount();			//��ö˵������
	virtual Point *Centroid() ;			//�������
	virtual int GetECount() ;		//��ñߵ�����
	virtual Line* GetEdge(int n) ;  //��ñ�Ե


	//grandfather
	virtual string GeometryType();
	virtual Rect Envelope();
	virtual double Distance(Geometry* g);


protected:
	Point* Center;
	double R;
};

