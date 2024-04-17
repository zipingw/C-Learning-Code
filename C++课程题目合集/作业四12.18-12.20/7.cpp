#include<iostream>
#include<cstring>
using namespace std;
bool symmetry (char *s) {
       int	i,n;
       n=strlen(s);
       for( i=0;i<n/2;i++){
		if(s[i]!=s[n-1-i])break;
	}
	return (i==n/2)?true:false;
} 
int main(){
	char a[1000];
	char*p=a;
	while(cin>>a) {
		cout<<((symmetry(a))?"Yes":"No")<<endl;
	}
}
