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
	//���ۿ����ת��
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
	//�������û�
	if (mode == Do_Create)
	{
		string strAll = "ʱ��" + TheTimer::getTime() + "���������: " + User::fun(afterMoney) + "�������û�" + Descr;
		if (Descr == "")
		{
			return strAll;
		}
		return strAll + Descr;
	}
	//��Ǯ
	if (mode == Do_Save)
	{
		string strAll = "ʱ��" + TheTimer::getTime() + "���������: " + User::fun(afterMoney) + "��Ǯ�� ��" + User::fun(changeMoney) + Descr;
		return strAll;
	}
	//���˸�Ǯ
	if (mode == Do_BeGive)
	{
		string strAll = "ʱ��" + TheTimer::getTime() + "���������: " + User::fun(afterMoney) + "   �õ���Ǯ  " + User::fun(changeMoney) + Descr;
		return strAll;
	}
	//�ۿ���
	if (mode == Do_Deduct)
	{
		string strAll = "ʱ��" + TheTimer::getTime() + "���������: " + User::fun(afterMoney) + "   ����Ǯ" + User::fun(changeMoney) + Descr;
		return strAll;
	}
	//ת�˸���ĳ����
	if (mode == Do_Transfer)
	{
		string strAll = "ʱ��" + TheTimer::getTime() + "���������: " + User::fun(afterMoney) + "ת�˸��ˣ� " + aimId + "   ת�ʽ��  " + User::fun(-changeMoney) + Descr;
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
