#include "Admin.h"
Admin::~Admin() {
	DeleteAux(root);
}
Admin::Admin(const Admin& OriginalTree) {
	copyAux(root, OriginalTree.root);
}
Admin& Admin::operator=(const Admin& RightTree) {
	DeleteAux(root);
	copyAux(root, RightTree.root);
	return *this;
}
bool Admin::empty()const {
	return (root == 0);
}//判空函数
bool Admin::normalInsert(const string userName, const string code) {
	NodePointer current = root,  //查找指针
		parent = 0;              //指向当前节点的双亲节点的指针
	bool found = false;
	while (!found && current != NULL) {
		parent = current;
		if (userName < current->user_name)
			current = current->left;
		else if (current->user_name < userName)
			current = current->right;
		else {
			found = true;
			return false;
		}
	}
	if (!found) {
		isuserName(userName, found);
		if (found) {
			iscode(code, found);
			if (found) {
				current = new Node(userName, code);
				if (parent == 0)
					root = current;
				else if (userName < parent->user_name)
					parent->left = current;
				else
					parent->right = current;
				refresh();                      //插入后重新计算树的高度等因素
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
}
bool Admin::Insert(const string userName, const string code) {
	if (normalInsert(userName, code)) {                    //如果插入了新的节点
		NodePointer current = root, parent = NULL, grandparent = NULL;
		NodePointer deepest2node = NULL, deepest2nodeparent = NULL;
		while (current != NULL) {
			if (parent != NULL)
				grandparent = parent;
			parent = current;
			if (userName < current->user_name) {
				if (current->balanceFactor == 2 || current->balanceFactor == -2) {
					deepest2node = current;
					deepest2nodeparent = grandparent;
				}
				current = current->left;
			}
			else if (userName > current->user_name) {
				if (current->balanceFactor == 2 || current->balanceFactor == -2) {
					deepest2node = current;
					deepest2nodeparent = grandparent;
				}
				current = current->right;
			}
			else
				break;//找到插入对象，循环终止
		}
		balanceAux(deepest2node, deepest2nodeparent);//平衡树
		return true;
	}
	else {
		cout << "Insert error!" << endl;
		return false;
	}
}
void Admin::refresh() {
	int h = 0;
	refreshAux(h, 0, root);
}
void Admin::LVR()const {
	inorderAux(root);
}
void Admin::DeleteAux(NodePointer current) {
	if (current->left != 0)
		DeleteAux(current->left);
	if (current->right != 0)
		DeleteAux(current->right);
	delete current;
}
void Admin::refreshAux(int& h, int f, NodePointer current) {
	if (current == 0)
		h = 0;
	else
	{
		int left_height, right_height;
		current->floor = f;
		refreshAux(left_height, f + 1, current->left);
		refreshAux(right_height, f + 1, current->right);
		current->balanceFactor = left_height - right_height;
		h = 1 + max(left_height, right_height);
		current->height = h;
	}
}
void Admin::inorderAux(NodePointer current)const {
	if (!empty()) {
		if (current != NULL) {
			inorderAux(current->left);
			cout << "user_name: " << current->user_name << endl;
			inorderAux(current->right);
		}
	}
	else {
		cout << "There is no avaliable memory!" << endl;
	}
}
void Admin::graph()const {
	graphAux(0, root);
}
void Admin::graphAux(int intend, NodePointer current)const {
	if (!empty()) {
		if (current != NULL) {
			graphAux(intend + 20, current->right);
			cout << setw(intend) << " " << current->user_name << " " << current->balanceFactor << " " << current->height << " " << current->floor << endl;
			graphAux(intend + 20, current->left);
		}
	}
	else {
		cout << "There is no avaliable memory!" << endl;
	}
}
void Admin::searchAux(const string& sName, bool& found, NodePointer& current, NodePointer& parent)const {
	if (!empty()) {
		while (current != 0) {
			if (sName < current->user_name) {
				parent = current;
				current = current->left;
			}
			else if (sName > current->user_name) {
				parent = current;
				current = current->right;
			}
			else {
				found = true;
				break;
			}
		}
	}
	else 
		cout << "There is no avaliable memory!" << endl;
}
Admin::NodePointer Admin::search(const string& sName)const {
	bool found = false;
	NodePointer parent = NULL;
	NodePointer current = root;
	searchAux(sName, found, current, parent);
	if (found)
		return current;
	else {
		cout << "There is no " << sName << " in the system!" << endl;
		return NULL;
	}
}
bool Admin::match(const string& sName, const string& sCode)const {
	NodePointer current = search(sName);
	if (current != NULL) {
		if (current->code == sCode)
			return true;
		else {
			cout << "The code is error!" << endl;
			return false;
		}
	}
	else
		return false;
}
int Admin::Getheight(NodePointer current)const {
	if (current == 0)
		return 0;
	else
		return current->height;
}
bool Admin::findDeepest2Node(NodePointer& deepest2node, NodePointer& parent) {
	deepest2node = NULL;
	parent = NULL;
	findDeepest2NodeAux(deepest2node, root, parent);
	if (deepest2node == NULL)
		return false;
	else
		return true;
}
void Admin::findDeepest2NodeAux(NodePointer& deepest2node, NodePointer current, NodePointer& parent) {
	if (!empty()) {
		if (current != 0) {
			if (current == root && (current->balanceFactor == 2 || current->balanceFactor == -2)) {
				deepest2node = root;
				parent = NULL;
			}
			findDeepest2NodeAux(deepest2node, current->left, parent);
			findDeepest2NodeAux(deepest2node, current->right, parent);
			if (current->right != NULL && (current->right->balanceFactor == 2 || current->right->balanceFactor == -2)) {
				deepest2node = current->right;
				parent = current;
			}
			else if (current->left != NULL && (current->left->balanceFactor == 2 || current->left->balanceFactor == -2)) {
				deepest2node = current->left;
				parent = current;
			}
		}
	}
}
void Admin::balance() {
	NodePointer deepest2node, parent;
	while (findDeepest2Node(deepest2node, parent)) {//利用循环防止存在多个节点的平衡因子为2或-2
		balanceAux(deepest2node, parent);
	}
}
void Admin::balanceAux(NodePointer deepest2node, NodePointer parent) {
	if (deepest2node != NULL) {
		//不平衡由树高改变引起，因此应寻找高的子树
		if (deepest2node->balanceFactor == 2) {//如果deepest2node节点的balanceFactor等于2，必然左子树引起不平衡
			if (Getheight(deepest2node->left->left) >= Getheight(deepest2node->left->right)) {//左子树树高更高
				RRotate(deepest2node, parent);
			}
			else //右子树树高更高
				LRRtoate(deepest2node, parent);
		}
		else if (deepest2node->balanceFactor == -2) {//如果deepest2node节点的balanceFactor等于-2，必然右子树引起不平衡
			if (Getheight(deepest2node->right->left) <= Getheight(deepest2node->right->right))//右子树更高
				LRtoate(deepest2node, parent);
			else//左子树更高
				RLRtoate(deepest2node, parent);
		}
		refresh();//刷新各项因素
	}
}
void Admin::RRotate(NodePointer deepest2node, NodePointer parent) {
	//parent为deepest2node的父结点
	if (deepest2node != NULL) {
		NodePointer A, B;          //A表示离插入项最近的具有平衡因子2或-2的祖先节点,B表示A的左孩子
		if (deepest2node == root) {//如果平衡因子为2的节点deepest2node为根节点
			A = root;
			B = A->left;
			root = B;
		}
		else {
			A = deepest2node;
			B = A->left;
			if (parent->left == deepest2node)
				parent->left = B;
			else if (parent->right == deepest2node)
				parent->right = B;
		}
		A->left = B->right;
		B->right = A;
	}
}
void Admin::LRtoate(NodePointer deepest2node, NodePointer parent) {
	if (deepest2node != NULL) {
		NodePointer A, B;
		if (deepest2node == root) {
			A = root;
			B = A->right;
			root = B;
		}
		else {
			A = deepest2node;
			B = A->right;
			if (parent->left == deepest2node)
				parent->left = B;
			else if (parent->right == deepest2node)
				parent->right = B;
		}
		A->right = B->left;
		B->left = A;
	}
}
void Admin::LRRtoate(NodePointer deepest2node, NodePointer parent) {
	NodePointer A, B, C;
	A = deepest2node;
	B = A->left;
	C = B->right;
	//左旋
	A->left = C;
	B->right = C->left;
	C->left = B;
	//右旋
	if (parent != NULL) {
		if (parent->left == deepest2node)
			parent->left = C;
		else if (parent->right == deepest2node)
			parent->right = C;
	}
	else
		root = C;
	A->left = C->right;
	C->right = A;
}
void Admin::RLRtoate(NodePointer deepest2node, NodePointer parent) {
	NodePointer A, B, C;
	A = deepest2node;
	B = A->right;
	C = B->left;
	//右旋
	A->right = C;
	B->left = C->right;
	C->right = B;
	//左旋
	if (parent != NULL) {
		if (parent->left == deepest2node)
			parent->left = C;
		else if (parent->right == deepest2node)
			parent->right = C;
	}
	else
		root = C;
	A->right = C->left;
	C->left = A;
}
bool Admin::remove(const string& sName) {
	bool found;
	NodePointer
		x,           //指向将被删除的节点
		parent;      //指向x和xSucc的双亲节点
	searchAux2(sName, found, x, parent);
	if (!found) {
		cout << "There is no "<<sName<<" in the system!.\n";
		return false;
	}
	//处理节点有两个子女的情况
	else if (x->left != 0 && x->right != 0) {
		NodePointer xSucc = x->right;
		parent = x;
		while (xSucc->left != 0) {//下降到左子树
			parent = xSucc;
			xSucc = xSucc->left;
		}
		x->user_name = xSucc->user_name;
		x->code = xSucc->code;
		x->balanceFactor = xSucc->balanceFactor;
		x->floor = xSucc->floor;
		x->height = xSucc->height;
		x = xSucc;
	}
	//处理节点没有子女和只有一个子女的情况
	NodePointer subtree = x->left;//指向x子树的指针
	if (subtree == 0)
		subtree = x->right;
	if (parent == 0)              //将被删除的是根节点
		root = subtree;
	else if (parent->left == x)   //双亲节点的左子节点
		parent->left = subtree;
	else                          //双亲节点的右子节点
		parent->right = subtree;
	delete x;
	refresh();//刷新各项因素
	balance();//平衡树
	return true;
}
void Admin::copyAux(NodePointer& current, NodePointer bstcurrent) {
	if (bstcurrent != NULL) {
		current = new Node(*bstcurrent);
		copyAux(current->left, bstcurrent->left);
		copyAux(current->left, bstcurrent->left);
	}
}
void Admin::isuserName(string un, bool& found)const {
	if (un.length() >= MIN_USERNAME && un.length() <= MAX_USERNAME)//判断输入的用户名长度是否合法
		found = true;
	else {
		cout << "Input error,the length of user_name is illegal!" << endl;
		found = false;
	}
}
void Admin::iscode(string c, bool& found)const {
	bool tag = false;
	if (c.length() >= MIN_CODE && c.length() <= MAX_CODE) {          //判断输入的用户名长度是否合法
		if (isupper(c[0]) != 0)                                      //判断输入的密码开头是否为大写字母
			tag = true;
		else {
			cout << "Input error,the first char of code is not a upper letter! " << endl;
			tag = false;
		}
	}
	else {
		cout << "Input error,the length of code is illegal!" << endl;
		tag = false;
	}
	if (tag)
		found = true;
	else
		found = false;
}
void Admin::searchAux2(const string& sName, bool& found, NodePointer& current, NodePointer& parent) {
	current = root;
	parent = 0;
	found = false;
	while (!found && current != 0) {
		if (sName < current->user_name) {
			parent = current;
			current = current->left;
		}
		else if (current->user_name < sName) {
			parent = current;
			current = current->right;
		}
		else
			found = true;
	}
}
void Admin::Login(const string sName, const string sCode)const {
	bool login = match(sName, sCode);
	if (login)
		cout << "Login successfully!" << endl;
}
void Admin::Change_Password(const string sName, const string sCode) {
	NodePointer current = search(sName);//找到要修改密码的用户
	if (current != NULL) {
		current->code = sCode;
		cout << "Modified successfully!" << endl;
	}
}
void Admin::write(ostream& out) {
	writeAux(out, root);
}
void Admin::writeAux(ostream& out, NodePointer current) {
	if (current != NULL) {
		writeAux(out, current->left);
		out << "userName: " << current->user_name << " Password: " << current->code << endl;
		writeAux(out, current->right);
	}
}