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
	//����һ����¼
	string getInfor();
	//����һ����¼�������Ӧ��Ϣ
	static double getAfterMonery(string str);
public:
	static int Do_Create;
	static int Do_Save;
	static int Do_Transfer;
	static int Do_Deduct;	//�۳�
	static int Do_BeGive;	//����Ǯ�����˸���Ǯ
protected:
	MODE mode;
	string aimId;
	string Descr;
	double afterMoney;
	double changeMoney;
};

