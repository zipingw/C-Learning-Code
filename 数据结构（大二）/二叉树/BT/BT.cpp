#include"BT.h"
#include<queue>
#include<vector>
#include<stack>
#include<iomanip>
using namespace std;
tnode* Insert_Recursive(tnode* locptr, tnode* Parent) {
	if (locptr == NULL)return NULL;								//�ݹ���ֹ����1��locptrΪ��,���ؿ�
	if (locptr == Parent) { return locptr; }					//�ݹ���ֹ����2���ҵ���Parent�ڵ㣬����locptr
	/*�������������������������������������������������������������ݹ飬�Ƚ�locptr��ڵ���Ϊ�������ٽ�locptr�ҽڵ���Ϊ����*/
	if (Insert_Recursive(locptr->left, Parent)) { return Insert_Recursive(locptr->left, Parent); }	//����ݹ�����еݹ麯������ֵ��Ϊ�գ����ҵ�Parent
	if (Insert_Recursive(locptr->right, Parent)) { return Insert_Recursive(locptr->right, Parent); }
	return NULL;
}
tnode* BT::Insert(tnode* Parent, int value, int oper) {
	tnode* newnode = new tnode(value);							//����newnode������Ҫ����Ľڵ�ֵ
	tnode* locptr = root;										//locptr��ʼ��Ϊroot
	if  (locptr != Parent) {									//��locptr������Parent
		tnode* result = Insert_Recursive(locptr, Parent);		//���õݹ���Parent���ݹ麯������ֵ����result
		if ( result!= NULL) {									//result�ǿգ����ҵ���Parent
			if (oper == 0) {									//��Ҫ���뵽Parent����ڵ�
				if (Parent->left != NULL)						//��ڵ�ǿգ��޷�����
				{ cout << "The designed pose is not available!" << endl; return NULL; }
				else                                            //��ڵ�Ϊ�գ�����
				{ Parent->left = newnode; return newnode;}
			}
			else if (oper == 1) {								//��Ҫ���뵽�ҽڵ㣬ͬ��
				if (Parent->right != NULL)
				{cout << "The designed pose is not available!" << endl; return NULL;}
				else
				{ Parent->right = newnode; return newnode;}
			}
		}
		/*����resultΪ�գ�δ�ҵ�Parent*/
		else {													
			cout << "There is not a matched parent in the tree!" << endl; return NULL;
		}
	}
	else{														//locptr��root����ΪParent,ֱ�Ӳ��룬�������ͬ��
		if (oper == 0) {
			if (Parent->left != NULL)
			{cout << "The designed pose is not available!" << endl; return NULL;}
			else
			{Parent->left = newnode; return newnode;}
		}
		else if (oper == 1) {
			if (Parent->right != NULL)
			{cout << "The designed pose is not available!" << endl; return NULL;}
			else
			{ Parent->right = newnode; return newnode;}
		}
	}
}
void BT::printtree(int indent,tnode* subtreeroot) {						//�ݹ��ӡ�����νṹ
	if (subtreeroot != 0) {												//�������ڵ�ǿ�
		/*�������Ϊ���������*/
		printtree(indent + 8, subtreeroot->right);						//�ݹ飬�����ҽڵ㣬indent+8
		cout << setw(indent) << " " << subtreeroot->nodeValue << endl;	//�����ǰ���ڵ�
		printtree(indent + 8, subtreeroot->left);						//�ݹ飬������ڵ㣬indent+8
	}
}
void BT::InOrder(tnode* subtreeroot) {									//����������
	vector<tnode*> v;													//STL  vector v, TΪtnode* �������ڵ㰴����˳���������
	stack<tnode*> s;													//STL  stack s , TΪtnode* ��
	while (subtreeroot || !s.empty()) {									//�������ڵ�ǿ�  ��  s�ǿ�
		while (subtreeroot) {											/*����ѭ�� ѭ����ֹ�������������ڵ�Ϊ��
																		  ѭ�����ã����Ƚ�������߽ڵ����ջ��
																		*/	
			s.push(subtreeroot);										//ѭ���壺�������ڵ���ջ��
			subtreeroot = subtreeroot->left;							//�������ڵ�����������ڵ����ڵ�
		}
		if (!s.empty()) {												//�Ϸ�ѭ����������s�ǿ�
			subtreeroot = s.top();										//ȡ��ջ�� Ϊ�������ڵ㸳ֵ
			s.pop();													//ջ�׳�ջ
			v.push_back(subtreeroot);									/*��ǰ�������ڵ���ջ��
																		 ����ʵ�����ڵ㰴������ջ*/
			subtreeroot = subtreeroot->right;							//�������ڵ�����������ڵ���ҽڵ�
		}
	}
	for (int i = 0; i < v.size(); i++) {								//���v������Ԫ�� 
		cout << v[i]->nodeValue << " ";
	}
	cout << endl;
}
int  BT::countleaf_Recursive(tnode* subtreeroot) {						//�ݹ������Ҷ�ڵ���
	if (subtreeroot == NULL)return count;								//�ݹ���ֹ�������������ڵ�ΪNULL
	if (subtreeroot->left == NULL && subtreeroot->right == NULL) {		//���������ڵ� ��ڵ���ҽڵ㶼Ϊ�գ�count+1
		count++;
	}
	countleaf_Recursive(subtreeroot->left);								//�Ƚ��������ڵ����ڵ���Ϊ�������õݹ麯��
	countleaf_Recursive(subtreeroot->right);							//�ٽ��������ڵ���ҽڵ����������õݹ麯��
												
	return count;
}
int BT::countleaf(tnode* subtreeroot) {									
	count = 0;															//�Ƚ�count����
	countleaf_Recursive(subtreeroot);									//���õݹ麯������count
	return count;
}