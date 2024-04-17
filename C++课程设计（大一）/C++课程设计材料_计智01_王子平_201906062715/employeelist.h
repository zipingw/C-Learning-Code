#pragma once
#ifndef EMPLOYEELIST_H
#define EMPLOYEELIST_H
#include"employee.h"
using namespace std;
class employeelist {
	int size;
	employee* head;
	employee* tail;
public:
	employeelist();
	~employeelist() {}
	void add(employee& a);//��ӽ�ְ����Ϣ
	void remove_by_eNo(string);//���ݹ���ɾ����ְ����Ϣ
	void change_by_eNo(string);//���ݹ����޸Ľ�ְ����Ϣ
	void count_edu_by_Dep(string);//��ϵͳ�Ƹ�ѧ��������
	void check_by_eNo(string No);//����ѧ�ž�ȷ��ѯְ����Ϣ
	void check_by_ename(string sname);//����������ѯ
	void check_by_Ins(string In);//����ѧԺ��ѯ
	void check_by_Dep(string De);//����ϵ��ѯ
	void check_by_edu(string ed);//����ѧ����ѯ
	void check_by_tele(string tel);//���ݵ绰�����ѯ
	void sort_by_edu();//����ѧ�����������ְ����Ϣ
	void write();//��������Ϣ���뵽�ļ�
};
#endif // !EMPLOYEELIST_H
