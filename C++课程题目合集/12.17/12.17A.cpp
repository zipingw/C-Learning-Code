#include<iostream>
using namespace std;
int main(){
	int a,b,n;
	while(cin>>n){
		for(;n>0;n--){
			cin>>a>>b;
			if(a>b)cout<<"Bigger"<<endl;
			else if(a==b)cout<<"Equal"<<endl;
			else cout<<"Smaller"<<endl;
		}
	}
	return 0;
	
} 
