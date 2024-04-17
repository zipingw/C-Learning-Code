#include"student.h"
#include<iomanip>
using namespace std;
student::student():Cl(NULL),Name(NULL),Snumber(NULL),GPA(0) {}			//构造函数		
student::student(int C, string N, string Sn, float G) {					//构造函数重载
	Cl = C;
	Name = N;
	Snumber = Sn;
	GPA = G;
}	
void student::print() {													//输出类内元素
	
	cout << this->Cl << "  " << this->Snumber << "  " << this->Name << "  " << this->GPA << endl;
}
bool operator< (const student& stu1, const student& stu2) {				//操作符<号重载
	return stu1.GPA < stu2.GPA;
}
