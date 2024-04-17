#pragma once
#ifndef Node_h          //头文件保护
#define Node_h
struct Node
{
	int data;           //节点储存的数据
	Node* next;         //该节点指向的下一个节点的地址
	Node(int x=0,Node*p=0):data(x),next(p){}
};
#endif