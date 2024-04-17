#include<iostream>
using namespace std;
//--------------------
class One{
    int a, b;
public:
    One(int a1,int b1): a(a1),b(b1){}
       friend class Two;      //友元类声明
};//------------------
class Two{
    int x,y,z;
public:
    Two(int x1=6, int y1=6, int z1=6):x(x1),y(y1),z(z1){}
   bool isSame(const One& A);
};//------------------
bool Two::isSame(const One& A){ //类Two的isSame函数的类外定义，
    return          (x==A.a&&y==A.b)         ;
// 前两个成员分别相等，返回true,否则返回false.
}//-------------------
int main(){
    int i,j;
    cin>>i>>j;
    One  one1(i,j);
    cin>>i>>j;
    Two two1(i,j,1);
    if(   two1.isSame(one1)  )cout << "Yes" << endl;
//调用TWO类的成员函数isSame判断one1,two1是否相等。
    else cout << "No" << endl;
}//-------------------

