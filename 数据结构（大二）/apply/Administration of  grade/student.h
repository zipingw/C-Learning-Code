#pragma once
#include<string>
#include<iostream>
using namespace std;
class student {	
	int Cl;									//�༶
	string Name;							//����
	string Snumber;							//ѧ��
	float GPA;								//����
public:	
	student();								//Ĭ�Ϲ��캯������
	student(int, string, string, float);	//���캯����������
	void print();							//�����������
	friend bool operator< (const student& stu1, const student& stu2);	//�����<���غ�������Ϊstudent�����Ԫ����
};