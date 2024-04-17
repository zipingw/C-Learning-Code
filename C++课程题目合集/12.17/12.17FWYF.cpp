#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,*p,k=0;
	cin>>n;
	while(n--)
	{
	int m;
	cin>>m;
	if(m<=2)
	{
		cout<<"yes"<<endl;
	}
	else
	{
		p=new int[m];
		for(int i=0;i<m;i++)
		{
			cin>>p[i];
		}
		sort(p,p+m);
		int s;
		s=p[0]-p[1];
		int i;
		for( i=0;i<m-1;i++)
		{
			if(p[i]-p[i+1]!=s)
			{
				break;
			}
		}
	 if(i==m-1)
	 {
	 	cout<<"yes"<<endl;
	 }
	 else
	 {
	 	cout<<"no"<<endl;
	 }
}
}
}
