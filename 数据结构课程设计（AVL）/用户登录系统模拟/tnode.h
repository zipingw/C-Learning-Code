#pragma once
#include"user.h"
class tnode {
	user iuserdata;				//�������û�����
public:
	tnode* pleft;				//��ڵ�
	tnode* pright;				//�ҽڵ�
	tnode* pparent;				//���ڵ�
	int nbf;					//ƽ������
	tnode();					//Ĭ���޲ι��캯��
	~tnode();					//��������
	tnode(user User);			//���ع��캯��1������user
	tnode(string, string);		//���ع��캯��2�������û���������
	user getUserdata();			//��ȡ�û�����
	void ChangePassword(string,string);//�޸��������û����ݵ�����
};