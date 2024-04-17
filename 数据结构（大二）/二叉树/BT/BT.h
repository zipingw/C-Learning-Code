#pragma once
#include"tnode.h"
class BT {
public:
	tnode* root;										//root��Ϊ����ΪInsert�����ṩ����
	int count;											//��¼��ǰ����Ҷ����������һ��countleaf����һ�θ���
	BT(int rootvalue) {									//���Ĺ��캯������Ҫ��һ�����������ڵ������
		root = new tnode(rootvalue);
		count = 0;
	}
	tnode* Insert(tnode* Parent, int value, int oper);	//���뺯������������������ڵ�ĸ��ڵ㣬����ڵ�����ݣ�������������
	friend tnode* Insert_Recursive(tnode* locptr, tnode* Parent);	//�������ܣ��ݹ�������е�Parent�ڵ㣬����Insert����
	void InOrder(tnode*);								//����������
	void printtree(int ,tnode*);						//��ӡ�����νṹ
	int countleaf(tnode* subtreeroot);					//��������Ҷ����
	int countleaf_Recursive(tnode* subtreeroot);		//�������ܣ��ݹ���㵱ǰ����Ҷ����
};