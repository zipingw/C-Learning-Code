#include<iostream>
using namespace std;
//--------------------
class One{
    int a, b;
public:
    One(int a1,int b1): a(a1),b(b1){}
       friend class Two;      //��Ԫ������
};//------------------
class Two{
    int x,y,z;
public:
    Two(int x1=6, int y1=6, int z1=6):x(x1),y(y1),z(z1){}
   bool isSame(const One& A);
};//------------------
bool Two::isSame(const One& A){ //��Two��isSame���������ⶨ�壬
    return          (x==A.a&&y==A.b)         ;
// ǰ������Ա�ֱ���ȣ�����true,���򷵻�false.
}//-------------------
int main(){
    int i,j;
    cin>>i>>j;
    One  one1(i,j);
    cin>>i>>j;
    Two two1(i,j,1);
    if(   two1.isSame(one1)  )cout << "Yes" << endl;
//����TWO��ĳ�Ա����isSame�ж�one1,two1�Ƿ���ȡ�
    else cout << "No" << endl;
}//-------------------

