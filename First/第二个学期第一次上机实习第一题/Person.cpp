#include "stdafx.h"
#include "Person.h"


Person::Person(string str,int age_,char gender_):name(str),age(age_),gender(gender_)
{
	cout << "Person called 构造" << endl;
}


Person::~Person()
{
	cout << "~Person called 析构" << endl;
}

void Person::getInfor() {
	cout << "姓名： " << name << endl;
	cout << "年龄： " << age << endl;
	cout << "性别： " << gender << endl;

}