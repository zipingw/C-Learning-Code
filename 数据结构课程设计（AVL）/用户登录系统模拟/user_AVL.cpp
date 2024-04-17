#include"user_AVL.h"
#include<iomanip>
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
//构造函数
user_AVL::user_AVL() { proot = NULL; nmaxheight = 0; }
//析构函数
user_AVL::~user_AVL() {
	Destroy(proot);				//摧毁整棵树，释放所有指针
}
//摧毁树函数，递归后序删除所有节点，释放所有指针
void user_AVL::Destroy(tnode* subroot) {
	if (subroot == NULL) {		//递归终止条件：节点为空
		return;
	}
	Destroy(subroot->pleft);	//遍历左子树释放指针
	Destroy(subroot->pright);	//遍历右子树释放指针
	delete subroot;				//释放指针
}
//中序打印树形辅助函数
void inorderAux(int indent, tnode* subroot) {
	if (subroot != 0) {			//递归终止条件：节点为空
		inorderAux(indent + 8, subroot->pleft);	//遍历左子树，每往左加深一层，输出时+8空格
		cout << setw(indent) << " " << subroot->getUserdata().getName() << endl;	//输出
		inorderAux(indent + 8, subroot->pright);//遍历右子树，每往右加深一层，输出时+8空格
	}
}

//打印树
void user_AVL::printtree() {
	inorderAux(0, proot);		//调用中序打印辅助函数输出整棵树的树形，初始空格数为0
}

//计算树的高度辅助函数，为class user_AVL的友元函数
int DepthAux(tnode* subroot) {	//计算以subroot为根节点的树的高度
	if (subroot == NULL) {		//递归终止条件：根节点为空
		return 0;
	}
	int leftheight = DepthAux(subroot->pleft);	//计算subroot的左子树的树高度
	int rightheight = DepthAux(subroot->pright);//计算subroot的右子树的树高度
	int max = leftheight > rightheight ? leftheight : rightheight;//取左右子树中高的
	return max + 1;								//max+1作为subroot为根节点的子树的高度
}

//计算以subroot为根节点的子树的高度
int user_AVL::DepthOfTree(tnode* subroot) {		
	nmaxheight = DepthAux(subroot);				//调用计算树的高度辅助函数计算树高度
	return nmaxheight;							//函数返回值：以subroot为根节点的树的高度
}

//计算bf辅助函数，每个节点的左子树高度减右子树高度，为class user_AVL的友元函数
void Calculate_bf_Aux(tnode* subroot) {
	int leftheight = DepthAux(subroot->pleft);	//计算subroot节点的左子树的高度
	int rightheight = DepthAux(subroot->pright);//计算subroot节点的右子树的高度
	subroot->nbf = leftheight - rightheight;	//subroot节点的平衡因子为左子树高度减右子树高度
}

//递归计算树中所有节点的平衡因子更新到每个节点的nbf中
void user_AVL::Calculate_bf(tnode* subroot) {
	if (subroot == NULL) {						//递归终止条件：subroot为空	
		return;
	}
	Calculate_bf(subroot->pleft);				//计算左子树中的节点的平衡因子
	Calculate_bf_Aux(subroot);					//计算当前节点的平衡因子
	Calculate_bf(subroot->pright);				//计算右子树中的节点的平衡因子
}

//插入辅助函数，中序遍历 找到插入点 ，为class user_AVL的友元函数
void insertAux(user& u, tnode*& subroot, tnode* parent) {
	//参数u为要插入的用户数据，subroot为当前节点，parent为当前节点的父节点
	if (subroot == NULL) {						//递归终止条件：subroot为空
												//即当前位置为新节点要插入的位置
		subroot  = new tnode(u);				//开辟一块空间放入u，地址为subroot
		subroot->pparent = parent;				//指定新节点subroot的父节点
												//使得每个节点的父节点有指向、可用
	}
	else if (u.getName() < subroot->getUserdata().getName()) {
												//要插入的数据应插入当前数据的左边
		insertAux(u, subroot->pleft,subroot);	//传递参数，当前节点改为其左孩子，父节点改为当前节点
	}
	else if (u.getName() > subroot->getUserdata().getName()) {
												//要插入的数据应插入当前数据的右边
		insertAux(u, subroot->pright,subroot);	//传递参数，当前节点改为其右孩子，父节点改为当前节点
	}
}

