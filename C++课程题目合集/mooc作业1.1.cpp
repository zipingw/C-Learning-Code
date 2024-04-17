#include<iostream>
using namespace std;
int  main(){
	int n,a[110];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];	
	}
	int x,count=0;
	cin>>x;
	for(int i=0;i<n;i++){
		if(x==a[i])
	    count++;
	}
	cout<<count<<endl;
	return 0;
} 
