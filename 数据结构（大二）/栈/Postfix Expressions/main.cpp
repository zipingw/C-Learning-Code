#include<iostream>
#include<stack>
#include<string>
using namespace std;
int compute_exp(string);													//��������
int main() {
	string exp;																//exp�洢��׺���ʽ
	getline(cin,exp);														//���exp
	cout<<compute_exp(exp);													//����compute_exp()������
	return 0;
}
int compute_exp(string exp) {
	int len = exp.length();													//len�洢exp����
	int sum = 0;															//sum�洢��ʱ����ֵ
	stack<int> s;															//����stackģ�� ջԪ��int���� 
	for (int i = 0; i < len; i++) {											//������׺���ʽ�ַ��� ѭ�������׺���ʽ
		if (exp[i] == ' ') { continue; }									//��ǰ�ַ�Ϊ " "����������ѭ��
		else if (exp[i] > '0' && exp[i] < '10') { s.push(exp[i] - '0'); }	//��ǰ�ַ�Ϊ0-10����ַ�,��Ԫ����ջ
		else {																//��ǰ�ַ�Ϊ�����������
			if (exp[i] == '+') {											//��ǰ�ַ�Ϊ"+"
				int x = s.top();											//��ȡջ���Ϸ�����Ԫ�أ���������ֵ����sum
				s.pop();													//ɾ��ջ��Ԫ��
				int y = s.top();											
				s.pop();													
				sum = x + y;												
				s.push(sum);												//sum����ջ��
			}
			else if (exp[i] == '-') {										//ͬ��
				int x = s.top();
				s.pop();
				int y = s.top();
				s.pop();
				sum = x - y;
				s.push(sum);
			}
			else if (exp[i] == '*') {										//ͬ��
				int x = s.top();
				s.pop();
				int y = s.top();
				s.pop();
				sum = x * y;
				s.push(sum);
			}
			else if (exp[i] == '/') {										//ͬ��
				int x = s.top();
				s.pop();
				int y = s.top();
				s.pop();
				sum = x / y;
				s.push(sum);
			}
		}
	}
	return sum;																//���sum
}