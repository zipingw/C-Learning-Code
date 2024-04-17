#pragma once
#ifndef LinkList_h															//头文件保护
#define LinkList_h
#include"Node.h"
class LinkList 
{
public:
	LinkList();																//构造函数
	LinkList(Node*p):pHead(p){}												//构造函数重载
	~LinkList();															//析构函数
	int isEmpty();															//判空
	void traversal_output();												//遍历输出
	void Insert(int value);													//插入节点
	void deletenode(int value);												//删除节点 从头结点开始找到第一个值相等的节点并删除
	Node* find(int value);													//查找节点 并返回第一个值相等的节点的地址
	LinkList& operator =(LinkList &L2);										//等号的运算符重载，把链表L2复制给L1
	void sort(bool cmp=0);													//排序，可按由大到小或由小到大排序皆可
	friend Node* mergeSortedList(LinkList &L1, LinkList &L2);				//合并有序链表
	Node* FindMidNode();													//找到中间节点
private:				
	Node* pHead;
};
#endif // !LinkList_h