#pragma once
#include<iostream>
#include<string>
using namespace std;
class Person
{
public:

	Person(string str, int age_, char gender_);
	~Person();
protected:
	string name;
	int age;
	 const char gender;
	void getInfor();
};

