#include<iostream>
using namespace std;
int main(){
	int m,n,k;
	int i,a[51]={1};
	while(cin>>n>>m>>k){
	int delc=0;
    int count = 0;
    for(i=1;;i++){
    	if(i>n)i=i%n;
    	if(a[i]>0)count++;
    	if(count==m&&delc<k){
    		count = 0;a[i]=0;delc++;
		}
		else if(count==m&&delc==k){
			a[i]==0;break;
		}
	}
		int ss=0;
		for(i=1;i<=n;i++ )
			if(a[i]!=0){
				if(ss++)cout<<' ';cout<<i;
			}
		cout<<endl;
   
}
return 0;
}
 
