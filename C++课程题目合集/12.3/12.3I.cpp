#include<iostream>
#include<string>
using namespace std;
int main(){
	int N;
	while(cin>>N){
	    int max=0;
		if(N==0)return 0;
		for(string str;N;N--){
			
			cin>>str;
			if(str.length()>max){max=str.length();
			}
		}
		cout<<max<<endl;
	}
	return 0;
} 
