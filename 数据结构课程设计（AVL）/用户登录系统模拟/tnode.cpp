#include"tnode.h"
using namespace std;
tnode::tnode() {				//Ĭ�Ϲ��캯������Ա�������ó�ʼֵ
	pleft = NULL;			
	pright = NULL;
	pparent = NULL;
	iuserdata = user();
	nbf = 0;
}
tnode::~tnode() {}				//Ĭ����������
tnode::tnode(user User) {		//���캯�����أ�����Ϊ������user
	pleft = NULL;
	pright = NULL;
	pparent = NULL;
	iuserdata = User;			//��������봫��Ĳ���
	nbf = 0;
}
tnode::tnode(string Name, string Password) {	//���캯�����أ�����Ϊ�û�������
	pleft = NULL;
	pright = NULL;
	pparent = NULL;
	iuserdata = user(Name, Password);			//�ò�������һ��user���͵Ķ��󣬷���������
	nbf = 0;
}
user tnode::getUserdata() {						//�ⲿ�����ȡ˽�������˺���Ϣ
	return this->iuserdata;
}

void tnode::ChangePassword(string uname,string unpass) {	//�޸�����
	user unew(uname, unpass);					//������Ĳ�������һ��user���͵Ķ���
	iuserdata = unew;							//���¶����滻ԭ������
}