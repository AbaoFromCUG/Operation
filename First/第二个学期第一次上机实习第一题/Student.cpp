#include "stdafx.h"
#include "Student.h"


Student::Student(string newName, int newAge, char newGender, unsigned int newMajor, int newYears):Person(newName,newAge,newGender)
{
	if (newYears >= 3 && newYears <= 6) {
		major = newMajor;
		years = newYears;
	}
	cout << "Student called 构造" << endl;
	
}


Student::~Student()
{
	cout << "~Student called 析构" << endl;
}


int Student::CalTuition() {
	int leng = 0;
	int tuition=0;
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
		tuition = 5000;
		break;
		case 2:
			tuition = 6000;
			break;
		case 3:
			tuition = 8000;
			break;
	default:
		break;
	}
	return tuition;
}