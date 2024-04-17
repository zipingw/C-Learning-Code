#include<iostream>
using namespace std;
int main(){
	int n,m,l,r,count=0;
	int a[10010]={0};
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>l>>r;
		for(int j=l;j<=r;j++){
			a[j]=1;
		}
	} 
	for(int k=0;k<=n;k++){
		count+=(a[k]==0);
	}
	cout<<count<<endl;
	return 0;
}