//调节平衡辅助函数，判断不平衡的节点应当执行四种旋转中的哪一种并旋转
void user_AVL::inorder_bf(tnode*subroot) {
	if (subroot == NULL)return;					//递归终止条件：subroot为空
	inorder_bf(subroot->pleft);					//遍历subroot左子树找不平衡节点
	if (abs(subroot->nbf) == 2) {				//平衡因子绝对值等于2
	//因为已确保建立树和插入及删除时每一个节点都会进行平衡操作，故平衡因子绝对值不会大于2
		if (subroot->nbf == 2) {				//平衡因子为2
			if (subroot->pleft->nbf == 1) {		//subroot的左节点平衡因子为1
				RotateR(subroot);				//以subroot为参数 右旋
				Calculate_bf(proot);			//重新计算整棵树所有节点的平衡因子
				return ;						//返回
			}
			else if (subroot->pleft->nbf == -1) {//subroot的左节点平衡因子为-1
				RotateLR(subroot);				//以subroot为参数 左右旋
				Calculate_bf(proot);			//重新计算整棵树所有节点的平衡因子
				return ;						//返回
			}
		}
		else if (subroot->nbf == -2) {			//平衡因子绝对值等于-2
			if (subroot->pright->nbf == -1) {	//subroot的左节点平衡因子为-1
				RotateL(subroot);				//以subroot为参数 左旋
				Calculate_bf(proot);			//重新计算整棵树所有节点的平衡因子
				return ;						//返回
			}
			else if (subroot->pright->nbf == 1) {//subroot的左节点平衡因子为1
				RotateRL(subroot);				//以subroot为参数 右左旋
				Calculate_bf(proot);			//重新计算整棵树所有节点的平衡因子
				return ;						//返回
			}
		}
	}
	inorder_bf(subroot->pright);				//遍历subroot左子树找不平衡节点
}

//插入函数，将user作为userdata构造新节点
void user_AVL::Insert(user& u) {
	if (proot == NULL) {						//根节点为空
		proot = new tnode(u);					//新数据插入到根节点
		proot->pparent = NULL;					//指定父节点为空，防止其父节点变为野指针
	}
	else {										//根节点非空
		insertAux(u, proot, proot->pparent);	//插入新节点
	}
	Calculate_bf(proot);						//计算并更新每个节点的nbf
	inorder_bf(proot);							//调节平衡
	DepthOfTree(proot);							//计算并更新树的nmaxheight
}

//中序遍历打印每个节点的nbf，用于验证nbf计算是否正确
void user_AVL::printbf(tnode* subroot) {
	if (subroot == NULL)return;					//递归终止条件：subroot为空
	printbf(subroot->pleft);					//遍历subroot的左子树
	cout << subroot->nbf << " ";				//输出nbf
	printbf(subroot->pright);					//遍历subroot的右子树
}

//删除函数辅助函数2：查找左子树中的最大节点或右子树中的最小节点
tnode* Delete_user_Aux2(int LoR, tnode* subroot) {
	//LoR值为1时找以subroot的父节点为根节点的左子树最大值，为0时找右子树最小值
	if (LoR == 1) {
		while (subroot->pright != NULL) {		//循环走到subroot的最右非空节点
			subroot = subroot->pright;			
		}
		return subroot;							
		//返回找到的节点，即subroot父节点的左子树最大节点
	}
	else if (LoR == 0) {
		while (subroot->pleft != NULL) {		//循环走到subroot的最左非空节点
			subroot = subroot->pleft;			
		}
		return subroot;
		//返回找到的节点，即subroot父节点的右子树最小节点
	}
	return NULL;
}

//删除辅助函数1：找到被删除的节点 为class user_AVL的友元函数
tnode* Delete_user_Aux1(string uname, tnode*& subroot) {
	if (subroot == NULL) { return NULL; }		//递归终止条件：subroot为空
	if (tnode* ptr = Delete_user_Aux1(uname, subroot->pleft))
												//递归遍历subroot为根节点的左子树
												//若函数有返回值，即找到了要删除的节点
		return ptr;								//返回找到的节点
	if (subroot->getUserdata().getName() == uname) {
												//subroot节点数据域的用户名与要删除的用户账号用户名相同
												//subroot即要删除的节点
		return subroot;							//返回该节点，外层可将其递归返回到最外层
	}
	if (tnode* ptr = Delete_user_Aux1(uname, subroot->pright))
												//递归遍历subroot为根节点的左子树
												//若函数有返回值，即找到了要删除的节点
		return ptr;								//返回找到的节点
	return NULL;								//没找到返回空
}

