#include<iostream>
#include<stack>
using namespace std;
void enqueue(stack<int>&s1, stack<int>&s2) {
	cout << "请输入一个要加入队列的整数" << endl;
	int input;
	cin >> input;
	s1.push(input);
}
void dequeue(stack<int>&s1, stack<int>&s2) {
	if (!s2.empty()) {
		s2.pop();
	}
	else {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		s2.pop();
	}
}
int  front(stack<int>s1, stack<int>s2) {
	if (!s2.empty()) {
		return s2.top();
	}
	else {
		int num = 0;
		while (!s1.empty()) {
			num = s1.top();
			s1.pop();
		}
		return num;
	}
}
int test_max(stack<int> s1, stack<int> s2) {
	int max=0;
	while (!s2.empty()) {
		int b = 0;
		int c = s2.top();
		while (c) {
			b++;
			c /= 10;
		}
		max = b;
		s2.pop();
	}
	while (!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
	}
	while (!s2.empty()) {
		int b = 0;
		int c = s2.top();
		while (c) {
			b++;
			c /= 10;
		}
		max = b;
		s2.pop();
	}
	return max;
}
int test_number(stack<int> s1, stack<int> s2) {
	int num = 0;
	while (!s2.empty()) {
		num++;
		s2.pop();
	}
	while (!s1.empty()) {
		num++;
		s1.pop();
	}
	return num;
}
void sort(stack<int>  s1, stack<int>  s2) {
	int x = test_number(s1, s2);
	int max = test_max(s1, s2);
	int *q=new int [x];
	for (int i = 0; i < x; i++) {
		if (!s2.empty()) {
			q[i] = s2.top();
			s2.pop();
		}
		else {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
			q[i] = s2.top();
			s2.pop();
		}
	}
	int* q1 = new int[x];
	int* q2 = new int[x];
	for (int i = 0; i < x; i++) {
		q1[i] = q[i]%10;
	}
	for (int i = 0; i < x; i++) {
		q2[i] = q[i] / 10;
	}
	for (int i = 0; i < x - 1; i++) {
		for (int j = i + 1; j < x; j++) {
			if (q1[i] < q1[j]) {
				swap(q[i], q[j]);
				swap(q2[i], q2[j]);
				swap(q1[i], q1[j]);
			}
		}
	}
	for (int i = 0; i < x - 1; i++) {
		for (int j = i + 1; j < x; j++) {
			if (q2[i] < q2[j]) {
				swap(q[i], q[j]);
				swap(q2[i], q2[j]);
				swap(q1[i], q1[j]);
			}
		}
	}
	for (int i = 0; i < x; i++) {
		cout << q[i] << " ";
	}
	cout << endl;

}
void traverse_output(stack<int> s1, stack<int> s2) {
	while (!s2.empty()) {
		cout << s2.top() << " ";
		s2.pop();
	}
	while (!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
	}
	while (!s2.empty()) {
		cout << s2.top() << " ";
		s2.pop();
	}
	cout << endl;
}
int main() {
	stack <int> s1;
	stack <int> s2;
	enqueue(s1, s2);
	enqueue(s1, s2);
	enqueue(s1, s2);
	enqueue(s1, s2);
	enqueue(s1, s2);
	enqueue(s1, s2);
	enqueue(s1, s2);
	enqueue(s1, s2);
	cout << front(s1, s2) << endl;
	traverse_output(s1, s2);
	dequeue(s1, s2);
	cout << front(s1, s2) << endl;
	traverse_output(s1, s2);
	sort(s1, s2);
}