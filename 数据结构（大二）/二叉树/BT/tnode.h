#pragma once
#include<iostream>
using namespace std;
class tnode
{
public:
	int nodeValue;						//节点值
	tnode* left, * right;				//左节点，右节点
	tnode() {}							//默认构造函数
	tnode(const int& item, tnode* lptr = NULL, tnode* rptr = NULL) :nodeValue(item), left(lptr), right(rptr) {}//可给定参数的节点构造函数
};
