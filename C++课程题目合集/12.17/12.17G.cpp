#include<iostream>
#include<algorithm>
using namespace std;
int  inverted(int n){
	int s=0;
	while(n!=0){
		s=s*10+n%10;
		n/=10;
	}
    return s;	
}
bool cmp(const int &a,const int &b){
	return inverted(a)<inverted(b);
}
int main(){
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		int *a=new int [n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
	    sort(a,a+n,cmp);
	    for(int i=0;i<n;i++){
	    	cout<<a[i]<<((i==n-1)?"":" ");
	    	}cout<<endl;
	}
	return 0; 
}

