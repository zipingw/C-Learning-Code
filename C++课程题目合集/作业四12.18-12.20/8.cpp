#include<iostream>
#include<cstring>
using namespace std;
int strcmp (char*p1,char*p2){
	
	int i;
		for(i=0;i<strlen(p1);i++){
			if(p1[i]!=p2[i])return ((int)p1[i]-(int)p2[i]);
		}
		if(i==strlen(p1))return 0;
	
}
int main(){
	char s1[100],s2[100];
	char*p1=s1;
	char*p2=s2;
	while(cin>>s1>>s2){
	cout<<strcmp(s1,s2)<<endl;
	}
	
}
