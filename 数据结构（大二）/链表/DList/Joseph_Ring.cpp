#include"DList.h"
#include<iostream>
using namespace std;
int main() {
	DList D;																//˫��ѭ������D
	cout << "������Լɪ��������" << endl;	
	int number;																
	cin >> number;															//����Լɪ��������
	for (int i = 0; i < number; i++) {										//ѭ������ڵ㵽����D��
		D.insert(number - i);												//�ڵ��������� ��������
	}
	D.travers_out();														//�����������
	int n = number;															//n��ʾʣ������	
	Dnode* node = D.head->next;												/*
																			node��ʼֵΪ��Ԫ�ڵ����һ�ڵ�
																			node��������ģ�ⱨ��
																			*/
	while (n!=1) {															//ѭ����ֹ������ʣ������ = 1
		for (int i = 1; i < 4; i++) {										//ģ�ⱨ��  ѭ��ɾ������ڵ�
			if (i % 3 == 0) {												//�������� 3 ����
				Dnode* p = node->next;										/*
																			ָ��p��ʱ�洢node->next�ڵ�
																			ʹ��ɾ����ǰ�ڵ�node����Ե�����һ�ڵ�
																			*/
				D.pop(node);												/*
																			popΪ���غ�����ɾ������D��������ڵ�����ͬ������Ľڵ�
																			��Լɪ�������� �ڵ������� Ψһ
																			*/
				node = p;													/*
																			node�ڵ�Ϊ��ɾ���Ľڵ����һ�ڵ�
																			��ʱnode��pָ��ͬһ�ڵ㣬����Ҫdelete p
																			*/
				n--;														//������1
				break;														//��������ʱ �˳�ѭ�� ���±���
			}
			node = node->next;												//������
			if (node == D.head) {											//������Ԫ�ڵ�ʱ node����������һ���ڵ�
				node = node->next;
			}
		}
	}
	cout << "������������ǵ�" << D.head->next->nodeValue << "��" << endl;	//��������D��ֻʣ��Ԫ�ڵ��� ���մ����
}

