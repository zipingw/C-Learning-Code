#include"BT.h"
#include<iostream>
using namespace std;
int main() {
	BT t1(4);								//������t1�����ڵ��ֵΪ4
	tnode* p1 = t1.Insert(t1.root, 9, 0);	//t1�ĸ��ڵ����ڵ����ڵ㣬ֵΪ9�������²���Ľڵ㸳ֵ��p1
	tnode* p2 = t1.Insert(t1.root, 8, 1);	//t1�ĸ��ڵ���ҽڵ����ڵ㣬ֵΪ8�������²���Ľڵ㸳ֵ��p2
	tnode* p3 = t1.Insert(p2, 3, 0);		//p2����ڵ����ڵ㣬ֵΪ3�������²���Ľڵ㸳ֵ��p3
	tnode* p4 = t1.Insert(p2, 6, 1);		//p2���ҽڵ����ڵ㣬ֵΪ6�������²���Ľڵ㸳ֵ��p4
	t1.countleaf(t1.root);					//���㵱ǰt1��Ҷ����
	cout << t1.count << endl;				//���Ҷ����
	t1.printtree(0, t1.root);				//��ӡ����ǰ��
	t1.InOrder(t1.root);					//���������ǰ���нڵ�
}