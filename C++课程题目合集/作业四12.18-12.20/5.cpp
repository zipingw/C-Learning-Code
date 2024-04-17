#include<iostream>
using namespace std;
void delc (char*s,int len){
    int j;
    int i;
    
	for( i=0;i<len;){
		if(s[i]==s[i+1]){
			for( j=i+1;j<len;j++){
				s[j]=s[j+1];
			} 
			len--;
		}
		else i++;
	} 
}
int main(){
    char str[81]={'\0'};
	char*p=str;
	while(cin>>str){
	int i=0;
	int len;
    while(str[i]!='\0'){
    	len++;i++;
	}
	
	delc(str,len);
	for(int k=0;k<len;k++){
	cout<<str[k];	
	}
	cout<<endl;
	}
	
} 
