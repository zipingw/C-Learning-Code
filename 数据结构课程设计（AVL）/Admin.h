#pragma once
#include"Node.h"
#include<iomanip>
class Admin {
private:
	typedef Node* NodePointer;
	NodePointer root;//根节点
	void DeleteAux(NodePointer current);//析构函数的辅助函数
	void refreshAux(int& h, int f, NodePointer current);//刷新树高等因素的辅助函数
	void inorderAux(NodePointer current)const;//中序遍历辅助查找函数
	void graphAux(int intend, NodePointer current)const;//图形输出二叉树辅助查找函数
	void searchAux(const string& sName, bool& found, NodePointer& current, NodePointer& parent)const;//利用用户命名查找的辅助函数
	void findDeepest2NodeAux(NodePointer& deepest2node, NodePointer current, NodePointer& parent);//寻找层数最大的平衡因子为2或-2的节点和父结点的辅助函数
	void balanceAux(NodePointer deepest2node, NodePointer parent);//平衡树的辅助函数
	void RRotate(NodePointer deepest2node, NodePointer parent);//简单右旋
	void LRtoate(NodePointer deepest2node, NodePointer parent);//简单左旋
	void LRRtoate(NodePointer deepest2node, NodePointer parent);//左右旋
	void RLRtoate(NodePointer deepest2node, NodePointer parent);//右左旋
	void copyAux(NodePointer& current, NodePointer bstcurrent);//复制辅助函数
	void isuserName(string un, bool& found)const;//判断用户名是否合法
	void iscode(string c, bool& found)const;//判断密码是否合法
	void searchAux2(const string& sName, bool& found, NodePointer& current, NodePointer& parent);//删除函数辅助查找函数
	void writeAux(ostream& out, NodePointer current);//输出到文件的辅助函数
public:
	Admin() :root(0) {}//构造函数
	~Admin();//析构函数
	Admin(const Admin& OriginalTree);//复制构造函数
	Admin& operator=(const Admin& RightTree);//赋值运算符重载
	bool empty()const;//判空函数
	bool normalInsert(const string userName, const string code);//普通插入
	bool Insert(const string userName, const string code);//带平衡树处理的插入函数
	void refresh();//刷新树高等因素函数
	void LVR()const;//中序遍历好函数
	void graph()const;//图形输出二叉树
	NodePointer search(const string& sName)const;//根据用户名查找
	bool match(const string& sName, const string& sCode)const;//匹配用户名和密码
	int Getheight(NodePointer current)const;//得到当前节点的高度
	bool findDeepest2Node(NodePointer& deepest2node, NodePointer& parent);//寻找层数最大的平衡因子为2或-2的节点和父结点
	void balance();//平衡整棵二叉树
	bool remove(const string& sName);//删除用户信息
	void Login(const string sName, const string sCode)const;//用户登陆
	void Change_Password(const string sName, const string sCode);//修改密码
	void write(ostream& out);//输出到文件中
};

