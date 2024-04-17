#include<iostream>
#include<fstream>
#include<list>
#include"student.h"
using namespace std;
int main() {
	list <student> Class[5];									//一个元素为student类型的链表数组
	ifstream readinfile("StudentFile.txt");						//文件输入流 对象readinfile
	string  Name, Snumber;										//用于读入文件数据的临时变量
	int Cl;
	float GPA;													
	while (readinfile >> Cl >> Name >> Snumber >> GPA) {		//文件读入
		student stu(Cl, Name, Snumber, GPA);					//每读入一组信息，创建一个student对象
		for (int cl = 0; cl < 5; cl++) {						//找到这组信息的班级
			if (Cl == cl + 1) { Class[cl].push_back(stu);}		//相应班级的链表中插入节点
		}
	}																		
	for (int cl = 0; cl < 5; cl++) {							//将五个班级的链表都排序
		Class[cl].sort();
	}
	for (int cl = 0; cl < 5; cl++) {							//输出排序后五个链表的内容
		while (!Class[cl].empty()) {								
			Class[cl].front().print();
			Class[cl].pop_front();
		}
	}	
}
