#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> v1;
	int n;
	cin>>n;
	int a;
	for(int i=0;i<n;i++)
	{   
	    cin>>a;
		v1.push_back(a);
	}
	int x,count;
	for(;cin>>x;){
	count=0;
	for(int i=0;i<n;i++){
		if(v1[i]==x)count++;
	}
	cout<<count<<endl;
    }
    return 0;
}
