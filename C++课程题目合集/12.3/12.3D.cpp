#include<iostream>
using namespace std;
int main (){
	int N;int a[10000]={0};
	while(cin>>N){int k=0;
	for(int i=0;i<N ;i++){
			cin>>a[i];int j;
			for(j=0;j<i;j++){
				if(a[i]==a[j])break;
			}
			if(j==i)k++;
		}
	cout<<k<<endl;
	}
	return 0;
} 
