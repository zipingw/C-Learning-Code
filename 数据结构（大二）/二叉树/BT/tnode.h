#pragma once
#include<iostream>
using namespace std;
class tnode
{
public:
	int nodeValue;						//�ڵ�ֵ
	tnode* left, * right;				//��ڵ㣬�ҽڵ�
	tnode() {}							//Ĭ�Ϲ��캯��
	tnode(const int& item, tnode* lptr = NULL, tnode* rptr = NULL) :nodeValue(item), left(lptr), right(rptr) {}//�ɸ��������Ľڵ㹹�캯��
};
