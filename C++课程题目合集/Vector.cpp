#include<iostream>
#include<stdlib.h>
using namespace std;
class Vector{
	int *buf;
	int size;
	int cap;
 public: 
    Vector(){size=0;cap=4;buf=new int [4];}
	Vector(int ,int );
	Vector(const Vector & );
	~Vector();
	void insert(int ,int );
	void erase(int  );
	void push_back(int );
	void push_front(int );
	void pop_back();
	void pop_front();
	void clear();
	void sz();
	void capacity();
    void print();  
    void printS(int );
    void printend();
};
Vector::Vector(int sz,int x){
	size=sz;
	cap=sz;
    buf=new int[cap];
    for(int i=0;i<size;i++){
    	buf[i]=x;
	}
}
Vector::Vector(const Vector& c)
{
    cap=size=c.size;buf=new int[size];
    memcpy(buf,c.buf,size*sizeof(int)); 
} 
Vector::~Vector(){
	delete []buf;
}
void Vector::insert(int m,int n){
	size+=1;
	for(int i=size-1;i>=m;i--){
		buf[i]=buf[i-1];
	}
	buf[m-1]=n;
}
void Vector::erase(int m){
	for(int i=m;i<size;i++){
		buf[i-1]=buf[i];
	}
	size-=1;
}
void Vector::push_back(int x){
	size+=1;
	if(size>cap){
	 cap*=2;
	 int *q;
     q=(int *) realloc(buf,sizeof(int)*cap);
     if(!q) buf=q;
	}
	buf[size-1]=x;
	cout<<size<<" "<<cap<<endl;
}
void Vector::push_front(int x){
	size+=1;
	if(size>cap){
	 cap*=2;
	 int *s;
     s=(int *) realloc(buf,sizeof(int)*cap);
     if(!s) buf=s;
	}
	for(int i=size-1;i>0;i--){
		buf[i]=buf[i-1];
	}
	buf[0]=x;
}
void Vector::pop_back(){
	size-=1;
}
void Vector::pop_front(){
	for(int i=0;i<size-1;i++){
		buf[i]=buf[i+1];
	}
	size-=1;
}
void Vector::sz(){
	cout<<size<<endl;
}
void Vector::capacity(){
	cout<<cap<<endl;
}
void Vector::print(){
	for(int i=0;i<size;i++){
		cout<<buf[i]<<" ";
	}
	cout<<endl;
}
void Vector::printS(int x){
	cout<<buf[x-1]<<endl;
}
void Vector::printend(){
	cout<<buf[size-1]<<endl;
}
int main(){
	Vector a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.print();  
    a.printS(1);
    a.printend();
    a.pop_back();
    a.pop_front();
	a.erase(2);
    a.print();
    a.push_back(5);
    a.push_front(1);
    a.insert(3,3);
    a.print();
	Vector c(a);//定义vector c 
    c.pop_back(); 
    c.print();
	a.push_back(6); 
    a.print();
    Vector b(5,7);//定义 vector b 
    b.print();
    b.sz();
    b.capacity();
    b.push_back(1);
    b.print();
    b.push_back(2);
    b.print();
    b.push_back(3);
    b.print();
    b.push_back(4);
    b.print();
    b.push_back(5);
    b.print();
    b.push_back(6);
    b.print();
    return 0;
}
