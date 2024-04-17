#include"user_AVL.h"
#include<iomanip>
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
//���캯��
user_AVL::user_AVL() { proot = NULL; nmaxheight = 0; }
//��������
user_AVL::~user_AVL() {
	Destroy(proot);				//�ݻ����������ͷ�����ָ��
}
//�ݻ����������ݹ����ɾ�����нڵ㣬�ͷ�����ָ��
void user_AVL::Destroy(tnode* subroot) {
	if (subroot == NULL) {		//�ݹ���ֹ�������ڵ�Ϊ��
		return;
	}
	Destroy(subroot->pleft);	//�����������ͷ�ָ��
	Destroy(subroot->pright);	//�����������ͷ�ָ��
	delete subroot;				//�ͷ�ָ��
}
//�����ӡ���θ�������
void inorderAux(int indent, tnode* subroot) {
	if (subroot != 0) {			//�ݹ���ֹ�������ڵ�Ϊ��
		inorderAux(indent + 8, subroot->pleft);	//������������ÿ�������һ�㣬���ʱ+8�ո�
		cout << setw(indent) << " " << subroot->getUserdata().getName() << endl;	//���
		inorderAux(indent + 8, subroot->pright);//������������ÿ���Ҽ���һ�㣬���ʱ+8�ո�
	}
}

//��ӡ��
void user_AVL::printtree() {
	inorderAux(0, proot);		//���������ӡ����������������������Σ���ʼ�ո���Ϊ0
}

//�������ĸ߶ȸ���������Ϊclass user_AVL����Ԫ����
int DepthAux(tnode* subroot) {	//������subrootΪ���ڵ�����ĸ߶�
	if (subroot == NULL) {		//�ݹ���ֹ���������ڵ�Ϊ��
		return 0;
	}
	int leftheight = DepthAux(subroot->pleft);	//����subroot�������������߶�
	int rightheight = DepthAux(subroot->pright);//����subroot�������������߶�
	int max = leftheight > rightheight ? leftheight : rightheight;//ȡ���������иߵ�
	return max + 1;								//max+1��ΪsubrootΪ���ڵ�������ĸ߶�
}

//������subrootΪ���ڵ�������ĸ߶�
int user_AVL::DepthOfTree(tnode* subroot) {		
	nmaxheight = DepthAux(subroot);				//���ü������ĸ߶ȸ��������������߶�
	return nmaxheight;							//��������ֵ����subrootΪ���ڵ�����ĸ߶�
}

//����bf����������ÿ���ڵ���������߶ȼ��������߶ȣ�Ϊclass user_AVL����Ԫ����
void Calculate_bf_Aux(tnode* subroot) {
	int leftheight = DepthAux(subroot->pleft);	//����subroot�ڵ���������ĸ߶�
	int rightheight = DepthAux(subroot->pright);//����subroot�ڵ���������ĸ߶�
	subroot->nbf = leftheight - rightheight;	//subroot�ڵ��ƽ������Ϊ�������߶ȼ��������߶�
}

//�ݹ�����������нڵ��ƽ�����Ӹ��µ�ÿ���ڵ��nbf��
void user_AVL::Calculate_bf(tnode* subroot) {
	if (subroot == NULL) {						//�ݹ���ֹ������subrootΪ��	
		return;
	}
	Calculate_bf(subroot->pleft);				//�����������еĽڵ��ƽ������
	Calculate_bf_Aux(subroot);					//���㵱ǰ�ڵ��ƽ������
	Calculate_bf(subroot->pright);				//�����������еĽڵ��ƽ������
}

//���븨��������������� �ҵ������ ��Ϊclass user_AVL����Ԫ����
void insertAux(user& u, tnode*& subroot, tnode* parent) {
	//����uΪҪ������û����ݣ�subrootΪ��ǰ�ڵ㣬parentΪ��ǰ�ڵ�ĸ��ڵ�
	if (subroot == NULL) {						//�ݹ���ֹ������subrootΪ��
												//����ǰλ��Ϊ�½ڵ�Ҫ�����λ��
		subroot  = new tnode(u);				//����һ��ռ����u����ַΪsubroot
		subroot->pparent = parent;				//ָ���½ڵ�subroot�ĸ��ڵ�
												//ʹ��ÿ���ڵ�ĸ��ڵ���ָ�򡢿���
	}
	else if (u.getName() < subroot->getUserdata().getName()) {
												//Ҫ���������Ӧ���뵱ǰ���ݵ����
		insertAux(u, subroot->pleft,subroot);	//���ݲ�������ǰ�ڵ��Ϊ�����ӣ����ڵ��Ϊ��ǰ�ڵ�
	}
	else if (u.getName() > subroot->getUserdata().getName()) {
												//Ҫ���������Ӧ���뵱ǰ���ݵ��ұ�
		insertAux(u, subroot->pright,subroot);	//���ݲ�������ǰ�ڵ��Ϊ���Һ��ӣ����ڵ��Ϊ��ǰ�ڵ�
	}
}

