     #include<iostream>
#include<cstring>
using namespace std;
//-------------------------------------
int main(){
int sz=5;
    int *p = new int[sz];  //Dynamic distribution
    memset(p,0,sz*sizeof(int));  //initialize
    p[0] = 6;  p[sz-1] = 7;
    for(int i=0; i<sz-1; ++i)cout << p[i] << " ";
    cout << p[sz-1] << endl;
    
    int *p2 = new int[sz += 2];
    memcpy(p2+2, p, (sz-2)*sizeof(int));
    delete[] p;
    p = p2;
    p[0]=1; p[1]=2;
    for(int i=0; i<sz-1; ++i)cout << p[i] << " ";
    cout << p[sz-1] << endl;
}//====================================

