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

	virtual double GetArea()=0; //���
	virtual double GetPerimeter() = 0; //�ܳ�
	virtual Point* GetVertex(int num = 0) = 0;//��ö˵�
	virtual int GetVCount() = 0;			//��ö˵������
	virtual Point *Centroid() = 0;			//�������
	virtual int GetECount() = 0;		//��ñߵ�����
	virtual Line* GetEdge(int n) = 0;  //��ñ�Ե

	

protected:
	long lineNum;
	Line *ptLine;

};