//����ƽ�⸨���������жϲ�ƽ��Ľڵ�Ӧ��ִ��������ת�е���һ�ֲ���ת
void user_AVL::inorder_bf(tnode*subroot) {
	if (subroot == NULL)return;					//�ݹ���ֹ������subrootΪ��
	inorder_bf(subroot->pleft);					//����subroot�������Ҳ�ƽ��ڵ�
	if (abs(subroot->nbf) == 2) {				//ƽ�����Ӿ���ֵ����2
	//��Ϊ��ȷ���������Ͳ��뼰ɾ��ʱÿһ���ڵ㶼�����ƽ���������ƽ�����Ӿ���ֵ�������2
		if (subroot->nbf == 2) {				//ƽ������Ϊ2
			if (subroot->pleft->nbf == 1) {		//subroot����ڵ�ƽ������Ϊ1
				RotateR(subroot);				//��subrootΪ���� ����
				Calculate_bf(proot);			//���¼������������нڵ��ƽ������
				return ;						//����
			}
			else if (subroot->pleft->nbf == -1) {//subroot����ڵ�ƽ������Ϊ-1
				RotateLR(subroot);				//��subrootΪ���� ������
				Calculate_bf(proot);			//���¼������������нڵ��ƽ������
				return ;						//����
			}
		}
		else if (subroot->nbf == -2) {			//ƽ�����Ӿ���ֵ����-2
			if (subroot->pright->nbf == -1) {	//subroot����ڵ�ƽ������Ϊ-1
				RotateL(subroot);				//��subrootΪ���� ����
				Calculate_bf(proot);			//���¼������������нڵ��ƽ������
				return ;						//����
			}
			else if (subroot->pright->nbf == 1) {//subroot����ڵ�ƽ������Ϊ1
				RotateRL(subroot);				//��subrootΪ���� ������
				Calculate_bf(proot);			//���¼������������нڵ��ƽ������
				return ;						//����
			}
		}
	}
	inorder_bf(subroot->pright);				//����subroot�������Ҳ�ƽ��ڵ�
}

//���뺯������user��Ϊuserdata�����½ڵ�
void user_AVL::Insert(user& u) {
	if (proot == NULL) {						//���ڵ�Ϊ��
		proot = new tnode(u);					//�����ݲ��뵽���ڵ�
		proot->pparent = NULL;					//ָ�����ڵ�Ϊ�գ���ֹ�丸�ڵ��ΪҰָ��
	}
	else {										//���ڵ�ǿ�
		insertAux(u, proot, proot->pparent);	//�����½ڵ�
	}
	Calculate_bf(proot);						//���㲢����ÿ���ڵ��nbf
	inorder_bf(proot);							//����ƽ��
	DepthOfTree(proot);							//���㲢��������nmaxheight
}

//���������ӡÿ���ڵ��nbf��������֤nbf�����Ƿ���ȷ
void user_AVL::printbf(tnode* subroot) {
	if (subroot == NULL)return;					//�ݹ���ֹ������subrootΪ��
	printbf(subroot->pleft);					//����subroot��������
	cout << subroot->nbf << " ";				//���nbf
	printbf(subroot->pright);					//����subroot��������
}

//ɾ��������������2�������������е����ڵ���������е���С�ڵ�
tnode* Delete_user_Aux2(int LoR, tnode* subroot) {
	//LoRֵΪ1ʱ����subroot�ĸ��ڵ�Ϊ���ڵ�����������ֵ��Ϊ0ʱ����������Сֵ
	if (LoR == 1) {
		while (subroot->pright != NULL) {		//ѭ���ߵ�subroot�����ҷǿսڵ�
			subroot = subroot->pright;			
		}
		return subroot;							
		//�����ҵ��Ľڵ㣬��subroot���ڵ�����������ڵ�
	}
	else if (LoR == 0) {
		while (subroot->pleft != NULL) {		//ѭ���ߵ�subroot������ǿսڵ�
			subroot = subroot->pleft;			
		}
		return subroot;
		//�����ҵ��Ľڵ㣬��subroot���ڵ����������С�ڵ�
	}
	return NULL;
}

