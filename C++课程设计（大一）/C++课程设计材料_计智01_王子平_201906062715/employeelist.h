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
	void add(employee& a);//添加教职工信息
	void remove_by_eNo(string);//根据工号删除教职工信息
	void change_by_eNo(string);//根据工号修改教职工信息
	void count_edu_by_Dep(string);//分系统计各学历的人数
	void check_by_eNo(string No);//根据学号精确查询职工信息
	void check_by_ename(string sname);//根据姓名查询
	void check_by_Ins(string In);//根据学院查询
	void check_by_Dep(string De);//根据系查询
	void check_by_edu(string ed);//根据学历查询
	void check_by_tele(string tel);//根据电话号码查询
	void sort_by_edu();//按照学历排序输出教职工信息
	void write();//将链表信息读入到文件
};
#endif // !EMPLOYEELIST_H
