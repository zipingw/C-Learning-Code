#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	vector<int>v1;
	int n,x,count;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		v1.push_back(x);
	}
	sort(v1.begin(),v1.end());
	for(;cin>>x;){
		count=0;
		int s=1,e=n,m;
		for(;s<=e;){
			m=(s+e)/2;
			if(v1[m-1]<x)s=m+1;
			else if(v1[m-1]>x)e=m-1;
            else {
            	 count++;
            	 for(int j=m+1;j<=e;j++)
            	 if(v1[j-1]==x)count++;
				 for(int k=m-1;k>=s;k--)
				 if(v1[k-1]==x)count++;
				 break; 
			}  		
		} 
		cout<<count<<endl;
	}
	return 0;
}
