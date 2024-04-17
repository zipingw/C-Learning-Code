#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;
int transfer(int x){    
int  a[32],pos=0,y=0;
unsigned b=x; 
while(b){
	a[pos++]=b&1;
	b>>=1;
}  
for(int i=pos-1;i>=0;--i)
y=y*10+a[i];
return y;
}
int main(){
	int s;
	int n;
	while(cin>>n){
		s=transfer(n);
        cout<<setw(11)<<setiosflags(ios::right)<<n<<"-->"<<(n>0?s:-s)<<endl;
	 }
	return 0;
} 


