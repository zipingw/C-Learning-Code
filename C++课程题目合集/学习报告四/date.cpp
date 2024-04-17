#include<iostream>
#include<iomanip>
using namespace std;
class Date{
  int year, month, day;
public:
  Date(int y=1900,int m=1,int d=1):year(y),month(m),day(d){}
  void set(int y,int m,int d);  // 赋值操作
  bool isLeapYear()const;              // 判断闰年
  void print()const;                    // 输出日期
  Date & operator ++();
  Date & operator ++(int );
};
void Date::set(int y,int m,int d){
  year=y; month=m; day=d;
}
bool Date::isLeapYear()const{
  return (year%4==0 && year%100!=0)||(year%400==0);
}
void Date::print()const{
  cout<<setfill('0');
  cout<<setw(4)<<year<<'-'<<setw(2)<<month<<'-'<<setw(2)<<day<<'\n';
  cout<<setfill(' ');
}
Date& Date::operator ++(){
    if(month==2){
	  if(this->isLeapYear()){
    	if(++day==30){day=1;month++;}
    	if(month==13){
    		month-=12;year++;
		} 
	  }
	  else {
	 	if(++day==29){day=1;month++;}
	 	if(month==13){
    		month-=12;year++;
		}
	  }
	}
	else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
		if(++day==32){day=1;month++;}
		if(month==13){
    		month-=12;year++;
		}
	}
	else {
		if(++day==31){day==1;month++;}
		if(month==13){
    		month-=12;year++;
		}
	}
	return *this;
}
Date& Date::operator ++(int ){
	Date d1(*this);
	day++;
	if(month==2){
	  if(this->isLeapYear()){
    	if(day==30){day=1;month++;}
    	if(month==13){
    		month-=12;year++;
		}
	  }
	  else {
	 	if(day==29){day=1;month++;}
	 	if(month==13){
    		month-=12;year++;
		}
	  }
	}
	else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
		if(day==32){day=1;month++;}
		if(month==13){
    		month-=12;year++;
		}
	}
	else {
		if(day==31){day==1;month++;}
		if(month==13){
    		month-=12;year++;
		}
	}
	return d1;
}
int main(){
	Date date1,date2(2016,1,1);
	date1.print();
	date2.print();
	date2++;
	date2.print();
	++date2;
	date2.print();
	date2.set(2016,2,29);
	date2++;
	date2.print();
	date2.set(2016,12,31);
	date2++;
	date2.print();
	return 0;
}
