#include "stdafx.h"
#include "House.h"


House::House():Building()
{
	bedRoom = 0;
	bathRoom = 0;
	cout << "House�����죨Ĭ�ϣ�" << endl;
}

House::House(int newLayers, int newRooms, float newSquareArea, int newBedRoom, int newBathRoom):
	Building( newLayers,  newRooms, newSquareArea)
{
	bedRoom = newBedRoom;
	bathRoom = newBathRoom;
	cout << "House������(���ι���)" << endl;
}

House::~House()
{
}

void House::print() {
	Building::print();
	
}
