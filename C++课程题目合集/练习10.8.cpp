#include<iostream>
using namespace std;
//----------------------------------
class Counter{
    int v;
public:
    Counter(){ v=0; }
    Counter& preAddOne(); //函数preAddOne的声明
    Counter  postAddOne(); ////函数postAddOne的声明
    void print(){ cout<<v<<"\n"; }
};//--------------------------------
Counter& Counter::preAddOne(){  // preAddOne的函数头
    v++;
    return *this;
}//---------------------------------
Counter Counter::postAddOne(){ // // postAddOne的函数头
    Counter temp;
    temp.v = v++;
    return temp;
}//---------------------------------
int main(){
    Counter c;
    for(int i=0; i<8; i++)
        c.postAddOne().postAddOne();
    c.print();
    for(int j=0; j<8; j++)
        c.preAddOne().preAddOne();
    c.print();
}//---------------------------------
 
