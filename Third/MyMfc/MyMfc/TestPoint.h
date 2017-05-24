#pragma once
class TestPoint
{
public:
	TestPoint();
	TestPoint(int xx, int yy);
	TestPoint operator++();
	TestPoint operator++(int);
	
	~TestPoint();
	double GetX();
	double  GetY();
	void Move(int x, int y);
	void display();
	
private:
	double  X, Y;
};

