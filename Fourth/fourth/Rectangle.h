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
	virtual double GetArea(); //���
	virtual double GetPerimeter(); //�ܳ�


	virtual Point* GetVertex(int num = 0);//��ö˵�,����Ϊ��һ��������Ϊ�ڶ���
	virtual int GetVCount();			//��ö˵������
	virtual Point *Centroid();			//�������
	virtual int GetECount();		//��ñߵ�����
	virtual Line* GetEdge(int n);  //��ñ�Ե


							  //grandfather
	virtual string GeometryType();
	virtual Rect Envelope();
	virtual double Distance(Geometry* g);
protected:
	double width;
	double high;
		
		
};

#endif // !RECTANGLE_H