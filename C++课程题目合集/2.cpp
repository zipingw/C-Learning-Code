#include<iostream>
#include<algorithm>
using namespace std;
int a[1000010];
int main() {
	int n,x,count;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(;cin>>x;){
		count=0;
		int s=1,e=n,m;
		for(;s<=e;){
			m=(s+e)/2;
			if(a[m-1]<x)s=m+1;
			else if(a[m-1]>x)e=m-1;
            else {
            	 count++;
            	 for(int j=m+1;j<=e;j++)
            	 if(a[j-1]==x)count++;
				 for(int k=m-1;k>=s;k--)
				 if(a[k-1]==x)count++;
				 break; 
			}  		
		} 
		cout<<count<<endl;
	}
	return 0;
}
