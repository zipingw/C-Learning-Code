#include<iostream>
#include<string>
#include"DClist.h"
using namespace std;
void list_insert(string exp,DClist &list) {
	int reset = 0;													//Ԥ��λ�ã����ڴ���ÿһ������ʽ
	for (int i = 0; i < exp.length(); i++) {						//��������ʽ�ַ���
		int index = 0;												//ϵ��indexΪ0
		int coef = 0;												//ָ��coefΪ0
		if (exp[i] == '+') {										/*
																	�����ַ����еġ�+��
																	��Ԥ��λ��reset��ʼ����+��ǰ�ĵ���ʽ
																	*/
			if (exp[reset] > '0' && exp[reset] <= '9') {			//����ʽ��ϵ��
				index = exp[reset] - '0';							//ϵ����ֵ
			}
			else {													//����ʽ��ϵ����˵��ϵ��Ϊ1������ָ������Ϊ1
				index = 1;											//ϵ����ֵΪ1
				coef = 1;											//ָ����ֵΪ1
			}
			reset++;												//Ԥ��λ��������1
			for (; reset < i; reset++ ) {							/*
																	ѭ��������ʽ��������
																	ѭ����ֹ������resetλ�õ���+��λ��
																	*/
				coef = 1;											/*
																	����ʽ���ַ���Ϊ����ʱ
																	���ܽ���ѭ������reset<i��˵��ָ������Ϊ1
																	*/
				if (exp[reset] == '^') {							//����"^"
					reset++;										//reset������1
					coef = exp[reset] - '0';						//ָ����ֵ"^"�����һ���ַ�
					continue;										/*reset�Ѿ�+1��
																	�ʲ�ִ��if�ṹ���reset++,ֱ�ӽ����´�ѭ��*/
				}
				
			}
			reset++;												/*
																	��ʱ�Ѿ������굥��ʽ��
																	reset��+����ͬһλ��
																	resetλ��������1 ��+�ź�һ��λ��
																	�Ա㴦����һ������ʽ
																	*/
			//cout << index << " " << coef << endl;					//����õ��ĸõ���ʽ��ϵ����ָ��
			list.insert(coef, index);								//ϵ����ָ����Ϊ�ڵ���������뵽����
		}
	}
																	//�������һ������ʽ������+�ţ���������
	int index = 1;													//ϵ������Ϊ1
	int coef = 0;													//ָ������Ϊ0
	if (exp[reset] > '0' && exp[reset] <= '9') {					//ͬ��
		index = exp[reset] - '0';
	}
	else {															//���ַ���Ϊ���֣�ϵ��Ϊ1��ָ������Ϊ1
		coef = 1;
	}
	reset++;														//���ַ�������ϣ���һ���ַ�
	for (; reset < exp.length(); reset++) {							//ѭ��������ʽ��������
		coef = 1;													//���ַ�Ϊ����ʱ�ܽ���ѭ����ָ������Ϊ1
		if (exp[reset] == '^') {									//ͬ��
			reset++;
			coef = exp[reset] - '0';
			continue;
		}
		
	}
	//cout << index << " " << coef << endl;
	list.insert(coef, index);
}
int Check_Maxcoef(string str) {									//���������ʽ�ַ��������ָ��
	int len = str.length();												
	int max=0;
	for (int i = 0; i < len; ) {
		if (str[i] == '^') {
			i++;
			max = (str[i]-'0')>max? (str[i] - '0'):max;
			continue;
		}
		i++;
	}
	return max;
}
void print_Polynyhic(DClist &list1, DClist &list2, int max_exp1, int max_exp2) {
	int max = 0;
	max = max_exp1 > max_exp2 ? max_exp1 : max_exp2;			//maxΪ��������ʽ�е����ָ��
	int *item=new int[max+(int)1];								/*
																����item ָ����0��max 
																�±�Ϊ����ʽ��ָ��
																����ֵΪ��ָ���ĵ���ʽ��ϵ��
																*/
	for (int i = 0; i < max+1; i++) { item[i] = 0; }			//����item����ֵ0
	DCnode* node = list1.head->next;							
	for (; node != list1.head; node = node->next) {				//�������� ͳ�Ƹ�ָ���ĵ���ʽ��ϵ��
		for (int i = 0; i < max+1; i++) {
			if (node->coef == i) {								//�ڵ��������ָ������i
				item[i] += node->index;							//ָ��Ϊi�ĵ���ʽ��ϵ�����ϸýڵ��������ϵ��
			}
		}
	}
	node = list2.head->next;									//ͬ��
	for (; node != list2.head; node = node->next) {
		for (int i = 0; i < max + 1; i++) {
			if (node->coef == i) {
				item[i] += node->index;
			}
		}
	}
	cout << "�ϲ���Ķ���ʽΪ��" << endl;						//����ϲ���Ķ���ʽ
	for (int i = 0; i < max; i++) {								//�൱�ڴ��� ����item
		if(i<2){												//ָ��С��2�Ĵ���
			if (i == 0) { cout << item[i]<<"+"; }
			else {
				if (item[i] == 1) { cout << "x+"; }
				else { cout << item[i] << "x+"; }
			}
		}
		else {													//ָ������2�Ĵ���
			if (item[i] == 1) { cout << "x^" << i << "+"; }
			else { cout << item[i] << "x^" << i << "+"; }
		}
	}
	if (item[max] == 1) { cout << "x^" << max ; }				//���һ�������,β����+��
	else { cout << item[max] << "x^" << max ; }
	cout << endl;
}
int main() {
	string exp1;												//����ʽ������ʽ 6+x+6*x+x^2+2*x^3+3*x^2
	string exp2;												//����ʽ������ʽ 2*x+2+2*x^2+3*x^3
	cout << "��������������ʽ��" << endl;					
	cin >> exp1 >> exp2;									
	int max_exp1 = 0;
	int max_exp2 = 0;
	max_exp1 = Check_Maxcoef(exp1);
	max_exp2 = Check_Maxcoef(exp2);
	cout << "��һ������ʽ����ߴ����ǣ�" << max_exp1 << endl;
	cout << "�ڶ�������ʽ����ߴ����ǣ�" << max_exp2 << endl;
	DClist list1(max_exp1);										//��������list1
	DClist list2(max_exp2);										//��������list2
	list_insert(exp1, list1);									//���� list_insert ����������ʽexp1���뵽list1
	list_insert(exp2, list2);									//���� list_insert ����������ʽexp2���뵽list2
	print_Polynyhic(list1, list2, max_exp1, max_exp2);			//����ϲ���Ķ���ʽ
	return 0;	
}
