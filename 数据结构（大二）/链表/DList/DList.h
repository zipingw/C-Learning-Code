#pragma once
#include"Dnode.h"
class DList {
public:	
	Dnode* head;							//��Ԫ�ڵ�
	DList();								//���캯��
	~DList();								//��������
	void insert(int in);					//����ڵ�
	void pop();								//ɾ���ڵ�
	void pop(int number);					//ɾ���ڵ� ����	ָ��������
	void pop(Dnode* nodex);					//ɾ���ڵ� ����	ָ���ڵ㣨ɾ����ָ���ڵ���������ͬ�Ľڵ㣩
	void travers_out();						//�������
};