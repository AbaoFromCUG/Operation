#pragma once
class Building
{
public:
	Building();
	Building(int newLayers,int newRooms,float newSquareArea);
	~Building();
	void print();
protected:
	int layers;
	int rooms;
	float squareArea;
};

