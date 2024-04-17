#pragma once
#include"tnode.h"
#include"user.h"
using namespace std;
class user_AVL {
	tnode* proot;										//���ڵ�
public:	
	int nmaxheight;										//�����߶�
	user_AVL();											//Ĭ�Ϲ��캯��
	~user_AVL();										//��������������Destroy�����ͷ�ָ��
	void Destroy(tnode* subroot);						//�ݹ����ݻ���subrootΪ���ڵ����
	void printtree();									//�����ӡ��
	friend void inorderAux(int indent, tnode* subroot);	//�����ӡ����������
	int DepthOfTree(tnode* subroot);					//������subrootΪ���ڵ�������ĸ߶�
	friend int DepthAux(tnode* subroot);				//�������ĸ߶ȸ�������
	void Calculate_bf(tnode* subroot);					//�ݹ�����������нڵ��ƽ�����Ӹ��µ�ÿ���ڵ��nbf��
	friend void Calculate_bf_Aux(tnode* subroot);		//����bf����������ÿ���ڵ���������߶ȼ��������߶�
	void Insert(user&);									//�����½ڵ㣬�����ڽ�user��Ϊuserdata����tnode
	friend void insertAux(user& u, tnode*& subroot, tnode* parent);
														//���븨��������������� �ҵ������
	void inorder_bf(tnode* subroot);					//����ƽ�⸨������ ����ת���� ���õݹ��������
														//�жϲ�ƽ��Ľڵ�Ӧ��ִ��������ת�е���һ��
	void printbf(tnode*);								//���������ӡÿ���ڵ��nbf��������֤nbf�����Ƿ���ȷ
	friend tnode* Delete_user_Aux2(int LoR, tnode* subroot);
														//ɾ��������������2�������������е����ڵ���������е���С�ڵ�
	friend tnode* Delete_user_Aux1(string uname, tnode*& subroot);
														//ɾ����������1���ҵ���ɾ���Ľڵ�
	bool Delete_user_Aux0(tnode*& targetPtr);			//ɾ����������0��ɾ���ҵ��Ľڵ�
														//�ж�Ŀ��ڵ��������������е���һ��
														//�������ͣ�1.���ӽڵ�ĸ��ڵ� 2.���ӽڵ��ҷǸ��ڵ�(Ҷ�ӽڵ�)
														//3.ֻ����ڵ㣬����ڵ����ӽڵ� 4.ֻ����ڵ㣬����ڵ����ӽڵ�
														//5.ֻ���ҽڵ㣬���ҽڵ����ӽڵ� 6.ֻ���ҽڵ㣬���ҽڵ����ӽڵ�
														//7.���ҽڵ㶼��Ϊ��
														//������1��2����������Ͷ����൱�ڽ�Ҫɾ����Ŀ��ڵ��Ƶ�����2��λ�ã���ɾ��
	void Delete_user(string uname);						//ע���û���ɾ���ڵ�

	void RotateL(tnode* );								//����
	void RotateR(tnode* );								//����
	void RotateRL(tnode* );								//������
	void RotateLR(tnode* );								//������

	friend bool Change_p_Aux(string uname, string unpass, tnode* subroot);
														//�޸����븨���ݹ麯��
	bool Change_password(string uname, string unpass);	//�ҵ��û������ڽڵ㣬���޸�����
	friend bool Check_e_Aux(string, tnode*);			//�ж��û��Ƿ���ڸ�������
	bool Check_exist(string uname);						//���AVL���Ƿ�����û���Ϊuname����ע���˺�
	friend bool Check_m_Aux(string uname, string upass, tnode* subroot);
														//�ж������Ƿ�ƥ�丨������
	bool Check_match(string uname, string upass);		//�ж������Ƿ�ƥ��
	friend void write_AVL_Aux(tnode* subroot, ofstream& outAVL);
														//����ǰ�����뵽�ļ���������
	void write();										//����ǰAVL����������뵽�ļ�"user.txt"��
	bool Find_bfone_two();								//�������ã��ҵ�һ��bf=1�Ľڵ�ʹ��bf��Ϊ2
	bool Find_bfone_two_Aux(tnode* subroot);			//�������ã� ʵ�ֵĸ�������
};