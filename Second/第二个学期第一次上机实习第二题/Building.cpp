#include "stdafx.h"
#include "Building.h"


Building::Building()
{
	layers = 0;
	rooms = 0;
	squareArea = 0;
	cout << "基类building被构造(默认构造)" << endl;
}

Building:: Building(int newLayers, int newRooms, float newSquareArea) {
	layers = newLayers;
	rooms = newRooms;
	squareArea = newSquareArea;
	cout << "基类building被构造（含参构造）" << endl;
}


Building::~Building()
{
}


void Building::print() {
	cout << "这个建筑共有" << layers << "层" << endl;
	cout << "这个建筑共有" << rooms << "个房间" << endl;
	cout << "这个建筑共有" << squareArea << "平方面积" << endl;
}