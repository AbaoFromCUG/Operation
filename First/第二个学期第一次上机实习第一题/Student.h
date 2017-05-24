#pragma once
#include "Person.h"
class Student :
	virtual public Person
{
public:
	Student(string newName,int newAge,char newGender,unsigned int newMajor,int newYears);
	~Student();
	int CalTuition();
protected:
	int major;
	int years;
};

