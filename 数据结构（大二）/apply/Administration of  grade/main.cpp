#include<iostream>
#include<fstream>
#include<list>
#include"student.h"
using namespace std;
int main() {
	list <student> Class[5];									//һ��Ԫ��Ϊstudent���͵���������
	ifstream readinfile("StudentFile.txt");						//�ļ������� ����readinfile
	string  Name, Snumber;										//���ڶ����ļ����ݵ���ʱ����
	int Cl;
	float GPA;													
	while (readinfile >> Cl >> Name >> Snumber >> GPA) {		//�ļ�����
		student stu(Cl, Name, Snumber, GPA);					//ÿ����һ����Ϣ������һ��student����
		for (int cl = 0; cl < 5; cl++) {						//�ҵ�������Ϣ�İ༶
			if (Cl == cl + 1) { Class[cl].push_back(stu);}		//��Ӧ�༶�������в���ڵ�
		}
	}																		
	for (int cl = 0; cl < 5; cl++) {							//������༶����������
		Class[cl].sort();
	}
	for (int cl = 0; cl < 5; cl++) {							//��������������������
		while (!Class[cl].empty()) {								
			Class[cl].front().print();
			Class[cl].pop_front();
		}
	}	
}
