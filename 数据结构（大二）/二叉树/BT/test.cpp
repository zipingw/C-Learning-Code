#include"BT.h"
#include<iostream>
using namespace std;
int main() {
	BT t1(4);								//构造树t1，根节点的值为4
	tnode* p1 = t1.Insert(t1.root, 9, 0);	//t1的根节点的左节点插入节点，值为9，并将新插入的节点赋值给p1
	tnode* p2 = t1.Insert(t1.root, 8, 1);	//t1的根节点的右节点插入节点，值为8，并将新插入的节点赋值给p2
	tnode* p3 = t1.Insert(p2, 3, 0);		//p2的左节点插入节点，值为3，并将新插入的节点赋值给p3
	tnode* p4 = t1.Insert(p2, 6, 1);		//p2的右节点插入节点，值为6，并将新插入的节点赋值给p4
	t1.countleaf(t1.root);					//计算当前t1的叶子树
	cout << t1.count << endl;				//输出叶子数
	t1.printtree(0, t1.root);				//打印出当前树
	t1.InOrder(t1.root);					//中序输出当前树中节点
}