#include"DClist.h"
#include<iostream>
using namespace std;
DClist::DClist() {
	head = new DCnode;
}
DClist::DClist(int maxcoef) {
	head = new DCnode(maxcoef,0);
}
DClist::~DClist() {
	
	DCnode* node = head->next;
	while (node != head)
	{
		DCnode* p = node->next;
		delete node;
		node = p;
	}
	delete head;
	
}
void DClist::insert(int coef,int index) {
	DCnode* newnode = new DCnode(coef, index);
	newnode->next = head->next;
	newnode->prev = head;
	head->next->prev = newnode;
	head->next = newnode;
}
void DClist::pop() {
	DCnode* node = head->next;
	head->next = node->next;
	node->next->prev = head;
	delete node;
}
void DClist::travers_out() {
	DCnode* node = head->next;
	while (node != head) {
		cout << node->index << " " << node->coef << endl;
		node = node->next;
	}
	cout << endl;
}