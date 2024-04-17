#include<iostream>
#include<cstring>
using namespace std;
void delc(char *s){
	for(int i=0;*(s+i)!='\0';)
	if(*(s+i-1)==*(s+i)) strcpy(s+i-1,s+i);
	else i++;
}
int main(){
	char s[81];
	cin.getline(s,81);
	delc(s);
	cout<<s<<endl; 
}
