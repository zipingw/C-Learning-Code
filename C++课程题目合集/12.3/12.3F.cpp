#include<iostream>
using namespace std;
int main(){
	int T;int a[100]={0};
	while(cin>>T){
		if(T==0)return 0;
		int k=0;
		for(int r=T;r!=0;){
			k+=r%2;
			r/=2;
		}
		cout<<k<<endl;
	}
}
