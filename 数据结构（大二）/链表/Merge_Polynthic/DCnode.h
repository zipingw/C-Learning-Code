#pragma once
class DCnode {
public:
	int coef;											//系数
	int index;											//指数
	DCnode* prev;
	DCnode* next;
	DCnode() {
		coef = 0;
		index = 0;
		next = this;
		prev = this;
	}
	DCnode(const int valuec,const int valuei) :coef(valuec),index(valuei) {
		next = this;
		prev = this;
	}
};