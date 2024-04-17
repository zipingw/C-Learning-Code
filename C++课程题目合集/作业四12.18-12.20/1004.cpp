#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n,a,b;
	while(cin>>n){
	   int *p=new int[n];
	   for(int i=0;i<n;i++){
	   	 cin>>p[i];
	   }
	   int k=abs(p[1]-p[0]);
	   int j;
	   for( j=2;j<n;j++){
	   	 if(abs(p[j]-p[j-1])!=k-1)break;
	   	 k=abs(p[j]-p[j-1]);
	   	}
	   if(j!=n)cout<<"Not jolly\n";
	   	 else cout<<"Jolly\n";
	}
	return 0;
} 
