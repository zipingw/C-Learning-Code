#include"BST.h"
#include<iostream>
using namespace std;
int main() {
	BST t1;
	t1.Insert(5);
	t1.Insert(3);
	t1.Insert(7);
	t1.Insert(4);
	t1.Insert(6);
	t1.Insert(2);
	t1.Insert(8);
	t1.traverse_level(t1.root);
}