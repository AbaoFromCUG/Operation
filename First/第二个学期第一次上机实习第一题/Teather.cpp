#include "stdafx.h"
#include "Teather.h"


Teather::Teather(string newName,char newGender,int newAge,string newTitle):
	Person(newName, newAge,newGender)
{
	title = newTitle;
	cout << "Teather called ����" << endl;

}


Teather::~Teather()
{
	cout << "~Teather called ����" << endl;
}

void Teather::setTitle(string newTitle) {
	title = newTitle;
}
string Teather::getTitle() {
	return title;
}