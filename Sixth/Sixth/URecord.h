#pragma once
#include<string>
using namespace std;
#define MODE int
class URecord
{
public:
	URecord(MODE mode, double lastMoney);
	virtual ~URecord();
	void addAimId(string str);
	void addChangeMoney(double a);
	void addDescription(string str);
	//返回一条记录
	string getInfor();
	//根据一条记录，获得相应信息
	static double getAfterMonery(string str);
public:
	static int Do_Create;
	static int Do_Save;
	static int Do_Transfer;
	static int Do_Deduct;	//扣除
	static int Do_BeGive;	//被给钱，有人给你钱
protected:
	MODE mode;
	string aimId;
	string Descr;
	double afterMoney;
	double changeMoney;
};

