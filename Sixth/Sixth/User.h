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
	//辅助函数，double与string互相转换
	static double fun(string  dMoney);
	static string fun(double  dMoney);

	//获得一条个人基本信息记录
	string getInfor();
	//根据一条个人信息记录记录获取一个User对象
	static User getObject(string str);
	//根据一条个人信息获取一个时间字符串
	string getTime(string str);
	//获取最后一条操作记录
	string  getLastRe();
	//根据一条操作记录获取一条记录的钱数
	double getLastMoney(string str);
	//进行金融操作并获取一条金融交易的记录,声明可能会产生的异常，异常主要有余额不足
	bool doSomesthing(int mode, string str)throw(string);					//创建
	bool doSomesthing(int mode, string str, double much)throw(string);		//存钱或者缴费(扣钱)
	bool doSomesthing(int mode, string str, string aim_id, double much)throw(string);		//转账
	bool isOk();
	bool isId();
	static bool isHeFa(string str);  //判断用户输入合法
public:
	string id;
	string key;
	string name;
	string file_path;

};

