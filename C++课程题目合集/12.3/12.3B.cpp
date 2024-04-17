#include<iostream>
using namespace std;
int main(){
	bool is7(int );
	int N,M,a;int k;
	while(cin>>N>>M>>a){
		 k=0;
		 for(int i=M;i<=N*a;i+=N){
			k+=is7(i);
		}
		cout<<k<<endl;
	}
	return 0;
} 
bool is7(int n){
	if(n%7==0){return 1;}
	else{
		for(int r=n;r!=0;){
			int a=r%10;
			if(a==7)return 1;
			else{r=r/10;}
		}
	}
	return 0;
}
