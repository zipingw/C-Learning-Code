#include"user.h"
user::user():name (""),password(""){}		//无参默认构造函数，参数为NULL
user::user(string Name, string Password) {	//重载，给定用户名与密码
	name = Name;
	password = Password;
}
user::~user() {}							//析构函数
string user::getName() {				
	return this->name;						//返回用户名
}
string user::getPassword() {
	return this->password;					//返回密码
}
void user::ChangePass(string unpass) {		//修改密码
	password = unpass;
}