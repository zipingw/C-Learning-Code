#include"employee.h"
using namespace std;
void employee::employeedisplay() {
	cout << "————————————————————" << endl;
	cout << "姓名    : " << ename << endl;
	cout << "性别    ：" << sex << endl;
	cout << "工号    ：" << eNo << endl;
	cout << "联系电话：" << tele << endl;
	cout << "学院    ：" << Ins << endl;
	cout << "系      ：" << Dep << endl;
	cout << "学历    ：" << edu << endl;
	cout << "————————————————————" << endl;
}