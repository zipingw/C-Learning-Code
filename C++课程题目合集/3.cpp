#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n,x,count;
	cin>>n; 
	int *p=new int [n];
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	sort(p,p+n);
	for(;cin>>x;){
		count=0;
		int s=1,e=n,m;
		for(;s<=e;){
			m=(s+e)/2;
			if(p[m-1]<x)s=m+1;
			else if(p[m-1]>x)e=m-1;
            else {
            	 count++;
            	 for(int j=m+1;j<=e;j++)
            	 if(p[j-1]==x)count++;
				 for(int k=m-1;k>=s;k--)
				 if(p[k-1]==x)count++;
				 break; 
			}  		
		} 
		
		cout<<count<<endl;
	}
	return 0;
}
