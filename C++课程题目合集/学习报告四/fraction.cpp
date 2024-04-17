#include<iostream>
using namespace std;
class Fraction{
    int num;
	int deno;
public:
	Fraction (int n=0,int d=1):num(n),deno(d){
		reduce();
	}
	void reduce();
	friend ostream& operator<<(ostream& o,const Fraction& f);
	friend Fraction operator +(Fraction &fone,Fraction &ftwo);
	friend Fraction operator *(Fraction &fone,Fraction &ftwo);
	friend bool operator ==(Fraction &fone,Fraction &ftwo);
	friend bool operator <(Fraction &fone,Fraction &ftwo);
	friend bool operator >(Fraction &fone,Fraction &ftwo);
	Fraction operator -();
	Fraction operator +=(Fraction &ff);
	Fraction operator *=(Fraction &ff);
	operator double(){
		return double(num)/double(deno);
 	}
}; 
void Fraction::reduce(){
    int temp,a,b;
	if(num>deno){
		a=num;b=deno;
	}
	else {a=deno;b=num;}
	while(b!=0){
		temp=a%b;
		a=b;
		b=temp;
	}
	num/=a;deno/=a;
	if(deno<0){
		num*=(-1);
		deno*=(-1);
	}
}  

Fraction Fraction::operator +=(Fraction &ff){
	num=num*ff.deno+ff.num*deno;
	deno*=ff.deno;
	reduce();
}
Fraction Fraction::operator *=(Fraction &ff){
	num*=ff.num;
	deno*=ff.deno;
	reduce();
}
 ostream& operator<<(ostream& o, const Fraction& f) {
   o<<f.num<<"/"<<f.deno;
   return o;
}
Fraction operator +(Fraction &fone,Fraction &ftwo){
	Fraction F((fone.num*ftwo.deno)+(ftwo.num*fone.deno),fone.deno*ftwo.deno);
	F.reduce();
	return F;
}
Fraction operator *(Fraction &fone,Fraction &ftwo){
	Fraction F(fone.num*ftwo.num,fone.deno*ftwo.deno);
	F.reduce();
	return F;
}
bool operator ==(Fraction &fone,Fraction &ftwo){
	if(fone.num==ftwo.num&&fone.deno==ftwo.deno)return 1;
	else return 0;
}
bool operator <(Fraction &fone,Fraction &ftwo){
	if(fone.num*ftwo.deno<ftwo.num*fone.deno)return 1;
	else return 0;
}
bool operator >(Fraction &fone,Fraction &ftwo){
	if(fone.num*ftwo.deno>ftwo.num*fone.deno)return 1;
	else return 0;
}
Fraction Fraction::operator -() {
	 Fraction F(num*(-1),deno);
	 return F;
}
int main() {
    Fraction f1(1, 6); // f1:1/6
    Fraction f2(2, 8); // f2:1/4
    cout << f2 << " ~ "<< double(f2) << endl;  // 1/4 ~ 0.25
    cout << f1+f2 << endl; //   5/12
    cout << f1*f2 << endl; //   1/24
    cout << -f1 <<endl;    //   -1/6
    f1 += f2;            //  
    cout << f1 <<endl;  // 5/12
    f1 *= f2;            
    cout <<  f1 <<endl; //5/48
   int a1,b1,a2,b2;
    while(cin >> a1 >> b1 >> a2 >> b2){
            Fraction ff1(a1, b1);
            Fraction ff2(a2, b2);
           if(ff1 == ff2)
            cout<<"equal\n";
           else if(ff1 < ff2)
            cout<<"smaller\n";
           else
            cout<<"bigger\n";
    }
}

