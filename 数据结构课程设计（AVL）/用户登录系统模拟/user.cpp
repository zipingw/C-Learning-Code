#include"user.h"
user::user():name (""),password(""){}		//�޲�Ĭ�Ϲ��캯��������ΪNULL
user::user(string Name, string Password) {	//���أ������û���������
	name = Name;
	password = Password;
}
user::~user() {}							//��������
string user::getName() {				
	return this->name;						//�����û���
}
string user::getPassword() {
	return this->password;					//��������
}
void user::ChangePass(string unpass) {		//�޸�����
	password = unpass;
}