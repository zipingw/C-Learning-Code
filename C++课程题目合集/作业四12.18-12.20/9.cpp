#include<iostream>
using namespace std;
int bSearch(  int*a,int n,int s                 ){ //�����б���Ҫ��ȫ
  int up=n-1, low=0,mid; 
  while(low<=up) { //���ֲ��ң������ҵ��������±꣬���򷵻�-1
     //��.
     //ѭ��������Ҫ��ȫ
     mid=(up+low)/2;
     if(a[mid]>s)up=mid-1;
     else if(a[mid]<s)low=mid+1;
     else return mid;
}
return -1; 
}
int main(){
   int a[2000],num;
   for (int i=0;i<2000;i++)a[i]=i*i;
   while(cin>>num){
	/*��a�����в���num,����ҵ������num���ĸ�����ƽ�����������num����ĳ������ƽ����*/
    int k=bSearch(a,2000, num);
	if(k>=0)
cout<<num<<"��"<<k<<"��ƽ��\n";
else cout<<num<<"����ĳ������ƽ��\n";

  }
}

