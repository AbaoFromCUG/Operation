#include "stdafx.h"
#include "Building.h"


Building::Building()
{
	layers = 0;
	rooms = 0;
	squareArea = 0;
	cout << "����building������(Ĭ�Ϲ���)" << endl;
}

Building:: Building(int newLayers, int newRooms, float newSquareArea) {
	layers = newLayers;
	rooms = newRooms;
	squareArea = newSquareArea;
	cout << "����building�����죨���ι��죩" << endl;
}


Building::~Building()
{
}


void Building::print() {
	cout << "�����������" << layers << "��" << endl;
	cout << "�����������" << rooms << "������" << endl;
	cout << "�����������" << squareArea << "ƽ�����" << endl;
}