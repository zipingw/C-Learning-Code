#include<iostream>
using namespace std;
//--------------------
class Num{
    int v;
public:
    Num():v(0){}
    Num& operator++(){ v==3 ? v=0 : v++; return *this; }
    Num& operator--(){ v==0 ? v=3 : v--; return *this; }
    int operator()(){ return v; }
};//-----------------
int main(){
    Num my;
    for(int i=0; i<5; i++){
        ++my;
        cout<<"="<<my();
    }
    --(--my);
    cout<<"\n="<<my()<<endl;
}//-------------
