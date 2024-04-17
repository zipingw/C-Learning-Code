#include <iostream>
using namespace std;
//----------------------------------
class Class{
    int x,y;
public:
    Class(int n=6, int m=7);
    ~Class();
    void Set(int n, int m){ x=n; y=m; }
};//--------------------------------
Class::Class(int n, int m){
    Set(n,m);
    cout<<"Construct: x="<<x<<",y="<<y<<"\n";
}//---------------------------------
Class::~Class(){
    cout<<"Destruct: x="<<x<<",y="<<y<<"\n";
}//---------------------------------
int main(){Class a(5);
    Class b=Class(1,3);
    cout <<"exiting...\n";
}//--注意：撤销对象会执行析构函数