//ɾ����������1���ҵ���ɾ���Ľڵ� Ϊclass user_AVL����Ԫ����
tnode* Delete_user_Aux1(string uname, tnode*& subroot) {
	if (subroot == NULL) { return NULL; }		//�ݹ���ֹ������subrootΪ��
	if (tnode* ptr = Delete_user_Aux1(uname, subroot->pleft))
												//�ݹ����subrootΪ���ڵ��������
												//�������з���ֵ�����ҵ���Ҫɾ���Ľڵ�
		return ptr;								//�����ҵ��Ľڵ�
	if (subroot->getUserdata().getName() == uname) {
												//subroot�ڵ���������û�����Ҫɾ�����û��˺��û�����ͬ
												//subroot��Ҫɾ���Ľڵ�
		return subroot;							//���ظýڵ㣬���ɽ���ݹ鷵�ص������
	}
	if (tnode* ptr = Delete_user_Aux1(uname, subroot->pright))
												//�ݹ����subrootΪ���ڵ��������
												//�������з���ֵ�����ҵ���Ҫɾ���Ľڵ�
		return ptr;								//�����ҵ��Ľڵ�
	return NULL;								//û�ҵ����ؿ�
}

//ɾ����������0��ɾ���ҵ��Ľڵ�
bool user_AVL::Delete_user_Aux0(tnode*& targetPtr) {
	//���ҵ�Ҫɾ����Ŀ��ڵ�
	//�ж�Ŀ��ڵ��������������е���һ��
	//�������ͣ�1.���ӽڵ�ĸ��ڵ� 2.���ӽڵ��ҷǸ��ڵ�(Ҷ�ӽڵ�)
	//3.ֻ����ڵ㣬����ڵ����ӽڵ� 4.ֻ����ڵ㣬����ڵ����ӽڵ�
	//5.ֻ���ҽڵ㣬���ҽڵ����ӽڵ� 6.ֻ���ҽڵ㣬���ҽڵ����ӽڵ�
	//7.���ҽڵ㶼��Ϊ��
	//�൱�ڽ�Ҫɾ����Ŀ��ڵ��Ƶ�Ҷ�ӽڵ�λ�û�����ֻ��һ���ڵ�������������ɾ��
	//����1��2����Ҷ�ӽڵ㣬ֱ��ɾ��������3��5���ڵ�Ŀ��ڵ�ֻ�뵥���ڵ�������Ҳ��ֱ��ɾ��
	//����1 ���ӽڵ�ĸ��ڵ�
	if(targetPtr->pparent==NULL&&targetPtr->pleft==NULL&&targetPtr->pright==NULL){
		proot = NULL;							//����ڵ�ΪNULL�����ͷ�targetPtr
												//��ֱֹ���ͷ�targetPtr�ᵼ�¸��ڵ��ΪҰָ��
		delete targetPtr;						//�ͷ�targetPtr
		return true;							//����true��ʾɾ���ɹ�
	}
	//����2 ���ӽڵ��ҷǸ��ڵ�(Ҷ�ӽڵ�)
	else if (targetPtr->pparent != NULL && targetPtr->pleft == NULL && targetPtr->pright == NULL) {
		tnode* tP = targetPtr->pparent;			//ָ��tP����ɾ��Ŀ��ĸ��ڵ�
		if (tP->pright == targetPtr) {			//Ŀ��ڵ�ΪtP���ҽڵ�
			tP->pright = NULL;					//��tP���ҽڵ�Ϊ��
												//��ֹ�ͷ�ɾ��Ŀ���tP�ҽڵ��ΪҰָ��
			delete targetPtr;					//�ͷ�targetPtr
		}
		else {									//Ŀ��ڵ�ΪtP����ڵ�
			tP->pleft = NULL;					//��tP����ڵ�Ϊ��
												//��ֹ�ͷ�ɾ��Ŀ���tP��ڵ��ΪҰָ��
			delete targetPtr;					//�ͷ�targetPtr
		}
		return true;							//����true��ʾɾ���ɹ�
	}
	else if (targetPtr->pleft != NULL && targetPtr->pright == NULL) {
		//Ŀ��ڵ����ڵ�ǿգ��ҽڵ�Ϊ��
		tnode* tL = targetPtr->pleft;			//tL:Ŀ��ڵ���ڵ�
		tnode* tP = targetPtr->pparent;			//tP��Ŀ��ڵ㸸�ڵ�
		tnode* tLL = tL->pleft;					//tLL:tL��ڵ�
		tnode* tLR = tL->pright;				//tLR:tL�ҽڵ�
		if (tLL == NULL && tLR == NULL) {		//����3 
												//Ŀ��ڵ�ֻ����ڵ㣬����ڵ����ӽڵ�
			if (tP) {							//targetPtr��Ϊ���ڵ�
				tP->pleft = tL;					//��Ŀ��ڵ�ĸ��ڵ�ָ��Ŀ��ڵ���ڵ�
				tL->pparent = tP;				//��Ŀ��ڵ����ڵ�ָ��Ŀ��ڵ㸸�ڵ�
				delete targetPtr;				//�ͷ�targetPtr
				return true;					//����true��ʾɾ���ɹ�
			}	
			else {								//targetPtrΪ���ڵ�
				proot = tL;						//Ŀ��ڵ����ڵ��Ϊ���ڵ�
				tL->pparent = NULL;				//��ֹ���ڵ㸸�ڵ��ΪҰָ��
				delete targetPtr;				//�ͷ�targetPtr
				return true;					//����true��ʾɾ���ɹ�
			}
		}
		if (tLL != NULL || tLR != NULL) {		//����4 ֻ����ڵ㣬����ڵ����ӽڵ�
			tnode* tL_subtree_max = Delete_user_Aux2(1, tL);
												//Ѱ��targetPtr���������е����ֵ�ڵ�
												//��������ص�tL_subtree_max
			targetPtr->getUserdata() = tL_subtree_max->getUserdata();
			//���ҵ���tL_subtree_maxָ��ָ��Ľڵ��������ȡ��Ŀ��ڵ��������
			targetPtr = tL_subtree_max;			//��ɾ����Ŀ��ڵ�ת�Ƶ�tL_subtree_maxָ��Ľڵ�
			Delete_user_Aux0(targetPtr);		//�ݹ�ɾ��������Ŀ��ڵ�ת�Ƶ���ֱ��ɾ������ʱ������ɾ��
			return true;						//����true��ʾɾ���ɹ�
		}
	}
	else if (targetPtr->pleft == NULL && targetPtr->pright != NULL) {
		//Ŀ��ڵ���ҽڵ�ǿգ���ڵ�Ϊ�� 
		//����5��6����������3��4ͬ��ע����
		tnode* tR = targetPtr->pright;			//tR:Ŀ��ڵ��ҽڵ�
		tnode* tP = targetPtr->pparent;			//tP��Ŀ��ڵ㸸�ڵ�
		tnode* tRL = tR->pleft;					//tRL:tR��ڵ�
		tnode* tRR = tR->pright;				//tRR:tR�ҽڵ�
		if (tRL == NULL && tRR == NULL) {		//����5 ֻ���ҽڵ㣬���ҽڵ����ӽڵ�
			if (tP) {
				tP->pright = tR;
				tR->pparent = tP;
				delete targetPtr;
				return true;
			}
			else {
				proot = tR;
				proot->pparent = NULL;
				delete targetPtr;
				return true;
			}
		}
		if (tRL != NULL || tRR != NULL) {		//����6 ֻ���ҽڵ㣬���ҽڵ����ӽڵ�
												//Ѱ��targetPtr���������е���Сֵ�ڵ�
			tnode* tR_subtree_min = Delete_user_Aux2(0, tR);
			targetPtr->getUserdata() = tR_subtree_min->getUserdata();
			targetPtr = tR_subtree_min;
			Delete_user_Aux0(targetPtr);
			return true;
		}
	}
	else if (targetPtr->pleft != NULL && targetPtr->pright != NULL) {
												//����7 ���ҽڵ㶼��Ϊ��
		//Ĭ��Ϊ��Ŀ��ڵ����������С�ڵ��Ŀ��ڵ�����滻����Ŀ��ڵ�ת�Ƶ�����������С�ڵ�
		tnode* tR = targetPtr->pright;			//tR:Ŀ��ڵ���ҽڵ�
		tnode* tR_subtree_min = Delete_user_Aux2(0, tR);
		//�ҵ�Ŀ��ڵ�����������С�ڵ㣬��ָ�����ָ�뷵�ص�tR_subtree_min
		
		targetPtr->getUserdata() = tR_subtree_min->getUserdata();
												//�����滻
		targetPtr = tR_subtree_min;				//ת��Ŀ��ڵ�
		Delete_user_Aux0(targetPtr);			//�ݹ�ɾ��
		return true;							//����true��ʾɾ���ɹ�
	}
	return NULL;
}

