#include<iostream>
using namespace std;
int count(int k,int s){
	int t=0;
	while(k!=0){
	if(k%10==s)	t++;
	k/=10;
	}
	return t;
}
int main(){
	unsigned a;
	int n;
	while(cin>>a>>n){
		cout<<count(a,n)<<endl;
	}
	return 0;
} 
