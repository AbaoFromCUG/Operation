#include "stdafx.h"
#include "House.h"


House::House():Building()
{
	bedRoom = 0;
	bathRoom = 0;
	cout << "House被构造（默认）" << endl;
}

House::House(int newLayers, int newRooms, float newSquareArea, int newBedRoom, int newBathRoom):
	Building( newLayers,  newRooms, newSquareArea)
{
	bedRoom = newBedRoom;
	bathRoom = newBathRoom;
	cout << "House被构造(带参构造)" << endl;
}

House::~House()
{
}

void House::print() {
	Building::print();
	
}
