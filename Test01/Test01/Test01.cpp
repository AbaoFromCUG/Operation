// Test01.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*


Son2 s02;
cout << "Son2���С  " << sizeof(s02) << endl;


GSon gs;
cout << "GSon2���С  " << sizeof(gs) << endl;


cout << endl;


*/
#include"stdafx.h"
#include"Base.h"
#include"Son.h"
#include"Son2.h"
#include"GSon.h"
#include<iostream>
using namespace std;

int main()
{

	typedef void(*Fun)(void);

	Base b01;
	//cout <<"Base���С  "<< sizeof(b01) << endl;
	cout << "Base ������׵�ַ��      " << &b01 << endl;
	Fun p = (Fun)(&b01);
	cout <<* p << endl;

	Son s01;
	//cout << "Son���С   " << sizeof(s01) << endl;

	

	cout << p << endl;
	system("pause");
    return 0;
}

