#pragma once
#include"tnode.h"
#include"user.h"
using namespace std;
class user_AVL {
	tnode* proot;										//根节点
public:	
	int nmaxheight;										//树最大高度
	user_AVL();											//默认构造函数
	~user_AVL();										//析构函数，调用Destroy函数释放指针
	void Destroy(tnode* subroot);						//递归后序摧毁以subroot为根节点的树
	void printtree();									//中序打印树
	friend void inorderAux(int indent, tnode* subroot);	//中序打印树辅助函数
	int DepthOfTree(tnode* subroot);					//计算以subroot为根节点的子树的高度
	friend int DepthAux(tnode* subroot);				//计算树的高度辅助函数
	void Calculate_bf(tnode* subroot);					//递归计算树中所有节点的平衡因子更新到每个节点的nbf中
	friend void Calculate_bf_Aux(tnode* subroot);		//计算bf辅助函数，每个节点的左子树高度减右子树高度
	void Insert(user&);									//插入新节点，函数内将user作为userdata构造tnode
	friend void insertAux(user& u, tnode*& subroot, tnode* parent);
														//插入辅助函数，中序遍历 找到插入点
	void inorder_bf(tnode* subroot);					//调节平衡辅助函数 即旋转操作 采用递归遍历调节
														//判断不平衡的节点应当执行四种旋转中的哪一种
	void printbf(tnode*);								//中序遍历打印每个节点的nbf，用于验证nbf计算是否正确
	friend tnode* Delete_user_Aux2(int LoR, tnode* subroot);
														//删除函数辅助函数2：查找左子树中的最大节点或右子树中的最小节点
	friend tnode* Delete_user_Aux1(string uname, tnode*& subroot);
														//删除辅助函数1：找到被删除的节点
	bool Delete_user_Aux0(tnode*& targetPtr);			//删除辅助函数0：删除找到的节点
														//判断目标节点属于七种类型中的哪一类
														//七种类型：1.无子节点的根节点 2.无子节点且非根节点(叶子节点)
														//3.只有左节点，且左节点无子节点 4.只有左节点，且左节点有子节点
														//5.只有右节点，且右节点无子节点 6.只有右节点，且右节点有子节点
														//7.左右节点都不为空
														//除类型1、2外的其他类型都是相当于将要删除的目标节点移到类型2的位置，再删除
	void Delete_user(string uname);						//注销用户，删除节点

	void RotateL(tnode* );								//左旋
	void RotateR(tnode* );								//右旋
	void RotateRL(tnode* );								//右左旋
	void RotateLR(tnode* );								//左右旋

	friend bool Change_p_Aux(string uname, string unpass, tnode* subroot);
														//修改密码辅助递归函数
	bool Change_password(string uname, string unpass);	//找到用户名所在节点，并修改密码
	friend bool Check_e_Aux(string, tnode*);			//判断用户是否存在辅助函数
	bool Check_exist(string uname);						//检查AVL中是否存在用户名为uname的已注册账号
	friend bool Check_m_Aux(string uname, string upass, tnode* subroot);
														//判断密码是否匹配辅助函数
	bool Check_match(string uname, string upass);		//判断密码是否匹配
	friend void write_AVL_Aux(tnode* subroot, ofstream& outAVL);
														//将当前树读入到文件辅助函数
	void write();										//将当前AVL树按中序读入到文件"user.txt"中
	bool Find_bfone_two();								//（验收用）找到一个bf=1的节点使其bf变为2
	bool Find_bfone_two_Aux(tnode* subroot);			//（验收用） 实现的辅助函数
};