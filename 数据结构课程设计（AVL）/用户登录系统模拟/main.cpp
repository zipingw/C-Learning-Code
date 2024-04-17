#include"user_AVL.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main() {
	string uname, upassword, newpassword;			//��������ı���
	user_AVL uAVL;									//����һ��AVL��
	ifstream inuser("user.txt");					//���ļ�"user.txt"��������
	while (inuser >> uname >> upassword) {			//�ļ����벻Ϊ��
		user u(uname, upassword);					//ÿ����һ���˺���Ϣ������һ��user���Ͷ���
		uAVL.Insert(u);								//���뵽uAVL����
		//uAVL.printtree();
		//cout << endl;
	}
	//uAVL.printtree();				
	/*if (uAVL.Find_bfone_two()) {
		uAVL.printtree();
	}*/
	int iloope = 0, iloopi = 0, conf = 0;			//iloope��������ѭ����iloopi���Ƶ�¼�ɹ����Сѭ��
													//conf����ע���˺�ʱ����ȷ����Ϣ
	while (iloope != -1) {
		cout << "---------------------------------------------\n";
		cout << "|      ������ϵͳ				              \n";
		cout << "|      1. ��¼������				          \n";
		cout << "|      2. ע��������˺�                     \n";
		cout << "---------------------------------------------\n";
		cout << "��ѡ��1/2��-1Ϊ�˳�ϵͳ):" << endl;
		cin >> iloope;								
		system("cls");								//���������
		switch (iloope)
		{
		case 1:
		{
			bool f1 = false, f2 = false;			//f1��¼�˺��Ƿ���ڵģ�f2��¼�˺������Ƿ�������ȷ
			cout << "������������˺ŵ� �û��� �� ���룺" << endl;
			cin >> uname >> upassword;
			//����uAVL������Ӧ�û����ڵ� ��1.�ж��Ƿ�����˺� ����f1  
			f1 = uAVL.Check_exist(uname);
			if (f1) {
				//2.�ж������Ƿ�ƥ�� ����f2
				f2 = uAVL.Check_match(uname, upassword);
				if (f2) {							//����ƥ�䣬��¼�ɹ�
					cout << "-----��¼�ɹ�����-----" << endl;
					system("pause");				//ͣ���ڵ�ǰ����
					system("cls");					///�û�ȷ�Ϻ�����
					iloopi = 0;						
					//��ʾ��¼��Ŀ��ù���
					while (iloopi != -1) {
						cout << "1.���µ�ǰ�˺�����" << endl;
						cout << "2.ע����ǰ�˺�" << endl;
						cout << "��ѡ��1/2,����-1�˳���¼����" << endl;
						cin >> iloopi;
						system("cls");				//�û����������
						switch (iloopi) {
						case 1:
							cout << "�����������룺" << endl;
							cin >> newpassword;		//�û�����������
							if (uAVL.Change_password(uname, newpassword)) {
								//�����޸����뺯�������޸ĳɹ�����������true
								cout << "�����޸ĳɹ���" << endl;
								system("pause");	//ͣ���ڵ�ǰ����ȴ��û�ȷ��
							}
							else {
								cout << "�����޸�ʧ��!" << endl;
								system("pause");	//ͣ���ڵ�ǰ����ȴ��û�ȷ��
							}
							system("cls");			//����
							break;
						case 2:
							cout << "�Ƿ�ȷ��ע����ǰ�˺ţ�" << endl;
							cout << "��ǰ�˺��û���Ϊ��" << uname << endl;
							cout << "����1ȷ��ע��������0ȡ��ע��" << endl;
							cin >> conf;
							if (conf == 1) {
								//����ɾ����ǰuser���ڽڵ�ĺ���
								uAVL.Delete_user(uname);
								iloopi = -1;		//�˺���ע������ֱ���˳���ǰСѭ��
								cout << "��ǰ�˺���ע����" << endl;
								system("pause");	//ͣ���ڵ�ǰ����ȴ��û�ȷ��
							}
							else if (conf == 0) {	//ȡ��ע��
								break;
							}
							break;
						}
					}
				}
				else {								//����ƥ��ʧ��
					cout << "�������" << endl;
					system("pause");				//ͣ���ڵ�ǰ����ȴ��û�ȷ��
				}
			}
			else {									//�����˺ŷ���ֵΪfalse
				cout << "������˺Ų����ڣ�" << endl;
				system("pause");					//ͣ���ڵ�ǰ����ȴ��û�ȷ��
			}
			system("cls");							//����
			break;
		}
		case 2:										//ע���˺�
		{
			cout << "������Ҫע����˺ŵ��û��������룺" << endl;
			cin >> uname >> upassword;
			user u(uname, upassword);
			uAVL.Insert(u);							//���ò��뺯���������˺�
			cout << "�˺��ѳɹ�ע�ᣡ" << endl;
			system("pause");						//ͣ���ڵ�ǰ����ȴ��û�ȷ��
			system("cls");							//����
			break;
		}
		case -1:									//�˳���¼
		{
			iloope = -1; break;
		}
		default:
			break;
		}
	}
	uAVL.write();									//�û�ѡ���˳�ϵͳ������ǰAVL�����뵽�ļ�����������
	return 0;
}