//ע���û���ɾ���ڵ�
void user_AVL::Delete_user(string uname) {
	tnode* targetPtr = Delete_user_Aux1(uname, proot);
												//�ҵ�Ҫɾ���Ľڵ�targetPtr
	Delete_user_Aux0(targetPtr);				//ɾ��Ŀ��ڵ�
	Calculate_bf(proot);						//���¼���nbf
	inorder_bf(proot);							//����ƽ��
}


//����
void user_AVL::RotateL(tnode* subroot){
	tnode* subR = subroot->pright;				//subR:subroot�ҽڵ�
	tnode* subRL = subR->pleft;					//subRL:subR��ڵ�
	tnode* pp = subroot->pparent;				//pp:subroot���ڵ�
	subroot->pright = subRL;					//��subroot���ҽڵ�ΪsubRL
	if (subRL) {								//subroot�ǿ�
		subRL->pparent = subroot;				//��subRL�ĸ��ڵ�Ϊsubroot
	}
	subR->pleft = subroot;						//��subR����ڵ�Ϊsubroot
	subroot->pparent = subR;					//��subroot�ĸ��ڵ�ΪsubR
	if (subroot == proot) {						//��subroot�Ǹ��ڵ�
		proot = subR;							//���¸��ڵ�ΪsubR
		subR->pparent = NULL;					//������subroot�ĸ��ڵ�ΪNULL
	}
	else if(pp)									//pp�ǿգ���subroot��Ϊ���ڵ�
	{								
		if (pp->pleft ==subroot) {				//��subroot��pp����ڵ�
			pp->pleft = subR;					//�����subRΪpp����ڵ�
			subR->pparent = pp;					//��subR�ĸ��ڵ�Ϊpp
		}
		else {									//subroot��pp���ҽڵ�
			pp->pright = subR;					//����subRΪpp���ҽڵ�
			subR->pparent = pp;					//��subR�ĸ��ڵ�Ϊpp
		}
	}
}
//����	������Ϊ�ԳƲ�����ע����
void user_AVL::RotateR(tnode* subroot){
	tnode* subL = subroot->pleft;
	tnode* subLR = subL->pright;
	tnode* pp = subroot->pparent;
	subroot->pleft = subLR;
	if (subLR) {
		subLR->pparent = subroot;
	}
	subL->pright = subroot;
	subroot->pparent = subL;
	if (subroot == proot) {
		proot = subL;
		subL->pparent = NULL;
	}
	else {
		if (pp->pleft == subroot) {
			pp->pleft = subL;
			subL->pparent = pp;
		}
		else {
			pp->pright = subL;
			subL->pparent = pp;
		}
	}
	subL->nbf = 0;
}
//������
void user_AVL::RotateRL(tnode* subroot){
	tnode* subR = subroot->pright;				//subRΪsubroot���ҽڵ�
	this->RotateR(subR);						//��subRΪ����������������
	this->RotateL(subroot);						//��subrootΪ����������������
}
//������
void user_AVL::RotateLR(tnode* subroot){
	tnode* subL = subroot->pleft;				//subLΪsubroot����ڵ�
	this->RotateL(subL);						//��subLΪ����������������
	this->RotateR(subroot);						//��subrootΪ����������������
}

