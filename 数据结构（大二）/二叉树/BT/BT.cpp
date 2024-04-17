#include"BT.h"
#include<queue>
#include<vector>
#include<stack>
#include<iomanip>
using namespace std;
tnode* Insert_Recursive(tnode* locptr, tnode* Parent) {
	if (locptr == NULL)return NULL;								//递归终止条件1：locptr为空,返回空
	if (locptr == Parent) { return locptr; }					//递归终止条件2：找到了Parent节点，返回locptr
	/*——————————————————————————————递归，先将locptr左节点作为参数，再将locptr右节点作为参数*/
	if (Insert_Recursive(locptr->left, Parent)) { return Insert_Recursive(locptr->left, Parent); }	//如果递归过程中递归函数返回值不为空，即找到Parent
	if (Insert_Recursive(locptr->right, Parent)) { return Insert_Recursive(locptr->right, Parent); }
	return NULL;
}
tnode* BT::Insert(tnode* Parent, int value, int oper) {
	tnode* newnode = new tnode(value);							//构造newnode，放入要插入的节点值
	tnode* locptr = root;										//locptr初始化为root
	if  (locptr != Parent) {									//若locptr不等于Parent
		tnode* result = Insert_Recursive(locptr, Parent);		//调用递归找Parent，递归函数返回值赋给result
		if ( result!= NULL) {									//result非空，即找到了Parent
			if (oper == 0) {									//若要插入到Parent的左节点
				if (Parent->left != NULL)						//左节点非空，无法插入
				{ cout << "The designed pose is not available!" << endl; return NULL; }
				else                                            //左节点为空，插入
				{ Parent->left = newnode; return newnode;}
			}
			else if (oper == 1) {								//若要插入到右节点，同上
				if (Parent->right != NULL)
				{cout << "The designed pose is not available!" << endl; return NULL;}
				else
				{ Parent->right = newnode; return newnode;}
			}
		}
		/*否则，result为空，未找到Parent*/
		else {													
			cout << "There is not a matched parent in the tree!" << endl; return NULL;
		}
	}
	else{														//locptr（root）即为Parent,直接插入，插入过程同上
		if (oper == 0) {
			if (Parent->left != NULL)
			{cout << "The designed pose is not available!" << endl; return NULL;}
			else
			{Parent->left = newnode; return newnode;}
		}
		else if (oper == 1) {
			if (Parent->right != NULL)
			{cout << "The designed pose is not available!" << endl; return NULL;}
			else
			{ Parent->right = newnode; return newnode;}
		}
	}
}
void BT::printtree(int indent,tnode* subtreeroot) {						//递归打印出树形结构
	if (subtreeroot != 0) {												//子树根节点非空
		/*整体输出为右往左输出*/
		printtree(indent + 8, subtreeroot->right);						//递归，调用右节点，indent+8
		cout << setw(indent) << " " << subtreeroot->nodeValue << endl;	//输出当前根节点
		printtree(indent + 8, subtreeroot->left);						//递归，调用左节点，indent+8
	}
}
void BT::InOrder(tnode* subtreeroot) {									//中序遍历输出
	vector<tnode*> v;													//STL  vector v, T为tnode* ，将树节点按中序顺序存入后输出
	stack<tnode*> s;													//STL  stack s , T为tnode* ，
	while (subtreeroot || !s.empty()) {									//子树根节点非空  或  s非空
		while (subtreeroot) {											/*进入循环 循环终止条件：子树根节点为空
																		  循环作用：优先将树的左边节点放入栈中
																		*/	
			s.push(subtreeroot);										//循环体：子树根节点入栈，
			subtreeroot = subtreeroot->left;							//子树根节点等于子树根节点的左节点
		}
		if (!s.empty()) {												//上方循环结束，若s非空
			subtreeroot = s.top();										//取出栈首 为子树根节点赋值
			s.pop();													//栈首出栈
			v.push_back(subtreeroot);									/*当前子树根节点入栈，
																		 即可实现树节点按中序入栈*/
			subtreeroot = subtreeroot->right;							//子树根节点等于子树根节点的右节点
		}
	}
	for (int i = 0; i < v.size(); i++) {								//输出v中所有元素 
		cout << v[i]->nodeValue << " ";
	}
	cout << endl;
}
int  BT::countleaf_Recursive(tnode* subtreeroot) {						//递归计算树叶节点数
	if (subtreeroot == NULL)return count;								//递归终止条件：子树根节点为NULL
	if (subtreeroot->left == NULL && subtreeroot->right == NULL) {		//当子树根节点 左节点和右节点都为空，count+1
		count++;
	}
	countleaf_Recursive(subtreeroot->left);								//先将子树根节点的左节点作为参数调用递归函数
	countleaf_Recursive(subtreeroot->right);							//再将子树根节点的右节点做参数调用递归函数
												
	return count;
}
int BT::countleaf(tnode* subtreeroot) {									
	count = 0;															//先将count归零
	countleaf_Recursive(subtreeroot);									//调用递归函数计算count
	return count;
}