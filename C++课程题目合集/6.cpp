#include<iostream>
using namespace std;
int main(){
    int sort(int x,int n,int *a);
	int a[100];
	int n,x,count;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(;cin>>x;){
		cout<<sort(x,n,a)<<endl;
	}
	return 0;
}
int sort(int x,int n,int *a){
        int count=0;
		for(int i=0;i<n;i++){
			if(x==*(a+i))count++;
		}
		return count;
}
