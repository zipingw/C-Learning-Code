#include"tnode.h"
using namespace std;
tnode::tnode() {				//默认构造函数，成员变量设置初始值
	pleft = NULL;			
	pright = NULL;
	pparent = NULL;
	iuserdata = user();
	nbf = 0;
}
tnode::~tnode() {}				//默认析构函数
tnode::tnode(user User) {		//构造函数重载，参数为数据域user
	pleft = NULL;
	pright = NULL;
	pparent = NULL;
	iuserdata = User;			//数据域放入传入的参数
	nbf = 0;
}
tnode::tnode(string Name, string Password) {	//构造函数重载：参数为用户名密码
	pleft = NULL;
	pright = NULL;
	pparent = NULL;
	iuserdata = user(Name, Password);			//用参数构造一个user类型的对象，放入数据域
	nbf = 0;
}
user tnode::getUserdata() {						//外部对象获取私有数据账号信息
	return this->iuserdata;
}

void tnode::ChangePassword(string uname,string unpass) {	//修改密码
	user unew(uname, unpass);					//将传入的参数构造一个user类型的对象
	iuserdata = unew;							//将新对象替换原数据域
}