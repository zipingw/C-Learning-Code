#include"student.h"
#include<iomanip>
using namespace std;
student::student():Cl(NULL),Name(NULL),Snumber(NULL),GPA(0) {}			//���캯��		
student::student(int C, string N, string Sn, float G) {					//���캯������
	Cl = C;
	Name = N;
	Snumber = Sn;
	GPA = G;
}	
void student::print() {													//�������Ԫ��
	
	cout << this->Cl << "  " << this->Snumber << "  " << this->Name << "  " << this->GPA << endl;
}
bool operator< (const student& stu1, const student& stu2) {				//������<������
	return stu1.GPA < stu2.GPA;
}
