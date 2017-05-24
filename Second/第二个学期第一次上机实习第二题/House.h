#pragma once 
#include"Building.h"
class House:public Building
{
public:
	House();
	House(int newLayers, int newRooms, float newSquareArea, int newBedRoom, int newBathRoom);
	~House();
	void print();
protected:
	int bathRoom;
	int bedRoom;
};

