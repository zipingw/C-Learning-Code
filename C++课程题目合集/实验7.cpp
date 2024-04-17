#include<iostream>
using namespace std;
//--------------------
template<class T>
void exchange(T& a, T& b){
  T t = a;
  a = b;
  b = t;
}//-------------------
 
int main(){
  int x=3,y=5;
  exchange(x, y);
  cout<<x<<" "<<y<<"\n";
  double d=3.5, e=6.2;
  exchange(d, e);
  cout<<d<<" "<<e<<"\n";
}//-------------------

