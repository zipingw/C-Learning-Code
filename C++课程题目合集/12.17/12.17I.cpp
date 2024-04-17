#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(){
    string num;
	while(cin>>num){
	int s1=0,s2=0;
	int c=num.length();
	while(c>0){
		s1+=(num[c-1]-48);c--;
		if(c!=0)
		s2+=(num[c-1]-48);c--;
	}
	cout<<((abs(s1-s2)%11==0)?"Yes":"No")<<endl;
	
	}
	
}
