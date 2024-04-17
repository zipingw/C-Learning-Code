#pragma once
#ifndef employee_h
#define employee_h
#include<string>
#include<iostream>
using namespace std;
class employee {
private:
	string ename;
	string sex;
	string Ins;
	string Dep;
	string edu;
	string eNo;
	string tele;
public:
	employee(string ename1 = "NULL", string sex1 = "NULL", string Ins1 = "NULL", string Dep1 = "NULL", string edu1 = "NULL", string eNo1 = "NULL", string tele1 = "NULL", employee* p = 0)
		:ename(ename1), sex(sex1), Ins(Ins1), Dep(Dep1), edu(edu1), eNo(eNo1), tele(tele1), next(p) {}
	employee* next;
	employee* gotonext()const { return next; }
	string getename()const { return ename; }
	string getsex()const { return sex; }
	string getIns()const { return Ins; }
	string getDep()const { return Dep; }
	string getedu()const { return edu; }
	string geteNo()const { return eNo; }
	string gettele()const { return tele; }
	void employeedisplay();
	friend class employeelist;
	~employee() {}
};
#endif // !employee_h