//�޸����븨���ݹ麯�� Ϊclass user_AVL����Ԫ���� �ҵ��û���ƥ����˺Ų��޸�����
bool Change_p_Aux(string uname, string unpass, tnode* subroot) {
	//����3���������û����������룬��ǰ�������ڵ�
	if (subroot == NULL)return false;			//�ݹ���ֹ������subrootΪ��
	if(Change_p_Aux(uname, unpass, subroot->pleft))return true;	
												//����subroot�������������ҵ�ƥ����˺�
												//������������޸ģ�������true
	if (subroot->getUserdata().getName() == uname) {
		//�ҵ���Ҫ�޸�������˺�
		subroot->ChangePassword(uname,unpass);	//�޸�����
		return true;							//����true���ɸ�֪��������������
	}
	if(Change_p_Aux(uname, unpass, subroot->pright))return true;
	return false;
}

//�ҵ��û������ڽڵ㣬���޸�����
bool user_AVL::Change_password(string uname,string unpass){
	if (Change_p_Aux(uname, unpass, proot))return true;
	//�����޸����븨���ݹ麯�����޸ĳɹ�����true
	else return false;
	//�޸�ʧ�ܷ���false
}

//�ж��û��Ƿ���� �������� Ϊclass user_AVL����Ԫ����
bool Check_e_Aux(string uname, tnode* subroot) {
	if (subroot == NULL) {						//�ݹ���ֹ������subrootΪ��
		return false;
	}
	if (Check_e_Aux(uname, subroot->pleft)) {	//�������������˺��Ƿ����
		return true;														
	}
	if (uname == subroot->getUserdata().getName()) {
		//��ǰ�����ڵ��������˺ŵ��û��������ƥ�䣬�ҵ����˺ţ�����true
		return true;							//����true���ɸ�֪��������������
	}
	if (Check_e_Aux(uname, subroot->pright)) {	//�������������˺��Ƿ����
		return true;
	}
	return false;								//����������������δ�ҵ����˺ţ�����false
}

