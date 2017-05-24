#include "stdafx.h"
#include "User.h"
#include"URecord.h"
#include "TheTimer.h"
#include<fstream>
#include<sstream>
#include<string>
#include"NewUserDialog.h"
using namespace std;


//如果最后一个参数为true，则创建了一个对象，且给其写好自己的文件
User::User(string new_id, string new_key, string new_name, bool isC) :
	id(new_id),
	key(new_key),
	name(new_name)
{


	string file_father = "File\\u_file\\";
	file_path = file_father + id +".mfc";
	if (isC)
	{
		fstream file2("File\\u_id_key.mfc", ios::app | ios::out);
		file2 << this->getInfor() << endl;
		file2.close();
		doSomesthing(URecord::Do_Create, "");
		return;
	}
	if (id.length()==20)
	{
		int i = 0;
		while (file_path[i])
		{
			i++;
		}
		file_path[i] = '.';
		file_path[i + 1] = 'm';
		file_path[i + 2] = 'f';
		file_path[i + 3] = 'c';
		file_path[i + 4] = '\0';
	}
	
}
User::~User()
{
}

string User::getId()
{
	return id;
}

string User::getKey()
{
	return key;
}


string User::getName()
{
	return name;
}

string User::getFile_path()
{
	return file_path;
}

double User::fun(string dMoney)
{
	double a;
	stringstream ss;
	ss << dMoney;
	ss >> a;
	return a;
}

string User::fun(double dMoney)
{
	string a;
	stringstream ss;
	ss << dMoney;
	ss >> a;
	return a;
}


double User::getLastMoney(string str)
{
	double answer = URecord::getAfterMonery(str);

	return answer;
}

string User::getInfor()
{
	string date = TheTimer::getTime();
	stringstream ss;
	return date + "``" + id + "``" + key + "``" + name + "``" + file_path + "``";
}

User User::getObject(string str)
{
	int i = 0;

	//跳过开头的日期，以及不相干字符
	{
		while (str[i] != '`')
		{
			i++;
		}
		while (str[i] == '`')
		{
			i++;
		}
	}


	string _id = "00000000000000000000";
	string _key = "00000000000000000000";
	string _name = "00000000000000000000";
	string _file_path = "000000000000000000000000000000000000000000000000000000000000";

	{
		//id 赋值
		{
			int j = i;
			while (str[i] != '`')
			{
				_id[i - j] = str[i];
				i++;
			}
			_id[i - j] = '\0';
		}
		while (str[i] == '`')
		{
			i++;
		}

		//key赋值
		{
			int j = i;
			while (str[i] != '`')
			{
				_key[i - j] = str[i];
				i++;
			}
			_key[i - j] = '\0';
		}

		while (str[i] == '`')
		{
			i++;
		}
		//naem赋值
		{
			int j = i;
			while (str[i] != '`')
			{
				_name[i - j] = str[i];
				i++;
			}
			_name[i - j] = '\0';
		}
		while (str[i] == '`')
		{
			i++;
		}
		//file_path赋值
		
	}
	
	return User(_id, _key, _name);
}


string User::getTime(string str)
{
	string str_date = "00000000000000000000";
	int i = 0;
	while (str[i] != '`')
	{
		str_date[i] = str[i];
		i++;
	}
	str_date[i] = '\0';
	return str_date;
}

string User::getLastRe()
{
	fstream file(&file_path[0], ios::in);
	string str;
	getline(file, str);
	string lastStr = str;  

	while (getline(file, str))
	{
		if (str == "")
		{
			break;
		}
		lastStr = str;
	}
	return lastStr;
}

//创建用户
bool User::doSomesthing(int mode, string str)
{
	if (mode != URecord::Do_Create)
	{
		throw "模式错误";
	}
	fstream file(file_path, ios::out | ios::app);
	URecord u(mode, 0);   //获取一条记录
	u.addDescription(str);
	file << u.getInfor() << endl;					//追加一条记录
	file.close();
	return true;
}

//存钱或者得到了钱或者缴费(扣钱)
bool User::doSomesthing(int mode, string str, double much)
{
	if (mode == URecord::Do_Save || mode == URecord::Do_BeGive)
	{
		fstream file(file_path, ios::out | ios::app);
		URecord u(mode, getLastMoney(getLastRe()));   //获取一条记录
		u.addChangeMoney(much);						//改变钱数
		u.addDescription(str);
		file << u.getInfor() << endl;					//追加一条记录
		file.close();
		return true;
	}
	if (mode == URecord::Do_Deduct)
	{
		if (this->getLastMoney(this->getLastRe())<much)
		{
			throw "余额不足，无法完成扣款 " + str;
		}
		fstream file(file_path, ios::out | ios::app);
		URecord u(mode, getLastMoney(getLastRe()));   //获取一条记录
		u.addChangeMoney(much);						//改变钱数
		u.addDescription(str);
		file << u.getInfor() << endl;					//追加一条记录
		file.close();
		return true;
	}
	throw "模式错误";
}

//转账给别的账户
bool User::doSomesthing(int mode, string str, string aim_id, double much)
{
	if (this->getLastMoney(this->getLastRe())<much)
	{
		throw "余额不足，无法转账";
	}



	if (mode != URecord::Do_Transfer)
	{
		throw "模式错误";
	}


	{
		fstream file(file_path, ios::out | ios::app);
		URecord u(mode, getLastMoney(getLastRe()));   //获取一条自己记录
		u.addChangeMoney(much);						//改变自己的钱数
		u.addDescription(str);
		u.addAimId(aim_id);
		file << u.getInfor() << endl;					//追加一条记录
		file.close();
	}
	{
		User aim(aim_id);
		fstream file(aim.file_path, ios::out | ios::app);
		URecord u(URecord::Do_BeGive, aim.getLastMoney(aim.getLastRe()));   //获取一条别人记录
		u.addChangeMoney(much);						//改变别人的钱数
		u.addDescription("收到转账");
		file << u.getInfor() << endl;					//追加一条记录
		file.close();
	}
	return true;
}

bool User::isOk()
{
	string str;
	fstream file("File\\u_id_key.mfc", ios::in);
	while (getline(file, str))
	{
		User A_u = User::getObject(str);
		User B_u = User::getObject(this->getInfor());


		//如果id存在
		if (A_u.getId() == B_u.getId()) {
			//判断两次密码是否相同
			if (A_u.getKey() == B_u.getKey())
			{
				CNewUserDialog::writeCache(str);
				//成功时关文件
				file.close();
				return true;
			}
		}
	}
	//失败时关文件
	file.close();
	return false;
}

bool User::isId()
{
	string str;
	fstream file("File\\u_id_key.mfc", ios::in);
	while (getline(file, str))
	{
		User A_u = User::getObject(str);
		User B_u = User::getObject(this->getInfor());


		//如果id存在
		if (A_u.getId() == B_u.getId()) {
			return true;
		}
	}
	//失败时关文件
	file.close();
	return false;
}

bool User::isHeFa(string str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i]=='`')
		{
			return false;
		}
		i++;
	}
	if (str.length() > 18)
	{
		return false;
	}
	return true;
}
