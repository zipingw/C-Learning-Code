#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main() {
	stack<char>s;
	int input;
	string output="0123456789ABCDEF";
	while (cin >> input) {
		while (input) {
			int index = input % 16;			//除16取模
			input /= 16;					//整除16
			s.push(output[index]);			//添加元素到栈中
		}
		while (!s.empty()) {				//栈非空
			cout << s.top() ;				//输出
			s.pop();						//删除栈顶
		}
		cout << endl;
	}
	return 0;
}