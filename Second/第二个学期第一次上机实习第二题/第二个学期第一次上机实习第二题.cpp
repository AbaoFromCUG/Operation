// �ڶ���ѧ�ڵ�һ���ϻ�ʵϰ�ڶ���.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
������ͨ�Ļ���building�����ڴ洢һ��¥���Ĳ�������������������ƽ�������
�ù��м̳н���������house���̳�building�����洢���Һ�ԡ�ҵ�������
��Ƴ��򣬲���ִ�н������house�ࡣ
���ඨ��ο����£�


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

