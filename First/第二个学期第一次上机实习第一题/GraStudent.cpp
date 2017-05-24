#include "stdafx.h"
#include "GraStudent.h"


GraStudent::GraStudent(string newName, int newAge, char newGender, unsigned int newMajor, int newYears,string newTName):
	Student( newName,  newAge,  newGender,   newMajor,  newYears),
	Person(newName, newAge, newGender)
{
	tName = newTName;
	cout << "GraStudent called ����" << endl;
}


GraStudent::~GraStudent()
{

	cout << "~GraStudent called ����" << endl;
}


int GraStudent::CalTuition() {
	int leng = 0;		//�ֲ���������¼רҵ�ĳ���
	int tuition = 0;   //�ֲ�������ѧ��
	if (major / 10 == 0)
		leng = 1;
	else if (major / 100 == 0)
		leng = 2;
	else if (major / 1000 == 0)
		leng = 3;
	else
	{
		throw "רҵ����";
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