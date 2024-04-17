#include<iostream>
#include<string>
using namespace std;
int main (){
	char s;
	string a;
	while(cin>>s>>a){
		int k=0;
	for(int i=0;i<a.length();++i){
		if(a[i]==s){
			k++;
		}
	}
	if(2*k>=a.length()){
		cout<<"Yes"<<endl;
	}
	else cout<<"No"<<endl;
	}
	return 0;
}

