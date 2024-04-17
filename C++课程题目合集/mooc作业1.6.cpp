#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int m,n,b[110][110];
	cin>>n>>m;
	if(n<3||m<3){
	    int s=m*n;
	    for(int i=0;i<n;i++){
	    	for(int j=0;j<m;j++){
	    		cin>>b[i][j];
			}
		}
		for(int i=0;i<n;i++){
	    	for(int j=0;j<m;j++){
	    		cout<<b[i][j]<<" ";
			}
			cout<<endl;
		}
	   return 0;
	} 
    double p [110][110];
	double a[110][110];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>p[i][j];
		}
	}
	for(int i=1;i<n-1;i++){
		for(int j=1;j<m-1;j++){
			a[i][j]=round((p[i][j]+p[i-1][j]+p[i+1][j]+p[i][j-1]+p[i][j+1])/5);
		}
	}
	for(int i=0;i<m;i++) cout<<p[0][i]<<" ";
	cout<<endl;
	for(int i=1;i<n-1;i++){
		cout<<p[i][0]<<" ";
		for(int j=1;j<m-1;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<p[i][m-1]<<endl;
	}
	for(int i=0;i<m;i++)cout<<p[n-1][i]<<" ";
	cout<<endl;
	return 0;
}
