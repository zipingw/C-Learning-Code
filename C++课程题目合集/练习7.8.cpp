#include<iostream>
using namespace std;
//----------------------------------
class A{
    int m;
public:
    A(int i=0):m(i){ cout<<"Construct: "<<m<<"\n"; }
    A(const A& obj){m=obj.m+2; cout<<"Copy Construct: "<<m<<"\n";}
    void Print(){ cout<<m<<"\n"; }
    ~A(){ cout<<"Destruct: "<<m<<"\n"; }
};//--------------------------------
void fun(A c){ c.Print(); }   
//----------------------------------
int main(){
    A Aobj(5);
    fun(Aobj); 
} 
 
