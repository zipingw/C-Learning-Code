#include<iostream>
using namespace std;
int main(){
	string s[12]={"January","February","March","April","May","June","July","Auguest","September","October","November","December"};
	string * a=s;
	int n;
	while(cin>>n){
		cout<<*(a+n-1)<<endl;
		cout<<a[n-1]<<endl;
	}
}
