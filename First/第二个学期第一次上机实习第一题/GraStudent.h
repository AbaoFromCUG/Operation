#pragma once
#include "Student.h"
class GraStudent :
	public Student
{
public:
	GraStudent(string newName, int newAge, char newGender, unsigned int newMajor, int newYears,string newTName);
	~GraStudent();
	int CalTuition();
protected:
	string tName;  //新增导师姓名
};

