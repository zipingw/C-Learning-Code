#pragma once
class DCnode {
public:
	int coef;											//ϵ��
	int index;											//ָ��
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