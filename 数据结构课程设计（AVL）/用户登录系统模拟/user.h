#pragma once
#include<string>
using namespace std;
class user {
	string name;				//�û���
	string password;			//����
public:
	user();						//Ĭ�Ϲ��캯��
	~user();					//��������
	user(string, string);		//���ع��캯�����Զ������
	//�û���������Ϊ˽�����ݣ������������������ڶ����ȡ�û���������
	string getName();			//��ȡ�û���
	string getPassword();		//��ȡ����
	void ChangePass(string);	//�޸�����
};

