#include<iostream>
#include"Line.h"
#include"Point.h"
#include"Circle.h"
#include"Collection.h"
using namespace std;
double PointToLine(Point* p, Line* l);

/*
	1.������������Geometry��Point ��Line��Circle��Rectangle��Collection�࣬�ҹ��ܴ��뾭����������
	2.Collection��ֻ�����Լ������ݳ�Ա��note* ��int �����ڴ�������������𱣴��Geographyָ�룬
		��Ϊ��Collection��ֻ�Ǳ����˼������ָ��
	3.Collection���������������ԭ�򣬲�ѯ����ûд���������ǻ����������ͳ��ȵĺ���������˲�ѯ������
		û������һ���ڵ�ĺ�����Ϊû�б��У�ֻ������һ���ڵ�ĺ���AddGeometry��Geometry* ��
	4.ûʲô��˵���ˣ�����ϻ���Ĺ������е�󣬴����������ܱȽϵͣ����Ǿ����Դ��뻹�ǿ����ܵ�
	5.��¶�˺ܶ����⣬�����Ҷ�IDE�����÷ǳ�����Ϥ��ǰ����Ϊ���˽���ؽ���6����Ŀ����ݼ�Ҳ�ǳ����˽�



*/
void main() 
{

	//һ���߶�
	Line m_linea(2);
	m_linea.GetVertex(1)->SetX(1);
	m_linea.GetVertex(1)->SetX(1);
	m_linea.GetVertex(2)->SetX(1);
	m_linea.GetVertex(2)->SetX(4);
	//һ������
	Point m_p1(2, 2);
	Point m_p2(5, 2);
	Point m_p3(5, 0);
	Point m_p4(2, 0);
	Rectangle rect;
	rect.SetPoint(&m_p1, &m_p2, &m_p3, &m_p4);

	//�����������ɹ�
	//�����ܳ��ȳɹ�

	Collection coll;
	Point m_testP(2, 2);
	Point m_testP2(1, 2);
	Circle c(2, &m_testP);


	coll.AddGeometry(&c);
	cout << endl;
	cout << "----------------�յ�------------" << endl;
	cout << coll.GetAllArea() << endl;
	cout << coll.GetAllLength() << endl;
	cout << "----------------һ��Բ�ε�������ܳ�------------"<<endl;
	coll.AddGeometry(&c);
	cout << coll.GetAllArea() << endl;
	cout << coll.GetAllLength() << endl;
	cout << "----------------����Բ�ε�������ܳ�------------" << endl;
	coll.AddGeometry(&rect);
	cout << coll.GetAllArea() << endl;
	cout << coll.GetAllLength() << endl;
	cout << "----------------һ����������Բ�ε�������ܳ�------------" << endl;
	coll.AddGeometry(&m_linea);
	cout << coll.GetAllArea() << endl;
	cout << coll.GetAllLength() << endl;
	cout << "----------------һ����������Բ�����һ���ߵĵ�������ܳ�------------" << endl;


	/*
	//�׶β���ģ��
	Point p(2,0);
	Point p2(1, 1);
	Line l(2);
	l.GetVertex(1)->SetX(4);
	l.GetVertex(1)->SetY(1);
	l.GetVertex(2)->SetX(4);
	l.GetVertex(2)->SetY(4);
	l.Distance(&p);
	*/


	//cout <<p.Distance(&l) << endl;
	//cout << p.Distance(&p2);
	/*

	int p = 3;
	int* a = &p;
	int q = 5;
	int* b = &q;
	if (typeid(p)==typeid(q))
	{
		cout << "jjjjj" << endl;
	}

	if (typeid(a) == typeid(b))
	{
		cout << "ggggg" << endl;
	}


	*/
	system("pause");
}