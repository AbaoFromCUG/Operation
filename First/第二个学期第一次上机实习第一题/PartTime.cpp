#include "stdafx.h"
#include "PartTime.h"


PartTime::PartTime(string newName, int newAge, char newGender, string newTitle, unsigned int newMajor, int newYears, string newTName, int newWage):
	Teather(newName,newAge,newGender,newTitle),
	GraStudent( newName,  newAge,  newGender,   newMajor,  newYears,  newTName),
	//Student(newName, newAge, newGender, newMajor, newYears),
	Person(newName, newAge, newGender)
{
	wage = newWage;
	cout << "PartTime called ¹¹Ôì" << endl;
}


PartTime::~PartTime()
{
	cout << "~PartTime called Îö¹¹" << endl;
}
