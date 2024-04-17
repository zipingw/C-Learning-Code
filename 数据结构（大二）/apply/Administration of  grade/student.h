#pragma once
#include<string>
#include<iostream>
using namespace std;
class student {	
	int Cl;									//班级
	string Name;							//姓名
	string Snumber;							//学号
	float GPA;								//绩点
public:	
	student();								//默认构造函数声明
	student(int, string, string, float);	//构造函数重载声明
	void print();							//输出函数声明
	friend bool operator< (const student& stu1, const student& stu2);	//运算符<重载函数声明为student类的友元函数
};