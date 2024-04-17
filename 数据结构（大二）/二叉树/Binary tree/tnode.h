#pragma once
#include<iostream>
using namespace std;
class tnode
{
public:
	int nodeValue;
	tnode* left, * right;
	tnode() {}
	tnode(const int& item, tnode* lptr = NULL, tnode* rptr = NULL) :nodeValue(item), left(lptr), right(rptr) {}
};




