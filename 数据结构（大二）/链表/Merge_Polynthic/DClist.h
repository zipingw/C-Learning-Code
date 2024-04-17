#pragma once
#include"DCnode.h"
#include<string>
using namespace std;
class DClist {
public:
	DCnode* head;
	DClist();
	DClist(int maxcoef);
	~DClist();
	void insert(int coef,int index);
	void pop();
	void travers_out();
};