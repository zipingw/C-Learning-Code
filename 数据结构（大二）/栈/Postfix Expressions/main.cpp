#include<iostream>
#include<stack>
#include<string>
using namespace std;
int compute_exp(string);													//函数声明
int main() {
	string exp;																//exp存储后缀表达式
	getline(cin,exp);														//输出exp
	cout<<compute_exp(exp);													//调用compute_exp()输出结果
	return 0;
}
int compute_exp(string exp) {
	int len = exp.length();													//len存储exp长度
	int sum = 0;															//sum存储临时计算值
	stack<int> s;															//运用stack模板 栈元素int类型 
	for (int i = 0; i < len; i++) {											//遍历后缀表达式字符串 循环计算后缀表达式
		if (exp[i] == ' ') { continue; }									//当前字符为 " "，跳过本次循环
		else if (exp[i] > '0' && exp[i] < '10') { s.push(exp[i] - '0'); }	//当前字符为0-10间的字符,该元素入栈
		else {																//当前字符为四则运算表达符
			if (exp[i] == '+') {											//当前字符为"+"
				int x = s.top();											//提取栈最上方两个元素，并将所得值存入sum
				s.pop();													//删除栈顶元素
				int y = s.top();											
				s.pop();													
				sum = x + y;												
				s.push(sum);												//sum存入栈顶
			}
			else if (exp[i] == '-') {										//同上
				int x = s.top();
				s.pop();
				int y = s.top();
				s.pop();
				sum = x - y;
				s.push(sum);
			}
			else if (exp[i] == '*') {										//同上
				int x = s.top();
				s.pop();
				int y = s.top();
				s.pop();
				sum = x * y;
				s.push(sum);
			}
			else if (exp[i] == '/') {										//同上
				int x = s.top();
				s.pop();
				int y = s.top();
				s.pop();
				sum = x / y;
				s.push(sum);
			}
		}
	}
	return sum;																//输出sum
}