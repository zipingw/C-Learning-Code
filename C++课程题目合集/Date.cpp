#include<iostream>
using namespace std;
class Date{
	int year;
	int month;
	int day;
	public:
		Date(int y=1900, int m=1, int d=1);
        Date(const string& s);   
	void set( int y, int m, int d );  //设置日期
	bool isValid();// 判断年月日的值是否构成一个有效日期
	bool isLeapYear(); //判断是否闰年
	int toInt() ; //把日期转换成整数（YYYYMMDD），比如201903015
	Date lastDay(); //返回当前对象的前一天的日期
	Date nextDay(); //返回当前对象的后一天的日期
	void print(); //打印日期，格式参考:"yyyy/mm/dd"或"yyyy-mm-dd"
	int getYear(); //返回当前对象的year的值
	int getMonth(); //返回当前对象的month的值
	int getDay(); //返回当前对象的day的值
	void setYear(int y);// 把y的值赋值给当前对象的year
	void setMonth( int m);// 把m的值赋值给当前对象的month
	void setDay( int d); //把d的值赋值给当前对象的day
};
void Date::set(int y,int m,int d){
	year=y;
	month=m;
	day=d;
}
void Date::setYear(int y){
	year=y;
}
void Date::setMonth(int m){
	month =m;
}
void Date::setDay(int d){
	day=d;
}
int Date::getYear(){
	return year;
}
int Date::getMonth(){
	return month;
}
int Date::getDay(){
	return day;
}
int Date::toInt(){
	return (year*10000+month*100+day);
}
void Date::print(){
	cout<<year<<"/"<<month<<"/"<<day<<endl;
}
Date Date::lastDay(){
	if(day-1==0){
		if(month-1==0){
			year=year-1;
			month=12;
			day=31;
		}
		else{
		month-=1;
		if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
			day=31;
		}
		else day=30;
		}
	}
	else{
		day-=1;
	}
}
Date Date::nextDay(){
	if(month==12){
		if(day==31){
			year+=1;month=1;day=1;
		}
		else{
			day+=1;
		}
	}
    else if(month==1||month==3||month==5||month==7||month==8||month==10){
    	if(day==31){
    		day=1;month+=1;
		}
		else day+=1;
	}
	else {
		if(day==30){
			day=1;month+=1;
		}
		else{
			day+=1;
		}
	}
}
bool Date::isLeapYear(){
	if(year%4==0&&year%100!=0||year%400==0)return 1;
	else return 0;
}
bool Date::isValid(){
	if(month<0||month>13){
		return 0;
	}
	else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
	  if(day<0||day>31)return 0;
	} 
	else {
		if(day<0||day>30)return 0;
	}
	return 1;
}
int main(){
	Date D1;
	D1.print();
	cout<<endl;
    D1.getYear();
	D1.getMonth();
	D1.getDay();
	cout<<endl;
	D1.set(2020,3,17);
	D1.print();cout<<endl;
	D1.setYear(2000);
	D1.setMonth(12);
	D1.setDay(12);
	D1.print();
	cout<<endl;
	D1.toInt();	
	
} 
