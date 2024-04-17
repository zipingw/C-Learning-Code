#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
bool cmp(const int &a,const int & b){
	return abs(a)<abs(b);
}
int main(){
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++){
	cin>>a[i]; 
	} 
	sort(a,a+n,cmp);
	for(int j=0;j<n;j++){
		
		cout<<a[j]<<" ";
	}
	return 0;
} 
