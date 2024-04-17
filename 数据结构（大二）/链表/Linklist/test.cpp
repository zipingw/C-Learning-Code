#include"LinkList.h"
#include"Node.h"
#include<iostream>
using namespace std;
int main() {
	LinkList L1;                                  //��������L1��������Ĺ���
	cout << L1.isEmpty() << endl;                 //�¹���������Ƿ�Ϊ�� ���Թ��캯��
	L1.Insert(1);                                 //����һ���ڵ�
	cout << L1.isEmpty() << endl;                 //�ж��Ƿ�Ϊ�� �����Բ��빦��
	L1.Insert(2);                                 //��������ڵ�
	L1.Insert(3);              
	L1.traversal_output();                        //������� ������������ڵ���Ƿ���ȷ����     
	L1.deletenode(1);                             //ɾ���ڵ� 
	L1.traversal_output();                        //����������ж��Ƿ���ȷɾ��
	cout << L1.isEmpty() << endl;                 //�ж��Ƿ�Ϊ�ա���֤��ɾ������֮���Ƿ�Ӱ���пչ���
	L1.Insert(1);                                 //����ڵ�
	L1.traversal_output();                        //������� ����ɾ���ڵ���Ƿ�Ӱ�����ڵ㹦��
	Node* p = L1.find(2);                         //���ҹ���
	if (p)cout << p->data<<endl;                  //�����ҽ����0 ����������ýڵ��������
	LinkList L2;                                  //����L2���顰=��������
	L2.Insert(100);
	L2.Insert(99);
	L2.Insert(98);
	L2.traversal_output();                        //�������L2ԭʼ����
	L1 = L2;                                      //ʹ�õȺŵ����ع���
	L1.traversal_output();                        //���������֤��=�������Ƿ���ȷ
	L1.sort();                                    //��Ĭ�ϴӴ�С����
	L1.traversal_output();                        //���������֤Ĭ�ϴӴ�С�����Ƿ���ȷ
	L1.sort(1);                                   //������ʹ�������С��������
	L1.traversal_output();                        //���������֤�Ӵ�С�����Ƿ���ȷ
	LinkList L3;								  //����L3�� 1 3 5 7 9
	LinkList L4;								  //����L4�� 2 4 6
	L3.Insert(9);
	L3.Insert(7);
	L3.Insert(5);
	L3.Insert(3);
	L3.Insert(1);
	L4.Insert(6);
	L4.Insert(4);
	L4.Insert(2);
	L3.traversal_output();						  //�������L3
	L4.traversal_output();						  //�������L4
	Node* m = L3.FindMidNode();					  //�ҵ�L3���м�ڵ�  L3��1 3 5 7 9				  
	cout << m->data<<endl;						  //���5
	LinkList L5(mergeSortedList(L3, L4));         //����L5 ͨ��mergeSortedList���غϲ����������ͷ�ڵ�
	L5.traversal_output();                        //�������L5  ��֤�ϲ������Ƿ���ȷʵ��
	m = L5.FindMidNode();						  //�ҵ�L5���м�ڵ�  L5��1 2 3 4 5 6 7 9	
	cout << m->data << endl;					  //���4	
	LinkList L6;								  //������L6
	LinkList L7(mergeSortedList(L5, L6));         //��֤�����еڶ�������Ϊ��ʱmergeSortedList�Ƿ���ȷ
	L7.traversal_output();						  //�������L7
	LinkList L8(mergeSortedList(L6, L5));		  //��֤�����е�һ������Ϊ��ʱmergeSortedList�Ƿ���ȷ
	L8.traversal_output();						  //�������L8
	L4.Insert(0);								  //L4:  0 2 4 6 
	L4.traversal_output();						  //�������L4	
	m = L4.FindMidNode();						  //�ҵ�L4���м�ڵ�  L4��0 2 4 6
	cout << m->data << endl;					  //���2	
	L4.deletenode(0);							  	
	L4.deletenode(2);
	L4.traversal_output();                        //ɾ����0 2 �������L4
	m = L4.FindMidNode();						  //�ҵ�L4�м�ڵ� L4�� 4 6	
	cout << m->data << endl;                      //���4
	return 0;
}