//删除辅助函数0：删除找到的节点
bool user_AVL::Delete_user_Aux0(tnode*& targetPtr) {
	//已找到要删除的目标节点
	//判断目标节点属于七种类型中的哪一类
	//七种类型：1.无子节点的根节点 2.无子节点且非根节点(叶子节点)
	//3.只有左节点，且左节点无子节点 4.只有左节点，且左节点有子节点
	//5.只有右节点，且右节点无子节点 6.只有右节点，且右节点有子节点
	//7.左右节点都不为空
	//相当于将要删除的目标节点移到叶子节点位置或往下只有一个节点与其相连，再删除
	//类型1、2属于叶子节点，直接删除；类型3、5属于的目标节点只与单个节点相连，也可直接删除
	//类型1 无子节点的根节点
	if(targetPtr->pparent==NULL&&targetPtr->pleft==NULL&&targetPtr->pright==NULL){
		proot = NULL;							//令根节点为NULL后再释放targetPtr
												//放止直接释放targetPtr会导致根节点变为野指针
		delete targetPtr;						//释放targetPtr
		return true;							//返回true表示删除成功
	}
	//类型2 无子节点且非根节点(叶子节点)
	else if (targetPtr->pparent != NULL && targetPtr->pleft == NULL && targetPtr->pright == NULL) {
		tnode* tP = targetPtr->pparent;			//指针tP存下删除目标的父节点
		if (tP->pright == targetPtr) {			//目标节点为tP的右节点
			tP->pright = NULL;					//令tP的右节点为空
												//防止释放删除目标后tP右节点变为野指针
			delete targetPtr;					//释放targetPtr
		}
		else {									//目标节点为tP的左节点
			tP->pleft = NULL;					//令tP的左节点为空
												//防止释放删除目标后tP左节点变为野指针
			delete targetPtr;					//释放targetPtr
		}
		return true;							//返回true表示删除成功
	}
	else if (targetPtr->pleft != NULL && targetPtr->pright == NULL) {
		//目标节点的左节点非空，右节点为空
		tnode* tL = targetPtr->pleft;			//tL:目标节点左节点
		tnode* tP = targetPtr->pparent;			//tP：目标节点父节点
		tnode* tLL = tL->pleft;					//tLL:tL左节点
		tnode* tLR = tL->pright;				//tLR:tL右节点
		if (tLL == NULL && tLR == NULL) {		//类型3 
												//目标节点只有左节点，且左节点无子节点
			if (tP) {							//targetPtr不为根节点
				tP->pleft = tL;					//将目标节点的父节点指向目标节点左节点
				tL->pparent = tP;				//将目标节点的左节点指向目标节点父节点
				delete targetPtr;				//释放targetPtr
				return true;					//返回true表示删除成功
			}	
			else {								//targetPtr为根节点
				proot = tL;						//目标节点的左节点改为根节点
				tL->pparent = NULL;				//放止根节点父节点变为野指针
				delete targetPtr;				//释放targetPtr
				return true;					//返回true表示删除成功
			}
		}
		if (tLL != NULL || tLR != NULL) {		//类型4 只有左节点，且左节点有子节点
			tnode* tL_subtree_max = Delete_user_Aux2(1, tL);
												//寻找targetPtr的左子树中的最大值节点
												//将结果返回到tL_subtree_max
			targetPtr->getUserdata() = tL_subtree_max->getUserdata();
			//用找到的tL_subtree_max指针指向的节点的数据域取代目标节点的数据域
			targetPtr = tL_subtree_max;			//将删除的目标节点转移到tL_subtree_max指向的节点
			Delete_user_Aux0(targetPtr);		//递归删除，当将目标节点转移到可直接删除类型时，将其删除
			return true;						//返回true表示删除成功
		}
	}
	else if (targetPtr->pleft == NULL && targetPtr->pright != NULL) {
		//目标节点的右节点非空，左节点为空 
		//类型5，6处理与类型3，4同理，注释略
		tnode* tR = targetPtr->pright;			//tR:目标节点右节点
		tnode* tP = targetPtr->pparent;			//tP：目标节点父节点
		tnode* tRL = tR->pleft;					//tRL:tR左节点
		tnode* tRR = tR->pright;				//tRR:tR右节点
		if (tRL == NULL && tRR == NULL) {		//类型5 只有右节点，且右节点无子节点
			if (tP) {
				tP->pright = tR;
				tR->pparent = tP;
				delete targetPtr;
				return true;
			}
			else {
				proot = tR;
				proot->pparent = NULL;
				delete targetPtr;
				return true;
			}
		}
		if (tRL != NULL || tRR != NULL) {		//类型6 只有右节点，且右节点有子节点
												//寻找targetPtr的右子树中的最小值节点
			tnode* tR_subtree_min = Delete_user_Aux2(0, tR);
			targetPtr->getUserdata() = tR_subtree_min->getUserdata();
			targetPtr = tR_subtree_min;
			Delete_user_Aux0(targetPtr);
			return true;
		}
	}
	else if (targetPtr->pleft != NULL && targetPtr->pright != NULL) {
												//类型7 左右节点都不为空
		//默认为找目标节点的右子树最小节点对目标节点进行替换，将目标节点转移到其右子树最小节点
		tnode* tR = targetPtr->pright;			//tR:目标节点的右节点
		tnode* tR_subtree_min = Delete_user_Aux2(0, tR);
		//找到目标节点右子树的最小节点，将指向其的指针返回到tR_subtree_min
		
		targetPtr->getUserdata() = tR_subtree_min->getUserdata();
												//进行替换
		targetPtr = tR_subtree_min;				//转移目标节点
		Delete_user_Aux0(targetPtr);			//递归删除
		return true;							//返回true表示删除成功
	}
	return NULL;
}

