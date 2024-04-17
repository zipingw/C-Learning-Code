#include<iostream>
using namespace std;
int a[400001];
long isA(long n) {
	int a=0,b=0;
	    for(long r=n;r!=0;r>>=1){
			(r&1)==1?a++:b++;
		}
		if(a>b)return 1;
		else return 0;
}
int main(){
	long  n; 
	for(long i=1;i<=400000;i++){
		a[i]=a[i-1]+isA(i);
	}
	while(cin>>n){
		if(n==0)return 0;
		else cout<<a[n]<<endl;
    }
	return 0;
} 

	
