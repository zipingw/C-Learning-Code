#include<iostream>
using namespace std;
int f(int n,int m){
	if(n==1) return 0;
	else return (f(n-1,m)+m)%n; 
}
int main (){
	int m,n;
	while(cin>>n>>m)
	cout<<f(n,m)+1;
	return 0;
}
