#include "stdafx.h"
#include "URecord.h"
#include"TheTimer.h"
#include"User.h"
#include<string>
using namespace std;

int URecord::Do_Create = 1;
int URecord::Do_Save = 2;
int URecord::Do_Transfer = 3;
int URecord::Do_Deduct = 4;
int URecord::Do_BeGive = 5;

URecord::URecord(MODE mode, double lastMoney) :mode(mode), afterMoney(lastMoney), changeMoney(0)
{
	Descr = "";
}


URecord::~URecord()
{
}

void URecord::addAimId(string str)
{
	aimId = str;
}

void URecord::addChangeMoney(double a)
{
	//被扣款或者转账
	if (mode == Do_Deduct || mode == Do_Transfer)
	{
		changeMoney += a;
		afterMoney -= a;
		return;
	}
	changeMoney += a;
	afterMoney = afterMoney + a;
}

void URecord::addDescription(string str)
{
	this->Descr = str;
}

string URecord::getInfor()
{
	//创建了用户
	if (mode == Do_Create)
	{
		string strAll = "时间" + TheTimer::getTime() + "操作后余额: " + User::fun(afterMoney) + "创建了用户" + Descr;
		if (Descr == "")
		{
			return strAll;
		}
		return strAll + Descr;
	}
	//存钱
	if (mode == Do_Save)
	{
		string strAll = "时间" + TheTimer::getTime() + "操作后余额: " + User::fun(afterMoney) + "存钱了 ：" + User::fun(changeMoney) + Descr;
		return strAll;
	}
	//有人给钱
	if (mode == Do_BeGive)
	{
		string strAll = "时间" + TheTimer::getTime() + "操作后余额: " + User::fun(afterMoney) + "   得到了钱  " + User::fun(changeMoney) + Descr;
		return strAll;
	}
	//扣款了
	if (mode == Do_Deduct)
	{
		string strAll = "时间" + TheTimer::getTime() + "操作后余额: " + User::fun(afterMoney) + "   扣了钱" + User::fun(changeMoney) + Descr;
		return strAll;
	}
	//转账给了某个人
	if (mode == Do_Transfer)
	{
		string strAll = "时间" + TheTimer::getTime() + "操作后余额: " + User::fun(afterMoney) + "转账给了： " + aimId + "   转帐金额  " + User::fun(-changeMoney) + Descr;
		return strAll;
	}
	return "";
}

double URecord::getAfterMonery(string str)
{
	string money = "00000000000000000000000000000000";
	int i = 0;
	while (str[i] != ':')
	{
		i++;
	}
	while (str[i] == ':')
	{
		i++;
	}
	while (str[i] != ':')
	{
		i++;
	}
	while (str[i] == ':')
	{
		i++;
	}
	while (str[i] != ':')
	{
		i++;
	}
	while (str[i] == ':')
	{
		i++;
	}
	while (str[i]<'0' || str[i]>'9')
	{
		i++;
	}
	int j = i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		money[i - j] = str[i];
		i++;
	}
	money[i - j] = '\0';
	return User::fun(money);
}
