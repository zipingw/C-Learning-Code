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
			int index = input % 16;			//��16ȡģ
			input /= 16;					//����16
			s.push(output[index]);			//���Ԫ�ص�ջ��
		}
		while (!s.empty()) {				//ջ�ǿ�
			cout << s.top() ;				//���
			s.pop();						//ɾ��ջ��
		}
		cout << endl;
	}
	return 0;
}