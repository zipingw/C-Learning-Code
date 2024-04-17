#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
	int n;
	double q;
	while(cin>>n>>q){
	    double sum=0;
		for(double i=0;i<=n;i++){
			sum+=pow(q,i);
		}
		cout<<fixed<<setprecision(3)<<sum<<endl;
	}
} 
