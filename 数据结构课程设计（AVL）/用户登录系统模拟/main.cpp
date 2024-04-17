#include"user_AVL.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main() {
	string uname, upassword, newpassword;			//用于输入的变量
	user_AVL uAVL;									//创建一棵AVL树
	ifstream inuser("user.txt");					//从文件"user.txt"读入数据
	while (inuser >> uname >> upassword) {			//文件读入不为空
		user u(uname, upassword);					//每读入一个账号信息，构造一个user类型对象
		uAVL.Insert(u);								//插入到uAVL树中
		//uAVL.printtree();
		//cout << endl;
	}
	//uAVL.printtree();				
	/*if (uAVL.Find_bfone_two()) {
		uAVL.printtree();
	}*/
	int iloope = 0, iloopi = 0, conf = 0;			//iloope控制外层大循环，iloopi控制登录成功后的小循环
													//conf用于注销账号时输入确认信息
	while (iloope != -1) {
		cout << "---------------------------------------------\n";
		cout << "|      服务器系统				              \n";
		cout << "|      1. 登录服务器				          \n";
		cout << "|      2. 注册服务器账号                     \n";
		cout << "---------------------------------------------\n";
		cout << "请选择（1/2，-1为退出系统):" << endl;
		cin >> iloope;								
		system("cls");								//输入后清屏
		switch (iloope)
		{
		case 1:
		{
			bool f1 = false, f2 = false;			//f1记录账号是否存在的；f2记录账号密码是否输入正确
			cout << "请输入服务器账号的 用户名 及 密码：" << endl;
			cin >> uname >> upassword;
			//调用uAVL查找相应用户名节点 ，1.判定是否存在账号 返回f1  
			f1 = uAVL.Check_exist(uname);
			if (f1) {
				//2.判断密码是否匹配 返回f2
				f2 = uAVL.Check_match(uname, upassword);
				if (f2) {							//密码匹配，登录成功
					cout << "-----登录成功！！-----" << endl;
					system("pause");				//停留在当前界面
					system("cls");					///用户确认后清屏
					iloopi = 0;						
					//显示登录后的可用功能
					while (iloopi != -1) {
						cout << "1.更新当前账号密码" << endl;
						cout << "2.注销当前账号" << endl;
						cout << "请选择（1/2,输入-1退出登录）：" << endl;
						cin >> iloopi;
						system("cls");				//用户输入后清屏
						switch (iloopi) {
						case 1:
							cout << "请输入新密码：" << endl;
							cin >> newpassword;		//用户输入新密码
							if (uAVL.Change_password(uname, newpassword)) {
								//调用修改密码函数，若修改成功，函数返回true
								cout << "密码修改成功！" << endl;
								system("pause");	//停留在当前界面等待用户确认
							}
							else {
								cout << "密码修改失败!" << endl;
								system("pause");	//停留在当前界面等待用户确认
							}
							system("cls");			//清屏
							break;
						case 2:
							cout << "是否确认注销当前账号？" << endl;
							cout << "当前账号用户名为：" << uname << endl;
							cout << "输入1确认注销，输入0取消注销" << endl;
							cin >> conf;
							if (conf == 1) {
								//调用删除当前user所在节点的函数
								uAVL.Delete_user(uname);
								iloopi = -1;		//账号已注销，则直接退出当前小循环
								cout << "当前账号已注销！" << endl;
								system("pause");	//停留在当前界面等待用户确认
							}
							else if (conf == 0) {	//取消注销
								break;
							}
							break;
						}
					}
				}
				else {								//密码匹配失败
					cout << "密码错误！" << endl;
					system("pause");				//停留在当前界面等待用户确认
				}
			}
			else {									//查找账号返回值为false
				cout << "输入的账号不存在！" << endl;
				system("pause");					//停留在当前界面等待用户确认
			}
			system("cls");							//清屏
			break;
		}
		case 2:										//注册账号
		{
			cout << "请输入要注册的账号的用户名和密码：" << endl;
			cin >> uname >> upassword;
			user u(uname, upassword);
			uAVL.Insert(u);							//调用插入函数插入新账号
			cout << "账号已成功注册！" << endl;
			system("pause");						//停留在当前界面等待用户确认
			system("cls");							//清屏
			break;
		}
		case -1:									//退出登录
		{
			iloope = -1; break;
		}
		default:
			break;
		}
	}
	uAVL.write();									//用户选择退出系统，将当前AVL树读入到文件，保存数据
	return 0;
}