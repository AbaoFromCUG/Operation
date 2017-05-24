// 第二个学期第一次上机实习第一题.cpp : 定义控制台应用程序的入口点。
//PartTime(string newName, int newAge, char newGender,string newTitle, unsigned int newMajor, int newYears, string newTName,int newWage);
//GraStudent(string newName, int newAge, char newGender, unsigned int newMajor, int newYears, string newTName);
#include "stdafx.h"
#include"GraStudent.h"
#include"PartTime.h"
#include<string>
using namespace std;
int main()
{
	string name = "Abao";

	GraStudent gra01(name,20,'m',111,4,"Mis Ye");
	PartTime partTime01(name, 20, 'm', "STUDENT", 111, 4, "Mis Ye", 220);  //5+4+1+8+4+7+4=33
	cout <<"GraStudent对象的大小是"<< sizeof(gra01) << endl;
	cout << "PartTime对象的大小是" << sizeof(partTime01) << endl;
	system("pause");
    return 0;
}

