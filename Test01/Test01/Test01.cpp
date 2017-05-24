// Test01.cpp : 定义控制台应用程序的入口点。
//
/*


Son2 s02;
cout << "Son2类大小  " << sizeof(s02) << endl;


GSon gs;
cout << "GSon2类大小  " << sizeof(gs) << endl;


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
	//cout <<"Base类大小  "<< sizeof(b01) << endl;
	cout << "Base 对象的首地址是      " << &b01 << endl;
	Fun p = (Fun)(&b01);
	cout <<* p << endl;

	Son s01;
	//cout << "Son类大小   " << sizeof(s01) << endl;

	

	cout << p << endl;
	system("pause");
    return 0;
}

