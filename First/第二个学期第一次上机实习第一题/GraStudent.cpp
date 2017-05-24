#include "stdafx.h"
#include "GraStudent.h"


GraStudent::GraStudent(string newName, int newAge, char newGender, unsigned int newMajor, int newYears,string newTName):
	Student( newName,  newAge,  newGender,   newMajor,  newYears),
	Person(newName, newAge, newGender)
{
	tName = newTName;
	cout << "GraStudent called 构造" << endl;
}


GraStudent::~GraStudent()
{

	cout << "~GraStudent called 析构" << endl;
}


int GraStudent::CalTuition() {
	int leng = 0;		//局部变量，记录专业的长度
	int tuition = 0;   //局部变量，学费
	if (major / 10 == 0)
		leng = 1;
	else if (major / 100 == 0)
		leng = 2;
	else if (major / 1000 == 0)
		leng = 3;
	else
	{
		throw "专业出错";
	}

	switch (leng)
	{
	case 1:
		tuition = 6000;
		break;
	case 2:
		tuition =8000;
		break;
	case 3:
		tuition =10000;
		break;
	default:
		break;
	}
	return tuition;


}