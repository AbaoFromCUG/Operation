#pragma once
#include "Person.h"
class Teather :
	 virtual public Person
{
public:
	Teather(string newName, char newGender, int newAge,string newTitle);
	~Teather();
	void setTitle(string newTitle);
	string getTitle();
protected:
	string title;
};

