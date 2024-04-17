#pragma once
#include"user.h"
class tnode {
	user iuserdata;				//数据域：用户数据
public:
	tnode* pleft;				//左节点
	tnode* pright;				//右节点
	tnode* pparent;				//父节点
	int nbf;					//平衡因子
	tnode();					//默认无参构造函数
	~tnode();					//析构函数
	tnode(user User);			//重载构造函数1，给定user
	tnode(string, string);		//重载构造函数2，给定用户名与密码
	user getUserdata();			//获取用户数据
	void ChangePassword(string,string);//修改数据域用户数据的密码
};