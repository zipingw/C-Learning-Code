#pragma once
class Dnode {
public:
	int nodeValue;									//数据域
	Dnode* prev;									//前一节点
	Dnode* next;									//下一节点
	Dnode() {										//构造函数
		nodeValue = 0;						
		next = this;								//next指向自身
		prev = this;								//prev指向自身
	}
	Dnode(const int value) :nodeValue(value) {		//构造函数重载
		next = this;								//next指向自身
		prev = this;								//prev指向自身
	}
};