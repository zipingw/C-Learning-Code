#include<iostream> 
#include<iomanip>
using namespace std;
int main (){
	int n;
	double ave,sum,s;
	while(cin>>n){
		
			
		s+=1;
		if(n<3)cout<<"0"<<endl;
		else if(n==3){cout<<"35"<<endl;sum+=1;}
		else if(n==4){cout<<"45"<<endl;sum+=1;}
		else {cout<<"50"<<endl;sum+=1;}
	}
	ave=sum/s;
	cout<<fixed<<setprecision(2)<<ave<<endl;
		
	return 0;
	
}
