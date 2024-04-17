#include<iostream>
using namespace std;
int main(){
	int n,a[110],x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int count;
    for(;cin>>x ; ){
    	count=0;
    	for(int i=0;i<n;i++){
    		if(a[i]==x)count++;
    		}
    		cout<<count<<endl;
	}
	return 0;
} 
