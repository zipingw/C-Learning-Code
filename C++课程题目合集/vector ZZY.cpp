#include<iostream>
using namespace std;
class Vector{
	int *buf;
	int size;
	int cap;
 public: 
    Vector(){size=0;cap=4;buf=new int [cap];}
	Vector(const int ,const int );
	Vector(const Vector & );
	~Vector(){};
	void insert(const int ,const int );
	void erase(const int  );
	void push_back(const int );
	void push_front(const int );
	void pop_back();
	void pop_front();
	void clear();
    void print();  
    void printS(const int );
    void printend();
};
Vector::Vector( int sz,const int capa){
	size=sz;
	cap=capa;
    buf=new int[cap];
}
Vector::Vector(const Vector& c)
{
    cap=size=c.size;buf=new int[size];
    memcpy(buf,c.buf,size*sizeof(int)); 
} 
void Vector::insert(const int m,const int n){
	size+=1;
	for(int i=size-1;i>m;i--){
		buf[i]=buf[i-1];
	}
	buf[m]=n;
}
void Vector::erase(const int m){
	for(int i=m;i<size-1;i++){
		buf[i]=buf[i+1];
	}
	size-=1;
}
void Vector::push_back(const int x){
	size+=1;
	if(size>cap){
		cap*=2;
	
	}
	buf[size-1]=x;
	cout<<size<<" "<<cap<<endl;
}
void Vector::push_front(const int x){
	size+=1;
	if(size>cap){
		cap*=2;
	buf=new int [cap];
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
void Vector::print(){
	for(int i=0;i<size;i++){
		cout<<buf[i]<<" ";
	}
}
void Vector::printS(const int x){
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
}
