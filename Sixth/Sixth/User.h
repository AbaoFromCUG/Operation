#pragma once
#include<string>
using namespace std;
class User
{
public:
	User(string new_id, string new_key = "0000", string new_name = "noname", bool idC = false);
	~User();
	string getId();
	string getKey();
	string getName();
	string getFile_path();
	//����������double��string����ת��
	static double fun(string  dMoney);
	static string fun(double  dMoney);

	//���һ�����˻�����Ϣ��¼
	string getInfor();
	//����һ��������Ϣ��¼��¼��ȡһ��User����
	static User getObject(string str);
	//����һ��������Ϣ��ȡһ��ʱ���ַ���
	string getTime(string str);
	//��ȡ���һ��������¼
	string  getLastRe();
	//����һ��������¼��ȡһ����¼��Ǯ��
	double getLastMoney(string str);
	//���н��ڲ�������ȡһ�����ڽ��׵ļ�¼,�������ܻ�������쳣���쳣��Ҫ������
	bool doSomesthing(int mode, string str)throw(string);					//����
	bool doSomesthing(int mode, string str, double much)throw(string);		//��Ǯ���߽ɷ�(��Ǯ)
	bool doSomesthing(int mode, string str, string aim_id, double much)throw(string);		//ת��
	bool isOk();
	bool isId();
	static bool isHeFa(string str);  //�ж��û�����Ϸ�
public:
	string id;
	string key;
	string name;
	string file_path;

};

