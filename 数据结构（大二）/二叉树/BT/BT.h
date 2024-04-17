#pragma once
#include"tnode.h"
class BT {
public:
	tnode* root;										//root设为公有为Insert函数提供参数
	int count;											//记录当前树的叶子树，调用一次countleaf进行一次更新
	BT(int rootvalue) {									//树的构造函数，需要给一个参数：根节点的数据
		root = new tnode(rootvalue);
		count = 0;
	}
	tnode* Insert(tnode* Parent, int value, int oper);	//插入函数，三个参数：插入节点的父节点，插入节点的数据，插入在左还是右
	friend tnode* Insert_Recursive(tnode* locptr, tnode* Parent);	//函数功能：递归查找树中的Parent节点，辅助Insert函数
	void InOrder(tnode*);								//中序遍历输出
	void printtree(int ,tnode*);						//打印出树形结构
	int countleaf(tnode* subtreeroot);					//更新树的叶子数
	int countleaf_Recursive(tnode* subtreeroot);		//函数功能：递归计算当前树的叶子数
};