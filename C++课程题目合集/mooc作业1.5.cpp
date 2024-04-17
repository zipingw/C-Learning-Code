#include<iostream>
using namespace std;
int main(){
	int a[5][5],imax,jmin,r,l,count=0;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<5;i++){
		imax=a[i][0];
		r=i;
		l=0;
		for(int j=0;j<5;j++){
			if(a[i][j]>imax){
				imax=a[i][j];
		        l=j;
			}
		}
		jmin=a[r][l];
		int k;
		for( k=0;k<5;k++){
			if(jmin>a[k][l])break;
		}
		if(k==5){
			cout<<r+1<<" "<<l+1<<" "<<imax<<endl;
		    count++;
		}
	}
	if(count==0)cout<<"not found"<<endl;
	return 0;
} 
