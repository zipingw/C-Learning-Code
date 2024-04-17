#pragma once
#include"Dnode.h"
class DList {
public:	
	Dnode* head;							//哑元节点
	DList();								//构造函数
	~DList();								//析构函数
	void insert(int in);					//插入节点
	void pop();								//删除节点
	void pop(int number);					//删除节点 重载	指定数据域
	void pop(Dnode* nodex);					//删除节点 重载	指定节点（删除与指定节点数据域相同的节点）
	void travers_out();						//遍历输出
};