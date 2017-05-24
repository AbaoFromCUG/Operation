#include<iostream>
#include"Line.h"
#include"Point.h"
#include"Circle.h"
#include"Collection.h"
using namespace std;
double PointToLine(Point* p, Line* l);

/*
	1.这个程序完成了Geometry，Point ，Line，Circle，Rectangle，Collection类，且功能代码经测试正常，
	2.Collection类只负责自己的数据成员（note* ，int ）的内存管理工作，不负责保存的Geography指针，
		因为，Collection类只是保存了集合类的指针
	3.Collection类我利用了链表的原则，查询函数没写出来，但是获得所有面积和长度的函数里包含了查询函数，
		没有销毁一个节点的函数因为没有必有，只有增加一个节点的函数AddGeometry（Geometry* ）
	4.没什么好说的了，这次上机真的工作量有点大，代码质量可能比较低，但是经测试代码还是可以跑的
	5.暴露了很多问题，首先我对IDE的利用非常不熟悉，前期因为不了解而重建了6次项目；快捷键也非常不了解



*/
void main() 
{

	//一条线段
	Line m_linea(2);
	m_linea.GetVertex(1)->SetX(1);
	m_linea.GetVertex(1)->SetX(1);
	m_linea.GetVertex(2)->SetX(1);
	m_linea.GetVertex(2)->SetX(4);
	//一个矩形
	Point m_p1(2, 2);
	Point m_p2(5, 2);
	Point m_p3(5, 0);
	Point m_p4(2, 0);
	Rectangle rect;
	rect.SetPoint(&m_p1, &m_p2, &m_p3, &m_p4);

	//测试面积计算成功
	//测试总长度成功

	Collection coll;
	Point m_testP(2, 2);
	Point m_testP2(1, 2);
	Circle c(2, &m_testP);


	coll.AddGeometry(&c);
	cout << endl;
	cout << "----------------空的------------" << endl;
	cout << coll.GetAllArea() << endl;
	cout << coll.GetAllLength() << endl;
	cout << "----------------一个圆形的面积与周长------------"<<endl;
	coll.AddGeometry(&c);
	cout << coll.GetAllArea() << endl;
	cout << coll.GetAllLength() << endl;
	cout << "----------------两个圆形的面积与周长------------" << endl;
	coll.AddGeometry(&rect);
	cout << coll.GetAllArea() << endl;
	cout << coll.GetAllLength() << endl;
	cout << "----------------一个矩形两个圆形的面积与周长------------" << endl;
	coll.AddGeometry(&m_linea);
	cout << coll.GetAllArea() << endl;
	cout << coll.GetAllLength() << endl;
	cout << "----------------一个矩形两个圆形外加一条线的的面积与周长------------" << endl;


	/*
	//阶段测试模块
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