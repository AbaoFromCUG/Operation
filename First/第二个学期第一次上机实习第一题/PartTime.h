#pragma once
#include "Teather.h"
#include "GraStudent.h"
class PartTime :
	public GraStudent,
	 public Teather
	
{
public:
	PartTime(string newName, int newAge, char newGender,string newTitle, unsigned int newMajor, int newYears, string newTName,int newWage);
	~PartTime();
protected:
	int wage;
};

