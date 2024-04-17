#include<iostream>
#include<iomanip>

using namespace std;
int  main(){
	for(int n;cin>>n;){
		cout<<setiosflags(ios::right);
		cout<<setw(11)<<n<<"-->";
		if(n==0){cout<<"0\n";continue;}
		if(n<0){cout<<"-";n=-n;}
		int a[32];
		int pos=0;
		while(n){
			a[pos++]=n&1;
			n>>=1;
		}
		for(int i=pos-1;i>=0;--i)cout<<a[i];
	}
	cout<<endl;
	return 0;
}
