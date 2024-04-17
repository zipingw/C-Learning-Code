#include<iostream>
#include<string>
using namespace std;
int main(){
	string g,a;
	char str[13]={'A','2','3','4','5','6','7','8','9','1','J','Q','K'};
	while(cin>>g>>a){
		int l=g.length()-1;
		if(g[0]=='A'&&g[l]=='K'){
			cout<<"No"<<endl;
		}
		else if(g[0]=='A'&&g[l]!='K'){
			int k=9;
			for(int i=0;i<13;i++){
				if(g[l]==str[i]) {
				k=i;break;
				}
			}
			if(a[0]==str[k+1])cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		else if(g[l]=='K'&&g[0]!='A'){
			int s=0;
			for(int i=0;i<13;i++){
				if(g[0]==str[i]) {
					s=i;break;
				}
			}
			if(a[0]==str[s-1])cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		else{
			int max=0,min=0;
			for(int i=0;i<13;i++){
				if(g[0]==str[i]) min=i;
				if(g[l]==str[i]) max=i;
			}
			if((a[0]==str[min-1])||(a[0]==str[max+1]))cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		
	}
	return 0;
} 
