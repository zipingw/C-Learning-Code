#pragma once
#ifndef Node_h          //ͷ�ļ�����
#define Node_h
struct Node
{
	int data;           //�ڵ㴢�������
	Node* next;         //�ýڵ�ָ�����һ���ڵ�ĵ�ַ
	Node(int x=0,Node*p=0):data(x),next(p){}
};
#endif