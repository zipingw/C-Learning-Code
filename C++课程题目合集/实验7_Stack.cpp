#include<iostream>
#include<string>
using namespace std;
//-------------------------------
template <typename T,unsigned SIZE>
class Stack{
public:
    Stack():tos(0){}
    bool empty()const{return tos==0;}
    void push(const T&);
    void pop();
    T& top();
    const T& top() const;
private:
    T s[SIZE];
    int tos;
};
template <typename T,unsigned SIZE>
void Stack<T,SIZE>::push(const T&a){
	s[tos++]=a;
}
template <typename T,unsigned SIZE>
void Stack<T,SIZE>::pop(){
	tos--;
}
template <typename T,unsigned SIZE>
T& Stack<T,SIZE>::top(){
	return s[tos-1];
}
template <typename T,unsigned SIZE>
const T& Stack<T,SIZE>::top()const{
    return s[tos-1]; 
}
int main(){
	Stack<int,100> S1;
	S1.push(3);
	cout<<S1.top()<<endl;
	S1.push(4);
	cout<<S1.top()<<endl;
	S1.pop();
	cout<<S1.top()<<endl;
	S1.pop();
	if(S1.empty())cout<<"S1 is empty."<<endl; 
	else cout<<"S1 is not empty."<<endl;
	Stack<double,200> S2;
	S2.push(3.5);
	cout<<S2.top()<<endl;
	S2.push(4.6);
	cout<<S2.top()<<endl;
	S2.pop();
	cout<<S2.top()<<endl;
	if(S2.empty())cout<<"S2 is empty."<<endl; 
	else cout<<"S2 is not empty."<<endl;	
}
