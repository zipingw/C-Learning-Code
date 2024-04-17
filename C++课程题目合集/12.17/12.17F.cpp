#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,j,a[105]={0};
		cin>>n;
		
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		if(n<=2){cout<<"yes"<<endl;continue;
		}
		sort(a,a+n);
		int s=a[1]-a[0];
	    for( j=2;j<n;j++){
			if((a[j]-a[j-1])!=s)break;
		}
		if(j==n)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}
