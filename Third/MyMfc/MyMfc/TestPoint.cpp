#include "stdafx.h"
#include "TestPoint.h"


TestPoint::TestPoint() { 
	X = Y = 0; 
}
TestPoint::TestPoint(int xx, int yy) { 
	X = xx; 	Y = yy; 
}
TestPoint::~TestPoint() {

}
double TestPoint::GetX() {
	return X; 
}
double  TestPoint::GetY() {
	return Y;
}
void TestPoint::Move(int x, int y) {
	X = x;  Y = y;
}
void TestPoint::display() {


}

//ǰ��++
TestPoint TestPoint::operator++() {
	this->X++;
	this->Y++;
	return *this;
}
//����++
TestPoint TestPoint::operator++(int) {
	TestPoint old = *this;
	this->X++;
	this->Y++;
	return old;
}