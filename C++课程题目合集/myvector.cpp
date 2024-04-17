#include<iostream>
using namespace std;
class myVector{
 	int a[101];
 	int sz=0;
   public:
 	void add(int );
 	void del();
 	void printall();
 	void printsz();
 	bool check(int );
 	
 };
void myVector::add(int i){
 	a[sz++]=i;
 }
void myVector::del(){
    sz--;
 }
void myVector::printall(){
	for(int i=0;i<sz;i++)cout<<a[i]<<" ";
} 
void myVector::printsz(){
	cout<<sz<<endl;
}
bool myVector::check(int n){
	for(int i=0;i<sz;i++){
		if(a[i]==n)return 1;
	}
	return 0;
}
int main(){
 	myVector v1;int n;
 	for(int i=0;i<5;i++){
 		cin>>n;
		if(v1.check(n)==0){	
		v1.add(n);
		}
	}
	v1.printsz();
 	v1.printall();
	cout<<endl;
 	v1.del();
 	v1.printall();
 	return 0; 
 }
