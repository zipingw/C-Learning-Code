#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int a[110];
	double n,a1[4]={0},b[4]={0};
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];	}
	for(int i=0;i<n;i++){
	   if(a[i]>=0&&a[i]<=18)a1[0]++;
	   else if(a[i]>18&&a[i]<36)a1[1]++;
	   else if(a[i]>35&&a[i]<61)a1[2]++;
	   else a1[3]++;
	}
    for(int j=0;j<4;j++){
    	b[j]=a1[j]/n*100;
	}
	for(int k=0;k<4;k++){
		cout<<fixed<<setprecision(2)<<b[k]<<"%"<<endl;
	}
	return 0;
	} 
