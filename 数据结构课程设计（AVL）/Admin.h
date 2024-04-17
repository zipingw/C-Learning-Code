#pragma once
#include"Node.h"
#include<iomanip>
class Admin {
private:
	typedef Node* NodePointer;
	NodePointer root;//���ڵ�
	void DeleteAux(NodePointer current);//���������ĸ�������
	void refreshAux(int& h, int f, NodePointer current);//ˢ�����ߵ����صĸ�������
	void inorderAux(NodePointer current)const;//��������������Һ���
	void graphAux(int intend, NodePointer current)const;//ͼ������������������Һ���
	void searchAux(const string& sName, bool& found, NodePointer& current, NodePointer& parent)const;//�����û��������ҵĸ�������
	void findDeepest2NodeAux(NodePointer& deepest2node, NodePointer current, NodePointer& parent);//Ѱ�Ҳ�������ƽ������Ϊ2��-2�Ľڵ�͸����ĸ�������
	void balanceAux(NodePointer deepest2node, NodePointer parent);//ƽ�����ĸ�������
	void RRotate(NodePointer deepest2node, NodePointer parent);//������
	void LRtoate(NodePointer deepest2node, NodePointer parent);//������
	void LRRtoate(NodePointer deepest2node, NodePointer parent);//������
	void RLRtoate(NodePointer deepest2node, NodePointer parent);//������
	void copyAux(NodePointer& current, NodePointer bstcurrent);//���Ƹ�������
	void isuserName(string un, bool& found)const;//�ж��û����Ƿ�Ϸ�
	void iscode(string c, bool& found)const;//�ж������Ƿ�Ϸ�
	void searchAux2(const string& sName, bool& found, NodePointer& current, NodePointer& parent);//ɾ�������������Һ���
	void writeAux(ostream& out, NodePointer current);//������ļ��ĸ�������
public:
	Admin() :root(0) {}//���캯��
	~Admin();//��������
	Admin(const Admin& OriginalTree);//���ƹ��캯��
	Admin& operator=(const Admin& RightTree);//��ֵ���������
	bool empty()const;//�пպ���
	bool normalInsert(const string userName, const string code);//��ͨ����
	bool Insert(const string userName, const string code);//��ƽ��������Ĳ��뺯��
	void refresh();//ˢ�����ߵ����غ���
	void LVR()const;//��������ú���
	void graph()const;//ͼ�����������
	NodePointer search(const string& sName)const;//�����û�������
	bool match(const string& sName, const string& sCode)const;//ƥ���û���������
	int Getheight(NodePointer current)const;//�õ���ǰ�ڵ�ĸ߶�
	bool findDeepest2Node(NodePointer& deepest2node, NodePointer& parent);//Ѱ�Ҳ�������ƽ������Ϊ2��-2�Ľڵ�͸����
	void balance();//ƽ�����ö�����
	bool remove(const string& sName);//ɾ���û���Ϣ
	void Login(const string sName, const string sCode)const;//�û���½
	void Change_Password(const string sName, const string sCode);//�޸�����
	void write(ostream& out);//������ļ���
};

