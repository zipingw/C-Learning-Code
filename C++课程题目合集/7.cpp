#include<iostream>
#include<vector>
using namespace std;
int main(){
     int check(int n,int x,vector<int>v);
	 int n,x;
     vector<int> v1;
     cin>>n;
     for(int i=0;i<n;i++){
     	cin>>x;
		v1.push_back(x);
	 }
	 while(cin>>x){
	 	cout<<check(n,x,v1)<<endl;
	 }
	 return 0;
}
int check(int n,int x,vector<int>v){
	int count =0;
	for(int i=0;i<n;i++){
		if(v[i]==x)count++;
	}
	return count;
}
