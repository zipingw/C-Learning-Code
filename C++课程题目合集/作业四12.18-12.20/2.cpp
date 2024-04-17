#include<iostream>
using namespace std;
int bigger(int *a,int n){
	double sum=0;
	for(int i=0;i<n;i++){
	    sum+=a[i];
	}
	double ave=sum/n;
	int s=0;
	for(int j=0;j<n;j++){
		if(a[j]>ave)s++;
	}
	return s;
}
int main(){
	int n;cin>>n;
	int *a=new int [n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int result=bigger(a,n);
	cout<<result<<endl;
}
