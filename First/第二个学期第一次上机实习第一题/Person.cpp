#include "stdafx.h"
#include "Person.h"


Person::Person(string str,int age_,char gender_):name(str),age(age_),gender(gender_)
{
	cout << "Person called ����" << endl;
}


Person::~Person()
{
	cout << "~Person called ����" << endl;
}

void Person::getInfor() {
	cout << "������ " << name << endl;
	cout << "���䣺 " << age << endl;
	cout << "�Ա� " << gender << endl;

}