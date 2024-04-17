#include<iostream>
using namespace std;
int a[400001];
bool isA(int n) {
	int a=0,b=0;
	    for(int r=n;r!=0;r>>=1){
			(r&1)==1?a++:b++;
		}
		return a>b;
}
int main(){
	int  n; 
	for(int i=1;i<=400000;i++){
		a[i]=a[i-1]+isA(i);
	}
	while(cin>>n){
		if(n==0)return 0;
		else cout<<a[n]<<endl;
    }
	return 0;
} 
