#pragma once
#include<string>
using namespace std;
class user {
	string name;				//用户名
	string password;			//密码
public:
	user();						//默认构造函数
	~user();					//析构函数
	user(string, string);		//重载构造函数：自定义参数
	//用户名与密码为私有数据，以下两个函数可用于对象获取用户名与密码
	string getName();			//获取用户名
	string getPassword();		//获取密码
	void ChangePass(string);	//修改密码
};

