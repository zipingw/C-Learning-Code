#include"DList.h"
#include<iostream>
using namespace std;
DList::DList() {	
	head=new Dnode();									//默认构造函数 只有一个哑元节点，数据域随机
}
DList::~DList() {										//析构函数
	Dnode* node = head->next;							//node为哑元节点后一个节点
	while (node!=head)									//node遍历链表
	{													
		Dnode* p = node->next;							//p临时存储node->next
		delete node;									//delete node
		node = p;										//用p访问到下一个节点，并赋给node
	}
	delete head;										//释放 head
}
void DList::insert(int in) {							//插入节点
	Dnode* newnode = new Dnode(in);						//以in作为数据域 新建 Dnode
	newnode->next = head->next;							//先建立newnode 与 哑元节点的下一个节点的链接
	newnode->prev = head;
	head->next->prev = newnode;							//再建立newnode 与 哑元节点的链接
	head->next = newnode;
}
void DList::pop() {										//删除节点 默认删除哑元节点的下一个节点
	Dnode* node = head->next;							//node为哑元节点的下一节点	
	head->next = node->next;							//建立哑元节点与node->next的链接 同时断开哑元节点与node的链接
	node->next->prev = head;
	delete node;										//释放 node
}
void DList::pop(int number) {							//删除节点 重载	指定数据域
	Dnode* node = head->next;							//node为哑元节点的下一节点	
	while (node != head) {								//node遍历链表直至回到哑元节点
		if (node->nodeValue == number) {				//node的数据域与number相等时 删除该node
			node->next->prev = node->prev;
			node->prev->next = node->next;
			delete node;
			break;
		}
		node = node->next;
	}
}
void DList::pop(Dnode* nodex) {							//删除节点 重载	指定节点（删除与指定节点数据域相同的节点）
	Dnode* node = head->next;							//node为哑元节点的下一节点	
	while (node != head) {								//node遍历链表直至回到哑元节点
		if (node->nodeValue == nodex->nodeValue) {		//node的数据域 与nodex的数据域 相等时 删除该node
			node->next->prev = node->prev;
			node->prev->next = node->next;
			delete node;
			break;
		}
		node = node->next;
	}
}
void DList::travers_out() {								//遍历输出链表
	Dnode* node = head->next;							//node为哑元节点的下一节点	
	while (node!=head) {								//node遍历链表直至回到哑元节点
		cout << node->nodeValue << " ";					//输出每一个节点的数据域
		node = node->next;								//下一个节点
	}
	cout << endl;
}