//注销用户，删除节点
void user_AVL::Delete_user(string uname) {
	tnode* targetPtr = Delete_user_Aux1(uname, proot);
												//找到要删除的节点targetPtr
	Delete_user_Aux0(targetPtr);				//删除目标节点
	Calculate_bf(proot);						//更新计算nbf
	inorder_bf(proot);							//调节平衡
}


//左旋
void user_AVL::RotateL(tnode* subroot){
	tnode* subR = subroot->pright;				//subR:subroot右节点
	tnode* subRL = subR->pleft;					//subRL:subR左节点
	tnode* pp = subroot->pparent;				//pp:subroot父节点
	subroot->pright = subRL;					//改subroot的右节点为subRL
	if (subRL) {								//subroot非空
		subRL->pparent = subroot;				//改subRL的父节点为subroot
	}
	subR->pleft = subroot;						//改subR的左节点为subroot
	subroot->pparent = subR;					//改subroot的父节点为subR
	if (subroot == proot) {						//若subroot是根节点
		proot = subR;							//更新根节点为subR
		subR->pparent = NULL;					//并更正subroot的父节点为NULL
	}
	else if(pp)									//pp非空，即subroot不为根节点
	{								
		if (pp->pleft ==subroot) {				//若subroot是pp的左节点
			pp->pleft = subR;					//则更新subR为pp的左节点
			subR->pparent = pp;					//改subR的父节点为pp
		}
		else {									//subroot是pp的右节点
			pp->pright = subR;					//更新subR为pp的右节点
			subR->pparent = pp;					//改subR的父节点为pp
		}
	}
}
//右旋	与左旋为对称操作，注释略
void user_AVL::RotateR(tnode* subroot){
	tnode* subL = subroot->pleft;
	tnode* subLR = subL->pright;
	tnode* pp = subroot->pparent;
	subroot->pleft = subLR;
	if (subLR) {
		subLR->pparent = subroot;
	}
	subL->pright = subroot;
	subroot->pparent = subL;
	if (subroot == proot) {
		proot = subL;
		subL->pparent = NULL;
	}
	else {
		if (pp->pleft == subroot) {
			pp->pleft = subL;
			subL->pparent = pp;
		}
		else {
			pp->pright = subL;
			subL->pparent = pp;
		}
	}
	subL->nbf = 0;
}
//右左旋
void user_AVL::RotateRL(tnode* subroot){
	tnode* subR = subroot->pright;				//subR为subroot的右节点
	this->RotateR(subR);						//以subR为参数进行右旋操作
	this->RotateL(subroot);						//以subroot为参数进行左旋操作
}
//左右旋
void user_AVL::RotateLR(tnode* subroot){
	tnode* subL = subroot->pleft;				//subL为subroot的左节点
	this->RotateL(subL);						//以subL为参数进行左旋操作
	this->RotateR(subroot);						//以subroot为参数进行右旋操作
}

