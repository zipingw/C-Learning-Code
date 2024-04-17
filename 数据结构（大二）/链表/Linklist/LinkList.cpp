#include"LinkList.h"
#include<iostream>
using namespace std;
LinkList::LinkList() { pHead = 0; }
LinkList::~LinkList()
{   
	Node* q = pHead;            //ͷָ���ַ����q
	while(pHead)                //��pHead����ѭ�������pHead����0
	{ 
		q = pHead->next;        //ָ��q�����洢pHead->next�ĵ�ַ��ʹdelete pHead֮���ܷ��ʵ���һ���ڵ� 
		delete pHead;           //delete����ǰָ��
		pHead = q;              //ʹpHeadָ����һ���ڵ�
	}
}
int LinkList::isEmpty() 
{
	if (!pHead) return 1;       //��ͷָ��Ϊ0 ������Ϊ������
	else return 0;              //ͷָ�벻Ϊ0 ���ǿ�����
}
void LinkList::traversal_output() 
{
	Node* p = pHead;            //ָ��pָ��ͷ�ڵ�
	for (; p; p = p->next)      //�����������pΪ0ʱ����ѭ������pΪ0��ֱ�ӽ���ѭ��
	{	
		cout << p->data << " ";
	}
	cout << endl;
	return;
}
void LinkList::Insert(int value) 
{
	Node a(value);              //������������ݵ��½ڵ�,Node�ṹ�Ĺ��캯����ָ����Ĭ�ϲ���Ϊ0
	Node* p = new Node(a);      //ָ��pָ������½ڵ�
	if (pHead)                  //��ͷָ��ǿ�
	{              
		p->next = pHead;        //�½ڵ����ͷ�ڵ�ǰ��
		pHead = p;              //ͷָ��ָ���½ڵ�
	}
	else                        //��ͷָ��Ϊ��
	{
        pHead = p;              
	}
}
void LinkList::deletenode(int value) 
{
	Node* q = pHead;                                   //ָ��qָ��ͷ�ڵ�
	Node* p = q;                                       //����ָ��p �ں�������������ʱ�洢 ����ѭ��������
	if (!q)                                            //����Ϊ������ʱ
	{
		cout << "����Ϊ�գ��޷�ɾ��" << endl; return;  //�˳�����
	}
	else                                               //����ǿ�
	{
		if (q->data == value)                          //��ͷ�ڵ�Ϊ��Ҫɾ���Ľڵ�
		{
			p = q->next;                               //�ڶ����ڵ�ĵ�ַ����ָ��p
			delete q;                                  //�ͷŵ�һ���ڵ�
			pHead = p;                                 //�޸�ͷָ��
			return;                                    //�ѳɹ�ɾ�� �˳�����
		}
		p = p->next;                                   //��pָ��ڶ����ڵ� ��ʱq->next==p,����p��������ʱq�洢����һ���ڵ�ĵ�ַ
		while (p)                                      //��ʼѭ������
		{
			if (p->data == value) {
				q->next = p->next;                     //p����һ���ڵ���p����һ���ڵ�����
				delete p;                              //�ͷ�ָ��pָ��Ľڵ�
				return;                                //��ɾ��ƥ��ĵ�һ���ڵ㣬�˳�����
			}
			else                                       //ѭ����������
			{
				p = p->next;                           //����ָ��һ��ָ����һ���ڵ�
				q = q->next;
			}
		}
	}
}
Node* LinkList::find(int value) 
{
	if(!pHead)                                         //ͷָ��Ϊ0
	{
		cout << "����Ϊ�գ��޲��ҽ��" << endl;
		return 0;                                      //��������ֵΪ0
	}
	else                                               //ͷָ�벻Ϊ0
	{
        for(Node* p = pHead;p;p=p->next)               //ָ��pָ��
	    {
			if (p->data == value)return p;             //�ҵ��ˣ���������ֵΪ��ʱ��ָ��p
	    }
		return 0;                                      //δ�ҵ�ƥ��Ľڵ㣬��������ֵΪ0
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
		Node* q = pHead;                               //100�С���106��  �������������壬���L1
		while (pHead)                
		{
			q = pHead->next;        
			delete pHead;           
			pHead = q;              
		}
		Node* p = L2.pHead;                            //p����L2��ͷָ��  
		pHead = new Node(p->data);                     //ʹͷָ����L2��ͷָ������������
		Node* s = pHead;
		while (p->next)                
		{         
			s->next = new Node((p->next)->data);       //�����Ը�����L2����������½ڵ� ��ַ��s->next
			s = s->next;                               //�������
			p = p->next;
		}
	}
	return*this;
}
void LinkList::sort(bool cmp )
{
	if (cmp == 0)									   //�Ӵ�С����
	{
		for (Node* p = pHead; p; p = p->next)		   //ָ��p����ͷָ�룬p���������ʼѡ������
		{ 
			int max = p->data;						   //max��ʱ�洢һ��ѭ�����ҵ���������������ں����Ľ���
			Node* pmax = p;                            //ָ��pmax��ʱ�洢һ��ѭ�����ҵ��İ������������Ľ���ַ�����ں����Ľ���
			for (Node* q = p->next; q; q = q->next)    //ѡ������
			{
				if (q->data > max)                     //ѭ���� ѡ���˴�ѭ�������  �ٽ���������
				{
					max = q->data;
					pmax = q;
				}
			}
			pmax->data = p->data;					   //��������
			p->data = max;                              
		}
	}
	else if (cmp == 1)                                 //��С�������򣬷���ͬ��
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
Node* mergeSortedList(LinkList &L1,LinkList &L2)       //�ϲ�������������ΪҪ�ϲ���������������� ����ֵΪ������ͷ�ڵ�
{
	Node* p1 = L1.pHead;							   //p1 L1ͷ�ڵ�
	Node* p2 = L2.pHead;							   //p2 L2ͷ�ڵ�
	Node* head = 0;									   //head ������ͷ�ڵ�	
	if (!p1)										   //���L1Ϊ������
	{
		Node* p = new Node(p2->data);				   //�����¿ռ乹��������
		head = p;                                      //headָ��������ͷ�ڵ㣬pָ��ȥ��������������
		while (p2->next)                               //p2Ϊ0ʱѭ������
		{
			p->next = new Node((p2->next)->data);      //����������Ľڵ�
			p = p->next;							   
			p2 = p2->next;
		}
		return head;                                   //����ָ��������ͷ�ڵ��ָ��
	}
	if (!p2)                                           //���L2Ϊ��  ͬ��
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
	if (p1->data < p2->data)                           //L1��L2����Ϊ�գ���ѡ���������С��ͷ�ڵ㣬����������ͷ�ڵ�
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
	Node* q = head;									   //q=head qȥ��������������Ľڵ�
	while (p1 && p2)                                   //p1,p2��ѭ���л������ߣ�ֱ����һ��Ϊ0ʱ����ѭ��
	{
		if (p1->data < p2->data)					   //�Ƚ�p1��p2��������С��	  
		{
			Node* p = new Node(p1->data);			   //��С�ߵ����������������½ڵ�	
			q->next = p;							   //���ӽڵ�	
			q = q->next;							   //q������	
			p1 = p1->next;							   //������С��ָ��������		
		}
		else										   //ͬ��
		{
			Node* p = new Node(p2->data);
			q->next = p;
			q = q->next;
			p2 = p2->next;
		}
	}
												       //ѭ�����˳�����ʱp1��p2������һ��Ϊ0
	if (!p1)										   //p1Ϊ0
	{
		while (p2)                                     //�ظ��˺������L1Ϊ��ʱ����� ��L2ʣ�µĽڵ����������½ڵ�������������
		{
			q->next= new Node(p2->data);
			p2 = p2->next;
		}
	}
	if (!p2)										   //p2Ϊ0 ͬ��
	{
		while (p1)
		{
			q->next = new Node(p1->data);
			p1 = p1->next;
			q = q->next;
		}
	}
	return head;									   //����ָ��������ͷ�ڵ��ָ��
}
Node* LinkList::FindMidNode()
{
	Node* pq = pHead;								   //pq��ָ��
	Node* ps = pHead;								   //ps��ָ��
	while (pq->next&&((pq->next)->next))			   //����ָ�����һ���ڵ㲻Ϊ0�����¸��ڵ�Ҳ��Ϊ0ʱ
	{
		ps = ps->next;								   //��ָ����һ��
		pq = (pq->next)->next;						   //��ָ��������	 
	}
	return ps;										   //��ָ�뼴�м�ڵ�
}