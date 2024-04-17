#include<iostream>
using namespace std;
//----------------------------------
class Counter{
    int v;
public:
    Counter(){ v=0; }
    Counter& preAddOne(); //����preAddOne������
    Counter  postAddOne(); ////����postAddOne������
    void print(){ cout<<v<<"\n"; }
};//--------------------------------
Counter& Counter::preAddOne(){  // preAddOne�ĺ���ͷ
    v++;
    return *this;
}//---------------------------------
Counter Counter::postAddOne(){ // // postAddOne�ĺ���ͷ
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
 
