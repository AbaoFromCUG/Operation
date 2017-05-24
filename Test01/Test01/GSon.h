#pragma once
#include "Son.h"
#include"Son2.h"
class GSon :
	 virtual public Son,
	 virtual public Son2
{
public:
	GSon();
	virtual ~GSon();
};

