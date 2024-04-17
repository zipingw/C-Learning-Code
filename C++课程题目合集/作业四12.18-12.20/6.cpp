#include<iostream>
using namespace std;
void strRev(char*s,int len){
	 int i;
	 for(i=0;i<len;i++)//整体后移 
    {
        s[2*(len-1)-i]=s[i];
    } 
     for(i=len-1;i<=2*(len-1);i++)//往前平移 
    {
         s[i-(len-1)]=s[i];    
    }

}
int main(){
	char str[1000]={'\0'};
	char*p=str;
	while(cin>>str){
		int i=0,len;
		while(str[i]!='\0'){
			len++;i++;
		}
		 strRev(str, len);
		for(int j=0;j<len;j++)cout<<str[j];
		cout<<endl;
	}
} 
