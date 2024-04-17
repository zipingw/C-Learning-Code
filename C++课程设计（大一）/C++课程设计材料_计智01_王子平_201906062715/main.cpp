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
		cout << "   |      ��ӭ������ְ����Ϣ����ϵͳ                      |\n";
		cout << "   |      1. ��ѯ��ְ����Ϣ                               |\n";
		cout << "   |      2. ��ӽ�ְ����Ϣ                               |\n";
		cout << "   |      3. ���ݹ����޸Ľ�ְ����Ϣ                       |\n";
		cout << "   |      4. ���ݹ���ɾ����ְ����Ϣ                       |\n";
		cout << "   |      5. ��ѧ�����������ְ����Ϣ    ��Ȩ������Ȩ�ؾ� |\n";
		cout << "   --------------------------------------------------------\n";
		cout << "          ��ѡ��1/2/3/4/5��-1Ϊ����)��";
		cin >> i;
		system("cls");
		switch (i) {
		case 1: {
			while (i1 != -1) {
				fh = 0;
				cout << "--------------------------------------------------\n";
				cout << "1.�����Ų�ѯ" << endl;
				cout << "2.��������ѯ" << endl;
				cout << "3.��ѧԺ��ѯ" << endl;
				cout << "4.��ϵ��ѯ" << endl;
				cout << "5.��ѧ����ѯ" << endl;
				cout << "6.���绰�����ѯ" << endl;
				cout << "7.��ϵ����ѧ��ͳ�ƣ������ѧ�����������" << endl;
				cout << "--------------------------------------------------\n";
				cout << "��ѡ��1/2/3/4/5/6/7��-1�������˵�����" << endl;
				cin >> i1;
				system("cls");
				switch (i1) {
				case 1: {
					cout << "������Ҫ��ѯ�Ľ�ְ���Ĺ��ţ�" << endl;
					string N;
					cin >> N;
					elist.check_by_eNo(N);
					while (fh != -1) {
						cout << "�����������ַ���" << endl;
						cin >> fh;
						fh = -1;
					}
					system("cls");
					break; }
				case 2: {
					cout << "������Ҫ��ѯ�Ľ�ְ����������" << endl;
					string n;
					cin >> n;
					elist.check_by_ename(n);
					while (fh != -1) {
						cout << "�����������ַ���" << endl;
						cin >> fh;
						fh = -1;
					}
					system("cls");
					break; }
				case 3: {
					cout << "������Ҫ��ѯ�Ľ�ְ����ѧԺ��" << endl;
					string I;
					cin >> I;
					elist.check_by_Ins(I);
					while (fh != -1) {
						cout << "�����������ַ��أ�" << endl;
						cin >> fh;
						fh = -1;
					}
					system("cls");
					break; }
				case 4: {
					cout << "������Ҫ��ѯ�Ľ�ְ����ϵ��" << endl;
					string D;
					cin >> D;
					elist.check_by_Dep(D);
					while (fh != -1) {
						cout << "�����������ַ���" << endl;
						cin >> fh;
						fh = -1;
					}
					system("cls");
					break; }
				case 5: {
					cout << "������Ҫ��ѯ�Ľ�ְ����ѧ����" << endl;
					string e;
					cin >> e;
					elist.check_by_edu(e);
					while (fh != -1) {
						cout << "�����������ַ���" << endl;
						cin >> fh;
						fh = -1;
					}
					system("cls");
					break; }
				case 6: {
					cout << "������Ҫ��ѯ�Ľ�ְ���ĵ绰���룺" << endl;
					string tel;
					cin >> tel;
					elist.check_by_tele(tel);
					while (fh != -1) {
						cout << "�����������ַ���" << endl;
						cin >> fh;
						fh = -1;
					}
					system("cls");
					break;}
				case 7: {
					cout << "������Ҫͳ��ѧ����ϵ��" << endl;
					string In;
					cin >> In;
					elist.count_edu_by_Dep(In);
					while (fh != -1) {
						cout << "�����������ַ���" << endl;
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
			cout << "�밴����˳������Ҫ��ӵĽ�ְ����Ϣ��" << endl;
			cout << "����/�Ա�/ѧԺ/ϵ/ѧ��/����/��ϵ�绰" << endl;
			string n, s, I, D, ed,No,tele;
			cin >> n >> s >> I >> D >> ed >> No >> tele;
			employee e1(n, s, I, D, ed, No, tele);
			elist.add(e1);
			cout << "��������������ӳɹ���������������" << endl;
			system("pause");
			system("cls");
			break; }
		case 3: {
			cout << "������Ҫ�޸���Ϣ�Ľ�ְ������:" << endl;
			string No;
			cin >> No;
			elist.change_by_eNo(No);
			system("pause");
			system("cls");
			break; }
		case 4: {
			cout << "������Ҫɾ����Ϣ�Ľ�ְ���Ĺ���:" << endl;
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
			cout << "�������" << endl;
			i = -1;
			break; }
		}
	}
	elist.write();
    return 0;
}