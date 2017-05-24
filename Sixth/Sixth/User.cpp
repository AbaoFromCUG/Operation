#include "stdafx.h"
#include "User.h"
#include"URecord.h"
#include "TheTimer.h"
#include<fstream>
#include<sstream>
#include<string>
#include"NewUserDialog.h"
using namespace std;


//������һ������Ϊtrue���򴴽���һ�������Ҹ���д���Լ����ļ�
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

	//������ͷ�����ڣ��Լ�������ַ�
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
		//id ��ֵ
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

		//key��ֵ
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
		//naem��ֵ
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
		//file_path��ֵ
		
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

//�����û�
bool User::doSomesthing(int mode, string str)
{
	if (mode != URecord::Do_Create)
	{
		throw "ģʽ����";
	}
	fstream file(file_path, ios::out | ios::app);
	URecord u(mode, 0);   //��ȡһ����¼
	u.addDescription(str);
	file << u.getInfor() << endl;					//׷��һ����¼
	file.close();
	return true;
}

//��Ǯ���ߵõ���Ǯ���߽ɷ�(��Ǯ)
bool User::doSomesthing(int mode, string str, double much)
{
	if (mode == URecord::Do_Save || mode == URecord::Do_BeGive)
	{
		fstream file(file_path, ios::out | ios::app);
		URecord u(mode, getLastMoney(getLastRe()));   //��ȡһ����¼
		u.addChangeMoney(much);						//�ı�Ǯ��
		u.addDescription(str);
		file << u.getInfor() << endl;					//׷��һ����¼
		file.close();
		return true;
	}
	if (mode == URecord::Do_Deduct)
	{
		if (this->getLastMoney(this->getLastRe())<much)
		{
			throw "���㣬�޷���ɿۿ� " + str;
		}
		fstream file(file_path, ios::out | ios::app);
		URecord u(mode, getLastMoney(getLastRe()));   //��ȡһ����¼
		u.addChangeMoney(much);						//�ı�Ǯ��
		u.addDescription(str);
		file << u.getInfor() << endl;					//׷��һ����¼
		file.close();
		return true;
	}
	throw "ģʽ����";
}

//ת�˸�����˻�
bool User::doSomesthing(int mode, string str, string aim_id, double much)
{
	if (this->getLastMoney(this->getLastRe())<much)
	{
		throw "���㣬�޷�ת��";
	}



	if (mode != URecord::Do_Transfer)
	{
		throw "ģʽ����";
	}


	{
		fstream file(file_path, ios::out | ios::app);
		URecord u(mode, getLastMoney(getLastRe()));   //��ȡһ���Լ���¼
		u.addChangeMoney(much);						//�ı��Լ���Ǯ��
		u.addDescription(str);
		u.addAimId(aim_id);
		file << u.getInfor() << endl;					//׷��һ����¼
		file.close();
	}
	{
		User aim(aim_id);
		fstream file(aim.file_path, ios::out | ios::app);
		URecord u(URecord::Do_BeGive, aim.getLastMoney(aim.getLastRe()));   //��ȡһ�����˼�¼
		u.addChangeMoney(much);						//�ı���˵�Ǯ��
		u.addDescription("�յ�ת��");
		file << u.getInfor() << endl;					//׷��һ����¼
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


		//���id����
		if (A_u.getId() == B_u.getId()) {
			//�ж����������Ƿ���ͬ
			if (A_u.getKey() == B_u.getKey())
			{
				CNewUserDialog::writeCache(str);
				//�ɹ�ʱ���ļ�
				file.close();
				return true;
			}
		}
	}
	//ʧ��ʱ���ļ�
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


		//���id����
		if (A_u.getId() == B_u.getId()) {
			return true;
		}
	}
	//ʧ��ʱ���ļ�
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