//���AVL���Ƿ�����û���Ϊuname����ע���˺ţ������ڣ�����true
bool user_AVL::Check_exist(string uname) { 
	if (Check_e_Aux(uname, proot)) { return true; }
	//���ò����˺��Ƿ���ڵĸ������������ҵ�����true
	else  return false;
	//δ�ҵ�������false
}

//�ж������Ƿ�ƥ�丨������ Ϊclass user_AVL����Ԫ����
bool Check_m_Aux(string uname, string upass, tnode* subroot) {
	//�����������û��������룬���ҵ��û���ƥ����˺ţ�����֤�����Ƿ�ƥ��
	if (subroot == NULL)return false;			//�ݹ���ֹ������subrootΪ��
	if (Check_m_Aux(uname, upass, subroot->pleft))return true;
												//����subroot���������ҵ��˺Ž�������ƥ��
	if (uname == subroot->getUserdata().getName()) {
		//�ҵ����˺�
		if (upass == subroot->getUserdata().getPassword())return true;
		//��������ƥ�䣬ƥ��ɹ�����true���ɸ�֪�������ɹ������˳�
		else return false;
		//���벻ƥ�䣬����false
	}
	if (Check_m_Aux(uname, upass, subroot->pright))return true;
	return false;
}

//�ж�����������Ƿ����û�����ǰ������ͬ
bool user_AVL::Check_match(string uname, string upass) { 
	if (Check_m_Aux(uname, upass, proot)) {return true;}
	//��������ƥ�丨�������ж������Ƿ���ȷ
	else return false;
}
//��AVL���뵽�ļ������������ݹ�������뵽�ļ�
void write_AVL_Aux(tnode* subroot, ofstream& outAVL) {
	//���ݹؼ��������ļ���������������
	if (subroot == NULL)return;					//�ݹ���ֹ��������ǰ�����ڵ�subrootΪ��
	write_AVL_Aux(subroot->pleft,outAVL);		//����subroot���������뵽�ļ�
	outAVL << subroot->getUserdata().getName() << " " << subroot->getUserdata().getPassword() << endl;
	//�����ǰ�ڵ���û��������뵽�ļ�
	write_AVL_Aux(subroot->pright, outAVL);		//����subroot���������뵽�ļ�
}
//��AVL���뵽�ļ�
void user_AVL::write() {						
	ofstream outAVL("user.txt");				//�����ļ����������outAVL�������"user.txt"
	write_AVL_Aux(proot,outAVL);				//���ø����������뵽�ļ�
}
//����
bool user_AVL::Find_bfone_two() {
	if (Find_bfone_two_Aux(proot)) {
		Calculate_bf(proot);						//���㲢����ÿ���ڵ��nbf
		inorder_bf(proot);							//����ƽ��
		return true;
	}
	else return false;
}
bool user_AVL::Find_bfone_two_Aux(tnode* subroot) {
	if (subroot == NULL) {
		return false;
	}
	if (Find_bfone_two_Aux(subroot->pleft))return true;
	if (subroot->nbf == 1) {
		string name = "a";
		string password = "111";
		user u(name, password);
		insertAux(u, subroot->pleft, subroot);
		return true;
	}
	if (Find_bfone_two_Aux(subroot->pright))return true;
	return false;
}