//修改密码辅助递归函数 为class user_AVL的友元函数 找到用户名匹配的账号并修改密码
bool Change_p_Aux(string uname, string unpass, tnode* subroot) {
	//包含3个参数，用户名，新密码，当前子树根节点
	if (subroot == NULL)return false;			//递归终止条件：subroot为空
	if(Change_p_Aux(uname, unpass, subroot->pleft))return true;	
												//遍历subroot的左子树，若找到匹配的账号
												//对其密码进行修改，并返回true
	if (subroot->getUserdata().getName() == uname) {
		//找到了要修改密码的账号
		subroot->ChangePassword(uname,unpass);	//修改密码
		return true;							//返回true，可告知外层结束函数调用
	}
	if(Change_p_Aux(uname, unpass, subroot->pright))return true;
	return false;
}

//找到用户名所在节点，并修改密码
bool user_AVL::Change_password(string uname,string unpass){
	if (Change_p_Aux(uname, unpass, proot))return true;
	//调用修改密码辅助递归函数，修改成功返回true
	else return false;
	//修改失败返回false
}

//判断用户是否存在 辅助函数 为class user_AVL的友元函数
bool Check_e_Aux(string uname, tnode* subroot) {
	if (subroot == NULL) {						//递归终止条件：subroot为空
		return false;
	}
	if (Check_e_Aux(uname, subroot->pleft)) {	//遍历左子树找账号是否存在
		return true;														
	}
	if (uname == subroot->getUserdata().getName()) {
		//当前子树节点数据域账号的用户名与参数匹配，找到了账号，返回true
		return true;							//返回true，可告知外层结束函数调用
	}
	if (Check_e_Aux(uname, subroot->pright)) {	//遍历右子树找账号是否存在
		return true;
	}
	return false;								//若遍历完整棵树后未找到该账号，返回false
}

//检查AVL中是否存在用户名为uname的已注册账号，若存在，返回true
bool user_AVL::Check_exist(string uname) { 
	if (Check_e_Aux(uname, proot)) { return true; }
	//调用查找账号是否存在的辅助函数，若找到返回true
	else  return false;
	//未找到，返回false
}

//判断密码是否匹配辅助函数 为class user_AVL的友元函数
bool Check_m_Aux(string uname, string upass, tnode* subroot) {
	//三个参数，用户名，密码，先找到用户名匹配的账号，再验证密码是否匹配
	if (subroot == NULL)return false;			//递归终止条件：subroot为空
	if (Check_m_Aux(uname, upass, subroot->pleft))return true;
												//遍历subroot的左子树找到账号进行密码匹配
	if (uname == subroot->getUserdata().getName()) {
		//找到了账号
		if (upass == subroot->getUserdata().getPassword())return true;
		//进行密码匹配，匹配成功返回true，可告知外层已完成工作可退出
		else return false;
		//密码不匹配，返回false
	}
	if (Check_m_Aux(uname, upass, subroot->pright))return true;
	return false;
}

//判断输入的密码是否与用户名当前密码相同
bool user_AVL::Check_match(string uname, string upass) { 
	if (Check_m_Aux(uname, upass, proot)) {return true;}
	//调用密码匹配辅助函数判断密码是否正确
	else return false;
}
//将AVL读入到文件辅助函数：递归中序读入到文件
void write_AVL_Aux(tnode* subroot, ofstream& outAVL) {
	//传递关键参数，文件输出流对象的引用
	if (subroot == NULL)return;					//递归终止条件：当前子树节点subroot为空
	write_AVL_Aux(subroot->pleft,outAVL);		//遍历subroot左子树读入到文件
	outAVL << subroot->getUserdata().getName() << " " << subroot->getUserdata().getPassword() << endl;
	//输出当前节点的用户名和密码到文件
	write_AVL_Aux(subroot->pright, outAVL);		//遍历subroot右子树读入到文件
}
//将AVL读入到文件
void user_AVL::write() {						
	ofstream outAVL("user.txt");				//创建文件输出流对象，outAVL，输出到"user.txt"
	write_AVL_Aux(proot,outAVL);				//调用辅助函数读入到文件
}
//验收
bool user_AVL::Find_bfone_two() {
	if (Find_bfone_two_Aux(proot)) {
		Calculate_bf(proot);						//计算并更新每个节点的nbf
		inorder_bf(proot);							//调节平衡
		return true;
	}
	else return false;
}
bool user_AVL::Find_bfone_two_Aux(tnode* subroot) {
	if (subroot == NULL) {
		return false;
	}
	if (Find_bfone_two_Aux(subroot->pleft))return true;
	if (subroot->nbf == 1) {
		string name = "a";
		string password = "111";
		user u(name, password);
		insertAux(u, subroot->pleft, subroot);
		return true;
	}
	if (Find_bfone_two_Aux(subroot->pright))return true;
	return false;
}