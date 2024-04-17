#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	while(cin>>n){
	for(double i=1;i<=24;i++){
			if((n>=pow(2,i-1))&&(n<=pow(2,i)-1)){
				cout<<i<<endl;
				break;
			}
		}
		
	}
	return 0;
	} 	
