#include"employee.h"
#include"employeelist.h"
#include<fstream>
#include<string>
using namespace std;
int main() {
	string a, b, c, d, e, f, g;
	employeelist elist;
	ifstream inemployee("employee.txt");
	while (inemployee >> a >> b >> c >> d >> e >> f >> g) {
		employee e(a, b, c, d, e, f, g);
		elist.add(e);
	}
	int i = 0, i1 = 0, i2 = 0;
	int fh = 0;
	while (i != -1) {
		cout << "   --------------------------------------------------------\n";
		cout << "   |      欢迎来到教职工信息管理系统                      |\n";
		cout << "   |      1. 查询教职工信息                               |\n";
		cout << "   |      2. 添加教职工信息                               |\n";
		cout << "   |      3. 根据工号修改教职工信息                       |\n";
		cout << "   |      4. 根据工号删除教职工信息                       |\n";
		cout << "   |      5. 按学历排序输出教职工信息    版权所有侵权必究 |\n";
		cout << "   --------------------------------------------------------\n";
		cout << "          请选择（1/2/3/4/5，-1为结束)：";
		cin >> i;
		system("cls");
		switch (i) {
		case 1: {
			while (i1 != -1) {
				fh = 0;
				cout << "--------------------------------------------------\n";
				cout << "1.按工号查询" << endl;
				cout << "2.按姓名查询" << endl;
				cout << "3.按学院查询" << endl;
				cout << "4.按系查询" << endl;
				cout << "5.按学历查询" << endl;
				cout << "6.按电话号码查询" << endl;
				cout << "7.分系进行学历统计，计算各学历人数并输出" << endl;
				cout << "--------------------------------------------------\n";
				cout << "请选择（1/2/3/4/5/6/7，-1返回主菜单）：" << endl;
				cin >> i1;
				system("cls");
				switch (i1) {
				case 1: {
					cout << "请输入要查询的教职工的工号：" << endl;
					string N;
					cin >> N;
					elist.check_by_eNo(N);
					while (fh != -1) {
						cout << "输入任意数字返回" << endl;
						cin >> fh;
						fh = -1;
					}
					system("cls");
					break; }
				case 2: {
					cout << "请输入要查询的教职工的姓名：" << endl;
					string n;
					cin >> n;
					elist.check_by_ename(n);
					while (fh != -1) {
						cout << "输入任意数字返回" << endl;
						cin >> fh;
						fh = -1;
					}
					system("cls");
					break; }
				case 3: {
					cout << "请输入要查询的教职工的学院：" << endl;
					string I;
					cin >> I;
					elist.check_by_Ins(I);
					while (fh != -1) {
						cout << "输入任意数字返回：" << endl;
						cin >> fh;
						fh = -1;
					}
					system("cls");
					break; }
				case 4: {
					cout << "请输入要查询的教职工的系：" << endl;
					string D;
					cin >> D;
					elist.check_by_Dep(D);
					while (fh != -1) {
						cout << "输入任意数字返回" << endl;
						cin >> fh;
						fh = -1;
					}
					system("cls");
					break; }
				case 5: {
					cout << "请输入要查询的教职工的学历：" << endl;
					string e;
					cin >> e;
					elist.check_by_edu(e);
					while (fh != -1) {
						cout << "输入任意数字返回" << endl;
						cin >> fh;
						fh = -1;
					}
					system("cls");
					break; }
				case 6: {
					cout << "请输入要查询的教职工的电话号码：" << endl;
					string tel;
					cin >> tel;
					elist.check_by_tele(tel);
					while (fh != -1) {
						cout << "输入任意数字返回" << endl;
						cin >> fh;
						fh = -1;
					}
					system("cls");
					break;}
				case 7: {
					cout << "请输入要统计学历的系：" << endl;
					string In;
					cin >> In;
					elist.count_edu_by_Dep(In);
					while (fh != -1) {
						cout << "输入任意数字返回" << endl;
						cin >> fh;
						fh = -1;
					}
					system("cls");
					break;
				}	
				}
			}
			break;
		}
		case 2: {
			cout << "请按下列顺序输入要添加的教职工信息：" << endl;
			cout << "姓名/性别/学院/系/学历/工号/联系电话" << endl;
			string n, s, I, D, ed,No,tele;
			cin >> n >> s >> I >> D >> ed >> No >> tele;
			employee e1(n, s, I, D, ed, No, tele);
			elist.add(e1);
			cout << "——————添加成功！——————" << endl;
			system("pause");
			system("cls");
			break; }
		case 3: {
			cout << "请输入要修改信息的教职工工号:" << endl;
			string No;
			cin >> No;
			elist.change_by_eNo(No);
			system("pause");
			system("cls");
			break; }
		case 4: {
			cout << "请输入要删除信息的教职工的工号:" << endl;
			string No;
			cin >> No;
			elist.remove_by_eNo(No);
			system("pause");
			system("cls");
			break; }
		case 5: {
			elist.sort_by_edu();
		    
			system("pause");
			system("cls");
			break; }
		case -1: {
			i = -1;
			break; }
		default: {
			cout << "输入错误" << endl;
			i = -1;
			break; }
		}
	}
	elist.write();
    return 0;
}