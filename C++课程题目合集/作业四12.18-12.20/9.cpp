#include<iostream>
using namespace std;
int bSearch(  int*a,int n,int s                 ){ //参数列表需要补全
  int up=n-1, low=0,mid; 
  while(low<=up) { //二分查找，返回找到的数的下标，否则返回-1
     //….
     //循环过程需要补全
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
	/*在a数组中查找num,如果找到，输出num是哪个数的平方；否则输出num不是某个数的平方。*/
    int k=bSearch(a,2000, num);
	if(k>=0)
cout<<num<<"是"<<k<<"的平方\n";
else cout<<num<<"不是某个数的平方\n";

  }
}

