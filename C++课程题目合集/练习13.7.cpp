#include<iostream>
using namespace std;
//------------------------------
class Base{
protected:
    int x,y;
public:
    Base(int i=0, int j=0):x(i),y(j){}
    void print()const{ cout<<x<<" "<<y<<'\n'; }
}; //----------------------------
class Derived : public Base{
    int z;
public:
    Derived(int i=0, int j=0, int k=0):Base(i,j),z(k){}
    void print()const{
        Base::print();
        cout<<x+z<<" "<<y+z<<'\n';
    }
}; //----------------------------
int main(){
    Base d1;
    d1.print();
    Derived d2(10,20,30);
    d2.print();
}
