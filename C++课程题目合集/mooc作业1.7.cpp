#include<iostream>
using namespace std;
int main(){
	int  a[110][110];
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
