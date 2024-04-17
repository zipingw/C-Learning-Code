#include<iostream>
#include<string>
#include"DClist.h"
using namespace std;
void list_insert(string exp,DClist &list) {
	int reset = 0;													//预留位置，用于处理每一个单项式
	for (int i = 0; i < exp.length(); i++) {						//遍历多项式字符串
		int index = 0;												//系数index为0
		int coef = 0;												//指数coef为0
		if (exp[i] == '+') {										/*
																	遇到字符串中的“+”
																	从预留位置reset开始处理+号前的单项式
																	*/
			if (exp[reset] > '0' && exp[reset] <= '9') {			//单项式有系数
				index = exp[reset] - '0';							//系数赋值
			}
			else {													//单项式无系数，说明系数为1，并且指数最少为1
				index = 1;											//系数赋值为1
				coef = 1;											//指数赋值为1
			}
			reset++;												//预留位置往后走1
			for (; reset < i; reset++ ) {							/*
																	循环处理单项式后续部分
																	循环终止条件：reset位置到达+号位置
																	*/
				coef = 1;											/*
																	单项式首字符不为数字时
																	若能进入循环，即reset<i，说明指数至少为1
																	*/
				if (exp[reset] == '^') {							//遇到"^"
					reset++;										//reset往后走1
					coef = exp[reset] - '0';						//指数赋值"^"后面的一个字符
					continue;										/*reset已经+1，
																	故不执行if结构外的reset++,直接进入下次循环*/
				}
				
			}
			reset++;												/*
																	此时已经处理完单项式，
																	reset与+号在同一位置
																	reset位置往后走1 到+号后一个位置
																	以便处理下一个单项式
																	*/
			//cout << index << " " << coef << endl;					//输出得到的该单项式的系数和指数
			list.insert(coef, index);								//系数和指数作为节点数据域插入到链表
		}
	}
																	//由于最后一个单项式后面无+号，单独处理
	int index = 1;													//系数至少为1
	int coef = 0;													//指数至少为0
	if (exp[reset] > '0' && exp[reset] <= '9') {					//同上
		index = exp[reset] - '0';
	}
	else {															//首字符不为数字，系数为1，指数至少为1
		coef = 1;
	}
	reset++;														//首字符处理完毕，下一个字符
	for (; reset < exp.length(); reset++) {							//循环处理单项式后续部分
		coef = 1;													//首字符为数字时能进入循环，指数至少为1
		if (exp[reset] == '^') {									//同上
			reset++;
			coef = exp[reset] - '0';
			continue;
		}
		
	}
	//cout << index << " " << coef << endl;
	list.insert(coef, index);
}
int Check_Maxcoef(string str) {									//计算出多项式字符串中最大指数
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
	max = max_exp1 > max_exp2 ? max_exp1 : max_exp2;			//max为两个多项式中的最大指数
	int *item=new int[max+(int)1];								/*
																数组item 指数从0到max 
																下标为单项式的指数
																数组值为该指数的单项式的系数
																*/
	for (int i = 0; i < max+1; i++) { item[i] = 0; }			//数组item赋初值0
	DCnode* node = list1.head->next;							
	for (; node != list1.head; node = node->next) {				//遍历链表 统计各指数的单项式的系数
		for (int i = 0; i < max+1; i++) {
			if (node->coef == i) {								//节点数据域的指数等于i
				item[i] += node->index;							//指数为i的单项式的系数加上该节点数据域的系数
			}
		}
	}
	node = list2.head->next;									//同上
	for (; node != list2.head; node = node->next) {
		for (int i = 0; i < max + 1; i++) {
			if (node->coef == i) {
				item[i] += node->index;
			}
		}
	}
	cout << "合并后的多项式为：" << endl;						//输出合并后的多项式
	for (int i = 0; i < max; i++) {								//相当于处理 数组item
		if(i<2){												//指数小于2的处理
			if (i == 0) { cout << item[i]<<"+"; }
			else {
				if (item[i] == 1) { cout << "x+"; }
				else { cout << item[i] << "x+"; }
			}
		}
		else {													//指数大于2的处理
			if (item[i] == 1) { cout << "x^" << i << "+"; }
			else { cout << item[i] << "x^" << i << "+"; }
		}
	}
	if (item[max] == 1) { cout << "x^" << max ; }				//最后一项单独处理,尾部无+号
	else { cout << item[max] << "x^" << max ; }
	cout << endl;
}
int main() {
	string exp1;												//多项式输入形式 6+x+6*x+x^2+2*x^3+3*x^2
	string exp2;												//多项式输入形式 2*x+2+2*x^2+3*x^3
	cout << "请输入两个多项式：" << endl;					
	cin >> exp1 >> exp2;									
	int max_exp1 = 0;
	int max_exp2 = 0;
	max_exp1 = Check_Maxcoef(exp1);
	max_exp2 = Check_Maxcoef(exp2);
	cout << "第一个多项式的最高次数是：" << max_exp1 << endl;
	cout << "第二个多项式的最高次数是：" << max_exp2 << endl;
	DClist list1(max_exp1);										//构造链表list1
	DClist list2(max_exp2);										//构造链表list2
	list_insert(exp1, list1);									//调用 list_insert 函数将多项式exp1插入到list1
	list_insert(exp2, list2);									//调用 list_insert 函数将多项式exp2插入到list2
	print_Polynyhic(list1, list2, max_exp1, max_exp2);			//输出合并后的多项式
	return 0;	
}
