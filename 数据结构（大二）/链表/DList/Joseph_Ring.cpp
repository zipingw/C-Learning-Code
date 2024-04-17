#include"DList.h"
#include<iostream>
using namespace std;
int main() {
	DList D;																//双向循环链表D
	cout << "请输入约瑟夫环总人数" << endl;	
	int number;																
	cin >> number;															//输入约瑟夫环总人数
	for (int i = 0; i < number; i++) {										//循环插入节点到链表D中
		D.insert(number - i);												//节点数据域存放 人数次序
	}
	D.travers_out();														//遍历输出链表
	int n = number;															//n表示剩余人数	
	Dnode* node = D.head->next;												/*
																			node初始值为哑元节点的下一节点
																			node遍历链表模拟报数
																			*/
	while (n!=1) {															//循环终止条件：剩余人数 = 1
		for (int i = 1; i < 4; i++) {										//模拟报数  循环删除链表节点
			if (i % 3 == 0) {												//报数报到 3 死亡
				Dnode* p = node->next;										/*
																			指针p临时存储node->next节点
																			使得删除当前节点node后可以调用下一节点
																			*/
				D.pop(node);												/*
																			pop为重载函数，删除链表D中与参数节点有相同数据域的节点
																			此约瑟夫问题中 节点数据域 唯一
																			*/
				node = p;													/*
																			node节点为刚删除的节点的下一节点
																			此时node与p指向同一节点，不需要delete p
																			*/
				n--;														//人数减1
				break;														//有人死亡时 退出循环 重新报数
			}
			node = node->next;												//往后报数
			if (node == D.head) {											//遇到哑元节点时 node继续往后走一个节点
				node = node->next;
			}
		}
	}
	cout << "存活下来的人是第" << D.head->next->nodeValue << "个" << endl;	//最终链表D中只剩哑元节点与 最终存活者
}

