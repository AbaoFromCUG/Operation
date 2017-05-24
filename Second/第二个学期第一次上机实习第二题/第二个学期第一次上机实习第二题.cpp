// 第二个学期第一次上机实习第二题.cpp : 定义控制台应用程序的入口点。
//
/*
建立普通的基类building，用于存储一座楼房的层数、房间数和它的总平方面积。
用共有继承建立派生类house，继承building，并存储卧室和浴室的数量。
设计程序，并按执行结果测试house类。
基类定义参考如下：


*/

#include "stdafx.h"
#include"Building.h"
#include"House.h"

int main()
{
	Building* b = new Building(2, 5, 12.2);
	b->print();

	House h(2, 5, 12.2, 5, 4);
	h.print();


	delete b;
	b = NULL;
	system("pause");

    return 0;
}

