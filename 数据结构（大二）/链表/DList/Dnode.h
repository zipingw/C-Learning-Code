#pragma once
class Dnode {
public:
	int nodeValue;									//������
	Dnode* prev;									//ǰһ�ڵ�
	Dnode* next;									//��һ�ڵ�
	Dnode() {										//���캯��
		nodeValue = 0;						
		next = this;								//nextָ������
		prev = this;								//prevָ������
	}
	Dnode(const int value) :nodeValue(value) {		//���캯������
		next = this;								//nextָ������
		prev = this;								//prevָ������
	}
};