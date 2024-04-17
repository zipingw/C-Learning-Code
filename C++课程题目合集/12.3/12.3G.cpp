#include<iostream>
using namespace std;
int main(){
	int transfer(int x);
	bool judgeA(int );
	int n;
	while(cin>>n){
		if(n==0)return 0;
		int s=0;
		for(int i=1;i<n+1;i++){
			if(judgeA(transfer(i))==1)s++;
		}
		cout<<s<<endl;
	}
	return 0;
} 
int transfer(int x){    
int p=1,y=0,yushu;    
while(1)    {        
yushu=x%2;        
x/=2;        
y+=yushu*p;        
p*=10;        
if(x<2)        
{      y+=x*p; break;        }    }    
return y;
}
bool judgeA(int b){
	int m=0,n=0;
	for(;b!=0;){
		b%10==0?m++ :n++;
		b/=10;
	}
	if(n>m) return 1;
	else return 0;
}
