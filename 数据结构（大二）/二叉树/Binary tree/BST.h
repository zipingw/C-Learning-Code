#pragma once
#include"tnode.h"
class BST {
	
public:
	tnode* root;
	BST() { 
		root = NULL;
		//tnode* left=NULL, * right=NULL;
		//root->left = left; root->right = right;
		//root->nodeValue = 0;
	}
	tnode* Insert(tnode* Parent, int value, int oper);
	void Insert(int value);
	void traverse_level(tnode* root);
	void traverse_row(tnode* root);
	tnode* sss(tnode*,tnode*, int, int);
	void printtree(int *,int *);
	//void inorderAux(ostream& out, tnode* subtreePtr)const;
};