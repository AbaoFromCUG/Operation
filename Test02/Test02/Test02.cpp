// Test02.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"Base.h"
#include"Son1.h"
#include"Son2.h"
#include<iostream>
using namespace std;

int main()
{
	Base b1;
	cout << sizeof(b1) << endl;
	

	//Son1 s1;
	//cout << sizeof(s1) << endl;


	cout << endl;
	system("pause");
    return 0;
}
//-		__vfptr	0x00f58b34 {Test02.exe!void(* Base::`vftable'[2])()} {0x00f513a2 {Test02.exe!Base::`vector deleting destructor'(unsigned int)}}	void * *

