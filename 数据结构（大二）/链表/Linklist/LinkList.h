#pragma once
#ifndef LinkList_h															//ͷ�ļ�����
#define LinkList_h
#include"Node.h"
class LinkList 
{
public:
	LinkList();																//���캯��
	LinkList(Node*p):pHead(p){}												//���캯������
	~LinkList();															//��������
	int isEmpty();															//�п�
	void traversal_output();												//�������
	void Insert(int value);													//����ڵ�
	void deletenode(int value);												//ɾ���ڵ� ��ͷ��㿪ʼ�ҵ���һ��ֵ��ȵĽڵ㲢ɾ��
	Node* find(int value);													//���ҽڵ� �����ص�һ��ֵ��ȵĽڵ�ĵ�ַ
	LinkList& operator =(LinkList &L2);										//�Ⱥŵ���������أ�������L2���Ƹ�L1
	void sort(bool cmp=0);													//���򣬿ɰ��ɴ�С����С��������Կ�
	friend Node* mergeSortedList(LinkList &L1, LinkList &L2);				//�ϲ���������
	Node* FindMidNode();													//�ҵ��м�ڵ�
private:				
	Node* pHead;
};
#endif // !LinkList_h