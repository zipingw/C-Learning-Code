#include"BST.h"
#include<queue>
#include<vector>
using namespace std;
tnode* BST::Insert(tnode* Parent, int value, int oper) {
	tnode* newnode = new tnode(value);
	tnode* locptr = root;
	bool found = false;
	while (locptr->nodeValue!=Parent->nodeValue&&!found) {
		if (value < locptr->nodeValue) { locptr = locptr->left; }
		else if (value > locptr->nodeValue) { locptr = locptr->right; }
		
	}
}
void BST::Insert(int value) {
	tnode* newnode = new tnode(value);
	tnode* locptr = root, *parent = 0;
	bool found = false;
	while (!found && locptr != 0) {
		parent = locptr;
		if (value < locptr->nodeValue) { locptr = locptr->left; }
		else if (value > locptr->nodeValue) { locptr = locptr->right; }
		else found = true;
	}
	if (!found) {
		locptr = new tnode(value);
		if (parent == 0)root = locptr;
		else if (value < parent->nodeValue)parent->left = locptr;
		else parent->right = locptr;
	}
	else { cout << "The value have been in the tree." << endl; }
}
//获得每个节点的所在行
void BST::traverse_level(tnode* root) {
	if (root == 0) {
		return;
	}
	queue<tnode *> qnodes;
	vector<int> num_nodes;
	num_nodes.push_back(1);
	num_nodes.push_back(0);
	int n = 0, depth = 0;
	for(qnodes.push(root); !qnodes.empty(); qnodes.pop()) {
		tnode* temp = qnodes.front();
		cout << temp->nodeValue << " ";
		if (temp->left) {
			qnodes.push(temp->left);
			num_nodes[depth + 1]++;
		}
		if (temp->right) {
			qnodes.push(temp->right);
			num_nodes[depth + 1]++;
		}
		if (++n == num_nodes[depth]) {
			n = 0;
			depth++;
			num_nodes.push_back(0);
			cout << endl;
		}
	}
}
//获得每个节点所在列
void BST::traverse_row(tnode* root) {
	
}

void BST::printtree(int *l,int *r) {

}

/*
tnode* BST::sss(tnode* locptr,tnode* Parent, int value, int oper) {
	bool f = false;
	if (locptr->nodeValue == Parent->nodeValue) {
		f = true;
		tnode* newnode = new tnode(value, NULL, NULL);
		if (oper) {
			if (locptr->right != NULL) {
				return NULL;
			}
			else { locptr->right = newnode; return locptr; }
		}
		else {
			if (locptr->left != NULL) {
				return NULL;
			}
			else { locptr->left = newnode; return locptr; }
		}
	}
}*/
/*
void BST::inorderAux(ostream& out, tnode* subtreeRoot)const {
	if (!subtreeRoot) {
		inorderAux(out, subtreeRoot->left);
		out << subtreeRoot->nodeValue << " ";
		inorderAux(out, subtreeRoot->right);
	}
}
*/