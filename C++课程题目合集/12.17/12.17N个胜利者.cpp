#include<iostream>
#include<algorithm>
using namespace std;
int main(){	
       int a[2000],M,N,k,x;	
       while(cin>>M>>N>>k)	{		
       x=1;	
       for(int i=1;i<=M;i++)   //���鸳��ֵ����ֵ��Ϊ���� 	
       {a[i]=i;	}		          
       while(M) {
	        if(M==k){     		
                sort(a,a+M);     	
                for(int i=1;i<=M;i++){
				cout<<a[i];
				if(i!=M)cout<<" ";
				}		
                cout<<endl;		 
				break;
				}    	    	
            if((N%M+x-1)%M==0)    	{x=M;}    	
            else	{x=(N%M+x-1)%M;}    	
                for(int j=x;j<M;j++)    	
				{a[j]=a[j+1];}    	    	    	
                M--;	
				}			
        } 
        return 0;
 }



