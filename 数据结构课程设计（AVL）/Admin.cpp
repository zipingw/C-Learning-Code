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
}//�пպ���
bool Admin::normalInsert(const string userName, const string code) {
	NodePointer current = root,  //����ָ��
		parent = 0;              //ָ��ǰ�ڵ��˫�׽ڵ��ָ��
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
				refresh();                      //��������¼������ĸ߶ȵ�����
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
	if (normalInsert(userName, code)) {                    //����������µĽڵ�
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
				break;//�ҵ��������ѭ����ֹ
		}
		balanceAux(deepest2node, deepest2nodeparent);//ƽ����
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
	while (findDeepest2Node(deepest2node, parent)) {//����ѭ����ֹ���ڶ���ڵ��ƽ������Ϊ2��-2
		balanceAux(deepest2node, parent);
	}
}
void Admin::balanceAux(NodePointer deepest2node, NodePointer parent) {
	if (deepest2node != NULL) {
		//��ƽ�������߸ı��������ӦѰ�Ҹߵ�����
		if (deepest2node->balanceFactor == 2) {//���deepest2node�ڵ��balanceFactor����2����Ȼ����������ƽ��
			if (Getheight(deepest2node->left->left) >= Getheight(deepest2node->left->right)) {//���������߸���
				RRotate(deepest2node, parent);
			}
			else //���������߸���
				LRRtoate(deepest2node, parent);
		}
		else if (deepest2node->balanceFactor == -2) {//���deepest2node�ڵ��balanceFactor����-2����Ȼ����������ƽ��
			if (Getheight(deepest2node->right->left) <= Getheight(deepest2node->right->right))//����������
				LRtoate(deepest2node, parent);
			else//����������
				RLRtoate(deepest2node, parent);
		}
		refresh();//ˢ�¸�������
	}
}
void Admin::RRotate(NodePointer deepest2node, NodePointer parent) {
	//parentΪdeepest2node�ĸ����
	if (deepest2node != NULL) {
		NodePointer A, B;          //A��ʾ�����������ľ���ƽ������2��-2�����Ƚڵ�,B��ʾA������
		if (deepest2node == root) {//���ƽ������Ϊ2�Ľڵ�deepest2nodeΪ���ڵ�
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
	//����
	A->left = C;
	B->right = C->left;
	C->left = B;
	//����
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
	//����
	A->right = C;
	B->left = C->right;
	C->right = B;
	//����
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
		x,           //ָ�򽫱�ɾ���Ľڵ�
		parent;      //ָ��x��xSucc��˫�׽ڵ�
	searchAux2(sName, found, x, parent);
	if (!found) {
		cout << "There is no "<<sName<<" in the system!.\n";
		return false;
	}
	//����ڵ���������Ů�����
	else if (x->left != 0 && x->right != 0) {
		NodePointer xSucc = x->right;
		parent = x;
		while (xSucc->left != 0) {//�½���������
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
	//����ڵ�û����Ů��ֻ��һ����Ů�����
	NodePointer subtree = x->left;//ָ��x������ָ��
	if (subtree == 0)
		subtree = x->right;
	if (parent == 0)              //����ɾ�����Ǹ��ڵ�
		root = subtree;
	else if (parent->left == x)   //˫�׽ڵ�����ӽڵ�
		parent->left = subtree;
	else                          //˫�׽ڵ�����ӽڵ�
		parent->right = subtree;
	delete x;
	refresh();//ˢ�¸�������
	balance();//ƽ����
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
	if (un.length() >= MIN_USERNAME && un.length() <= MAX_USERNAME)//�ж�������û��������Ƿ�Ϸ�
		found = true;
	else {
		cout << "Input error,the length of user_name is illegal!" << endl;
		found = false;
	}
}
void Admin::iscode(string c, bool& found)const {
	bool tag = false;
	if (c.length() >= MIN_CODE && c.length() <= MAX_CODE) {          //�ж�������û��������Ƿ�Ϸ�
		if (isupper(c[0]) != 0)                                      //�ж���������뿪ͷ�Ƿ�Ϊ��д��ĸ
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
	NodePointer current = search(sName);//�ҵ�Ҫ�޸�������û�
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