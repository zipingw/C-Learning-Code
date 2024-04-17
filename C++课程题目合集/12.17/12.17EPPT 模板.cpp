#include<iostream>
using namespace std; 
void Josephus(int *a, int m, int n, int delNum ){
 int delc = 0;
 int count = 0;
 int i = 1;    // no. of  child
 while( delc < delNum ){
 if( a[i] != 0){
 	count++;
 	if(count==n)
 	{
 		a[i]=0;
 		count=0;
 		delc++;
	 }
 }
 i++; //next
 if(i == m+1 ) i=1; 
 }
}
int main(){
	int i,a[51];
	int m,n,k;
	while(cin>>m>>n>>k){
		for(i=1;i<=m;i++)a[i]=1;
		Josephus(a,m,n,m-k);
		int ss=0;
		for(i=1;i<=m;i++){
			if(a[i]!=0){
				if(ss++)cout<<" ";
				cout<<i;
			}
		}
		cout<<endl;
		}
		return 0;
} 
