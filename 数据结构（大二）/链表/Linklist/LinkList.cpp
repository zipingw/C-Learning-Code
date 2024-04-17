#include"LinkList.h"
#include<iostream>
using namespace std;
LinkList::LinkList() { pHead = 0; }
LinkList::~LinkList()
{   
	Node* q = pHead;            //头指针地址赋给q
	while(pHead)                //用pHead遍历循环，最后pHead等于0
	{ 
		q = pHead->next;        //指针q用来存储pHead->next的地址，使delete pHead之后能访问到下一个节点 
		delete pHead;           //delete掉当前指针
		pHead = q;              //使pHead指向下一个节点
	}
}
int LinkList::isEmpty() 
{
	if (!pHead) return 1;       //若头指针为0 则链表为空链表
	else return 0;              //头指针不为0 则不是空链表
}
void LinkList::traversal_output() 
{
	Node* p = pHead;            //指针p指向头节点
	for (; p; p = p->next)      //遍历输出，在p为0时结束循环，若p为0则直接结束循环
	{	
		cout << p->data << " ";
	}
	cout << endl;
	return;
}
void LinkList::Insert(int value) 
{
	Node a(value);              //构造包含新数据的新节点,Node结构的构造函数中指针域默认参数为0
	Node* p = new Node(a);      //指针p指向这个新节点
	if (pHead)                  //若头指针非空
	{              
		p->next = pHead;        //新节点挂在头节点前面
		pHead = p;              //头指针指向新节点
	}
	else                        //若头指针为空
	{
        pHead = p;              
	}
}
void LinkList::deletenode(int value) 
{
	Node* q = pHead;                                   //指针q指向头节点
	Node* p = q;                                       //伴随指针p 在后续操作中起到临时存储 遍历循环的作用
	if (!q)                                            //链表为空链表时
	{
		cout << "链表为空，无法删除" << endl; return;  //退出函数
	}
	else                                               //链表非空
	{
		if (q->data == value)                          //若头节点为所要删除的节点
		{
			p = q->next;                               //第二个节点的地址赋给指针p
			delete q;                                  //释放第一个节点
			pHead = p;                                 //修改头指针
			return;                                    //已成功删除 退出函数
		}
		p = p->next;                                   //令p指向第二个节点 此时q->next==p,在用p遍历链表时q存储了上一个节点的地址
		while (p)                                      //开始循环查找
		{
			if (p->data == value) {
				q->next = p->next;                     //p的上一个节点与p的下一个节点相连
				delete p;                              //释放指针p指向的节点
				return;                                //已删除匹配的第一个节点，退出函数
			}
			else                                       //循环中若不等
			{
				p = p->next;                           //两个指针一共指向下一个节点
				q = q->next;
			}
		}
	}
}
Node* LinkList::find(int value) 
{
	if(!pHead)                                         //头指针为0
	{
		cout << "链表为空，无查找结果" << endl;
		return 0;                                      //函数返回值为0
	}
	else                                               //头指针不为0
	{
        for(Node* p = pHead;p;p=p->next)               //指针p指向
	    {
			if (p->data == value)return p;             //找到了，函数返回值为此时的指针p
	    }
		return 0;                                      //未找到匹配的节点，函数返回值为0
	}
}
LinkList& LinkList::operator =(LinkList &L2) 
{
	if (!L2.pHead)
	{
		this->~LinkList();
		return *this;
	}
	else
	{
		Node* q = pHead;                               //100行——106行  析构函数函数体，清空L1
		while (pHead)                
		{
			q = pHead->next;        
			delete pHead;           
			pHead = q;              
		}
		Node* p = L2.pHead;                            //p等于L2的头指针  
		pHead = new Node(p->data);                     //使头指针与L2的头指针的数据域相等
		Node* s = pHead;
		while (p->next)                
		{         
			s->next = new Node((p->next)->data);       //建立以复制了L2的数据域的新节点 地址给s->next
			s = s->next;                               //往后遍历
			p = p->next;
		}
	}
	return*this;
}
void LinkList::sort(bool cmp )
{
	if (cmp == 0)									   //从大到小排序
	{
		for (Node* p = pHead; p; p = p->next)		   //指针p复制头指针，p往后遍历开始选择排序
		{ 
			int max = p->data;						   //max临时存储一次循环中找到的最大数据域，用于后续的交换
			Node* pmax = p;                            //指针pmax临时存储一次循环中找到的包含最大数据域的结点地址，用于后续的交换
			for (Node* q = p->next; q; q = q->next)    //选择排序
			{
				if (q->data > max)                     //循环体 选出此次循环中最大  再交换数据域
				{
					max = q->data;
					pmax = q;
				}
			}
			pmax->data = p->data;					   //交换数据
			p->data = max;                              
		}
	}
	else if (cmp == 1)                                 //从小到大排序，方法同上
	{
		for (Node* p = pHead; p; p = p->next)
		{
			int min = p->data;
			Node* pmin = p;
			for (Node* q = p->next; q; q = q->next)
			{
				if (q->data < min)
				{
					min = q->data;
					pmin = q;
				}
			}
			pmin->data = p->data;
			p->data = min;
		}
	}
	return;
}
Node* mergeSortedList(LinkList &L1,LinkList &L2)       //合并两个链表，参数为要合并的两个链表的引用 返回值为新链表头节点
{
	Node* p1 = L1.pHead;							   //p1 L1头节点
	Node* p2 = L2.pHead;							   //p2 L2头节点
	Node* head = 0;									   //head 新链表头节点	
	if (!p1)										   //如果L1为空链表
	{
		Node* p = new Node(p2->data);				   //开辟新空间构造新链表
		head = p;                                      //head指向新链表头节点，p指针去遍历构造新链表
		while (p2->next)                               //p2为0时循环结束
		{
			p->next = new Node((p2->next)->data);      //构造新链表的节点
			p = p->next;							   
			p2 = p2->next;
		}
		return head;                                   //返回指向新链表头节点的指针
	}
	if (!p2)                                           //如果L2为空  同上
	{
		Node* p = new Node(p1->data);
		head = p;
		while (p1->next)
		{
			p->next = new Node((p1->next)->data);
			p = p->next;
			p1 = p1->next;
		}
		return head;
	}
	if (p1->data < p2->data)                           //L1，L2都不为空，先选出数据域较小的头节点，构造新链表头节点
	{
		Node* p = new Node(p1->data);                  
		head = p;
		p1 = p1->next;
	}
	else
	{
		Node* p = new Node(p2->data);
		head = p;
		p2 = p2->next;
	}
	Node* q = head;									   //q=head q去遍历构造新链表的节点
	while (p1 && p2)                                   //p1,p2在循环中会往后走，直到有一个为0时结束循环
	{
		if (p1->data < p2->data)					   //比较p1和p2中数据域小的	  
		{
			Node* p = new Node(p1->data);			   //把小者的数据域拿来构造新节点	
			q->next = p;							   //链接节点	
			q = q->next;							   //q往后走	
			p1 = p1->next;							   //数据域小的指针往后走		
		}
		else										   //同上
		{
			Node* p = new Node(p2->data);
			q->next = p;
			q = q->next;
			p2 = p2->next;
		}
	}
												       //循环已退出，此时p1和p2至少有一个为0
	if (!p1)										   //p1为0
	{
		while (p2)                                     //重复此函数最初L1为空时的情况 将L2剩下的节点数据域构造新节点连到新链表中
		{
			q->next= new Node(p2->data);
			p2 = p2->next;
		}
	}
	if (!p2)										   //p2为0 同上
	{
		while (p1)
		{
			q->next = new Node(p1->data);
			p1 = p1->next;
			q = q->next;
		}
	}
	return head;									   //返回指向新链表头节点的指针
}
Node* LinkList::FindMidNode()
{
	Node* pq = pHead;								   //pq快指针
	Node* ps = pHead;								   //ps慢指针
	while (pq->next&&((pq->next)->next))			   //当快指针的下一个节点不为0且下下个节点也不为0时
	{
		ps = ps->next;								   //慢指针走一步
		pq = (pq->next)->next;						   //快指针走两步	 
	}
	return ps;										   //慢指针即中间节点
}