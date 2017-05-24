#pragma once
#include"stdafx.h"
#include<string>
using namespace std;
class Geometry
{
public:
	Geometry();
	virtual ~Geometry();
	virtual  string GenmetryType() = 0;
	void Envelope();
	virtual double Distance(Geometry *p)=0;
};


