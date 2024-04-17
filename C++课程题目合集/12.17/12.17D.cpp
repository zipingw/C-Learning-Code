#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		if(n>0&&n<10){
			for(int i=1;i<=n;i++)cout<<i;
			cout<<endl;
		}
	     if(n>9&&n<100){
	     	int a=n/10;int b=n%10;
	     	for(int j=0;j<a;j++){
	     		cout<<"S";
			 }
			 for(int i=1;i<=b;i++){
			 cout<<i;
			 } 
			 cout<<endl;
		 }
		 if(n>99&&n<1000){
		 	int s=n/100;
		 	int m=n%100/10;
		 	int k=n%10;
		 	for(int i=0;i<s;i++){
		 		cout<<"B";
			 }
			for(int j=0;j<m;j++){
				cout<<"S";
			}
			for(int p=1;p<=k;p++){
			cout<<p;
		    }
		    cout<<endl;
		 }
	}
	return 0;
} 
