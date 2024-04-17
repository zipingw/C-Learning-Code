#include"DList.h"
#include<iostream>
using namespace std;
DList::DList() {	
	head=new Dnode();									//Ĭ�Ϲ��캯�� ֻ��һ����Ԫ�ڵ㣬���������
}
DList::~DList() {										//��������
	Dnode* node = head->next;							//nodeΪ��Ԫ�ڵ��һ���ڵ�
	while (node!=head)									//node��������
	{													
		Dnode* p = node->next;							//p��ʱ�洢node->next
		delete node;									//delete node
		node = p;										//��p���ʵ���һ���ڵ㣬������node
	}
	delete head;										//�ͷ� head
}
void DList::insert(int in) {							//����ڵ�
	Dnode* newnode = new Dnode(in);						//��in��Ϊ������ �½� Dnode
	newnode->next = head->next;							//�Ƚ���newnode �� ��Ԫ�ڵ����һ���ڵ������
	newnode->prev = head;
	head->next->prev = newnode;							//�ٽ���newnode �� ��Ԫ�ڵ������
	head->next = newnode;
}
void DList::pop() {										//ɾ���ڵ� Ĭ��ɾ����Ԫ�ڵ����һ���ڵ�
	Dnode* node = head->next;							//nodeΪ��Ԫ�ڵ����һ�ڵ�	
	head->next = node->next;							//������Ԫ�ڵ���node->next������ ͬʱ�Ͽ���Ԫ�ڵ���node������
	node->next->prev = head;
	delete node;										//�ͷ� node
}
void DList::pop(int number) {							//ɾ���ڵ� ����	ָ��������
	Dnode* node = head->next;							//nodeΪ��Ԫ�ڵ����һ�ڵ�	
	while (node != head) {								//node��������ֱ���ص���Ԫ�ڵ�
		if (node->nodeValue == number) {				//node����������number���ʱ ɾ����node
			node->next->prev = node->prev;
			node->prev->next = node->next;
			delete node;
			break;
		}
		node = node->next;
	}
}
void DList::pop(Dnode* nodex) {							//ɾ���ڵ� ����	ָ���ڵ㣨ɾ����ָ���ڵ���������ͬ�Ľڵ㣩
	Dnode* node = head->next;							//nodeΪ��Ԫ�ڵ����һ�ڵ�	
	while (node != head) {								//node��������ֱ���ص���Ԫ�ڵ�
		if (node->nodeValue == nodex->nodeValue) {		//node�������� ��nodex�������� ���ʱ ɾ����node
			node->next->prev = node->prev;
			node->prev->next = node->next;
			delete node;
			break;
		}
		node = node->next;
	}
}
void DList::travers_out() {								//�����������
	Dnode* node = head->next;							//nodeΪ��Ԫ�ڵ����һ�ڵ�	
	while (node!=head) {								//node��������ֱ���ص���Ԫ�ڵ�
		cout << node->nodeValue << " ";					//���ÿһ���ڵ��������
		node = node->next;								//��һ���ڵ�
	}
	cout << endl;
}