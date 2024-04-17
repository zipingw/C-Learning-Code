#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n){int k=31;int r;int a[32]={0};
	if(n==0){for(int s=0;s<32;s++)cout<<a[s];}
	
	if(n>0){
	    for(r=n;n!=0&&r!=0;k--)
	    {a[k]=r%2;r=r/2;}
		for(int s=0;s<32;s++)cout<<a[s];
	}
	else if(n<0) {
	   for(r=-n-1;n!=0&&r!=0;k--){
		a[k]=r%2;r=r/2;
	}
	for(int s=0;s<32;s++)cout<<(a[s]^1);
	}
	
	cout<<"  "<<n<<endl;	
		
	}
	return 0;
}
