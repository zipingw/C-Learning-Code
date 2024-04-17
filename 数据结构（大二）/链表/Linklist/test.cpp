#include"LinkList.h"
#include"Node.h"
#include<iostream>
using namespace std;
int main() {
	LinkList L1;                                  //建立链表L1来测试类的功能
	cout << L1.isEmpty() << endl;                 //新构造的链表是否为空 测试构造函数
	L1.Insert(1);                                 //插入一个节点
	cout << L1.isEmpty() << endl;                 //判断是否为空 来测试插入功能
	L1.Insert(2);                                 //继续插入节点
	L1.Insert(3);              
	L1.traversal_output();                        //遍历输出 测试连续插入节点后是否正确插入     
	L1.deletenode(1);                             //删除节点 
	L1.traversal_output();                        //遍历输出，判断是否正确删除
	cout << L1.isEmpty() << endl;                 //判断是否为空。验证在删除操作之后是否不影响判空功能
	L1.Insert(1);                                 //插入节点
	L1.traversal_output();                        //遍历输出 测试删除节点后是否影响插入节点功能
	Node* p = L1.find(2);                         //查找功能
	if (p)cout << p->data<<endl;                  //若查找结果非0 输出查找所得节点的数据域
	LinkList L2;                                  //构造L2检验“=”的重载
	L2.Insert(100);
	L2.Insert(99);
	L2.Insert(98);
	L2.traversal_output();                        //遍历输出L2原始数据
	L1 = L2;                                      //使用等号的重载功能
	L1.traversal_output();                        //遍历输出验证“=”重载是否正确
	L1.sort();                                    //按默认从大到小排序
	L1.traversal_output();                        //遍历输出验证默认从大到小排序是否正确
	L1.sort(1);                                   //给参数使得链表从小到大排序
	L1.traversal_output();                        //遍历输出验证从大到小排序是否正确
	LinkList L3;								  //构造L3： 1 3 5 7 9
	LinkList L4;								  //构造L4： 2 4 6
	L3.Insert(9);
	L3.Insert(7);
	L3.Insert(5);
	L3.Insert(3);
	L3.Insert(1);
	L4.Insert(6);
	L4.Insert(4);
	L4.Insert(2);
	L3.traversal_output();						  //遍历输出L3
	L4.traversal_output();						  //遍历输出L4
	Node* m = L3.FindMidNode();					  //找到L3的中间节点  L3：1 3 5 7 9				  
	cout << m->data<<endl;						  //输出5
	LinkList L5(mergeSortedList(L3, L4));         //构造L5 通过mergeSortedList返回合并出的链表的头节点
	L5.traversal_output();                        //遍历输出L5  验证合并功能是否正确实现
	m = L5.FindMidNode();						  //找到L5的中间节点  L5：1 2 3 4 5 6 7 9	
	cout << m->data << endl;					  //输出4	
	LinkList L6;								  //空链表L6
	LinkList L7(mergeSortedList(L5, L6));         //验证参数中第二个链表为空时mergeSortedList是否正确
	L7.traversal_output();						  //遍历输出L7
	LinkList L8(mergeSortedList(L6, L5));		  //验证参数中第一个链表为空时mergeSortedList是否正确
	L8.traversal_output();						  //遍历输出L8
	L4.Insert(0);								  //L4:  0 2 4 6 
	L4.traversal_output();						  //遍历输出L4	
	m = L4.FindMidNode();						  //找到L4的中间节点  L4：0 2 4 6
	cout << m->data << endl;					  //输出2	
	L4.deletenode(0);							  	
	L4.deletenode(2);
	L4.traversal_output();                        //删除了0 2 遍历输出L4
	m = L4.FindMidNode();						  //找到L4中间节点 L4： 4 6	
	cout << m->data << endl;                      //输出4
	return 0;
}