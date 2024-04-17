#include<iostream>
using namespace std;
int insertNum(int *p,int n,int x){
	int b=0,e=n-1;
	int s=(b+e)/2;
	for( ;e>=b;){
		if(p[s]<x){
			e=s-1;
		}
		else if(p[s]>x){
			b=s+1;
		}
		else{
			s+=1;break;
		}
	}
	if(b<e){for(int i=n+1;i>e+1;i--)p[i]=p[i-1];
	p[e+1]=x;
	}
	else{
		for(int i=n+1;i>s+1;i--)p[i]=p[i-1];
		p[s+1]=x;
	}
	return (n+1);
}
int main(){
	int n,x;
	cin>>n;
	int *p=new int [n+1];
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	cin>>x;
	int m=insertNum(p,n,x);
	for(int j=0;j<insertNum(p,n,x);j++){
		cout<<p[j]<<" ";
	}
}
